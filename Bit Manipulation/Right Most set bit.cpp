#include<bits/stdc++.h>
using namespace std;
// general binary number:   x  = [1's and 0's] 1 [only 0's]
//                          ~x = [0's and 1's] 0 [only 1's]
//                      ~x + 1 = [0's and 1's] 1 [only 0's]

//                          x  = [1's and 0's] 1 [only 0's]
//                      ~x + 1 = [0's and 1's] 1 [only 0's]
//                x & (~x + 1) = [  only 0's ] 1 [only 0's]   

// i.e we got the 1 << i for the right shift set bit
// not by substracting this with the original number we replace the right most set bit from 1 to 0

int main(){
    int N;
    cin >> N;
    int rmsb = N & (~N + 1);
    // or
    int b = N & (-N);
    int removed_rmsb = N - rmsb;
    cout << removed_rmsb;
}