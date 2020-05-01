#include<iostream>

using namespace std;

struct rect{
    int x;
    int y;
    int w;
    int h;
};


bool intersect(rect r1, rect r2){
    if (r2.x < r1.x+r1.w && r2.x + r2.w > r1.x && r1.y < r2.y + r2.h && r2.y < r1.y + r1.h )
        return true;
    return false;}

int main(){
    rect r1;
    r1.x = 0;
    r1.y = 0;
    r1.w = 5;
    r1.h = 5;
    rect r2;
    r2.x = 6;
    r2.y = 6;
    r2.w = 5;
    r2.h = 5;
    cout<< intersect(r1, r2)<<endl;
    return 1;}
