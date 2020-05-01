#include<iostream>
using namespace std;
int main(){
    int i{5}; // declaring and assigning int i.
    int ia[10];
    int ib[] = {1,2,3,4,5};
    int ic[10] = {1,2,3};
    cout<<i<<endl;

    char ch{'a'};
    char cha[5];
    char chb[10] = {'a', 'b', 'c'};
    char chc[] = {'g', 'h', 'k', 'p', 'q'};
    char chd[] = {'g', 'h', 'k', '\0'};
    cout<<ch<<endl;
    cout<<cha<<endl;
    cout<<chb<<endl;
    cout<<chc<<endl;
    cout<<chd<<endl;

    string s{"hello"};
    cout<<s<<endl;


}
