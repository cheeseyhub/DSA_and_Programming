#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Node {
  public:
  int vertex, weight;
  Node(int v, int w): vertex(v), weight(w) {};


  bool operator<(const Node& other) const {
    return weight > other.weight;
  }
};
void printSolution(const std::vector<int>& distances) {
    std::cout << "Vertex\t| Distance from Source" << std::endl;
    for (int i = 0; i < distances.size(); i++) {
        std::cout << i << "\t|\t" << (distances[i] == INT_MAX ? "INF" : std::to_string(distances[i])) << std::endl;
    }
}

void dijkstra(const std::vector <std::vector<int>>& graph, int source)
{
  std::priority_queue<Node> queue;

  std::vector<int> distances(graph.size(), INT_MAX);
  std::vector<bool> visited(graph.size(), false);

  distances[source] = 0;
  queue.push(Node(source, 0));

  while(!queue.empty())
  {
    Node current = queue.top();
    queue.pop();
    int vertex = current.vertex;
    if(visited[vertex]) continue;

    visited[vertex] = true;

    for(int i = 0 ; i < graph.size(); i++)
    {
      if (graph[vertex][i] > 0 && !visited[i]){
        int newDist = distances[vertex] + graph[vertex][i];
        if(newDist < distances[i])
        {
          distances[i] = newDist;
          queue.push(Node(i,distances[i]));
        }
      }
    }
  }
  printSolution(distances);
}

int main() {


  int source = 0 ;
   std::vector <std::vector<int>> graph = {
    {0, 6, 0, 1, 0},
        {6, 0, 5, 2, 2},
        {0, 5, 0, 0, 5},
        {1, 2, 0, 0, 1},
        {0, 2, 5, 1, 0}
   };
   dijkstra(graph,source);
  return 0;
}
