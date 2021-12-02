all:
	gcc -c lib/initPantalla.c
	gcc -c lib/entradaTeclado.c
	gcc -c lib/menuDesplegable.c
	gcc -c lib/dibujarCuadrado.c
	gcc -c lib/mostrarContenido.c
	gcc -c main.c
	gcc -o main main.o initPantalla.o entradaTeclado.o menuDesplegable.o dibujarCuadrado.o mostrarContenido.o
	rm -r bin
	mkdir bin
	mv *.o bin/
	echo compilación terminada

remove:
	rm -r bin
	rm main

list:
	ls
