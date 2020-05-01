#include<iostream>
#include<vector>
#include<utility>
#include<cmath>

using namespace std;



int FindOptimalCost(const vector<pair<int, int>>& weight_price, int weight_limit){
    vector<vector<int>> dp(weight_price.size(), vector<int>(weight_limit+1, 0));

    for(int i=0; i<weight_price.size(); i++){
        for(int j=0; j<weight_limit+1; j++){
            int q1 = i>0?dp[i-1][j]:0; //Don't consider new one
            int q2 = j-weight_price[i].first>=0?dp[i][j-weight_price[i].first]+weight_price[i].second:0; //Consier new item
            dp[i][j] = max(q1, q2);
            //dp[i][j] = max(q2, q1);

        }
    }

    /*for(size_t i=0; i<dp.size(); i++){
        for(size_t j=0; j<dp[i].size(); j++)
            cout<<dp[i][j]<<"  ";
    cout<<"\n";
    }*/

    return dp.back().back();


}



int main(){

    vector<pair<int, int>> weight_price;
    weight_price.emplace_back(pair<int, int>(5, 60));
    weight_price.emplace_back(pair<int, int>(3, 50));
    weight_price.emplace_back(pair<int, int>(4, 70));
    weight_price.emplace_back(pair<int, int>(2, 30));
    cout<<FindOptimalCost(weight_price, 5)<<endl;
    return 0;
}
