// Smile with Similes
// https://www.acmicpc.net/problem/6889

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> v(n), w(m);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int j = 0; j < m; j++) {
        cin >> w[j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i] << " as " << w[j] << '\n';
        }
    }
}

// 앞단어와 뒷단어 풀이 주어질 때, 모든 단어 쌍 출력하기