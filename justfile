verify:
    oj-verify run

# Clean build and temporary files
clean:
    @rm -f *.log *.out *.aux *.toc notebook.tex
    @rm -rf ./build ./bin

# Generate README
readme:
    @python3 scripts/gen-readme/gen-readme.py > README.md

# Format content
format:
    @python3 scripts/format/main.py --content {{justfile_directory()}}/content

# Generate notebook TeX
notebook-tex:
    @python3 scripts/notebook/main.py \
        --content {{justfile_directory()}}/content

# Build notebook PDF (requires running twice)
notebook-pdf:
    @lualatex notebook.tex
    @lualatex notebook.tex

# Build complete notebook (format -> TeX -> PDF)
notebook: clean format notebook-tex notebook-pdf

# Run all tasks
do-it: clean verify readme notebook
