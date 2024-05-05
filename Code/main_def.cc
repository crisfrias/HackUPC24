#include <iostream>
#include <string>
#include "fileOfFuncs.hh"
#include "BinTree.hh"
using namespace std;

typedef BinTree<pair<string,int> > BT; 

int main() {
	 // ASCII Art
    cout << R"(


 /$$$$$$$$ /$$                        
|__  $$__/|__/                        
   | $$    /$$ /$$$$$$/$$$$   /$$$$$$ 
   | $$   | $$| $$_  $$_  $$ /$$__  $$
   | $$   | $$| $$ \ $$ \ $$| $$$$$$$$
   | $$   | $$| $$ | $$ | $$| $$_____/
   | $$   | $$| $$ | $$ | $$|  $$$$$$$
   |__/   |__/|__/ |__/ |__/ \_______/
                                      
                                      
                                      
 /$$$$$$$$                    /$$     
|__  $$__/                   | $$     
   | $$  /$$$$$$   /$$$$$$$ /$$$$$$   
   | $$ /$$__  $$ /$$_____/|_  $$_/   
   | $$| $$$$$$$$|  $$$$$$   | $$     
   | $$| $$_____/ \____  $$  | $$ /$$ 
   | $$|  $$$$$$$ /$$$$$$$/  |  $$$$/ 
   |__/ \_______/|_______/    \___/   



                                                     
)";
	cout << "Welcome to Time Test, the program that will help you for using better your time!" << endl;
	
	
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
	 cout << "Now you have to answer the next yes/no questions:" << endl << endl;
	 int middle_time = ask_questions(tasks);
	 cout << endl;
	 
	 /*
	  * 3. Now that we know the base time, we're going to do it more exactly
	  * 
	  */
	 cout << "These are the lasts questions left, be sincere ;)" << endl << endl;
	 modify_middle_time(middle_time);
	  
	  /*
	   * 4. Print the result and finish the program
	   */
	 print_time_correctly(middle_time);
	 return 0;
}
