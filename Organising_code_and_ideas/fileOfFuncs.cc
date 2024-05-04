#include "fileOfFuncs.hh"

typedef BinTree<pair<string,double> > BT;

vector<string> split(const string& line) {
	vector<string> tokens;
	string token;
	
	istringstream tokenStream(line);	
	while(tokenStream >> token) {		
		tokens.push_back(token);		
	}
	return tokens;				
}

int convert_string_to_int(const string& s) {
	int result;
	istringstream(s) >> result;
	return result;
}

BT initialize_tasks() {
	
}
