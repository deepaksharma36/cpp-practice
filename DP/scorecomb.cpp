#include<iostream>
#include<vector>

using namespace std;

int NumCombinationsForFinalScore(int final_score,
        const vector<int>& individual_play_scores){

    vector<vector<int>> dp(individual_play_scores.size(), vector<int>(final_score+1,0));
    for(int i=0; i<individual_play_scores.size(); i++){
        dp[i][0] = 1;
        cout<<"Nor"<<endl;
        for(int j=1; j<=final_score; j++){
            int without_play = i>0?dp[i-1][j]:0;
            int with_play = j>=individual_play_scores[i]?dp[i][j-individual_play_scores[i]]:0;
            dp[i][j] = without_play + with_play;
        }

    }
    for(vector<int> row: dp){
        cout<<"row"<<row.size()<<endl;
        for(int i: row)
            cout<<i<<"  ";
        cout<"\n";
    }
    return dp.back().back();

}

int main(){

    vector<int> individual_play_scores{2,3,7};
    cout<<NumCombinationsForFinalScore(12, individual_play_scores);


}
