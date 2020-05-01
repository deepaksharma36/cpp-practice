#include<iostream>
#include<string>
#include<unordered_set>
#include<utility>

using namespace std;


struct pair_hash {
template <class T1, class T2>
std::size_t operator () (const std::pair<T1,T2> &p) const {
    auto h1 = std::hash<T1>{}(p.first);
    auto h2 = std::hash<T2>{}(p.second);
                 return h1 ^ h2;} };




int main(){


    int i = 5;
    int j = 4;

    char l  = (i+'0');
    char m  = (j+'0');

    char* ii = &l;// &(i+'0');
    char* jj = &m;//(j+'0');

    cout<<ii<<endl;

    string k = string(ii) +string( jj);

    string b = 3+'0' + " " + 4+'0';
    string u0 = i + " " + j;
    string u = (i+'0')+":"+(j+'0');
   string uu = (i-1)+":"+j;
    string ux = i+":"+(j+1);
    string uv = i+":"+(j-1);


    unordered_set<pair<int, int>,  pair_hash > abc;

    cout<<u0<<endl;
    cout<<u<<" "<<uu<<" "<<uv<<" "<<ux<<endl;




}
