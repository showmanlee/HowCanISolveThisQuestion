// 방 번호
// https://www.acmicpc.net/problem/1475

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
    string s;
    cin >> s;
    vector<int> count(9);
    for (char c : s){
        int i = c - '0';
        if (i == 9)
            i = 6;
        count[i]++;
    }
    count[6] = (count[6] + 1) / 2;
    int res = 0;
    for (int i = 0; i <= 8; i++)
        if (res < count[i])
            res = count[i];
    cout << res << '\n';
}

// 0~9 숫자 세트로 번호를 만들려고 한다. 6과 9는 서로 공유할 수 있을 때, 필요한 세트 수는?
// 0~8까지 필요한 조각수를 기록, 9는 6으로 기록되게 하고, 6을 올림으로 /2해준 뒤 기록된 수 중 가장 많이 필요한 걸로 결정