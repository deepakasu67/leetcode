#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    bool parseLog(string& log, pair<int, int>& getFunctionNumAndTime)
    {
        if(log.find(":start:")!= string::npos)
        {
            size_t found = log.find(":start:");
            int functionName = atoi(log.substr(0,found).c_str());
            int time = atoi(log.substr(found + 7).c_str());
            getFunctionNumAndTime.first = functionName;
            getFunctionNumAndTime.second = time;
            return true;
        }
        if(log.find(":end:") != string::npos)
        {
            size_t found = log.find(":end:");
            int functionName = atoi(log.substr(0, found).c_str());
            int time = atoi(log.substr(found + 5).c_str());
            getFunctionNumAndTime.first = functionName;
            getFunctionNumAndTime.second = time;
            return false;
        }
        return false;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs)
    {
        vector<int> functionsTime(n,0);
        stack<pair<int,int>> st;
        pair<int, int> functionNameAndTime;

        int timeSpan = 0;
        for(int i = 0; i < logs.size(); i++)
        {
            if(parseLog(logs[i],functionNameAndTime) == true)
            {
                if(st.empty())
                {
                    st.push(functionNameAndTime);
                    timeSpan = st.top().second;
                    continue;
                }
                int lastStartFuncName = st.top().first;
                functionsTime[lastStartFuncName] += (functionNameAndTime.second - timeSpan);
                st.push(functionNameAndTime);
                timeSpan = functionNameAndTime.second;
            }
            else
            {
                //this should not happen
                if (st.empty())
                    return {};
                int lastStartFuncName = st.top().first;
                functionsTime[lastStartFuncName] += (functionNameAndTime.second - timeSpan) + 1;
                st.pop();
                //if task ends at this timeSpan then i need to increase it by 1 to start a new task
                timeSpan = functionNameAndTime.second + 1;
            }
        }
        return functionsTime;
    }
};

//int main(void)
//{
//    vector<string> logs = { "0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7" };
//    Solution obj;
//    obj.exclusiveTime(2,logs);
//}
