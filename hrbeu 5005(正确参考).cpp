#include<iostream>
using namespace std;
int m, n, cnt;
char s[55][55];
int used[55][55];
int p[11][4] = {1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1};

void dfs(int x, int y){
        used[x][y] = 1;
        if(p[s[x][y] - 'A'][0]){
                if(x > 0 && !used[x - 1][y] && p[s[x - 1][y] - 'A'][2])
                        dfs(x - 1, y);
        }
        if(p[s[x][y] - 'A'][1]){
                if(y > 0 && !used[x][y - 1] && p[s[x][y - 1] - 'A'][3])
                        dfs(x, y - 1);
        }
        if(p[s[x][y] - 'A'][2]){
                if(x < m - 1 && !used[x + 1][y] && p[s[x + 1][y] - 'A'][0])
                        dfs(x + 1, y);
        }
        if(p[s[x][y] - 'A'][3]){
                if(y < n - 1 && !used[x][y + 1] && p[s[x][y + 1] - 'A'][1])
                        dfs(x, y + 1);
        }
}

int main(){
        int i, j, k, tmp;
        while(cin>>m>>n && (m != -1 || n != -1)){
                for(i = 0; i < m; i++){
                        cin>>s[i];
                }
                memset(used, 0, sizeof(used));
                cnt = 0;
                for(i = 0; i < m; i++){
                        for(j = 0; j < n; j++){
                                if(!used[i][j]){
                                        cnt++;
                                        dfs(i, j);
                                }
                        }
                }
                cout<<cnt<<endl;
        }
}
