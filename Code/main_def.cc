#include <iostream>
#include <string>
#include "fileOfFuncs.hh"
#include "BinTree.hh"
using namespace std;

typedef BinTree<pair<string,int> > BT; 

int main() {
	/*
	 * 1. We are going to store all our tasks in a Binary Tree, 
	 * so we have to initialize it
	 */
	 BT tasks = initialize_tasks();
	 
	 /*
	  * 2. Ask the questions for knowing which task wants the user
	  * 
	  * For making this posible, the binary tree structure separes into diferent 
	  * zones (left and right) a standart name of concepts. The way they're separe is 
	  * into questions
	  * 
	  */
	 int middle_time = ask_questions(tasks);
	 
	 /*
	  * 3. Now that we know the base time, we're going to do it more exactly
	  * 
	  */
	  //modify_time(middle_time);
	  
	  /*
	   * 4. Print the result and finish the program
	   */
	   cout << middle_time << endl;
	   return 0;
}
