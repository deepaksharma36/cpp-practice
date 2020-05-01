#include<iostream>
#include<vector>
#include<string>

using namespace std;

int bsearch(int t, const vector<int>& a){
    int L = 0, U = a.size()-1;
    while(L <= U){
        int mid = (U+L)/2;
        if(a[mid] > t)
            U = mid-1;
        else if(a[mid] < t)
            L = mid + 1;
        else if(a[mid] == t)
            return mid;
    }
    return -1;
}


int main(){


    vector<int> a{1,4,5,7,9,13,16,19,23};
    std::cout<<bsearch(16,a)<<std::endl;
    return 0;
}
