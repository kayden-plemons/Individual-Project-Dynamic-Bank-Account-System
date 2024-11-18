proj3 : project3.o account.o
	g++ -o proj3 project3.o account.o

Account.o : account.cpp account.h
	g++ -c -Wall account.cpp

project3.o : project3.cpp account.h
	g++ -c -Wall project3.cpp

clean :
	rm *.o proj3