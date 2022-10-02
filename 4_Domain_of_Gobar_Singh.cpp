/*
CodeZest22 Div-1
Question 4 - Domain of Gobar Singh

Problem Statement-
The domain of Gobar Singh can be represented as a network(grid) with X rows and Y columns. 
Let (a,b) denote the square at the a-th row from the north and b-th column from the west.

Recently, there have been more and more requests from the Gobar’s minions to build a bus system, and now the Gobar has no choice but to build one.
The construction of the system will have the following two phases.

First, choose two different squares and build a stop on each of them. It costs Ca,b rupees to build a bus stop on the square (a,b).
Then, build a road connecting these two stops. This costs M×(∣a−a′∣+∣b−b′∣) rupees when the two stops are on the squares (a,b) and (a′,b′). 
(|x| denotes the absolute value of x.) In true villain fashion, Gobar Singh’s priority is to spend as little as possible on this endeavour, rather than to improve convenience for his minions.

Print the minimum possible total cost of the construction of the bus system.
*/

#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e3+5;
long long mn[N][N], c[N][N];
int main(){
    int x, y, m;
    cin>>x>>y>>m;
    for (int i=1;i<=x;i++) {
        for (int j=1;j<=y;j++) cin>>c[i][j];
    }
    memset(mn,INF,sizeof mn);
    for (int i=1;i<=x;i++) {
        for (int j=1;j<=y;j++) {
            mn[i][j]=min({c[i][j],mn[i-1][j]+m,mn[i][j-1]+m});
        }
    }
    long long ans=2e18;
    for (int i=1;i<=x;i++) {
        for (int j=1;j<=y;j++) {
            ans=min(ans,min(mn[i-1][j], mn[i][j-1])+m +c[i][j]);
        }
    }
    for (int i=1;i<=x;i++) {
        for (int j=y;j>=1;j--) {
            mn[i][j]=min({c[i][j], mn[i-1][j]+m, mn[i][j+1]+m});
        }
    }
    for (int i=1;i<=x;i++) {
        for (int j=y;j>=1;j--) {
            ans=min(ans,min(mn[i-1][j], mn[i][j+1])+m+c[i][j]);
        }
    }
    cout<<ans;
    return 0;
}