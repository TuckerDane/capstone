/* ..............................................
  @file Console.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-27
  
  
.............................................. */
#include "Console.h"

Console::Console()
{
    string pid = std::to_string(getpid());
    this->logFile = "logs/adventure_" + pid + ".log";
    ofstream lf (this->logFile);
    lf << "LOG: " + pid << std::endl;
    lf.close();
}

Console::~Console()
{

}

void Console::log(std::string message)
{
    ofstream lf;
    lf.open(this->logFile, std::ios_base::app);
    lf << message << std::endl;
    lf.close();
}

int Console::getNumLogLines()
{
    string s;
    int lines = 0;
    ifstream lf;
    lf.open(this->logFile);
    while(!lf.eof()) {
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
    while(lines != lineNumber) {
        getline(lf, s);
        lines++;	
    }
    lf.close();	
    return s;
}