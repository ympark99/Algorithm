#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
   ios_base::sync_with_stdio(0); cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v1(n);
	for (auto& c : v1)
		cin >> c;

	vector<int> v2(m);
	for (auto& c : v2)
		cin >> c;

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int counter = 0;
	int p1 = 0, p2 = 0;

	while (p1 < n && p2 < m) {
		if (v1[p1] == v2[p2]) {
			++p1, ++p2;
			++counter;
		}
		else if (v1[p1] < v2[p2]) {
			++p1;
		}
		else {
			++p2;
		}
	}

	cout << (n + m) - 2 * counter << '\n';

   return 0;
}
