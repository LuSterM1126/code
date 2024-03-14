#include "Huffman.hpp"

struct Head
{
    int len;
    std::string type;
    std::vector<int> weight;
    Head(int l = 0): len(l), type(".huf"), weight(256, 0) {}
};

struct Compress
{
    Head FileHead;// 原文件信息
    Huffman huffman;
    std::vector<int> weight;
    // Compress() = default;
    Compress(const char *pFilename = "D:\\Pic.bmp") : weight(256, 0)
    {
        FILE *in = fopen(pFilename, "rb");
        int c;
        while((c = getc(in)) != EOF)
        {
            FileHead.weight[c]++;
            FileHead.len++;
        }
        huffman = Huffman(FileHead.weight, 256);
        fclose(in);
        in = nullptr;
    }
    char to_byte(std::string str)
    {
        char c = 0x00;
        for(int i = 0; i < 8; i++)
        {
            c <<= 1;
            if(str[i] == '1')
            {
                c |= 0x01;
            }
        }
        return c;
    }

    void Encode(char *pBuffer, int nSize, const char *pFilename = "D:\\Pic.bmp")
    {
        FILE *in = fopen(pFilename, "rb");
        char t[256] = {0};
        int c, pos = 0;
        while((c = getc(in)) != EOF)
        {
            strcat(t, huffman.code[c].c_str());
            while(strlen(t) >= 8)
            {
                pBuffer[pos++] = to_byte(t);
                for(int i = 0; i < 256 - 8; i++)
                {
                    t[i] = t[i + 8];
                }
            }
        }
        if(strlen(t) > 0)
        {
            pBuffer[pos++] = to_byte(t);
        }
        fclose(in);
        in = nullptr;
    }

    int WriteFile(char *pBuffer, int nSize, const char *pFilename = "D:\\Pic.bmp")
    {
        char filename[256] = {0};
        strcpy(filename, pFilename);
        strcat(filename, ".huf");
        FILE *out = fopen(filename, "wb");
        fwrite(&FileHead, sizeof(FileHead), 1, out);
        fwrite(pBuffer, sizeof(char), nSize, out);
        fclose(out);
        out = nullptr;
        std::cout << sizeof(FileHead) << "\n" << strlen(pFilename) << "\n" << nSize << "\n";
        return int(sizeof(FileHead)) + int(strlen(pFilename)) + nSize + 1;
    }

    void begin()
    {
        int siz = 0;
        for(int i = 0; i < 256; i++)
        {
            if(!FileHead.weight[i]) continue;
            siz += FileHead.weight[i] * huffman.code[i].size();
            // std::cout << FileHead.weight[i] << " " << huffman.code[i].size() << "\n";
        }
        siz = (siz + 7) / 8;
        char *pBuffer = new char[siz];
        memset(pBuffer, 0, siz * sizeof(char));
        Encode(pBuffer, siz);
        std::cout << FileHead.len << "\n";
        int len = WriteFile(pBuffer, siz);
        std::cout << len << "\n";
        std::cout << 1. * len * 100 / FileHead.len << "\n";
    }
};