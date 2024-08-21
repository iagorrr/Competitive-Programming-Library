from dataclasses import dataclass, field
from shutil import copyfile
from typing import Optional
from pathlib import Path
from enum import Enum
import argparse
import re


class Tag(Enum):
    TITLE = "Title"
    DESCRIPTION = "Description"
    USAGE = "Usage"
    TIME = "Time"
    MEMORY = "Memory"
    WARNING = "Warning"


def extract_by_tag(content: str, tag: Tag) -> Optional[str]:
    pattern = re.compile(
        rf"/\*8<(?:[\s\S]*?)@{tag.value}:([\s\S]*?)(?=@\w+:|>8\*/)", re.DOTALL
    )
    match = re.findall(pattern=pattern, string=content)
    if not match:
        return None

    match = match[0].strip()
    if tag != Tag.TITLE:
        match = f"""

            \\begingroup
                \\fontsize{{7}}{{10pt}}\\selectfont 
                \n\n\\textbf{{{tag.value}}}: 
                {match}
            \\endgroup
        """

    return match


def extract_scissors(content: str) -> str:
    pattern = r"/\*8<.*?>8\*/"
    regex = re.compile(pattern, re.DOTALL)
    content = regex.sub("", content)
    content = re.sub(r"\n\s*\n", "\n\n", content)
    content = content.strip()  # Remove leading/trailing whitespace
    return content


@dataclass
class Entry:
    path: Path
    per_tag: dict[Tag, Optional[str]]
    source: Optional[str] = None

    @classmethod
    def from_path(cls, entry_path: Path) -> "Entry":
        with open(entry_path, "r") as f:
            content = f.read()

        per_tag: dict[Tag, Optional[str]] = dict()
        for tag in Tag:
            per_tag[tag] = extract_by_tag(content=content, tag=tag)

        if per_tag[Tag.TITLE] is None:
            per_tag[Tag.TITLE] = entry_path.stem.replace("_", "\\_").replace("&", "\\&")

        source: str = extract_scissors(content=content)

        return cls(path=entry_path, per_tag=per_tag, source=source)

    def get_tex(self, is_under_sub: bool = False) -> str:
        ret: str = ""
        if is_under_sub:
            ret += f"\\subsubsection{{{self.per_tag[Tag.TITLE]}}}\n"
        else:
            ret += f"\\subsection{{{self.per_tag[Tag.TITLE]}}}\n"

        for key, value in self.per_tag.items():
            if value is not None and key is not Tag.TITLE:
                ret += value

        ret += "\n\\vspace{2.5pt}\\hrule\n"

        ext = str(self.path).split(".")[-1]
        if ext == "cpp":
            ret += "\\lstset{style=cppstyle}\n"
        else:
            ret += "\\lstset{style=genericstyle}\n"
        ret += "\\begin{lstlisting}\n"
        ret += self.source
        ret += "\\end{lstlisting}\n"

        return ret

    @classmethod
    def is_valid_entry(cls, path: Path):
        allowed_file_types = set({"cpp", "vim", "sh"})
        return str(path).split(".")[-1] in allowed_file_types

    def __lt__(self, other):
        return self.per_tag[Tag.TITLE] < other.per_tag[Tag.TITLE]


@dataclass
class Subsection:
    title: str
    entries: list[Entry] = field(default_factory=list)

    @classmethod
    def from_path(cls, path: Path) -> "Subsection":
        title = path.name.replace("_", "\\_")
        return cls(title=title)

    def get_tex(self) -> str:
        return f"\\subsection{{{self.title}}}\n"

    def __lt__(self, other):
        return self.title < other.title


@dataclass
class Section:
    title: str
    subsections: list[Subsection] = field(default_factory=list)
    entries: list[Entry] = field(default_factory=list)

    @classmethod
    def from_path(cls, path: Path) -> "Section":
        title = path.name.replace("_", "\\_")
        return cls(title=title)

    def get_tex(self) -> str:
        return f"\\section{{{self.title}}}\n"

    def __lt__(self, other):
        return self.title < other.title


def get_dump(content_path: Path):
    all_sections: list[Section] = []
    for section in content_path.iterdir():
        cur_section: Section = Section.from_path(path=section)
        for entry in section.iterdir():
            if entry.is_dir():
                cur_subsection: Subsection = Subsection.from_path(path=entry)
                for sub_entry in entry.iterdir():
                    if Entry.is_valid_entry(sub_entry):
                        cur_subsection.entries.append(
                            Entry.from_path(entry_path=sub_entry)
                        )
                cur_subsection.entries = sorted(cur_subsection.entries)
                cur_section.subsections.append(cur_subsection)
            elif Entry.is_valid_entry(entry):
                cur_section.entries.append(Entry.from_path(entry_path=entry))

        cur_section.entries = sorted(cur_section.entries)
        cur_section.subsections = sorted(cur_section.subsections)
        all_sections.append(cur_section)

    all_sections = sorted(all_sections)

    return all_sections


def cpy_template(output_path=Path):
    # gets the path from the file gen.py
    path = Path(__file__).parent.absolute()
    template = path / "template.tex"
    copyfile(template, output_path)


def write_tex(sections: list[Section], output_path: Path):
    END_FLUSHLEFT = "\n\\end{flushleft}\n"
    END_MULTICOLS = "\n\\end{multicols}\n"
    END_DOCUMENT = "\n\\end{document}\n"

    fulltex: str = ""
    for section in sections:
        fulltex += section.get_tex()
        # sort subsections
        for subsection in section.subsections:
            fulltex += subsection.get_tex()
            for sub_entry in subsection.entries:
                fulltex += sub_entry.get_tex(is_under_sub=True)

        # sort entries
        for entry in section.entries:
            fulltex += entry.get_tex()

    fulltex += END_FLUSHLEFT + END_MULTICOLS + END_DOCUMENT
    cpy_template(output_path=output_path)
    with open(output_path, "a") as f:
        f.write(fulltex)


def build_full_tex(content_path: Path, output_path: Path):
    sections = get_dump(content_path=content_path)
    write_tex(sections=sections, output_path=output_path)


# Get the paths from the command line
def parse_args():
    parser = argparse.ArgumentParser(description="Create a .tex from a C++ file tree")
    parser.add_argument(
        "--content",
        type=str,
        default="content/",
        help="Path to content",
    )
    parser.add_argument(
        "--output",
        type=str,
        default="./notebook.tex",
        help="Path to save the tex generated",
    )

    args = parser.parse_args()
    return args


if __name__ == "__main__":
    args = parse_args()
    build_full_tex(content_path=Path(args.content), output_path=Path(args.output))
