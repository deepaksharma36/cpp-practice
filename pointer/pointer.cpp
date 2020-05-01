#include<iostream>
using namespace std;
int main(){
    int num ;
    cout<<"num: "<<num<<"at: "<<&num<<endl;
    int num2 = 17;
    cout<<"num2: "<<num2<<"at: "<<&num2<<endl;
    int* ptr = &num;
    ptr = &num;
    cout<<"*ptr = &num: "<<*ptr<<"at: "<<ptr<<endl;
    *ptr = 15;
    cout<<"*ptr=15: "<<*ptr<<"at: "<<ptr<<endl;
    cout<<"num: "<<num<<"at: "<<&num<<endl;
    *ptr = num2; //changing value at the address of 17
    cout<<"*ptr = num2: "<<*ptr<<"at: "<<ptr<<endl;
    num2++;
    cout<<"num2++: "<<num2<<"at: "<<&num2<<endl;
    cout<<"*ptr: "<<*ptr<<"at: "<<ptr<<endl;
}
