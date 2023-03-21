#include <string>
#include <vector>

using namespace std;

/* 초기 답안 */
string solution(vector<int> food) {
	string answer = "";

	vector<int> cnt;
	for (int i = 1; i < food.size(); i++)
	{
		int tmpt = food[i];
		cnt.push_back(food[i] / 2);
	}

	for (int i = 0; i < cnt.size(); i++)
	{
		int p_cnt = cnt[i];
		while (p_cnt--)
			answer += to_string(i + 1);
	}
	answer += "0";

	for (int i = cnt.size(); i > 0; i--)
	{
		int p_cnt = cnt[i - 1];
		while (p_cnt--)
			answer += to_string(i);
	}
	return answer;
}

/* 개선 답안 */
// #include <algorithm> 필요
string solution(vector<int> food) {
	string answer = "";

	for (int i = 1; i < food.size(); i++)
	{
		int cnt = food[i] / 2;
		for (int j = 0; j < cnt; j++)
		{
			answer += to_string(i);
		}
	}

	string temp = answer;
	reverse(temp.begin(), temp.end());
	answer += "0";
	answer += temp;

	return answer;
}