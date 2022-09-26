/* Program to Print Square Matrix Pattern */
#include <iostream>
using namespace std;

int main() {
    int n;  //here n represent the number of rows or columns in the pattern
    cin>>n;
    
    int i=0;  // i is used iteration through rows
    
    while(i<n){
        int j=0;  // j is used iteration through rows  
        
        while(j<n){
            cout<<"*  ";
            j++;  // to update column
        }
        cout<<endl;  //this statement act as enter to print next row in next line
        i++;  // to update row
    }
}
