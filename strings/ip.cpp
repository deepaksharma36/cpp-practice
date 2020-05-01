#include<iostream>
#include<string>

using namespace std;

bool isValidip(string s){
    if(stoi(s) < 256)
        return true;
    return false;
}

int main(){

    string ip;
    getline(cin, ip);

    for(int i=1; i<ip.size()-2; i++){
        string first = ip.substr(0, i);
        //cout <<"first"<<first<<endl;
        if(!isValidip(first))
            continue;
        for(int j=i+1; j<ip.size()-1; j++){
            string second = ip.substr(i, j-i);
            //cout <<"second"<<second<<endl;
            if(!isValidip(second))
                continue;
        for(int k=j+1; k<ip.size(); k++){
            string third = ip.substr(j, k-j);
            //cout <<"third"<<third<<endl;
            if(!isValidip(third))
                continue;
            string forth = ip.substr(k);
            //cout <<"forth"<<forth<<endl;
            if(isValidip(forth))
                cout<<first<<"."<<second<<"."<<third<<"."<<forth<<endl;
        }
        }


    }

}
