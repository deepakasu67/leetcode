#include<iostream>
#include<stack>
#include<utility>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> st;
public:
    StockSpanner() {

    }

    int next(int price) {
        int span = 1;
        while (!st.empty())
        {
            if (price >= st.top().first)
            {
                span += st.top().second;
                st.pop();
            }
            else
            {
                break;
            }
        }
        st.push({price, span});
        return st.top().second;
    }
};
//int main(void)
//{
//    StockSpanner obj;
//    cout<<obj.next(28);
//    cout << endl;
//    cout<<obj.next(14);
//    cout << endl;
//    cout<<obj.next(60);
//    cout << endl;
//    cout<<obj.next(70);
//    cout << endl;
//    cout<<obj.next(60);
//    cout << endl;
//    cout<<obj.next(75);
//    cout << endl;
//    cout<<obj.next(85);
//    cout << endl;
//}