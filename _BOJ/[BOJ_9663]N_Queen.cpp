#include <iostream>

using namespace std;

int n,cnt;
bool chk0[15], chk1[31], chk2[31];

void nQueen(int x) {
    if (x == n)
        ++cnt;
    else {
        for (int y = 0;y < n;++y) {
            if (!chk0[y] && !chk1[x + y] && !chk2[x - y + n]) {
                chk0[y] = chk1[x + y] = chk2[x - y + n] = true;
                nQueen(x + 1);
                chk0[y] = chk1[x + y] = chk2[x - y + n] = false;
            }
        }
    }
}

int main()
{
    cin >> n;
    nQueen(0);
    cout << cnt;
    return 0;
}
