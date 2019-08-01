#include "scoreboard.h"
#include "iostream"
#include <vector>

using std::endl;

Scoreboard::Scoreboard(vector<string> &teams, vector<string> &events) {
	for (int i = 0; i < teams.size(); i++) {

		m_teams.push_back(teams[i]);

	}
	for (int i = 0; i < events.size(); i++) {

		m_events.push_back(events[i]);

	}
	vector<int> temp = {};
	for (int j = 0; j < events.size(); j++) {
		temp.push_back(0);
	}
	for (int i = 0; i < teams.size(); i++) {
		m_scores.push_back(temp);
	}
}

vector<string> Scoreboard::getTeams() const {
	return m_teams;
}

vector<string> Scoreboard::getEvents() const {
	return m_events;
}

vector<int> Scoreboard::getScores(const string &team) const {
	for (int i = 0; i < m_teams.size(); i++) {
		if (m_teams[i] == team) {
			return m_scores[i];
		}
	}
	return {};
}

std::ostream& operator<<(std::ostream &out, const Scoreboard data) {
	out << "\t";
	for (string var : data.getEvents())
	{
		out << var << "       ";
	}
	out << endl;
	for (string var : data.getTeams())
	{
		vector<int> scoreList = data.getScores(var);
		out << var << "    ";
		for (int i = 0; i < scoreList.size(); i++) {
			out << scoreList[i] << "               ";
		}
		out << "\n\n\n";
	}
	return out;
}

int Scoreboard::getTeamIndex(string team) {
	for (int i = 0; i < m_teams.size(); i++) {
		if (m_teams[i] == team) {
			return i;
		}
	}
}

int Scoreboard::getEventIndex(string event) {
	for (int i = 0; i < m_events.size(); i++) {
		if (m_events[i] == event) {
			return i;
		}
	}
}

void Scoreboard::addScore(string team,string event) {
	int team_index = getTeamIndex(team);
	int event_index = getEventIndex(event);
	m_scores[team_index][event_index]++;
}

