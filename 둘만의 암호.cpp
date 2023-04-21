#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
	string answer = "";

	int n = 26;
	char start = 'a';
	vector<char> list;
	vector<char> no;

	for (int i = 0; i < skip.size(); i++)
		no.push_back(skip[i]);

	while (n--)
	{
		int cnt = 0;
		for (int i = 0; i < no.size(); i++)
		{
			if (no[i] == start)
			{
				cnt = 1;
				break;
			}
		}

		if (cnt == 0)
			list.push_back(start);

		start++;
	}

	for (int i = 0; i < s.size(); i++)
	{
		int idx = 0;
		for (int j = 0; j < list.size(); j++)
		{
			if (list[j] == s[i])
			{
				idx = j;
				break;
			}

		}

		if (idx + index > list.size() - 1)
			answer += list[(idx + index) % list.size()];
		else
			answer += list[idx + index];
	}
	return answer;
}
