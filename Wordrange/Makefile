CXX = g++
CXXFLAGS = -g -Wall -std=c++11
SOURCES = AVL.cpp wordrange.cpp
OBJECTS = $(SOURCES:.cpp=.o)

wordrange: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o wordrange $(OBJECTS)

AVL.o: AVL.h
	$(CXX) $(CXXFLAGS) -c AVL.cpp

wordrange.o: wordrange.cpp
	$(CXX) $(CXXFLAGS) -c wordrange.cpp

clean:
	rm -f *.o
	rm wordrange