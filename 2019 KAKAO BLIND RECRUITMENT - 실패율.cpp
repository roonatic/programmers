#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<float, int> a, pair<float, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<pair<float, int>> sol;

	int num = N; //연살을 시행하는 횟수
	int now = 1; //현재 스테이지
	int person = stages.size(); //스테이지에 도전하는 사람 수

	while (num--)
	{
		int fail = 0; //실패한 사람의 수
		for (int i = 0; i < stages.size(); i++)
		{
			if (stages[i] == now)
				fail++;
		}

		float failure = fail / (float)person; //실패율

		if (person > 0)
			sol.push_back(make_pair(failure, now));
		else
			sol.push_back(make_pair(0, now));

		now++; //다음 스테이지로 넘어감
		person -= fail; //탈락하고 남은 사람의 수
	}

	sort(sol.begin(), sol.end(), compare);

	for (int i = 0; i < sol.size(); i++)
		answer.push_back(sol[i].second);

	return answer;
}
