#include "Graph.hpp"

struct Tourism
{
    Graph g;
    std::optional<int> ver, edg;
    Tourism(): ver(std::nullopt), edg(std::nullopt) {}
    void Tourism_Init()
    {
        int tmp;
        std::fstream read;
        read.open("D:\\University\\DataStructure_Algorithm\\code\\Vertex.txt", std::ios::in);
        if(!(read >> tmp))
        {
            std::cout << tmp << "\n";
            std::cout << "Invalid Input\n\n";
            read.clear();
            read.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        ver.emplace(tmp);
        if(ver.has_value())
        {
            // std::cout << ver.value() << "\n";
            g.InitVertex(ver.value(), read);
        }
        read.close();
        std::cout << "Vertex Initialize\n";
        read.open("D:\\University\\DataStructure_Algorithm\\code\\Edge.txt", std::ios::in);
        if(!(read >> tmp))
        {
            std::cout << "Invalid Input\n\n";
            read.clear();
            read.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        edg.emplace(tmp);
        if(edg.has_value())
        {
            // std::cout << edg.value() << "\n";
            g.InitEdge(edg.value(), read);
        }
        read.close();
        std::cout << "Edge Initialize\n";
    }
    auto QueryInfo()
    {
        int v;
        std::cin >> v;
        return this->g.QueryInfo(v);
    }
    auto PathSearch()
    {
        std::cout << "3.PathSearch\n";
        std::cout << "START:";
        int s;
        std::cin >> s;
        return this->g.PathSearch(s);
    }
    auto ShortestPath()
    {
        int s, e;
        std::cout << "4.ShortestPath\n";
        std::cout << "START:";
        std::cin >> s;
        std::cout << "END:";
        std::cin >> e;
        return this->g.ShortestPath(s, e);
    }
    auto Plan()
    {
        return this->g.Plan();
    }
};
