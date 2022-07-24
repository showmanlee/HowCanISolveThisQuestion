// 수열
// https://www.acmicpc.net/problem/2491

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int cur;
    cin >> cur;
    int prev = cur;
    int inc = 1, dec = 1, res = 1;
    for (int i = 1; i < n; i++) {
        cin >> cur;
        if (prev == cur) {
            inc++;
            dec++;
        } else if (prev < cur) {
            inc++;
            dec = 1;
        } else {
            inc = 1;
            dec++;
        }
        res = max(res, max(inc, dec));
        prev = cur;
    }
    cout << res << '\n';
}

// 주어진 수열에서 연속적으로 감소하지 않거나 증가하지 않는 최대 길이 출력하기

// 현재 수를 입력받은 후 이전 수와 비교해 값이 바뀐 쪽의 연속을 늘리고, 그렇지 않은 쪽은 1로 두기 - 그 과정에서 나온 최댓값이 답
// 반드시 증가하거나 감소하지 않고 동률이 유지되어도 연속이 유지됨 - 이 경우 두 연속 모두 +1