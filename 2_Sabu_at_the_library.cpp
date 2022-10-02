/* 
CodeZest22 Div-1
Question 2- Sabu at the library

Problem Statement- 
We have two tables : X and Y. Table X has a vertical stack of A number of Chacha Chaudhary comics on it, and Table Y similarly has B number of comics on it.
It takes Sabu Xi minutes to read the i-th comic from the top on Table X (1≤i≤A), and Yi minutes to read the i-th comic from the top on Table Y (1≤i≤B).

Consider the following operation:

Choose a table with a comic remaining, read the topmost comic on that table, and remove it from the table.
How many comics can Sabu read at most by repeating this operation so that it takes him at most N minutes in total? 
He ignores the time it takes to do anything other than reading.
*/

#include <bits/stdc++.h>
using namespace std;
 
int main(){

    long long a,b,n, ans = 0;
    cin>>a>>b>>n;
    vector<long long> v1,v2;
    for(long long i=0;i<a;i++){
        int x;
        cin>>x;
        if(i)
            v1.push_back(x + v1[i-1]);
        else
            v1.push_back(x);
    }
    for(long long i=0;i<b;i++){
        int x;
        cin>>x;
        if(i)
            v2.push_back(x + v2[i-1]);
        else
            v2.push_back(x);
        if(v2[i] <= n)
            ans++;
    }
    for(long long i=0;i<a;i++){
        if(v1[i] > n)
            break;
        long long temp = i+1;
        temp += upper_bound(v2.begin(),v2.end(),n - v1[i]) - v2.begin();
        ans = max(temp,ans);
    }
    cout<<ans;
    return 0;
}