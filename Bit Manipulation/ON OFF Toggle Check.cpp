#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, i;
    cin >> N >> i;
    int ON_Mask = (1 << i);     // 1 is powerfull - OR is used to ON a bit
    int OFF_Mask = ~(1 << i);   // 0 is powerfull - AND is used to OFF a bit
    int Toggle_Mask = (1 << i); // 1 is powerfull - XOR is used to toggle a bit
    int Check_Mask = (1 << i);  // 1 is powerfull if OR is used and 0 is powerfull if AND is used

    cout << "ON Mask: " << (N | ON_Mask) << endl;
    cout << "OFF Mask: " << (N & OFF_Mask) << endl;
    cout << "Toggle Mask: " << (N ^ Toggle_Mask) << endl;
    if((N & Check_Mask))
        cout << "Check Mask: ON " << endl;
    else 
        cout << "Check Mask: OFF " << endl;
}