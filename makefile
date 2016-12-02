BooliTest : main.cpp BooliAPI.o
	g++ -lssl -lcrypto -lcurl BooliAPI.o main.cpp

BooliAPI.o: Booli.o Retriver.o Result.o SearchCondition.o
	ld -r -o BooliAPI.o Retriver.o Booli.o Result.o SearchCondition.o

Booli.o : Booli.cpp Booli.h
	g++ -c Booli.cpp

Retriver.o: Retriver.cpp Retriver.h
	g++ -c Retriver.cpp

Result.o: Result.cpp Result.h
	g++ -c Result.cpp

SearchCondition.o: SearchCondition.cpp SearchCondition.h
	g++ -c SearchCondition.cpp
