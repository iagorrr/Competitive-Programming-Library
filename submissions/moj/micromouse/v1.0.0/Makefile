compile: 
	gcc -O2 -Wextra -g -Wall main.c 

run:
	./a.out

crun:
	make compile
	make run
	make clean

clean:
	rm main.out

moj:
	gcc -E -O2 -g -Wall -Wextra main.c > moj.c

compile-moj:
	gcc -O2 -g -Wall -Wextra moj.c -o moj.out

run-moj: moj compile-moj
	./moj.out
