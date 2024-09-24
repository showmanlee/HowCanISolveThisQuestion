// Zbiór
// https://www.acmicpc.net/problem/8678

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n, m;
        cin >> n >> m;
        cout << (m % n == 0 ? "TAK" : "NIE") << '\n';
    }
}

// n의 약수 집합이 m의 약수 집합에 포함되는지 구하기

// n이 m의 약수라면 포함되겠지