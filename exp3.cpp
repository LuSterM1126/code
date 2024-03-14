// 1
// #include <bits/stdc++.h>
// using i64 = long long;

// int main()
// {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n), b(n);
//     for(int i = 0; i < n; i++)
//     {
//         std::cin >> a[i];
//     }
//     for(int i = 0; i < n; i++)
//     {
//         std::cin >> b[i];
//     }
//     std::function<void (std::vector<int>, std::vector<int>)> dfs = [&](std::vector<int> m, std::vector<int> p)
//     {
//         if(m.size() > 0 && p.size() > 0)
//         {
//             std::cout << " " << p.back();
//             int index = std::find(m.begin(), m.end(), p.back()) - m.begin();
//             dfs(std::vector<int>(m.begin(), m.begin() + index), std::vector<int>(p.begin(), p.begin() + index));
//             dfs(std::vector<int>(m.begin() + index + 1, m.end()), std::vector<int>(p.begin() + index, p.begin() + p.size() - 1));
//         }
//     };
//     std::cout << "Preorder:";
//     dfs(b, a);
// }

// 2
//  #include <bits/stdc++.h>
//  using i64 = long long;

// int main()
// {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n + 1),tree(n + 1);
//     for(int i = 1; i <= n; i++)
//     {
//         std::cin >> a[i];
//     }
//     int cnt = 1;
//     auto dfs = [&](auto self, int t) -> void
//     {
//         if(t <= n)
//         {
//             self(self, t * 2);
//             self(self, t * 2 + 1);
//             tree[t] = a[cnt++];
//         }
//     };

//     dfs(dfs, 1);
//     std::cout << tree[1];
//     for(int i = 2; i <= n; i++)
//     {
//         std::cout << " " << tree[i];
//     }

//     return 0;
// }

// 3
//  #include <bits/stdc++.h>
//  using i64 = long long;
//  constexpr int inf = 0x3f3f3f3f;

// int main()
// {
//     int n, m;
//     std::cin >> n >> m;
//     std::queue<int> q;
//     std::vector dis(n, std::vector<int>(n, inf));
//     std::vector<int> in(n, 0);
//     for(int i = 0; i < m; i++)
//     {
//         int u, v, w;
//         std::cin >> u >> v >> w;
//         dis[u][v] = w;
//         in[v]++;
//     }
//     int cnt = 0;
//     std::vector<int> time(n, 0);
//     for(int i = 0; i < n; i++)
//     {
//         if(!in[i]) q.push(i);
//     }
//     while(!q.empty())
//     {
//         cnt++;
//         int u = q.front();
//         q.pop();
//         for(int v = 0; v < n; v++)
//         {
//             if(dis[u][v] != inf)
//             {
//                 in[v]--;
//                 time[v] = std::max(time[v], time[u] + dis[u][v]);
//                 if(!in[v]) q.push(v);
//             }
//         }
//     }
//     if(cnt == n) std::cout << *std::max_element(time.begin(), time.end());
//     else std::cout << "Impossible";
//     return 0;
// }

// 4
// #include <bits/stdc++.h>
// using i64 = long long;
// constexpr int inf = 0x3f3f3f3f;

// struct edge
// {
//     int f, t, w, v;
//     edge(int a, int b, int c, int d) : f(a), t(b), w(c), v(d) {}
// };

// struct node
// {
//     int id, w, v;
//     node(int a, int b, int c) : id(a), w(b), v(c) {}
// };

// int main()
// {
//     int n, m, s, d;
//     std::cin >> n >> m >> s >> d;
//     auto cmp = [&](auto x, auto y) -> bool
//     {
//         return (x.w == y.w ? x.w < y.w : x.v < y.v);
//     };
//     std::priority_queue<node, std::vector<node>, decltype(cmp)> q(cmp);
//     std::vector<std::vector<edge>> adj(n);
//     std::vector<int> dis(n, inf);
//     std::vector<int> val(n, inf);
//     for(int i = 0; i < m; i++)
//     {
//         int u, v, w, t;
//         std::cin >> u >> v >> w >> t;
//         adj[u].push_back(edge(u, v, w, t));
//         adj[v].push_back(edge(v, u, w, t));
//     }
//     dis[s] = 0, val[s] = 0;
//     q.push(node(s, 0, 0));
//     while(!q.empty())
//     {
//         node u = q.top();
//         q.pop();
//         // if(vis[u.id]) continue;
//         // vis[u.id] = 1;
//         for(int i = 0; i < adj[u.id].size(); i++)
//         {
//             edge e = adj[u.id][i];
//             // if(vis[e.t]) continue;
//             if(dis[e.t] > dis[u.id] + e.w) // 仅距离更新时入队
//             {
//                 dis[e.t] = dis[u.id] + e.w;
//                 val[e.t] = val[u.id] + e.v;
//                 q.push(node(e.t, dis[e.t], val[e.t]));
//             }
//             else if(dis[e.t] == dis[u.id] + e.w && val[e.t] > val[u.id] + e.v)
//             {
//                 val[e.t] = val[u.id] + e.v;
//             }
//         }
//     }
//     std::cout << dis[d] << " " << val[d];
//     return 0;
// }

// 多权值不能使用 vis[] 数组，按单一边权排序会影响其他权值的大小关系
// vis[] 数组仅针对单一边权值有效

// 最短路 - 迪杰斯特拉
// #include <bits/stdc++.h>
// using i64 = long long;
// constexpr int inf = 0x3f3f3f3f;

// struct edge
// {
//     int f, t, w, v;
//     edge(int a, int b, int c, int d): f(a), t(b), w(c), v(d) {}
// };

// struct node
// {
//     int id, w, v;
//     node(int a, int b, int c): id(a), w(b), v(c) {}
// };

// int main()
// {
//     int n, m, s, d;
//     std::cin >> n >> m >> s >> d;
//     auto cmp = [&](auto x, auto y) -> bool
//     {
//         return (x.w == y.w ? x.w < y.w : x.v < y.v);
//     };
//     std::priority_queue<node, std::vector<node>, decltype(cmp)> q(cmp);
//     std::vector<std::vector<edge>> adj(n);
//     std::vector<int> vis(n, 0);
//     std::vector<int> dis(n, inf);
//     std::vector<int> val(n, inf);
//     for(int i = 0; i < m; i++)
//     {
//         int u, v, w, t;
//         std::cin >> u >> v >> w >> t;
//         adj[u].push_back(edge(u, v, w, t));
//         adj[v].push_back(edge(v, u, w, t));
//     }
//     dis[s] = 0, val[s] = 0;
//     q.push(node(s, 0, 0));
//     while(!q.empty())
//     {
//         node u = q.top();
//         q.pop();
//         if(vis[u.id]) continue;
//         vis[u.id] = 1;
//         for(int i = 0; i < adj[u.id].size(); i++)
//         {
//             edge e = adj[u.id][i];
//             if(vis[e.t]) continue;
//             if(dis[e.t] > dis[u.id] + e.w)
//             {
//                 dis[e.t] = dis[u.id] + e.w;
//                 q.push(node(e.t, dis[e.t], val[e.t]));
//             }
//         }
//     }
//     for(int i = 0; i < n; i++)
//     {
//         std::cout << i << " " << dis[i] << "\n";
//     }
//     return 0;
// }


// #include<iostream>
// using namespace std;

// #define MAXCITY 5
// #define MAXNUM 10

// //采用邻接矩阵来存储和表示自驾旅游路线图
// int main()
// {
// 	int G[MAXCITY][MAXCITY][2];//0 为长度，1 为费用
// 	int N, M, S, D;//城市个数，高速条数，出发编号，到达编号
// 	cin >> N >> M >> S >> D;
// 	for (int i = 0; i < N; i++)
// 	{
// 		for (int j = 0; j < N; j++)
// 		{
// 			G[i][j][0] = MAXNUM;
// 			G[i][j][1] = MAXNUM;
// 		}
// 	}
// 	int v1, v2, distance, fee;//起点终点距离费用
// 	for (int i = 0; i < M; i++)
// 	{
// 		cin >> v1 >> v2 >> distance >> fee;
// 		G[v1][v2][0] = G[v2][v1][0] = distance;
// 		G[v1][v2][1] = G[v2][v1][1] = fee;
// 	}
// 	//Floyd 算法，通过 path 存储中转点
// 	int P[MAXCITY][MAXCITY] = { -1 };
// 	for (int k = 0; k < N; k++)//每轮增加一个中转点，有 N 个点有 N 轮
// 	{
// 		for (int i = 0; i < N; i++)
// 		{
// 			for (int j = i; j < N; j++)
// 			{
// 				if (G[i][j][0] > G[i][k][0] + G[k][j][0])
// 				{
// 					G[i][j][0] = G[i][k][0] + G[k][j][0];
// 					G[i][j][1]= G[i][k][1] + G[k][j][1];
// 					P[i][j] = k;
// 				}
// 				else if (G[i][j][0] == G[i][k][0] + G[k][j][0])
// 				{
// 					if(G[i][j][1] >= G[i][k][1] + G[k][j][1])
// 						G[i][j][1] = G[i][k][1] + G[k][j][1];
// 					P[i][j] = k;
// 				}
// 			}
// 		}
// 	}

// 	cout << G[S][D][0] << " " << G[S][D][1];

// 	system("pause");
// 	return 0;
// }

// #include <iostream>
// #define MaxInt int(1e9)
// using namespace std;
// class highway
// {
// public:
//     int from;   // 起点
//     int to;     // 终点
//     int length; // 长度
//     int fare;   // 收费
// };
// class AMGraph
// {
// public:
//     int n; // 顶点总数
//     highway *arcs[510];
//     AMGraph(int n) : n(n)
//     {
//         for (int i = 0; i < 510; i++)
//             arcs[i] = new highway[510];
//         for (int i = 0; i < 510; i++)
//         {
//             for (int j = 0; j < 510; j++)
//             {
//                 arcs[i][j].length = MaxInt;
//                 arcs[i][j].fare = MaxInt;
//             }
//         }
//     }
// };
// void Floyd(AMGraph &G, int n)
// {
//     for (int k = 0; k < n; k++)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (G.arcs[i][j].length > G.arcs[i][k].length + G.arcs[k][j].length)
//                 {
//                     G.arcs[i][j].length = G.arcs[i][k].length + G.arcs[k][j].length;
//                     G.arcs[i][j].fare = G.arcs[i][k].fare + G.arcs[k][j].fare;
//                 }
//                 else if ((G.arcs[i][j].length == G.arcs[i][k].length + G.arcs[k][j].length))
//                 {
//                     if(G.arcs[i][j].fare > G.arcs[i][k].fare + G.arcs[k][j].fare)
//                     {
//                         G.arcs[i][j].fare = G.arcs[i][k].fare + G.arcs[k][j].fare;
//                     }
//                 }
//             }
//         }
//     }
// }
// int main()
// {
//     int N, M, S, D;
//     cin >> N >> M >> S >> D;
//     AMGraph G(N);
//     for (int i = 0; i < M; i++)
//     {
//         int from, to, length, fare;
//         cin >> from >> to >> length >> fare;
//         G.arcs[from][to].length = length;
//         G.arcs[to][from].length = length;
//         G.arcs[from][to].fare = fare;
//         G.arcs[to][from].fare = fare;
//     }
//     Floyd(G, N);
//     cout << G.arcs[S][D].length << " " << G.arcs[S][D].fare;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// #define MAXSIZE 100
// class SqStack
// {
// public:
//     int *base;
//     int *top;
//     int stacksize;
//     SqStack();
//     void Push(int e);
//     void Pop(int &e);
// };
// SqStack::SqStack()
// {
//     this->base = new int[MAXSIZE];
//     if (!this->base)
//         exit(0);
//     this->top = this->base;
//     this->stacksize = MAXSIZE;
// }
// void SqStack::Push(int e)
// {
//     if ((this->top - this->base) >= this->stacksize)
//         exit(0);
//     *top = e;
//     top++;
// }
// void SqStack::Pop(int &e)
// {
//     if (base == top)
//         exit(0);
//     top--;
//     e = *top;
// }
// class arcnode
// {
// public:
//     int adjvex; // 弧指向的顶点序号
//     int time;   // 弧持续时间
//     arcnode *nextarc;
//     arcnode(int a, int t)
//     {
//         nextarc = NULL;
//         adjvex = a;
//         time = t;
//     }
//     // arcnode() = default;
// };
// class vnode
// {
// public:
//     int num;
//     int ve; // 顶点的最早开始时间
//     int in; // 入度
//     arcnode *firstarc;
//     vnode()
//     {
//         num = 0;
//         ve = 0;
//         in = 0;
//         firstarc = NULL;
//     }
// };
// class ALGraph
// {
// public:
//     int vexnum, arcnum;
//     vnode *v;
//     ALGraph(int n, int m)
//     {
//         vexnum = n;
//         arcnum = m;
//         v = new vnode[vexnum];
//         for (int i = 0; i < m; i++)
//         {
//             int a, b, c;
//             cin >> a >> b >> c;
//             arcnode *t = new arcnode(b, c);
//             arcnode *p = v[a].firstarc;
//             if (p == NULL)
//             {
//                 v[a].firstarc = t;
//             }
//             else
//             {
//                 while (p->nextarc != nullptr)
//                     p = p->nextarc;
//                 p->nextarc = t;
//             }
//             v[b].in++;
//         }
//         v[0].ve = 0;
//     }
//     // ALGraph() = default;
// };
// void getearliesttime(ALGraph &G)
// {
//     SqStack S;
//     int count = 0; // 记录出栈的结点数，若最终小于结点总数，说明形成了环
//     for (int i = 0; i < G.vexnum; i++)
//     {
//         if (G.v[i].in == 0)
//             S.Push(i);
//     }
//     while (S.top != S.base)
//     {
//         int e;
//         S.Pop(e);
//         count++;
//         arcnode *p = G.v[e].firstarc;
//         while (p != NULL)
//         {
//             G.v[p->adjvex].in--;
//             if (G.v[p->adjvex].in == 0)
//                 S.Push(p->adjvex);
//             G.v[p->adjvex].ve = std::max(G.v[e].ve + p->time, G.v[p->adjvex].ve);
//             p = p->nextarc;
//         }
//     }
//     int ans = -1;
//     if (count < G.vexnum)
//         cout << "Impossible";
//     else
//     // cout << G.v[G.vexnum - 1].ve;
//     {
//         for (int i = 0; i < G.vexnum; i++)
//         {
//             ans = std::max(ans, G.v[i].ve);
//         }
//         std::cout << ans;
//     }
//     return;
// }
// int main()
// {
//     int N, M;
//     cin >> N >> M;
//     ALGraph G(N, M);
//     getearliesttime(G);
//     return 0;
// }





// #include <bits/stdc++.h>

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);

//     int n, e;
//     std::cin >> n >> e;
//     std::vector<std::vector<int>> adj(n);
//     for (int i = 0; i < e; i++)
//     {
//         int u, v;
//         std::cin >> u >> v;
//         adj[u].emplace_back(v);
//         adj[v].emplace_back(u);
//     }
//     std::vector<int> vis(n, 0);
//     std::vector<std::string> ans;
//     auto dfs = [&](auto self, int u, std::string str) -> void
//     {
//         bool f = 1;
//         for (int i = 0; i < n; i++)
//         {
//             f &= vis[i];
//         }
//         if (f)
//         {
//             ans.push_back(str);
//             return;
//         }
//         for (auto v : adj[u])
//         {
//             if (!vis[v])
//             {
//                 vis[v] = 1;
//                 str.push_back(v + '0');
//                 self(self, v, str);
//                 str.pop_back();
//                 vis[v] = 0;
//             }
//         }
//     };
//     vis[2] = 1;
//     dfs(dfs, 2, "2");
//     for (auto s : ans)
//     {
//         std::cout << s << "\n";
//     }
//     return 0;
// }





#include <bits/stdc++.h>
using i64 = long long;
// constexpr int mod = 998244353;
// constexpr i64 MOD = 1e9 + 7;
// constexpr int inf = 0x3f3f3f3f;
// constexpr i64 INF = 0x3f3f3f3f3f3f3f3f;

struct DSU
{
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int find(int x)
    {
        // return x == f[x] ? x : find(f[x]);
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

int main()
{
    int n, e;
    std::cin >> n >> e;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    int tot = 0;
    DSU d(n);
    std::vector<std::array<int, 3>> ans;
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
    for (int u = 0; u < n; u++)
    {
        if (adj[u].empty())
            continue;
        for (auto [v, w] : adj[u])
        {
            pq.push({w, u, v});
        }
    }
    while (!pq.empty())
    {
        auto [w, u, v] = pq.top();
        pq.pop();
        // std::cout << w << " " << u << " " << v << "\n"; 
        if (d.find(u) == d.find(v))
            continue;
        tot += w;
        d.merge(u, v);
        ans.push_back({u, v, w});
    }
    for (auto [u, v, w] : ans)
    {
        std::cout << u << " " << v << " " << w << "\n";
    }
    std::cout << tot << "\n";
    return 0;
}