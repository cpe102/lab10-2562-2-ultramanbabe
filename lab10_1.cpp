// cout << "Press Enter 3 times to reveal your future.";
// cout << "You will get A in this 261102.";
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    string y = "";

    cout << "Press Enter 3 Times to reveal your future.\n";
    cin.get();
    cin.get();
    cin.get();
    int x = rand()%9;
    if(x == 0){
        y = "A";
    }else if(x == 1){
        y = "B+";
    }else if(x == 2){
        y = "B";
    }else if(x == 3){
        y = "C+";
    }else if(x == 4){
        y = "C";
    }else if(x == 5){
        y = "D+";
    }else if(x == 6){
        y = "D";
    }else if(x == 7){
        y = "F";
    }else{
        y = "W";
    }
    cout << "You will get " << y << " in this 261102\n";
    
    return 0;
}