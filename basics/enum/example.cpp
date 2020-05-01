#include<iostream>

using namespace std;

enum Example{ A=0, B, C};

enum NationalColor{RED, BLUE, WHITE};

enum Example2: unsigned char{ AA=0, BB, CC};

enum class TheColor{ORANGE, WHITE, GREEN};

int main(){

    int exam =  A;

    Example example = B;

    NationalColor x = RED;

    //example = (Example)example+1;

    TheColor i = TheColor::ORANGE;
    //TheColor i = ORANGE; it's an error

    cout<<example+1<<endl;

    if(exam == x )
        cout<<"exam is x"<<endl;

    //if(i==x)
    //    cout<<"applie==orange"<<endl;




}
