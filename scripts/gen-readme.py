import os
from pathlib import Path

SECTIONS_TO_IGNORE = ["ds-c"]


def valid_section(section: Path) -> bool:
    return section.is_dir() and section.name not in SECTIONS_TO_IGNORE


def get_section_name(section: str) -> str:
    return section.replace("-", " ").title()


def valid_file(file: Path) -> bool:
    return file.is_file() and file.name.endswith((".py", ".cpp"))


def get_algorithm_name(algorithm: str) -> str:
    name, lang = algorithm.split(".")
    name = name.replace("-", " ")
    name = name.replace("_", " ")
    if lang == "py":
        name += " (python)"
    return name


def get_relative_path(file: Path) -> str:
    return str(file).split("..")[1]


def get_algorithms_md() -> str:
    algorithmsPath = Path(__file__).parent / ".." / "algorithms"
    output = list()
    for section in os.listdir(algorithmsPath):
        if valid_section(algorithmsPath / section):
            current = {"name": get_section_name(section), "algorithms": list()}
            for algorithm in os.listdir(algorithmsPath / section):
                filePath = algorithmsPath / section / algorithm
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
    md = "## Algorithms\n"
    for section in output:
        md += f"- {section['name']}\n"
        for algorithm in section["algorithms"]:
            md += f"    - [{algorithm['name']}]({algorithm['path']})\n"

        md += "\n"

    md += "\n"
    return md


SECTIONS_TO_IGNORE = ["upsolving"]


def valid_sub_section(section: Path) -> bool:
    return section.is_dir() and section.name not in SECTIONS_TO_IGNORE


def get_sub_section_name(section: str) -> str:
    return section.replace("-", " ").replace("_", " ")


def get_sub_section_path(file: Path) -> str:
    return str(file).split("..")[1]


def get_submissions_md():
    submissionsPath = Path(__file__).parent / ".." / "submissions"
    output = list()
    for section in os.listdir(submissionsPath):
        if valid_sub_section(Path(submissionsPath / section)):
            current = {
                "name": get_sub_section_name(section),
                "path": get_sub_section_path(submissionsPath / section),
            }
            output.append(current)

    sorted(output, key=lambda x: x["name"])

    md = "## Submissions\n"
    for section in output:
        md += f"- [{section['name']}]({section['path']})\n"

    md += "\n"
    return md


def get_intro() -> str:
    md = "# Competitive Programming Algorithms\n"
    md += "Here you will find implementation of algorithms and data structures used in competitive programming and submissions to many OJ\n"
    md += "\n"
    return md


def get_references() -> str:
    md = """## References & Courses
- [TEP](https://github.com/edsomjr/TEP)
- [UnBalloon](https://github.com/UnBalloon/programacao-competitiva)
- [Macacário](https://github.com/splucs/Competitive-Programming)
- [Algorithms for Competitive Programming](https://cp-algorithms.com/)
- [Neps Academy](https://neps.academy/br/courses)
- [USACO Guide](https://usaco.guide/dashboard/)
- [IME algoritmos](https://www.ime.usp.br/~pf/algoritmos/idx.html)
- [UFMG Lib](https://github.com/brunomaletta/Biblioteca)
    """
    md += "\n"

    return md


def build_md() -> str:
    md = ""
    md += get_intro()
    md += get_algorithms_md()
    md += get_submissions_md()
    md += get_references()
    return md


print(build_md())
