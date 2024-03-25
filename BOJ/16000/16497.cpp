// 대출 요청
// https://www.acmicpc.net/problem/16497

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(32);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a]--;
        v[b]++;
    }
    int t;
    cin >> t;
    int res = 1;
    for (int i = 1; i <= 31; i++) {
        t += v[i];
        if (t < 0) {
            res = 0;
            break;
        }
    }
    cout << res << '\n';
}

// 책 t권의 대출/반납 현황이 주어질 때, 모든 대출/반납 요청이 가능한지 판정하기

// 대출일은 재고를 빼고, 반납일은 재고를 넣는다
// 이를 이용해 1일부터 31일까지 재고 변동 현황을 작성한 뒤 돌려보며 마이너스가 뜨는지 확인하기