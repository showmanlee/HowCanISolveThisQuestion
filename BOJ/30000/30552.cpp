// Attendance
// https://www.acmicpc.net/problem/30552

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<char, int> pr;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> res;
    string prev;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "Present!") {
            res.pop_back();
        } else {
            res.push_back(s);
        }
    }
    if (res.empty()) {
        cout << "No Absences" << '\n';
    } else {
        for (string s : res) {
            cout << s << '\n';
        }
    }
}

// 출석과 대답이 순서대로 주어질 때, 대답하지 않은 사람들 찾기