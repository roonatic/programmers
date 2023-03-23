#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	string answer = "Yes";

	for (int i = 0; i < goal.size(); i++)
	{
		if (goal[i] == cards1.front())
		{
			cards1.erase(cards1.begin());
		}
		else if (goal[i] == cards2.front())
		{
			cards2.erase(cards2.begin());
		}
		else
			answer = "No";
	}
	return answer;
}


/*
2개의 큐라고 생각하고 앞에서 하나씩 pop한다.
2개의 큐에서 빠진적이 없으면 No 출력
*/