#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    int l;
    cin >> l;
    vector<int> v(l + 1);
    for (int i = 1; i <= l; i++) {
        cin >> v[i];
    }
    v[0] = 0;
    sort(v.begin(), v.end());
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < l; i++) {
        if (v[i] <= n && v[i + 1] >= n) {
            for (int a = v[i] + 1; a <= n; a++) {
                for (int b = n; b < v[i + 1]; b++) {
                    if (a != b) {
                        res++;
                    }
                }
            }
            break;
        }
    }
    cout << res << '\n';
}