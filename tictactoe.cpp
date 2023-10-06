#include<iostream>
#include<cstring>
using namespace std;
char arr[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,column;
char token='x';
bool tie=false;
string n1="";
string n2="" ;
void function_one() {
   //now I am going to make the structure of  game
   cout << "     |       |      "<<endl;
   cout << "  "<<arr[0][0]<<"  |   "<<arr[0][1]<<"   |  "<<arr[0][2]<<endl;
   cout << "_____|_______|_____ "<<endl;
   cout << "     |       |      "<<endl;
   cout << "  "<<arr[1][0]<<"  |   "<<arr[1][1]<<"   |  "<<arr[1][2]<<endl;
   cout << "_____|_______|_____ "<<endl;
   cout << "     |       |      "<<endl;
   cout << "  "<<arr[2][0]<<"  |   "<<arr[2][1]<<"   |  "<<arr[2][2]<<endl;
   cout << "     |       |      "<<endl;
}
void function_two() {
   int digit;
   if(token =='x') {
         cout << n1 <<" - please enter : ";
         cin>>digit;
   }
   if(token =='0') {
         cout << n2 <<" - please enter : ";
         cin>>digit;
   }
   if(digit ==1) {
      row = 0;
      column = 0;
   }
   if(digit ==2) {
      row = 0;
      column = 1;
   }
   if(digit ==3) {
      row = 0;
      column = 2;
   }
   if(digit ==4) {
      row = 1;
      column = 0;
   }
   if(digit ==5) {
      row = 1;
      column = 1;
   }
   if(digit ==6) {
      row = 1;
      column = 2;
   }
   if(digit ==7) {
      row = 2;
      column = 0;
   }
   if(digit ==8) {
      row = 2;
      column = 1;
   }
   if(digit ==9) {
      row = 2;
      column = 2;
   }
   else if(digit<1 || digit >9){
      cout << "invalid input"<<endl;
   }
   if(token == 'x' && arr[row][column]!='x' && arr[row][column] != '0') {
      arr[row][column] = 'x';
      token = '0';
   }
   else if(token == '0' && arr[row][column]!='0' && arr[row][column] != '0') {
      arr[row][column] = '0';
      token = 'x';
   }
   else {
      cout << "there is no empty space" << endl;
      function_two();
   }
   function_one();
}
bool function_three() {
   for(int i=0;i<3;i++) {
    if((arr[i][0] ==arr[i][1] && arr[i][1]==arr[i][2]) || (arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i])) {
         return true;
      }
   }
   if((arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2]) || (arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0])) {
      return true;
   }
   for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
         if(arr[i][j] !='x' && arr[i][j]!='0') {
            return false;
         }
      }
   }
   tie = true;
   return false;
}
int main() {
   cout << "enter the name of first player: " << endl;
   cin>>n1;
   cout << "enter the name of second player: " << endl;
   cin>>n2;
   cout << n1<<" is first player so he will play first"<<endl;
   cout << n2<<" is second player so he will play second"<<endl;
   while(!function_three()) {
      function_one();
      function_two();
      function_three();
   }
   if(token=='x' && tie ==false) {
      cout << n2 << " has won the match."<<endl;
   }
   if(token=='0' && tie ==false) {
      cout << n1 << " has won the match."<<endl;
   }
   else {
      cout << "It's a draw."<<endl;
   }
}
