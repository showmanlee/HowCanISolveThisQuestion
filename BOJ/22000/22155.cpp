// Простая задача
// https://www.acmicpc.net/problem/22155

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << (((a <= 2 && b <= 1) || (a <= 1 && b <= 2)) ? "Yes" : "No") << '\n';
    }
}

// a가 2 이하고 b가 1 이하거나, b가 2 이하고 a가 1 이하인지 확인하기