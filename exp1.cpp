#include<bits/stdc++.h>

//7 - 1 struct 60
struct node
{
    int v1, v2;
    struct node* next;
    struct node* tail;
    node() {next = nullptr; tail = this;}
    node(int num1, int num2):v1(num1), v2(num2), next(nullptr), tail(this) {}
    void push(node* n);
    void add(node* h1, node* h2);
    void mul(node* h1, node* h2);
    void muladd(node* h);
    void derive(node* h);
    void print();
};

void node::push(node* n)
{
    tail->next = n;
    tail = n;
}


void node::add(node* h1, node* h2)
{
    node* t1 = h1->next;
    node* t2 = h2->next;
    while(t1 != nullptr && t2 != nullptr)
    {
        if(t1->v2 > t2->v2)
        {
            this->push(new node(t1->v1, t1->v2));
            t1 = t1->next;
        }
        else if(t1->v2 < t2->v2)
        {
            this->push(new node(t2->v1, t2->v2));
            t2 = t2->next;
        }
        else
        {
            if(t1->v1 + t2->v1 != 0)
            {
                this->push(new node(t1->v1 + t2->v1, t1->v2));
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    while(t1 != nullptr)
    {
        this->push(new node(t1->v1, t1->v2));
        t1 = t1->next;
    }
    while(t2 != nullptr)
    {
        this->push(new node(t2->v1, t2->v2));
        t2 = t2->next;
    }
}

void node::muladd(node* h)
{
    node* t1 = this->next;
    node* t1p = this;
    node* t2 = h->next;
    while(t1 != nullptr && t2 != nullptr)
    {
        if(t1->v2 > t2->v2)
        {
            t1 = t1->next;
            t1p = t1p->next;
        }
        else if(t1->v2 < t2->v2)
        {
            node* tmp = new node(t2->v1, t2->v2);
            t1p->next = tmp;
            tmp->next = t1;
            t1p = tmp;
            t2 = t2->next;
        }
        else
        {
            if(t1->v1 + t2->v1 != 0)
            {
                t1->v1 += t2->v1;
                t1p = t1p->next;
            }
            else
            {
                t1p->next = t1->next;
                if(t1->next == nullptr)
                {
                    this->tail = t1p;
                }
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    while(t2 != nullptr)   
    {
        this->push(new node(t2->v1, t2->v2));
        t2 = t2->next;
    }
}

void node::mul(node* h1, node* h2)
{
    node* tmp1 = h1->next;
    while(tmp1 != nullptr)
    {
        node* new1 = new node();
        node* tmp2 = h2->next;
        while(tmp2 != nullptr)
        {
            new1->push(new node(tmp1->v1 * tmp2->v1, tmp1->v2 + tmp2->v2));
            tmp2 = tmp2->next;
        }
        this->muladd(new1);
        tmp1 = tmp1->next;
    }
}

void node::print()
{
    node* n = this->next;
    while(n != nullptr)
    {
        std::cout << n->v1 << " " << n->v2 << " \n"[n->next == nullptr];
        n = n->next;
    }
}

void node::derive(node* h)
{
    node* t = h->next;
    while(t != nullptr)
    {
        if(t->v2 >= 1)
        {   
            this->push(new node(t->v1 * t->v2, t->v2 - 1));
        }
        t = t->next;
    }
}

int main()
{
    node* h1 = new node();
    node* h2 = new node();
    int n1, n2;
    std::cin >> n1;
    for(int i = 0; i < n1; i++)
    {
        int x, y;
        std::cin >> x >> y;
        h1->push(new node(x, y));
    }
    std::cin >> n2;
    for(int i = 0; i < n2; i++)
    {
        int x, y;
        std::cin >> x >> y;
        h2->push(new node(x, y));
    }
    node* h4 = new node();
    h4->mul(h1, h2);
    if(h4->next == nullptr)
    {
        std::cout << "0 0\n";
    }
    else h4->print();

    node* h3 = new node();
    h3->add(h1, h2);
    if(h3->next == nullptr)
    {
        std::cout << "0 0";
    }
    else h3->print();
    return 0;
}


//7 - 2 struct 40
// int main()
// {
//     node* h = new node();
//     while(1)
//     {
//         int x, y;
//         std::cin >> x >> y;
//         h->push(new node(x, y));
//         if(getchar() == '\n') break;
//     }
//     node* h1 = new node();
//     h1->derive(h);
//     if(h1->next != nullptr) h1->print();
//     else std::cout << "0 0" << "\n";
//     return 0;
// }


//7 - 1 LinkedList(60 + 40)
// struct node
// {
//     int v1, v2;
//     node* next;
//     node() {next = nullptr;}
//     node(int n1, int n2): v1(n1), v2(n2), next(nullptr) {}
// };

// void Insert(node* h, int x, int y)
// {
//     node* t = h;
//     while(t->next != nullptr)
//     {
//         t = t->next;
//     }
//     t->next = new node(x, y);
// }

// node* Add(node* h1, node* h2)//传入头节点,返回头节点
// {
//     node* t = new node();
//     node* t1 = h1->next;
//     node* t2 = h2->next;
//     while(t1 && t2)
//     {
//         if(t1->v2 > t2->v2)
//         {
//             Insert(t, t1->v1, t1->v2);
//             t1 = t1->next;
//         }
//         else if(t1->v2 < t2->v2)
//         {
//             Insert(t, t2->v1, t2->v2);
//             t2 = t2->next;
//         }
//         else
//         {
//             if(t1->v1 + t2->v1 != 0)
//             {
//                 Insert(t, t1->v1 + t2->v1, t1->v2);
//                 t1 = t1->next;
//                 t2 = t2->next;
//             }
//             else
//             {
//                 t1 = t1->next;
//                 t2 = t2->next;
//             }
//         }
//     }
//     while(t1)
//     {
//         Insert(t, t1->v1, t1->v2);
//         t1 = t1->next;
//     }
//     while(t2)
//     {
//         Insert(t, t2->v1, t2->v2);
//         t2 = t2->next;
//     }
//     return t;
// }

// node* Mul(node* h1, node* h2)//传入头节点,返回头节点
// {
//     node* t1 = h1->next;
//     node* t = new node();
//     while(t1 != nullptr)
//     {
//         node* t2 = h2->next;
//         node* tmp = new node();
//         while(t2 != nullptr)
//         {
//             Insert(tmp, t1->v1 * t2->v1, t1->v2 + t2->v2);
//             t2 = t2->next;
//         }
//         t = Add(t, tmp);
//         t1 = t1->next;
//     }
//     return t;
// }

// void print(node* h)
// {
//     node* t = h->next;
//     while(t != nullptr)
//     {
//         std::cout << t->v1 << " " << t->v2;
//         std::cout << (t->next == nullptr ? "\n" : " ");
//         t = t->next;
//     }
// }

// int main()
// {
//     int n1, n2;
//     node* h1 = new node();
//     std::cin >> n1;
//     for(int i = 0; i < n1; i++)
//     {
//         int x, y;
//         std::cin >> x >> y;
//         Insert(h1, x, y);
//     }
//     std::cin >> n2;
//     node* h2 = new node();
//     for(int i = 0; i < n2; i++)
//     {
//         int x, y;
//         std::cin >> x >> y;
//         Insert(h2, x, y);
//     } 
//     node* h4 = Mul(h1, h2);
//     if(h4->next != nullptr)
//     {
//         print(h4);
//     }
//     else
//     {
//         std::cout << "0 0\n";
//     }
//     node* h3 = Add(h1, h2);
//     if(h3->next != nullptr)
//     {
//         print(h3);
//     }
//     else
//     {
//         std::cout << "0 0\n";
//     }
//     return 0;
// }


//7 - 1 STL(60 + 40)
// #include<bits/stdc++.h>
// using i64 = long long;

// int main()
// {
//     int n1, n2;
//     std::cin >> n1;
//     std::vector<std::pair<int, int>> a, b;
//     std::map<int, int>m1, m2;
//     for(int i = 0; i < n1; i++)
//     {
//         int x, y;
//         std::cin >> x >> y;
//         a.push_back(std::make_pair(x, y));
//         m1[y] = x;
//     }
//     std::cin >> n2;
//     for(int i = 0; i < n2; i++)
//     {
//         int x, y;
//         std::cin >> x >> y;
//         b.push_back(std::make_pair(x, y));
//         if(m1.count(y) == 0)
//         {
//             m1[y] = x;
//         }
//         else
//         {
//             if(m1[y] + x == 0)
//             {
//                 m1.erase(y);
//             }
//             else 
//             {
//                 m1[y] += x;
//             }
//         }
//     }
//     for(int i = 0; i < n1; i++)
//     {
//         for(int j = 0; j < n2; j++)
//         {
//             int tmp1 = a[i].second + b[j].second;
//             int tmp2 = a[i].first * b[j].first;
//             if(m2.count(tmp1) == 0)
//             {
//                 m2[tmp1] = tmp2;
//             }
//             else
//             {
//                 if(m2[tmp1] + tmp2 == 0)
//                 {
//                     m2.erase(tmp1);
//                 }
//                 else
//                 {
//                     m2[tmp1] += tmp2;
//                 }
//             }
//         }
//     }
//     int cnt1 = 0;
//     bool f1 = false;
//     for(auto it = m2.rbegin(); it != m2.rend(); it++)
//     {
//         if(it->second != 0)
//         {
//             f1 = true;
//             cnt1++;
//         }
//     }
//     if(f1)
//     {
//         for(auto it = m2.rbegin(); it != m2.rend(); it++)
//         {
//             if(it->second != 0)
//             {
//                 std::cout << it->second << " " << it->first << (cnt1 > 1 ? " " : "");
//                 cnt1--;
//             }
//         }
//         std::cout << "\n";
//     }
//     else
//     {
//         std::cout << "0 0\n";
//     }
//     cnt1 = 0;
//     bool f2 = false;
//     for(auto it = m1.rbegin(); it != m1.rend(); it++)
//     {
//         if(it->second != 0)
//         {
//             f2 = true;
//             cnt1++;
//         }
//     }
//     if(f2)
//     {
//         for(auto it = m1.rbegin(); it != m1.rend(); it++)
//         {
//             if(it->second != 0)
//             {
//                 std::cout << it->second << " " << it->first << (cnt1 > 1 ? " " : "");
//                 cnt1--;
//             }
//         }
//     }
//     else
//     {
//         std::cout << "0 0";
//     }
// }

//7 - 2 STL(60 + 40)
// #include<bits/stdc++.h>
// int main()
// {
//     int x, y, cnt = 0;
//     bool f = false;
//     std::vector<std::pair<int, int>> a;
//     while(1)
//     {
//         int x, y;
//         std::cin >> x >> y;
//         if(y != 0)
//         {
//             x *= y;
//             y -= 1;
//             cnt++;
//         }
//         a.push_back(std::make_pair(x, y));
//         if(getchar() == '\n') break;
//     }
//     if(cnt == 0)
//     {
//         std::cout << "0 0";
//     }
//     else
//     {
//         for(int i = 0; i < cnt; i++)
//         {
//             std::cout << a[i].first << " " << a[i].second;
//             std::cout << (i < cnt - 1 ? " " : "");
//         }
//     }
// }




//book
// struct Term {
// 	float coef;
// 	int exp;
// 	Term* link;
// 	Term(float c, int e, Term* next = NULL)
// 	{
// 		coef = c; exp = e; link = next;
// 	}
// 	Term* InsertAfter(float c, int e);
// 	friend std::ostream& operator<<(std::ostream&, const Term&);
// };

// Term* Term::InsertAfter(float c, int e) {
// 	link = new Term(c, e, link);
// 	return link;
// }

// class Polynomial {
// public:
// 	Polynomial() { first = new Term(0, -1); }
// 	Polynomial(Polynomial& R);
// 	int maxOrder();
// 	Term* getHead() { return first; }
// 	void reverse();
// 	//Polynomial& operator=(Polynomial& R);
// private:
// 	Term* first;
// 	friend std::ostream& operator<<(std::ostream& out, const Polynomial& x);
// 	friend std::istream& operator>>(std::istream& in, Polynomial& x);
// 	friend Polynomial operator+(Polynomial& A, Polynomial& B);
// 	//friend Polynomial operator*(Polynomial&, Polynomial&);
// };

// std::ostream& operator<<(std::ostream& out, const Term& x) {
// 	if (x.coef == 0.0)return out;
// 	out << x.coef;
// 	switch (x.exp) {
// 	case 0:break;
// 	case 1:out << "X"; break;
// 	default:out << "X^" << x.exp; break;
// 	}
// 	return out;
//  }

// Polynomial::Polynomial(Polynomial& R) {
// 	first = new Term(0, -1);
// 	Term* destptr = first, * srcptr = R.first->link;
// 	while (srcptr != NULL) {
// 		destptr->InsertAfter(srcptr->coef, srcptr->exp);
// 		srcptr = srcptr->link;
// 		destptr = destptr->link;
// 	}
// }

// int Polynomial::maxOrder() {
// 	Term* current = first;
// 	while (current->link != NULL) current = current->link;
// 	return current->exp;
// }

// std::istream& operator>>(std::istream& in, Polynomial& x) {
// 	Term* rear = x.first;
// 	float c; int e;
// 	while (1) {
// 		std::cout << "Input a term(coef,exp):" << "\n";
// 		in >> c >> e;
// 		if (e < 0) break;
// 		rear = rear->InsertAfter(c, e);
// 	}
// 	return in;
// }

// std::ostream& operator<<(std::ostream& out, Polynomial& x) {
// 	Term* current = x.getHead()->link;
// 	std::cout << "The Polynomial is:";
// 	bool h = true;
// 	while (current != NULL) {
// 		if (h == false && current->coef > 0.0) out << "+";
// 		h = false;
// 		out << *current;
// 		current = current->link;
// 	}
// 	out << "\n";
// 	return out;
// }

// Polynomial operator+(Polynomial& A, Polynomial& B)
// {
// 	Term* pa, * pb, * pc, * p; float temp;
// 	Polynomial R; pc = R.first;
// 	pa = A.first->link; pb = B.first->link;
// 	while (pa != NULL && pb != NULL){
// 		if (pa->exp == pb->exp){
// 			temp = pa->coef + pb->coef;
// 			if (fabs(temp) > 0.001)
// 				pc = pc->InsertAfter(temp, pa->exp);
// 			pa = pa->link; pb = pb->link;
// 			}
// 		else if (pa->coef < pb->coef) {
// 			pc = pc->InsertAfter(pa->coef, pa->exp);
// 			pa = pa->link;
// 		}
// 		else {
// 			pc = pc->InsertAfter(pb->coef, pb->exp);
// 			pb = pb->link;
// 		}
// 	}
// 	if (pa != NULL)p = pa;
// 	else p = pb;
// 	while (p != NULL) {
// 		pc = pc->InsertAfter(p->coef, p->exp);
// 		p = p->link;
// 	}
// 	return R;

// }

// int main()
// {
//     Polynomial p1, p2;
//     int n;
//     std::cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         int x, y;
//         std::cin >> x >> y;
//         p1.getHead()->InsertAfter(x, y);
//     }
//     std::cout << p1;
// 	system("pause");
// 	return 0;
// }
