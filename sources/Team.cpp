#include "Team.hpp"

using namespace std;

namespace ariel{

    Team::Team(Character *leader)
    : leader(leader){}

    Team::~Team() {
        for(Character* character: this->members){
            delete character;
        }
    }

    void Team::add(Character* character)
    {
    }

    void Team::attack(Team* enemyTeam)
    {
    }

    int Team::stillAlive()
    {
        int sumAlive = 0;
        for (Character* c: this->members) {
            if(c->isAlive())
                sumAlive++;
        }
        return sumAlive;
    }

    vector<Character*> Team::getCharacters(){
        return this->members;
    }

    void Team::setCharacters(ariel::Character* NewCharacter){
        this->members.push_back(NewCharacter);
    }

    void Team::updateLeader(){
    }
    
    string Team::print()
    {
        return "";
    }
}

