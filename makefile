CC = g++
CFLAGS = -Wall -Wextra -pedantic -std=c++11

all: main

main: main.o Bill.o Payment.o SubBill.o
	$(CC) $(CFLAGS) -o main main.o Bill.o Payment.o SubBill.o

main.o: main.cpp Bill.h Payment.h SubBill.h
	$(CC) $(CFLAGS) -c main.cpp

Bill.o: Bill.h
	$(CC) $(CFLAGS) -c Bill.cpp

Payment.o: Payment.h Bill.h
	$(CC) $(CFLAGS) -c Payment.cpp

SubBill.o: SubBill.h Bill.h
	$(CC) $(CFLAGS) -c SubBill.cpp

run: main
	./main

clean:
	rm -f main main.o Bill.o Payment.o SubBill.o