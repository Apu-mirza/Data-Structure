#include<iostream>
#include<vector>
using namespace std;

class Vertex{
public:
    int id;
    vector<int> neighbors;
    Vertex(int _id) : id(_id){}
};

class Graph{
public:
    vector<Vertex> vertices;

    void addVertex(int id){
        vertices.emplace_back(id);
    }
    void addEdge(int src, int dest){
        for(auto& vertex: vertices){
            if(vertex.id == src){
                vertex.neighbors.push_back(dest);
            }
            /*else if(vertex.id == dest){
                vertex.neighbors.push_back(src);
            }*/
        }
    }
    void printGraph(){
        for(auto& vertex: vertices){
            cout<<"Vertex "<<vertex.id<<" neighbors: ";
            for(int neighbor: vertex.neighbors){
                cout<<neighbor<<" ";
            }cout<<endl;
        }
    }
};
int main(){
    Graph graph;
    cout<<"Enter the number of vertex: ";
    int vSize;
    cin>>vSize;
    for(int i=0; i<vSize; i++){
        int verTex;
        cout<<"Enter the "<<i<<"-th vertex: ";
        cin>>verTex;
        graph.addVertex(verTex);
    }
    cout<<"Enter the number of edges of the graph: ";
    int numEdge;
    cin>>numEdge;
    for(int i=0; i<numEdge; i++){
        cout<<"Enter the "<<i<<"-th edge source and destination: ";
        int source, destination;
        cin>>source>>destination;
        graph.addEdge(source, destination);
    }
    graph.printGraph();
    return 0;
}
