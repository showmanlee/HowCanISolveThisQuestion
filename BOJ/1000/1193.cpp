// 분수찾기
// https://www.acmicpc.net/problem/1193

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a = 1, b = 1, p = 1;
    if (n == 1)
        cout << "1/1";
    else {
        for (int i = 0; i < n-1; i++){
            if (p % 2 == 1){
                if (a == 1)
                    b = p = b + 1;
                else{
                    a--; b++;
                }
            }
            else{
                if (b == 1)
                    a = p = a + 1;
                else{
                    a++; b--;
                }
            }
        }
        cout << a << "/" << b;
    }
}