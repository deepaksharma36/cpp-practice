#include<iostream>

using namespace std;

void Merge(int (&a)[9], int (&b)[4], int m, int n){

    int write_idx = m+ n -1;
    int i=m-1;
    int j=n-1;

    while(i>-1 && j>-1){
        //cout<<i<<endl;
        //cout<<j<<endl;
        //cout<<"\n"<<endl;
        a[write_idx--] = a[i]>b[j]?a[i--]:b[j--];
    }
    while(j>-1)
        a[write_idx--] = b[j--];

}

int main(){
    int a[] = {1,3,5,7,9, 0, 0, 0, 0};
    int b[] = {2,4,6,8};
    for(int i=0; i<5+4-1; i++)
        cout<<a[i]<<endl;
    Merge(a, b, 5, 4);


}
