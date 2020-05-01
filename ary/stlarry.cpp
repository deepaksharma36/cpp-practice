#include<iostream>
#include<array>

using namespace std;

int main(){


    array<int, 4> a{{9,1,2,3}};
    array<int, 4> a1 = {{9,1,2,3}};
    array<int, 4> c;//{9,1,2,3};

    array<array<int, 2>, 3> x{{{1, 2}, {3,4}, {5,6}}};

    array<array<int, 2>, 3> x1 = {{{1, 2}, {3,4}, {5,6}}};


    cout<<a.size()<<endl;

    cout<<c.size()<<endl;



}
