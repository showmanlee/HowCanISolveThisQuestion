// 일반 화학 실험
// https://www.acmicpc.net/problem/4766

#include <cstdio>
using namespace std;

int main(void) {
    double a, b;
    scanf("%lf", &b);
    while (true) {
        a = b;
        scanf("%lf", &b);
        if (b == 999)
            break;
        printf("%.2lf\n", (b - a));
    }
}

// 현재 입력값과 이전 입력값을 차를 실수형으로 구하기