#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <vector>

class Graph {
private:
    std::unordered_map<int, std::list<int>> adjList;

public:
    // Method to add a vertex
    void addVertex(int vertex) {
        adjList[vertex];  // Ensures the vertex is added
    }

    // Method to add an edge
    void addEdge(int vertex1, int vertex2) {
        adjList[vertex1].push_back(vertex2);
        adjList[vertex2].push_back(vertex1);
    }

    std::vector<int> findShortestPath(int startVertex, int endVertex)
    {
      std::queue<int> queue;
      std::unordered_map<int , int> predecessors;
      std::unordered_set<int> visited;

      queue.push(startVertex);
      visited.insert(startVertex);
      predecessors[startVertex] = -1;

      while(!queue.empty())
      {
        int currentVertex = queue.front();
        queue.pop();

        if(currentVertex == endVertex){
          return constructPath(endVertex,predecessors);
        }
        for(int neighbor : adjList[currentVertex])
        {
          if(visited.find(neighbor) == visited.end()){
          queue.push(neighbor);
          visited.insert(neighbor);
          predecessors[neighbor] = currentVertex;
          }
        }
      }
      return {};
    }
    private:
    std::vector<int> constructPath(int endVertex, std::unordered_map<int,int>& predecessors)
    {
std::vector<int> path;
for(int vertex = endVertex; vertex != -1; vertex= predecessors[vertex])
{
  path.push_back(vertex);
}
std::reverse(path.begin(),path.end());
return path;
    }
};
int main() {
    Graph graph;

    // Add vertices
    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Find the shortest path from 0 to 4
    std::vector<int> shortestPath = graph.findShortestPath(0, 4);
    std::cout << "Shortest path from 0 to 4: ";
    for (int vertex : shortestPath) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    return 0;
}
