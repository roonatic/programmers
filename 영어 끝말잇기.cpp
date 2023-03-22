#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	vector<string> check;
	bool counter = true;
	int checkpoint = 0;

	for (int i = 0; i < words.size(); i++)
	{
		if (check.empty())
			check.push_back(words[i]);
		else
		{
			string now = words[i];
			string before = check.back();
			if (counter == false)
				break;
			else
			{
				if (now.substr(0, 1) == before.substr(before.length() - 1))
				{
					for (int j = 0; j < check.size(); j++)
					{
						if (check[j] == now)
						{
							counter = false;
							checkpoint = i;
							break;
						}
						else
						{
							if (j == check.size() - 1)
							{
								check.push_back(now);
								break;
							}
						}
					}
				}
				else
				{
					counter = false;
					checkpoint = i;
					break;
				}
			}
		}
	}

	if (counter == false)
	{
		int who = (checkpoint + 1) % n;
		int num = (checkpoint + 1) / n;
		if (who == 0)
			who = n;
		else
			num += 1;

		answer.push_back(who);
		answer.push_back(num);
	}
	else
	{
		answer.push_back(0);
		answer.push_back(0);
	}
	return answer;
}
