#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <unordered_set>
#include <string>


class Graph {
  private:
  std::unordered_map<std::string,std::list<std::string>>adjList;

  public:
  void addVertex(const std::string& label)
  {
    adjList[label];
  }
  void addEdge(const std::string& vertex1, const std::string& vertex2)
  {
    adjList[vertex1].push_back(vertex2);
  }

void bfs(const std::string& start)
{
  std::unordered_set<std::string> visited;
  std::queue<std::string>   queue;

  queue.push(start);

  while(!queue.empty())
  {
    std::string vertex = queue.front();
    queue.pop();
    std::cout << vertex << " ";

    const auto& neighbors = adjList[vertex];
    for(const auto& next :neighbors){
      if(visited.find(next) == visited.end())
      {
        visited.insert(next);
        queue.push(next);
      }
    }
  }
}
};

int main() {
  Graph graph;
  std::string vertices[] = {"A","B","C","D","E"};

  for(const auto& vertex : vertices)
  {
    graph.addVertex(vertex);
  }
   graph.addEdge("A", "C");
    graph.addEdge("A", "B");
    graph.addEdge("C", "E");
    graph.addEdge("B", "D");
    graph.addEdge("D", "C");
    graph.addEdge("D", "E");



    std::cout << "BFS Traversal starting from vertex A:" << std::endl;
    graph.bfs("A");

    return 0;
}
