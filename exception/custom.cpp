#include<iostream>
#include<exception>

using namespace std;

class MyException: public exception{
    public:
        virtual const char* what()
}

