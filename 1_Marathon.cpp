/* 
CodeZest22 Div-1
Question 1 - Marathon 

Problem Statement- 
Chacha Chaudhary and Chachi decided to run.
Chacha said the following: "I will run at Y meters a second for X seconds and take a rest for Z seconds."
Chachi said the following: "I will run at L meters a second for K seconds and take a rest for M seconds."

When S seconds have passed since they simultaneously started to run,is Chacha ahead or Chachi?
*/
   

#include <bits/stdc++.h>
using namespace std;
int main() {
    
    // Chacha: speed = y, time = x, rest = z
    // Chachi: speed = l, time = k, rest = m
    // s = total time passed (time instance)
    // distanceChacha = distance travelled by Chacha
    // distanceChachi = distance travelled by Chachi
    
    int x, y, z, k, l, m, s;
    int distanceChacha, distanceChachi;
    cin>>x>>y>>z>>k>>l>>m>>s;
    
    // distance = speed * time
    if (s % (x + z) < x)
        distanceChacha = y * (s / (x + z) * x + s % (x + z)); 
    if (s % (x + z) >= x)
        distanceChacha = y * (s / (x + z) * x + x);
    if (s % (k + m) < l)
        distanceChachi = l * (s / (k + m) * k + s % (k + m));
    if (s % (k + m) >= l)
        distanceChachi = l * (s / (k + m) * k + k);
    
    if (distanceChacha > distanceChachi)
        cout << "Chacha" <<endl;
    if (distanceChacha == distanceChachi)
        cout << "Draw" <<endl;
    if (distanceChacha < distanceChachi)
        cout << "Chachi" <<endl;
    
    return 0;
}