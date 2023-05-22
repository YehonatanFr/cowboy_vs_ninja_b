#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Point.hpp"
#include <string>

namespace ariel {
    class Character {
    private:
        Point location;
        int hitPoints;
        std::string name;
        bool isPlay;

    public:
        //constructor
        Character(std::string name, const Point& location, int hitPoints);
        // Copy Constructor
        Character (const Character& other);
        // Move Constructor
        Character(Character&& other) noexcept;
        // Copy Assignment operator
        Character& operator = (const Character& other); 
        // Move Assignment operator
        Character& operator = (Character&& other) noexcept; 

        virtual ~Character() = default;
        

        bool isAlive() const;

        double distance(const Character* other);

        void hit(int damage);

        std::string getName() const;

        Point getLocation() const;

        void setLocation(const Point& loca);

        int getHitPoints();

        void setHitPoints(int hits);

        bool play()const;
        
        void setPlay(bool playNow);

        virtual std::string print();
    };
}

#endif
