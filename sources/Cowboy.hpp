#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
#include "Point.hpp"

namespace ariel {
    class Cowboy : public Character {
    private:
        int bullets;

    public:
        Cowboy(std::string name, Point location);

        void shoot(Character* enemy);

        bool hasboolets() ;

        void reload();

        bool isCowboy() override;

        std::string print() override;
    };
}

#endif
