BooliTest : main.cpp Booli.o Retriver.o
	g++ -lssl -lcrypto -lcurl Booli.o Retriver.o main.cpp

Booli.o : Booli.cpp Booli.h Retriver.cpp Retriver.h
	g++ -c Booli.cpp Retriver.cpp

