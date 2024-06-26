#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Pre: line is not empty and has exactly 2 different types of information
// Post: A vector which elements are the first part (string one) of line
vector<string> split(const string& line) {
	vector<string> tokens;
	string token;
	
	istringstream tokenStream(line);	
	while(tokenStream >> token) {		
		tokens.push_back(token);		
	}
	return tokens;				
}

// Pre: s is not empty
// Post: returns s converted to an int
int convert_string_to_int(const string& s) {
	int result;
	istringstream(s) >> result;
	return result;
}


int main() {
	/*
	 * 1. We have to use the input file list for the program 
	 * 	 and prove that it's open
	 */
	ifstream inputFile("input_file_name");
	
	if (!file.is_open()) { 
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }
    
    /* 
     * 2. Divide the content of the file and save it in a container
     * 
     * The idea is to have two containers: one with tasks and another one with
     * times. They are going to have the same indexes. They key for identifying them
     * are that in the tasks' container the first element of each one would be the 
     * key term (starting with '#') and in the times' container the first element
     * would be -1, as it cannot be a negative time of tasks
     * 
     * We would also convert the strings to the correct format (see else part)
     */
    vector<vector<string>> lines;
    vector<vector<int>> times;
    string s;
    int index = 0;
    while (getline(inputFile, s)) {
		if (s[0] == '#') {
			// Updating the lines container
			vector<string> aux1(1);
			aux1[0] = s;
			lines.push_back[aux1];
			// Updating the times container
			vector<int> aux2(1);
			aux2[0] = -1;
			times.push_back[aux2]
			// Updating the index, as it would be a new sub-container
			++index
		}
        else {
			vector<string> actualLine = split(s);
			int num = convert_string_to_int(actualLine[1]);
			lines[index].push_back(actualLine[0]);
			times[index].push_back(num);
		}
    }
    
    /*
     * 3. Now it's time for the user to choose between the tasks
     */
    while ()
    cout << "Choose between the tasks to find yours: ";
    show_actual_options();
    int n;
    cin >> n;
    
    /*
     * 4. Questions adapted to the list of task that the user had chosen
     * 
     * 	This consists in questions of yes/no that depending on the answer, 
     * 	different funcs will be executed
     */
    
    
    
    /*
     * 5. It prints the output of the program
     */
     print_middle_time(double middTime);
}
