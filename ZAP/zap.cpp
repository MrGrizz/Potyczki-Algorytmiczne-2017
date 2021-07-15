#include <iostream>
#include <set>
#include <map>
using namespace std;

const int N = 200100;

long long t[N];
int d[N];
int right[N];
long long left[N];

int main() {
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    set<pair<long long, int>> nextCheck;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        left[i] = t[i] - t[i - 1];
        nextCheck.insert(pair<long long, int>(left[i] ,i));
    }

    int maxD = 0;
    for (int i = 1; i <= m; i++) {
        cin >> d[i];
        maxD = max(maxD, d[i]);
    }

    long long result = 0;
    long long currentAdd = 0;
    map<int, long long> results;
    pair<long long, int> next;

    // dla każdego d
    for (int oven = 1; oven <= maxD; oven++) {
        result += currentAdd;
        results[oven] = result;

        next = *nextCheck.begin();

        while (next.first == oven) {
            nextCheck.erase(next);

            if (right[next.second] == 0) {
                right[next.second] = 1 + right[next.second - 1];

                currentAdd += right[next.second];

                if (right[next.second + 1] == 0 && next.second + 1 <= n) {
                    nextCheck.erase(pair<long long, int>(left[next.second + 1], next.second + 1));

                    int tmp = t[next.second + 1] - oven - t[next.second];


                }

            }

            next = *nextCheck.begin();
        }
    }

    return 0;
}