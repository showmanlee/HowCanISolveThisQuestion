// ESEJ
// https://www.acmicpc.net/problem/11773

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= b; i++) {
        string res;
        int p = i;
        while (p > 0) {
            res += ('a' + p % 26);
            p /= 26;
        }
        cout << res << ' ';
    }
    cout << '\n';
}

// 최소 b/2 종류의 최대 15글자의 a~b단어로 구성된 문장 출력하기

// 사전에 있는 단어일 필요는 없음 - 그러나 중복은 체크해야 함
// 따라서 a부터 zzzzzz...까지 매 단어마다 만들 수 있도록 처리해줍시다
// 여기서 단어 종류가 b/2가지 이상이어야 하므로 종류 수는 b로 맞춰줘야 함 - a < b/2면 a가지 출력해서 정답 못받음