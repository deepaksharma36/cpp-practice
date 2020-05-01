#include<memory>
#include<iostream>

using namespace std;

class Wget{
    const size_t numEle = 100000;
    public:
        Wget():mPtr{new int[numEle]} {}
        Wget(int* other): mPtr{new int[numEle]}{
            memcpy(mPtr, other, sizeof(int)*numEle);
        }

        Wget& operator =(const Wget& other){
            if(this == &other)
                return *this;
            memcpy(mPtr, other.mPtr, sizeof(int)*numEle);

        }

        bool operator <(const Wget& other){
            return intPtr
        }

        ~Wget(){
            delete[] mPtr;
        }

    private:
        int* mPtr;

};
