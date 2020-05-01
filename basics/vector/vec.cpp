#include<iostream>
#include<vector>
#include<list>
#include<algorithm>

void show(std::vector<int>& arr){
    for(auto ele: arr)
        std::cout<<ele<<" ";
    std::cout<<"\n";

}

void itr(std::vector<int>& a){
    //std::vector<int>::iterator it = std::find(a.begin(), a.end(), 2);
    auto it = std::find(a.begin(), a.end(), 2);
    std::cout << *it <<std::endl;
    if(it != a.end())
        it = a.erase(it);
}

void removeall(std::vector<int>& a){
    a.erase(std::remove(a.begin(), a.end(), 1), a.end());
}

int main(){

    std::vector<int> a;
    a.push_back(4);
    show(a);

    std::vector<int> b{1,2,3,4};
    show(b);

    std::vector<int> c(4,-1);
    show(c);

    int arr[] = {1,2,3,4};
    std::vector<int> d(arr, arr + sizeof(arr)/sizeof(int));
    show(d);

    std::list<int> l1{1,2,3,4,5};

    std::vector<int> e(l1.begin(), l1.end());
    show(e);

    std::vector<int> f(e);
    show(f);







}


