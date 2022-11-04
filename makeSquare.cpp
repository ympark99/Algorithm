#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


/* [Notice for C/C++]
 * - 기본 제공되는 뼈대 코드는 입출력의 이해를 돕기위해 제공되었습니다.
 * - 뼈대코드의 활용은 선택사항이며 코드를 직접 작성하여도 무관합니다.
 *
 * - 데이터의 입력과 출력은 stdin과 stdout을 통하고 scanf와 printf를 사용하세요
 * - 별도의 병렬 처리나 시스템콜, 네트워크/파일접근 등을 하지 마세요 
 * - main은 int형으로 선언한 후 return 0를 항상 하는 것을 권유합니다 
 * - 지역변수 배열 크기에 의한 Stack Overflow 에러에 주의하세요
 * - (C++) cin/cout보다 scanf/printf를 사용하기를 권장합니다. (입출력 성능에 의한 이유)
 */

vector<pair<int, int>> test;
int N;
double ans;
bool check[51];

int case1[6] = {0, 1, 2, 0, 0, 1};
int case2[6] = {1, 2, 3, 3, 2, 3};

// 네 변 길이 같고, 대각선 길이 같은지
double isSquare(vector<pair<int, int>> dot){
	// 각각 거리 다 구하고 크기순 정렬
	vector<double> dist;
	for(int i = 0; i < 6; i++){
		int ax = dot[case1[i]].first;
		int ay = dot[case1[i]].second;
		int bx = dot[case2[i]].first;
		int by = dot[case2[i]].second;
		
		double distance = sqrt(pow((bx - ax), 2.0) + pow((by-ay), 2.0));
		dist.push_back(distance);
	}
	sort(dist.begin(), dist.end());
	
	for(int i = 0; i < 3; i++){
		if(dist[i] == dist[i+1])
			continue;
		else return -1;
	}
	if(dist[4] != dist[5])
		return -1;

	return dist[0] * dist[0];
}

void dfs(vector<pair<int, int>> v, int idx, int cnt){
	if(cnt == 4){
		double res = isSquare(test);
		if(res != -1){
			ans = max(ans, res);
		}
        return;
	}

	for(int i = idx; i < N; i++){
		if(!check[i]){
			check[i] = true;
			test.push_back(v[i]);
			dfs(v, i, cnt+1);
			test.pop_back();
			check[i] = false;
		}
	}
}

int main()
{   //프로그램의 시작부 
		ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
		cin >> N;
		vector<pair<int, int>> v(N);
		for(int i = 0; i < N; i++){
			cin >> v[i].first >> v[i].second;
		}
		
		dfs(v, 0, 0);
		ans = (round(ans * 100)) / 100.0;
		printf("%.2f\n", ans);
    return 0;
}
