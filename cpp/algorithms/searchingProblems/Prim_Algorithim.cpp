#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <functional>
#include <queue>


// This is an algorithm that finds the Minimum Spanning Tree by 
// Steps of Prim’s Algorithm
//Initialization: Start with a vertex, marking it as part of the MST. Initialize a priority queue with all edges from this vertex, sorted by their weights.
//Iterate Until the MST is Complete: Repeat the following steps until the MST includes all vertices:
//Extract the minimum weight edge from the priority queue.
//If the edge connects to a vertex not already in the MST, add the vertex to the MST and add all its edges to the priority queue.
//If the edge connects to a vertex already in the MST, discard the edge.
//Finalize the MST: Once all vertices are included in the MST, the algorithm terminates, and the MST is complete.

class Graph{


  public:

  class Edge {
    public:
     int vertex, weight;

    Edge( int v, int w): vertex(v),weight(w){

    }

            friend std::ostream& operator<<(std::ostream& os, const Edge& e) {
                os << e.vertex << " \t" << e.weight;
                return os;
            }
  };

  int numVertices;
  std::map<int, std::vector<Edge>> adjList;

  void addVertex(int vertex)
  {
    adjList[vertex] = std::vector<Edge>();
  }

  public:
  Graph(int vertices): numVertices(vertices) {
    for(int i = 0 ; i < numVertices; i++)
      addVertex(i);
    


    }
    void addEdge(int vertex1, int vertex2 , int weight)
    {
      adjList[vertex1].push_back(Edge(vertex2,weight));
      adjList[vertex2].push_back(Edge(vertex1,weight));
    }

    Graph primMST() {
      std::vector <bool> inMST(numVertices, false);
      std::vector <int> minWeights(numVertices, std::numeric_limits<int>::max());
      std::vector<int> edges(numVertices, -1);
      minWeights[0] = 0;

      auto cmp = [](const Edge& left, const Edge& right){
        return left.weight > right.weight;
      };
        std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> pq(cmp);


      pq.push(Edge(0,0));
      while(!pq.empty())
      {
        int current = pq.top().vertex;
        pq.pop();
        inMST[current] = true;

        for(const Edge& edge : adjList[current])
        {
          int neighbor = edge.vertex;
          int neighborWeight =edge.weight;
          if(!inMST[neighbor] && neighborWeight < minWeights[neighbor])
          {
            minWeights[neighbor] = neighborWeight;
            edges[neighbor] = current;
            pq.push(Edge(neighbor, neighborWeight));
          }
        }
      }

      Graph mst(numVertices);
      for(int i = 1 ; i < numVertices; i++)
      {
        mst.addEdge(edges[i], i, minWeights[i]);

      }
      return mst;
    }

   void printGraph() const {
        for (const auto& entry : adjList) {
            for (const Edge& edge : entry.second) {
                int source = entry.first;
                if (source < edge.vertex) {
                    std::cout << source << " - " << edge << std::endl;
                }
            }
        }
    }
  

};
int main() {
    Graph graph(5);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 8);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(3, 4, 9);

    Graph mst = graph.primMST();
    std::cout << "Edge\tWeight" << std::endl;
    mst.printGraph();

    return 0;
}
