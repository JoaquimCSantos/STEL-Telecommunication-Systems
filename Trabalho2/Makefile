
mushu: lista_ligada.o ajuda_mushu.o mushu.o
	gcc  lista_ligada.o ajuda_mushu.o mushu.o -o mushurun


lista_ligada.o: lista_ligada.c
	gcc -c lista_ligada.c

ajuda_mushu.o: ajuda_mushu.c
	gcc -c ajuda_mushu.c

mushu.o: mushu.c
	gcc -c mushu.c

clean:
	clear
	rm -f *.o mushu mushurun grili grilirun

mushurun: mushu
	clear
	./muhsurun

