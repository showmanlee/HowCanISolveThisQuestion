// 참외밭
// https://www.acmicpc.net/problem/2477

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
   cin.tie(NULL);
   ios_base::sync_with_stdio(false);

   int n;
   cin >> n;
   vector<int> sides;
   int maxX = 0, maxY = 0;
   int keyX = 0, keyY = 0;
   for (int i = 0; i < 6; i++) {
      int a, b;
      cin >> a >> b;
      sides.push_back(b);
      if (i % 2 == 0) {
         if (maxX < b) {
            maxX = b;
            keyX = i;
         }
      } else {
         if (maxY < b) {
            maxY = b;
            keyY = i;
         }
      }
   }
   int res = maxX * maxY * n;
   res -= sides[(keyX + 3) % 6] * sides[(keyY + 3) % 6] * n;
   cout << res << '\n';
}

// 직사각형에서 한 꼭지가 ㄱ자로 깎인 육각형 형태의 밭에서 1m^2당 참외가 n개 자라고 각 변의 길이가 시계 반대 방향 순서로 주어질 떄 전체 밭에서 나는 참외의 수는?

// 가장 긴 가로/세로변은 짧은 가로/세로변과 길이가 같을 수 없다 - 주어진 변의 길이가 0이 될 수 없으므로
// 이를 이용해 가장 긴 가로변과 세로변 길이, 그리고 그들의 등장 순서를 기록해둔다
// 변들은 언제나 순서대로 주어지므로, 가장 긴 변들은 항상 붙어 나오고, 그 덩어리에서 2칸 뒤(각 변의 3칸 뒤)에 깎인 넓이를 나타내는 변들이 등장한다
// 따라서 긴변의 곱 - 깎인 변의 곱을 구하면 답