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

   // initialize linked list variables
   Queue* teams;
   Queue* losers;

   // loop until the user quits the program
   while(status == true) {
      // initialize all containers: (1) team #1, (2) team #2, & (3) losers
      teams = new Queue[2];
      losers = new Queue();

      introMenu(numFighters, status);

      if(status == false) {
         break;
      }

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

      // start the fight & handle the loser(s)
      Character* loser;
      int team1Score = 0;  // keeps track of team #1's (team[0]) score
      int team2Score = 0;  // keeps track of team #2's (team[1]) score

      // execute fights until one of the two teams has had all fighters
      // defeated (remaining fighters = 0)
      while(teams[0].isEmpty() == false && teams[1].isEmpty() == false) {
         loser = Fight(teams[0].getFront(), teams[1].getFront());

         // if teams[0] (team #1 within the game) fighter loses
         if(teams[0].getFront() == loser) {
            losers->addBack(loser);
            teams[0].removeFront();

            // shift the fight winner's team's lineup (if another fight will occur)
            if(teams[0].isEmpty() == false) {
               teams[1].shift();
            }
            team1Score -= 1;
            team2Score += 2;
         }

         // if teams[1] (team #2 within the game) fighter loses
         else if(teams[1].getFront() == loser){
            losers->addBack(loser);
            teams[1].removeFront();

            // shift the fight winner's team's lineup (if another fight will occur)
            if(teams[1].isEmpty() == false) {
               teams[0].shift();
            }
            team2Score -= 1;
            team1Score += 2;
         }
      }

//      cout << endl;

      if(teams[0].isEmpty() == true) {
         cout << "Team #2 Won!" << endl;
         cout << endl << "Tournament Scores:" << endl;
         cout << "   Team #1: " << team1Score << endl;
         cout << "   Team #2: " << team2Score << endl;
         cout << endl << "----------------------------------------" << endl;
      }
      else if(teams[1].isEmpty() == true) {
         cout << "Team #1 Won!" << endl;
         cout << endl << "Tournament Scores:" << endl;
         cout << "   Team #1: " << team1Score << endl;
         cout << "   Team #2: " << team2Score << endl;
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

      while(teams[0].isEmpty() == false) {
         teams[0].clearFront();
      }

      while(teams[1].isEmpty() == false) {
         teams[1].clearFront();
      }

      while(losers->isEmpty() == false) {
         losers->clearFront();
      }

      // free memory
//      delete player1;
//      delete player2;
      delete[] teams;
      delete losers;
   }
   return 0;
}
