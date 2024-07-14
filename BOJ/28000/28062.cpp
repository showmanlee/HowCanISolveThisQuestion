// 준석이의 사탕 사기
// https://www.acmicpc.net/problem/28062

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> odd;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p % 2 == 1) {
            odd.push_back(p);
        } else {
            res += p;
        }
    }
    sort(odd.begin(), odd.end());
    for (int i = (odd.size() % 2 == 1 ? 1 : 0); i < odd.size(); i++) {
        res += odd[i];
    }
    cout << res << '\n';
}

// n개의 사탕 묶음 속에 들어 있는 사탕 개수가 주어질 때, 짝수로 가져갈 수 있는 최대 개수 구하기

// 짝수 묶음은 그대로 들고가면 됨 - 짝수를 몇 번 더하든 짝수니까
// 하지만 홀수는 홀수번 더하면 홀수가 됨 - 따라서 홀수 묶음을 모은 후 묶음 개수가 홀수일 경우 가장 작은 건 버린다