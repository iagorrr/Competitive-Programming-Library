import os
import subprocess
import shutil
import argparse
from pathlib import Path


def treat(s) -> str:
    s2 = s
    s2 = s2.replace("(", "\\(").replace(")", "\\)")
    return s2


# Get the path from the command line
parser = argparse.ArgumentParser()
parser.add_argument(
    "--path", type=str, default="C++", help="Path to implementation paths"
)

parser.add_argument(
    "--clangpath",
    type=str,
    default=Path(__file__).absolute().parent / ".clang-format",
    help="Path to clang configuration",
)
args = parser.parse_args()
path = Path(args.path)
clangpath = args.clangpath
# clangcmd = f"clang-format --style={clangpath} -i "
clangcmd = f"clang-format --style='file:{clangpath}' -i "

if __name__ == "__main__":
    for theme in os.listdir(path):
        if not Path.is_dir(path / theme):
            continue

        print(theme)
        for algorithm in os.listdir(path / theme):
            if not (path / theme / algorithm).__str__().endswith(".cpp"):
                continue
            print("\t", algorithm)
            algorithm2 = treat(algorithm)
            cmd = clangcmd + (path / theme / algorithm2).absolute().__str__()
            print("Running: ", cmd)
            subprocess.run(
                cmd,
                shell=True,
            )
