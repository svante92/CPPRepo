CXX = g++
CXXFLAGS = -g -Wall -std=c++11
SOURCES = graph.cpp sixdegrees.cpp
OBJECTS = $(SOURCES:.cpp=.o)

sixdegrees: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o sixdegrees $(OBJECTS)

graph.o: graph.h
	$(CXX) $(CXXFLAGS) -c graph.cpp

sixdegrees.o: sixdegrees.cpp
	$(CXX) $(CXXFLAGS) -c sixdegrees.cpp

clean:
	rm -f *.o
	rm sixdegrees