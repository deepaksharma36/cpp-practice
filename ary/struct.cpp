#include<iostream>
using namespace std;

struct Coffee{
    string origin;
    int batchnum;
    string name; };

int main()
    {
    Coffee c;
    Coffee cb{"india", 11, "gf"};
    cout<<c.origin<<endl;
    cout<<cb.name<<endl;

    }
