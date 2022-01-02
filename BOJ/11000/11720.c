// 숫자의 합
// https://www.acmicpc.net/problem/11720

#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, i, sum = 0; char str[101];
    scanf("%d", &n);
    scanf("%s", str);
    for (i = 0; i < 101; i++)
    {
        if (str[i] == '\0')
            break;
        sum += str[i] - '0';
    }
    printf("%d\n", sum);
}