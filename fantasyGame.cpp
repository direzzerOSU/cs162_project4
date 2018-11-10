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

//################################################################

// returns Barbarian
std::string Barbarian::getType() {
   return charType;
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
void Barbarian::defending(int attacker) {
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
         cout << endl << "Barbarian has been defeated!" << endl;
      }
   }
   else {
      // do nothing - the char defended against the attack
      cout << "Total Inflicted Damage: 0" << endl;
      cout << "Defender's Updated Strength: " << strength << endl;
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
void Vampire::defending(int attacker) {
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
         cout << endl << "Vampire has been defeated!" << endl;
      }
   }
   else {
      // do nothing - the char defended against the attack
      cout << "Total Inflicted Damage: 0" << endl;
      cout << "Defender's Updated Strength: " << strength << endl;
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
void BlueMen::defending(int attacker) {
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
         cout << endl << "Blue Men have been defeated!" << endl;
      }
   }
   else {
      // do nothing - the char defended against the attack
      cout << "Total Inflicted Damage: 0" << endl;
      cout << "Defender's Updated Strength: " << strength << endl;
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
void Medusa::defending(int attacker) {
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
         cout << endl << "Medusa has been defeated!" << endl;
      }
   }
   else {
      // do nothing - the char defended against the attack
      cout << "Total Inflicted Damage: 0" << endl;
      cout << "Defender's Updated Strength: " << strength << endl;
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
void HarryPotter::defending(int attacker) {
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
         cout << endl << "Harry Potter has been defeated!" << endl;
      }
   }
   else {
      // do nothing - the char defended against the attack
      cout << "Total Inflicted Damage: 0" << endl;
      cout << "Defender's Updated Strength: " << strength << endl;
   }
}

// returns the amount of strength (health)
int HarryPotter::getStrength() {
   return strength;
}
