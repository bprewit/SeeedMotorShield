PRJ = MotorTest

CFLAGS = -lrt -lpthread -fpermissive
SRC = arduPi.cpp SeeedMotorShield.cpp main.cpp

all:
	g++ $(CFLAGS) $(SRC) -o $(PRJ)

.PHONY : clean
clean:
	-rm $(PRJ) *~
