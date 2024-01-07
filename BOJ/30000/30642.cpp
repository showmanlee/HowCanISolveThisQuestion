// 아이그루스와 화장실
// https://www.acmicpc.net/problem/30642

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, p;
    string s;
    cin >> n >> s >> p;
    if (s == "annyong") {
        if (p % 2 == 1) {
            cout << p;
        } else {
            cout << (p + 1 > n ? p - 1 : p + 1);
        }
    } else if (s == "induck") {
        if (p % 2 == 0) {
            cout << p;
        } else {
            cout << (p + 1 > n ? p - 1 : p + 1);
        }
    }
}

// n층 건물에서 annyong은 홀수 층, induck은 짝수 층의 화장실만 들어갈 수 있을 때, 현재 위치에서 가장 가까운 화장실 찾기

// 홀짝이 맞으면 그 자리에서, 아니면 한층 위나 아래로 이동 - 건물 밖으로 벗어나지 않게 주의