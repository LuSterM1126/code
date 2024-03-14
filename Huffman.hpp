#include <bits/stdc++.h>

struct Node
{
    int w, num;
    Node *l;
    Node *r;
    Node(int _w = 0) : w(_w), l(nullptr), r(nullptr) {}
};

struct Huffman
{
    int n;
    Node *root;
    std::vector<std::string> code;
    std::vector<Node *> forest;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    std::string arr;
    Huffman() = default;
    Huffman(std::vector<int> weight, int _n) : n(_n), forest(_n), arr(256, '0'), root(nullptr), code(_n, "")
    {
        for(int i = 0; i < n; i++)
        {
            forest[i] = new Node(weight[i]);
            forest[i]->num = i;
            q.emplace(weight[i], i);
        }
        HuffmanCreate();
    }
    void create()
    {
        for(int i = 1; i < n; i++)
        {
            int mn, mnSub, w = 0;
            mn = q.top().second;
            w += q.top().first;
            q.pop();
            mnSub = q.top().second;
            w += q.top().first;
            q.pop();
            q.emplace(w, mn);
            Node *tmp = new Node(w);
            // std::cout << forest[mn]->w << " " << forest[mnSub]->w << "\n";
            tmp->l = forest[mn];
            tmp->r = forest[mnSub];
            forest[mn] = tmp;
            forest[mnSub] = nullptr;
            if(i == n - 1)
            {
                root = tmp;
            }
        }
    }
    void HuffmanCreate()
    {
        create();
    }
    void Encode(Node *node, int len)
    {
        if(node != nullptr)
        {
            if(node->l == nullptr && node->r == nullptr)
            {
                // printf("%d ", node->w);
                // printf("%d ", node->num);
                // std::cout << len << "\n";
                code[node->num] = arr.substr(0, len);
                return;
            }
            Encode(node->l, len + 1);
            arr[len] = '1';
            Encode(node->r, len + 1);
            arr[len] = '0';
        }
    }
    void test(Node *node)
    {
        std::cout << node->w << " ";
        if(node->l != nullptr)
        {
            test(node->l);
        }
        if(node->r != nullptr)
        {
            test(node->r);
        }
    }
    void HuffmanCode()
    {
        Encode(root, 0);
        // test(root);
    }
    // ~Huffman()
    // {
    //     delete root;
    //     forest.clear();
    // }
};