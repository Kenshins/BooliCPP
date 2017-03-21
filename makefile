CC=g++
CFLAGS= -W -std=gnu++11 

LIBS=-lssl -lcrypto -lcurl
DEPS= jsonRetriverInterface.h jsonRetriver.h searchCondition.h listings.h address.h areas.h distance.h location.h position.h region.h result.h searchParams.h sold.h source.h curlException.h Booli.h BooliFactory.h

OBJ= jsonRetriver.o searchCondition.o listings.o address.o areas.o distance.o location.o position.o region.o result.o searchParams.o sold.o source.o Booli.o BooliFactory.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)  

boolitest : main.cpp $(OBJ)
	$(CC) -o $@ $(CFLAGS) main.cpp $(OBJ) $(LIBS)

unittest : unitTests.cpp searchCondition.cpp
	$(CC) -o $@ $(CFLAGS) unitTests.cpp searchCondition.cpp $(LIBS) -lgtest -lpthread

clean :
	rm -f *.o *~ boolitest
