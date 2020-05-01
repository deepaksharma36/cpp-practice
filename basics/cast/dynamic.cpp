#include<iostream>
using namespace std;
class A{

    public:
       A(): c{1} {cout<<"this"<<endl;}
       explicit A(int c): c{c} {cout<<"I am st explicity"<<endl;}
       virtual void print() {
           cout<<"from A"<<endl;
       }
       friend ostream& operator<<(const ostream& stream, const string& s );

       ~A(){cout<<"del A"<<endl;}

    private:
       double c;
};

class B: public A{

    public:
        B():d{1} {cout<<"this is b"<<endl;}
       void print() override {
           cout<<"from B"<<endl;
       }
       ~B(){cout<<"del B"<<endl;}
    private:
        int d;
};

/*ostream& operator<<(const ostream& stream, const A& a ){
    stream << a.c;
    return stream;
}*/

int main(){

    //A* aa = new A('1');
    A* aa = new A();
    B* bb = dynamic_cast<B*>(aa);
    cout<<bb<<endl;
    aa->print();
    //delete aa;
    delete bb;

    return 0;

}
