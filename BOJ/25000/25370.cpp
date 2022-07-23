// 카드 숫자 곱의 경우의 수
// https://www.acmicpc.net/problem/25370

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> res;

void times(int n, int c) {
    if (c == 0) {
        return;
    }
    for (int i = 1; i <= 9; i++) {
        int nn = n * i;
        res[nn]++;
        times(nn, c - 1);
    }
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    times(1, n);
    cout << res.size() << '\n';
}

// 1부터 9까지의 수를 n번 곱할 때, 나올 수 있는 숫자의 개수 구하기

// 재귀함수를 이용해 모든 경우의 수를 구해본다 - n이 7까지만 나오기 때문에 어느 정도는 구할 수 있음
// 그러면서 map으로 등장 횟수를 세고, map.size()로 원소 수(등장 수)를 출력한다
// 사실 이렇게 해서 그렇지, 9^7이 500만 언저리이므로 배열로 놓고 풀어도 됨