#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int findTreasure(int n, int m, int (*a)[m], int (*r)[m], int k)
{
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            *(*(a + i) + j) += max((i > 0) ? *(*(a + i - 1) + j) : 0, (j > 0) ? *(*(a + i) + j - 1) : 0);
        }
    }

    int i = n - 1; int j = m - 1;
    while (i >= 0 && j >= 0){
        *(*(r + i) + j) = k--;
        if (i < 1) j--;
        else if (j < 1) i--;
        else{
            if (*(*(a + i - 1) + j) > *(*(a + i) + j-1)) i--;
            else j--;
        }
    }
    return *(*(a + n-1) + m - 1);
}

int main()
{
    //freopen("map", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n][m];
    int r[n][m];
    for (int i =0; i < n; i++)
        for (int j = 0; j < m; j++){
            scanf("%d", (*(a+i)+j));
            *(*(r + i) + j) = 0;
        }

    printf("%d\n", findTreasure(n, m, a, r, n+m-1));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%2d ", *(*(r+i)+j));
        }
        putchar('\n');
    }
    return 0;
}
