#include <iostream>
#include <cstring>
#include <limits>
using namespace std;
char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, column;
char token = 'x';
string n1 = "";
string n2 = "";
int val = 0;
void basic_structure_of_board(){
   // Display the game board
   cout << "     |       |      " << endl;
   cout << "  " << arr[0][0] << "  |   " << arr[0][1] << "   |  " << arr[0][2] << endl;
   cout << "_____|_______|_____ " << endl;
   cout << "     |       |      " << endl;
   cout << "  " << arr[1][0] << "  |   " << arr[1][1] << "   |  " << arr[1][2] << endl;
   cout << "_____|_______|_____ " << endl;
   cout << "     |       |      " << endl;
   cout << "  " << arr[2][0] << "  |   " << arr[2][1] << "   |  " << arr[2][2] << endl;
   cout << "     |       |      " << endl;
}
void input_handling(){
   int digit;
   if (token == 'x'){
      cout << n1 << " - please enter: ";
   }
   else{
      cout << n2 << " - please enter: ";
   }
   cin >> digit;
   if (cin.fail() || digit < 1 || digit > 9){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter a number between 1 and 9." << endl;
      input_handling();
   }
   else{
      row = (digit - 1) / 3;
      column = (digit - 1) % 3;

      if (arr[row][column] != 'x' && arr[row][column] != '0'){
         if (token == 'x'){
            arr[row][column] = 'x';
            token = '0';
         }
         else{
            arr[row][column] = '0';
            token = 'x';
         }
      }
      else{
         cout << "The cell is already occupied. Please choose another cell." << endl;
         input_handling();
      }
   }
   basic_structure_of_board();
}
//logic to determine whether a player have won the game or not.
bool logic(){
   for (int i = 0; i < 3; i++){
      if ((arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) ||
          (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) ||
          (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) ||
          (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]))
      {
         val = 1;
         return true;
      }
   }
   bool found = false;
   for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
         if (arr[i][j] != 'x' && arr[i][j] != '0'){
            found = true;
            break;
         }
      }
      if (found){
         break;
      }
   }
   if (found){
      return false;
   }
   return true;
}

int main(){
   cout << "Enter the name of the first player: " << endl;
   cin >> n1;
   cout << "Enter the name of the second player: " << endl;
   cin >> n2;
   cout << n1 << " is the first player, so they will play first." << endl;
   cout << n2 << " is the second player, so they will play second." << endl;
   while (!logic()){
      basic_structure_of_board();
      input_handling();
   }
   if (val == 1){
      if (token == 'x'){
         cout << n2 << " has won the match." << endl;
      }
      else{
         cout << n1 << " has won the match." << endl;
      }
   }
   else{
      cout << "It's a draw." << endl;
   }
   return 0;
}
