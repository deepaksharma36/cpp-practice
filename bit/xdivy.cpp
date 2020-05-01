#include<iostream>

using namespace std;

unsigned div(unsigned x, unsigned y){
    int bitset = 2;
    unsigned result = 0;
    long mask = 1<<bitset;
    //mask << bitset;
    //x-2^k(y) > y
    while(x>=y){
        bitset = 32;
        mask=1<<bitset;
        do{
            mask=1<<bitset;
            bitset>>=1;
        }while(x-mask*y < 0)
        result+=mask;
        x -= mask*y; }
    return result;
}
int main(){
    cout<<div(2, 2)<<endl;
    cout<<div(26, 5)<<endl;
}
