all:
	$(info  ----- Usage ------)
	$(info a: make a)
	$(info b: make b)
	$(info c: make c)
	$(info clean: make clean)
	$(info  ------ end ------)	
mushuc.o: mushuc.c
	gcc -c mushuc.c -lm
	
c: lista_ligada.o ajuda_mushu.o mushuc.o 
	gcc  lista_ligada.o ajuda_mushu.o mushuc.o -o mushuruna -lm
	./mushuruna


mushub.o: mushub.c
	gcc -c mushub.c
	
b: lista_ligada.o ajuda_mushu.o mushub.o
	gcc  lista_ligada.o ajuda_mushu.o mushub.o -o mushuruna -lm
	./mushuruna

mushua.o: mushua.c
	gcc -c mushua.c
	
a: lista_ligada.o ajuda_mushu.o mushua.o
	gcc  lista_ligada.o ajuda_mushu.o mushua.o -o mushuruna -lm
	./mushuruna

mushu.o: mushu.c
	gcc -c mushu.c -lm 

mushu: lista_ligada.o ajuda_mushu.o mushu.o
	gcc  lista_ligada.o ajuda_mushu.o mushu.o -o mushurun -lm 


lista_ligada.o: lista_ligada.c
	gcc -c lista_ligada.c -lm

ajuda_mushu.o: ajuda_mushu.c
	gcc -c ajuda_mushu.c -lm


clean:
	clear
	rm -f *.o mushu mushurun grili grilirun

mushurun: mushu
	clear
	./muhsurun