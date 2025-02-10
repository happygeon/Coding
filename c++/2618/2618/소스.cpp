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
    /// locx, locy의 상태일때가 되기까지의 이동거리의 최솟값,
    cout << locx << " " << locy << endl;
    if (arr[locx][locy] != inf)return arr[locx][locy];



    // ex) locx 10, locy 3 ->무조건 locx9, locy3에서 이동했어야함
    if (locx - locy > 1) {
        //안구했으면
        if (arr[locx - 1][locy] == inf) arr[locx - 1][locy] = mini(locx - 1, locy);

        arr[locx][locy] = arr[locx - 1][locy] + dist(lis[locx - 1], lis[locx]);
        return arr[locx][locy];
    }

    // ex) locx 3, locy 10 ->무조건 locx3, locy9에서 이동했어야함
    if (locy - locx > 1) {
        //안구했으면
        if (arr[locx][locy - 1] == inf) arr[locx][locy - 1] = mini(locx, locy - 1);

        arr[locx][locy] = arr[locx][locy - 1] + dist(lis[locy - 1], lis[locy]);
        return arr[locx][locy];
    }

    // ex) locx 10, locy 9 ->locy9는 알지만, locx는 0~8가능
    if (locx - locy == 1) {
        int tmp = inf;
        int minidx = 0;

        //0에서출발
        if (arr[0][locy] == inf) arr[0][locy] = mini(0, locy);
        tmp = arr[0][locy] + dist(make_pair(1, 1), lis[locx]);

        for (int i = 1; i < locy; i++) {
            //안구했으면
            if (arr[i][locy] == inf) arr[i][locy] = mini(i, locy);

            if (tmp > arr[i][locy] + dist(lis[i], lis[locx])) {
                tmp = arr[i][locy] + dist(lis[i], lis[locx]);
            }
        }
        arr[locx][locy] = tmp;
        return tmp;
    }

    // ex) locx 9, locy 10 ->locx9는 알지만, locy는 0~8가능
    if (locy - locx == 1) {
        int tmp = inf;
        int minidx = 0;

        //0에서출발
        if (arr[locx][0] == inf) arr[locx][0] = mini(locx, 0);
        tmp = arr[locx][0] + dist(make_pair(siz, siz), lis[locy]);

        for (int i = 1; i < locx; i++) {
            //안구했으면
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