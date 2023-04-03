#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;

	int zero_cnt = 0;   // ������ 0�� ����
	int num = 0;    // ��ȯ Ƚ��

	string tmpt = s;
	while (tmpt.size() != 1)
	{
		string temp = "";
		vector<int> binary;

		// 1. ��� 0 ����
		for (int i = 0; i < tmpt.size(); i++)
		{
			if (tmpt[i] == '1')
				temp += tmpt[i];
			else
				zero_cnt++;
		}
		tmpt = temp;

		// 2. �������� ��ȯ
		int n = tmpt.size();    // 1�� ������ ���ڿ��� ����
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