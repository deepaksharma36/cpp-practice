#include<iostream>

using namespace std;

enum class Color{red, green, blue};
enum class Traffic{green, yellow, red};

Traffic& operator++(Traffic& t){

    switch(t){
        case Traffic::green: return t=Traffic::yellow;
        case Traffic::yellow: return t=Traffic::red;
        case Traffic::red: return t=Traffic::green;
    }
}

int main(){

    //Color x = red;
    //Color y = Traffic::red;
    Color z = Color::red;

    Traffic next = ++z;
    std::cout<<z<<std::endl;


    return 0;


}
