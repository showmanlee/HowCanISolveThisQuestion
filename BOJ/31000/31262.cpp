// ПОДАРЪК
// https://www.acmicpc.net/problem/31262

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<char> letter, number;
    for (int i = 0; i < 6; i++) {
        if (isdigit(s[i])) {
            number.push_back(s[i]);
        } else {
            letter.push_back(s[i]);
        }
    }
    sort(letter.begin(), letter.end());
    sort(number.begin(), number.end(), greater<char>());
    for (int i = 0; i < 3; i++) {
        cout << letter[i] << number[i];
    }
    cout << '\n';
}

// 주어진 대문자, 숫자 3개씩을 각각 정순, 역순으로 정렬하여 대문자, 숫자 순으로 교대로 출력하기

// 하면 됩니다