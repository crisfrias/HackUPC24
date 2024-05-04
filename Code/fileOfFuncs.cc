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
	BT take_care_plants = BT(make_pair("SEMILEAF", 300), hang_laundry, BT());
	BT make_bed = BT(make_pair("LEAF", 180));
	BT change_sheets = BT(make_pair("LEAF", 1200));
	BT have_breakfast = BT(make_pair("LEAF", 600));
	BT read_news = BT(make_pair("This task is something you do like a hobby?", 300), read, study);
	BT go_someplace = BT(make_pair("LEAF", 1200));
	BT planning_future = BT(make_pair("LEAF", 600));
	BT paint = BT(make_pair("LEAF", 4200));
	BT write = BT(make_pair("SEMILEAF", 2700), toDo_list, BT());
	BT go_school = BT(make_pair("LEAF", 1200));
	BT go_walking = BT(make_pair("This task is something you have in routine?", 2400), do_sports, go_shopping);
	BT take_shower = BT(make_pair("LEAF", 480));
	BT write_diary = BT(make_pair("LEAF", 600));
	BT answer_emails = BT(make_pair("LEAF", 900));
	BT meeting = BT(make_pair("LEAF", 1800));
	BT daily_clean = BT(make_pair("Do you do this task inside your house?", 1200), make_bed, take_care_plants);
	BT deep_clean = BT(make_pair("SEMILEAF", 14488), change_sheets, BT());
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
	BT non_house_staff = BT(make_pair("Are only you the only person involved?", 0), get_ready, do_a_call);
	BT house_stuff = BT(make_pair("The task has something related with food?", 1500), cook, clean);
	BT out_of_the_house = BT(make_pair("Is a task that changes constanty or something that involves movement?", 0), dynamic, sstatic);
	BT in_the_house = BT(make_pair("The task is related with taking care of the house?", 0), house_stuff, non_house_staff);
	BT root = BT(make_pair("Is something that is entirely or starts and ends in your house?", 0), in_the_house, out_of_the_house);
	
	return root;
}

int ask_questions(BT t){
	int time;
	// BASE CASE
	if (t.value().first == "LEAF") {
		time = t.value().second;
	}
	else if (t.value().first == "SEMILEAF") {
		time = t.left().value().second;
	}
	else {
		// GENERAL CASE
		cout << t.value().first << "(y/n) ";
		char answer;
		cin >> answer;
		if (answer == 'y' and not t.left().empty()) {
			time = ask_questions(t.left());
		}
		else if (answer == 'n' and not t.right().empty()) {
			time = ask_questions(t.right());
		}
	}
	return time;
}

void modify_middle_time(int& time) {
	char s;
	// First question
	cout << "    # Have you done this type of task before?(y/n) ";
	cin >> s;
	if (s == 'y' and time > 60) time = time - time/4;
	else if (s == 'n')time += 60;
	cout << endl;
	// Second question
	cout << "   ## Are you specialized in this tasks?(y/n) ";
	cin >> s;
	if (s == 'y' and time > 60) time = time - 60;
	else if (s == 'n') time += 120;
	cout << endl;
	// Third question
	cout << "  ### Do you want to do it slowly?(y/n) ";
	cin >> s;
	if (s == 'y') time = time + 300;
	cout << endl;
	// Forth question
	cout << " #### Are you motivated to do this task?(y/n) ";
	cin >> s;
	if (s == 'y' and time > 60) time = time - 120;
	else if (s == 'n') time = time + 250;
	cout << endl;
	// Fift question
	cout << "##### Is this task difficult for you?(y/n) ";
	cin >> s;
	if (s == 'y') time = time + time/3;
	else if (s == 'n') time = time - 150;
	cout << endl;
}

void print_time_correctly(int sec) {
	if (sec < 60) return;
	int min;
	if (sec >= 60 and sec < 3600) {
		min = sec/60;
		sec = sec%60;
		cout << "It will take you " << min << " minutes and " << sec << " seconds for you to do your task" << endl;
	}
	else {
		int hour = sec/3600;
		int sec = sec%3600;
		if (sec >= 60) {
			min = sec/60;
			sec = sec%60;
		}
		cout << "It will take you " << hour << "hours, " << min << " minutes and " << sec << " seconds for you to do your task" << endl;
	}
}
