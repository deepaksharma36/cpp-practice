#define MAX(a,b) ((a > b) ? a:b)
#define SUM(a,b) (a+b)
#include<iostream>

inline int max(int a, int b){return a>b?a:b;}

int main(){

    int x = 9, y=6;
    std::cout<<x<<std::endl;
    std::cout<<SUM(x++,y)<<std::endl;
    std::cout<<x<<std::endl;
    std::cout<<max(x++,y)<<std::endl;
    std::cout<<x<<std::endl;
    std::cout<<max(x,y)<<std::endl;
    std::cout<<x<<std::endl;


    return 0;
}
