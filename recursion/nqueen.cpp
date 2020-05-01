#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

bool IsValid(vector<vector<int>>& nrows, int try_idx){

    for(int i=nrows.size()-2; i>=0; i--){
        if(nrows[i][try_idx])
            return false;
     int dig_dis_1 = try_idx-(nrows.size()-1-i); //2 -0
     int dig_dis_2 = try_idx+(nrows.size()-1-i);
     cout<<nrows.size()<<endl;
     cout<<"i"<<i<<endl;
     cout<<i<<" "<<"dig1 "<<(nrows.size()-1-i)<<endl;
     //cout<<i<<" "<<"dig2 "<<dig_dis_2<<endl;
     if(dig_dis_1>=0 && dig_dis_1<=nrows.size()-1){
         if(nrows[i][dig_dis_1])
            return false; }

     if(dig_dis_2>=0 && dig_dis_2<=nrows.size()-1){
         if(nrows[i][dig_dis_2])
            return false; }
    }
    return true;
}

void PlaceQueens(vector<vector<int>>& nrows, int size){
    for(int i=0; i<size; i++){
        vector<int> row;
        nrows.push_back(row);
        cout<<"nrowssize"<<nrows.size()<<endl;
        bool notPlaced = true;
        for(int j=0; j<size; j++){
            if(notPlaced && IsValid(nrows, j)){
                nrows[i].push_back(1);
                notPlaced = false;
            }

            nrows[i].push_back(0);
        }
    }
}

bool IsValidRec(vector<int>& ncol, int try_at_idx){
    for(int i=0; i<ncol.size()-1; i++){
        //cout<<"try_at_idx"<<try_at_idx<<endl;
        //cout<<"ncol"<<i<<ncol[i]<<endl;
        int diff = abs(try_at_idx - ncol[i]);
        cout<<"Diff"<<diff<<endl;
        //cout<<"insided n try_at_idx"<<ncol[i]<<endl;
        //cout<<ncol[i]<<" "<<diff<<endl;
        if(diff==0|| diff==abs(ncol.size()-1-i))
            return false;}
        cout<<"valid"<<try_at_idx<<endl;
        return true;
}

void PlaceQueensRec(vector<int>& ncol,  int n, int row, vector<vector<int>>& result){
    if(row==n)
    {
        cout<<"Found"<<endl;
        result.push_back(ncol);

    }
    else{
    for(int j=0; j<n; j++){
        cout<<"row num"<<row<<" try_idx"<<j<<endl;
        ncol.push_back(j);
        if(IsValidRec(ncol, j)){
            cout<<j<<"Assiging: "<<j<<endl;
            PlaceQueensRec(ncol, n, row+1, result);}
            cout<<j<<"outside rec: "<<j<<endl;
        ncol.pop_back();
    }
    }}

int main(){

    vector<vector<int>> nrows;
    //PlaceQueens(nrows, 4);
    vector<int> ncol;
    vector<vector<int>> result;
    PlaceQueensRec(ncol, 4, 0, result);
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            for(int k=0; k<max(result[i]); k++)
                cout<<(result[i][j]==k?1:0)<<"\t";}
            //cout<<(result[i][j])<<"\t";}
    cout<<"\n";
    }
    }



