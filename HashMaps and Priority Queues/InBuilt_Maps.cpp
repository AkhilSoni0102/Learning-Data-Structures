#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string, int> ourmap;

    // insert
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    ourmap["def"] = 2;

    // find or access
    cout<< ourmap["abc"]<<endl;
    cout<<ourmap.at("abc")<<endl;
    cout<<ourmap["ghi"]<<endl;

    // size
    cout<<"size: "<<ourmap.size()<<endl;

    /* cout<<ourmap.at("ghi")<<endl;
    this will give us the error : key not found 
    but cout<<ourmap["ghi"] : will insert this value and assign a value 0 to it and will then print it.
    */
    
    // check presence 
    if(ourmap.count("ghi") > 0)
        cout<<"ghi is present"<<endl;

    // erase 
    ourmap.erase("ghi");
}