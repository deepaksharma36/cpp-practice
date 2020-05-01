#include<iostream>
#include<bitset>
#include<cmath>
using namespace std;

int reverseDecimal(int x){
    int output = 0;
    bool isNeg = x<0;
    x = abs(x);
    while(x){
        output = output*10 + x%10;
        x/=10;
    }
    return isNeg?-1*output:output; }

double bitpow(double x, int y){
    double output = 1;
    if(!y)
        return 1;
    else if(y&1)
        output = x;
    else
        output = 1;
    return output*bitpow(x*x, y>>1);
    }

double bitpow2(double x, int y){
    double output = 1;
    if (y<0)
        x = 1/x; y = -1*y;
    while(y){
        if(y&1){
            output *= x;}
        x = x*x;
        y>>=1;
    }
    return output;
}
int palindromic(int x){
    int mask = 0;
    int numDig = 0;
    int xc = abs(x);
    while(abs(x)>0){//123
        x/= 10;
        numDig += 1;
        }
    for(int idx=0; idx<numDig/2; idx++){
        mask = pow(10, numDig-idx-1);
        if(xc%10 != (xc/mask)%10)
            return false;
        xc/=10;
    }
    return true;


}
unsigned int equalWeight2(unsigned int x){
    unsigned int equal = x;
    unsigned int lastbit;
    int idx = 0;
    do{idx++;
        lastbit = x&1;
        x >>=1;}while((x&1)==lastbit);
    //unsigned int mask1 = pow(2, idx) || pow(2, idx-1);
    cout<<bitset<8>(((1U << idx) | (1U << idx-1)))<<endl;
    equal ^= (1U << idx) | (1U << idx-1);
    //equal ^= mask1;
    return equal;
    }

unsigned int equalWeight(unsigned int x){
    for(int idx=0; idx<16; idx++){
        if((x&1)!=(x>>1&1)){
            x ^= (1U << idx) | (1U << idx+1);
            return x;}
        x >>=1;}
    //throw invalid_argument("All bits are 0 or 1");
    }

unsigned int add(unsigned int a, unsigned int b){
    int ch=0;
    unsigned int output = 0;
    int idx = 0;
    cout<<"a"<<a<<endl;
    cout<<"b"<<b<<endl;
    while(a||b){
        int mul = (a&1)|(b&1)|ch;
        output |= ( mul << idx);
        cout<<idx<<output<<endl;
        ch = (a&1)&(b&1);
        idx+=1;
        a>>=1;
        b>>=1;}
    return output;
    }

unsigned int mul(unsigned int x, unsigned int y){
    unsigned int mul = 0;
    while(x){
        if(x&1){
            mul = add(mul, y);
            cout<<mul<<endl;}
        x>>=1;
        y<<=1;
        cout<<y<<endl;}
    return mul;}


int reversebits(unsigned long x){
    //int mid_idx = sizeof(x)/2-1;
    int reversed = 0;
    int idx = 0;
    while(x){
        reversed <<= 1;
        cout<<bitset<16>(reversed)<<endl;
        reversed|=(x&1);
        x=x>>1;
    }
    return reversed;}

int reversebits2(unsigned long x){
    int reversed=0;



    }

int swapbits(unsigned long x, int idx1, int idx2){
    if((x>>idx1)&1 == (x>>idx2)&1)
        return x;
    unsigned long mask = (1L<<idx1)|(1L<<idx2);
    return x^mask;
}
int getParity(int x){
    int score = 0;
    while(x)
        {score += x&1;
         cout<< bitset<8>(x)<<endl;
         x = x>>1;}
    cout<<score<<endl;
    return score%2;
}

int getParity2(int xx){
    short x = 0b0111111111111111;//111111111111111;
    const int bitspace = 16;
    cout<<bitset<bitspace>(x)<<endl;
    x ^= x>>16;
    cout<<bitset<bitspace>(x)<<endl;
    x ^= x>>8;
    cout<<bitset<bitspace>(x)<<endl;
    x ^= x>>4;
    cout<<bitset<bitspace>(x)<<endl;
    x ^= x>>2;
    cout<<bitset<bitspace>(x)<<endl;
    x ^= x>>1;
    cout<<bitset<bitspace>(x)<<endl;
    return x%2; }

    int getParity3(int x){
        cout<<bitset<8>(x)<<endl;
        int xr = x-1;
        cout<<bitset<8>(x-1)<<endl;



    }
int main(){
    int i = 0b100010101;
    i = 0b010101001;
    cout<<1UL<<endl;
    cout<<1U<<endl;
    cout<<1<<endl;
    //cout<<sizeof(i)<<endl;
    //cout<<i<<endl;
    //cout<<getParity(i)<<endl;
    //cout<<getParity2(i)<<endl;
    //unsigned long x = 0b1111110000;
    //cout<<bitset<16>(x)<<endl;
    //cout<<bitset<16>(swapbits(x, 3, 7))<<endl;
    //cout<<bitset<16>(reversebits(x))<<endl;

    //unsigned int xb = 0b10100100;
    //unsigned int y = 0b10100100;
    //int x = -121;
    //cout<<x<<": Equal Weight "<<bitset<16>(equalWeight(x))<<":"<<equalWeight(x)<<endl;
    //cout<<x<<"x"<<y<<": Mul "<<":"<<mul(x,y)<<endl;
    //cout<<x<<"->"<<reverseDecimal(x)<<endl;
    //cout<<x<<"->"<<palindromic(x)<<endl;
    double x = 10;
    int y = -7;
    cout<<x<<"-->"<<bitpow2(x,y)<<endl;
    return 1;
}
