#include<bits/stdc++.h>
#define inf 1987654321
using namespace std;

typedef pair<int, int> p;
p x = { 1, 1 }, y;
p lis[1100];

int arr[1100][1100];
int siz;
queue<int> q;

int dist(p who, p where);

int mini(int locx, int locy);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> siz;

    x = { 1, 1 };
    y = make_pair(siz, siz);

    int len;
    cin >> len;

    for (int i = 1; i <= len; i++) {
        cin >> lis[i].first >> lis[i].second;
    }

    //initial
    for (int i = 0; i <= len + 5; i++) {
        for (int j = 0; j <= len + 5; j++) {
            arr[i][j] = inf;
        }
    }
    arr[0][0] = 0;
    arr[1][0] = dist(make_pair(1, 1), lis[1]);
    arr[0][1] = dist(make_pair(siz, siz), lis[1]);


    //debug
    for (int i = 0; i < len; i++) {
        int tmp = mini(i, len);
        tmp = mini(len, i);
    }

    for (int i = 0; i <= len; i++) {
        for (int j = 0; j <= len; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

int dist(p who, p where) { return abs(who.first - where.first) + abs(who.second - where.second); }

int mini(int locx, int locy) {
    /// locx, locy�� �����϶��� �Ǳ������ �̵��Ÿ��� �ּڰ�,
    cout << locx << " " << locy << endl;
    if (arr[locx][locy] != inf)return arr[locx][locy];



    // ex) locx 10, locy 3 ->������ locx9, locy3���� �̵��߾����
    if (locx - locy > 1) {
        //�ȱ�������
        if (arr[locx - 1][locy] == inf) arr[locx - 1][locy] = mini(locx - 1, locy);

        arr[locx][locy] = arr[locx - 1][locy] + dist(lis[locx - 1], lis[locx]);
        return arr[locx][locy];
    }

    // ex) locx 3, locy 10 ->������ locx3, locy9���� �̵��߾����
    if (locy - locx > 1) {
        //�ȱ�������
        if (arr[locx][locy - 1] == inf) arr[locx][locy - 1] = mini(locx, locy - 1);

        arr[locx][locy] = arr[locx][locy - 1] + dist(lis[locy - 1], lis[locy]);
        return arr[locx][locy];
    }

    // ex) locx 10, locy 9 ->locy9�� ������, locx�� 0~8����
    if (locx - locy == 1) {
        int tmp = inf;
        int minidx = 0;

        //0�������
        if (arr[0][locy] == inf) arr[0][locy] = mini(0, locy);
        tmp = arr[0][locy] + dist(make_pair(1, 1), lis[locx]);

        for (int i = 1; i < locy; i++) {
            //�ȱ�������
            if (arr[i][locy] == inf) arr[i][locy] = mini(i, locy);

            if (tmp > arr[i][locy] + dist(lis[i], lis[locx])) {
                tmp = arr[i][locy] + dist(lis[i], lis[locx]);
            }
        }
        arr[locx][locy] = tmp;
        return tmp;
    }

    // ex) locx 9, locy 10 ->locx9�� ������, locy�� 0~8����
    if (locy - locx == 1) {
        int tmp = inf;
        int minidx = 0;

        //0�������
        if (arr[locx][0] == inf) arr[locx][0] = mini(locx, 0);
        tmp = arr[locx][0] + dist(make_pair(siz, siz), lis[locy]);

        for (int i = 1; i < locx; i++) {
            //�ȱ�������
            if (arr[locx][i] == inf) arr[locx][i] = mini(locx, i);

            if (tmp > arr[locx][i] + dist(lis[i], lis[locy])) {
                tmp = arr[locx][i] + dist(lis[i], lis[locy]);
            }
        }
        arr[locx][locy] = tmp;
        return tmp;
    }

    cout << "fuck";
    return inf;
}