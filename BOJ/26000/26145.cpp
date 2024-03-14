// 출제비 재분배
// https://www.acmicpc.net/problem/26145

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> v(n + m);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + m; j++) {
            int p;
            cin >> p;
            v[i] -= p;
            v[j] += p;
        }
    }
    for (int i = 0; i < n + m; i++) {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

// n명의 출제자가 각자 받은 출제비로 n명의 출제자 및 m명의 검수자에게 돈을 줄 때, 모두가 돈을 나눠가진 결과 출력하기

// 주어지는 대로 교환해갑시다