readme:
	python scripts/gen-readme.py > README.md

notebook:
	python3 scripts/notebook/gen.py --path ${CURDIR}/algorithms
