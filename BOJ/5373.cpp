// 큐빙
// https://www.acmicpc.net/problem/5373

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pr;

char cube[54];

void init() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 9; j++) {
			if (i == 0)
				cube[i * 9 + j] = 'w';
			else if (i == 1)
				cube[i * 9 + j] = 'g';
			else if (i == 2)
				cube[i * 9 + j] = 'r';
			else if (i == 3)
				cube[i * 9 + j] = 'b';
			else if (i == 4)
				cube[i * 9 + j] = 'o';
			else if (i == 5)
				cube[i * 9 + j] = 'y';
		}
	}
}

void rotate(string s) {
	int d = (s[1] == '+' ? 1 : 3);
	int p = 0;
	for (int i = 0; i < d; i++) {
		if (s[0] == 'U') {
			char t1  = cube[36];
			char t2  = cube[37];
			char t3  = cube[38];
			cube[36] = cube[9];
			cube[37] = cube[10];
			cube[38] = cube[11];
			cube[9]  = cube[18];
			cube[10] = cube[19];
			cube[11] = cube[20];
			cube[18] = cube[27];
			cube[19] = cube[28];
			cube[20] = cube[29];
			cube[27] = t1;
			cube[28] = t2;
			cube[29] = t3;
			p = 0;
		}
		else if (s[0] == 'D') {
			char t1  = cube[15];
			char t2  = cube[16];
			char t3  = cube[17];
			cube[15] = cube[42];
			cube[16] = cube[43];
			cube[17] = cube[44];
			cube[42] = cube[33];
			cube[43] = cube[34];
			cube[44] = cube[35];
			cube[33] = cube[24];
			cube[34] = cube[25];
			cube[35] = cube[26];
			cube[24] = t1;
			cube[25] = t2;
			cube[26] = t3;
			p = 5;
		}
		else if (s[0] == 'F') {
			char t1  = cube[6];
			char t2  = cube[7];
			char t3  = cube[8];
			cube[6]  = cube[17];
			cube[7]  = cube[14];
			cube[8]  = cube[11];
			cube[17] = cube[47];
			cube[14] = cube[46];
			cube[11] = cube[45];
			cube[47] = cube[27];
			cube[46] = cube[30];
			cube[45] = cube[33];
			cube[27] = t1;
			cube[30] = t2;
			cube[33] = t3;
			p = 2;
		}
		else if (s[0] == 'B') {
			char t1  = cube[0];
			char t2  = cube[1];
			char t3  = cube[2];
			cube[0]  = cube[29];
			cube[1]  = cube[32];
			cube[2]  = cube[35];
			cube[29] = cube[53];
			cube[32] = cube[52];
			cube[35] = cube[51];
			cube[53] = cube[15];
			cube[52] = cube[12];
			cube[51] = cube[9];
			cube[15] = t1;
			cube[12] = t2;
			cube[9]  = t3;
			p = 4;
		}
		else if (s[0] == 'L') {
			char t1  = cube[0];
			char t2  = cube[3];
			char t3  = cube[6];
			cube[0]  = cube[44];
			cube[3]  = cube[41];
			cube[6]  = cube[38];
			cube[44] = cube[45];
			cube[41] = cube[48];
			cube[38] = cube[51];
			cube[45] = cube[18];
			cube[48] = cube[21];
			cube[51] = cube[24];
			cube[18] = t1;
			cube[21] = t2;
			cube[24] = t3;
			p = 1;
		}
		else if (s[0] == 'R') {
			char t1  = cube[47];
			char t2  = cube[50];
			char t3  = cube[53];
			cube[47] = cube[42];
			cube[50] = cube[39];
			cube[53] = cube[36];
			cube[42] = cube[2];
			cube[39] = cube[5];
			cube[36] = cube[8];
			cube[2]  = cube[20];
			cube[5]  = cube[23];
			cube[8]  = cube[26];
			cube[20] = t1;
			cube[23] = t2;
			cube[26] = t3;
			p = 3;
		}
		char ta = cube[p * 9 + 0];
		cube[p * 9 + 0] = cube[p * 9 + 6];
		cube[p * 9 + 6] = cube[p * 9 + 8];
		cube[p * 9 + 8] = cube[p * 9 + 2];
		cube[p * 9 + 2] = ta;
		char tb = cube[p * 9 + 1];
		cube[p * 9 + 1] = cube[p * 9 + 3];
		cube[p * 9 + 3] = cube[p * 9 + 7];
		cube[p * 9 + 7] = cube[p * 9 + 5];
		cube[p * 9 + 5] = tb;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		init();
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			rotate(s);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << cube[i * 3 + j];
			cout << '\n';
		}
	}
}

// 큐브를 주어진 대로 돌렸을 때 윗면에 나오는 색상은?

// 큐브의 초기 상태는 다음과 같고, 여기의 면 인덱스를 이렇게 줘보자
//    w            U           0
//  g r b o  ->  L F R B  -> 1 2 3 4
//    y            D           5
// 면 인덱스를 준 큐브의 각 칸에 번호를 매기면 다음과 같이 됨
//          00 01 02
//          03 04 05
//          06 07 08
// 09 10 11 18 19 20 27 28 29 36 37 38
// 12 13 14 21 22 23 30 31 32 39 40 41
// 15 16 17 24 25 26 33 34 35 42 43 44
//          45 46 47                         
//          48 49 50                       
//          51 52 53       

// 이 상태의 큐브를 배열로 구현하여, 회전 방향에 맞게 배열을 회전해주어야 함
// U - (36 37 38) (27 28 29) (18 19 20) (09 10 11)
// D - (15 16 17) (24 25 26) (33 34 35) (42 43 44)
// F - (06 07 08) (27 30 33) (47 46 45) (17 14 11)
// B - (00 01 02) (15 12 09) (53 52 51) (29 32 35)
// L - (00 03 06) (18 21 24) (45 48 51) (44 41 38)
// R - (47 50 53) (20 23 26) (02 05 08) (42 39 36)
// 이를 시계방향(+)으로 돌릴 때는 (i)를 (i + 1) 자리에 옮겨주면 됨
// 반시계(-)는 시계방향으로 3번 돌리면 된다 - 따라서 시계방향만 구현해주면 됨
// 여기에 면 회전까지 구현하면 회전 명령 완료
// 0 -> 2 -> 8 -> 6 / 1 -> 5 -> 7 -> 3

// 역시 노가다가 최고야