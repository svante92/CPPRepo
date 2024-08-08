#include "graph.h"
#include <sstream>
#include <set>
#include <algorithm>

void Graph::addMovie(const std::string& movie, const std::vector<std::string>& actors) {
    for (const auto& actor : actors) {
        for (const auto& coActor : actors) {
            if (actor != coActor) {
                adjacencyList[actor].insert(coActor);
                movieMap[actor][coActor] = movie;
            }
        }
    }
}

std::string Graph::findShortestPath(const std::string& actor1, const std::string& actor2) {
    if (adjacencyList.find(actor1) == adjacencyList.end() || adjacencyList.find(actor2) == adjacencyList.end()) {
        return "Not present";
    }
    if (actor1 == actor2) {
        return actor1;
    }

    std::unordered_map<std::string, std::string> parent;
    std::queue<std::string> toVisit;
    toVisit.push(actor1);
    parent[actor1] = "";

    while (!toVisit.empty()) {
        std::string current = toVisit.front();
        toVisit.pop();

        for (const auto& neighbor : adjacencyList[current]) {
            if (parent.find(neighbor) == parent.end()) {
                parent[neighbor] = current;
                toVisit.push(neighbor);
                if (neighbor == actor2) {
                    std::string path = neighbor;
                    std::string temp = neighbor;
                    while (temp != actor1) {
                        std::string next = parent[temp];
                        path = next + " -(" + movieMap[next][temp] + ")- " + path;
                        temp = next;
                    }
                    return path;
                }
            }
        }
    }
    return "Not present";
}
