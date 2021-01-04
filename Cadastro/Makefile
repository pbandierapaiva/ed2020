C = gcc
all: cad criaind
cad : cad.o util.o
	$(C) -o cad cad.o util.o
criaind : criaind.o util.o
	$(C) -o criaind criaind.o util.o

cad.o : cad.c cadastro.h
	$(C) cad.c -c -g
criaind.o : criaind.c cadastro.h
	$(C) criaind.c -c -g
util.o : util.c cadastro.h 
	$(C) util.c -c -g


