main : main.o complex.o lodepng.o
	g++ -o main  main.o complex.o lodepng.o

main.o : main.cpp complex.h lodepng.h rgb.h
	g++ -c main.cpp

complex.o : complex.cpp complex.h
	g++ -c complex.cpp

lodepng.o : lodepng.cpp lodepng.h
	g++ -c lodepng.cpp
