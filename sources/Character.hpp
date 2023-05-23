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
        Character (const Character& other) = delete;
        // Move Constructor
        Character(Character&& other) noexcept = delete;
        // Copy Assignment operator
        Character& operator = (const Character& other) = delete; 
        // Move Assignment operator
        Character& operator = (Character&& other) noexcept = delete; 

        virtual ~Character() = default;
        

        bool isAlive() const;

        double distance(const Character* other);

        void hit(int damage);

        std::string getName() const;

        Point getLocation() const;

        void setLocation(const Point& loca);

        int getHitPoints();

        void setHitPoints(int hits);

        bool getPlay()const;
        
        void setPlay();

        static bool compare(Character* character1, Character* character2);

        virtual bool isCowboy() = 0;

        virtual std::string print();
    };
}

#endif
