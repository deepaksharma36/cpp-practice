#include<iostream>
#include<list>
#include<unordered_map>
#include<string>

using namespace std;

struct Book{

    int price;
    string name;
};


class Lru{

    public:
        Lru(int capacity): capacity{capacity} {}

        /*void remove(string b){
            Book bs* = map[b];
            bs-

        }*/

        bool Erase(string& name){
            if(map.find(name) == map.end())
                return false;
            cash.erase(map[name]);
            map.erase(name);
            for(auto it = cash.begin(); it != cash.end(); it++)
                cout<<(*it)->name<<endl;

            return true;

        }

        bool Lookup(string& name){
            if(map.find(name) == map.end())
                return false;
            cout<<(*map[name])->name<<"->"<<(*map[name])->price<<endl;
            cash.erase(map[name]);
            cash.push_front(*map[name]);
            map[name] = cash.begin();
            for(auto it = cash.begin(); it != cash.end(); it++)
                cout<<(*it)->name<<endl;
            return true;}

        void Insert(Book*& b){
            if(map.find(b->name) == map.end()){
               if(cash.size() == capacity){
                    map.erase(cash.back()->name);
                    cash.pop_back();}
                cash.push_front(b);
                map[b->name] = cash.begin();}
            else{
                list<Book*>::iterator exiting_book_entry = map[b->name];
                cout<<"itr rend"<< (*exiting_book_entry)->price<<endl;
                (*exiting_book_entry)->price = b->price;
                cash.erase(exiting_book_entry);
                //map.erase((*exiting_book_entry)->name);
                cash.push_front(*exiting_book_entry);
                map[(*exiting_book_entry)->name] =cash.begin();

                //map[b->name]
            }
                for(auto it = cash.begin(); it != cash.end(); it++)
                    cout<<(*it)->name<<endl;}




    private:
        int capacity;
        list<Book*> cash;
        unordered_map<string, list<Book*>::iterator> map;


};


int main(){

    Lru alru(3);
    Book* b1 = new Book{1, "Ramayan"};
    alru.Insert(b1);
    cout<<"Insertion done"<<endl;
    Book* b2 = new  Book{2, "Gita"};
    alru.Insert(b2);
    cout<<"Insertion done"<<endl;
    Book* b3 = new Book{3, "Mahabharat"};
    alru.Insert(b3);
    cout<<"Insertion done"<<endl;
    Book* b4 = new Book{10, "Mahabharat"};
    alru.Insert(b4);
    cout<<"Insertion done"<<endl;
    Book* b5 = new Book{5, "Bibal"};
    alru.Insert(b5);
    string k = "Gita";
    //alru.Lookup(string("Gita"));
    alru.Lookup(k);
    k = "Bibal";
    //alru.Lookup(string("Gita"));
    cout<<"Eraseing"<<endl;
    alru.Erase(k);
    cout<<"Insertion done"<<endl;
    delete b1;
    delete b2;
    delete b3;
    delete b4;
    delete b5;
    return 0;
}
