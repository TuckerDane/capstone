/* ..............................................
  @ file Console.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019
  
  
.............................................. */
#include "Console.hpp"

/* ..............................................
  CONSTRUCTORS/DECONSTRUCTORS
  
.............................................. */
Console::Console()
{
    string pid = std::to_string(getpid());
    this->logFile = "logs/adventure_" + pid + ".log";
    ofstream lf(this->logFile);
    lf << "LOG: " + pid << std::endl;
    lf.close();
}

Console::~Console()
{
}

/* ..............................................
  SETTERS

.............................................. */

/* ..............................................
  GETTERS
  
.............................................. */
int Console::getNumLogLines()
{
    string s;
    int lines = 0;
    ifstream lf;
    lf.open(this->logFile);
    while (!lf.eof())
    {
        getline(lf, s);
        lines++;
    }
    lf.close();
    return lines;
}

int Console::getMaxHeight()
{
    return MAX_HEIGHT;
}

int Console::getMaxWidth()
{
    return MAX_WIDTH;
}

char Console::getLogText(int height, int width)
{
    return logText[height][width];
}

string Console::getLogLine(int lineNumber)
{
    string s;
    int lines = 0;
    ifstream lf;
    lf.open(this->logFile);
    while (lines != lineNumber)
    {
        getline(lf, s);
        lines++;
    }
    lf.close();
    return s;
}

/* ..............................................
  ACTIONS
  
.............................................. */
void Console::log(std::string message)
{
    ofstream lf;
    lf.open(this->logFile, std::ios_base::app);
    lf << message << std::endl;
    lf.close();
}