// Head or Tail
// https://www.acmicpc.net/problem/5751

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            if (p == 0) {
                a++;
            } else {
                b++;
            }
        }
        cout << "Mary won " << a << " times and John won " << b << " times" << '\n';
    }
}

// 소문자 시저 암호문과 복호화된 첫 글자가 주어질 떄, 주어진 암호문 전체 복호화하기