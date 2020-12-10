// Day 9: Recursion 3
// https://www.hackerrank.com/challenges/30-recursion/problem

#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = factorial(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

// 재귀 함수로 팩토리얼 짜기
// factorial(n) = n * factorial(n - 1)
// (factorial(1) = 1)