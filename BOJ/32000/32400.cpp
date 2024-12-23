// 다트판
// https://www.acmicpc.net/problem/32400

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<double> v(20);
    double a = 0, b = 0;
    int idx = 0;
    for (int i = 0; i < 20; i++) {
        cin >> v[i];
        b += v[i];
        if (v[i] == 20) {
            idx = i;
        }
    }
    a += v[(idx + 19) % 20] + v[idx] + v[(idx + 1) % 20];
    a /= 3.0;
    b /= 20.0;
    cout << (a == b ? "Tie" : (a > b ? "Alice" : "Bob")) << '\n';
}

// n/10개 문항을 모두 맞춰야 하는 문제 10세트가 주어질 때, 모두 맞춘 문제 개수 출력하기