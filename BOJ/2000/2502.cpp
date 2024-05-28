// 떡 먹는 호랑이
// https://www.acmicpc.net/problem/2502

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> fiba(n + 1), fibb(n + 1);
    fiba[1] = 1;
    fiba[2] = 0;
    fibb[1] = 0;
    fibb[2] = 1;
    for (int i = 3; i <= n; i++) {
        fiba[i] = fiba[i - 1] + fiba[i - 2];
        fibb[i] = fibb[i - 1] + fibb[i - 2];
    }
    for (int i = 1; i <= k; i++) {
        int p = k - (fiba[n] * i);
        if (p % fibb[n] == 0) {
            cout << i << '\n' << (p / fibb[n]) << '\n';
            break;
        }
    }
}

// 하루에 전날과 그 전날에 먹은 떡만큼 먹는 호랑이가 n일차에 먹은 떡이 k개일 때, 1일차와 2일차에 먹은 떡의 개수 구하기

// 1일차에 a개, 2일차에 b개를 먹었으면 3일차부터는 a+b, b+(a+b), (a+b)+(a+b+b)... 순으로 xa+yb 꼴로 나타낼 수 있음
// 따라서 이 케이스에 맞춰 n일차의 a와 b의 값을 구한 후, 여기에 맞는 값을 찾아준다