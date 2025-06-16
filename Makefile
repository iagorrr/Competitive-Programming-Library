.PHONY: clean
clean:
	@rm -f *.log *.out *.aux *.toc notebook.tex
	@rm -f theoretical/*.log theoretical/*.out theoretical/*.aux theoretical*.toc
	@rm -rf ./CMakeCache.txt  ./CTestTestfile.cmake ./cmake_install.cmake ./CMakeFiles ./_deps ./build ./bin

.PHONY: readme
readme:
	@python scripts/gen-readme/gen-readme.py > README.md

.PHONY: format
format:
	@python3 scripts/format/main.py --content ${CURDIR}/content

.PHONY: notebook-tex
notebook-tex:
	@python3 scripts/notebook/main.py \
		--content ${CURDIR}/content

.PHONY: notebook-pdf
notebook-pdf:
	# Yeah you have to run it twice to work :P
	@lualatex  notebook.tex
	@lualatex  notebook.tex

.PHONY: notebook 
notebook: clean format notebook-tex notebook-pdf

.PHONY: theoretical
theoretical:
	# Yeah you have to run it twice to work :P
	@cd theoretical &&  \
	lualatex  theoretical.tex && \
	lualatex  theoretical.tex

.PHONY: test-problems 
test-problems:
	@bash scripts/test-all/script.sh ./tests

.PHONY: test-unit
test-unit:
	cmake -S . -B build
	cmake --build build
	cd build && ctest --output-on-failure --verbose

all: clean test-unit test-problems format readme notebook theoretical build
