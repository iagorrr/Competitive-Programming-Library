readme:
	@python scripts/gen-readme/gen-readme.py > README.md

format:
	@python3 scripts/format/main.py --content ${CURDIR}/content

notebook-tex:
	@python3 scripts/notebook/main.py \
		--content ${CURDIR}/content \

notebook-pdf:
	# Yeah you have to run it twice to work :P
	@lualatex  notebook.tex
	@lualatex  notebook.tex

theoretical-pdf:
	# Yeah you have to run it twice to work :P
	@cd theoretical && ls  && \
	lualatex  theoretical.tex && \
	lualatex  theoretical.tex  && \
	cd .. \

clean:
	@rm -f *.log *.out *.aux *.toc notebook.tex
	@rm -f theoretical/*.log theoretical/*.out theoretical/*.aux theoretical*.toc

notebook: clean format notebook-tex notebook-pdf

theoretical: clean theoretical-pdf

test-all:
	@bash scripts/test-all/script.sh ./tests


