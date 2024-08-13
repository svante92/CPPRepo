CXX = g++
CXXFLAGS = -g -Wall
SOURCES = linkedlist.cpp bard.cpp
OBJECTS = $(SOURCES:.cpp=.o)

bard: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o bard $(OBJECTS)

linkedlist.o: linkedlist.h
	$(CXX) $(CXXFLAGS) -c linkedlist.cpp

bard.o: bard.cpp
	$(CXX) $(CXXFLAGS) -c bard.cpp

clean:
	rm -f *.o
	rm bard
