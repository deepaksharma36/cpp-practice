#include<iostream>
using namespace std;

int main(){
    int i{1};
    char ch;
    float f = 2.5;
    double dbl;
    ch = static_cast<char>(i);
    cout<<ch<<endl;
    dbl = static_cast<double>(f);
    cout<<dbl<<endl;
    long ii;
    ii = i;
    cout<<ii<<endl;
    const int j{1};
    i = 5;
    return i;
}
