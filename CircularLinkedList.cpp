/*********************************************************************
** Program name: Circular Linked List 
** Author: Ryan DiRezze
** Date: November 11, 2018
** Description: Implements various functions within the QueueNode
   struct and Queue class required to implement a program that
   uses circular linked lists
*********************************************************************/

#include "CircularLinkedList.hpp"

// initializes a new list with a specific value for the first node
Queue::Queue(Character* x) {
   head = new QueueNode();
   head->val = x;
}

// Queue class destructor
Queue::~Queue() {

   if(head == nullptr) {
      // do nothing
   }
   
   // free memory of all nodes within the linked list
   else {
      QueueNode* node = head->next;
      QueueNode* nodeDelete = head;
      
      // iterate through the list
      while(node != nullptr && node != head) {
         delete nodeDelete;
         nodeDelete = node;
         node = node->next;
      }
      
      delete nodeDelete;
   }
}

// indicates whether the list is empty or not
bool Queue::isEmpty() {
   if(head == nullptr) {
      return true;
   }
   else {
      return false;
   }
}

// adds a new node to the back of the list
void Queue::addBack(Character* value) {
   if(head == nullptr) {
      head = new QueueNode();
      head->val = value;
   }

   else {
      QueueNode* node = head;

      // finds the last node in the list
      while(node->next != nullptr && node->next != head) {
         node = node->next;
      }

      node->next = new QueueNode();
      node->next->val = value;
      node->next->prev = node;
      node = node->next;
      node->next = head;
      head->prev = node;
   }
}

// returns a pointer to the character
Character* Queue::getFront() {
   if(isEmpty() == true) {
      cout << "List is empty..." << endl;
      return head->val;    // added
   }
   else {
      return head->val;
   }
}

// removes the front node/character from the linked list
void Queue::removeFront() {
   
   if(isEmpty() == true) {
      cout << "List is empty..." << endl;
   }

   else {
      
      if(head->next == nullptr && head->prev == nullptr) {
         delete head;
         head = nullptr;
//         cout << "List is now empty..." << endl;
      }

      else {
         QueueNode* node = head->next;

         while(node->next != nullptr && node->next != head) {
            node = node->next;
         }

         QueueNode* temp = head;
         head = head->next;
         delete temp;
         
         head->prev = node;
         node->next = head;

         if(head->val == head->next->val && head->val == head->prev->val) {
            head->next = nullptr;
            head->prev = nullptr;
         }
      }
   }
}

// prints all character names in the linked list
void Queue::printQueue() {
   if(head == nullptr) {
//      cout << "No more available fighters..." << endl;
   }

   else {
      cout << "Fighters: ";
      QueueNode* node = head;
      cout << node->val->getName() << " ";
      node = node->next;
      while(node != nullptr && node != head) {
         cout << node->val->getName() << " ";
         node = node->next;
      }
   }
}

// reverse print queue
void Queue::reversePrint() {
   if(head == nullptr) {
   }

   else {
      cout << "Fighers: ";
      QueueNode* node = head->prev;
      cout << node->val->getName() << " ";
      node = node->prev;
      while(node != nullptr && node != head->prev) {
         cout << node->val->getName() << " ";
         node = node->prev;
      }
   }
}

// returns the character at a particular position in the list
Character* Queue::getCharacter(int x) {
   
   // list is empty
   if(head == nullptr) {
      cout << "There aren't any characters on this team..." << endl;
      return head->val;    // added
   }

   QueueNode* node = head;
   int counter = 0;

   // list is NOT empty
   while(node != nullptr) {
      if(counter == x) {
         return node->val;
      }
      node = node->next;
      counter++;
   }
   return node->val;    // added
   cout << "Uh oh! There are only " << x+1 << " players on the team, beginning at position 0..." << endl;
}

void Queue::shiftLineup() {
   QueueNode* temp = head;
   QueueNode* node = head;

   while(node->next != head) {
      node = node->next;
   }

   node->next = head->next;
   head->next->prev = node;

   head->next = nullptr;
   head->prev = nullptr;

   head = node->next;
}
   
