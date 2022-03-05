#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
string input;
int l=0;

// Match function
void match(char t){
    if (input[l] == t) {
        l++;
    }
    else{
	printf("error\n");
	exit(1);
    }
}

// Definition of E, as per the given production
void E(){
	if(input[l]=='$'){
		printf("accepted\n");
	}
	else if (input[l] == 'a') {
		match('a');
		E();
		match('b');
	}
	else if (input[l] == 'b') {
		return;
	}
 	else{
		printf("error\n");
		exit(1);
	}
}

int main(){
	input="aabb$";
	// E is a start symbol.
	E();
	// if lookahead = $, it represents the end of the string
	// Here l is lookahead.
	if (input[l] == '$')
		printf("accepted\n");
	else 
	printf("error\n");
}

