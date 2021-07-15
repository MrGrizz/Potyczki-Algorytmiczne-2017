#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int N = 100004;

long long z[N];
bool visited[N];
long long totalCost[N];
vector<int> tree[N];
vector<long long> cost[N];

int main() {
    ios_base::sync_with_stdio(0);

    int n, q;

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> z[i];
    }

    int a, b;
    long long c;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;

        tree[a].push_back(b);
        tree[b].push_back(a);

        cost[b].push_back(c);
        cost[a].push_back(c);
    }

    int type;
    long long v, d;
    int city = 1;
    while (q --> 0) {
        cin >> type;

        if (type == 1) {
            cin >> v >> d;

            z[v] = d;
        } else {
            cin >> a >> b >> d;

            for (int i = 0; i < tree[a].size(); i++) {
                if (tree[a][i] == b) {
                    cost[a][i] = d;
                    break;
                }
            }

            for (int i = 0; i < tree[b].size(); i++) {
                if (tree[b][i] == a) {
                    cost[b][i] = d;
                    break;
                }
            }
        }

        for (int i = 0; i <= n; i++) {
            visited[i] = 0;
        }

        queue<int> Q;
        Q.push(city);

        long long maxx = LLONG_MIN;
        int newCity = -1;
        totalCost[city] = 0;

        while (!Q.empty()) {
            int tmp = Q.front();
            Q.pop();
            visited[tmp] = 1;

            for (int i = 0; i < tree[tmp].size(); i++) {
                if (visited[tree[tmp][i]] == 0) {
                    Q.push(tree[tmp][i]);

                    totalCost[tree[tmp][i]] = totalCost[tmp] + cost[tmp][i];
                }
            }
        }

        bool isFirst = true;
        for (int i = 1; i <= n; i++) {
            if (i != city) {
                if (isFirst || z[i] - totalCost[i] > maxx) {
                    maxx = z[i] - totalCost[i];
                    newCity = i;
                    isFirst = false;
                }
            }
        }

        cout << newCity << " ";

        city = newCity;

    }

    return 0;
}