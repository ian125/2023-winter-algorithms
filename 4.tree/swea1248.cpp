#include <iostream>
#include <string>
#include <queue>
#define MAXNUM 10001
using namespace std;

typedef struct _Node{
    int key;
    int child[2];
    int parent;
    int index;
}Node;

int v, e, start[2];
int dist[MAXNUM][2];
Node tree[MAXNUM];

void init(){
    memset(dist, 0, sizeof(dist));
    for(int i = 0; i < MAXNUM; i++){
        tree[i].key = i;
        tree[i].index = 0;
        tree[i].parent = tree[i].child[0] = tree[i].child[1] = 0;
    }
}

void dfs(int n, int cnt, int idx){
    dist[n][idx] = cnt;
    if(tree[n].parent != 0)
        dfs(tree[n].parent, cnt + 1, idx);
}

int bfs(int n){
    queue<int> q;
    q.push(n);
    int cnt = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i =0; i<2; i++){
            if(tree[now].child[i]!=0){
                q.push(tree[now].child[i]);
                cnt++;
            }
        }
    } 
    return cnt;
}

int main(){
    int T;
    freopen("swea1248_input.txt","r",stdin);
    cin >> T;
    for(int t = 1; t <=T; t++){
        init();
        int ancestor, size;
        cin >> v >> e >> start[0] >> start[1];
        for(int i = 0; i < e; i++){
            int p, c;
            cin >> p >> c;
            tree[p].child[tree[p].index++] = c;
            tree[c].parent = p;
        }

        for(int i = 0; i<2; i++) dfs(start[i], 0, i);
        int maxA = 987654321, maxB=987654321;
        for(int i=1; i <= v; i++){
            if(dist[i][0]!= 0 && dist[i][1] != 0){
                if( maxA > dist[i][0] && maxB>dist[i][1]){
                    maxA = dist[i][0];
                    maxB = dist[i][1];
                    ancestor = i;
                
                }
            }
        }

        size = bfs(ancestor);

        cout << "#" << t << " " << ancestor << " " << size << endl;
    }
}