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
2���� ť��� �����ϰ� �տ��� �ϳ��� pop�Ѵ�.
2���� ť���� �������� ������ No ���
*/