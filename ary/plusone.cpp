#include<iostream>
#include<vector>
using namespace std;
vector<int> pulsone(vector<int> vala){
    vala.back()++;
    cout<<vala[0]<<endl;
    for(int i=vala.size()-1; i>0; i--){
        if(vala[i]==10){
            vala[i]=0;
            vala[i-1]++;
        }
    }
    if (vala.front()==10) {
        vala[0]=0;
        vala.insert(vala.begin(), 1);}
    return vala;
}

int main(){
    vector<int> vala;
    vala.push_back(9);
    vala.push_back(9);
    vala.push_back(9);
    vector<int> result = pulsone(vala);
    for(int i=0; i<result.size(); i++)
        cout<<result[i]<<endl;
}
