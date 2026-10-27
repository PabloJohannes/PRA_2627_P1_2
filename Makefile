all: testDyV testProgDin

testDyV.o: testDyV.cpp DyV.h
	g++ -c testDyV.cpp

testProgDin.o: testProgDin.cpp ProgDin.h
	g++ -c testProgDin.cpp

testDyV: testDyV.o
	g++ -o testDyV testDyV.o

testProgDin: testProgDin.o
	g++ -o testProgDin testProgDin.o

clean:
	rm -r *.o *.gch *.pch testDyV testProgDin
