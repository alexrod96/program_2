///////////////////////////////////////////////////////////////////////////////
//                   
// Title:            Program #2 - Priority Queue
// Files:            Assignment sheet
// Semester:         Data Structures Spring 2018
//
// Author:           Alexis Rodriguez
// Email:            Alexis_rodriguez13@aol.com
// Description:
//    This Program is to grab input from the input file and sort the input
// using a Queue that sorts the input depending on the word length and also 
// alphabetical order this is accomplished by creating functions that will 
// Push and pop the words onto a list and then the function bubbleListSort 
// sorts the word depending on the length.
/////////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int countLen(char *word) {
	int l = 0;
	while (*word) {
		*word++;
		l++;
	}
	return l;
}
/**
* Function node :
*   Struct to hold a word and pointer to next word
* 
* Params:
*      ponter and Node
* Returns
*      
*/
struct Node {
	string val;
	Node *next;
	Node() {
		val = " ";
		next = NULL;
	}
	Node(string v) {
		val = v;
		next = NULL;
	}
};

/**
* Class that represents a generic list with the following methods:
*     nodes pointing to Front and Rear
*/
class Queue {
private:
	Node *Front;
	Node *Rear;

public:
	/**
   * Queue
   * constructor
   *
   * params:
   *     - none
   */
	Queue() {
		Front = Rear = NULL;
	}
/**
* Function bubbleListSort :
*      sorts input according to size
* 
* Params:
*      list t1 t2 & boolean if false
* Returns
*      void
*/
void bubbleListSort(){
  
	
    Node* t1 = Front;
    Node* t2 = Front;
    
    string temp = "";
    
    bool swapped = false;
    
    while(t1){
      swapped = false;
      t2=t1->next;
      while(t2){
        if(t1->val.length() > t2->val.length()){
          swapped = true;
          temp = t1->val;
          t1->val = t2->val;
          t2->val = temp;
        }
       
        t2=t2->next;
      }
      t1 = t1->next;
    }
    if(!swapped){
      return;
    }
  }

/**
* Function pop :
*      sorts input according to size
* 
* Params:
*      Front & string v
* Returns
*      string
*/
	string pop() {
		if (!empty()) {
			Node *temp = Front;   // temp pointer so we can delete node
			string v = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;		  // give mem back to system
			return v;
		} else {
			cout << "error: cannot pop off empty queue." << endl;
			return " ";
		}
	}
/**
* Function push :
*      pushes value onto stack
* 
* Params:
*      Front & Rear & n
* Returns
*      void
*/
    void push(string v) {
		Node *n = new Node(v);

		// handle the empty case
		if (empty()) {
			Front = n;
			Rear = n;
		} else {
			// not empty add to rear
			Rear->next = n;
			Rear = n;
		}
		
	}
	/**
   * Queue
   * constructor
   *
   * params:
   *     - none
   */
	bool empty() {
		return (Front == NULL && Rear == NULL);
	}

 /**
* Function pop :
*      pops value after being pushed
* 
* Params:
*      Front & Rear & v
* Returns
*      bool
*/
	bool pop(string &v) {
		if (!empty()) {
			Node *temp = Front;   // temp pointer so we can delete node
			string t = temp->val; // grab value out of node
			Front = Front->next;  // move pointer to next node
			delete temp;		  // give mem back to system
			v = t;
			return true;
		} else {
			cout << "error: cannot pop off empty queue." << endl;
			return false;
		}
	}
};

int main() {
	
	
	Queue Q;
	string word;
 
	ofstream outfile;
	outfile.open("priority_out.txt");
  ifstream fin;
	fin.open("input_data.txt");


 while(!fin.eof())
 {
   
   fin >> word;
   if(word != "pop"&& word!="push")
   {
    Q.push(word);
   }
  
 }
  
  Q.bubbleListSort();
  
 
while (Q.pop(word)) {
		outfile << word << endl;
		
	}
	
	fin.close();
	outfile.close();
}
