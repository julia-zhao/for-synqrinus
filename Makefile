all: make_q1 make_bonus

make_q1:	q1.cpp q1.h
	g++ -std=c++11 -o q1 q1.cpp

make_bonus:	q1_bonus.cpp q1_bonus.h
	g++ -std=c++11 -o bonus q1_bonus.cpp

clean:
	rm q1 bonus
