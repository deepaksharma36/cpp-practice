#include<iostream>
#include<vector>
#include<string>

using namespace std;

int CountWays(int num_pair, int open_used, int end_used){

    if(open_used+end_used == 2*num_pair)
        return 1;

    int with_end = 0;
    int with_open = 0;
    if(open_used>end_used)
        with_end = CountWays(num_pair, open_used, end_used+1);
    if(open_used<num_pair)
        with_open = CountWays(num_pair, open_used+1, end_used);
    return with_end + with_open;
}


int main(){

    cout<<CountWays(1, 0, 0)<<endl;
    cout<<CountWays(2, 0, 0)<<endl;
    cout<<CountWays(3, 0, 0)<<endl;


}



