// https://codeforces.com/problemset/problem/893/C

#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

queue<int> ok;
const int N=100007;
unsigned int gold[N];
bool vis[N];
vector<int> v[N];
int n,m;

int main(){
    
    unsigned long long int sum=0;

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",gold+i);
    for(int i=1;i<=m;++i){
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;++i)
        ok.push(i);

    while(!ok.empty()){
        
        queue<int> bfs;
        int a=ok.front();
        ok.pop();
        if(vis[a]) 
            continue;
        bfs.push(a);
        vis[a]=1;
        unsigned long long int min=gold[a];

        while(!bfs.empty()){
            int tmp=bfs.front();
            bfs.pop();

            for(int i=0;i<v[tmp].size();++i){
                if(vis[ v[tmp][i] ])
                    continue;
                bfs.push(v[tmp][i]);
                vis[ v[tmp][i] ]=1;
                if(gold[ v[tmp][i] ]<min)
                    min=gold[ v[tmp][i] ];
            }
        }
        sum+=min;
        

    }
    printf("%llu",sum);
  

}