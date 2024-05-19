// 진흥원 세미나
// https://www.acmicpc.net/problem/30087

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "Algorithm") {
            cout << 204;
        } else if (s == "DataAnalysis") {
            cout << 207;
        } else if (s == "ArtificialIntelligence") {
            cout << 302;
        } else if (s == "CyberSecurity") {
            cout << "B101";
        } else if (s == "Network") {
            cout << 303;
        } else if (s == "Startup") {
            cout << 501;
        } else if (s == "TestStrategy") {
            cout << 105;
        }
        cout << '\n';
    }
}

// 수업명이 주어질 때, 호수 출력하기