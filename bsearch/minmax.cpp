#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

pair<int, int> FindMinMax(vector<int>& vals){
    if(vals.size()==1)
        return {vals[0], vals[0]};

    pair<int, int>  globalmm = minmax(vals[0], vals[0]);
    for(int i=0; i+1<vals.size(); i+=2){
        pair<int, int> localmm = minmax(vals[i], vals[i+1]);
        //cout<<localmm.first<<","<<localmm.second<<endl;
        globalmm = {min(globalmm.first, localmm.first),
            max(localmm.second, globalmm.second)};
        //cout<<globalmm.first<<","<<globalmm.second<<endl;

    }
    if(vals.size()%2){
        globalmm = {min(globalmm.first, vals.back()),
            max(globalmm.first, vals.back())};
    }

    return globalmm;
}


int main(){
    vector<int> vals{1,3,2,6,4,9};
    auto output =FindMinMax(vals);
    cout<<output.first<<","<<output.second<<endl;
}
