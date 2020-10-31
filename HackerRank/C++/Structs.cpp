// Structs
// https://www.hackerrank.com/challenges/c-tutorial-struct/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student{
    int age;
    string first_name;
    string last_name;
    int standard;
};

int main() {
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}

// 구조체는 C에서부터 지원되던 것, C++ 클래스의 모태가 됨
// 클래스와는 달리 기본적으로 접근자가 public으로 처리됨