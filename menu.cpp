/*********************************************************************
** Program name: Fantasy Combat Game 
** Author: Ryan DiRezze
** Date: November 4, 2018
** Description: 
*********************************************************************/

#include "menu.hpp"
#include "inputValidation.hpp"

// the main/primary menu that issues arrive at after starting the program;
// this menu allows the user to navigate to various areas of the program
// to perform different transactions and view different data.
void fantasyGameMenu(char& option1, char& option2) {
   // introduction
   string program_name = "Fantasy Combat Game";
   cout << "Hello! Welcome to the " << program_name << "!" << endl << endl;

   while((tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f') || (tolower(option2) != 'a' && tolower(option2) != 'b' && tolower(option2) != 'c' && tolower(option2) != 'd' && tolower(option2) != 'e' && tolower(option2) != 'f')) {
      // menu prompt
      cout << "Please select two characters that will fight each other from the following choices:" << endl;
      cout << "Input the option's corresponding letter to make a selection..." << endl << endl;
      
      // menu choices
      cout << "    a. Vampire" << endl;
      cout << "    b. Barbarian" << endl;
      cout << "    c. Blue Men" << endl;
      cout << "    d. Medusa" << endl;
      cout << "    e. Harry Potter" << endl;
      cout << "    f. Exit the program" << endl << endl;

      cout << "Character #1: ";
      cin >> option1;
      charValidation(option1);   // verify that a character was entered

      // input validation to only allow valid menu option choices by the user (for Player #1)
      if(tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f') {
         while(tolower(option1) != 'a' && tolower(option1) != 'b' && tolower(option1) != 'c' && tolower(option1) != 'd' && tolower(option1) != 'e' && tolower(option1) != 'f') {
            cout << "Uh oh! It looks like you didn't input a valid menu option... Please try again." << endl << endl;
            cout << "Character #1: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
            cin >> option1;
            cout << endl;
         }
      }
      if(tolower(option1) == 'f') {
         break;
      }

      cout << "Character #2: ";
      cin >> option2;
      charValidation(option2);

      // input validation to only allow valid menu option choices by the user (for Player #2)
      if(tolower(option2) != 'a' && tolower(option2) != 'b' && tolower(option2) != 'c' && tolower(option2) != 'd' && tolower(option2) != 'e' && tolower(option2) != 'f') {
         while(tolower(option2) != 'a' && tolower(option2) != 'b' && tolower(option2) != 'c' && tolower(option2) != 'd' && tolower(option2) != 'e' && tolower(option2) != 'f') {
            cout << "Uh oh! It looks like you didn't input a valid menu option... Please try again." << endl << endl;
            cout << "Character #2: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
            cin >> option2;
            cout << endl;
         }
      }
      if(tolower(option2) == 'f') {
         break;
      }

      cout << endl;

   }
}

// a small prompt that asks the user if he/she would like to return to the main
// menu; this was intended to appear after the user performs some transaction
void mainMenuReturn(char& option) {
   option = 'n';
   while(tolower(option) == 'n') {
      cout << "Do you want to return to the main menu? (Y/N): ";
      cin >> option;
      validYesNo(option);

      if(tolower(option) == 'y') {
         option = 'z';       // let the program escape the 'while loop' & return to the menu
      }
      
      else if(tolower(option) == 'n') {
         cout << "Do you want to exit the program? (Y/N): ";
         cin >> option;
         validYesNo(option);
         
         // escape the 'while loop' & quit the program
         if(tolower(option) == 'y') {
            option = 'f';
            cout << endl;     // add a line & space for aesthetics
         }
         
         // do nothing and let the program run back through the 'while loop'
         else if(tolower(option) == 'n') {
            //option = 'n'
         }
      }
   }
}
