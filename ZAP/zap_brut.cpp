#include <iostream>

using namespace std;

const int N = 200100;

long long t[N];
int d[N];

int main() {
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> d[i];
    }

    for (int i = 1; i <= m; i++) {
        long long result = 0;
        long long maxLeft = 0;

        for (int j = 1; j <= n; j++) {
            // wyrobimy sie
            if (t[j] - maxLeft >= d[i]) {
                maxLeft = t[j];
            }
            // nie wyrobimy sie, ale mozemy zaczac wczesniej
            else if (t[j] - maxLeft > 0) {
                long long tmp = t[j] - maxLeft;
                tmp = d[i] - tmp;

                result += tmp;
                maxLeft = t[j] + tmp;
            }
            // nie wyrobimy sie, musimy czekac az poprzedni skonczy
            else {
                long long tmp = maxLeft - t[j] + d[i];

                result += tmp;
                maxLeft = t[j] + tmp;
            }
        }

        cout << result << "\n";
    }

    return 0;
}