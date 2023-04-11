// Create a diamond pattern using alphabet letters.
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    char *ptr;
    cout<<"Enter any number you want: \n";
    cin>>n;
    
    if (n >= 1){
        for(int i = 0; i < (n*2 +1); i++){
            for(int j = 0; j < (n*2 + 1); j++){
                int num =  n - abs(n - j);
                int num2 =  n - abs(n - i);
                if (num + num2 <= n){
                    ptr = new char(num+65);
                    cout<<*ptr<<" ";
                }
                else{
                    cout<<"  ";
                }
            }
            cout<<endl;
        }
    }
return 0;
}
