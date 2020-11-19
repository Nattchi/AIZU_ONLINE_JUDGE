#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

// Union-Find
struct UnionFind {
    vector<int> par, siz;

    // 初期化
    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    // 根を求める
    int root(int x) {
        if (par[x] == -1) return x; // x が根の場合は x を返す
        else return par[x] = root(par[x]);
    }

    // x と y が同じグループに属するかどうか (根が一致するかどうか)
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループとを併合する
    bool unite(int x, int y) {
        // x, y をそれぞれ根まで移動する
        x = root(x);
        y = root(y);

        // すでに同じグループのときは何もしない
        if (x == y) return false;

        // union by size (y 側のサイズが小さくなるようにする)
        if (siz[x] < siz[y]) swap(x, y);

        // y を x の子とする
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // x を含むグループのサイズ
    int size(int x) {
        return siz[root(x)];
    }
};

using Edge = pair<int, pair<int, int> >;

int main() {
    int n;
    cin >> n;
    vector<Edge> edges;
    vector<vector<int> > a(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] != -1){
                edges.push_back(make_pair(a[i][j], make_pair(i, j)));
            }
        }
    }
    sort(edges.begin(), edges.end());

    long long ans = 0;
    UnionFind uf(n); // {0}, {1}, {2}, {3}, ..., {n-1}

    for(size_t i = 0; i < edges.size(); i++){
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        // 辺の追加により、サイクル形成される場合
        if(uf.issame(u, v)) continue;

        // 辺(u, v) を追加する
        ans += w;
        uf.unite(u, v);
    }
    cout << ans << endl;
}