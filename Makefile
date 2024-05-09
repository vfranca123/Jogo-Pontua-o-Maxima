all: obj/tp2.o obj/Array.o  obj/ConfigArquivo.o obj/Dinamica.o obj/Tempo.o obj/Alternativo.o 
	gcc obj/tp2.o obj/array.o obj/configArquivo.o obj/Dinamica.o obj/Tempo.o obj/Alternativo.o -o tp2
	mv tp2 bin/

obj/tp2.o: desenvolvimento_funcoes/tp2.c
	gcc desenvolvimento_funcoes/tp2.c -c
	mv tp2.o obj/

obj/Array.o: desenvolvimento_funcoes/array.c interfaces/array.h
	gcc desenvolvimento_funcoes/array.c -c
	mv array.o obj/

obj/Dinamica.o: desenvolvimento_funcoes/dinamica.c interfaces/dinamica.h
	gcc desenvolvimento_funcoes/dinamica.c -c
	mv Dinamica.o obj/

obj/Tempo.o: desenvolvimento_funcoes/tempo.c interfaces/tempo.h
	gcc desenvolvimento_funcoes/tempo.c -c
	mv Tempo.o obj/

obj/ConfigArquivo.o: desenvolvimento_funcoes/configArquivo.c interfaces/configArquivo.h
	gcc desenvolvimento_funcoes/configArquivo.c -c
	mv configArquivo.o obj/

obj/Alternativo.o: desenvolvimento_funcoes/alternativo.c interfaces/alternativo.h
	gcc desenvolvimento_funcoes/alternativo.c -c
	mv Alternativo.o obj/

apagar:
	rm obj/* bin/tp2