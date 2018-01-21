#Name: Sahar Levi
#ID: 203405147
#Name: Or Sharabi
#ID: 312530496

server.out: compileAll
	g++ -pthread -o ../../exe/server.out *.o
	rm -f *.o

compileAll: *.h *.cpp
	    g++ -c *.cpp

run:
	./server.out
