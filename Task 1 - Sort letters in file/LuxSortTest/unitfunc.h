#ifndef UNITFUNC
#define UNITFUNC

#endif // UNITFUNC
#include<fstream>
#include<string>
#include<iostream>

string unitread(const char* testfile)
{
string s;
char cc;
ifstream in(testfile); // Open for reading

while (in.get(cc))
    s += cc;
in.close();
return s;
}
