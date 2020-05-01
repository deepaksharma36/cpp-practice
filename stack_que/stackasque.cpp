#include<iostream>
#include<stack>
#include<stdexcept>

using namespace std;

class Queue{

    public:
        //explicit Queue():

        void enque(int i){
            first_.push(i);
        }

        int deque(){
            if(second_.empty()){
                while(!first_.empty()){
                    second_.push(first_.top());
                    first_.pop();
                }
            }

            if(second_.empty())
                throw length_error("Pop from an empty que");

            int ret = second_.top();
            second_.pop();
            return ret;
        }

    private:
        stack<int> first_, second_;
};


int main(){
    Queue que;
    que.enque(1);
    que.enque(2);
    que.enque(3);
    que.enque(4);
    cout<<que.deque()<<endl;
    cout<<que.deque()<<endl;
    que.enque(5);
    que.enque(6);
    cout<<que.deque()<<endl;
    cout<<que.deque()<<endl;
    cout<<que.deque()<<endl;
    cout<<que.deque()<<endl;
    cout<<que.deque()<<endl;
    cout<<que.deque()<<endl;
}
