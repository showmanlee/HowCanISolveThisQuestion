// 암호코드
// https://www.acmicpc.net/problem/2011

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    vector<int> dp(s.length() + 3);
    s = 'X' + s;
    dp[0] = dp[1] = 1;
    if (s[1] == '0') {
        cout << 0 << '\n';
    } else {
        for (int i = 2; i < s.length(); i++) {
            if (s[i] > '0') {
                dp[i] = (dp[i] + dp[i - 1]) % 1000000;
            }
            int t = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (t >= 10 && t <= 26) {
                dp[i] = (dp[i] + dp[i - 2]) % 1000000;
            }
        }
        cout << dp[s.length() - 1] << '\n';
    }
}

// 대문자 알파벳을 순서 숫자로 바꾸어 나열한 암호 코드가 있을 때, 해당 암호 코드로 만들 수 있는 대문자 문자열 개수 구하기

// dp 문제 - 수의 자릿수를 보는 문제
// 현재 자리에서 앞의 숫자와 합쳐서 두 자릿수가 될 수도 있고, 따로 쓰여 한 자릿수가 될 수도 있음 - 다만 두 자릿수가 되려면 합쳐서 10~26이 되어야 하고, 0은 한 자릿수로 사용될 수 없음
// 또한, 이를 미루어볼 때 수가 0부터 시작할 경우 답이 나올 수 없음 - 이 경우는 0 출력
// dp는 1부터 시작, 뒤로 이동하며 한 자릿수가 가능한 경우 전 칸 dp를 더하고, 두 자릿수가 가능한 경우 그 전 칸 dp도 더해준다 - 불가능한 0이 있는 경우 dp 덧셈 과정이 누락되어 0이 되어버림
// 참고로 문자열 앞에 X를 붙여주는 이유는 dp 인덱스와 싱크를 맞춰주기 위해서