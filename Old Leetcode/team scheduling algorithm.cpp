#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



void scheduleTeams(vector<vector<pair<int, int>>>& slots, vector<int>& teams)
{
	int teamsCount = 0;
	for (int i = 0; i < slots.size(); i++)
	{
		for (int j = 0; j < slots[i].size(); j++)
		{
			if (teamsCount == teams.size())
				return;

			slots[i][j] = { teams[teamsCount], teams[teamsCount+1] };
			teamsCount += 2;
		}
	}
}


void scheduleTeams(vector<int>& teams, int days)
{ 
   //Morning slot
	//1st slot 9-9:55
	//2nd slot 10-10:55
	//3rd slot 11-11:55

   //Evening slot
	 //1st slot 2-2:55
	 //2nd slot 3-3:55
	 //3rd slot 4-4:55
	vector<vector<pair<int, int>>> slot(days, vector<pair<int,int>>(6));
	
	scheduleTeams(slot, teams);
	
	return;
}

//int main(void)
//{
//
//	vector<int> teams = { 101,102,103,104,106,107,108,109 };
//
//	scheduleTeams(teams, 6);
//}
