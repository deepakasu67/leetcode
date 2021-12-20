#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path)
    {

        stack<string> st;
        st.push("/");
        int i = 0;
        for(int i = 1; i < path.length(); i++)
        {
            size_t secSlash = path.find_first_of('/', i);

                string strBetweenTwoSlash = path.substr(i, secSlash - i);
                i = (secSlash == string::npos ? path.length() : secSlash);
                if(strBetweenTwoSlash == "..")
                {
                    if(st.top() == "/")
                    {
                        continue;
                    }
                    else
                    {
                        st.pop();
                    }
                }
                else if(strBetweenTwoSlash == ".")
                {
                    continue;
                }
                else if(strBetweenTwoSlash.empty())
                {
                    continue;
                }
                else
                {
                    st.push(strBetweenTwoSlash+ "/");
                }

        }
        string result;
        while(!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }
        if (result.size() > 1 &&  result.back() == '/')
            result.pop_back();

        return result;
    }
};

//int main(void)
//{
//    string path = "/a//b////c/d//././/..";
//    Solution obj;
//    cout<<obj.simplifyPath(path);
//}