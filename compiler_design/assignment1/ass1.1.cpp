#include<iostream>
#include<string>
using namespace std;

// grammer
//  E->iF
// F->+iF|e
//e stands for epsilon

string input;
int l=0;
void match(char t){
    if(input[l]==t)
        l++;
    else{
        cout<<"\nerror\n";
        exit(1);
    }
}
void F(){
    if(input[l]=='+'){
        match('+');
        match('i');
        cout<<"F->+iF|e"<<endl;
        F();
    }
}

void E(){
    if(input[l]=='i'){
        match('i');
        cout<<"E->iF"<<endl;
        F();
    }
}
int main(){
    input="i+i+i+i+i$";
    E();
    if(input[l]=='$')
        cout<<"parsing successful";
    return 0;
}