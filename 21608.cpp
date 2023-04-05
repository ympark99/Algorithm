#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int seat[21][21]; // 자리 배치 1~N만 쓸 것임

int dx[4] = {1, -1, 0, 0};           // 방향
int dy[4] = {0, 0, 1, -1};           // 방향
int good[5] = {0, 1, 10, 100, 1000}; // 점수

int N;

vector<int> info[401]; // 학생 번호와 선호하는 학생을 저장

int main()
{
    cin >> N;
    int num = N * N;
    while (num--)
    {
        int st, a, b, c, d;
        cin >> st >> a >> b >> c >> d;
        info[st].push_back(a);
        info[st].push_back(b);
        info[st].push_back(c);
        info[st].push_back(d);

        int x, y;            // 자리
        bool isDone = false; // 해당 작업에서 자리를 찾았는지

        // 1번 작업
        vector<pair<int, int>> vec1[5]; // 벡터 배열 선언
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (seat[i][j] == 0)
                {
                    int cnt = 0;
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];

                        if (nx < 1 || nx > N || ny < 1 || ny > N)
                            continue;
                        if (seat[nx][ny] == a || seat[nx][ny] == b || seat[nx][ny] == c || seat[nx][ny] == d)
                        {
                            cnt++;
                        }
                    }
                    // 해당 인접한 개수만큼에 대해 벡터 추가
                    vec1[cnt].push_back({i, j});
                }
            }
        }

        // vec1에 대해서 인접한 칸이 많은 벡터부터 찾음
        int after1;
        for (int i = 4; i >= 0; i--)
        {
            if (vec1[i].empty())
                continue;
            // 비어있지 않다면 개수를 셈

            int size = vec1[i].size();
            // 개수가 1로 유일하면 그 원소가 자리 결정
            if (size == 1)
            {
                x = vec1[i][0].X;
                y = vec1[i][0].Y;
                isDone = true;
                break;
            }
            else
            {
                after1 = i; // 해당 벡터 저장
                break;
            }
        }

        // 2번 작업 시작 전 자리를 찾았으면 다음 것 찾으러감
        if (isDone)
        {
            seat[x][y] = st;
            continue;
        }

        // 2번 작업 vec1에서 여러 개의 후보를 가져옴. -> after i에 저장해놓음
        // 해당 벡터에 들어있는 좌표들의 인접 빈칸 조사
        vector<pair<int, int>> vec2[5]; // 벡터 배열 선언

        for (auto x : vec1[after1])
        {
            int cnt = 0;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = x.X + dx[dir];
                int ny = x.Y + dy[dir];

                if (nx < 1 || nx > N || ny < 1 || ny > N)
                    continue;
                if (seat[nx][ny] == 0)
                {
                    cnt++;
                } // 해당 자리가 비어있으면
            }
            vec2[cnt].push_back(x);
        }

        // vec2에 대해서 인접한 빈칸이 많은 벡터부터 찾음
        int after2;
        for (int i = 4; i >= 0; i--)
        {
            if (vec2[i].empty())
                continue;
            // 비어있지 않다면 개수를 셈

            int size = vec2[i].size();
            // 개수가 1로 유일하면 자리 결정
            if (size == 1)
            {
                x = vec2[i][0].X;
                y = vec2[i][0].Y;
                isDone = true;
                break;
            }
            else
            {
                after2 = i; // 해당 벡터 번호 저장
                break;
            }
        }

        // 3번 작업 시작 전 자리를 찾았으면 다음 것 찾으러감
        if (isDone)
        {
            seat[x][y] = st;
            continue;
        }

        // 3번 작업 시작
        // vec2[after2]에 대한 좌표들을 먼저 x(행)으로 오름차순 정렬후 y(열) 오름차순 정렬하여 가장 작은 것
        sort(vec2[after2].begin(), vec2[after2].end());
        x = vec2[after2][0].X;
        y = vec2[after2][0].Y;
        isDone = true;

        // 마지막 자리를 찾아서 넣음
        if (isDone)
        {
            seat[x][y] = st;
            continue;
        }
    }

    // 자리를 모두 배치했으면 만족도 조사
    long long ans = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int number = seat[i][j];
            int cnt = 0;
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                if (nx < 1 || nx > N || ny < 1 || ny > N)
                    continue;
                if (seat[nx][ny] == info[number][0] || seat[nx][ny] == info[number][1] || seat[nx][ny] == info[number][2] || seat[nx][ny] == info[number][3])
                {
                    cnt++;
                }
            }

            ans += good[cnt];
        }
    }

    cout << ans;

    return 0;
}
