#include<iostream>
#include<vector>

using namespace std;

int FindCelibrity(vector<vector<int>>& G){
    int size = G.size();

    int i=0, j=1;
    while(j<size){
        if(G[i][j])
            i = j++;
        else
            j++;
    }

    return i;

}


int main(){


    int size = 5;
    vector<vector<int>> G(size, vector<int>(size, 0));
    for(int i=0; i<size; i++)
        G[i][2] = 1;

    for(int i=0; i<size-2; i++)
        G[i][4] = 1;
    G[2][4] = 0;

    cout<<FindCelibrity(G)<<endl;


}
