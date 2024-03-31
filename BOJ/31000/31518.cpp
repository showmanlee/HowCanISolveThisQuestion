// Triple Sevens
// https://www.acmicpc.net/problem/31518

#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < 3; i++) {
        bool b = false;
        for (int j = 0; j < n; j++) {
            int p;
            cin >> p;
            if (p == 7) {
                b = true;
            }
        }
        if (b) {
            res++;
        }
    }
    cout << (res == 3 ? 777 : 0) << '\n';
}

// 길이가 n인 3개의 숫자 배열에서 모두 7이 나오는지 확인하기