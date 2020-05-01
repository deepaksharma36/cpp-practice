#include<iostream>
#include<queue>
#include<deque>
#include<stdexcept>

using namespace std;

class Queue{

    public:
        int max(){
            if(que.empty())
               throw length_error("Max from empty que");
            return max_deq.front();

        }

        void inque(int val){
            que.push(val);
            while(!max_deq.empty() && max_deq.back() < val){
                max_deq.pop_back();
            }
            max_deq.push_back(val);

        }

        int deque(){
            if(que.empty())
                throw length_error("Deque from empty que");
            int ret = que.front();
            que.pop();
            if(ret==max_deq.front())
                max_deq.pop_front();
            return ret;
        }


    private:
        std::queue<int> que;
        std::deque<int> max_deq;
};

int main(){
    Queue que;
    que.inque(3);
    cout<<"Max"<<que.max()<<endl;
    que.inque(1);
    cout<<"Max"<<que.max()<<endl;
    que.inque(3);
    cout<<"Max"<<que.max()<<endl;
    que.inque(2);
    cout<<"Max"<<que.max()<<endl;
    que.inque(0);
    cout<<"Max"<<que.max()<<endl;
    cout<<que.deque()<<endl;
    cout<<"Max"<<que.max()<<endl;
    cout<<que.deque()<<endl;
    cout<<"Max"<<que.max()<<endl;
    que.inque(1);
    cout<<"Max"<<que.max()<<endl;
    que.inque(2);
    cout<<"Max"<<que.max()<<endl;
    que.inque(4);
    cout<<"Max"<<que.max()<<endl;
    que.inque(5);
    cout<<"Max"<<que.max()<<endl;
}
