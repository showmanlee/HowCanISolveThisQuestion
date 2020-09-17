// 스택
// https://www.acmicpc.net/problem/10828

#include <iostream>
#include <string>
using namespace std;

int main(void){
    int lines;
    int stack[10000];
    int cursor = -1;    
    
    cin >> lines;  
    for (int i = 0; i < lines; i++){
        string order;

        cin >> order;
        if  (order == "push"){
            int num;
            cin >> num;
            cursor++;
            stack[cursor] = num;
        }
        else if (order == "pop"){
            if (cursor == -1)
                cout << -1 << endl;
            else{
                cout << stack[cursor] << endl;
                cursor--;
            }
        }
        else if (order == "size"){
            cout << cursor + 1 << endl;
        }
        else if (order == "empty"){
            if (cursor == -1)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (order == "top"){
            if (cursor == -1)
                cout << -1 << endl;
            else
                cout << stack[cursor] << endl;
        }
    }
}

// 내 손으로 스택 자료구조 만들기