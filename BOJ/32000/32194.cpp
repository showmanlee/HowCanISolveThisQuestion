// 질문은 계속돼
// https://www.acmicpc.net/problem/32194

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n + 2);
    v[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
        int q, a, b;
        cin >> q >> a >> b;
        int d = b - a + 1;
        int p = v[b] - v[a - 1];
        v[i] = v[i - 1];
        if ((q == 1 && p == d) || (q == 2 && p == 0)) {
            cout << "Yes";
            v[i]++;
        } else {
            cout << "No";
        }
        cout << '\n';
    }
}

// 첫 문제가 참으로 주어지고 그 다음부터 "a번째부터 b번째 문제의 답이 참/거짓인가?" 라는 질문이 계속 주어질 때, 각 질문의 답 구하기

// 누적합 시스템 사용 - 지금까지 나온 참 개수 저장  