#include "Team2.hpp"

using namespace std;

namespace ariel{

    Team2::Team2(Character *leader) 
    : Team(leader) {}


    void Team2::add(Character* character) {
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

    // string Team2::print() {
    //     string output;
    //     for (const auto& member : members) {
    //         output += member->print() + "\n";
    //     }
    //     return output;
    // }
}
