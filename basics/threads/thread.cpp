#include<iostream>
#include<thread>
#include<string>
#include<mutex>
using namespace std;


std::mutex mu;

void fun(string msg){
    lock_guard<mutex> guard(mu);
    //mu.lock();
    cout<<msg<<endl;
    cout<<"A thread is running me"<<endl;
    //mu.unlock();
}

class functor{

    public:
        void operator ()(){
            std::cout<<"holyshit"<<std::endl;
        }
};

int main(){

    cout<<thread::hardware_concurrency()<<endl;
    thread aThread(fun, move(string("hello")));
    functor f;
    thread bThread(f);
    aThread.join();
    bThread.join();
    //aThread.detach();
    cout<<"wth"<<endl;


}
