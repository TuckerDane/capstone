/* ..............................................
  @file Console.hpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-27
  
  
.............................................. */
#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <string>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstring>

using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;

class Console
{
private:
  static const int MAX_HEIGHT = 28;
  static const int MAX_WIDTH = 148;
  string logFile;
  char logText[MAX_HEIGHT][MAX_WIDTH];

public:
  // CONSTRUCTORS/DESTRUCTORS
  Console();
  ~Console();

  // SETTERS
  void log(std::string message);

  // GETTERS
  int getNumLogLines();
  int getMaxHeight();
  int getMaxWidth();
  char getLogText(int height, int width);
  string getLogLine(int lineNumber);
};

#endif