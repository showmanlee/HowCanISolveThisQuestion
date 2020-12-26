// Day 25: Running Time and Complexity
// https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n){
    if (n == 1)
        return false;
    for (int i = 2; i <= (int)sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        if (isPrime(n))
            cout << "Prime\n";
        else
            cout << "Not prime\n";
    }
    return 0;
}


// 소수 알고리즘 짜는데, O(n^2)가 나오지 않게 하기
// sqrt(n)까지 계산해도 됨