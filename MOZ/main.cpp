#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2002;

int x[N];
int y[N];
int resultX[N];
int resultY[N];
int result[N];
pair<pair<int, int>, int> sorted[N];
int n;

int main() {
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t --> 0) {
        cin >> n;

        for (int i = 0; i <= n; i++) {
            resultX[i] = 0;
            resultY[i] = 0;
            result[i] = 0;
        }

        int minX = 1000000001;
        int minY = 1000000001;

        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
            sorted[i].first.first = x[i];
            sorted[i].first.second = y[i];
            sorted[i].second = i;

            minX = min(minX, x[i]);
            minY = min(minY, y[i]);
        }

        sort(sorted, sorted + n);

        if (sorted[0].first.first != minX || sorted[0].first.second != minY) {
            cout << "NIE\n";
            continue;
        }

        for (int i = 0; i < n - 1; i++) {
            int nr = sorted[i].second;
            int curX = sorted[i].first.first;
            int curY = sorted[i].first.second;

            int nextX = sorted[i + 1].first.first;
            int nextY = sorted[i + 1].first.second;

            if (curX == nextX) {
                resultY[nr] = nextY - curY;
            }
        }

        for (int i = 0; i < n; i++) {
            int tmp = sorted[i].first.first;
            sorted[i].first.first = sorted[i].first.second;
            sorted[i].first.second = tmp;
        }

        sort(sorted, sorted + n);

        for (int i = 0; i < n - 1; i++) {
            int nr = sorted[i].second;
            int curY = sorted[i].first.first;
            int curX = sorted[i].first.second;

            int nextY = sorted[i + 1].first.first;
            int nextX = sorted[i + 1].first.second;

            if (curY == nextY) {
                resultX[nr] = nextX - curX;
            }
        }

        vector<int> zeros;

        bool end = false;
        for (int i = 0; i < n; i++) {
            if (resultX[i] != 0 && resultY[i] == 0) {
                result[i] = resultX[i];
            }
            else if (resultY[i] != 0 && resultX[i] == 0) {
                result[i] = resultY[i];
            } else if (resultY[i] != 0 && resultX[i] != 0) {
                if (resultY[i] == resultX[i]) {
                    result[i] = resultX[i];
                }
                else {
                    cout << "NIE\n";
                    end = true;
                    break;
                }
            } else {
                zeros.push_back(i);
            }
        }

        if (end) {
            continue;
        }

        int maxY = 0;
        int maxX = 0;

        for (int i = 0; i < n; i++) {
            maxX = max(maxX, x[i] + result[i]);
            maxY = max(maxY, y[i] + result[i]);
        }

        if (zeros.size() == 1) {
            int nr = zeros[0];

            if (maxX == x[nr] && maxY == y[nr]) {
                if (n > 1) {
                    cout << "NIE\n";
                    continue;
                } else {
                    maxX = 1;
                    maxY = 1;
                    result[nr] = 1;
                }
            } else if (maxX - x[nr] == maxY - y[nr]) {
                if (maxX - x[nr] > 0) {
                    result[nr] = maxX - x[nr];
                }
                else {
                    cout << "NIE\n";
                    continue;
                }
            }
            else if (minX == x[nr] && y[nr] == maxY) {
                result[nr] = maxX - x[nr];
                maxY = result[nr] + y[nr];
            }
            else if (minY == y[nr] && x[nr] == maxX) {
                result[nr] = maxY - y[nr];
                maxX = result[nr] + x[nr];
            }
            else {
                cout << "NIE\n";
                continue;
            }

        } else if (zeros.size() == 2) {
            int nr1 = zeros[0];
            int nr2 = zeros[1];

            if (y[nr1] == maxY && x[nr2] == maxX) {
                result[nr2] = maxY - y[nr2];
                result[nr1] = maxX - x[nr1] + result[nr2];

                maxX = x[nr2] + result[nr2];
                maxY = y[nr1] + result[nr1];
            }
            else if (y[nr2] == maxY && x[nr1] == maxX) {
                result[nr1] = maxY - y[nr1];
                result[nr2] = maxX - x[nr2] + result[nr1];

                maxX = x[nr1] + result[nr1];
                maxY = y[nr2] + result[nr2];
            }
            else {
                cout << "NIE\n";
                continue;
            }

        } else if (zeros.size() > 2) {
            cout << "NIE\n";
            continue;
        }

        long long check1 = ((long long)(maxX - minX))*((long long)(maxY - minY));
        long long check2 = 0;

        for (int i = 0; i < n; i++) {
            check2 += ((long long) result[i])*((long long) result[i]);
        }

        if (check1 == check2) {
            cout << "TAK ";

            for (int i = 0; i < n; i++) {
                cout << result[i] << " ";
            }

            cout << "\n";

        } else {
            cout << "NIE\n";
        }

    }


    return 0;
}