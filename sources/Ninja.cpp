#include "Ninja.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>

using namespace std;

namespace ariel {

    Ninja::Ninja(string name, const Point& location, int hitPoints, int speed)
    :Character(name,location, hitPoints) ,speed(speed) {}


    void Ninja::move(Character* enemy) {
        if (this == enemy)
            throw runtime_error("No self harm");

        if (!isAlive() || !enemy->isAlive())
            throw runtime_error("Dead characters cannot move, and characters cannot move towards a dead enemy");

        double distanceToEnemy = sqrt(pow(enemy->getLocation().getX() - getLocation().getX(), 2) + pow(enemy->getLocation().getY() - getLocation().getY(), 2));
        if (distanceToEnemy > speed) {
            double dx = enemy->getLocation().getX() - getLocation().getX();
            double dy = enemy->getLocation().getY() - getLocation().getY();
            double ratio = speed / distanceToEnemy;
            double moveX = dx * ratio;
            double moveY = dy * ratio;
            setLocation(Point(getLocation().getX() + moveX, getLocation().getY() + moveY));
        } else {
            setLocation(enemy->getLocation());
        }
    }



    void Ninja::slash(Character* enemy) {
        if (isAlive() && enemy != this && enemy->isAlive() && distance(enemy) < 1) {
            enemy->hit(40);
        } else {
            if (!isAlive()) {
                throw runtime_error("Cannot slash when dead");
            } else if (enemy == this) {
                throw runtime_error("Cannot slash oneself");
            } else if (!enemy->isAlive()) {
                throw runtime_error("Cannot slash a dead enemy");
            } else if (distance(enemy) >= 1) {
                throw runtime_error("Enemy is out of range for slashing");
            }
        }
    }


    int Ninja::getSpeed(){
        return this->speed;
    }


    void Ninja::setSpeed(int newSpeed){
        this->speed = newSpeed;
    }

    string Ninja::print() {
        if(this->isAlive()){
            return " N " + Character::print();
        }
        else{
            return "(" + this->getName() +") , Location: " + this->getLocation().print();

        }
    }
}
