#include "Team2.hpp"

using namespace std;

namespace ariel{

    Team2::Team2(Character *leader) 
    : Team(leader) {}

    Team2::~Team2() {
        for (Character* character : members) {
            delete character;
        }

    }



    void Team2::add(Character* character) {
        if(character->getPlay())
            throw runtime_error("Cant be both teams");
        if(this->getCharacters().size() == 10)
            throw runtime_error("Cant be over 10 characters in one team");
        if(!character->isAlive()) 
            throw invalid_argument ("Cant add dead man");
        if(character==nullptr) 
            throw invalid_argument ("Can't add null pointer");

        this->setCharacters(character);
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
