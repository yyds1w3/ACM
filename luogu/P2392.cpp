#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset
using namespace std;

int s[4];
int a[25];
int total;
int min_ans;

void dfs(int depth, int left_sum, int count)
{
	if (left_sum > total / 2)
		return;
	if (depth == count)
	{
		int current_time = max(left_sum, total - left_sum);
		min_ans = min(min_ans, current_time);
		return;
	}
	dfs(depth + 1, left_sum + a[depth], count);
	dfs(depth + 1, left_sum, count);
}

int main()
{
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	int final_total_time = 0;
	for (int i = 0; i < 4; ++i)
	{
		total = 0;
		min_ans = 1e9;
		for (int j = 0; j < s[i]; ++j)
		{
			cin >> a[j];
			total += a[j];
		}
		dfs(0, 0, s[i]);
		final_total_time += min_ans;
	}
	cout << final_total_time << endl;
	return 0;
}