#include <bits/stdc++.h>
using namespace std;

struct star{
	int x, y;
};

int n, m, l, k, res;
vector<star> arr;

void calc(int x, int y){
	int cnt=0;
	for(int i=0; i<k; i++){
		if(x<=arr[i].x && arr[i].x<=x+l && y<=arr[i].y && arr[i].y<=y+l) cnt++;
		res = max(res, cnt);
	}
}

int main(){
	cin >> n >> m >> l >> k;
	arr.resize(k);
	int max = 0, maxx, maxy;

	for(int i=0; i<k; i++){
		cin >> arr[i].x >> arr[i].y;
	}

	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++){
			calc(arr[i].x, arr[j].y);
		}
	}

	cout << k-res;
}
