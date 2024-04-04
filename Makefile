cube.out: cube.o rotation.o logic.o movements.o prints.o r-blocks.o r-layers.o rp-blocks.o rp-layers.o
	gcc -o cube.out cube.o rotation.o logic.o movements.o prints.o r-blocks.o r-layers.o rp-blocks.o rp-layers.o

cube.o: cube.c
	gcc -c cube.c

rotation.o: rotation.c
	gcc -c rotation.c

logic.o: logic.c
	gcc -c logic.c

movements.o: movements.c
	gcc -c movements.c

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

clean:
	rm *.o
	rm *.out

push:
	git add .
	git commit -m "${m}"
	git push origin main
	clear