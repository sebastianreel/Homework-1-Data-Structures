linkedlist: driver.o
	g++ driver.o -o linkedlist

driver.o: driver.cpp linkedlist.h
	g++ -c driver.cpp

clean: 
	rm*.o