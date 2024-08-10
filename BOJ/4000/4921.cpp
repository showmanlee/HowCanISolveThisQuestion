// 나무 블록
// https://www.acmicpc.net/problem/4921

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int cnt = 0;
    while (true) {
        cnt++;
        string s;
        cin >> s;
        if (s == "0") {
            break;
        }
        bool res = true;
        if (s[0] != '1' || s[s.length() - 1] != '2') {
            cout << cnt << ". NOT\n";
            continue; 
        }
        for (int i = 1; i < s.length(); i++) {
            switch (s[i]) {
                case '1':
                    res = false;
                    break;
                case '2':
                case '3':
                    res = (s[i - 1] == '4' || s[i - 1] == '6'); 
                    break;
                case '4':
                case '5':
                    res = (s[i - 1] == '1' || s[i - 1] == '3');
                    break;
                case '6':
                case '7':
                    res = (s[i - 1] == '8');
                    break;
                case '8':
                    res = (s[i - 1] == '5' || s[i - 1] == '7');
                    break;
                default:
                    break;
            }
            if (!res) {
                break;
            }
        }
        cout << cnt << ". " << (res ? "VALID" : "NOT") << '\n';
    }
}

// 주어진 블럭들을 순서대로 일렬로 빈 구멍 없이 끼울 수 있는지 확인하기

// 앞에서부터 보면서 끼울 수 있는지 확인하기