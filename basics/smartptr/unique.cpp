#include<iostream>
#include<string>
#include<memory>

class Entity{
    public:
        Entity(){
            std::cout << "Created Entity!" <<std::endl;
        }

        ~Entity(){
            std::cout << "Deleted Entity!" <<std::endl;
        }

};

int main(){

        std::shared_ptr<Entity> sharedEntity;
    {
        //std::unique_ptr<Entity> u_entity(new Entity());
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();

    }

    std::cin.get();
}
