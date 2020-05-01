#include<iostream>
#include<string>

using namespace std;

string nextNum(string& preNum){
    string result = "";
    for(size_t i=0; i<preNum.size(); i++){
        int freq = 1;
        while(i+1<preNum.size() && preNum[i] == preNum[i+1]){
            freq++; i++;}
        result += (to_string(freq)+preNum[i]);

    }
    cout<<"result"<<result<<endl;
    return result;
}


int main(){
    int n;
    cout<<"Give us n"<<endl;
    cin>>n;
    string next = "1";
    for(int i=0; i<n; i++){
        next = nextNum(next);

        cout<<next<<endl;
    }

    return 0;
}
