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
	BT getting_ready() = (make_pair())
	BT do_a_call() = (make_pair("Is presencial?"), meeting(), answer_emails());
	BT clean() = (make_pair("It's a daily?"), deep_clean(), daily_clean());
	BT cook() = (make_pair("It's a necessity for living?"), eat(), take_snack());
	BT sstatic() = (make_pair("Is a formal task?"), admin_papers(), play_with_friends());
	BT dynamic() = (make_pair("Is a physical movement?", 1200), go_somewhere(), homework());
	BT non_house_staff() = (make_pair("Are only you involved or maybe can be another person?", 0), do_a_call(), get_ready());
	BT house_stuff() = (make_pair("The task has to be done in the kitchen?", 1500), cook(), clean());
	BT out_of_the_house() = (make_pair("Is a task that changes constanty or something that involves movement?", 0), dynamic(), sstatic());
	BT in_the_house() = (make_pair("The task has to take place everytime at house or it starts and ends in the house?", 0), house_stuff(), non_house_staff());
	BT root() = (make_pair("nothing", 0), in_the_house(), out_of_the_house());
}

void print_middle_time(double middTime) {
	
}
