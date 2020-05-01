#include<iostream>
#include<string>

using namespace std;

string encode(string& a){
    string encode = "";
    for(size_t i=0; i<a.size(); i++){
        int count = 1;
        while(i+1< a.size() && a[i] == a[i+1]){
            i++; count++;

        }
        encode += to_string(count)+a[i];
    }
    return encode;

}

string decode(string& a){
    string decode = "";
    size_t i = 0;

    //for(size_t i =0; i<a.size(); i = i+2)
    while(i<a.size()){
        int frq = 0;
        while(isdigit(a[i]))
            frq  10 + a[i++]-'0';
        while(frq-- )
            decode+=a[i];
        i++;
    }

    return decode;

}


int main(){
    string s;
    getline(cin, s);
    string encodes = encode(s);
    cout << encodes <<endl;

    string decodes = decode(encodes);
    cout << decodes << endl;
}
