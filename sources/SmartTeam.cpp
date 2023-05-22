#include "SmartTeam.hpp"

using namespace std;

namespace ariel{

    SmartTeam::SmartTeam(Character *leader) 
    : Team(leader) {}


    void SmartTeam::add(Character* character) {
        members.push_back(character);
    }

    // int Team2::stillAlive() const {
    //     int count = 0;
    //     for (const auto& member : members) {
    //         if (member->isAlive()) {
    //             count++;
    //         }
    //     }
    //     return count;
    // }

    // string SmartTeam::print() {
    //     string output;
    //     for (const auto& member : members) {
    //         output += member->print() + "\n";
    //     }
    //     return output;
    // }
}
