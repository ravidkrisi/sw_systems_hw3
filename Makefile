graph: algo.o edges.o nodes.o main.o
	gcc -c algo.o edges.o nodes.o main.o -o graph

algo.o: algo.c graph.h
	gcc -c algo.c -o algo.o

edges.o: edges.o graph.h
	gcc -c edges.c -o edges.o

nodes.o: nodes.c graph.h
	gcc -c nodes.c -o nodes.o

main.o: main.c graph.h
	gcc -c main.c -o main.o

clean: 
	rm graph *.o 