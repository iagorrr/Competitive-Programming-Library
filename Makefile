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

.PHONY: theoretical-pdf
theoretical-pdf:
	# Yeah you have to run it twice to work :P
	@cd theoretical &&  \
	lualatex  theoretical.tex && \
	lualatex  theoretical.tex

.PHONY: clean
clean:
	@rm -f *.log *.out *.aux *.toc notebook.tex
	@rm -f theoretical/*.log theoretical/*.out theoretical/*.aux theoretical*.toc

.PHONY: notebook 
notebook:
	clean format notebook-tex notebook-pdf

.PHONY: theoretical
theoretical:
	clean theoretical-pdf

.PHONY: test-algorithm
test-algorithm:
	echo "Test: $1" 
	# @echo "Tests path: $$1"
	# @bash scripts/test-algorithm/script.sh $$1

.PHONY: test-all
test-all:
	@bash scripts/test-all/script.sh ./tests

.PHONY: new-test
new-test:
	cmake -S . -B build
	cmake --build build
	cd build && ctest --output-on-failure --verbose

