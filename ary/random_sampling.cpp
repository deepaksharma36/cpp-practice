#include<iostream>
#include<vector>
#include<random>
#include<sstream>
using namespace std;


void random_sampling(vector<int> &a, int k){
    default_random_engine seed((random_device())());
    for(int i=0; i<k; i++){
        swap(a[i], a[uniform_int_distribution<int>{i, a.size()-1}(seed)]);

    }
}

vector<int> random_running_sampling(istringstream &s, int k){
    vector<int> a;
    int x;
    for(int i=0; i<k && s>>x; i++){
        a.emplace_back(x);
    }
    default_random_engine seed((random_device())());
    int num_seen_so_far = k;
    while(s>>x){
        ++num_seen_so_far;
        int slot = uniform_int_distribution<int>{0, num_seen_so_far-1}(seed);
        cout<<"slot"<<slot<<endl;
        if (slot < k)
            a[slot] = x;}
    return a;}

vector<int> random_permutation(int n){
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    random_sampling(a, n);
    return a;

    }

int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    random_sampling(a, 5);
    //for(int i=0; i<a.size(); i++)
    //    cout<<a[i]<<endl;
    istringstream iss;
    iss.str("1 2 3 4 5 6 7 8 9 10");
    //vector<int> b = random_running_sampling(iss, 5);
    //for(int i=0; i<b.size(); i++)
    //    cout<<b[i]<<endl;
    vector<int> c = random_permutation(10);
    for(int i=0; i<c.size(); i++)
        cout<<c[i]<<endl;
    return 0;
