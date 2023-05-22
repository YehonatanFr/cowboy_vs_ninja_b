#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
    protected:
        int speed;

    public:
        Ninja(std::string name, const Point& location, int hitPoints, int speed);

        void move(Character* enemy);

        void slash(Character* enemy);

        int getSpeed();

        void setSpeed(int newSpeed);

        std::string print() override;
    };
}

#endif
