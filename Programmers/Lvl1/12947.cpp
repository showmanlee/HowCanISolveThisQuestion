// 하샤드 수
// https://programmers.co.kr/learn/courses/30/lessons/12947

#include <string>
#include <vector>

using namespace std;

bool solution(int x) {  
    string s = to_string(x);
    int k = 0;
    for (int i = 0; i < s.length(); i++)
        k += s[i] - '0';
    
    if (x % k == 0)
        return true;
    else 
        return false;
}