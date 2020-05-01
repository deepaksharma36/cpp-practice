#include<iostream>
#include<string>

using namespace std;

int SSDecodeColId(const string& s){
    int result = 0;
    for(char c: s){
        result = result*26 + (c-'A'+1);
    }
    return result;
}

int main(){


    cout<< SSDecodeColId("AA")<<endl;
    return 0;
}
