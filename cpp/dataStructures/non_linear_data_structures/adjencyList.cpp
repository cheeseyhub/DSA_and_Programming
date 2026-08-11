#include <iostream>
#include <vector>

class AdjacencyListGraph{
private:
std::vector<std::vector<int>> adjList;


public:
AdjacencyListGraph() = default;




void addVertex() {
  adjList.push_back(std::vector<int>());
}

void addEdge(int vertex1, int vertex2){
  getOrCreateList(vertex1).push_back(vertex2);
  getOrCreateList(vertex2).push_back(vertex1);
}

std::vector<int>& getOrCreateList(int index)
{
  while(index >= static_cast<int> (adjList.size()))
  {
    adjList.push_back(std::vector<int>());


  }
  return adjList[index];
}

    void printGraph() const {
        for (int i = 0; i < static_cast<int>(adjList.size()); i++) {
            std::cout << "Vertex " << i << " is connected to: ";
            for (int vertex : adjList[i]) {
                std::cout << vertex << " ";
            }
            std::cout << std::endl;
        }
    }
};


int main() {
    AdjacencyListGraph graph;

    graph.addVertex();
    graph.addVertex();
    graph.addVertex();
    graph.addVertex();

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 0);

    graph.printGraph();

    return 0;
}
