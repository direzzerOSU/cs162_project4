/*********************************************************************
** Program name: Fantasy Combat Game 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"
#include "fantasyGame.hpp"
#include "CircularLinkedList.hpp"

Character* Fight(Character*, Character*);

int main() {
   cout << endl;
   srand(time(0));
   // initialize the variable for determining which function will be 'called'
   int selection1, selection2;

   int numFighters = 9;
   bool status = true;

   while(status == true) {
      introMenu(numFighters, status);

      if(status == false) {
         break;
      }
      
      // initialize all containers: (1) team #1, (2) team #2, & (3) losers
      //Queue* team1, team2, losers;
      Queue* teams = new Queue[2];
//      Queue* team1 = new Queue();
//      Queue* team2 = new Queue();
      Queue* losers = new Queue();

      // only break the loop if the user opts to exit the program
      for(int n=0; n<numFighters; n++) {
         cout << endl;
         // reset the value after each iteration through the loop
         selection1 = 9;
         selection2 = 9;

         cout << "Select a player for team #1!" << endl << endl;

         // start the menu
         GameMenu(selection1);

         Character* player1;
         Character* player2;

         // initialize character #1 for combat      
         if(selection1 == 1) {
            player1 = new Vampire();
         }
         else if(selection1 == 2) {
            player1 = new Barbarian();
         }
         else if(selection1 == 3) {
            player1 = new BlueMen();
         }
         else if(selection1 == 4) {
            player1 = new Medusa();
         }
         else if(selection1 == 5) {
            player1 = new HarryPotter();
         }
         // exit the program
         else if(selection1 == 6) {
            // do nothing and let the program terminate
            break;
         }

         // get player1's name
         cout << endl << "What would you like to call this character (#1)? " << endl;
         cout << "   Name: ";
         std::string name1;
         cin.ignore();
         getline(cin, name1);
         player1->setName(name1);   

         cout << endl << endl << "Select a player for team #2!" << endl;

         cout << endl;
         GameMenu(selection2);      

         // initialize character #2 for combat
         if(selection2 == 1) {
            player2 = new Vampire();
         }
         else if(selection2 == 2) {
            player2 = new Barbarian();
         }
         else if(selection2 == 3) {
            player2 = new BlueMen();
         }
         else if(selection2 == 4) {
            player2 = new Medusa();
         }
         else if(selection2 == 5) {
            player2 = new HarryPotter();
         }
         // exit the program
         else if(selection2 == 6) {
            // do nothing and let the program terminate
            break;
         }

         // get player2's name
         cout << endl << "What would you like to call this character (#2)? " << endl;
         cout << "   Name: ";
         std::string name2;
         cin.ignore();
         getline(cin, name2);
         player2->setName(name2);
         
         // add players to each team
         teams[0].addBack(player1);
         teams[1].addBack(player2);

         cout << endl;

      }

      // verify the circularLinkedList is working as intended
      for(int n=0; n<2; n++) {
         cout << "Team #" << n+1 << ":" << endl;
         for(int k=0; k<numFighters; k++) {
            cout << "   Player #" << k+1 << ": " << teams[n].getCharacter(k)->getName() << endl;
         }
      }
      
      cout << endl << "----------------------------------------" << endl << endl;

      // start the fight
      Character* loser;
      while(teams[0].isEmpty() == false && teams[1].isEmpty() == false) {
         loser = Fight(teams[0].getFront(), teams[1].getFront());
         if(teams[0].getFront() == loser) {
            losers->addBack(loser);
            teams[0].removeFront();
//            teams[1].shiftLineup();
         }
         else if(teams[1].getFront() == loser){
            losers->addBack(loser);
            teams[1].removeFront();
//            teams[0].shiftLineup();
         } 
      }

//      cout << endl;

      if(teams[0].isEmpty() == true) {
         cout << "Team #2 Won!" << endl;
         cout << endl << "----------------------------------------" << endl;
      }
      else if(teams[1].isEmpty() == true) {
         cout << "Team #1 Won!" << endl;
         cout << endl << "----------------------------------------" << endl;
      }
      else {
         cout << "Uh oh... There's an issue with finding the winning team..." << endl;
      }

      int choice = 9;

      while(choice != 1 && choice != 2) {
         cout << endl << "Would you like to display the loser pile?" << endl;
         cout << "   1. Yes" << endl;
         cout << "   2. No" << endl;
         cout << endl << "Selection: ";
         cin >> choice;
         intValidation(choice);
      }
      cout << endl;

      // print the loser pile
      if(choice == 1) {
         losers->reversePrint();
      }

      cout << endl << endl;
      mainMenuReturn(status);
      
      cout << endl;

      // free memory
//      delete player1;
//      delete player2;
   }

   return 0;
}

//// takes two characters (fighters) as function parameters and executes rounds
//// of combat until one of the two characters (fighters) dies (i.e., strength <= 0)
//Character* Fight(Character* player1, Character* player2) {
//   int attack = 0;
//   int counter = 1;
//   int damage1 = 0;
//   int damage2 = 0;
//
//   // start the fight
//   while(player1->getStrength() > 0 && player2->getStrength() > 0) {
//      cout << "Round #" << counter << " (Player #1: " << player1->getName() << " Attack): " << endl;
//      attack = 0;
//      attack = player1->attacking();
//      damage2 += player2->defending(attack);
//
//      if(player2->getStrength() > 0) {
//         cout << endl << "Round #" << counter << " (Player #2: " << player2->getName() << " Attack): " << endl;
//         attack = 0;
//         attack = player2->attacking();
//         damage1 = player1->defending(attack);
//      }
//
//      counter += 1;
//
//      cout << endl;
//      cout << "----------------------------------------" << endl << endl;
//   }
//
//   if(player1->getStrength() <= 0 && player2->getStrength() > 0) {
//      cout << "Congratulations! " << "Player #2: " << player2->getName() << " Won!" << endl;
//      cout << endl << "----------------------------------------" << endl << endl;
//      player2->restoreStrength(damage2);
//      return player1;
//   }
////   else(player1->getStrength() > 0 && player2->getStrength() <= 0) {
//   else {
//      cout << "Congratulations! " << "Player #1: " << player1->getName() << " Won!" << endl;
//      cout << "----------------------------------------" << endl << endl;
//      player1->restoreStrength(damage1);
//      return player2;
//   }
////   else {
////      cout << "Whoops! Looks like there's a bug with finding the winner of the fight..." << endl;
////   }
//}
