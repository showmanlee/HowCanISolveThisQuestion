// Paslėpta suma
// https://www.acmicpc.net/problem/30067

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    vector<int> v(10);
    int res = 0;
    for (int i = 0; i < 10; i++) {
        cin >> v[i];
        res += v[i];
    }
    for (int i = 0; i < 10; i++) {
        if (res - v[i] == v[i]) {
            cout << v[i] << '\n';
            break;
        }
    }
}

// 10개의 정수 중 남은 9개의 합으로 만들 수 있는 정수 하나 고르기