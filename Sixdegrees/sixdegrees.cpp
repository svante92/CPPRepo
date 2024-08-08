#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void parseMovieList(const std::string& filename, Graph& graph) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string movie;
        iss >> movie;
        std::vector<std::string> actors;
        std::string actor;
        while (iss >> actor) {
            actors.push_back(actor);
        }
        graph.addMovie(movie, actors);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./sixdegrees <input_file> <output_file>" << std::endl;
        return 1;
    }

    Graph graph;
    parseMovieList("cleaned_movielist.txt", graph);

    std::ifstream inputFile(argv[1]);
    std::ofstream outputFile(argv[2]);
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string actor1, actor2;
        iss >> actor1 >> actor2;
        std::string result = graph.findShortestPath(actor1, actor2);
        outputFile << result << "\n";
    }

    return 0;
}
