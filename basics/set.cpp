#include<set>
#include<iostream>



class A{
    public:

        A(int val): val{val} {};

        /*bool operator< (const A a) const{
            return val < a.getVal();
        }*/

        int getVal() const{
            return val;
        }

        friend std::ostream& operator <<(std::ostream& os, const A ao);

    private:
        int val;
};

struct Comparator{

    bool operator()(const A a, const A b){
        return a.getVal() < b.getVal();
    }

};


std::ostream& operator <<(std::ostream& os, const A ao){
    os<<ao.getVal()<<std::endl;
}


void show(const std::set<A>& a){
    for(auto itm: a)
        std::cout<<itm;

}

int main(){

    std::set<A, Comparator> aSet;

    A aa(5);
    std::pair<std::set<A>::iterator, bool> result = aSet.insert(aa);
    std::cout << result.second<<std::endl;



    A ab(1);
    aSet.insert(ab);

    A ac(2);
    aSet.insert(ac);

    //show(aSet);
    for(auto itm: aSet)
        std::cout<<itm<<std::endl;
}
