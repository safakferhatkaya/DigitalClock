#define _CRT_SECURE_NO_WARNINGS
#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <time.h>
//#include <string.h>
//#include <stdlib.h>
#pragma once

std::string getNowHhMm()
{
    time_t now = time(0);
    tm* localtm = localtime(&now);
    char buff[sizeof("hh:mm")];
    strftime(buff, sizeof(buff), "%H:%M", localtm);
    //std::cout<<buff<<std::endl;
    return buff;
}

char* timeHand()
{
    char* date = nullptr;
    int length;
    length = getNowHhMm().length();
    date = (char*)malloc(length * sizeof(char*));

    strcpy(date, getNowHhMm().c_str());

    //date info, in the buff char array
    //printf("%d\n\n",date[0]);//it works
    return date; //date's 0 and 1'st elements have hours, 3 and 4 have minute information,
}
#endif