// DNA 해독
// https://www.acmicpc.net/problem/1672

#include <iostream>
#include <string>
using namespace std;

int toindex(char c) {
	if (c == 'A')
		return 0;
	else if (c == 'G')
		return 1;
	else if (c == 'C')
		return 2;
	else if (c == 'T')
		return 3;
	return -1;
}

int main(void) {
	char px[4][4] = {	{'A', 'C', 'A', 'G'},
						{'C', 'G', 'T', 'A'},
						{'A', 'T', 'C', 'G'},
						{'G', 'A', 'G', 'T'} };
	int n;
	string s;
	cin >> n >> s;
	char last = s[n - 1];
	for (int i = n - 2; i >= 0; i--) 
		last = px[toindex(s[i])][toindex(last)];
	cout << last << endl;
}