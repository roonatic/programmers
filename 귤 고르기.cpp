#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
	int cnt[10000001] = { 0, };
	int answer = 0;
	int total = 0;

	for (int i = 0; i < tangerine.size(); i++)
	{
		int t = tangerine[i];   // ±Ö »çÀÌÁî

		cnt[t]++;
	}

	sort(cnt, cnt + 10000001, greater<int>());

	int tmpt = 0;
	for (int i = 0; i < 10000001; i++)
	{
		if (k > total)
		{
			total += cnt[i];
			tmpt = cnt[i];
			answer++;
		}
		else if (k = total)
			break;
		else if (k < total)
		{
			answer--;
			total -= tmpt;
		}
	}
	return answer;
}