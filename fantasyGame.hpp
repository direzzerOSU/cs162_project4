/*********************************************************************
** Program name: Fantasy Combat Game 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#ifndef FANTASYGAME_H
#define FANTASYGAME_H

#include "inputValidation.hpp"

#include<cstdlib>
#include<ctime>

class Character {
 public:
    Character() {};
    virtual int attacking() = 0;
    virtual void defending(int) = 0;
    virtual int getStrength() = 0;
    virtual std::string getType() = 0;
    int roll(int, int);
    void printStats();
    virtual ~Character() {};
 protected:
    std::string charType;
    int attack = 0;
    int defense = 0;
    int armor = 0;
    int strength = 0;
};

class Barbarian : public Character {
 public:
    // default (Barbarian character) constructor
    Barbarian() : Character() {
      armor = 0;
      strength = 12;
    }
    int attacking();
    void defending(int);
    int getStrength();
    std::string getType();
    ~Barbarian() {};    // destructor (of Barbarian character objects)
 private:
    std::string charType = "Barbarian";
    int armor = 0;
    int strength = 12;
};

class Vampire : public Character {
 public:
    // default (Vampire character) constructor
    Vampire() : Character() {
      armor = 1;
      strength = 18;
    }
    int attacking();
    void defending(int);
    int getStrength();
    std::string getType();
    ~Vampire() {};      // destructor (of Vampire character objects)
 private:
    std::string charType = "Vampire";
    int armor = 1;
    int strength = 18;
};

class BlueMen : public Character {
 public:
    BlueMen() : Character() {
       armor = 3;
       strength = 12;    
    }
    int attacking();
    void defending(int);
    int getStrength();
    std::string getType();
    ~BlueMen() {};      // destructor (of Blue Men character objects)
 private:
    std::string charType = "Blue Men";
    int armor = 3;
    int strength = 12;   
};

class Medusa : public Character {
 public:
    Medusa() : Character() {
       armor = 3;
       strength = 8;    
    }
    int attacking();
    void defending(int);
    int getStrength();
    std::string getType();
    ~Medusa() {};      // destructor (of Medusa character objects)
 private:
    std::string charType = "Medusa";
    int armor = 3;
    int strength = 8;  
};

class HarryPotter : public Character {
 public:
    HarryPotter() : Character() {
       armor = 3;
       strength = 10;         
    }
    int attacking();
    void defending(int);
    int getStrength();
    std::string getType();
    ~HarryPotter() {};      // destructor (of HarryPotter character objects)
 private:
    std::string charType = "Harry Potter";
    int armor = 0;
    int strength = 10; // should be: 10/20
    int lives = 2;
};

#endif
