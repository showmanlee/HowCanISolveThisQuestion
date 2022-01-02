// RPG Extreme
// https://www.acmicpc.net/problem/17081

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Me {
public:
	int r, c, r_i, c_i;
	int hp, hp_m;
	int att, att_w;
	int def, def_a;
	int lv, exp, exp_m;
	bool boss;
	vector<string> obs;

	Me() {
		r = r_i = c = c_i = 0;
		hp = hp_m = 20;
		att = def = 2;
		att_w = def_a = 0;
		lv = 1;
		exp = 0;
		exp_m = 5;
		boss = false;
	}

	void init(int x, int y) {
		r = r_i = x;
		c = c_i = y;
	}

	int attack(bool init) {
		int a = att + att_w;
		if (init && obsfinder("CO")) {
			if (obsfinder("DX"))
				a *= 3;
			else
				a *= 2;
		}
		return a;
	}

	int damage(int d) {
		if (boss) {
			boss = false;
			return 0;
		}
		hp -= max(1, d - def - def_a);
		if (hp <= 0) {
			if (obsfinder("RE")) {
				obs.pop_back();
				r = r_i;
				c = c_i;
				hp = hp_m;
				return 1;
			}
			hp = 0;
			return -1;
		}
		return 0;
	}

	int trap() {
		if (obsfinder("DX"))
			hp -= 1;
		else
			hp -= 5;
		if (hp <= 0) {
			if (obsfinder("RE")) {
				obs.pop_back();
				r = r_i;
				c = c_i;
				hp = hp_m;
				return 1;
			}
			hp = 0;
			return -1;
		}
		return 0;
	}

	void bossin() {
		if (obsfinder("HU")) {
			hp = hp_m;
			boss = true;
		}
	}

	void win(int e) {
		if (obsfinder("HR")) {
			hp += 3;
			if (hp > hp_m)
				hp = hp_m;
		}
		double gain = e;
		if (obsfinder("EX"))
			gain *= 1.2;
		exp += (int)gain;
		if (exp >= exp_m) {
			lv++;
			exp = 0;
			exp_m += 5;
			hp = hp_m = hp_m + 5;
			att += 2;
			def += 2;
		}
	}

	void getobs(string s) {
		if (!obsfinder(s) && obs.size() < 4) {
			obs.push_back(s);
			sort(obs.begin(), obs.end());
		}
	}

	bool obsfinder(string s) {
		if (find(obs.begin(), obs.end(), s) == obs.end())
			return false;
		return true;
	}
};

class Monster {
public:
	int r, c, hp, hp_m, att, def, exp;
	string name;
	bool boss;

	Monster(int r, int c, string name, int att, int def, int hp, int exp) {
		this->r = r;
		this->c = c;
		this->name = name;
		this->att = att;
		this->def = def;
		this->hp = hp_m = hp;
		this->exp = exp;
		boss = false;
	}

	void imboss() {
		boss = true;
	}
};

class Item {
public:
	int r, c;
	char type;
	string stat;

	Item(int r, int c, char type, string stat) {
		this->r = r;
		this->c = c;
		this->type = type;
		this->stat = stat;
	}
};

int main(void) {
	int m, n, turn = 0, mc = 0, ic = 0;
	vector<string> board;
	vector<Monster> monsters;
	vector<Item> items;
	string command;
	Me me;
	int end = 0;

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		board.push_back(s);
		for (int j = 0; j < s.length(); j++) {
			if (board[i][j] == '@') {
				me.init(i, j);
				board[i][j] = '.';
			}
			if (board[i][j] == 'B')
				ic++;
			if (board[i][j] == '&' || board[i][j] == 'M')
				mc++;
		}
	}
	cin >> command;
	for (int i = 0; i < mc; i++) {
		int r, c, w, a, h, e;
		string s;
		cin >> r >> c >> s >> w >> a >> h >> e;
		monsters.push_back(Monster(r - 1, c - 1, s, w, a, h, e));
	}
	for (int i = 0; i < ic; i++) {
		int r, c;
		char t;
		string s;
		cin >> r >> c >> t >> s;
		items.push_back(Item(r - 1, c - 1, t, s));
	}

	for (int d = 0; d < command.length(); d++) {
		if (command[d] == 'U') {
			if (me.r > 0 && board[me.r - 1][me.c] != '#')
				me.r -= 1;
		}
		else if (command[d] == 'D') {
			if (me.r < m - 1 && board[me.r + 1][me.c] != '#')
				me.r += 1;
		}
		else if (command[d] == 'L') {
			if (me.c > 0 && board[me.r][me.c - 1] != '#')
				me.c -= 1;
		}
		else if (command[d] == 'R') {
			if (me.c < n - 1 && board[me.r][me.c + 1] != '#')
				me.c += 1;
		}

		if (board[me.r][me.c] == 'B') {
			for (int i = 0; i < items.size(); i++) {
				if (items[i].r == me.r && items[i].c == me.c) {
					if (items[i].type == 'W')
						me.att_w = stoi(items[i].stat);
					else if (items[i].type == 'A')
						me.def_a = stoi(items[i].stat);
					else if (items[i].type == 'O')
						me.getobs(items[i].stat);
					board[me.r][me.c] = '.';
					break;
				}
			}
		}
		else if (board[me.r][me.c] == '^') {
			int fail = me.trap();
			if (fail == -1)
				end = 1;
		}
		else if (board[me.r][me.c] == '&') {
			for (int i = 0; i < monsters.size(); i++) {
				if (monsters[i].r == me.r && monsters[i].c == me.c) {
					bool init = true;
					while (true) {
						monsters[i].hp -= max(1, me.attack(init) - monsters[i].def);
						if (monsters[i].hp <= 0) {
							me.win(monsters[i].exp);
							board[me.r][me.c] = '.';
							break;
						}
						if (init)
							init = false;
						int fail = me.damage(monsters[i].att);
						if (fail == -1) {
							end = -i - 1;
							break;
						}
						else if (fail == 1) {
							monsters[i].hp = monsters[i].hp_m;
							break;
						}
					}
					break;
				}
			}
		}
		else if (board[me.r][me.c] == 'M') {
			for (int i = 0; i < monsters.size(); i++) {
				if (monsters[i].r == me.r && monsters[i].c == me.c) {
					bool init = true;
					me.bossin();
					while (true) {
						monsters[i].hp -= max(1, me.attack(init) - monsters[i].def);
						if (monsters[i].hp <= 0) {
							me.win(monsters[i].exp);
							board[me.r][me.c] = '.';
							end = 10;
							break;
						}
						if (init)
							init = false;
						int fail = me.damage(monsters[i].att);
						if (fail == -1) {
							end = -i - 1;
							break;
						}
						else if (fail == 1) {
							monsters[i].hp = monsters[i].hp_m;
							break;
						}
					}
					break;
				}
			}
		}

		turn++;
		if (end != 0)
			break;
	}
	if (me.hp > 0)
		board[me.r][me.c] = '@';
	for (int i = 0; i < board.size(); i++)
		cout << board[i] << endl;
	cout << "Passed Turns : " << turn << endl;
	cout << "LV : " << me.lv << endl;
	cout << "HP : " << me.hp << "/" << me.hp_m << endl;
	cout << "ATT : " << me.att << "+" << me.att_w << endl;
	cout << "DEF : " << me.def << "+" << me.def_a << endl;
	cout << "EXP : " << me.exp << "/" << me.exp_m << endl;
	if (end == 10)
		cout << "YOU WIN!" << endl;
	else if (end == 1)
		cout << "YOU HAVE BEEN KILLED BY SPIKE TRAP.." << endl;
	else if (end == 0)
		cout << "Press any key to continue." << endl;
	else
		cout << "YOU HAVE BEEN KILLED BY " << monsters[-end - 1].name << ".." << endl;
}

/*	역대(?) 최대 규모의 구현 문제
	BOJ에서 푸는 비문학 문제

	- Input
	맵 사이즈 N M
	맵의 상태(N * M 문자 블록)
	주인공 이동 경로
		Left Right Up Down, 벽에 닿거나 맵 밖으로 벗어나는 경우 무시
	몬스터 관련 정보(여러 줄)
		행 열 이름 공격력 방어력 체력 경험치
		맵 좌표에 따라 일반/보스 구분
	아이템 관련 정보(여러 줄)
		행 열 타입 효과
		타입 = W, A일 경우 효과는 추가 스탯
		타입 = O일 경우 효과는 장신구 효과

	- 맵 구성요소
	. = 빈 칸
	@ = 주인공의 (초기) 위치, . 판정
	# = 벽
	B = 아이템 상자
		무기 W, 갑옷 A, 장신구 O 중 하나 획득 가능, 열리면 .로 변경
		W, A는 얻은 장비로 즉시 교체
		O는 착용 칸이 남았고, 동일한 효과의 장신구를 착용하지 않은 상태일 때 장착
	^ = 가시 함정
		밟으면 HP -5 (사망 가능), 사라지지 않음
		커맨드 입력 실수로 움직이지 못한 경우 또 밟음 처리
	& = 몬스터
		몬스터 스탯: 이름(string), 공격력, 방어력, 체력, 경험치(int)
		몬스터 칸에 진입 시 전투, 주인공의 선공으로 max(1, 내 공격력 - 쟤 방어력)의 피해를 입히다 누구 하나 죽으면 끝
		전투 과정 전체는 모두 한 턴 판정
		몬스터가 죽으면 .로 변경
	M = 보스
		잡으면 승리, 그 외에는 &과 같음

	- 주인공 (초기) 스탯
	int 체력 = 20
	int 공격력 = 2
	int 방어력 = 2
	int 레벨 = 1
	int 경험치 = 0
		레벨업에 필요한 경험치 = 현재 레벨 * 5
		레벨업 시 체력 +5, 공격력 +2, 방어력 +2 적용, 체력 모두 회복, 경험치 0부터 다시 시작

	- 장비
	무기 - 1개만 장착 가능, 공격력 증가
		무기의 공격력은 주인공의 공격력과 같은 판정, 아이템으로 인한 공격력 증가에도 적용
	방어구 - 1개만 장착 가능, 방어력 증가
	장신구 - 동일한 효과는 1개씩, 총 4개까지 장착 가능
		HR - 전투에서 승리할 때마다 체력 3 회복(최대치까지)
		RE - 사망 시 시작 위치에서 최대 체력 및 스탯/아이템 유지하고 부활(날 죽인 몬스터의 체력도 회복), 부활시 해당 장신구 소멸(재획득시 재장착 가능)
		CO - 전투 돌입 시 첫 공격의 공격력 * 2
		EX - 얻는 경험치 * 1.2(소수 버림)
		DX - 가시 함정 받는 대미지 1로 변경, CO로 인한 첫타 공격력 증가 효과 * 3으로 증가
		HU - 보스전 돌입 시 체력 최대로 회복, 보스 첫타 대미지 0으로 변경
		CU - 아무 효과 없음

	- 게임 종료 조건
	보스 사살 - YOU WIN!
		보스 사살 후 경험치 획득 및 레벨업, 장신구 효과 적용까지 끝난 후 종료
	HP가 0이 되었지만 RE 장신구가 없을 경우 - YOU HAVE BEEN KILLED BY 몬스터 이름 or SPIKE TRAP..
	모든 커맨드를 마쳤을 때 - Press any key to continue.

	- 결과 출력
	맵 상태
		죽은 경우 플레이어 위치 표시 안함
	Passed Turns : 진행한 턴 수
		턴 수는 0부터 시작해 행동(전투)를 마치고 다음 행동하기 직전에 ++
	LV : 레벨
	HP : 남은/최대
	ATT : 나/무기
	DEF : 나/방어구
	EXP : 현재/목표
	종료 콜
*/