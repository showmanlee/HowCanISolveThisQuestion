// 별 찍기 - 1
// https://www.acmicpc.net/problem/2438

#include<stdio.h>
int main(void)
{
    int n, i, j;
    scanf("%d", &n);
    for (i=0;i<n;i++)
    {
        for (j=0; j<=i; j++)
            printf("*");
        printf("\n");
    }
}