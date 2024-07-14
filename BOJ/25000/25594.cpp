// HG 음성기호
// https://www.acmicpc.net/problem/25594

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string code[26] = {
    "aespa",
    "baekjoon",
    "cau",
    "debug",
    "edge",
    "firefox",
    "golang",
    "haegang",
    "iu",
    "java",
    "kotlin",
    "lol",
    "mips",
    "null",
    "os",
    "python",
    "query",
    "roka",
    "solvedac",
    "tod",
    "unix",
    "virus",
    "whale",
    "xcode",
    "yahoo",
    "zebra"
};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    bool res = true;
    string ress;
    int idx = 0;
    while (idx < s.length()) {
        string t = code[s[idx] - 'a'];
        for (int i = 0; i < t.length(); i++) {
            if (idx + i >= s.length() || s[i + idx] != t[i]) {
                res = false;
                break;
            }
        }
        if (!res) {
            break;
        }
        ress += s[idx];
        idx += t.length();
    }

    if (res) {
        cout << "It's HG!\n" << ress << '\n';
    } else {
        cout << "ERROR!\n";
    }
}

// 소문자 문자열을 주어진 음성 기호로 풀어쓴 결과가 주어질 때, 그게 정말 맞는지, 맞다면 결과 출력하기

// 커서를 움직이며 첫 글자의 알파벳과 이후 문자들이 그에 대응하는 음성 기호와 같다면 넘어가기
// 길이가 매우 길어서 최적화가 필요함