#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	
	stack<int> sub;
	stack<int> main;
	int j = 1;
	for (int i = 0; i < order.size(); i++)
	{
		if (sub.empty())
		{
			
			while (j <= order[i])
			{
				sub.push(j);
				j++;
			}	
			main.push(sub.top());
			sub.pop();

		}
		else 
		{
			if (sub.top() == order[i])
			{
				main.push(sub.top());
				sub.pop();
			}
			else
			{
				while (j <= order[i])
				{
					sub.push(j);
					j++;
				}
				if (sub.top() == order[i])
				{
					main.push(sub.top());
					sub.pop();
				}
				else
					break;
				
			}
		}
	}
	
	answer = main.size();
	return answer;
}

int main()
{
	vector<int> order = { 4, 3, 1, 2, 5 };
	solution(order);
}