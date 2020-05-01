#include<iostream>
#include<typeinfo>
#include<vector>

void PrintValue(int value){

    std::cout << "Value" << value << std::endl;

}

void ForEach(const std::vector<int>& values, void(*func)(int)){

    for(int value: values)
        func(value);

}

void HelloWorld(){

    std::cout<<"Hello World"<<std::endl;

}

int main(){

    auto function = HelloWorld;

    //void(*HelloWorld)()

    typedef void(*HelloWorldFunction)() = aFun;

    std::cout<<typeid(function).name()<<std::endl;

    std::vector<int> values{1,2,3,4,5};

    ForEach(values, [](int value){std::cout<< "valueL:"<<value<<std::endl;});

    ForEach(values, PrintValue);

    function();
}
