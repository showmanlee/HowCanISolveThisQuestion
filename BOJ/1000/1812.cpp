// 사탕
// https://www.acmicpc.net/problem/1812

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += (i % 2 == 0 ? v[i] : -v[i]);
    }
    sum /= 2;
    cout << sum << '\n';
    for(int i = 1; i < n; i++)
    {
        sum = v[i - 1] - sum;
        cout << sum << '\n';
    }
}

// 홀수인 n명 중 맞붙은 2명이 가지고 있는 사탕의 개수들이 주어질 때, 각각이 가지고 있는 사탕 개수 구하기

// (1 + 2) - (2 + 3) + (3 + 1) = 1 * 2
// 이 원리를 이용해 1번을 구한 후, 차례로 열어본다