#include "Character.hpp"
#include "Point.hpp"
#include <iostream>

using namespace std;

namespace ariel {
    // Constructor
    Character::Character(std::string name, const Point& location, int hitPoints)
        : name(name), location(location), hitPoints(hitPoints) {}

    // Copy Constructor
    Character::Character(const Character& other)
        : name(other.name), location(other.location), hitPoints(other.hitPoints) {}

    // Move Constructor
    Character::Character(Character&& other) noexcept
        : name(move(other.name)), location(move(other.location)), hitPoints(other.hitPoints) {}

    // Copy Assignment operator
    Character& Character::operator=(const Character& other) {
        if (this != &other) {
            name = other.name;
            location = other.location;
            hitPoints = other.hitPoints;
        }
        return *this;
    }

    // Move Assignment operator
    Character& Character::operator=(Character&& other) noexcept {
        if (this != &other) {
            name = move(other.name);
            location = move(other.location);
            hitPoints = other.hitPoints;
        }
        return *this;
    }

    bool Character::isAlive() const {
        return hitPoints > 0;
    }

    double Character::distance(const Character* other) {
        return location.distance(other->getLocation());
    }

    void Character::hit(int damage) {
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

    bool Character::play()const{
        return this->isPlay;
    }
    
    void Character::setPlay(bool is_Play){
        this->isPlay = is_Play;
    }

    string Character::print() {
        return name + " - Hit Points: " + to_string(hitPoints) + ", Location: " + location.print();
    }


}
