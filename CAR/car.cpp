#include <iostream>
#include <set>

using namespace std;

const int N = 3002;
const int MOD = 1000000007;

char board[N][N];

int n;
char getField(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return '#';
    }

    return board[x][y];
}

bool isFree(int x, int y) {
    return getField(x, y) == '.';
}

long long solve(int k, set<pair<int, int>>& possibleMoves) {
    long long result = 0;

    if (k == 1) {
        result = (long long) possibleMoves.size();
    } else {
        set<pair<int, int>> nextPossibleMove = possibleMoves;
        int index = 0;

        for (auto& move : possibleMoves) {
            nextPossibleMove.erase(move);
            board[move.first][move.second] = '#';

            int i = move.first;
            int j = move.second;

            if (isFree(i + 1, j)) {
                nextPossibleMove.insert(pair<int, int>(i + 1, j));
            }

            if (isFree(i - 1, j)) {
                nextPossibleMove.insert(pair<int, int>(i - 1, j));
            }

            if (isFree(i, j + 1)) {
                nextPossibleMove.insert(pair<int, int>(i, j + 1));
            }

            if (isFree(i, j - 1)) {
                nextPossibleMove.insert(pair<int, int>(i, j - 1));
            }



            result += solve(k - 1, nextPossibleMove) - index;
            result %= MOD;



            if (isFree(i + 1, j)) {
                nextPossibleMove.erase(pair<int, int>(i + 1, j));
            }

            if (isFree(i - 1, j)) {
                nextPossibleMove.erase(pair<int, int>(i - 1, j));
            }

            if (isFree(i, j + 1)) {
                nextPossibleMove.erase(pair<int, int>(i, j + 1));
            }

            if (isFree(i, j - 1)) {
                nextPossibleMove.erase(pair<int, int>(i, j - 1));
            }

            board[move.first][move.second] = '.';
            nextPossibleMove.insert(move);
            index++;
        }
    }

    return result % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);

    int k;
    cin >> n >> k;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            cin >> board[j][i];
        }
    }

    set<pair<int, int>> possibleMoves;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == '#') {
                if (isFree(i + 1, j)) {
                    possibleMoves.insert(pair<int, int>(i + 1, j));
                }

                if (isFree(i - 1, j)) {
                    possibleMoves.insert(pair<int, int>(i - 1, j));
                }

                if (isFree(i, j + 1)) {
                    possibleMoves.insert(pair<int, int>(i, j + 1));
                }

                if (isFree(i, j - 1)) {
                    possibleMoves.insert(pair<int, int>(i, j - 1));
                }
            }
        }
    }

    cout << solve(k, possibleMoves);

    return 0;
}