// 부분 문자열
// https://www.acmicpc.net/problem/16916

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;
    string p;
    int n = s.length();
    int m = t.length();
    bool res = false;

    vector<int> failVec(m, 0);
    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && t[i] != t[j]) {
            j = failVec[j - 1];
        }
        if (t[i] == t[j]) {
            failVec[i] = ++j;
        }
    }
    
    j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != t[j]){
            j = failVec[j - 1];
        }
        if (s[i] == t[j]){
            if (j == m - 1) {
                res = true;
                break;
            }
            else {
                j++;
            }
        }
    }

    cout << (res ? 1 : 0) << '\n';
}

// 주어진 문자열이 다른 문자열의 부분 문자열인지 확인하기

// substr을 쓰면 무조건 시간 초과 - 슬라이딩 윈도우를 쓰기도 어려우니, KMP 알고리즘이란 걸 써보죠
// 실패함수를 만들어서 문자열 탐색을 최적화할 수 있는 알고리즘 - 현재 위치에서 틀렸을 때, 그 전 칸 기준으로 봐야할 곳, 매칭되는 곳을 저장
// python에서는 in을 쓰면 아주 쉽게 풀립니다 - c++에서도 bits/stdc++.h의 strstr을 쓰면 풀려요 - 하지만 이참에 원리를 알아야죠