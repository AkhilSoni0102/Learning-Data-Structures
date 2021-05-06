#include<iostream>
#include<unordered_map>
#include<vector>
#include<string> 

using namespace std;
int main(){
    unordered_map<string, int> ourmap;
    ourmap["abc1"] = 1;
    ourmap["abc2"] = 2;
    ourmap["abc3"] = 3;
    ourmap["abc4"] = 4;
    ourmap["abc5"] = 5;
    ourmap["abc6"] = 6;
    ourmap["abc7"] = 7;
    unordered_map<string,int>:: iterator it = ourmap.begin();
    while(it != ourmap.end()){
        cout<<"Key: "<<it->first<<" value: "<<it->second<<endl;
        it++;
    }

    // for vectors 
    vector<int> v;
    for(int i = 1;i < 5;i++)
        v.push_back(i);

    vector<int>:: iterator it1 = v.begin();
    while(it1 != v.end()){
        cout<<*it1<<" ";
        it1++;
    }
    

    // find function
    unordered_map<string, int>:: iterator it2 = ourmap.find("abc");
    ourmap.erase(it); // will delete the values at iterator it but here it doesn't make sense as it doesn't have any order.
    v.erase(it1, it1+1); // will delete the elements for it1 to it1 + 1


}