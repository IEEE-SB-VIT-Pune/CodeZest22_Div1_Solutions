/*
CodeZest22 Div-1
Question 3 - Tingu Master does Repairs

Problem Statement-
There are X square shaped tiles arranged in a row from left to right. 
Let Tile i be the i-th tile from the left.

Y of those tiles, Tile T1, T2, T3, …, TY, are blue; 
the others are white (Y may be 0, in which case there is no blue tiles).

Tingu Master is a dimwit and can only learn how to paint exactly d tiles at one point in time. 
In one paintjob of the tiles, he chooses d consecutive tiles from the X tiles and then paints them red, as long as those d tiles are not blue.

At least how many times he needs to paint the tiles (number of paintjobs) so that no white coloured tiles remain. 
Please help Tingu Master make the optimal choice of learning how many d tiles to paint in one go in order to determine the minimum number of paint jobs required.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m, k = 1, ans = 0;
  cin >> n >> m;
  vector <long long> a(m), sa(m+1);
  
  if(m == 0) {
    cout << 1 << endl;
    return 0;
  }
  
  for(long long &i : a)
    cin >> i;
  
  sort(a.begin(), a.end());
  
  for(int i = 1; i < m; i++)
    sa[i-1] = a[i] - a[i-1] - 1;
  
  sa[m-1] = a[0] - 1;
  sa[m] = n - a[m-1];
  sort(sa.begin(), sa.end());
  
  for(int i = 0; i < m + 1; i++)
    
    if(sa[i] != 0) {
      k = sa[i];
      break;
    }
  
  for(long long i : sa) {
    ans += i / k;
    
    if(i % k != 0)
      ans++;
  }
  
  cout << ans << endl;
}