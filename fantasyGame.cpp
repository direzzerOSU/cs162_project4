/*********************************************************************
** Program name: Fantasy Combat Game 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#include "fantasyGame.hpp"

// rolls a given [number] number of dice; each die has [sides] number of sides
// the range of possible returned values is: 1 - [sides]
int Character::roll(int number, int sides) {
   int value = 0;
   for(int n=0; n<number; n++) {
      value += (rand() % sides)+1;
   }
   return value;
}

// restores a random percentage of the character's strength (health)
void Character::restoreStrength(int damage) {
   float percent = rand() % 100;
   percent = percent/100.00 + 1;

   damage = damage * percent;
   strength += damage;
}

//################################################################

// returns Barbarian
std::string Barbarian::getType() {
   return charType;
}

// sets the Barbarian's name
void Barbarian::setName(std::string x) {
   name = x;
}

// returns the Barbarian's name
std::string Barbarian::getName() {
   return name;
}

// generates (returns) an attack value for the barbarian character type
int Barbarian::attacking() {
   // rolls two 6-sided dice
   int value = 0;
   value += roll(2, 6);

   attack = value;
   cout << "Attacker Type: " << charType << endl;
   return value;
}

// prints most of the attack stats & updates player stats based on attack results
int Barbarian::defending(int attacker) {
   int defender = 0;

   cout << "Defender Type: " << charType << endl;
   cout << "Defender Armor: " << armor << endl;
   cout << "Defender Strength Points: " << strength << endl;
   cout << "Attacker's Dice Roll: " << attacker << endl;

   // rolls two 6-sided dice
   defender += roll(2, 6);
   defense = defender;
   cout << "Defender's Dice Roll: " << defense << endl;

   int damage = attacker - defense - armor;
   
   // apply attack & defense for any impact to strength (health)
   if(damage > 0) {
      strength -= damage;
      cout << "Total Inflicted Damage: " << damage << endl;
      cout << "Defender's Updated Strength: " << strength << endl;

      if(strength <= 0) {
         cout << endl << getName() << " has been defeated!" << endl;
      }

      return damage;
   }
   else {
      // do nothing - the char defended against the attack
      cout << "Total Inflicted Damage: 0" << endl;
      cout << "Defender's Updated Strength: " << strength << endl;
      
      return 0;
   }
}

// returns the amount of strength (health)
int Barbarian::getStrength() {
   return strength;
}

//################################################################

// returns Vampire
std::string Vampire::getType() {
   return charType;
}

// sets the Vampire's name
void Vampire::setName(std::string x) {
   name = x;
}

// returns the Vampire's name
std::string Vampire::getName() {
   return name;
}

// generates an attack value for the Vampire character type
int Vampire::attacking() {
   // rolls one 12-sided dice
   int value = 0;
   value += roll(1, 12);

   attack = value;
   cout << "Attacker Type: " << charType << endl;
   return value;
}

// prints most of the attack stats & updates player stats based on attack results
int Vampire::defending(int attacker) {
   int defender = 0;

   cout << "Defender Type: " << charType << endl;
   cout << "Defender Armor: " << armor << endl;
   cout << "Defender Strength Points: " << strength << endl;
   cout << "Attacker's Dice Roll: " << attacker << endl;

   // rolls one 6-sided dice
   defender += roll(1, 6);    
   defense = defender;
   cout << "Defender's Dice Roll: " << defense << endl;

   int damage = 0;

   // 1/2 (50%) odds of activating charm or not
   int activateCharm = rand() % 2;

   // charm is NOT activated
   if(activateCharm == 0) {
      damage = attacker - defense - armor;
   }
   // charm is activated
   else if(activateCharm == 1) {
      cout << "The Vampire charmed his opponent into not attacking! \nThe opponent didn't do any harm..." << endl;
   }
   
   // apply attack & defense for any impact to strength (health)
   if(damage > 0) {
      strength -= damage;
      cout << "Total Inflicted Damage: " << damage << endl;
      cout << "Defender's Updated Strength: " << strength << endl;

      if(strength <= 0) {
         cout << endl << getName() << " has been defeated!" << endl;
      }

      return damage;
   }
   else {
      // do nothing - the char defended against the attack
      cout << "Total Inflicted Damage: 0" << endl;
      cout << "Defender's Updated Strength: " << strength << endl;

      return 0;
   }
}

// returns the amount of strength (health)
int Vampire::getStrength() {
   return strength;
}

//################################################################

// returns Blue Men
std::string BlueMen::getType() {
   return charType;
}

// sets the BlueMen's name
void BlueMen::setName(std::string x) {
   name = x;
}

// returns the BlueMen's name
std::string BlueMen::getName() {
   return name;
}

// generates an attack value for the BlueMen character type
int BlueMen::attacking() {
   // rolls two 10-sided dice
   int value = 0;
   value += roll(2, 10);

   attack = value;
   cout << "Attacker Type: " << charType << endl;
   return value;
}

// prints most of the attack stats & updates player stats based on attack results
int BlueMen::defending(int attacker) {
   int defender = 0;

   cout << "Defender Type: " << charType << endl;
   cout << "Defender Armor: " << armor << endl;
   cout << "Defender Strength Points: " << strength << endl;
   cout << "Attacker's Dice Roll: " << attacker << endl;

   // rolls (defense) dice
   if(strength > 8) {
      defender = roll(3, 6);
   }
   // lost one die
   else if(strength > 4 & strength <= 8) {
      defender = roll(2, 6);
   }
   // lost a second die
   else if(strength <= 4) {
      defender = roll(1, 6);
   }   
   
   defense = defender;
   cout << "Defender's Dice Roll: " << defense << endl;

   int damage = attacker - defense - armor;
   
   // apply attack & defense for any impact to strength (health)
   if(damage > 0) {
      strength -= damage;
      cout << "Total Inflicted Damage: " << damage << endl;
      cout << "Defender's Updated Strength: " << strength << endl;

      if(strength <= 0) {
         cout << endl << getName() << " has been defeated!" << endl;
      }

      return damage;
   }
   else {
      // do nothing - the char defended against the attack
      cout << "Total Inflicted Damage: 0" << endl;
      cout << "Defender's Updated Strength: " << strength << endl;

      return 0;
   }
}

// returns the amount of strength (health)
int BlueMen::getStrength() {
   return strength;
}

//################################################################

// returns Medusa
std::string Medusa::getType() {
   return charType;
}

// sets the Medusa's name
void Medusa::setName(std::string x) {
   name = x;
}

// returns the Medusa's name
std::string Medusa::getName() {
   return name;
}

// generates an attack value for the Medusa character type
int Medusa::attacking() {
   // rolls two 6-sided dice
   int value = 0;
   value += roll(2, 6);

   attack = value;
   cout << "Attacker Type: " << charType << endl;

   // Medusa's "Glare" special ability
   if(value == 12) {
      value += 100;  // ensure that the enemy dies
      cout << "Medusa used her special ability, Glare, and turned the defender into stone!" << endl;
   }
   return value;
}

// prints most of the attack stats & updates player stats based on attack results
int Medusa::defending(int attacker) {
   int defender = 0;

   cout << "Defender Type: " << charType << endl;
   cout << "Defender Armor: " << armor << endl;
   cout << "Defender Strength Points: " << strength << endl;
   cout << "Attacker's Dice Roll: " << attacker << endl;

   // rolls one 6-sided dice
   defender = roll(1, 6);
   defense = defender;
   cout << "Defender's Dice Roll: " << defense << endl;

   int damage = attacker - defense - armor;
   
   // apply attack & defense for any impact to strength (health)
   if(damage > 0) {
      strength -= damage;
      cout << "Total Inflicted Damage: " << damage << endl;
      cout << "Defender's Updated Strength: " << strength << endl;

      if(strength <= 0) {
         cout << endl << getName() << " has been defeated!" << endl;
      }

      return damage;
   }
   else {
      // do nothing - the char defended against the attack
      cout << "Total Inflicted Damage: 0" << endl;
      cout << "Defender's Updated Strength: " << strength << endl;

      return 0;
   }
}

// returns the amount of strength (health)
int Medusa::getStrength() {
   return strength;
}

//################################################################

// returns Harry Potter
std::string HarryPotter::getType() {
   return charType;
}

// sets the HarryPotter's name
void HarryPotter::setName(std::string x) {
   name = x;
}

// returns the HarryPotter's name
std::string HarryPotter::getName() {
   return name;
}

// generates an attack value for the HarryPotter character type
int HarryPotter::attacking() {
   // rolls two 6-sided dice
   int value = 0;
   value += roll(2, 6);

   attack = value;
   cout << "Attacker Type: " << charType << endl;
   return value;
}

// prints most of the attack stats & updates player stats based on attack results
int HarryPotter::defending(int attacker) {
   int defender = 0;

   cout << "Defender Type: " << charType << endl;
   cout << "Defender Armor: " << armor << endl;
   cout << "Defender Strength Points: " << strength << endl;
   cout << "Attacker's Dice Roll: " << attacker << endl;

   // rolls two 6-sided dice
   defender = roll(2, 6);
   defense = defender;
   cout << "Defender's Dice Roll: " << defense << endl;

   int damage = attacker - defense - armor;
   
   // apply attack & defense for any impact to strength (health)
   if(damage > 0) {
      strength -= damage;
      cout << "Total Inflicted Damage: " << damage << endl;
      cout << "Defender's Updated Strength: " << strength << endl;

      if(strength <= 0 && lives == 2) {
         cout << endl << "The attacker killed Harry Potter!..." << endl;
         cout << "But wait... Harry Potter is reborn with a second life!" << endl;
         cout << "Harry Potter's strength has been restored to 20..." << endl;

         strength = 20;
         lives -= 1;
      }
      else if(strength <= 0 && lives == 1) {
         lives -= 1;
         cout << endl << getName() << " has been defeated!" << endl;
      }

      return damage;
   }
   else {
      // do nothing - the char defended against the attack
      cout << "Total Inflicted Damage: 0" << endl;
      cout << "Defender's Updated Strength: " << strength << endl;
      
      return 0;
   }
}

// returns the amount of strength (health)
int HarryPotter::getStrength() {
   return strength;
}

// takes two characters (fighters) as function parameters and executes rounds
// of combat until one of the two characters (fighters) dies (i.e., strength <= 0)
Character* Fight(Character* player1, Character* player2) {
   int attack = 0;
   int counter = 1;
   int damage1 = 0;
   int damage2 = 0;

   // start the fight
   while(player1->getStrength() > 0 && player2->getStrength() > 0) {
      cout << "Round #" << counter << " (Player #1: " << player1->getName() << " Attack): " << endl;
      attack = 0;
      attack = player1->attacking();
      damage2 += player2->defending(attack);

      if(player2->getStrength() > 0) {
         cout << endl << "Round #" << counter << " (Player #2: " << player2->getName() << " Attack): " << endl;
         attack = 0;
         attack = player2->attacking();
         damage1 = player1->defending(attack);
      }

      counter += 1;

      cout << endl;
      cout << "----------------------------------------" << endl << endl;
   }

   if(player1->getStrength() <= 0 && player2->getStrength() > 0) {
      cout << "Congratulations! " << "Player #2: " << player2->getName() << " Won!" << endl;
      cout << endl << "----------------------------------------" << endl << endl;
      player2->restoreStrength(damage2);
      return player1;
   }
//   else(player1->getStrength() > 0 && player2->getStrength() <= 0) {
   else {
      cout << "Congratulations! " << "Player #1: " << player1->getName() << " Won!" << endl;
      cout << "----------------------------------------" << endl << endl;
      player1->restoreStrength(damage1);
      return player2;
   }
//   else {
//      cout << "Whoops! Looks like there's a bug with finding the winner of the fight..." << endl;
//   }
}
