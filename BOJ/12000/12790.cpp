// Mini Fantasy War
// https://www.acmicpc.net/problem/12790

#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int hp, mp, att, def, hp_u, mp_u, att_u, def_u;
        cin >> hp >> mp >> att >> def >> hp_u >> mp_u >> att_u >> def_u;
        hp += hp_u;
        if (hp < 1)
            hp = 1;
        mp += mp_u;
        if (mp < 1)
            mp = 1;
        att += att_u;
        if (att < 0)
            att = 0;
        def += def_u;
        cout << (hp + mp * 5 + att * 2 + def * 2) << endl;
    }
}