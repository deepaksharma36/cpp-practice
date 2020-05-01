#include<queue>
#include<string>
#include<iostream>
#include<unordered_map>

using namespace std;

struct Vertex{

    Vertex(char name_, int dist_ ): name{name_}, dist{dist_}{}
    string name;
    int dist;

    bool operator<(Vertex* other){
        if(dist == -1) return false;
        if(other->dist == -1) return true;
        return dist < other->dist;
    }
};


unordered_map<Vertex*, vector<pair<Vertex*, int>>>  BuildGraph(){

    Vertex* v1 =  new Vertex{'A', -1};
    Vertex* v2 =  new Vertex{'B', -1};
    Vertex* v3 =  new Vertex{'C', -1};
    Vertex* v4 =  new Vertex{'D', -1};
    Vertex* v5 =  new Vertex{'E', -1};
    Vertex* v6 =  new Vertex{'F', -1};

    unordered_map<Vertex*, vector<pair<Vertex*, int>>> graph;
    vector<pair<Vertex*, int>> p1{{v1, 0}, {v2, 2}, {v3, 4}};
    vector<pair<Vertex*, int>> p2{{v2, 0}, {v3, 2}, {v4, 4}};
    vector<pair<Vertex*, int>> p3{{v3, 0}, {v5, 2}, {v6, 4}};

    for(auto p: p1)
        cout<<p.first->name<<","<<p.second<<endl;

    graph[v1] =  p1;
    return pair<unordered_map<Vertex*, vector<pair<Vertex*, int>>>, Vertex*>{graph, v1};



}


void Dijkstra(unordered_map<Vertex*, vector<pair<Vertex*, int>>>graph, Vertex* start){

    priority_queue<Vertex*> pq;
    pq.push(start);
    for(auto v: graph){

}}

int main(){

    auto graph = BuildGraph();
    Dijkstra(graph.first, graph.second );




}



