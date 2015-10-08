.PHONY=main

CFLAGS += $(shell Magick++-config --cflags --libs)

main: src/main.cpp
	mkdir -p bin
	$(CXX) -o bin/main -std=c++14 -pthread -pedantic -Wall -Wextra -O3 -Isrc src/main.cpp $(CFLAGS)

clean:
	rm -rf bin/*
