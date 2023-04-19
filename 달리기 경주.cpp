#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer;
	map<string, int> list;
	map<int, string> now;

	for (int i = 0; i < players.size(); i++)
	{
		list.insert(std::pair<string, int>(players[i], i+1));
		now.insert(std::pair<int, string>(i + 1, players[i]));
	}

	for (int i = 0; i < callings.size(); i++)
	{
		string tmpt = callings[i];
		string temp = now[list.at(tmpt) - 1];
		now[list.at(tmpt)] = temp;
		now[list.at(tmpt)-1] = tmpt;
		list[tmpt] = list.at(tmpt) - 1;
		list[temp] += 1;
	}

	for (int i = 1; i <= now.size(); i++)
		answer.push_back(now.at(i));

	return answer;
}

int main()
{
	vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
	vector<string> callings = { "kai", "kai", "mine", "mine" };
	solution(players, callings);
}