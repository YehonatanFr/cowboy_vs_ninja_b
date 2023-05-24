#include "Team.hpp"
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>

using namespace std;

namespace ariel{

    Team::Team(Character *leader)
    {
        if(leader->getPlay())
            throw runtime_error("Cant be both teams");
        if(leader==nullptr) 
            throw invalid_argument ("Leader can't be null pointer");
        if(!leader->isAlive()) 
            throw invalid_argument ("leader cant be dead man");

        this->leader = leader;
        leader->setPlay();
        this->members.push_back(leader);
    }

    Team::~Team() {
        for(Character* character: this->members){
            delete character;
        }
    }

    void Team::add(Character* character)
    {
        if(character->getPlay())
            throw runtime_error("Cant be both teams");
        if(this->members.size() == 10)
            throw runtime_error("Cant be over 10 characters in one team");
        if(!character->isAlive()) 
            throw invalid_argument ("Cant add dead man");
        if(character==nullptr) 
            throw invalid_argument ("Can't add null pointer");

        character->setPlay();
        this->members.push_back(character);
        sort(members.begin(), members.end() , &Character::compare);
    }

    void Team::attack(Team* enemyTeam) {
        if (enemyTeam == nullptr) {
            throw std::invalid_argument("Enemy team cannot be null");
        }

        if (enemyTeam->stillAlive() == 0) {
            throw std::runtime_error("Attacking a dead team should throw an exception");
        }

        SetNewLeader();
        Character* target = nullptr;

        for (Character* c : enemyTeam->getCharacters()) {
            if (c->isAlive() && (target == nullptr || c->distance(this->leader) < target->distance(this->leader))) {
                target = c;
            }
        }

        for (Character* attacker : this->getCharacters()) {
            if (attacker->isAlive() && target->isAlive()) {
                Cowboy* cowboy = dynamic_cast<Cowboy*>(attacker);
                Ninja* ninja = dynamic_cast<Ninja*>(attacker);

                if (cowboy != nullptr) {
                    if (cowboy->hasboolets()) {
                        cowboy->shoot(target);
                    } else {
                        cowboy->reload();
                    }
                } else if (ninja != nullptr) {
                    if (ninja->distance(target) < 1) {
                        ninja->slash(target);
                    } else {
                        ninja->move(target);
                    }
                }
            }

            if (this->stillAlive() == 0 || enemyTeam->stillAlive() == 0) {
                return;
            }

            if (!target->isAlive()) {
                target = nullptr;

                for (Character* c : enemyTeam->getCharacters()) {
                    if (c->isAlive() && (target == nullptr || c->distance(this->leader) < target->distance(this->leader))) {
                        target = c;
                    }
                }
            }
        }
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

    void Team::setCharacters(Character* NewCharacter){
        this->members.push_back(NewCharacter);
    }

    void Team::SetNewLeader(){
        if (!leader->isAlive()) {
            Character* newLeader = nullptr;
            double minDistance = numeric_limits<double>::max();

            for (Character* character : members) {
                if (character->isAlive() && character->distance(leader) < minDistance) {
                    newLeader = character;
                    minDistance = character->distance(leader);
                }
            }

            if (newLeader != nullptr) {
                leader = newLeader;
            }
        }
        
    }
    
    void Team::print()
    {
        cout << "Team Members:" << endl;
        for (Character* character : members) {
            cout << character->print() << endl;
        }
    }
}

