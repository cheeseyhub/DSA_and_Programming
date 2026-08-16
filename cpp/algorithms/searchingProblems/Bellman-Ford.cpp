#include <iostream>
#include <limits>
#include <cstring>
#include <climits>


class Edge {
  public:
  int source , destintation,weight;
  Edge(int s , int d , int w): source(s), destintation(d) , weight(w) {};


};

void printSolution(int* distances, int vertices) {
    std::cout << "Vertex\t| Distance from Source" << std::endl;
    for (int i = 0; i < vertices; i++) {
        std::cout << i << "\t|\t" << (distances[i] == INT_MAX ? "INF" : std::to_string(distances[i])) << std::endl;
    }
}


void bellamanFord(Edge* edges, int edgeCount, int vertices, int source)
{
  int* distances = new int [vertices];
  std::fill(distances, distances+ vertices, INT_MAX);
  distances[source] = 0;


  for(int i = 1; i <vertices; i++)
  {
    for (int j = 0 ; j < edgeCount ; j++)
    {
      Edge edge = edges[j];

      if(distances[edge.source] != INT_MAX &&
      distances[edge.source] + edge.weight < distances[edge.destintation]
    ){
      distances[edge.destintation] = distances[edge.source] + edge.weight;
    }


    }
    for( int j = 0 ; j < edgeCount; j++)
    {
      Edge edge = edges[j];

      if(distances[edge.source] != INT_MAX && distances[edge.source] + edge.weight < distances[edge.destintation]){
        std::cout << "Graph contains a negative cycle. " << std::endl;
        delete[] distances;
        return;
      }
    }
  }
  printSolution(distances,vertices);
  delete[] distances;
}

int main() {
 int vertices = 5;
    int edgeCount = 8;
    int source = 0;
    Edge edges[] = {
        Edge(0, 1, -1),
        Edge(0, 2, 4),
        Edge(1, 2, 3),
        Edge(1, 3, 2),
        Edge(1, 4, 2),
        Edge(3, 2, 5),
        Edge(3, 1, 1),
        Edge(4, 3, -3)
    };

    bellmanFord(edges, edgeCount, vertices, source);
    return 0;
}
