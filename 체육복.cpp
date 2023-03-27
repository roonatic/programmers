#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	answer = n - lost.size();

	vector<int> already;
	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 0; j < reserve.size(); j++)
		{
			if (lost[i] == reserve[j] - 1 || lost[i] == reserve[j] + 1)
			{
				if (already.empty())
				{
					already.push_back(reserve[j]);
					answer++;
					break;
				}
				else
				{
					for (int k = 0; k < already.size(); k++)
					{
						if (already[k] == reserve[j])
							break;
						else
							answer++;
					}
				}
			}

			if (answer == n)
				break;

				
		}
	}

	return answer;
}

int main()
{
	int n = 5;
	vector<int> lost = {2,4};
	vector<int> reserve = { 1,3,5 };

	solution(n, lost, reserve);
}