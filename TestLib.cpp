//
//  TestLib.cpp
//  TestLib
//
//  Created by Kusyumov Nikita on 23.04.2022.
//

#include <iostream>
#include "TestLib.hpp"
#include "TestLibPriv.hpp"

void TestLib::getHelloString(std::string s) {
    TestLibPriv *theObj = new TestLibPriv;
    theObj->getHelloString(s);
    delete theObj;
};

std::string TestLibPriv::getHelloString(std::string s) {
    std::string begining = "Hello, ";
    std::string end = ". Glad to hear you";
    
    std::string greatingsString = begining + s + end;
    return greatingsString;
};
