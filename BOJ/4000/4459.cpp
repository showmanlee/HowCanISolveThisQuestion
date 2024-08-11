// Always Follow the Rules in Zombieland
// https://www.acmicpc.net/problem/4459

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n);
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, v[i]);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        cout << "Rule " << p << ": ";
        if (p >= 1 && p <= n) {
            cout << v[p - 1];
        } else {
            cout << "No such rule";
        }
        cout << '\n';
    }
}

// 1~n번 규칙이 주어질 때, 입력한 번호의 규칙 출력하기

// 번호에 없으면 No such rule 출력하기