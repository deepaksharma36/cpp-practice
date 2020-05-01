#include<iostream>
#include<vector>

using namespace std;

int ComputXchooseY(int x, int y, vector<vector<int>>& x_choose_y){
    if(x==0 || y==x )
        return 1;
    else if(x_choose_y[y][x] > 0)
        return x_choose_y[y][x];

    int with_y = ComputXchooseY(x , y-1,  x_choose_y);
    int without_y = ComputXchooseY(x-1, y-1, x_choose_y);

    x_choose_y[y][x] = with_y + without_y;
    return x_choose_y[y][x];
}


int ComputBinomialCoff(int x, int y){
    vector<vector<int>> x_choose_y(y+1, vector<int>(x+1, 0));
    cout<<"size"<<x_choose_y.size()<<" "<<x_choose_y[0].size();
    cout<<"**"<<x<<"choose"<<y<<"********"<<endl;
    int ans = ComputXchooseY(x, y, x_choose_y);
    for(int i=0; i<x_choose_y.size(); i++){
        for(int j=0; j<x_choose_y[i].size(); j++)
            cout<<x_choose_y[i][j]<<" ";
        cout<<"\n";
    }
    return ans;
}


int main(){

    int x = 3;
    int y = 2;
    cout<<ComputBinomialCoff(0, 0)<<endl;
    cout<<ComputBinomialCoff(1, 1)<<endl;
    cout<<ComputBinomialCoff(2, 4)<<endl;
    cout<<ComputBinomialCoff(2, 3)<<endl;
    cout<<ComputBinomialCoff(2, 4)<<endl;
}
