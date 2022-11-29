output: main.o CVlibrary.o
	gcc main.o CVlibrary.o -o output.exe

main.o: main.c
	gcc -c main.c

CVlibrary.o: CVlibrary.c
	gcc -c CVlibrary.c

clean:
	del *.o output.exe