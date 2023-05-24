#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"
#include "Point.hpp"
#include "Character.hpp"
#include <vector>
#include <string>

namespace ariel {
    class Team2 : public Team{
    private:
        std::vector<Character*> members;
        Character* leader;

    public:
        //constructor
        explicit Team2(Character* leader);
        //deconstructor
        ~Team2() override;

        void add(Character* character) override;
    };
}

#endif
