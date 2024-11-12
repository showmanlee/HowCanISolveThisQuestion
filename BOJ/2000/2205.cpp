// 저울 추 만들기
// https://www.acmicpc.net/problem/2205

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n + 1);
    vector<bool> visit(n + 1);
    int p = 1;
    while (p <= n) {
        p *= 2;
    }

    for (int i = n; i >= 1; i--) {
        for (int j = p; j >= 1; j /= 2) {
            if (j - i <= n && !visit[j - i]) {
                v[i] = j - i;
                visit[j - i] = true;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << v[i] << '\n';
    }
}

// 1부터 n까지 수열 두 쌍에서 양쪽 원소 하나씩을 사용해 모두 2의 배수로 만들 때, 선택해야 하는 원소 구하기

// 모두 만들 수는 있음 - 뒤에서부터 가장 큰 값부터 체크해가면 됨