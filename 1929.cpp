#include <iostream>
#include <cstdio>
 
using namespace std;
 
int num[1000001];
 
int main()
{
    int m, n;
    scanf("%d%d", &m, &n);
    num[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (num[i] == 0) {
            for (int j = 2; n >= i * j; j++)
            {
                num[i * j] = 1;
            }
        }
    }
    for (int i = m; i <= n; i++)
    {
        if(num[i] == 0)
            printf("%d\n", i);
    }
    return 0; 
}
