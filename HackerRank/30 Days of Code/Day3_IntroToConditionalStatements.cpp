// Day 3: Intro to Conditional Statements
// https://www.hackerrank.com/challenges/30-conditional-statements/problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if (N % 2 == 1)
        cout << "Weird" << '\n';
    else if (N >= 2 && N <= 5)
        cout << "Not Weird" << '\n';
    else if (N >= 6 && N <= 20)
        cout << "Weird" << '\n';
    else
        cout << "Not Weird" << '\n';
            
    return 0;
}

// 조건문 만들기
// 사실 어느 언어에서나 크게 다르지 않아서
