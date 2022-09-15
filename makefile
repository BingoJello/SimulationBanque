
OBJ = Arrival.o Bank.o Cashier.o Client.o Departure.o Event.o Queue.o Simulation.o main.o

all: depend simulbank

simulbank: $(OBJ)
	c++ -o simulbank.out $(OBJ)

depend:
	sed '/^#DEP/q' Makefile > mk.tmp
	c++ -M *.cpp >> mk.tmp
	mv mk.tmp Makefile


clean: clean_o
	rm -rfv mk.tmp
	rm -rfv *.out

clean_o:
	rm -rfv *.o

#DEPENDENCIES: list of dependencies do not remove