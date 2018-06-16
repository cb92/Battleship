# Battleship
C++ implementation of a battleship game in Terminal

## Class Descriptions
### Player
Player is a fairly simple class, with only getter/setter functions, and two constructors (one with and one without input parameters). The three member variables of the Player class - player number, whether the player is automatic, and the name of the player - are used to control gameplay, and interact with the players by name throughout gameplay. In particular, the bool stating whether the player is automatic determines which board initialization and move making functions get called when it is that player's turn.

### Ship
The Ship class creates a dynamically allocated array of characters to represent a ship in the game. A Ship object consists of a size, a name, an array representing the ship in the game, a position (x, y, orientation), and a boolean variable to indicate whether it is sunk or not. Initially, the x and y positions of the ship are set to -1, indicating that they are not yet set. Aside from the use of dynamically allocated memory, the Ship class is straightforward. In addition to the standard getter/setter functions, this class contains all necessary functionality to safely dynamically allocate memory as a part of object creation (copy constructor, destructor, move constructor, a copy assignment operator, and a move assignment operator), as well as a function to determine whether provided x and y coordinates should register a hit on a given ship. The recordHit function returns false if the coordinates provided are not a hit on the ship, and true if they are. Additionally, it changes the character in the hit position to an "X", and if all spots on the ship have been hit, changes the isSunk member variable to true. 

### Board
The Board class provides the underlying structure with which a game is played. A Board object consists of a two-dimensional 10x10 array, a vector of ships with the standard names/sizes of the ships in the classic Battleship game. The class also provides member functions to get the number of hits recorded on the board (to determine if the game has been won by a player), to print the board from the perspective of each player (ie. the opponent of a board only gets to see hits and misses, where the owner of the board gets to see remaining open spots on their ships), to get the value at a given space, record a hit and place a ship given x and y coordinates. The recordHit function actually loops over each ship in the vector for the board, and attempts to record a hit on each one. Additionally, if the move sinks a ship, it informs the user which ship was sunk. The placeShip function performs error checking, and returns false if the placement is invalid (if it falls outside of the board dimensions, if the ship has already been placed, or if the desired placement overlaps with an already placed ship). If the move is a valid one, it places the ship and changes the character values on the board appropriately before returning true. 


### Game




## Gameplay instructions

## Remaining MVP requirements
* Add error protection in Game function for user entries
* 

## Future Work
If I return to this, and decide to expand, future work may include:
* Build out a set of rules for an auto-player to base intelligent gameplay on
* Add sentinel character to end the game early (right now, it will loop until someone wins)