#include<iostream>
#include<vector>
using namespace std;
int main()
{
    // vector is a template, so it allows us to choose the datatype of elements that We need
    //vector<int> *vp = new vector<int>(); // Dynamic allocation
    vector<int> v; // static allocation
    // inserting elements in vector
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // When accessing/changing vectors elements, it acts like arrays
    v[1] = 100;
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    
    // But if it is an array, why use push_back? 
    // why can't we just assign a value at some position?
    v[3] = 1002;
    v[4] = 1234;
    v.push_back(23);
    v.push_back(234);
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;
    cout<<v[5]<<endl;
    cout<<v[6]<<endl; 
    /*
    10
    100
    30
    23
    234
    16318656 #Garbage
    7562610  #Garbage
    This is what it will print
    Here, only push_back is working
    i.e. 
    we can not use square bracket to insert the elements.
    we can use it to:
        1.Get an element
        2.Update an element
    */
    // An aleternate to square bracket is at() function
    cout<<"Size: "<<v.size()<<endl;
    cout<<v.at(2)<<endl;
    cout<<v.at(6)<<endl;
    /*
    at() Function doesn't return the garbage value when accessing an element which is out of range of the vector
    unlike, when we used the square bracket.
    i.e. at() is safe to use as it gives an error when we access elements out of range
    */
    /* we can use pop_back() to pop an element out of our vector from the back
    */
}