// Sets - STL
// https://www.hackerrank.com/challenges/cpp-sets/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int t;
    set<int> s;
    cin >> t;
    for (int i = 0; i < t; i++){
        int c, n;
        cin >> c >> n;
        if (c == 1)
            s.insert(n);
        else if (c == 2 && s.find(n) != s.end())
            s.erase(n);
        else if (c == 3){
            if (s.find(n) == s.end())
                cout << "No\n";
            else 
                cout << "Yes\n";
        }
    } 
    return 0;
}


// set = 균형 이진 트리 탐색 기반의 자료구조(원소 중복 불가)
// begin(), end(), empty(), insert(), erase(), find(), size(), lower_bound(), upper_bound() 등 사용 가능