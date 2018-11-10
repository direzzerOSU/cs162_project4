/*********************************************************************
** Program name: Fantasy Combat Game 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"
#include "fantasyGame.hpp"

int main() {
   cout << endl;
   srand(time(0));
   // initialize the variable for determining which function will be 'called'
   char selection1, selection2;

   // only break the loop if the user opts to exit the program
   while(tolower(selection1) != 'f' && tolower(selection2) != 'f') {
      // reset the value after each iteration through the loop
      selection1 = 'z';
      selection2 = 'z';

      // start the menu of recursive functions
      fantasyGameMenu(selection1, selection2);
      cout << endl;

      Character* player1;
      Character* player2;

      // initialize character #1 for combat      
      if(tolower(selection1) == 'a') {
         player1 = new Vampire();
      }
      else if(tolower(selection1) == 'b') {
         player1 = new Barbarian();
      }
      else if(tolower(selection1) == 'c') {
         player1 = new BlueMen();
      }
      else if(tolower(selection1) == 'd') {
         player1 = new Medusa();
      }
      else if(tolower(selection1) == 'e') {
         player1 = new HarryPotter();
      }
      // exit the program
      else if(tolower(selection1) == 'f') {
         // do nothing and let the program terminate
         break;
      }

      // initialize character #2 for combat
      if(tolower(selection2) == 'a') {
         player2 = new Vampire();
      }
      else if(tolower(selection2) == 'b') {
         player2 = new Barbarian();
      }
      else if(tolower(selection2) == 'c') {
         player2 = new BlueMen();
      }
      else if(tolower(selection2) == 'd') {
         player2 = new Medusa();
      }
      else if(tolower(selection2) == 'e') {
         player2 = new HarryPotter();
      }
      // exit the program
      else if(tolower(selection2) == 'f') {
         // do nothing and let the program terminate
         break;
      }

      int attack = 0;
      int counter = 1;

      // start the fight
      while(player1->getStrength() > 0 && player2->getStrength() > 0) {
         cout << "Round #" << counter << " (Player #1: " << player1->getType() << " Attack): " << endl;
         attack = 0;
         attack = player1->attacking();
         player2->defending(attack);

         cout << endl << "Round #" << counter << " (Player #2: " << player2->getType() << " Attack): " << endl;
         attack = 0;
         attack = player2->attacking();
         player1->defending(attack);

         counter += 1;

         cout << endl;
         cout << "----------------------------------------" << endl << endl;
      }

      if(player1->getStrength() <= 0 && player2->getStrength() > 0) {
         cout << "Congratulations! " << "Player #2: " << player2->getType() << " Won!" << endl;
      }
      else if(player1->getStrength() > 0 && player2->getStrength() <= 0) {
         cout << "Congratulations! " << "Player #1: " << player1->getType() << " Won!" << endl;
      }
      else {
         cout << "Whoops! Looks like there's a bug with finding the winner of the fight..." << endl;
      }

      cout << endl << "Would you like to play again? (Y/N): ";
      cin >> selection1;
      charValidation(selection1);

      while(tolower(selection1) != 'y' && tolower(selection1) != 'n') {
         cout << endl << "Sorry... It looks like you didn't enter a valid choice. \nPlease try again: ";
         cin.ignore();
         cin >> selection1;
         charValidation(selection1);
      }
      if(tolower(selection1) == 'y') {
         // do nothing
      }
      else if(tolower(selection1) == 'n') {
         selection1 = 'f';
      }
      cout << endl;

      // free memory
      delete player1;
      delete player2;
   }

   return 0;
}
