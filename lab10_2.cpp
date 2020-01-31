#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	//Write the function to random the number from 1 to 13 and return that random number.
	int x = rand()%13 + 1;
	return x;
}

int calScore(int x,int y,int z){
	//Write the function to calculate the score with is the rightmost digit of summation of the scores from three cards.
	//Return the score. 
	int sum = (cardScores[x] + cardScores[y] + cardScores[z]) % 10;
	return sum;
}

int findYugiAction(int s){	
	if(s == 9) return 2; // Yugi will definitely stay (2) when current score (s) is equal to 9
	else if(s < 6) return 1; // Yugi will definitely draw (1) when current score (s) is less than 6
	else{
		// If current score is 6,7,8, Yugi will draw with probability 69% and will stay with probability 31% 
		// Write conditions here using random number 
		srand(time(0));
		int x = rand()%100 + 1;
		if(x >= 69){
			return 1;
		}else{
			return 2;
		}
	}
}

void checkWinner(int p, int y){
	// Write condition for cout in this function
	cout << "\n---------------------------------\n";
	if(p == y){
	cout <<   "|             Draw!!!           |"; // when p is equal to y
	}else if(p > y){
	cout <<   "|         Player wins!!!        |"; // when p is greater than y
	}else{
	cout <<   "|          Yugi wins!!!         |"; // when p is less than y
	}
	cout << "\n---------------------------------\n";
}

int main(){	
	srand(time(0));
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0}; //This line of code is not completed. You need to initialize value of yugiCards[].
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2);
	if(playerAction == 1){
		//The following lines of code are not completed. Please correct it.
		/*
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << "\n";
		cout << "Your new score: " << "\n";
		*/
		drawCard();
		cout << "Player draws the 3rd card!!!\n";
		playerCards[2] = drawCard();
		cout << "Your 3rd card: " << cardNames[playerCards[2]] << endl;
		playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout << "Your new score: " << playerScore << endl;
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	
	//The following lines of code for Yugi's turn are not completed. Please correct it.
	/*
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << "\n";
	yugiScore = ?????;
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: " << "\n";
		cout << "Yugi's new score: " << "\n";
	}
	cout << "------------ Turn end -------------------\n";
	*/
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << endl;
	yugiScore = calScore(yugiCards[0], yugiCards[1], yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << endl;
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		yugiCards[2] = drawCard();
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]] << endl;
		yugiScore = calScore(yugiCards[0], yugiCards[1], yugiCards[2]);
		cout << "Yugi's new score: " << yugiScore << endl;
	}
	
	checkWinner(playerScore,yugiScore);
}
