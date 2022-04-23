//
//  myLib.h
//  TestLib
//
//  Created by Kusyumov Nikita on 23.04.2022.
//

#include <iostream>

using namespace std;
namespace myLib
{
    class Greatings
    {
    public:
        // Returns greating string
        static string getHelloString(string name);
    };
}
