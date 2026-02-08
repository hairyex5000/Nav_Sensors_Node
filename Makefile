all:
	g++ main.cpp lib/serialib.cpp lib/arduinojson.hpp -o test.exe
	./test.exe