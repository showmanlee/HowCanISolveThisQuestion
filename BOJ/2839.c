// 설탕 배달
// https://www.acmicpc.net/problem/2839

#include <stdio.h>
int main(void)
{
    int n, c = 0;
    scanf("%d", &n);
    if (n % 5 == 0)
        printf("%d\n", n/5);
    else{
        c += n/5;
        if (n % 5 == 1 && n >= 6)
            c++;
        else if (n % 5 == 2 && n >= 12)
            c += 2;
        else if (n % 5 == 3)
            c++;
        else if (n % 5 == 4 && n >= 9)
            c += 2;
        else
            c = -1;
        printf("%d\n", c);
    }
}

// 3짜리 봉투와 5짜리 봉투가 있을 때 최대한 적은 봉투로 가져가는 방법
// 5짜리 봉투를 최대한 많이 들고 가며 남은 양을 3을 이용해 처리