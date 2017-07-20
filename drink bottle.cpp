#include <iostream>
using namespace std;


void helper(int &n,int &result){
    if(n == 1){
        return;
    }//if
    if(n == 2){
        ++result;
        return;
    }//if
    result += n / 3;
    n = n % 3 + n / 3;
    helper(n,result);
}

int Drink(int n){
    if(n <= 1){
        return 0;
    }//if
    if(n == 2){
        return 1;
    }//if
    int result = 0;
    helper(n,result);
    return result;
}


int main(){
    int n;
    //freopen("C:\\Users\\Administrator\\Desktop\\c++.txt","r",stdin);
    while(cin>>n && n != 0){
        cout<<Drink(n)<<endl;
    }//while
    return 0;
}
