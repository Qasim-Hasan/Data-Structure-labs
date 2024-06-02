//Lab 12
//BCS-3J
//21K3210
//Qasim Hasan
//Task 1
#include<iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;
class Edge;
class Vertex;
class Edge {
  public:
    int DestinationVertexID;
  int weight;

  Edge() {}
  Edge(int destVID, int w) {
    DestinationVertexID = destVID;
    weight = w;
  }
  void setEdgeValues(int destVID, int w) {
    DestinationVertexID = destVID;
    weight = w;
  }
  void setWeight(int w) {
    weight = w;
  }
  int getDestinationVertexID() {
    return DestinationVertexID;
  }
  int getWeight() {
    return weight;
  }
};

class Vertex {
  public:
    int state_id;
  string state_name;
  list < Edge > edgeList;
  Vertex() {
    state_id = 0;
    state_name = "";
  }
  Vertex(int id, string sname) {
    state_id = id;
    state_name = sname;
  }
  int getStateID() {
    return state_id;
  }
  string getStateName() {
    return state_name;
  }
  void setID(int id) {
    state_id = id;
  }
  void setStateName(string sname) {
    state_name = sname;
  }

  list < Edge > getEdgeList() {
    return edgeList;
  }
  void printEdgeList() {
    cout << "[";
    for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
      cout << it -> getDestinationVertexID() << "(" << it -> getWeight() << ") --> ";
    }
    cout << "]";
    cout << endl;
  }
  void updateVertexName(string sname) {
    state_name = sname;
    cout << "Vertex Name Updated Successfully";
  }
};

class Graph {

  vector < Vertex > vertices;

  public:

    bool checkIfVertexExistByID(int vid) {
      bool flag = false;
      for (int i = 0; i < vertices.size(); i++) {
        if (vertices.at(i).getStateID() == vid) {
          return true;
        }
      }
      return flag;
    }

  void addVertex(Vertex newVertex) {
    bool check = checkIfVertexExistByID(newVertex.getStateID());
    if (check == true) {
      cout << "Vertex with this ID already exist" << endl;
    } else {
      vertices.push_back(newVertex);
      cout << "New Vertex Added Successfully" << endl;
    }
  }

  Vertex getVertexByID(int vid) {
    Vertex temp;
    for (int i = 0; i < vertices.size(); i++) {
      temp = vertices.at(i);
      if (temp.getStateID() == vid) {
        return temp;
      }
    }
    return temp;
  }

  bool checkIfEdgeExistByID(int fromVertex, int toVertex) {
    Vertex v = getVertexByID(fromVertex);
    list < Edge > e;
    e = v.getEdgeList();
    bool flag = false;
    for (auto it = e.begin(); it != e.end(); it++) {
      if (it -> getDestinationVertexID() == toVertex) {
        flag = true;
        return flag;
        break;
      }

    }
    return flag;
  }
  void addEdgeByID(int fromVertex, int toVertex, int weight) {
    bool check1 = checkIfVertexExistByID(fromVertex);
    bool check2 = checkIfVertexExistByID(toVertex);

    bool check3 = checkIfEdgeExistByID(fromVertex, toVertex);
    if ((check1 && check2 == true)) {
      if (check3 == true) {
        cout << "Edge between " << getVertexByID(fromVertex).getStateName() << "(" << fromVertex << ") and " << getVertexByID(toVertex).getStateName() << "(" << toVertex << ") Already Exist" << endl;
      } else {
        for (int i = 0; i < vertices.size(); i++) {
          if (vertices.at(i).getStateID() == fromVertex) {
            Edge e(toVertex, weight);
            vertices.at(i).edgeList.push_back(e);
          } else if (vertices.at(i).getStateID() == toVertex) {
            Edge e(toVertex, weight);
            vertices.at(i).edgeList.push_back(e);
          }
        }
        cout << "Edge between " << fromVertex << " and " << toVertex << " added Successfully" << endl;
      }
    } else {
      cout << "Invalid Vertex ID entered.";
    }
  }
  void deleteVertexByID(int vid) {
    int vIndex = 0;
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices.at(i).getStateID() == vid) {
        vIndex = i;
      }
    }
    for (int i = 0; i < vertices.size(); i++) {
      for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
        if (it -> getDestinationVertexID() == vid) {
          vertices.at(i).edgeList.erase(it);
          break;
        }
      }

    }
    vertices.erase(vertices.begin() + vIndex);
    cout << "Vertex Deleted Successfully" << endl;
  }

  void getAllNeigborsByID(int vid) {
    cout << getVertexByID(vid).getStateName() << " (" << getVertexByID(vid).getStateID() << ") --> ";
    for (int i = 0; i < vertices.size(); i++) {
      if (vertices.at(i).getStateID() == vid) {
        cout << "[";
        for (auto it = vertices.at(i).edgeList.begin(); it != vertices.at(i).edgeList.end(); it++) {
          cout << it -> getDestinationVertexID() << "(" << it -> getWeight() << ") --> ";
        }
        cout << "]";
        cout << endl;
      }
    }

  }

  void printGraph() {
    for (int i = 0; i < vertices.size(); i++) {
      Vertex temp;
      temp = vertices.at(i);
      cout << temp.getStateName() << " (" << temp.getStateID() << ") --> ";
      temp.printEdgeList();
    }
  }

};

int main() {
  Graph g;
  string sname;
  int id1, id2, w;
  int option;
  bool check;
    Vertex v1,v2,v3,v4;
      v1.setID(0);
      v1.setStateName("Qasim");
      g.addVertex(v1);
      v2.setID(1);
      v2.setStateName("hasan");
      g.addVertex(v2);
      v3.setID(2);
      v3.setStateName("ali");
      g.addVertex(v3);
      v4.setID(3);
      v4.setStateName("fouzan");
      g.addVertex(v4);
      g.addEdgeByID(0,1,5);
      g.addEdgeByID(0,3,8);
      g.addEdgeByID(1,2,7);
      g.addEdgeByID(1,3,3);
      g.getAllNeigborsByID(0);
      g.getAllNeigborsByID(1);
      g.getAllNeigborsByID(2);
      g.getAllNeigborsByID(3);
        g.deleteVertexByID(3);
        cout << "\nGRAPH:";
      g.printGraph();
}