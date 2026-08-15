//FREEZE CODE BEGIN
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

class Vertex;
class Edge {
private:
    Vertex* target;  
    int weight;

public:
    Edge(Vertex* target, int weight);
    int getWeight() const;
    void setWeight(int newWeight);
    Vertex* getTarget() const;
    bool operator==(const Edge& other) const;
};

class Vertex {
private:
    int id;
    std::vector<Vertex*> neighbors;  
    std::vector<Edge> edges;

public:
    Vertex(int id);
    int getId() const;
    void addNeighbor(Vertex* neighbor, int weight);
    const std::vector<Vertex*>& getNeighbors() const;
    int getWeight(int index) const;
    void updateWeight(int index, Vertex* target, int newWeight);
    bool operator==(const Vertex& other) const;
    std::string toString() const;
};

Edge::Edge(Vertex* target, int weight) : target(target), weight(weight) {}

int Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(int newWeight) {
    weight = newWeight;
}

Vertex* Edge::getTarget() const {
    return target;
}

bool Edge::operator==(const Edge& other) const {
    return target->getId() == other.target->getId();
}

Vertex::Vertex(int id) : id(id) {}

int Vertex::getId() const {
    return id;
}

void Vertex::addNeighbor(Vertex* neighbor, int weight) {
    neighbors.push_back(neighbor);
    edges.emplace_back(neighbor, weight);
}

const std::vector<Vertex*>& Vertex::getNeighbors() const {
    return neighbors;
}

int Vertex::getWeight(int index) const {
    return edges.at(index).getWeight();
}

void Vertex::updateWeight(int index, Vertex* target, int newWeight) {
    edges.at(index).setWeight(newWeight);
}

bool Vertex::operator==(const Vertex& other) const {
    return id == other.id;
}

std::string Vertex::toString() const {
    return std::to_string(id);
}

class Graph {
private:
    std::vector<Vertex> vertices;

public:
    Graph(int numVertices);
    void addEdge(int source, int target, int weight);
    void printGraph() const;
    int getSize() const;
    std::vector<Vertex>& getVertices();
    const std::vector<Vertex>& getVertices() const;
};

Graph::Graph(int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        vertices.emplace_back(i);
    }
}

void Graph::addEdge(int source, int target, int weight) {
    Vertex& sourceVertex = vertices.at(source);
    Vertex& targetVertex = vertices.at(target);
    sourceVertex.addNeighbor(&targetVertex, weight);
}

void Graph::printGraph() const {
    for (const Vertex& vertex : vertices) {
        std::cout << "Vertex " << vertex.getId() << ":";
        const std::vector<Vertex*>& neighbors = vertex.getNeighbors();
        for (size_t i = 0; i < neighbors.size(); ++i) {
            int weight = vertex.getWeight(i);
            std::cout << " -> " << neighbors.at(i)->getId() << " (" << weight << ")";
        }
        std::cout << std::endl;
    }
}

int Graph::getSize() const {
    return vertices.size();
}

std::vector<Vertex>& Graph::getVertices() {
    return vertices;
}

const std::vector<Vertex>& Graph::getVertices() const {
    return vertices;
}
class GraphMerger {
  public:
  static void addEdge(Graph& graph,
    int sourceIndex,
    const Vertex& currentVertex,
    const Vertex* neighbor,
    const std::vector<Vertex*>& neighbors
  )
  {

    int targetIndex = neighbor->getId();
    auto it = std::find(neighbors.begin(),neighbors.end(), neighbor);
    if(it != neighbors.end())
    {
      int neighborIndex = std::distance(neighbors.begin(), it);
      int weight = currentVertex.getWeight(neighborIndex);
      graph.addEdge(sourceIndex, targetIndex, weight);
    }
  }

  static Graph mergeGraphs(const Graph& graph1, const Graph& graph2)
  {
    int totalVertices = std::max(graph1.getSize(), graph2.getSize());
    Graph mergedGraph(totalVertices);


    for(int i = 0 ; i < graph1.getSize(); ++i){

    const Vertex& vertex = graph1.getVertices().at(i);


    const std::vector<Vertex*>& neighbors = vertex.getNeighbors();


    for(const Vertex* neighbor: neighbors)
    {
      addEdge(mergedGraph, i , vertex, neighbor, neighbors);
    }
  }


    for (int i = 0 ; i < graph2.getSize(); ++i){

      const Vertex& vertex = graph2.getVertices().at(i);
      const std::vector<Vertex*>& neighbors = vertex.getNeighbors();

      for (const Vertex* neighbor : neighbors){
        addEdge(mergedGraph,i,vertex,neighbor,neighbors);
      }

    
  }
  return mergedGraph;

    
    
  }
};





int main() {
    int numVertices = 6;
    
    Graph graph1(numVertices);
    graph1.addEdge(0, 1, 2);
    graph1.addEdge(0, 3, 1);
    graph1.addEdge(1, 2, 3);
    graph1.addEdge(2, 4, 5);

    Graph graph2(numVertices);
    graph2.addEdge(1, 2, 4);
    graph2.addEdge(5, 3, 3);
    graph2.addEdge(2, 4, 1);
    graph2.addEdge(4, 5, 0);

    std::cout << "Graph 1:" << std::endl;
    graph1.printGraph();
    std::cout << std::endl;

    std::cout << "Graph 2:" << std::endl;
    graph2.printGraph();
    std::cout << std::endl;

    Graph mergedGraph = GraphMerger::mergeGraphs(graph1, graph2);
    std::cout << "Merged Graph:" << std::endl;
    mergedGraph.printGraph();

    return 0;

}

