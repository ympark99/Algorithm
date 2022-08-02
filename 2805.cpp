#include <iostream>
#include <queue>

using namespace std;

int arr[1000000];
int N, M;

int bSearch(int end)
{
        int start = 0;
        int height = 0;
        long long sum = 0;

        while (start <= end) {
                sum = 0;
                height = (start + end) / 2;

                for (int i = 0; i < N; i++) {
                        if (arr[i] > height)
                                sum += (arr[i] - height);
                }

                if (sum >= M) {
                        start = height + 1;
                }
                else {
                        end = height - 1;
                }
        }

        return end;
}

int main(void) 
{
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) 
                scanf("%d", &arr[i]);

        sort(arr, arr + N);
        printf("%d", bSearch(arr[N-1]));

        return 0;
}
