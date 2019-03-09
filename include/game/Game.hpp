/* ..............................................
  @file Game.hpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-27
  
  
.............................................. */
#ifndef GAME_HPP
#define GAME_HPP
#include <stdlib.h>
#include <ncurses.h>
#include <string>
#include <locale.h>
#include <sys/time.h>
#include "Enemy.hpp"
#include "Console.hpp"
#include "Room.hpp"
#include "Player.hpp"
#include "Door.hpp"
#include "Key.hpp"
#include "Trap.hpp"
#include "Potion.hpp"
#include "Bomb.hpp"
#include "Softblock.hpp"
#include "Movable.hpp"
#include "Movable2.hpp"
#include "Immovable.hpp"
#include "Snorlax.hpp"
#include "Pokeflute.hpp"
#include "Pokeball.hpp"
#include "Statue.hpp"
#include "Profoak.hpp"
#include "Colors.hpp"

#define MAX_ROOMS 20

#define GRASS ' '
#define EMPTY ' '
#define WALL1 '-'
#define WALL2 '|'
#define WALL3 '\\'
#define WALL4 '/'
#define WALL5 '+'
#define DOOR '░'
#define TELEPORTER 'H'

#define WINDOW_WIDTH 150
#define WORLD_WINDOW_HEIGHT 30
#define NARRATIVE_WINDOW_HEIGHT 5
#define STATUS_WINDOW_HEIGHT 5

class Game
{
private:
  bool isComplete;
  bool planted;
  unsigned int userInput;
  clock_t begin_time;
  double elapsedSeconds;
  int bombX, bombY;
  Player player;
  Console devConsole;
  Room *rooms[MAX_ROOMS];
  WINDOW *statusWindow;
  WINDOW *worldWindow;
  WINDOW *inventoryWindow;
  WINDOW *narrativeWindow;
  string narrative;
  WINDOW *developerWindow;
  WINDOW *currentWindow;

public:
  /* ..............................................
    GAME.CPP
    
  .............................................. */

  // CONSTRUCTORS/DESTRUCTORS
  Game();
  ~Game();
  Room* initStartRoom();
  Room* initPuzzleRoom1();
  Room* initPuzzleRoom2();
  Room* initPuzzleRoom3(); //Snorlax
  Room* initPuzzleRoom4();
  Room* initPuzzleRoom5();
  Room* initPuzzleRoom6(); //Bomberman
  Room* initPuzzleRoom7(); //Super Mario Bros part 1
  Room* initPuzzleRoom8();
  Room* initPuzzleRoom9(); //Rodent's Revenge
  Room* initPuzzleRoom10(); //Super Mario Bros part 2
  Room* initPuzzleRoom11(); //end room
  Room* initPuzzleRoom12(); //Invisible Maze
  Room* initPuzzleRoom13(); //repair room
  Room* initPuzzleRoom14(); //trophy/statue room
  Room* initPuzzleRoomX();
  Room* initEndRoom();

  // ACTIONS
  void run();

  /* ..............................................
    PROCESS.CPP
    
  .............................................. */

  // ACTIONS
  void process(); // gets input from the user and stores it in userInput

  /* ..............................................
    UPDATE.CPP
    
  .............................................. */

  // SETTERS
  void setIsComplete(bool isComplete);
  void setPlanted(bool planted);
  void setRoom(Room *room, int roomIndex);
  void setNarrative(string narrative);
  void setCurrentWindow(WINDOW *window);
  void setBombY(int bombY);
  void setBombX(int bombX);

  // GETTERS
  bool getIsComplete();
  bool getPlanted();
  bool isMoveAllowed(int y, int x);
  bool isEnemyMoveAllowed(int y, int x);
  bool isItemMoveAllowed(int y, int x, char direction, Object* object);
  Room *getRoom(int roomIndex);
  string getNarrative();
  WINDOW *getCurrentWindow();
  int getBombY();
  int getBombX();

  // ACTIONS
  void update();
  void updatePlayer();
  void updateEnemies();
  void resolveDoorMovement();
  void useKeyOnOppositeDoor(Door* door);
  void useKey();
  void resolveHealing();                  //user takes healing
  void usePotion(Item* item);
  void resolveDamage();                   //user takes damage
  void resolveMovingItem(char direction); //user pushes an item forward in the direction they are trying to go
  void resolveSnorlax();
  void usePokeball();
  void resolveMovingItem(char direction, Item* item, Object* object); //user pushes an item forward in the direction they are trying to go
  void resolveItemAction(char direction);
  void resolveTeleporterMovement();
  void readItem();
  void pickUpItem();
  void dropItem();
  void displayItemDescriptionToNarrativeWindow(Item *item);
  void giveProfOakSnorlax();
  void resolveBomb();
  void plantBomb(int y, int x);
  void animateBomb();

  /* ..............................................
    RENDER.CPP
    
  .............................................. */

  // ACTIONS
  void render();
  void colorWindow(WINDOW *window, int colorPair);
  void renderCurrentWindow();
  void renderStatus();
  void renderWorld();
  void renderInventory();
  void renderDev();
  void renderNarrative();
  void renderRoom();
  void renderWalls();
  void renderDoors();
  void renderItems();
  void renderPlayer();
  void renderEnemies();
  void renderTeleporters();
  void renderEndScreen();
  void mvwaddchWithColor(int yPos, int xPos, string TILE_SYMBOL, char TILE_PAIR);
};

#endif
