#include <iostream>
#include <vector>

using std::vector;
using std::string;


class Scoreboard
{
	private:
		vector<string> m_teams = {};
		vector<string> m_events = {};
		vector<vector<int>> m_scores = {};

	public:
		vector<string> getTeams() const;
		vector<string> getEvents() const;
		Scoreboard(vector<string> &teams, vector<string> &events);
		int getTeamIndex(string team);
		int getEventIndex(string team);
		vector<int> getScores(const string &team) const;
		void addScore(string team, string event);
};

std::ostream& operator<<(std::ostream& out, const Scoreboard data);
