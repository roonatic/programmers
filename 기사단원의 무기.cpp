#include <string>
#include <vector>

using namespace std;

// ��� ���� ���ϱ�
int divisor(int n)
{
	int cnt = 0;	// ��� ����

	// N�� ��� ����,  1���� N�� ������ ������ ���� 0���� ������ ���������� Ȯ��
	for (int i = 1; i * i <= n; i++)	
	{
		if (n % i == 0)
		{
			cnt++;
			if (i * i < n)
				cnt++;
		}
	}

	return cnt;
}
int solution(int number, int limit, int power) {
	int answer = 0;

	for (int i = 1; i <= number; i++)
	{
		int num = divisor(i);
		if (num > limit)
			answer += power;
		else
			answer += num;
	}
	return answer;
}