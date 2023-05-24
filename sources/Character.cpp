#include "Character.hpp"
#include "Point.hpp"
#include <iostream>

using namespace std;

namespace ariel {

    // Constructor
    Character::Character(std::string name, const Point& location, int hitPoints)
        : name(name), location(location), hitPoints(hitPoints) ,isPlay(false){}


    bool Character::isAlive() const {
        return hitPoints > 0;
    }

    double Character::distance(const Character* other) {
        return location.distance(other->getLocation());
    }

    void Character::hit(int damage) {
        if(damage < 0)
            throw invalid_argument (" Cant get a negative ");

        hitPoints -= damage;
        if (hitPoints < 0) {
            hitPoints = 0;
        }
    }

    string Character::getName() const {
        return name;
    }

    Point Character::getLocation() const {
        return location;
    }

    void Character::setLocation(const Point& loca) {
        location = loca;
    }

    int Character::getHitPoints(){
        return hitPoints;
    }

    void Character::setHitPoints(int hits){
        this->hitPoints = hits;
    }

    bool Character::getPlay()const{
        return this->isPlay;
    }
    
    void Character::setPlay(){
        this->isPlay = true;
    }

    bool Character::compare(Character* character1, Character* character2){
        return character1->isCowboy() && ! character2->isCowboy();
    }

    string Character::print() {
        return name + " - Hit Points: " + to_string(hitPoints) + ", Location: " + location.print();
    }


}
