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
parser = argparse.ArgumentParser(description="Create notebook from C++ files.")
parser.add_argument(
    "--path", type=str, default="C++", help="Path to implementation paths"
)
args = parser.parse_args()
path = Path(args.path)

if __name__ == "__main__":
    for theme in os.listdir(path):
        if not Path.is_dir(path / theme):
            continue

        print(theme)
        for algorithm in os.listdir(path / theme):
            if not (path / theme / algorithm).__str__().endswith(".cpp"):
                continue
            print("\t", algorithm)
            # run cmd to format it all
            algorithm2 = treat(algorithm)
            subprocess.run(
                "clang-format -i " +
                (path / theme / algorithm2).absolute().__str__(),
                shell=True,
            )
