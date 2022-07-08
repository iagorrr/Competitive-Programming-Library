import os
import subprocess
import argparse
from pathlib import Path


def treat(s) -> str:
    s2 = s
    s2 = s2.replace("(", "\\(").replace(")", "\\)")
    return s2


parser = argparse.ArgumentParser()
parser.add_argument(
    "--path", type=str, default="C++", help="Path to implementation paths"
)

args = parser.parse_args()
path = Path(args.path)
clangcmd = "clang-format -i "

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
