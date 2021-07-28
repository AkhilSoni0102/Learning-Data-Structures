#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int Data;
    ListNode* next;
    ListNode(int Data){
        next = NULL;
        this -> Data = Data;
    }
};

// N = 2 ^ x + l;
// Ans = 2 * l + 1;
int main(){
    int N;
    cin >> N;
    ListNode* Head = new ListNode(1);
    ListNode* Temp = Head;
    for(int i = 2;i <= N;i++){
        ListNode* New = new ListNode(i);
        Temp -> next = New;
        Temp = New;
    }
    Temp -> next = Head;
    ListNode* t = Head;
    while(t -> next != t){
        t -> next = t -> next -> next;
        t = t -> next;
    }
    cout << t -> Data;
}