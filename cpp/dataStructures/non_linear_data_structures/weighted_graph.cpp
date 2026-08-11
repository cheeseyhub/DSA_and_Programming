#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


class WeightedGraph{ 
  private:
  struct Pair {
    std::string vertex;
    int weight;


    Pair(const std::string& vertex, int weight): vertex(vertex), weight(weight){};

    std::string toString() const {
      return vertex + " { " + std::to_string(weight) + " } ";
    }
  };
  
  public:

  std::map<std::string, std::vector<Pair>> adjList;


  WeightedGraph() = default;

  void addVertex(const std::string& label){
    adjList[label] = std::vector<Pair>();



  }
  void addEdge(const std::string& vertex1, const std::string& vertex2 , int weight){
    adjList[vertex1].emplace_back(vertex2,weight);
    adjList[vertex2].emplace_back(vertex1,weight);
  }

 
      void removeEdge(const std::string& vertex1, const std::string& vertex2) {
        auto it1 = adjList.find(vertex1);
        auto it2 = adjList.find(vertex2);

        if (it1 != adjList.end()) {
            auto& list1 = it1->second;
            list1.erase(std::remove_if(list1.begin(), list1.end(),
                                        [&vertex2](const Pair& p) { return p.vertex == vertex2; }),
                        list1.end());
        }

        if (it2 != adjList.end()) {
            auto& list2 = it2->second;
            list2.erase(std::remove_if(list2.begin(), list2.end(),
                                        [&vertex1](const Pair& p) { return p.vertex == vertex1; }),
                        list2.end());
        }

    }
    
    void printGraph() const {
        for (const auto& [vertex, neighbors] : adjList) {
            std::cout << "Vertex " << vertex << " is connected to: ";
            for (const auto& pair : neighbors) {
                std::cout << pair.toString() << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    WeightedGraph graph;

    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");
    graph.addVertex("E");

    graph.addEdge("A", "B", 4);
    graph.addEdge("B", "E", 2);
    graph.addEdge("A", "C", 3);
    graph.addEdge("B", "D", 2);
    graph.addEdge("C", "D", 1);

    std::cout << "Graph before removing edge:" << std::endl;
    graph.printGraph();

    graph.removeEdge("A", "B");

    std::cout << "\nGraph after removing the edge between A and B:" << std::endl;
    graph.printGraph();

    return 0;
}
