#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


vector<int> mul(vector<int> a, vector<int> b){
    bool negSign = a.front()*b.front()<0?1:0;
    a[0] = abs(a[0]);
    b[0] = abs(b[0]);
    vector<int> result(a.size()+b.size(), 0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
           result[i+j] += a[i]*b[j]%10;
           if(a[i]*b[j]/10> 0)
                result[i+j+1]+= a[i]*b[j]/10;
        }
    }
    if(negSign)
        result[result.size()-1]*=-1;
    reverse(result.begin(), result.end());
    return result;

}

int main(){
    vector<int> a;
    a.push_back(2);
    a.push_back(5);
    vector<int> b;
    b.push_back(2);
    b.push_back(5);
    vector<int> r = mul(a, b);
    for(int i=0; i<r.size(); i++)
        cout<<r[i];
    cout<<'\n'<<endl;
}
