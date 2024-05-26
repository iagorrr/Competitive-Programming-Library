from pathlib import Path
from dataclasses import dataclass, asdict

@dataclass
class Entry:
    path: Path
    md: str

@dataclass
class AlgorithmEntry(Entry):
    pass
    
@dataclass
class SubsectionEntry(Entry):
    algorithms_entries: list[AlgorithmEntry]

@dataclass
class SectionEntry(Entry):
    algorithms_entries: list[AlgorithmEntry]
    subsections_entries: list[SubsectionEntry]


def get_relative_path(entry_path: Path) -> str:
    entry_path = entry_path.__str__()
    i = entry_path.find("/algorithms")
    entry_path = entry_path[i:]

    return entry_path

def get_section_md(section: Path) -> str:
    return "#### " + section.name.__str__().replace("-", " ").title()

def get_subsection_md(section: Path) -> str:
    return "- " + section.name.__str__().replace("-", " ").title()


def valid_file(file: Path) -> bool:
    return file.is_file() and file.name.endswith((".py", ".cpp"))

def get_algorithm_name(algorithm_path: Path) -> str:
    return  algorithm_path.stem.replace("-", " ").replace("_", " ")

def get_algorithm_md(algorithm_path: Path, is_under_sub: bool) -> str:
    name: str = algorithm_path.stem.replace("-", " ").replace("_", " ")
    relative_path: str = get_relative_path(algorithm_path)
    ident: int = 0 if not is_under_sub else 4
    md: str = ident * " " + "- " + f"[{name}]({relative_path})"
    return md



def get_algorithms_md() -> str:
    ALGORITHMS_FOLDER_PATH:Path = Path(__file__).parent.parent.parent / "algorithms"

    all: list[SectionEntry] = list()

    for section_path in ALGORITHMS_FOLDER_PATH.iterdir():
        if not section_path.is_dir():
            continue

        current_section: SectionEntry = SectionEntry(
                path=section_path,
                md=get_section_md(section_path),
                algorithms_entries=list(),
                subsections_entries=list()
        )

        for entry_path in section_path.iterdir():
            if entry_path.is_dir():
                current_subsection: SubsectionEntry = SubsectionEntry(
                    path=entry_path,
                    md=get_subsection_md(entry_path),
                    algorithms_entries=list()
                )

                for algorithm_entry in entry_path.iterdir():
                    if not valid_file(algorithm_entry):
                        continue

                    current_algorithm: AlgorithmEntry = AlgorithmEntry(
                        path = algorithm_entry,
                        md = get_algorithm_md(algorithm_entry, True),
                    )

                    current_subsection.algorithms_entries.append(current_algorithm)

                current_section.subsections_entries.append(current_subsection)
            else:
                if valid_file(entry_path):
                    current_algorithm: AlgorithmEntry = AlgorithmEntry(
                        path = entry_path,
                        md = get_algorithm_md(entry_path, False),
                    )
                    current_section.algorithms_entries.append(current_algorithm)


        
        all.append(current_section)


    all.sort(key= lambda x: x.md)
    md = "## Algorithms\n\n\n"

    for section in all:
        md += section.md + "\n"

        section.subsections_entries.sort(key=lambda x: x.md)
        for subsection in section.subsections_entries:
            md += subsection.md + "\n"
            for algorithm in subsection.algorithms_entries:
                md += algorithm.md + "\n"
            md += "\n" * 1

        section.algorithms_entries.sort(key=lambda x: x.md)
        for algorithm in section.algorithms_entries:
            md += algorithm.md + "\n"

        md += "\n" * 3

    return md

def get_md_file(file_name: str) -> str:
    REF_PATH: Path = Path(__file__).parent / (file_name + ".md")

    with open(REF_PATH, 'r') as f:
        md = f.read()

    return md

def build_md() -> str:
    md = ""
    md += get_md_file("intro")
    md += get_algorithms_md()
    md += get_md_file("references")
    return md


print(build_md())
