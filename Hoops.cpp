/*
 * Author: <Dario Mejia Garduno>
 * Program description: < Basketball Shooting Ralley. The program takes four
 * user inputs: number of players, shooting ability, the Money Rack position,
 * and whther they want to play again at the end of the program. Simulates a
 * basketball shooting ralley, displaying for each postion (basketabll rack)
 * the shooting outcomes and the total points, culminating in the total ralley
 * score, that is finally compared among all players to determine the winner.
 * >
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

/*
 * Function: UserHandling
 * Description: Handles user input within specified bounds.
 * Parameters: int LowerBound <the lower limit of valid input>
 *             int UpperBound <the upper limit of valid input>
 * Returns: The valid user input within the specified range.
 * Side effects: Prompts user for input and validates it.
 */
int UserHandling(int LowerBound, int UpperBound);

/*
 * Function: ShootingResultsDisplay
 * Description: Displays the result of each shot (miss, regular shot, money shot).
 * Parameters: int Shot <the result of the shot (1 for a basket, 0 for a miss)>
 * Returns: N/A (void).
 * Side effects: Outputs the shooting result to the console.
 */
void ShootingResultsDisplay(int Shot);

/*
 * Function: Game
 * Description: Manages the gameplay for multiple players.
 * Parameters: int Players <the number of players participating in the game>
 * Returns: N/A (void).
 * Side effects: Calls various functions to simulate a full game session.
 */
void Game(int Players);

/*
 * Function: Shooting
 * Description: Determines if a shot is successful based on the player's shooting ability.
 * Parameters: int ShootingAbility <player's shooting ability (1-99)>
 * Returns: 1 if the shot is successful, 0 otherwise.
 * Side effects: N/A.
 */
int Shooting(int ShootingAbility);

/*
 * Function: Skill
 * Description: Prompts the user to input a shooting ability level.
 * Parameters: N/A.
 * Returns: The shooting ability level (1-99).
 * Side effects: Prompts user for input and validates it.
 */
int Skill();

/*
 * Function: MoneyRack
 * Description: Prompts the user to select the position of the money rack in their shooting rally.
 * Parameters: N/A.
 * Returns: The position of the money rack (1-5).
 * Side effects: Prompts user for input and validates it.
 */
int MoneyRack();

/*
 * Function: ScoreTable
 * Description: Displays and calculates the score for each player after all racks.
 * Parameters: int** Table <mimics 2D array storing players' shot results>
 *             int Players <the number of players>
 *             int* TotalScores <array storing total scores for each player>
 * Returns: N/A (void).
 * Side effects: Outputs the score table to the console.
 */
void ScoreTable(int** Table, int Players, int* TotalScores);

/*
 * Function: WelcomeMessage
 * Description: Displays the welcome message for the game and the number of players.
 * Parameters: int Players <the number of players>.
 * Returns: N/A (void).
 * Side effects: Outputs a welcome message to the console.
 */
void WelcomeMessage(int Players);

/*
 * Function: Winner
 * Description: Determines and displays the winner based on the highest score.
 * Parameters: int* TotalScores <array storing total scores for each player>
 *             int Players <the number of players>
 * Returns: N/A (void).
 * Side effects: Outputs the winner or tie message to the console.
 */
void Winner(int* TotalScores, int Players);

/*
 * Function: DeclareWinner
 * Description: Declares the winner or announces a tie.
 * Parameters: int Index - the index of the player with the highest score.
 *             int HighScore <the highest score achieved>
 *             bool isTie <determines a tie>
 * Returns: N/A (void).
 * Side effects: Outputs the result to the console.
 */
void DeclareWinner(int Index, int HighScore, bool isTie);

/*
 * Function: DoublePoints
 * Description: Doubles the points if the shot is a money shot.
 * Parameters: int index <the shot number within the rack>
 *             int Rack <the current rack number>
 *             int MoneyRack <the position of the money rack>
 *             int result <the result of the shot>
 * Returns: The result of the shot, doubled if it's a money shot.
 * Side effects: Alters the value of a shot made.
 */
int DoublePoints(int index, int Rack, int MoneyRack, int result);

/*
 * Function: StarryHoop
 * Description: Simulates a starry hoop shot and adds points accordingly.
 * Parameters: int ShootingAbility <the player's shooting ability>
 *             int& totalPoints <reference to the total score to update>
 * Returns: N/A (void).
 * Side effects: Updates the total score and outputs the result.
 */
void StarryHoop(int ShootingAbility, int& totalPoints);

/*
 * Function: ProcessRack
 * Description: Processes all shots in a rack, calculating the score for each shot.
 * Parameters: int playerIndex <the index of the current player>
 *             int rackIndex <the current rack number>
 *             int ShootingAbility <the player's shooting ability>
 *             int** Table <2D array storing players' shot results>
 *             int* TotalScores <array storing total scores for each player>
 *             int MoneyBallRack <the position of the money rack>
 * Returns: N/A (void).
 * Side effects: Updates the score and displays the shooting results.
 */
void ProcessRack(int playerIndex, int rackIndex, int ShootingAbility, int** Table, int* TotalScores, int MoneyBallRack);

/*
 * Function: WhereIsStarry
 * Description: Determines if the current shot is a starry shot and processes it.
 * Parameters: int rack <the current rack number>
 *             int ShootingAbility <the player's shooting abilit>
 *             int& totalPoints <reference to the total score to update>
 * Returns: N/A (void).
 * Side effects: Updates the total score and outputs the starry shot result.
 */
void WhereIsStarry(int rack, int ShootingAbility, int& totalPoints);

/*
 * Function: OrdinalSuffix
 * Description: Returns the ordinal suffix for a given number.
 * Parameters: int n <the number to convert to an ordinal suffix>
 * Returns: A string containing the ordinal suffix.
 * Side effects: None.
 */
string OrdinalSuffix(int n);

/*
 * Function: GameHomeScreen
 * Description: Manages the game's home screen and main loop, asking if the players want to play again.
 * Parameters: N/A.
 * Returns: N/A (void).
 * Side effects: Prompts the user for input and calls the Game function.
 */
void GameHomeScreen();

//End of Prototypes

void WelcomeMessage(int Players) {
    cout << "Welcome to All Star Hooping!\n";
    cout << "Get ready to carve your name among the legends of All-Star Hooping!\n";
    cout << "Number of Players: " << Players << endl;
}

void GameHomeScreen() {
    int SessionKey = 1; // While loop exit key
    do {
        cout << "Please indicate the number of players (at least 2):\n";
        int Players = UserHandling(2, RAND_MAX);
        WelcomeMessage(Players);
        Game(Players);
        cout << "More to show? Play Again!\n1 = Yes\n0 = No\n";
        SessionKey = UserHandling(0, 1);
    } while(SessionKey == 1);
}

int** PlayerList(int Players) { 
    int** PlayerTurn = new int*[Players];
    for (int i = 0; i < Players; i++){
        PlayerTurn[i] = new int[5 * 5]; // 5 racks * 5 shots per rack
    }
    return PlayerTurn;
}

void WhereIsStarry(int rack, int ShootingAbility, int& totalPoints) {
    if (rack == 1 || rack == 2){ // After Rack 2 or 3
        cout << "Starry: ";
        StarryHoop(ShootingAbility, totalPoints);
    }
}

void ProcessRack(int Player, int Rack, int ShootingAbility, int** Table, int* TotalScores, int MoneyBallRack) {
    
    int rackPoints = 0;
    cout << "Rack " << Rack + 1 << ": ";
    
    for (int shot = 0; shot < 5; shot++) {
        int result = DoublePoints(shot, Rack, MoneyBallRack, Shooting(ShootingAbility));
        Table[Player][Rack * 5 + shot] = result;  //2D indexing
        
        ShootingResultsDisplay(result); // Display results
        rackPoints += result; // Calculate points
    }
    cout << "| " << rackPoints << " pts" << endl;
    TotalScores[Player] += rackPoints; // Update total points for the player

    // Starry shot check point before moving onto the next rack
    WhereIsStarry(Rack, ShootingAbility, TotalScores[Player]);
}

void ScoreTable(int** Table, int Players, int* TotalScores) {
    for (int player = 0; player < Players; player++) {
        cout << "\nPlayer " << player + 1 << "'s Shooting Results:\n";
        int ShootingAbility = Skill();
        int MoneyBallRack = MoneyRack(); // Placing Money Rack to use in For Loop.

        for (int rack = 0; rack < 5; rack++) {
            ProcessRack(player, rack, ShootingAbility, Table, TotalScores, MoneyBallRack);
        }

        cout << "Total: " << TotalScores[player] << " pts\n"; // Print total points.
    }
}

void StarryHoop(int ShootingAbility, int& totalPoints) {
    int starryShot = Shooting(ShootingAbility); // Shoot Starry Ball.
    
    // Print starry outcome
    if (starryShot == 1) {
        cout << "S \t| 3 pts" << endl;
        totalPoints += 3;
    } else {
        cout << "_ \t| 0 pts" << endl;
    }
}

int DoublePoints(int index, int Rack, int MoneyRack, int result) {
    if((index == 4 && Rack != MoneyRack - 1) || Rack == MoneyRack - 1 ){ // Last shot in a normal rack  or All shots in Money Rack
        return  result * 2; } else                                     // Money ball is worth 2 points
        return result;
}

void Winner(int* TotalScores, int Players) {
    int highestScore = TotalScores[0]; // Set up starting point for comparison
    int winnerIndex = 0;
    bool isTie = false;

    // Find the highest score
    for (int i = 1; i < Players; i++) {
        if (TotalScores[i] > highestScore) {
            highestScore = TotalScores[i];
            winnerIndex = i;
            isTie = false; // No Tie
        } else if (TotalScores[i] == highestScore) {
            isTie = true; // There's a tie
        }
    }
    DeclareWinner(winnerIndex, highestScore, isTie);
}

void DeclareWinner(int Index, int HighScore, bool isTie) {
    if (isTie) {
        cout << "\nIt's a tie!\n";
    } else {
        cout << "\nThe winner is Player " << Index + 1 << " with " << HighScore << " points!\n";
    }
}

void Game(int Players) {
    int** PlayerTurn = PlayerList(Players); // Create dynamic array for players
    int* TotalScores = new int[Players](); // Initialize total score for each player to 0
    
    ScoreTable(PlayerTurn, Players, TotalScores);
    Winner(TotalScores, Players); // Updated winner function

    // Clean up dynamic memory
    for (int i = 0; i < Players; i++) {
        delete[] PlayerTurn[i];
    }
    delete[] PlayerTurn;
    delete[] TotalScores;
}

string OrdinalSuffix(int n) {
    switch(n) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
        default: return "th";
    }
}

int UserHandling(int LowerBound, int UpperBound) {
    int UserInput;
    while(true) {
        cin >> UserInput;
        if (cin.fail() || UserInput < LowerBound || UserInput > UpperBound) {
            cout << "That was not a valid option. Select from the specified options" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return UserInput;
        }
    }
}

int MoneyRack() {
    int WhereIsMoney;
    cout << "Please select the position of the money rack in your shooting rally (1 to 5):\n";
    WhereIsMoney = UserHandling(1, 5); // Valid range 1-5
    cout << "The Money Rack will be at the " << WhereIsMoney << OrdinalSuffix(WhereIsMoney) << " position.\n";
    return WhereIsMoney;
}

int Skill() {
    cout << "Please specify a shooting ability (1 to 99):\n";
    int ShootingAbility = UserHandling(1, 99);
    cout << "Shooting Ability: " << ShootingAbility << endl;
    return ShootingAbility;
}

int Shooting(int ShootingAbility) { 
    if (rand() % 100 + 1 <= ShootingAbility){  // Shot probability based on Shooting Ability
        return 1;
    }
    return 0;
}

void ShootingResultsDisplay(int Shot){
	
    if(Shot == 1){
        cout << 'X';
    } else if (Shot == 2){
        cout << 'M';
    } else
        cout << "_";

}


int main() {
    srand(time(nullptr)); // Seed the PRNG
    GameHomeScreen();
}