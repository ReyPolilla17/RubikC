cube.out: cube.o miscs.o prints.o r-blocks.o r-layers.o rp-blocks.o rp-layers.o
	gcc -o cube.out cube.o miscs.o prints.o r-blocks.o r-layers.o rp-blocks.o rp-layers.o

cubo.o: cube.c
	gcc -c cube.c

miscs.o: miscs.c
	gcc -c miscs.c

prints.o: prints.c
	gcc -c prints.c

r-blocks.o: r-blocks.c
	gcc -c r-blocks.c

r-layers.o: r-layers.c
	gcc -c r-layers.c

rp-blocks.o: rp-blocks.c
	gcc -c rp-blocks.c

rp-layers.o: rp-layers.c
	gcc -c rp-layers.c

clear:
	rm *.o
	rm *.out
	rm *.txt

push:
	git add .
	git commit -m "${m}"
	git push origin main
	clear