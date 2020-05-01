#include<iostream>

int main(){

    int a = 50;
    double value = *(double*)&a;
    std::cout<<&a<<std::endl;
    std::cout<<&value<<std::endl;

}
