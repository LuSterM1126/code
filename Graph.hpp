#include <bits/stdc++.h>

struct DSU
{
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int find(int x) 
    {
        //return x == f[x] ? x : find(f[x]);
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) 
    {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

struct Graph
{
    int Vex, Edg;
    int inf = 0x3f3f3f3f;
    std::vector<std::pair<std::string, std::string>> des;
    std::vector<std::vector<std::pair<int, int>>> adj;
    Graph() = default;
    void operator = (const Graph &_g)
    {
        Vex = _g.Vex;
        Edg = _g.Edg;
        des = _g.des;
        adj = _g.adj;
    }
    void InitVertex(int _Vex, std::fstream &read)
    {
        Vex = _Vex;
        des.resize(_Vex);
        adj.resize(_Vex);
        for(int i = 0; i < Vex; i++)
        {
            int id;
            std::string name, d;
            read >> id >> name >> d;
            des[id] = {name, d};
        }
    }
    void InitEdge(int _Edg, std::fstream &read)
    {
        Edg = _Edg;
        for(int i = 0; i < Edg; i++)
        {
            int u, v, w;
            read >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
    }
    auto QueryInfo(int u)
    {
        std::vector<std::pair<std::string, std::string>> out;
        for(auto v : adj[u])
        {
            out.push_back({des[v.first].first, des[v.first].second});
        }
        return out;
    }
    auto PathSearch(int s)
    {
        std::vector<int> vis(Vex, 0);
        std::vector<std::pair<int, std::string>> out;
        vis[s] = 1;
        int cnt = 1;
        auto dfs = [&](auto self, int u, std::string str) -> void
        {
            bool f = 1;
            for(int i = 0; i < Vex; i++)
            {
                f &= vis[i];
            }
            if(f)
            {
                out.push_back({cnt++, str});
                return;
            }
            for(auto [v, w] : adj[u])
            {
                if(!vis[v])
                {
                    vis[v] = 1;
                    str.push_back(v + '0');
                    self(self, v, str);
                    str.pop_back();
                    vis[v] = 0;
                }
            }
        };
        dfs(dfs, s, std::string(1, s + '0'));
        // for(auto str : ans)
        // {
        //     std::cout << "Path" << cnt++ << ":";
        //     for(auto c : str)
        //     {
        //         std::cout << c << " ";
        //     }
        //     std::cout << "\n";
        // }
        return out;
    }
    auto ShortestPath(int s, int e)
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        std::vector<int> vis(Vex);
        std::vector<int> dis(Vex, inf);
        std::vector<int> pre(Vex);
        std::ranges::iota(pre, 0);
        dis[s] = 0;
        pq.emplace(0, s);
        while(!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(auto [v, dw] : adj[u])
            {
                if(vis[v]) continue;
                if(dis[v] > dis[u] + dw)
                {
                    pre[v] = u;
                    dis[v] = dis[u] + dw;
                    pq.emplace(dis[v], v);
                }
            }
        }
        auto dfs = [&](auto self, int u) -> void
        {
            if(u == s)
            {
                std::cout << s << " ";
                return;
            }
            self(self, pre[u]);
            std::cout << u << " ";
        };
        dfs(dfs, e);
        std::cout << "\n";
        // std::cout << dis[e] << "\n";
        return dis[e];
    }
    std::pair<int, std::vector<std::array<int, 3>>> Plan()
    {
        int tot = 0;
        DSU d(Vex);
        std::vector<std::array<int, 3>> ans;
        std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
        for(int u = 0; u < Vex; u++)
        {
            if(adj[u].empty()) continue;
            for(auto [v, w] : adj[u])
            {
                pq.push({w, u, v});
            }
        }
        while(!pq.empty())
        {
            auto [w, u, v] = pq.top();
            pq.pop();
            if(d.same(u, v)) continue;
            tot += w;
            d.merge(u, v);
            ans.push_back({u, v, w});
        }
        // for(auto [u, v, w] : ans)
        // {
        //     std::cout << u << " " << v << " " << w << "\n";
        // }
        // std::cout << tot << "\n";
        return {tot, ans};
    }
};