#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <queue>
#include <utility>

class Graph {
public:
    void addMovie(const std::string& movie, const std::vector<std::string>& actors);
    std::string findShortestPath(const std::string& actor1, const std::string& actor2);

private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjacencyList;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> movieMap;
};

#endif // GRAPH_H
