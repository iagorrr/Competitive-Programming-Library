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


clean:
	@rm -f notebook.log notebook.out notebook.toc notebook.aux notebook.tex

notebook: format notebook-tex notebook-pdf clean

test-all:
	@bash scripts/test-all/script.sh ./tests
