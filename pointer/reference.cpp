#include<iostream>
using namespace std;

int passbyRef(int& val){
    //int& val = num;
    val++;
}

int main(){
    int num = 5;
    int* nump = &num;
    //int &ref = num;
    int &ref = *nump;
    cout<<num<<endl;
    cout<<ref<<endl;
    ref++;
    cout<<"num"<<num<<endl;
    cout<<"ref"<<ref<<endl;
    cout<<"&num"<<&num<<endl;
    cout<<"&ref"<<&ref<<endl;
    passbyRef(num);
    cout<<num<<endl;
    }

