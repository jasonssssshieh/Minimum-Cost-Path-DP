//
//  main.cpp
//  Mininum Cost Path DP
//
//  Created by Zijian Xie on 2016/11/10.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

//Space: O(min(m,n));
class MinCostPath_2{
private:
    vector<vector<int>> cost;
public:
    MinCostPath_2(vector<vector<int>>& cost){
        this->cost = cost;
    }
    
    int DP(){
        if(cost.empty()) return 0;
        int m = (int)cost.size();
        int n = (int)cost[0].size();
        //suppose m >= n
        vector<int> dp(n,0);
        dp[0] = cost[0][0];
        for(int i = 1; i < n; ++i){dp[i] = dp[i-1] + cost[0][i];}
        for(int i = 1; i < m; ++i){
            dp[0] = dp[0] + cost[i][0];
            for(int j = 1; j < n; ++j){
                dp[j] = cost[i][j] + min(dp[j-1], dp[j]);
            }
        }
        cout<< "The minimum amount of cost is: " <<dp[n-1]<<endl;
        return dp[n-1];
    }
};

class MinCostPath{
private:
    vector<vector<int>> cost;
public:
    MinCostPath(vector<vector<int>>& cost){
        this->cost = cost;
    }
    
    int DP(){
        if(cost.empty()) return 0;
        int m = (int)cost.size();
        int n = (int)cost[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = cost[0][0];
        for(int i = 1; i < m; ++i){
            dp[i][0] = dp[i-1][0] + cost[i][0];
        }
        for(int j = 1; j < n; ++j){
            dp[0][j] = dp[0][j-1] + cost[0][j];
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = cost[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int i = m-1, j = n-1;
        string res = "cost[" + to_string(i)+ "]" + "[" + to_string(j) + "]" + "(cost is " + to_string(cost[i][j]) + ") ";
        
        while(i || j){
            if(i > 0 && dp[i][j] == dp[i-1][j] + cost[i][j]){
                i--;
            }else{
                j--;
            }
            res += "<- cost[" + to_string(i)+ "]" + "[" + to_string(j) + "]" + "(cost is " + to_string(cost[i][j]) + ") ";
        }
        cout<<"The minimum cost path is: " <<res<<endl;
        cout<< "The minimum amount of cost is: " <<dp[m-1][n-1]<<endl;
        return dp[m-1][n-1];
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> cost = {{1,3,5,8},{4,2,1,7},{4,3,2,3}};
    MinCostPath* test = new MinCostPath(cost);
    test->DP();
    cout<<endl;
    MinCostPath_2* test2 = new MinCostPath_2(cost);
    test2->DP();
    return 0;
}
