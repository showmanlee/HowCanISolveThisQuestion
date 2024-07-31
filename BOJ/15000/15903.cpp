// 카드 합체 놀이
// https://www.acmicpc.net/problem/15903

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    priority_queue<long long> pq;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        pq.push(-p); 
    }
    for (int i = 0; i < m; i++) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }
    long long res = 0;
    while (!pq.empty()) {
        res += -pq.top();
        pq.pop();
    }
    cout << res << '\n';
}

// 자연수가 적힌 카드 n장 중 2장을 골라 두 수의 합을 2장에 카드에 덮어쓰는 과정을 m번 반복할 때, 모든 카드 수의 합의 최솟값 구하기

// 최소 힙으로 언제나 가장 작은 두 카드를 뽑아 더한다