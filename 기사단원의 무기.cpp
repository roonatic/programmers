#include <string>
#include <vector>

using namespace std;

// 약수 개수 구하기
int divisor(int n)
{
	int cnt = 0;	// 약수 개수

	// N의 약수 계산시,  1부터 N의 제곱근 까지의 수만 0으로 나누어 떨어지는지 확인
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