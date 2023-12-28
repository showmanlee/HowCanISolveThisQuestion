// 첫 번째 항
// https://www.acmicpc.net/problem/9214

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string func(string s) {
    if (s.length() % 2 == 1) {
        return s;
    }
    string ss;
    for (int i = 0; i < s.length(); i += 2) {
		for (int j = 0; j < s[i] - '0'; j++) {
            ss += s[i + 1];
        }
	}
    if (ss == s) {
        return ss;
    }
    return func(ss);
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int test = 0;
    while (true) {
        test++;
        string s;
        cin >> s;
        if (s == "0") {
            break;
        }
        cout << "Test " << test << ": " << func(s) << '\n';
    }
}

// 현재 항을 같은 숫자들로 구분되도록 쪼갠 후, 각 숫자가 반복되는 횟수를 앞에 붙여 수열을 만들 때, 주어진 항의 첫 번째 항 구하기

// 역순으로 구해나가봅시다 - 주어진 항의 길이가 홀수면 아웃, 짝수면 개수로 바꾸기