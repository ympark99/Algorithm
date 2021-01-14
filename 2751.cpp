#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.clear();

	for(int i=0; i<n; i++){
		int num;
		cin >> num;
		v.push_back(num); // vector 추가
		
		sort(v.begin(),v.end());
	}
	
	for(int i=0; i<n; i++){
		cout << v[i] << endl;		
	}
	return 0;
}
