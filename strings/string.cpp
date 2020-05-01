#include<iostream>
#include<string>

using namespace std;
int main(){

    string u;
    getline(cin, u);
    string u1, u2;
    u1 = u;
    u2.assign(u);
    cout<<u1<<u2<<endl;
    string str;
    str = "deepak sharma";
    cout<<str<<endl;

    string a("a",9);
    cout<<"a: "<<a<<endl;

    for(int i=0; i<str.length(); i++)
        cout<<str.at(i)<<endl;

    string b = str.substr(3);
    string c = str.substr(1, 4);
    cout<<"c: "<<c<<"b: "<<b<<endl;

    c.swap(b);
    cout<<"c: "<<c<<"b: "<<b<<endl;

    cout<<"where is pak: "<<c.find("pak")<<endl;

    //replace(str, "deepak", "Deepak");
    //cout<<d<<endl;

    c.replace(0, 3, "deepak");
    cout<<"replace pak in c: "<<c<<endl;
    c.erase(7);
    cout<<"erased c: "<<c<<endl;

    return 0;
}
