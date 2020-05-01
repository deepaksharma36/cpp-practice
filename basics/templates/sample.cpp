#include<iostream>
#include<string>


void Print(int value){
    std::cout <<value <<std::endl;
}

void Print(std::string value){
    std::cout <<value <<std::endl;
}

void Print(double value){
    std::cout <<value <<std::endl;
}

template<typename T>
void Print(T value){
    std::cout<<"Template" <<value <<std::endl;
}
int main(){

    Print(5);
    Print("Hello");
    std::string str = "hey";
    Print(str);
    Print(5.999f);
    Print<float>(5.999);
    Print(5.999);
    return 0;
}
