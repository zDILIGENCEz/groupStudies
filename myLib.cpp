//
//  myLib.cpp
//  TestLib
//
//  Created by Kusyumov Nikita on 23.04.2022.
//

#include "myLib.h"

namespace myLib
{
    string getHelloString(string name)
    {
        string begining = "Hello, ";
        string end = ". Glad to hear you";
        
        string greatingsString = begining + name + end;
        return greatingsString;
    }
}
