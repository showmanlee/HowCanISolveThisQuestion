// 가단조와 다장조
// https://www.acmicpc.net/problem/5211

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    char k = 'X';
    int a = 0, c = 0;
    bool ready = true;
    for (char p : s) {
        if (ready) {
            if (p == 'A' || p == 'D' || p == 'E') {
                a++;
            } else if (p == 'C' || p == 'F' || p == 'G') {
                c++;
            }
            k = p;
            ready = false;
        }
        if (!ready && p == '|') {
            ready = true;
        }
    }
    if (a == c) {
        cout << ((s.back() == 'A' || s.back() == 'D' || s.back() == 'E') ? "A-minor" : "C-major");
    } else {
        cout << (a > c ? "A-minor" : "C-major");
    }
    cout << '\n';
}

// 코드 표가 주어질 때, 가단조인지 다장조인지 확인하기

// 확인하는 방법은 마디 처음으로 A,D,E가 더 많이 나오면 가단조, C,F,G가 더 많이 나오면 다장조 - 같으면 마지막 음 보고 결정
// 그렇기에 악보 문자열 받고 | 나올 때마다 그 다음 문자를 보고 첫 음 개수 세어주면 됩니다