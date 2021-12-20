#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

string sExpression(string nodes)
{
	vector<string> elems;

    stringstream ss(nodes);

    while (ss.good()) {
        string substr;
        getline(ss, substr, ')');
        elems.push_back(substr);
    }
    return " ";
}
//int main(void)
//{
//    string s = "(B,D) (D,E) (A,B) (C,F) (E,G) (A,C)";
//    sExpression(s);
//}