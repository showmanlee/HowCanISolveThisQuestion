// Maps - STL
// https://www.hackerrank.com/challenges/cpp-maps/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int t;
    map<string, int> m;
    cin >> t;
    for (int i = 0; i < t; i++){
        int c;
        string s;
        cin >> c >> s;
        if (c == 1){
            int n;
            cin >> n;
            m[s] += n;
        }
        else if (c == 2 && m.find(s) != m.end())
            m.erase(s);
        else if (c == 3){
            if (m.find(s) != m.end())
                cout << m[s] << '\n';
            else 
                cout << 0 << '\n';
        }
    }
    return 0;
}

// map - 해시 기반 자료구조
// insert(make_pair()), erase, find 등 사용 가능