#include<iostream>
#include<stack>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
bool balance(string expression){
    stack<char>st;
    for(auto i:expression){
        // cout<<i<<'\t';
        switch(i){
            case('('):
                st.push(i);
                break;
            case('{'):
                st.push(i);
                break;
            case('['):
                st.push(i);
                break;
            case(')'):
                if(st.empty())
                    return false;
                else if(st.top()=='(')
                    st.pop();
                else
                    return false;
            break;
            case('}'):
                if(st.empty())
                    return false;
                else if(st.top()=='{')
                    st.pop();
                else
                    return false;
            break;
            case(']'):
                if(st.empty())
                    return false;
                else if(st.top()=='[')
                    st.pop();
                else
                    return false;
            break;
            default:
                ;
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}

void result(string filename){
    vector<pair<int,string>>v{{}};
    int line=1;
    fstream newfile;
    newfile.open(filename,ios::in);
    if(newfile.is_open()){
        string tp;
        while(getline(newfile,tp)){
            if(balance(tp))
                cout<<line<<'\t'<<"balanced"<<endl;
            else
                cout<<line<<'\t'<<"unbalanced"<<endl;
            line++;
        }
        newfile.close();
    }
}

int main(){
    result("exam.txt");
    return 0;
}