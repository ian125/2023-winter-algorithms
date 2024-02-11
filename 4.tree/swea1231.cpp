#include <iostream>
#include <string>
#define MAXN 10001
using namespace std;


typedef struct _Node{
    int child[2];
    char c;
}Node;

Node tree[MAXN];

void init(){
    for(int i = 0; i < MAXN; i++){
        tree[i].c = ' ';
        tree[i].child[0] = tree[i].child[1] = 0;
    }
}

void middle(int n){
    if(tree[n].child[0] != 0) middle(tree[n].child[0]);
    char c = tree[n].c;
    cout << c;
    if(tree[n].child[1] != 0) middle(tree[n].child[1]);
}

int main(){
    int T = 10;
    freopen("swea1231_input.txt","r",stdin);
    for(int t = 1; t <= T; t++){
        int n;
        cin >> n;
        init();
        for(int i = 1; i <= n; i++){
            int k, c1, c2;
            char c;
            cin >> k ;
            if(k * 2 < n){
                cin >> c >> c1 >> c2;
                tree[i].c = c;
                tree[i].child[0] = c1;
                tree[i].child[1] = c2;
            }else if(n % 2 == 0 && k == n / 2){
                cin >> c >> c1;
                tree[i].c = c;
                tree[i].child[0] = c1;
            }else {
                cin >> c;
                tree[i].c = c;
            }
        }

        cout << "#" << t << " ";
        middle(1);
        cout << endl;

    }
}
