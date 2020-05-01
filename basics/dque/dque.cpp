#include<iostream>
#include<deque>

int main(){

    std::deque<int> adque;

    adque.push_back(5);
    adque.push_front(4);

    std::cout<<adque.front()<<std::endl;
    std::cout<<adque.back()<<std::endl;

    adque.pop_back();
    adque.pop_front();
}
