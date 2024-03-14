#include "Tourism.hpp"

int main()
{
    int op;
    Tourism t;
    // std::optional<int> ver(std::nullopt), edg(std::nullopt);
    while(true)
    {
        std::cout << "SYSTEM\n";
        std::cout << "1.Init\n2.QueryInfo\n3.PathSearch\n4.ShortestPath\n5.Plan\n0.Exit\n";
        std::cout << "Operation Input:";
        std::cin >> op;
        if(op <= 0 || op > 5)
        {
            std::cout << "0.Exit\n";
            return 0;
        }
        if(op == 1)
        {
            // int tmp;
            std::cout << "1.Init\n";
            std::cout << "\n";
            t.Tourism_Init();
            if(t.ver.has_value() && t.edg.has_value())
            {
                std::cout << "Init Succeed\n";
            }
            else
            {
                std::cout << "Init Fail\n";
            }
        }
        else
        {
            if(!t.ver.has_value() || !t.edg.has_value())
            {
                std::cout << "Uninitialized\n\n";
                continue;
            }
            else
            {
                if(op == 2)
                {
                    std::cout << "2.QueryInfo\n";
                    auto out = t.QueryInfo();
                    if(out.empty())
                    {
                        std::cout << "Invalid\n";
                        continue;
                    }
                    for(auto &x : out)
                    {
                        std::cout << x.first << " " << x.second << "\n";
                    }
                }
                else if(op == 3)
                {

                    auto out = t.PathSearch();
                    if(out.empty())
                        if(out.empty())
                    {
                        std::cout << "Invalid\n";
                        continue;
                    }
                    for(auto [cnt, path] : out)
                    {
                        std::cout << "path" << " " << cnt << ": ";
                        for(auto c : path)
                        {
                            std::cout  << c << " \n"[c == path.back()];
                        }
                    }
                }
                else if(op == 4)
                {
                    auto out = t.ShortestPath();
                    std::cout << out << "\n";
                }
                else if(op == 5)
                {
                    std::cout << "5.Plan\n";
                    auto [tot,  a] = t.Plan();
                    std::cout << tot << "\n";
                    for(auto [u, v, w] : a)
                    {
                        std::cout << u << " " << v << " " << w << "\n";
                    }

                }
            }
        }
        std::cout << "\n\n";
    }
    return 0;
}