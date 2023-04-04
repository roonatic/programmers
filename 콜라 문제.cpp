#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
	int answer = 0;

	int tmpt = n;
	while (tmpt >= a)
	{
		int now = (tmpt / a) * b;
		int leftover = tmpt % a;
		answer += now;
		now += leftover;
		tmpt = now;
	}
	return answer;
}