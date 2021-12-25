#include <algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void dfs(unordered_map<string,
        vector<string>>& graph,
        unordered_set<string>& visited, 
        string& email, 
        vector<string>& result)
    {
            if (visited.find(email) != visited.end())
                return;

            visited.insert(email);
            result.push_back(email);

            for(int i = 0 ;i < graph[email].size();i++)
            {
                dfs(graph, visited, graph[email].at(i), result);
            }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        //first create a graph
        unordered_map<string, vector<string>> graph;
        unordered_map<string, string> email_to_name;

        for(vector<string>& account: accounts)
        {
            for(int i = 1; i < account.size();i++ )
            {
                graph[account[1]].push_back(account[i]);
                graph[account[i]].push_back(account[1]);
                email_to_name[account[i]] = account[0];
            }
        }
        unordered_set<string> visited;
        vector<vector<string>> result;
        for (vector<string>& account : accounts)
        {
            for(int i = 1 ; i  < account.size();i++)
            {
                vector<string> merged_account;
                dfs(graph, visited, account[i], merged_account);
                sort(merged_account.begin(), merged_account.end());
                merged_account.insert(merged_account.begin(), email_to_name[account[i]]);
                result.push_back(merged_account);
            }
        }
        return result;
    }
};

//int main(void)
//{
//    vector<vector<string>> accounts = { {"John", "johnsmith@mail.com", "john00@mail.com"},{"John", "johnnybravo@mail.com"},{"John", "johnsmith@mail.com", "john_newyork@mail.com"},{"Mary", "mary@mail.com"} };
//    Solution obj;
//    obj.accountsMerge(accounts);
//}