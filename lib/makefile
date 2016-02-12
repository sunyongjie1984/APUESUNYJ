all : libApueSunyj.a
libApueSunyj.a: error.o
	ar cr libApueSunyj.a error.o
error.o: error.cpp apuesunyj.h
	g++ -c -g -Wall error.cpp -o error.o
clean:
	rm -rf error.o libApueSunyj.a
