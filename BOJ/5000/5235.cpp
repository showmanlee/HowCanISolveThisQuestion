// Even Sum More Than Odd Sum
// https://www.acmicpc.net/problem/5235

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n;
        cin >> n;
        int even = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            if (p % 2 == 1) {
                odd += p;
            } else {
                even += p;
            }
        }
        cout << (even > odd ? "EVEN" : (even < odd ? "ODD" : "TIE")) << '\n';
    }
}

// 주어진 n개의 정수 중 홀수까리의 합과 짝수끼리의 합 중 더 큰 값 구하기