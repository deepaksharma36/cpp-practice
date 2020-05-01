#include<iostream>

class Baap{

    public:
        virtual void bc() = 0;

};

class A: Baap{


    public:
        A(){std::cout<<"A constructor"<<std::endl;}
        virtual ~A(){std::cout<<"A destructor"<<std::endl;}
        void bc(){std::cout<<"gand marao"<<std::endl;}



};

class B: public A{

    public:
        B(){std::cout<<"B constructor"<<std::endl;}
        ~B(){std::cout<<"B destructor"<<std::endl;}
};


int main(){


    //B* bb = new B;

    //delete bb;

    A* aa = new B;

    delete aa;
}
