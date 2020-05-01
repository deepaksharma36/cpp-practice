#include<iostream>
#include "log.h"

//void Log(const char* message);

void Logger();

int main(){
    Logger();
    Log("Hello");
    std::cin.get();
    return 0;
}
