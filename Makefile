#Nemtudom mit csinálok, de remélem nem bukok bele, mert annak nagyon nem fogok örülni :D
CC=g++

CFLAGS=-c -Wall

all: petra

petra: petra.o
	$(CC) petra.o -o hello

petra.o: petra.cpp
	$(CC) $(CFLAGS) petra.cpp -std=c++11 -lexpat

clean:
	rm -rf *o petra

