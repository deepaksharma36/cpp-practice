#include<iostream>
#include<vector>
#include<algorithm>
#include<stdexcept>

using namespace std;

class Queue{

    public:
        explicit Queue(size_t capacity): _que(capacity), _head{}, _tail{} {}

        void enque(int ele){
            if(_num_ele == _que.size()){
                rotate(_que.begin(), _que.begin()+_head, _que.end());
                _head = 0;
                _tail = _num_ele;
                _que.resize(_que.size()*_rescale_f);
            }
            _que[_tail] = ele;
            _tail = (_tail+1)%_que.size();
            _num_ele++;
        }

        int deque(){
            if(_num_ele == 0)
                throw length_error("empty que");
            for(size_t i=0; i<_que.size(); i++)
                cout<<_que[i];
            cout<<"\n";
            int ret = _que[_head];
            _head = (_head+1)%_que.size();
            _num_ele--;
            return ret;

        }

        size_t size(){ return _num_ele;}



    private:
        vector<int> _que;
        int _tail, _head, _rescale_f=2;
        size_t _num_ele=0;
};


int main(){
    Queue que(3);
    que.enque(1);
    que.enque(2);
    que.enque(3);
    cout<<que.deque()<<endl;
    que.enque(4);
    que.enque(5);
    cout<<que.deque()<<endl;
}

