#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(int n, vector<vector <int> > G){
    queue<int> q;
    vector<int> dis(n+1, -1);
    q.push(1);
    dis[1] = 0;
    while(!q.empty()){
        int now = q.front();
        for(size_t i = 0; i < G[now].size(); i++){
            if(dis[G[now][i]] == -1){//未到達のノード
                q.push(G[now][i]);
                dis[G[now][i]] = dis[now] + 1;
            }else{//到達済みのノード
                dis[G[now][i]] = min(dis[G[now][i]], dis[now]+1);
            }
        }
        q.pop();
    }
    for(int i = 1; i <= n; i++){
        cout << i << " " << dis[i] << endl;
    }
}

int main(){
    int n, u, k, v;
    cin >> n;
    vector<vector <int> > G(n+1);

    for(int i = 0; i < n; i++){
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v;
            G[u].push_back(v);
        }
    }
    bfs(n, G);
}