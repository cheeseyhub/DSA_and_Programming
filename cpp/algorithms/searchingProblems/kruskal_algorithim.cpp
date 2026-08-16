#include <iostream>
#include <algorithm>

class Graph {


  public:
  class Edge {
    public:
    int src, dest , weight;
    bool operator <(const Edge& other) const {
      return weight < other.weight;
    }
  };

  int numVertices, numEdges;
  Edge* edges;
  Graph(int v, int e) {
    numVertices = v;

    numEdges = e;

    edges = new Edge[numEdges];
  }
  ~Graph() {
    delete[] edges;
  }
  int find(std::vector<int> disjoint, int i)
  {
    if (disjoint[i] == -1)
    return i;
  return find(disjoint,disjoint[i]);
  }
  void unionSets(std::vector<int> disjoint, int x, int y)
  {
    int xSet = find(disjoint,x);
    int ySet = find(disjoint,y);


    disjoint[xSet] = ySet;
  }


  Edge* kruskalMST() {
    Edge* result = new Edge[numVertices - 1];
    int resultIndex = 0;
    int sortedIndex= 0;
    std::sort(edges,edges + numEdges);



    std::vector<int> disjoint(numVertices, -1);

    while(resultIndex < numVertices - 1)
    {
      Edge nextEdge = edges[sortedIndex++];
      int x = find(disjoint, nextEdge.src);
      int y = find(disjoint , nextEdge.dest);

      if(x !=y){
        result[resultIndex++] = nextEdge;
        unionSets(disjoint,x,y);
      }

    }
    return result;
  }

};

int main() {
    int numVertices = 4;
    int numEdges = 5;
    Graph graph(numVertices, numEdges);

    graph.edges[0].src = 0;
    graph.edges[0].dest = 1;
    graph.edges[0].weight = 10;

    graph.edges[1].src = 0;
    graph.edges[1].dest = 2;
    graph.edges[1].weight = 6;

    graph.edges[2].src = 0;
    graph.edges[2].dest = 3;
    graph.edges[2].weight = 5;

    graph.edges[3].src = 1;
    graph.edges[3].dest = 3;
    graph.edges[3].weight = 15;

    graph.edges[4].src = 2;
    graph.edges[4].dest = 3;
    graph.edges[4].weight = 4;

    Graph::Edge* result = graph.kruskalMST();

    std::cout << "Edges in the minimum spanning tree:\n";
    for (int i = 0; i < numVertices - 1; ++i) {
        std::cout << "Edge from vertex " << result[i].src
                  << " to vertex " << result[i].dest
                  << " with weight " << result[i].weight << std::endl;
    }

    delete[] result;
    return 0;
}
