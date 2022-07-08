# Clean build and temporary files
clean:
    @rm -f *.log *.out *.aux *.toc notebook.tex
    @rm -f theoretical/*.log theoretical/*.out theoretical/*.aux theoretical*.toc
    @rm -rf ./CMakeCache.txt ./CTestTestfile.cmake ./cmake_install.cmake ./CMakeFiles ./_deps ./build ./bin

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

# Build theoretical document (requires running twice)
theoretical:
    @cd theoretical && \
    lualatex theoretical.tex && \
    lualatex theoretical.tex

# Run problem tests
test-problems:
    @bash scripts/test-all/script.sh ./tests

# Run unit tests
test-unit:
    cmake -S . -B build
    cmake --build build
    cd build && ctest --output-on-failure --verbose

# Run all tasks
do-it: clean test-unit test-problems readme notebook theoretical
