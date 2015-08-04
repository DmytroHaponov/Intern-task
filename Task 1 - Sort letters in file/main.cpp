/**
    main.cpp
    Purpose: open file, read letters like "A B C R K H H F D I E F G B N T O H G H F J K L F D",
              sort them in reverse alphabetic order and write to another file

    @author Dmytro Haponov
    @version 1.3 3/08/15
*/

#include <queue>
#include <fstream>
#include <iostream>

#include "forfunc.h"

using namespace :: std;

int main()
{
    char read[55], write[55];
    cout<<"enter full path and name of file to read"<<endl;
    cin>>read;
    cout<<"enter full path and name of file to write"<<endl;
    cin>>write;
    afunc(read, write);
}

