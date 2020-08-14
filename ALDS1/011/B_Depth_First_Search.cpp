#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int n, vector<vector <int> > G) {
    /*タイムスタンプ*/
    int step = 0;
    vector<int> d(n+1);// vを最初に発見した発見時刻を記録
    vector<int> f(n+1);  // vの隣接リストを調べ終えた完了時刻を記録
    stack<int> S;

    for(int i = 1; i <= n; i++) {
        if(d[i] == 0){
            d[i] = ++step;
            S.push(i);
        }

        while (!S.empty()) {
            int v = S.top();
            if (G[v].size() == 0) {//その点からの辺が存在しない
                S.pop();
                f[v] = ++step;
            } else {
                int achivedVertex = 0;
                for (size_t j = 0; j < G[v].size(); j++) {
                    if (d[G[v][j]] == 0) {//その点に初到達
                        d[G[v][j]] = ++step;
                        S.push(G[v][j]);
                        break;
                    } else {
                        achivedVertex++;
                    }
                }
                if (achivedVertex == G[v].size()) {//現在の点からの辺はすべて到達済み
                    S.pop();
                    f[v] = ++step;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
}

void print_AdjacencyList(vector<vector <int> > G) {
    for (size_t i = 0; i < G.size(); i++) {
        for (size_t j = 0; j < G[i].size(); j++) {
            cout << G[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, u, k, v;
    cin >> n;
    vector<vector <int> > G(n+1);

    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v;
            G[u].push_back(v);
        }
    }
    //print_AdjacencyList(G);

    dfs(n, G);
}