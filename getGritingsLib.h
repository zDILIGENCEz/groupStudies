//
//  getGritingsLib.h
//  TestLib
//
//  Created by Kusyumov Nikita on 23.04.2022.
//

#ifndef getGritingsLib_h
#define getGritingsLib_h

using namespace std;

string getHelloString(string name)
{
    string begining = "Hello, ";
    string end = ". Glad to hear you";
    
    string greatingsString = begining + name + end;
    return greatingsString;
}

#endif /* getGritingsLib_h */
