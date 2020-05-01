#include<iostream>

using namespace std;


void mayGiveError(){

    bool error = true;
    if(error)
        throw 8;
}


int main(){

    try{
        mayGiveError();}
    catch(int e){
        cout<<"catched error: "<<e<<endl;
    }
    return 0;
}
