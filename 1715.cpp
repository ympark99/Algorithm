#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
int N;

int main(void)
{
        int n;
        int sum = 0;

        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
              scanf("%d", &n);
              pq.push(n);  
        }

        while(pq.size() > 1) {
                int n1, n2;

                n1 = pq.top(), pq.pop();
                n2 = pq.top(), pq.pop();
                sum += (n1 + n2);
                pq.push(n1 + n2);
        }

        printf("%d", sum);
        return 0;
}
