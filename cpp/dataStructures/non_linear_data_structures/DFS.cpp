#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>


class Graph {
  private:
  std::unordered_map<std::string,std::vector<std::string>> adjList;


  public:
  Graph() {
  adjList = std::unordered_map<std::string,std::vector<std::string>>();

  }


  void addVertex(const std::string& label)
  {
    adjList.emplace(label,std::vector<std::string>());
  }
  void addEdge(const std::string& vertex1, const std::string& vertex2)
  {
    adjList[vertex1].push_back(vertex2);
    adjList[vertex2].push_back(vertex1);
  }
  void dfs(const std::string& start){
    std::unordered_set<std::string> visited;
    dfs(start,visited);
  }
  private:
  void dfs(const std::string& vertex, std::unordered_set<std::string>& visited){
    if(visited.find(vertex) != visited.end())
    {
      return;
    }
    visited.insert(vertex);
    std::cout << vertex << " ";

    const std::vector<std::string>& neighbors = adjList[vertex];
    for(const std::string& next : neighbors){
      dfs(next,visited);
    }
  }
};

int main() {
  Graph graph;
  std::string vertices[]  = {"A", "B", "C", "D", "E"};

  for(const std::string& vertex : vertices)
  {
    graph.addVertex(vertex);
  }
  
    graph.addEdge("A", "C");
    graph.addEdge("A", "B");
    graph.addEdge("C", "E");
    graph.addEdge("B", "D");
    graph.addEdge("D", "C");
    graph.addEdge("D", "E");

    std::cout << "DFS Traversal starting from vertex A:" << std::endl;
    graph.dfs("A");

    return 0;
}

