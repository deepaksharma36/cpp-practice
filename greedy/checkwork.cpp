//
//[1      3]
//  [2      9]
//    [4 6]
//    [4      8]
//         [7                      19]
//             [10,   12]
//                       [14  16]
//
//if not inside then you will be selected till range
//otherwise == with old one then bigger range
//
//
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

vector<int> FindVisitingTimes(vector<pair<int, int>>& task_time_slots){

    sort(task_time_slots.begin(), task_time_slots.end());
    vector<int> selected;
    int last_end_time = 0;
    int poped_end_time;
    int j=0;
    cout<<"called"<<endl;
    for(int i=0; i<task_time_slots.size(); i++){
        cout<<task_time_slots[i].first<<endl;
        /*if(selected.size()>0 && task_time_slots[i].first==selected[selected.size()-1] && last_end_time<task_time_slots[i].second){
            //poped_end_time = poped_end_time>0?min(poped_end_time, task_time_slots[i].first):task_time_slots[i].first;
            //if(poped_end_time >  )
            selected.pop_back();

        }*/
        if( selected.size()>0 && task_time_slots[i].first<=last_end_time){
            //poped_end_time = poped_end_time>0?min(poped_end_time, task_time_slots[i].first):task_time_slots[i].first;
            selected.pop_back();
            last_end_time = min(last_end_time, task_time_slots[i].second);
            selected.push_back(task_time_slots[i].first);

        }
        else{
            selected.push_back(task_time_slots[i].first);
            last_end_time = task_time_slots[i].second;

    }}
    return selected;


}

int main(){

    //vector<pair<int, int>> tasks{{{1, 3}, {1,7}, {2, 9}, {5, 6},{5, 8}, {7, 19}, {10, 12}, {14, 19}}};
    vector<pair<int, int>> tasks{{{1, 2}, {2,3}, {3, 4}, {2, 3},{3, 4}, {4, 5}, {10, 12}, {14, 19}}};
    auto times = FindVisitingTimes(tasks);
    cout<<"this"<<endl;
    for(auto t: times)
        cout<<t<<endl;

}
