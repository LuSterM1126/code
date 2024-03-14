// 1
// #include <bits/stdc++.h>
// using i64 = long long;

// int main()
// {
//     std::stack<char> op;
//     std::map<char, int> mp; //运算符优先级比较
//     std::string s;
//     std::cin >> s;
//     bool space = true;
//     //运算符优先级 +- < */ < ()
//     //栈外 () 优先级最高，进栈后 (最低
//     mp['-'] = 1, mp['+'] = 1;
//     mp['*'] = 2, mp['/'] = 2;
//     mp['('] = 3, mp[')'] = 3;
//     //遍历字符串
//     for(int i = 0; i < int(s.size()); i++)
//     {
//         if(((i == 0 || s[i - 1] == '(') && (s[i] == '+' || s[i] == '-')) || (s[i] >= '0' && s[i] <= '9') || (s[i] == '.'))
//         //前一个是否为'('   (是否为括号表达式，括号表达式第一个可能为负数)
//         //是否为'+'或'-'
//         //是否为数字 (直接输出)
//         //是否为小数点 (小数问题)
//         {
//             if(!space) //判断输出是否要打印空格 (第一次不用打印，后续都需要打印)
//             {
//                 std::cout << " ";
//             }
//             if(s[i] != '+') //数字前符号为 - ,代表负数;若为。,代表为小数
//             {
//                 std::cout << s[i];
//             }
//             while(s[i + 1] == '.' || s[i + 1] >= '0' && s[i + 1] <= '9') //小数
//             {
//                 i++;
//                 std::cout << s[i];
//             }
//             space = false;
//         }
//         else
//         {
//             //遇到运算符时
//             //空栈或者栈顶为'('直接入栈
//             //否则比较符号优先级：大于 push，小于等于 pop 至大于栈顶符号的优先级
//             if(s[i] == ')')
//             {
//                 while(!op.empty() && op.top() != '(')
//                 {
//                     std::cout << " " << op.top();
//                     op.pop();
//                 }
//                 op.pop();
//             }
//             else if(op.empty() || mp[s[i]] > mp[op.top()])
//             {
//                 op.push(s[i]);
//             }
//             else
//             {
//                 while(!op.empty() && op.top() != '(')
//                 {
//                     std::cout << " " << op.top();
//                     op.pop();
//                 }
//                 op.push(s[i]);
//             }
//         }
//     }
//     while(!op.empty()) //遍历结束后全部 pop
//     {
//         std::cout << " " << op.top();
//         op.pop();
//     }
//     return 0;
// }



// 2
// #include <bits/stdc++.h>
// using i64 = long long;

// int main()
// {
//     //设置小数点打印
//     std::cout << std::fixed << std::setprecision(1);
//     std::string s;
//     std::getline(std::cin, s);//空格输入
//     std::stack<double> n;
//     //前缀从后往前遍历 (后缀从前往后遍历)
//     for (int i = s.size() - 1; i >= 0; i--)
//     {
//         if(s[i] == ' ') continue;
//         else if (s[i] >= '0' && s[i] <= '9')
//         {
//             // int index = -1;
//             // double sum = 0;
//             std::string tmp;//临时存储操作数
//             while(i >= 0 && ((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == '-'))
//             //整数，小数，负数
//             {
//                 // if(s[j] == '.') index = j;
//                 tmp = s[i] + tmp;
//                 i--;
//             }
//             // std::cout << tmp << "\n";
//             // if(index == -1)
//             // {
//             //     for(int k = tmp.size() - 1; k >= 0; k--)
//             //     {
//             //         sum = sum * 10 + double(tmp[k] - '0');
//             //     }
//             // }
//             // else
//             // {
//             //     //+ + 2 * 3 - 7 4 / 8 -4
//             //     index -= j + 1;
//             //     for(int k = tmp.size() - 1; k >= 0; k--)
//             //     {
//             //         if(tmp[k] == '.') continue;
//             //         sum += (tmp[k] - '0') * pow(10, --index);
//             //     }
//             // }
//             // i = (j + (s[j] != '-'));
//             // sum *= (s[j] == '-' ? -1 : 1);
//             // n.push(sum);
//             // if(i == 2 && s[0] == '+' && n.size() == 1) break;
//             // std::cout << sum << "\n";
//             n.push(std::stof(tmp));
//         }
//         else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')//遇到运算符 pop 两次栈，运算结束后再 push
//         {
//             double x = n.top(); n.pop();
//             double y = n.top(); n.pop();
//             // std::cout << x << " " << y << "\n";
//             if(s[i] == '+')
//                 n.push(x + y);
//             else if (s[i] == '-')
//                 n.push(x - y);
//             else if (s[i] == '*')
//                 n.push(x * y);
//             else if (s[i] == '/')
//             {
//                 //除数为 0 抛出异常 ERROR
//                 if (y == 0)
//                 {
//                     std::cout << "ERROR\n"
//                     return 0;
//                 }
//                 n.push(x / y);
//             }
//         }
//     }
//     //最终栈中只能有 1 个结果
//     if (n.size() == 1)
//         std::cout << n.top();
//     else
//         std::cout << "ERROR";
//     return 0;
// }



// 3
//  #include <bits/stdc++.h>
//  using i64 = long long;
//  constexpr int MAX = 1e5 + 5;
//  int dp[MAX];

// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);

//     int n;
//     std::cin >> n;
//     std::vector<int> a(n);
//     for(int i = 0; i < n; i++)
//     {
//         std::cin >> a[i];
//         dp[i] = n + 1;
//     }
//     int ans = -1;
//     for(int i = 0; i < n; i++)
//     {
//         int index = std::lower_bound(dp, dp + n, a[i]) - dp;
//         dp[index] = a[i];
//         ans = std::max(ans, index + 1);
//     }
//     std::cout << ans;
//     return 0;
// }


























// #include <iostream>
// using namespace std;

// template <class T>
// struct Node
// {
//     T data;
//     Node<T> *next;
// };

// template <class T>
// class LinkedStack
// {
// private:
//     Node<T> *top;

// public:
//     LinkedStack();
//     ~LinkedStack();
//     bool Push(T e);
//     bool Pop(T &e);
//     bool GetTop(T &e);
//     bool IsEmpty();
// };

// template <class T>
// bool LinkedStack<T>::GetTop(T &e)
// {
//     if (top == NULL)
//         return false;
//     e = top->next->data;
//     return true;
// }

// template <class T>
// bool LinkedStack<T>::Push(T e)
// {
//     Node<T> *p = new Node<T>;
//     if (!p)
//         return false;
//     p->data = e;
//     p->next = top->next;
//     top->next = p;
//     return true;
// }

// template <class T>
// bool LinkedStack<T>::Pop(T &e)
// {
//     Node<T> *p;
//     if (top->next == NULL)
//         return false;
//     else
//     {
//         p = top->next;
//         e = p->data;
//         top->next = p->next;
//         delete p;
//         return true;
//     }
// }

// template <class T>
// LinkedStack<T>::LinkedStack()
// {
//     top = new Node<T>;
//     top->next = nullptr;
// }

// template <class T>
// LinkedStack<T>::~LinkedStack()
// {
//     Node<T> *p;
//     while (top != nullptr)
//     {
//         p = top;
//         top = top->next;
//         delete p;
//     }
// }

// template <class T>
// bool LinkedStack<T>::IsEmpty()
// {
//     if (top->next == NULL)
//         return true;
//     else
//         return false;
// }

// // 中缀式转换后缀式
// char Precede(char theta1, char theta2)
// {
//     if ((theta1 == '(' && theta2 == ')') || (theta1 == '#' && theta2 == '#'))
//         return '=';
//     else if (theta1 == '(' || theta1 == '#' || theta2 == '(' || ((theta1 == '+' || theta1 == '-') && (theta2 == '*' || theta2 == '/')))
//         return '<';
//     else
//         return '>';
// }

// char *change(char *ptr)
// {
//     char *result = new char;
//     int i = 0;
//     LinkedStack<char> OPTR;
//     OPTR.Push('#');
//     char e, op;
//     while (*ptr != '\0')
//     {
//         if ((*ptr) >= '0' && (*ptr) <= '9')
//         {
//             *(result + i) = *ptr;
//             i++;
//         }
//         else
//         {
//             if (*ptr == '(')
//                 OPTR.Push(*ptr);
//             else if (*ptr == ')')
//                 do
//                 {
//                     OPTR.Pop(e);
//                     if (e != '(')
//                         *(result + i++) = e;
//                 } while (e != '(');
//             else
//             {
//                 OPTR.GetTop(op);
//                 switch (Precede(op, *ptr))
//                 {
//                 case '<':
//                     OPTR.Push(*ptr);
//                     break;
//                 case '=':
//                 case '>':
//                     OPTR.Pop(e);
//                     *(result + i++) = e;
//                     OPTR.GetTop(op);
//                     while (Precede(op, *ptr) == '>')
//                     {
//                         OPTR.Pop(e);
//                         *(result + i++) = e;
//                         OPTR.GetTop(op);
//                     }
//                     OPTR.Push(*ptr);
//                 }
//             }
//         }
//         ptr++;
//     }
//     while (OPTR.IsEmpty() == false)
//     {
//         OPTR.Pop(e);
//         if (e != '#')
//             *(result + i++) = e;
//     }
//     *(result + i) = '\0';
//     return result;
// }

// int main()
// {
//     // 中缀转后缀测试代码
//     char c[25] = {0}; // 数组大小未定
//     while (1)
//     {
//         cin >> c;
//         if (getchar() == '\n')
//             break;
//     }
//     char *result;
//     result = change(c);
//     while (1)
//     {
//         if (*result == '\0')
//             break;
//         cout << *result;
//         result++;
//         if (*result != '\0')
//             cout << " ";
//     }
//     return 0;
// }