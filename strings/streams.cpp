#include<iostream>
#include<sstream>

using namespace std;

int main(){
    istringstream iss;
    iss.str("1 2 3 4 5 6 7 8");
    //iss.str("1,2,3,4,5,6,7,8");
    int x;
    while(iss>>x)
        cout<<x<<endl;

    ostringstream oss;
    for(int i=0; i<9; i++)
        oss<<i;
    cout<<oss.str()<<endl;

}
