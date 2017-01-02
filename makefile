CC=g++
CFLAGS= -W -std=gnu++11 

LIBS=-lssl -lcrypto -lcurl
DEPS= Booli.h retriver.h searchCondition.h listings.h address.h areas.h distance.h location.h position.h region.h result.h searchParams.h sold.h source.h

OBJ= Booli.o retriver.o searchCondition.o listings.o address.o areas.o distance.o location.o position.o region.o result.o searchParams.o sold.o source.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)  

BooliTest : main.cpp $(OBJ)
	$(CC) $(CFLAGS) main.cpp $(OBJ) $(LIBS)
