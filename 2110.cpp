#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	int n, c, num, st, router, start, end, mid, ans = 0;
	cin >> n >> c;
	vector<int> pos;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		pos.push_back(num);
	}
	sort(pos.begin(), pos.end());
	start = 1;
	end = pos[n - 1] - pos[0];

	while (start <= end)
	{
		router = 1;
		mid = (start + end) / 2;
		st = pos[0];

		for (int i = 1; i < n; i++)
		{
			if (pos[i] - st >= mid)
			{
				router++;
				st = pos[i];
			}
		}

		if (router >= c)
		{
			ans = max(ans, mid);
			start = mid + 1;
		}

		else
			end = mid - 1;
	}
	cout << ans;
	return 0;
}
