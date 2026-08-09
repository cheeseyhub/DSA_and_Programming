#include <iostream>
#include <map>
#include <list>
#include <string>


class Graph {
  private:
  std::map<std::string, std::list<std::string>> adjList;



  public:
  Graph() {
  }

  void addVertex(const std::string& label)
{
  adjList[label] = std::list<std::string>();
  
}

void addEdge(const std::string& vertex1, const std::string& vertex2)
{
  adjList[vertex1].push_back(vertex2);
  adjList[vertex2].push_back(vertex1);
}

    void printGraph() const {
        for (const auto& vertex : adjList) {
            std::cout << "Vertex " << vertex.first << " is connected to: ";
            for (const auto& edge : vertex.second) {
                std::cout << edge << " ";
            }
            std::cout << std::endl;
        }
    }




};
int main() {
    Graph graph;

    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");

    graph.addEdge("A", "B");
    graph.addEdge("A", "C");
    graph.addEdge("B", "D");
    graph.addEdge("C", "D");


    return 0;
}
