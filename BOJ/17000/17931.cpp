// Greedily Increasing Subsequence
// https://www.acmicpc.net/problem/17931

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int x = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (x < p) {
            x = p;
            res.push_back(p);
        }
    }
    cout << res.size() << '\n';
    for (int i : res) {
        cout << i << ' ';
    }
    cout << '\n';
}

// 주어진 수열에서 원소들을 빼서 만들 수 있는 가장 긴 증가수열 출력하기