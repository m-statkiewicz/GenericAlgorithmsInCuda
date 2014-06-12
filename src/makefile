all: clean mainTest

install:
	mkdir ../target
	mv *.o ../target
	mv networkGenerator ../target

clean:
	rm -Rf ../target
	rm -rf *.o networkGenerator

mainTest: main.o function.o strategy.o 
	g++ main.o function.o strategy.o -o mainTest

main.o: 
	g++ -c main.cpp

function.o: function.cpp function.h 
	g++ -c function.cpp 

strategy.o: strategy.cpp strategy.h
	g++ -c strategy.cpp

