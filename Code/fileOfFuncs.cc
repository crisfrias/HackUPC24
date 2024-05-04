#include "fileOfFuncs.hh"

typedef BinTree<pair<string,int> > BT;

// The time units are seconds
BT initialize_tasks() {
	BT hang_laundry = BT(make_pair("LEAF", 600));
	BT read = BT(make_pair("LEAF", 1800));
	BT study = BT(make_pair("LEAF", 8400));
	BT toDo_list = BT(make_pair("LEAF", 600));
	BT go_shopping = BT(make_pair("LEAF", 4200));
	BT do_sports = BT(make_pair("LEAF", 5400));
	BT take_care_plants = BT(make_pair("LEAF", 300), hang_laundry, BT());
	BT make_bed = BT(make_pair("LEAF", 180));
	BT change_sheets = BT(make_pair("LEAF", 1200));
	BT have_breakfast = BT(make_pair("LEAF", 600));
	BT read_news = BT(make_pair("This task is something you do like a hobby?", 300), read, study);
	BT go_someplace = BT(make_pair("LEAF", 1200));
	BT planning_future = BT(make_pair("LEAF", 600));
	BT paint = BT(make_pair("LEAF", 4200));
	BT write = BT(make_pair("LEAF", 2700), toDo_list, BT());
	BT go_school = BT(make_pair("LEAF", 1200));
	BT go_walking = BT(make_pair("This task is something you have in routine?", 2400), do_sports, go_shopping);
	BT take_shower = BT(make_pair("LEAF", 480));
	BT write_diary = BT(make_pair("LEAF", 600));
	BT answer_emails = BT(make_pair("LEAF", 900));
	BT meeting = BT(make_pair("LEAF", 1800));
	BT daily_clean = BT(make_pair("Do you do this task inside your house?", 1200), make_bed, take_care_plants);
	BT deep_clean = BT(make_pair("LEAF", 14488), change_sheets, BT());
	BT take_snack = BT(make_pair("LEAF", 1200));
	BT eat = BT(make_pair("This task involves eating?", 120), have_breakfast, read_news);
	BT play_with_friends = BT(make_pair("It's a task that are you going to be proud in the future?", 240), planning_future, go_someplace);
	BT admin_papers = BT(make_pair("LEAF", 7200));
	BT homework = BT(make_pair("Is your task related with doing some graphical stuff?", 5400), paint, write);
	BT go_somewhere = BT(make_pair("Is mandatory for you to do this?", 1200), go_school, go_walking);
	BT get_ready = BT(make_pair("Do you have to take your clothes out for doing this task?",900), take_shower, write_diary);
	BT do_a_call = BT(make_pair("Is presencial?", 1200), meeting, answer_emails);
	BT clean = BT(make_pair("It's a daily task?", 1200), daily_clean, deep_clean);
	BT cook = BT(make_pair("It's a necessity for living?", 0), eat, take_snack);
	BT sstatic = BT(make_pair("Is a formal task?", 0), admin_papers, play_with_friends);
	BT dynamic = BT(make_pair("Is a physical movement?", 1200), go_somewhere, homework);
	BT non_house_staff = BT(make_pair("Are only you involved or maybe can be another person?", 0), get_ready, do_a_call);
	BT house_stuff = BT(make_pair("The task has something related with food?", 1500), cook, clean);
	BT out_of_the_house = BT(make_pair("Is a task that changes constanty or something that involves movement?", 0), dynamic, sstatic);
	BT in_the_house = BT(make_pair("The task is related with taking care of the house?", 0), house_stuff, non_house_staff);
	BT root = BT(make_pair("Is something that is entirely or starts and ends in your house?", 0), in_the_house, out_of_the_house);
	
	return root;
}

int ask_questions(BT t){
	// BASE CASE
	if (t.empty()) return -1; 
	
	// GENERAL CASE
	// if it's a leaf, returns its time value
	int time;
	if(t.value().first == "LEAF" and t.left().empty()) {
		time = t.value().second;
	}
	else if (t.value().first == "LEAF" and not t.left().empty()) {
		time = ask_questions(t.left());
	}
	else {
		cout << t.value().first << "(y/n) ";
		char answer;
		cin >> answer;
		if (answer == 'y') {
			ask_questions(t.left());
		}
		else if (answer == 'n') {
			ask_questions(t.right());
		}
		else {
			cout << "Error, try again" << endl;
		}
	}
	return time;
}
