// !밀비 급일
// https://www.acmicpc.net/problem/11365

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    vector<string> p;
    string input;
    while (true) {
        getline(cin, input);
        if (input == "END")
            break;
        p.push_back(input);
    }
    for (int i = 0; i < p.size(); i++) {
        for (int j = p[i].length() - 1; j >= 0; j--)
            cout << p[i][j];
        cout << endl;
    }
}

// std::getline(cin, string);