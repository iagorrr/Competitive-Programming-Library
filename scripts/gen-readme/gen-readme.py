import os
from pathlib import Path

def get_section_name(section: Path) -> str:
    return section.name.__str__().replace("-", " ").title()


def valid_file(file: Path) -> bool:
    return file.is_file() and file.name.endswith((".py", ".cpp"))

def get_algorithm_name(algorithm: str) -> str:
    name, _ = algorithm.split(".")
    name = name.replace("-", " ")
    name = name.replace("_", " ")

    return name


def get_relative_path(entry_path: Path) -> str:
    entry_path = entry_path.__str__()
    i = entry_path.find("/algorithms")
    entry_path = entry_path[i:]

    return entry_path


def get_algorithms_md() -> str:
    algorithms_folder_path = Path(__file__).parent.parent.parent / "algorithms"
    output = list()
    for section in algorithms_folder_path.iterdir():
        if section.is_dir():
            current = {"name": get_section_name(section), "algorithms": list()}
            for algorithm in os.listdir(algorithms_folder_path / section):
                filePath = algorithms_folder_path / section / algorithm
                if valid_file(filePath):
                    current["algorithms"].append(
                        {
                            "name": get_algorithm_name(algorithm),
                            "path": get_relative_path(filePath),
                        }
                    )
            current["algorithms"] = sorted(
                current["algorithms"], key=lambda x: x["name"]
            )
            output.append(current)

    output = sorted(output, key=lambda x: x["name"])

    md = "## Algorithms\n\n"
    for section in output:
        md += f"- {section['name']}\n"
        for algorithm in section["algorithms"]:
            name:str = algorithm['name']
            link:str = algorithm['path'].__str__().replace(" ", "%20")
            md += f"    - [{name}]({link})\n"

        md += "\n"

    md += "\n"
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
