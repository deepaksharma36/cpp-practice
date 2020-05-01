#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int> add(vector<int> a, vector<int> b){
    int size = a.size()>b.size()?a.size():b.size();
    int unitadd = 0;
    int ch = 0;
    int au;
    int bu;
    vector<int> result;
    int ai = a.size()-1;
    int bi = b.size()-1;
    while(ai>=0 || bi>=0){
        if(ai>=0 && bi>=0)
        {au = a[ai]; bu = b[bi];}
        else if (ai < 0 && bi >=0)
        {au = 0; bu=b[bi];}
        else if (bi < 0 && ai >=0)
        {bu = 0; au=a[ai];}
        unitadd = (au + bu + ch);
        result.insert(result.begin(), unitadd%10);
        ch = unitadd/10;
        ai--; bi--;}
    while(ch)
    {
        result.insert(result.begin(), ch%10);
        ch /=10;
    }
    return result;

}
vector<int> arymul(vector<int> a, vector<int> b){
    vector<int> result;
    vector<int> mul;
    bool posSign = a.front()*b.front()>0?1:0;
    int ch = 0, unitmul=0;
    for(int i=b.size()-1; i>=0; i--){
        for(int j=b.size()-1-i; j>0; j--)
            mul.insert(mul.begin(), 0);
        for(int k=a.size()-1; k>=0; k--){
           unitmul = abs(b[i])*abs(a[k]) + ch;
           mul.insert(mul.begin(), unitmul%10);
           ch = unitmul/10;
        }
        while(ch){
            mul.insert(mul.begin(), ch%10);
            ch/=10;}
        for(int ii=0; ii<mul.size(); ii++)
            cout<<mul[ii];
        cout<<"\n"<<endl;
        if(i==b.size()-1)
            result = mul;//deep copy
        else
            //cout<<mul[0]<<endl;
            result = add(result, mul);
        mul.clear();

    }
    if(!posSign)
        result[0]*=-1;
    return result;
}


int main(){
    vector<int> a;
    a.push_back(2);
    a.push_back(5);
    vector<int> b;
    b.push_back(-2);
    b.push_back(5);
    vector<int> r = arymul(a, b);
    cout<<endl;
    for(int i=0; i<r.size(); i++)
        cout<<r[i];
}
