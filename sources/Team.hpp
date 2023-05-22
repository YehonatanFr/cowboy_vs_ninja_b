#ifndef TEAM_HPP
#define TEAM_HPP

#include "Point.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include <vector>
#include "Character.hpp"

namespace ariel {
    class Team {
    private:
        std::vector<Character*> members;
        Character* leader;

    public:
        //constructor
        explicit Team(Character* leader);
        // Copy Constructor
        Team(const Team& other);
        // Move Constructor
        Team(Team&& other) noexcept;
        // Copy Assignment operator
        Team& operator=(const Team& other);
        // Move Assignment operator
        Team& operator=(Team&& other) noexcept;

        //deconstructor
        virtual ~Team();

        virtual void add(Character* character);
        void attack(Team* enemyTeam);
        int stillAlive();
        std::vector<Character*> getCharacters();
        void setCharacters(Character* NewCharacter);
        void updateLeader();

        std::string print();
    };
}

#endif
