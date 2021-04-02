#ifndef SEGMENT_H
#define SEGMENT_H
#include "date.h"
#pragma once
#include <map>
#include <iostream>
#include <Windows.h>
#include <vector>

void shiftxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int xdigitCheck(char seg,int digit)
{
    int* digitHolder = new int[4];//(int*)malloc(4 * sizeof(int));
    if (seg == 'a' || seg == 'f' || seg == 'd')
    {
        digitHolder[0] = 2;
        digitHolder[1] = 7;
        digitHolder[2] = 14;
        digitHolder[3] = 19;
        return digitHolder[digit];
    }

    else if (seg == 'g' || seg == 'e')//first vertical digit
    {
        digitHolder[0] = 1;
        digitHolder[1] = 6;
        digitHolder[2] = 13;
        digitHolder[3] = 18;
        return digitHolder[digit];
    }
    else if (seg == 'b' || seg == 'c')//second vertical digit
    {
        digitHolder[0] = 4;
        digitHolder[1] = 9;
        digitHolder[2] = 16;
        digitHolder[3] = 21;
        return digitHolder[digit];
    }
    else
    {
        free(digitHolder);
    }
}

int yCoordinate(char seg)
{
    std::map< char, int > yCoo;//declaring map, for constant y digits
    yCoo['a'] = 0;
    yCoo['b'] = 1;
    yCoo['c'] = 3;
    yCoo['d'] = 4;
    yCoo['e'] = 3;
    yCoo['f'] = 2;
    yCoo['g'] = 1;
    return yCoo.find(seg)->second;
}

char* whichSegment(char dir,unsigned int xdigit,unsigned int ydigit) {
    //int digittemp;
    char* elderSegm = new char[2];//(char*)malloc(2 * sizeof(char));
    
    if (dir == 'h') {//adf is hor
        elderSegm[0] = '-';
        elderSegm[1] = '-';
        shiftxy(xdigit, ydigit);
        for (unsigned int i = 0; i < 2; i++)
        {
            std::cout << elderSegm[i];
        }
        return elderSegm;
    }
    else if (dir == 'v') {//or basically vertical symbols
        elderSegm[0] = '|';
        elderSegm[1] = '\n';
        
        shiftxy(xdigit, ydigit);
        for (unsigned int i = 0; i < 2; i++)
            {
                std::cout << elderSegm[i];
            }
    }
    else
        free(elderSegm);
}
void updateScreen()
{
    std::vector<int> date;
    for (unsigned int i = 0; i < 5; i++)//now we get the time as ascii, 0-1 and 3-4. indexes are useful
        //48 to 57 (for '0' to '9')
    {
        date.push_back(timeHand()[i]-48);
        //now 0-1 and 2-3. indexes are good
    }
     date.erase(date.begin() + 2);//deleting trash data, now the size of vector 4
 //   date = date.at(2) - 6;
    for(unsigned int i = 0 ; i < date.size() ; i++){
        switch (date[i])
        {
        case 0:
            whichSegment('h', xdigitCheck('a', i), yCoordinate('a'));
            whichSegment('v', xdigitCheck('b', i), yCoordinate('b'));
            whichSegment('v', xdigitCheck('c', i), yCoordinate('c'));
            whichSegment('h', xdigitCheck('d', i), yCoordinate('d'));
            whichSegment('v', xdigitCheck('e', i), yCoordinate('e'));
            whichSegment('v', xdigitCheck('g', i), yCoordinate('g'));
            break;
        case 1:
            whichSegment('v', xdigitCheck('b', i), yCoordinate('b'));
            whichSegment('v', xdigitCheck('c', i), yCoordinate('c'));
            break;
        case 2:
            whichSegment('h', xdigitCheck('a', i), yCoordinate('a'));
            whichSegment('v', xdigitCheck('b', i), yCoordinate('b'));
            whichSegment('h', xdigitCheck('d', i), yCoordinate('d'));
            whichSegment('v', xdigitCheck('e', i), yCoordinate('e'));
            whichSegment('h', xdigitCheck('f', i), yCoordinate('f'));
            break;
        case 3:
            whichSegment('h', xdigitCheck('a', i), yCoordinate('a'));
            whichSegment('v', xdigitCheck('b', i), yCoordinate('b'));
            whichSegment('v', xdigitCheck('c', i), yCoordinate('c'));
            whichSegment('h', xdigitCheck('d', i), yCoordinate('d'));
            whichSegment('h', xdigitCheck('f', i), yCoordinate('f'));
            break;
        case 4:
            whichSegment('v', xdigitCheck('b', i), yCoordinate('b'));
            whichSegment('v', xdigitCheck('c', i), yCoordinate('c'));
            whichSegment('h', xdigitCheck('f', i), yCoordinate('f'));
            whichSegment('v', xdigitCheck('g', i), yCoordinate('g'));
            break;
        case 5:
            whichSegment('h', xdigitCheck('a', i), yCoordinate('a'));
            whichSegment('v', xdigitCheck('c', i), yCoordinate('c'));
            whichSegment('h', xdigitCheck('d', i), yCoordinate('d'));
            whichSegment('h', xdigitCheck('f', i), yCoordinate('f'));
            whichSegment('v', xdigitCheck('g', i), yCoordinate('g'));
            break;
        case 6:
            whichSegment('h', xdigitCheck('a', i), yCoordinate('a'));
            whichSegment('v', xdigitCheck('c', i), yCoordinate('c'));
            whichSegment('h', xdigitCheck('d', i), yCoordinate('d'));
            whichSegment('v', xdigitCheck('e', i), yCoordinate('e'));
            whichSegment('h', xdigitCheck('f', i), yCoordinate('f'));
            whichSegment('v', xdigitCheck('g', i), yCoordinate('g'));
            break;
        case 7:
            whichSegment('h', xdigitCheck('a', i), yCoordinate('a'));
            whichSegment('v', xdigitCheck('b', i), yCoordinate('b'));
            whichSegment('v', xdigitCheck('c', i), yCoordinate('c'));
            break;
        case 8:
            whichSegment('h', xdigitCheck('a', i), yCoordinate('a'));
            whichSegment('v', xdigitCheck('b', i), yCoordinate('b'));
            whichSegment('v', xdigitCheck('c', i), yCoordinate('c'));
            whichSegment('h', xdigitCheck('d', i), yCoordinate('d'));
            whichSegment('v', xdigitCheck('e', i), yCoordinate('e'));
            whichSegment('h', xdigitCheck('f', i), yCoordinate('f'));
            whichSegment('v', xdigitCheck('g', i), yCoordinate('g'));
            break;
        case 9:
            whichSegment('h', xdigitCheck('a', i), yCoordinate('a'));
            whichSegment('v', xdigitCheck('b', i), yCoordinate('b'));
            whichSegment('v', xdigitCheck('c', i), yCoordinate('c'));
            whichSegment('h', xdigitCheck('d', i), yCoordinate('d'));
            whichSegment('h', xdigitCheck('f', i), yCoordinate('f'));
            whichSegment('v', xdigitCheck('g', i), yCoordinate('g'));
            break;
        }
    }
}



void doubleDot()
{
    shiftxy(11, 1);
    std::cout << '.';
    shiftxy(11, 3);
    std::cout << '.'<<"\n\n";
}
void clearScreen()
{
    Sleep(1000);
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}
#endif