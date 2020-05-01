#include<iostream>
#include "cls.h"
using namespace std;

int main(){
    Abc a1{};
    Abc a2{6,1};
    Abc* a3 = new Abc(6, 1);
    cout<<a1._h<<endl;
    cout<<a1.getArea()<<endl;
    return 1;
}
