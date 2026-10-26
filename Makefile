all: testDyV

testDyV.o: testDyV.cpp DyV.h
	g++ -c testDyV.cpp


testDyV: testDyV.o
	g++ -o testDyV testDyV.o

clean:
	rm -r *.o *.gch *.pch testDyV
