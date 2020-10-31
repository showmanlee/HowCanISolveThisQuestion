// Array Introduction
// https://www.hackerrank.com/challenges/arrays-introduction/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = n - 1; i >= 0; i--)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}

// C++에서는 C와 달리 변수로도 배열 크기를 지정할 수 있다