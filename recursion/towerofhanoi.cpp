#include<iostream>

using namespace std;

int CountMove(int n){
    if(n==1)
        return 1;
    else
        return CountMove(n-1) + 1 + CountMove(n-1);
}

void ShowMove(int n, int t_from, int t_to, int t_using){
    if(n==1)
        cout<<"Moving Disk from "<<t_from<<" to "<<t_to<<endl;
    else
    {
        ShowMove(n-1, t_from, t_using, t_to);
        ShowMove(1, t_from, t_to, t_using);
        ShowMove(n-1, t_using, t_to, t_from);



}}

int main(){

    cout<<CountMove(4)<<endl;
    cout<<"\n"<<endl;
    ShowMove(1, 1, 3, 2);
    cout<<"\n"<<endl;
    ShowMove(2, 1, 3, 2);
    cout<<"\n"<<endl;
    ShowMove(3, 1, 3, 2);

}
