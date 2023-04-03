#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;

	int zero_cnt = 0;   // 제거한 0의 개수
	int num = 0;    // 변환 횟수

	string tmpt = s;
	while (tmpt.size() != 1)
	{
		string temp = "";
		vector<int> binary;

		// 1. 모든 0 제거
		for (int i = 0; i < tmpt.size(); i++)
		{
			if (tmpt[i] == '1')
				temp += tmpt[i];
			else
				zero_cnt++;
		}
		tmpt = temp;

		// 2. 이진으로 변환
		int n = tmpt.size();    // 1을 제거한 문자열의 길이
		while (n != 1)
		{
			binary.push_back(n % 2);
			n /= 2;
		}
		binary.push_back(1);
		reverse(binary.begin(), binary.end());

		tmpt = "";

		for (int i = 0; i < binary.size(); i++)
			tmpt += to_string(binary[i]);

		num++;
	}

	answer.push_back(num);
	answer.push_back(zero_cnt);
	return answer;
}