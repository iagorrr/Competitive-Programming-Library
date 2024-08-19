from pathlib import Path
import subprocess
import argparse


def format_all(content_path: Path):
    for entry in content_path.rglob("*.cpp"):
        cmd = f'clang-format -i "{entry}"'
        subprocess.run(cmd, shell=True)


# Get the paths from the command line
def parse_args():
    parser = argparse.ArgumentParser(
        description="Format every C++ file in the given directory (recursive)"
    )
    parser.add_argument(
        "--content",
        type=str,
        default="content/",
        help="Path to content",
    )
    args = parser.parse_args()
    return args


if __name__ == "__main__":
    args = parse_args()
    format_all(content_path=Path(args.content))
