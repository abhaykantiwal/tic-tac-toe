#include<iostream>
#include<cstring>
#include<limits>
using namespace std;
char arr[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,column;
char token='x';
bool tie=false;
string n1="";
string n2="" ;
void basic_structure_of_board() {
   //now I am going to make the structure of board
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

void input_handling() {
    int digit;
    if (token == 'x') {
        cout << n1 << " - please enter: ";
    } else {
        cout << n2 << " - please enter: ";
    }
    
    cin >> digit;

    if (cin.fail() || digit < 1 || digit > 9) {
        cin.clear();  // Clear the error flag.
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer.
        cout << "Invalid input. Please enter a number between 1 and 9." << endl;
        input_handling(); // Ask for input again.
    } else {
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        if (arr[row][column] != 'x' && arr[row][column] != '0') {
            if (token == 'x') {
                arr[row][column] = 'x';
                token = '0';
            } else {
                arr[row][column] = '0';
                token = 'x';
            }
        } else {
            cout << "The cell is already occupied. Please choose another cell." << endl;
            input_handling(); // Ask for input again.
        }
    }
    basic_structure_of_board();
}

//logic to show whether player has won the match or not
bool logic() {
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
         if(arr[i][j] !='x' || arr[i][j]!='0') {
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
   while (!logic()) {
        basic_structure_of_board();
        input_handling();
        tie = false;     // Set tie to false after a valid move is made
    }
    basic_structure_of_board();

    if (token == 'x' && !tie) {
        cout << n2 << " has won the match." << endl;
    } else if (token == '0' && !tie) {
        cout << n1 << " has won the match." << endl;
    } else {
        cout << "It's a tie." << endl;
    }
    return 0;
}
