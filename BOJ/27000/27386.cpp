#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    string res = a + b;
    sort(res.begin(), res.end());
    cout << res << '\n';
}
