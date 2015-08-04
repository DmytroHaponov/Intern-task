/**
    forfunc.h
    Purpose: define function to read the file, sort letters
             in reverse alphabetic order and write them to another file

    @author Dmytro Haponov
    @version 1.3 3/08/15
*/

#ifndef FORFUNC
#define FORFUNC

#endif // FORFUNC

#include <queue>
#include <fstream>
#include <iostream>

using namespace :: std;

//function to read the file,
//sort letters and write to file
void afunc(const char* fileread, const char* filewrite)
{
    char c;
    cout<<"file to read is "<<fileread<<endl;
    ifstream in(fileread); // Open for reading
    try
    {
        if(!in)
        {
            throw "ERROR - cannot open file!!";
        }
    }
    catch(const char * p)
    {
        cerr<<p;
        exit(EXIT_FAILURE);
        return;
    }
//----------------------------------------------------------
    //sort letters by
    //putting them in priority queue
    priority_queue < char, vector<char>, less<char> > chars;
    while (in.get(c))
    {
        if (c == 32)
            continue;
        else
            chars.push(c);
    }
    in.close();
//----------------------------------------------------------
    ofstream out(filewrite); // Open for writing
    try
    {
        if (!out)
        {
            throw "ERROR - cannot write to file";
        }
    }
    catch(const char * p)
    {
        cerr<<p;
        exit(EXIT_FAILURE);
        return;
    }
    cout<<"file to write is "<<filewrite<<endl;
    while (chars.size() > 0)
    {
        out << chars.top() << " ";
        chars.pop();
    }
    out.close();
    cout<<"please check file "<<filewrite;
}
