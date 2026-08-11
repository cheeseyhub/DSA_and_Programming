#include <iostream>

class AdjacencyMatrixGraph {

  private:
  bool** adjMatrix;
  int numVertices;


  public:
  AdjacencyMatrixGraph(int numVertices);
  ~AdjacencyMatrixGraph();
  void addEdge(int i , int j);
  void removeEdge(int i , int j );
  void printMatrix();
};

AdjacencyMatrixGraph::AdjacencyMatrixGraph(int numVertices){
  this->numVertices = numVertices;

  adjMatrix = new bool*[numVertices];
  for(int i = 0; i < numVertices; i++)
  {
    adjMatrix[i] = new bool[numVertices];
    for(int j = 0; j < numVertices;j++)
    {
      adjMatrix[i][j] = false;
    }
  }
}
AdjacencyMatrixGraph::~AdjacencyMatrixGraph(){
  for(int i = 0 ; i < numVertices; i++)
  {
    delete[] adjMatrix[i];
  }
  delete[] adjMatrix;
}
void AdjacencyMatrixGraph::addEdge(int i , int j){
  adjMatrix[i][j] = true;
  adjMatrix[j][i] = true;


}
void AdjacencyMatrixGraph::removeEdge(int i , int j)
{
  adjMatrix[i][j] = false;
  adjMatrix[j][i] = false;
}

void AdjacencyMatrixGraph::printMatrix() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            std::cout << (adjMatrix[i][j] ? 1 : 0) << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    AdjacencyMatrixGraph graph(4);

    // Adding edges
    graph.addEdge(0, 1); // Edge A-B
    graph.addEdge(0, 2); // Edge A-C
    graph.addEdge(1, 3); // Edge B-D
    graph.addEdge(2, 3); // Edge C-D

    std::cout << "Initial Graph:" << std::endl;
    graph.printMatrix();

    std::cout << "\nGraph after removing edge B-D:" << std::endl;
    graph.removeEdge(1, 3); // Removing Edge B-D
    graph.printMatrix();

    return 0;
}
