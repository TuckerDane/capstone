/* ..............................................
  @file Colors.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-26
  
  
.............................................. */

#include "Colors.h"

void Game::initColorPairs()
{
    init_pair( RED_ON_BLACK, COLOR_RED, COLOR_BLACK);
    init_pair( RED_ON_GREEN, COLOR_RED, COLOR_GREEN);
    init_pair( RED_ON_YELLOW, COLOR_RED, COLOR_YELLOW);
    init_pair( RED_ON_BLUE, COLOR_RED, COLOR_BLUE);
    init_pair( RED_ON_MAGENTA, COLOR_RED, COLOR_MAGENTA);
    init_pair( RED_ON_CYAN, COLOR_RED, COLOR_CYAN);
    init_pair( RED_ON_WHITE, COLOR_RED, COLOR_WHITE);

    init_pair( BLACK_ON_RED, COLOR_BLACK, COLOR_RED);
    init_pair( BLACK_ON_GREEN, COLOR_BLACK, COLOR_GREEN);
    init_pair( BLACK_ON_YELLOW, COLOR_BLACK, COLOR_YELLOW);
    init_pair( BLACK_ON_BLUE, COLOR_BLACK, COLOR_BLUE);
    init_pair( BLACK_ON_MAGENTA, COLOR_BLACK, COLOR_MAGENTA);
    init_pair( BLACK_ON_CYAN, COLOR_BLACK, COLOR_CYAN);
    init_pair( BLACK_ON_WHITE, COLOR_BLACK, COLOR_WHITE);

    init_pair( GREEN_ON_RED, COLOR_GREEN, COLOR_RED);
    init_pair( GREEN_ON_BLACK, COLOR_GREEN, COLOR_BLACK);
    init_pair( GREEN_ON_YELLOW, COLOR_GREEN, COLOR_YELLOW);
    init_pair( GREEN_ON_BLUE, COLOR_GREEN, COLOR_BLUE);
    init_pair( GREEN_ON_MAGENTA, COLOR_GREEN, COLOR_MAGENTA);
    init_pair( GREEN_ON_CYAN, COLOR_GREEN, COLOR_CYAN);
    init_pair( GREEN_ON_WHITE, COLOR_GREEN, COLOR_WHITE);

    init_pair( YELLOW_ON_GREEN, COLOR_YELLOW, COLOR_GREEN);
    init_pair( YELLOW_ON_BLACK, COLOR_YELLOW, COLOR_BLACK);
    init_pair( YELLOW_ON_CYAN, COLOR_YELLOW, COLOR_CYAN);
    init_pair( YELLOW_ON_BLUE, COLOR_YELLOW, COLOR_BLUE);
    init_pair( YELLOW_ON_MAGENTA, COLOR_YELLOW, COLOR_MAGENTA);
    init_pair( YELLOW_ON_CYAN, COLOR_YELLOW, COLOR_CYAN);
    init_pair( YELLOW_ON_WHITE, COLOR_YELLOW, COLOR_WHITE);

    init_pair( BLUE_ON_GREEN, COLOR_BLUE, COLOR_GREEN);
    init_pair( BLUE_ON_RED, COLOR_BLUE, COLOR_RED);
    init_pair( BLUE_ON_BLACK, COLOR_BLUE, COLOR_BLACK);
    init_pair( BLUE_ON_MAGENTA, COLOR_BLUE, COLOR_MAGENTA);
    init_pair( BLUE_ON_YELLOW, COLOR_BLUE, COLOR_YELLOW);
    init_pair( BLUE_ON_WHITE, COLOR_BLUE, COLOR_WHITE);
    init_pair( BLUE_ON_CYAN, COLOR_BLUE, COLOR_CYAN);

    init_pair( MAGENTA_ON_GREEN, COLOR_MAGENTA, COLOR_GREEN);
    init_pair( MAGENTA_ON_RED, COLOR_MAGENTA, COLOR_RED);
    init_pair( MAGENTA_ON_BLACK, COLOR_MAGENTA, COLOR_BLACK);
    init_pair( MAGENTA_ON_WHITE, COLOR_MAGENTA, COLOR_WHITE);
    init_pair( MAGENTA_ON_YELLOW, COLOR_MAGENTA, COLOR_YELLOW);
    init_pair( MAGENTA_ON_BLUE, COLOR_MAGENTA, COLOR_BLUE);
    init_pair( MAGENTA_ON_CYAN, COLOR_MAGENTA, COLOR_CYAN);

    init_pair( CYAN_ON_GREEN, COLOR_CYAN, COLOR_GREEN);
    init_pair( CYAN_ON_RED, COLOR_CYAN, COLOR_RED);
    init_pair( CYAN_ON_BLACK, COLOR_CYAN, COLOR_BLACK);
    init_pair( CYAN_ON_MAGENTA, COLOR_CYAN, COLOR_MAGENTA);
    init_pair( CYAN_ON_YELLOW, COLOR_CYAN, COLOR_YELLOW);
    init_pair( CYAN_ON_BLUE, COLOR_CYAN, COLOR_BLUE);
    init_pair( CYAN_ON_WHITE, COLOR_CYAN, COLOR_WHITE);

    init_pair( WHITE_ON_GREEN, COLOR_WHITE, COLOR_GREEN);
    init_pair( WHITE_ON_RED, COLOR_WHITE, COLOR_RED);
    init_pair( WHITE_ON_BLACK, COLOR_WHITE, COLOR_BLACK);
    init_pair( WHITE_ON_MAGENTA, COLOR_WHITE, COLOR_MAGENTA);
    init_pair( WHITE_ON_YELLOW, COLOR_WHITE, COLOR_YELLOW);
    init_pair( WHITE_ON_BLUE, COLOR_WHITE, COLOR_BLUE);
    init_pair( WHITE_ON_CYAN, COLOR_WHITE, COLOR_CYAN);
}