// Basic Data Types
// https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i;
    long l;
    char c;
    float f;
    double d;
    scanf("%d %ld %c %f %lf", &i, &l, &c, &f, &d);
    printf("%d\n%ld\n%c\n%f\n%lf\n", i, l, c, f, d);
    return 0;
}

// int/float = 4바이트, long/double = 8바이트
// Microsoft 등 일부 컴파일러는 int와 long의 크기가 같고, long long이 8바이트인 경우도 있으니 주의
// 그리고 cin/cout보다 scanf/printf가 더 빠름 - 15552.cpp