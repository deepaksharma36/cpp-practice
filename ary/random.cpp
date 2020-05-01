#include<iostream>
#include<vector>
#include<random>
#include<sstream>
using namespace std;

int main(){
    //default_random_engine eng;
    default_random_engine seed((random_device())());
    cout << "min: " << seed.min() <<endl;
    cout << "max: " << seed.max() <<endl;
    cout << "rand val: " << seed() << endl;


    std::stringstream state;
    state <<seed; //save the current state
    cout<<state<<endl;
    cout << "rand val: " << seed() << endl;
    state >> seed; //save the current state
    cout << "rand val: " << seed() << endl;
    cout << "rand val: " << seed() << endl;
    cout<<state<<endl;

    uniform_int_distribution<int> distr(0, 5);
    cout<<"Inside range"<<distr(seed)<<endl;

    uniform_real_distribution<double> distR(0, 5);
    cout<<"Inside range"<<distR(seed)<<endl;

    return 0;


}
