#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"
#include "Point.hpp"
#include "Character.hpp"
#include <vector>
#include <string>

namespace ariel {
    class SmartTeam : public Team{
    private:
        std::vector<Character*> members;
        Character* leader;

    public:
        //constructor
        explicit SmartTeam(Character* leader);
        //deconstructor
        // ~SmartTeam() override;

        // void add(Character* character) override;
        // std::string print();
    };
}

#endif
