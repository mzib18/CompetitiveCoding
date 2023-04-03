#include<bits/stdc++.h>
using namespace std;
#define N 10
bool isVerticalValid(vector<vector<char>> &grid, int row, int col,string word){
    for(int i=1;i<word.length();i++){
      if (row + i >= N) {
        return false;
      }
           if(grid[row+i][col]!='-'){
               if(grid[row+i][col] == '+')return false;
               if(grid[row+i][col] != word[i])return false;
           }
    }
    return true;
}
void setVertical(vector<vector<char>> &grid, int row, int col, bool isFilled[],string word){
    for(int i=0;i<word.length();i++){
      if (grid[row + i][col] == '-') {
        grid[row + i][col] = word[i];
        isFilled[i] = true;
      }else{
          isFilled[i]=false;
      }
    }
}
inline void resetVertical(vector<vector<char>> &grid, int row, int col, bool isFilled[],int n){
    for(int i=0;i<n;i++)
        if(isFilled[i]==true)
            grid[row+i][col] = '-';
}
bool isHorizontalValid(vector<vector<char>> &grid, int row, int col,string word){
 for(int i=1;i<word.length();i++){
   if (col + i >= N) {
     return false;
   }
           if(grid[row][col+i]!='-'){
               if(grid[row][col+i] == '+')return false;
               if(grid[row][col+i] != word[i])return false;
           }
    }
    return true;
}
void setHorizontal(vector<vector<char>> &grid, int row, int col, bool isFilled[],string word){
  for (int i = 0; i < word.length(); i++) {
    if (grid[row][col+i] == '-') {
      grid[row][col+i] = word[i];
      isFilled[i] = true;
    }else{
        isFilled[i] = false;
    }
  }
}
inline void resetHorizontal(vector<vector<char>> &grid, int row, int col, bool isFilled[],int n){
  for (int i = 0; i < n; i++)
        if (isFilled[i] == true)
            grid[row][col+i] = '-';
}

bool solveCrossword(vector<vector<char>> &grid, vector<string> &words,int index){
    if(index == words.size()){
        return true;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j] == '-' || grid[i][j] == words[index][0]){
                if(isVerticalValid(grid,i,j,words[index])){
                    bool isFilled[words[index].length()];
                    setVertical(grid,i,j,isFilled,words[index]);
                    if(solveCrossword(grid,words,index+1)){
                        return true;
                    }
                    resetVertical(grid,i,j,isFilled,words[index].length());
                }
                if (isHorizontalValid(grid, i, j,words[index])) {
                  bool isFilled[words[index].length()];
                  setHorizontal(grid, i, j, isFilled,words[index]);
                  if (solveCrossword(grid, words, index + 1)) {
                    return true;
                  }
                  resetHorizontal(grid, i, j, isFilled,words[index].length());
                }
            }
        }
    }
    return  false;
}
int main() {
  vector<vector<char>> grid(N, vector<char>(N));

  // read input crossword grid
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }

  cin.ignore(); // ignore the newline character after reading the grid

  // read input words list
  vector<string> words;
  string line;
  getline(cin, line);
  stringstream ss(line);
  string word;
  while (getline(ss, word, ';')) {
    words.push_back(word);
  }

  // solve the crossword puzzle
  solveCrossword(grid, words, 0);

  // output the solved crossword grid
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }

  return 0;
}
//The completed code can be found below:
