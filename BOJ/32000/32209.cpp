// 다음 달에 봐요
// https://www.acmicpc.net/problem/32209

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int p = 0;
    bool res = true;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) {
            p += b;
        } else {
            if (p >= b) {
                p -= b;
            } else {
                res = false;
            }
        }
    }
    cout << (res ? "See you next month" : "Adios") << '\n';
}

// 문제은행에 문제를 쌓거나, 쌓인 문제 중 일부를 꺼내서 쓰는 작업 중 하나를 하는 과정에서 꺼내는 문제 수가 쌓인 문제보다 많을 경우 못 꺼낸다고 할 때, 일련의 과정에서 못 꺼내는 상황이 있는지 확인하기