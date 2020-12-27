// Day 26: Nested Logic
// https://www.hackerrank.com/challenges/30-nested-logic/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    
    int res = 0;
    if (c > z)
        res = 10000;
    else if (b > y && c == z)
        res = 500 * (b - y);
    else if (a > x && b == y && c == z)
        res = 15 * (a - x);
    cout << res << '\n';
    
    return 0;
}

// 주어진 문제 구현하기
// 복합 조건문 문제