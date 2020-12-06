// Day 5: Loops
// https://www.hackerrank.com/challenges/30-loops/problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int i = 1; i <= 10; i++)
        cout << n << " x " << i << " = " << (n * i) << endl;
    
    return 0;
}

// 반복문으로 구구단 출력