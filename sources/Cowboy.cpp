#include "Cowboy.hpp"

using namespace std;

namespace ariel {

    Cowboy::Cowboy(std::string name, Point location) 
    :Character(name, location, 110), bullets(6){}


    void Cowboy::shoot(Character* enemy) {
        if (isAlive() && enemy != this && enemy->isAlive() && hasboolets()) {
            enemy->hit(10);
            this->bullets--;
        } else {
            if (!isAlive()) {
                throw runtime_error("Cannot shoot when dead");
            } else if (enemy == this) {
                throw runtime_error("Cannot shoot oneself");
            } else if (!enemy->isAlive()) {
                throw runtime_error("Cannot shoot a dead enemy");
            } else if (bullets == 0) {
                throw runtime_error("No bullets remaining");
            }
        }
    }


    bool Cowboy::hasboolets(){
        return bullets > 0;

    }

    void Cowboy::reload() {
        if (!(this->isAlive())){
            throw runtime_error("This Cowboy is dead, cant do reload");
        }
        bullets = 6;
    }

    bool Cowboy::isCowboy(){
        return true;
    } 

    string Cowboy::print(){
        if(this->isAlive()){
            return " C " + Character::print();
        }
        else{
            return "(" + this->getName() +") , Location: " + this->getLocation().print();

        }
    }
}
