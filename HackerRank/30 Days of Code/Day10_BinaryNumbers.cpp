// Day 10: Binary Numbers
// https://www.hackerrank.com/challenges/30-binary-numbers/problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    int max = 0, count = 0;
    while(n > 0){
        if (n % 2 == 1){
            count++;
            if (max < count)
                max = count;
        }
        else
            count = 0;
        n /= 2;
    }
    cout << max << '\n';
    return 0;
}

// 10진수를 2진수로 변환하고, 연속해서 나오는 1의 최대 개수 구하기