#include<iostream>

struct A{
    int a;
    int b;
};

int main(){

    A st = {1, 4};
    int* pos = (int*)&st;
    std::cout<<pos[0]<<","<<pos[1]<<std::endl;
    std::cout<<*pos<<","<<*(pos+1)<<std::endl;


}
