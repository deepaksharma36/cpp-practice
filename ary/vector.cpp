#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> d;
    for(int i=0; i< 19; i++){
        d.push_back(1);
        cout<<d.size()<<","<<d.capacity()<<endl;
    }
    vector<int> c(7);
    //c(7);
    for(int i=0; i<c.size(); i++){
        cout<<c[i];
    }

    vector<int> v;
    for(int i=0; i<5; i++){
        v.push_back(i);
    }
    v.resize(17);
    v.reserve(100);
    /*
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }*/

    //vector<vector<int>> a(3, vector<int>(3, {{1,2,3}}));
    vector<vector<int>> a(3, vector<int>(3, 4));
    vector<int> c1;
    a.emplace_back(c1);

    cout<<"size"<<v.size()<<endl;
    cout<<"capacity"<<v.capacity()<<endl;
    cout<<"front"<<v.front()<<endl;
    cout<<"back"<<v.back()<<endl;
    cout<<"isempty"<<v.empty()<<endl;

    reverse(v.begin(), v.end());
    vector<int>::iterator ptr;
    for(ptr=v.begin(); ptr<v.end(); ptr++)
        cout<<*ptr<<endl;
    return 0;

}
