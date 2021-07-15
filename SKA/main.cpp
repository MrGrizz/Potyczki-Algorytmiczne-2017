#include <iostream>

using namespace std;

const int N = 250000;

int count[N];

int main() {
    ios_base::sync_with_stdio(0);

    int n, a, maxi = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;

        maxi = max(maxi, a);
        count[a]++;
    }

    int i = 0;
    int b = 0;
    while (true) {
        if (count[i] == 1) {
            b = max(b, i);

            if (b >= maxi) {
                break;
            }
        }
        else if (count[i] > 1) {
            int upgrade = count[i]/2;
            count[i + 1] += upgrade;
        } else if (b >= maxi) {
            break;
        }

        i++;
    }

    cout << b << endl;

    return 0;
}
