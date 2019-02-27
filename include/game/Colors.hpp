/* ..............................................
  @file Colors.hpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-26
  
  
.............................................. */
#ifndef COLORS_HPP
#define COLORS_HPP

#include <ncurses.h>

#define COLOR_BLACK 0
#define COLOR_RED 1
#define COLOR_GREEN 2
#define COLOR_YELLOW 3
#define COLOR_BLUE 4
#define COLOR_MAGENTA 5
#define COLOR_CYAN 6
#define COLOR_WHITE 7

#define RED_ON_BLACK 1
#define RED_ON_GREEN 2
#define RED_ON_YELLOW 3
#define RED_ON_BLUE 4
#define RED_ON_MAGENTA 5
#define RED_ON_CYAN 6
#define RED_ON_WHITE 7

#define BLACK_ON_RED 8
#define BLACK_ON_GREEN 9
#define BLACK_ON_YELLOW 10
#define BLACK_ON_BLUE 11
#define BLACK_ON_MAGENTA 12
#define BLACK_ON_CYAN 13
#define BLACK_ON_WHITE 14

#define GREEN_ON_BLACK 15
#define GREEN_ON_RED 16
#define GREEN_ON_YELLOW 17
#define GREEN_ON_BLUE 18
#define GREEN_ON_MAGENTA 19
#define GREEN_ON_CYAN 20
#define GREEN_ON_WHITE 21

#define YELLOW_ON_GREEN 22
#define YELLOW_ON_BLACK 23
#define YELLOW_ON_RED 24
#define YELLOW_ON_BLUE 25
#define YELLOW_ON_MAGENTA 26
#define YELLOW_ON_CYAN 27
#define YELLOW_ON_WHITE 28

#define BLUE_ON_GREEN 29
#define BLUE_ON_BLACK 30
#define BLUE_ON_RED 31
#define BLUE_ON_YELLOW 32
#define BLUE_ON_MAGENTA 33
#define BLUE_ON_CYAN 34
#define BLUE_ON_WHITE 35

#define MAGENTA_ON_GREEN 36
#define MAGENTA_ON_BLACK 37
#define MAGENTA_ON_RED 38
#define MAGENTA_ON_YELLOW 39
#define MAGENTA_ON_BLUE 40
#define MAGENTA_ON_CYAN 41
#define MAGENTA_ON_WHITE 42

#define CYAN_ON_GREEN 43
#define CYAN_ON_BLACK 44
#define CYAN_ON_RED 45
#define CYAN_ON_YELLOW 46
#define CYAN_ON_BLUE 47
#define CYAN_ON_MAGENTA 48
#define CYAN_ON_WHITE 49

#define WHITE_ON_GREEN 50
#define WHITE_ON_BLACK 51
#define WHITE_ON_RED 52
#define WHITE_ON_YELLOW 53
#define WHITE_ON_BLUE 54
#define WHITE_ON_MAGENTA 55
#define WHITE_ON_CYAN 56

#define RED_ON_RED 57
#define BLACK_ON_BLACK 58
#define GREEN_ON_GREEN 59
#define YELLOW_ON_YELLOW 60
#define BLUE_ON_BLUE 61
#define MAGENTA_ON_MAGENTA 62
#define CYAN_ON_CYAN 63
#define WHITE_ON_WHITE 64

#define WINDOW_WIDTH 150
#define WORLD_WINDOW_HEIGHT 30
#define NARRATIVE_WINDOW_HEIGHT 5
#define STATUS_WINDOW_HEIGHT 5

void initColorPairs();

#endif