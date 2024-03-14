#include "Compress.hpp"

int main()
{
    // std::vector<int> w(5);
    // std::ranges::iota(w, 1);
    // Huffman h(w, w.size());
    // h.HuffmanCode();
    Compress c;
    c.huffman.HuffmanCode();
    c.begin();
    return 0;
}
