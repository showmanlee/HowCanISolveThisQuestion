// 모르고리즘 회장님 추천 받습니다
// https://www.acmicpc.net/problem/20124

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int max = 0;
    vector<string> p;
    for (int i = 0; i < n; i++){
        string s;
        int c;
        cin >> s >> c;
        if (c > max){
            max = c;
            p.clear();
        }
        if (c == max)
            p.push_back(s);
    }
    sort(p.begin(), p.end());
    cout << p[0] << '\n';
}

// 최다 득표를 받은 사람(중 사전 순서로 가장 앞에 있는 사람)을 찾아라