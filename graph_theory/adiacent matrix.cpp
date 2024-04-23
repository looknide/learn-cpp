#include "iostream"
#include<vector>

using namespace std;

int m,n;
vector<bool>vis;//是否遍历过该节点
vector<vector<bool>>adj;//邻接矩阵,表示两节点之间是否有边

bool if_edge(int u,int v){//判断两节点之间是否有边
    return adj[u][v];
}

void dfs(int u){//深度优先搜索
    if(vis[u]){return;}//如果已经遍历过该节点，直接返回
    else{
        vis[u]=true;//标记该节点已经遍历过
        for(int v=1;v<=n;v++){//遍历所有节点
            if(if_edge(u,v)){//如果两节点之间有边
                dfs(v);//递归遍历
            }
        }
    }
}

int main(){
    cin>>n>>m;
    vis.resize(n+1,false);//初始化
    adj.resize(n+1,vector<bool>(n+1,false));
    for(int i=1;i<=m;i++){//输入边
        int u,v;
        cin>>u>>v;
        adj[u][v]=true;//两点之间有边
    }
    return 0;
}