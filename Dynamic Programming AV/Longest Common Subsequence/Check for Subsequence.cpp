#include <iostream>
using namespace std;

bool isSubSequence(string A, string B) 
{
    int i = 0;
    int j = 0;
    while(i < A.length() && j < B.length()){
        if(A[i] == B[j]){
            i++;
            j++;
        }
        else 
            j++;
    }
    if(i == A.length())
        return true;
    return false;
}

int main() {
	string A, B;
	cout << isSubSequence(A, B);
}
