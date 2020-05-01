#include<iostream>
#include<vector>

using namespace std;

void swap(vector<int>& vals, int i, int j){
    int temp = vals[i];
    vals[i] = vals[j];
    vals[j] = temp;
}

int PivotSortNoPivot(vector<int>& vals, int s, int e){
    int gtr = s;
    int itr = s;
    int pivot_idx = (s+e)/2;
    int pivot = vals[pivot_idx];
    while(itr<=e){

        if(vals[itr] <= pivot){
            if(itr == pivot_idx)
                pivot_idx = gtr;
            swap(vals, gtr, itr);
            gtr++;
        }
        itr++;
    }
    swap(vals, gtr-1, pivot_idx);
    return gtr-1;

}

void PivotSort(vector<int>& vals, int pivot){
    int gtr = -1;
    int itr = 0;
    int pivot_idx = -1;
    while(itr<vals.size()){

        if(vals[itr] <= pivot){
            if(vals[itr] == pivot)
                pivot_idx = gtr+1;
            swap(vals, gtr+1, itr);
            gtr++;
        }
        itr++;
    }
    swap(vals, gtr, pivot_idx);

}


int KthLargest(vector<int>& vals, int k){
    int pivot_idx = -1;
    int s = 0;
    int e = vals.size()-1;
    int targe_idx = vals.size()-k;
    while(pivot_idx != targe_idx){
        pivot_idx = PivotSortNoPivot(vals, s , e);
        cout<<pivot_idx<<" "<<s<<" "<<e<<" "<<targe_idx<<endl;
        if(targe_idx > pivot_idx)
            s = pivot_idx+1;
        else if(targe_idx < pivot_idx)
            e = pivot_idx-1;
    }
    return vals[pivot_idx];
}

int main(){
    //vector<int> vals{1, 3, 5,6,5,5, 2,2,2, 8, 6, 2};
    vector<int> vals{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout<<KthLargest(vals, 1)<<endl;
    cout<<KthLargest(vals, 2)<<endl;
    cout<<KthLargest(vals, 3)<<endl;
    cout<<KthLargest(vals, 4)<<endl;
    cout<<KthLargest(vals, 5)<<endl;
    //int pivot_idx = PivotSortNoPivot(vals, 0, vals.size()-1);
    //cout<<"pivot_idx"<<pivot_idx<<endl;

    for(int x: vals)
        cout<<x<<" ";
    cout<<"\n";
}


