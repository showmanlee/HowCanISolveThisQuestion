// 완전수
// https://www.acmicpc.net/problem/14563

#include <iostream>
#include <vector>
#include <cmath>
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
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                res += i;
            }
        }
        cout << (res == n ? "Perfect" : (res < n ? "Deficient" : "Abundant")) << '\n';
    }
}

// 주어진 자연수가 자신을 제외한 모든 약수의 합이 되는지 확인하기

// 약수를 구해봅시다