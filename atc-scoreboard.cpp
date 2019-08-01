#include "scoreboard.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
	vector<string> teams = {"Pink", "Blue", "Purple", "Turquoise", "Red", "Black", "White" };
	vector<string> events = { "KanJam", "Cornhole", "Spikeball", "Yardpong", "Water Balloon Toss", "Bucket Race"};
	Scoreboard scoreboard_atc = Scoreboard(teams, events);
	cout << scoreboard_atc << endl;
	
	string input = "";
	while (input != "quit") {
		cout << "What team are you on? ";
		string team;
		cin >> team;
		cout << "\n";
		cout << "What event did you win? ";
		string event;
		cin >> event;
		cout << "\n";
		scoreboard_atc.addScore(team, event);
		cout << scoreboard_atc;
	}
}


