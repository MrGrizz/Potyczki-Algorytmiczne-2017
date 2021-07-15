#include <iostream>

using namespace std;

const int N = 2001;

int field[N][N];
long long sum[N][N];
int height, width;

int main() {
    ios_base::sync_with_stdio(0);

    cin >> height >> width;

    int n;
    cin >> n;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            field[i][j] = 1;
        }
    }

    int a, b;
    while (n --> 0) {
        cin >> a >> b;
        field[a][b] = 0;
    }

    for (int i = width - 1; i >= 0; i--) {
        for (int j = height - 1; j >= 0; j--) {
            if (field[i][j]) {
                sum[i][j] = sum[i + 1][j] + sum[i][j + 1] + 1;

                if (sum[i + 1][j] != 0 || sum[i][j + 1] != 0) {
                    sum[i][j] -= sum[i + 1][j + 1];
                }
            }
        }
    }

    for (int i = width - 1; i >= 0; i--) {
        for (int j = height - 1; j >= 0; j--) {
            if (field[i][j]) {
                sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
            }
            else {
                sum[i][j] = sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
            }
        }
    }


    cout << sum[0][0];

    return 0;
}