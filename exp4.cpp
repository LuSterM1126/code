// #include<bits/stdc++.h>

// int main()
// {
//     int n;
//     std::cin >> n;
//     std::vector<int> a(n);
//     for(int i = 0; i < n; i++)
//     {
//         std::cin >> a[i];
//     }
//     std::sort(a.begin(), a.end());
//     for(int i = 0; i < n; i++)
//     {
//         std::cout << a[i];
//         if(i != n - 1) std::cout << " ";
//     }
// }

// #include <bits/stdc++.h>

// int main()
// {
//     int n;
//     std::priority_queue<int, std::vector<int>, std::greater<>> p;
//     std::cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         int t;
//         std::cin >> t;
//         p.push(t);
//     }
//     for(int i = 0; i < n; i++)
//     {
//         std::cout << p.top();
//         p.pop();
//         std::cout << (i == n - 1 ? "" : " ");
//     }
//     return 0;
// }

// #include <bits/stdc++.h>

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);

//     int m, n;
//     std::cin >> m >> n;
//     auto check = [&](int t)
//     {
//         if (t == 1)
//             return false;
//         for (int i = 2; i * i <= t; i++)
//         {
//             if (t % i == 0)
//                 return false;
//         }
//         return true;
//     };
//     if (!check(m))
//     {
//         for (int i = m;; i++)
//         {
//             if (check(i))
//             {
//                 m = i;
//                 break;
//             }
//         }
//     }
//     std::vector<int> a(n), ans(n), vis(m, 0);
//     for (int i = 0; i < n; i++)
//     {
//         std::cin >> a[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         int k = a[i] % m;
//         int t = k, j;
//         for (j = 0; j < m; j++)
//         {
//             k = t + j * j;
//             if (!vis[k % m])
//             {
//                 vis[k % m] = 1;
//                 ans[i] = k % m;
//                 break;
//             }
//         }
//         if (j == m)
//         {
//             ans[i] = -1;
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (ans[i] == -1)
//             std::cout << "-";
//         else
//             std::cout << ans[i];
//         if (i != n - 1)
//             std::cout << " ";
//     }
//     return 0;
// }

#include <iostream>

template <class T>
struct RecordType
{
    T key;
    bool operator<(const RecordType<T> &rec) const
    {
        return this->key < rec.key;
    }
    bool operator>(const RecordType<T> &rec) const
    {
        return this->key > rec.key;
    }
    bool operator==(const RecordType<T> &rec) const
    {
        return this->key == rec.key;
    }
    RecordType<T> &operator=(const RecordType<T> &rec)
    {
        if (this == &rec)
            return *this;
        this->key = rec.key;
        return *this;
    }
};
template <class T>
class ListToSort
{
private:
    RecordType<T> *r;
    int length;
    int size;

public:
    explicit ListToSort(int size) : size(size), length(0), r(new RecordType<T>[size]) {}
    ~ListToSort()
    {
        delete[] r;
    }
    ListToSort<T> &operator=(const ListToSort<T> &list)
    {
        if (this == &list)
        {
            return *this;
        }
        this->length = list.length;
        this->size = list.size;
        for (int i = 0; i < length; i++)
        {
            this->r[i] = list.r[i];
        }
        return *this;
    }
    int directInsertSort(const RecordType<T> &rec)
    {
        int i = length - 1;
        while (rec < r[i] && i != -1)
        {
            r[i + 1] = r[i];
            i--;
        }
        r[i + 1] = rec;
        length++;
        return i + 1;
    }
    int binaryInsertSort(const RecordType<T> &rec)
    {
        int low = 0, high = length - 1;
        int mid;
        // 当 length 等于 0 时，不会循环
        while (low <= high)
        { // 在 low 等于 high 时，说明 low<=mid<=high，low 再循环一次加一，保持排序的稳定性
            mid = (low + high) / 2;
            if (rec < r[mid])
                high = mid - 1;
            else if (rec > r[mid] || rec == r[mid])
                low = mid + 1;
        }
        for (int i = length; i > low; i--)
        {
            r[i] = r[i - 1];
        }
        r[low] = rec;
        length++;
        return low;
    }
    void shellSort(const RecordType<T> *r, const int length)
    {
        // 首先把记录数组复制过来
        for (int i = 0; i < length; i++)
        {
            this->r[i] = r[i];
        }
        this->length = length;
        // 选取间隔
        for (int i = length / 2; i >= 1; i = i / 2)
        {
            RecordType<T> temp;
            // 逐个遍历记录与该间隔下的前一个进行比较
            for (int j = i; j < length; j++)
            {
                // 发现降序部分就开始调整
                temp = this->r[j];
                if (this->r[j] < this->r[j - i])
                {
                    int k;
                    for (k = j - i; k >= 0 && this->r[k] > temp; k -= i)
                    {
                        this->r[k + i] = this->r[k];
                    }
                    // k 退出时就是正好这一串大于 temp 的同间隔的序列的前面一个小于 temp 的位置
                    // 所以插到 k+i，也就是大于 temp 的序列的原来开头的位置
                    this->r[k + i] = temp;
                }
            }
        }
    }
    // 扑嘟扑嘟沉到底排序🤭
    void bubbleSort(const RecordType<T> *r, const int length)
    {
        // 先复制记录
        for (int i = 0; i < length; i++)
        {
            this->r[i] = r[i];
        }
        this->length = length;
        RecordType<T> swap;
        for (int i = 0; i < length - 1; i++)
        {
            for (int j = 0; j < length - i; j++)
            { // 每次第 i+1 大的记录都会沉底
                std::cout << j << "\n";
                if (this->r[j] > this->r[j + 1])
                {
                    swap = this->r[j];
                    this->r[j] = this->r[j + 1];
                    this->r[j + 1] = swap;
                }
            }
        }
    }
    int get(const int i, RecordType<T> &rec) const
    {
        if (0 <= i && i < length)
        {
            rec = r[i];
            return 0;
        }
        else
        {
            return -1;
        }
    }
    void show()
    {
        for (int i = 0; i < length; i++)
        {
            std::cout << r[i].key << " ";
        }
    }
};

int main()
{
    int choice = 3; // 0 直接插入排序，1 折半插入排序，2 希尔排序，3 冒泡排序
    using namespace std;
    int n;
    cin >> n;
    ListToSort<int> list(n);
    RecordType<int> rec;

    if (choice == 0 || choice == 1)
    {
        // 直接插入排序和折半插入排序
        for (int i = 0; i < n; i++)
        {
            cin >> rec.key;
            if (choice == 0)
                list.directInsertSort(rec);
            else if (choice == 1)
                list.binaryInsertSort(rec);
        }
    }
    else if (choice == 2)
    {
        // 希尔排序
        RecordType<int> *r = new RecordType<int>[n];
        for (int i = 0; i < n; i++)
        {
            cin >> r[i].key;
        }
        list.shellSort(r, n);
    }
    else if (choice == 3)
    {
        RecordType<int> *r = new RecordType<int>[n];
        for (int i = 0; i < n; i++)
        {
            cin >> r[i].key;
        }
        list.bubbleSort(r, n);
    }

    // 显示结果
    for (int i = 0; i < n; i++)
    {
        list.get(i, rec);
        cout << rec.key;
        if (i != n - 1)
            cout << " ";
    }
    return 0;
}
