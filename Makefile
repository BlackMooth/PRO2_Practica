#MAKEFILE

OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

#Instruccio per generar el tar
practica.tar: program.exe
	tar -cvf practica.tar Magatzem.cc Magatzem.hh Sala.cc Sala.hh Inventari.cc Inventari.hh program.cc

program.exe: program.o Inventari.o Sala.o Magatzem.o
	g++ -o program.exe program.o Inventari.o Sala.o Magatzem.o

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Inventari.o: Inventari.cc
	g++ -c Inventari.cc $(OPCIONS)

Sala.o: Sala.cc
	g++ -c Sala.cc $(OPCIONS)

Magatzem.o: Magatzem.cc Sala.hh
	g++ -c Magatzem.cc $(OPCIONS)

clear:
	rm *.o
	rm *.exe
