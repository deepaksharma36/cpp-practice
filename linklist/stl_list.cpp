#include<iostream>
#include<list>
//#include<utile>

using namespace std;

int main(){

    list<int> l(1);
    list<int> l2(4, 100);
    //l2.assign(3,200);
    l2.push_back(150);
    cout<<"back: "<<l2.back()<<endl;
    for(int k: l2){
        //cout<<k<<endl;
    }
    for(list<int>::iterator it=l2.begin(); it!=l2.end(); it++){
        cout<<*it<<endl;
    }
    for(list<int>::const_iterator it=l2.cbegin(); it!=l2.cend(); it++){
        cout<<*it<<endl;
    }
    //l2.clear();
    for(auto it=l2.cbegin(); it!=l2.cend(); it++){
        cout<<*it<<endl;
    }
    cout<<"\n"<<endl;
    for(auto it=l2.crbegin(); it!=l2.crend(); it++){
        cout<<*it<<endl;
    }

    cout<<"\n"<<endl;
    list<pair<int, char>> l3;
    l3.emplace(l3.begin(), 300, 'y');
    l3.emplace(l3.begin(), 500, 't');
    l3.emplace_back(600, 'x');
    auto it = l3.begin();
    advance(it, 1);
    l3.erase(it);

    for(auto it =l3.cbegin(); it!=l3.cend(); it++){
        cout<<it->first<<endl;
    }
    cout<<"Max size"<<l3.max_size()<<endl;
    l.merge(l2);
    for(auto it = l.begin(); it != l.end(); it++)
        cout<<*it<<endl;

}
