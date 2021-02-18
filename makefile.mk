link_list: driver.o
	g++ -o link_list driver.o

driver.o: driver.cpp linked_list.h
	g++ -c driver.cpp

clear:
	rm*.o link_list