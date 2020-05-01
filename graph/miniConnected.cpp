#include<iostream>
#include<vector>
#include<queue>

using namespace std;

enum class Color{WHITE, GRAY, BLACK};

struct Vertex{
    Color vertexColor;
    vector<Vertex*> edges;
};

bool HasCycle(Vertex*& curr, Vertex*& pre){
    if(curr->vertexColor == Color::GRAY || curr->vertexColor == Color::BLACK)
        return true;
    curr->vertexColor = Color::GRAY;
    bool result = false;
    for(Vertex* neighbour: curr->edges){
        if(neighbour != pre && neighbour->vertexColor != Color::BLACK)
        if(HasCycle(neighbour, pre)){
            return result;
        }
    }
    curr->vertexColor = Color::BLACK;
    return false
}


bool IsMinConnected(Vertex*& head){

    if(head==nullptr|| !HasCycle(headi, nullptr))
        return true;
    return false;
}


int main(){
    vector<Vertex*> edg;
    Vertex* v1 = new Vertex{Color::WHITE, edg};
    IsMinConnected(v1);
}

