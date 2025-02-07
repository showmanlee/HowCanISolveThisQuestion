// Sumac Sequences
// https://www.acmicpc.net/problem/6780

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int res = 3;
    int cur = a - b;
    while (b >= cur) {
        res++;
        int p = cur;
        cur = b - cur;
        b = p;
    }
    cout << res << '\n';
}

// 한 항이 (두 칸 앞 - 한 칸 앞)으로 정의되는 수열에서 첫째 항과 둘째 항이 주어질 때, 마지막 항만 뒷항보다 큰 조건이 유지되는 수열의 길이 출력하기