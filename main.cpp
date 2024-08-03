#include<iostream>
#include <bits/stdc++.h>
#include<fstream>
using namespace std;

class Sudoku{
    public:
    Sudoku(){
        solveSudoku();
    }
    private:
    vector<vector<char>> board;
    void add(vector<vector<set<char>>> &options){
        set<char> st={'1','2','3','4','5','6','7','8','9'};
        vector<set<char>> row;
        for(int i=0;i<9;i++)
            row.push_back(st);
        for(int i=0;i<9;i++)
            options.push_back(row);
    }
    void remove(vector<vector<set<char>>> &options,int i,int j,char ch){
        for(int r=0;r<9;r++){
            auto pos=options[r][j].find(ch);
            if(pos != options[r][j].end())
                options[r][j].erase(pos);
            pos=options[i][r].find(ch);
            if(pos != options[i][r].end())
                options[i][r].erase(pos);
        }
        int v1=(i/3)*3,v2=(j/3)*3;
        for(int r=v1;r<v1+3;r++){
            for(int c=v2;c<v2+3;c++){
                auto pos=options[r][c].find(ch);
                if(pos != options[r][c].end())
                    options[r][c].erase(pos);
            }
        }
    }
    bool solve(vector<vector<set<char>>> &options,int r,int c){
        if(c>8) return true;
        if(board[r][c]=='.' && options[r][c].size()>0){
            for(auto it=options[r][c].begin();it!=options[r][c].end();it++){
                board[r][c]=*it;
                vector<vector<set<char>>> optionstemp=options;
                remove(optionstemp,r,c,board[r][c]);
                if(r+1<9){
                    if(solve(optionstemp,r+1,c))
                        return true;
                    else
                        board[r][c]='.';
                }
                else{
                    if(solve(optionstemp,0,c+1))
                        return true;
                    else
                        board[r][c]='.';
                }
            }
        }
        else if(board[r][c]>='0' && board[r][c]<='9'){
            if(r+1<9)
                return solve(options,r+1,c);
            else
                return solve(options,0,c+1);
        }
        return false;
    }
    void solveSudoku(){
        if(!takeInput() || !isValidSudoku()){
            cout<<"Invalid Input\n";
            return;
        }
        vector<vector<set<char>>> options;
        add(options);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.')
                    remove(options,i,j,board[i][j]);
            }
        }
        solve(options,0,0);
        cout<<"Solution saved in 'Output.txt'";
        output();
    }
    bool isValidSudoku() {
        for(int i=0;i<9;i++){
            set<char> st1,st2;
            for(int j=0;j<9;j++){
                if(st1.find(board[i][j]) != st1.end()) return false;
                else if(board[i][j] != '.') st1.emplace(board[i][j]);
                if(st2.find(board[j][i]) != st2.end()) return false;
                else if(board[j][i] != '.') st2.emplace(board[j][i]);
            }
        }
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                set<char> st;
                for(int k=i;k<i+3;k++){
                    for(int h=j;h<j+3;h++){
                        if(st.find(board[k][h]) != st.end()) return false;
                        else if(board[k][h] != '.') st.emplace(board[k][h]);
                    }
                }
            }
        }
        return true;
    }
    bool takeInput(){
        ifstream ipfile("Input.txt");
        for(int i=0;i<9;i++){
            vector<char> row;
            string st;
            getline(ipfile,st);
            int j=0;
            for(;j<9 && j<st.length();j++){
                if(st.at(j)>='0' && st.at(j)<='9')
                    row.push_back(st.at(j));
                else if(st.at(j)==' ')
                    row.push_back('.');
                else return false;
            }
            for(;j<9;j++)
                row.push_back('.');
            board.push_back(row);
        }
        output();
        return true;
    }
    void output(){
        ofstream opfile("Output.txt");
        for(int i=0;i<9;i++){
            string s="";
            for(int j=0;j<9;j++){
                s=s+board[i][j]+" ";
            }
            if(i<8)
                s+="\n";
            opfile<<s;
        }
    }
};

int main(){
    Sudoku s;
    return 0;
}