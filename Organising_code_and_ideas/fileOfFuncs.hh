#include <vector>
#include <string>
#include <sstream>
#include "BinTree.hh"
using namespace std;

// Pre: line is not empty and has exactly 2 different types of information
// Post: A vector which elements are the first part (string one) of line
vector<string> split(const string& line);

// Pre: s is not empty
// Post: returns s converted to an int
int convert_string_to_int(const string& s);

// Pre: true
// Post: returns a Binary Tree with a defined and organized number of tasks
BT initialize_tasks();
