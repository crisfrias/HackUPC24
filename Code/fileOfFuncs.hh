#include <vector>
#include <string>
#include <sstream>
#include "BinTree.hh"
using namespace std;

typedef BinTree<pair<string,int> > BT; 

// Pre: true
// Post: returns a Binary Tree with a defined and organized number of tasks
BT initialize_tasks();

// Pre: t is not empty
// Post: returns the middle time most aproximated
int ask_questions(BT t);
