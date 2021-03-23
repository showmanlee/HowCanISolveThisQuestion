// 8단 변속기
// https://softeer.ai/practice/info.do?eventIdx=1&psProblemId=408

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
        vector<int> arr(8);
        for (int i = 0; i < 8; i++)
                cin >> arr[i];
        bool order = arr[0] < arr[1];
        bool mixed = false;
        for (int i = 2; i < 8; i++){
                if (order != arr[i - 1] < arr[i]){
                        mixed = true;
                        break;
                }
        }
        if (mixed)
                cout << "mixed" << '\n';
        else
                cout << (order ? "ascending" : "descending") << '\n';
        return 0;
}

// 1~8까지의 숫자가 정순/역순으로 정렬되었는지 정렬되지 않았는지 판단하기
// 0,1번 숫자의 정렬 상태를 확인한 후, 그 뒤의 정렬 상태가 그와 같은지 확인
// 만약 중간에 섞였다면 mixed, 그렇지 않으면 처음에 본 정렬 상태를 출력