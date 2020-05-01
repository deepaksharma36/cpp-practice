#include<iostream>
#include<list>
#include<algorithm>

int show(std::list<int>& l){
    for(auto k: l)
        std::cout<<k<<" ";
    std::cout<<"\n";
}

int main(){

    std::list<int> l;
    //l.push_back(2);
    l.push_front(6);

    std::list<int>::iterator it = l.begin();
    std::cout<<*it<<std::endl;
    l.insert(it, 2);
    l.insert(it, 3);
    l.insert(it, 4);
    l.insert(it, 5);
    it = l.begin();
    std::advance(it, 2);
    std::cout<<*it<<std::endl;
    //l.erase(l.begin(), it);
    it = l.begin();
    it = std::next(it, 2);
    std::cout<<*it<<std::endl;

    //std::cout<<std::contains(l, 4)<<"\n";
    show(l);


}
