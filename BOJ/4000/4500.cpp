// “Bubble Gum, Bubble Gum, in the dish, how many pieces do you wish?”
// https://www.acmicpc.net/problem/4500

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        string s, name, r;
        int p;
        cin.ignore();
        getline(cin, s);
        stringstream ss(s);
        cin >> name >> p;
        int idx = 0;
        vector<string> v;
        while (ss >> r) {
            v.push_back(r);
            if (r == name) {
                idx = v.size() - 1;
            }
        }
        cout << v[(idx + p - 1) % v.size()] << '\n';
    }
}

// 원으로 둘러앉은 사람들 중에서 자신을 첫 번째로 하여 오른쪽으로 n번째 칸에 있는 사람 구하기