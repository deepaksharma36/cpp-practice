#include<iostream>
#include<vector>

using namespace std;

class A {


    public:
        A(int a, int b): a{0}, b{0} {cout<<"created"<<endl;}

    private:
            int a; int b;

};


int main(){

    A x(1,1);
    vector<int> a{1,2,3,4};

    for(auto& n: a)
        cout<<n<<endl;
}
