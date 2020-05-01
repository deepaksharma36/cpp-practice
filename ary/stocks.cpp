#include<iostream>
#include<vector>
#include<cmath>
#include<limits>
using namespace std;
int profit(vector<double>& a){
    double currp=0, bestp=0;
    double buyp = std::numerics_limits<double>::max();

    for(int i=0; i<a.size(); i++)
    {
        buyp = min(a[i], buyp);
        currp = a[i] - buyp;
        bestp = max(currp, bestp);
    }
    return bestp;
}

int main(){

    vector<double> a;
    a.push_back(310);
    a.push_back(315);
    a.push_back(275);
    a.push_back(295);
    a.push_back(260);
    a.push_back(270);
    a.push_back(290);
    a.push_back(230);
    a.push_back(255);
    a.push_back(250);
    a.push_back(6);
    cout<<profit(a)<<endl;
    return 1;
}
