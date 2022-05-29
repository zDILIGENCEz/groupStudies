//
//  myLib.h
//  TestLib
//
//  Created by Kusyumov Nikita on 23.04.2022.
//

#include <iostream>
#include <vector>

using namespace std;
namespace myLib
{
    // Returns greating string
    static string getHelloString(string name);

    static vector<int> getOptimalPath(string file, int startPointID, int endPointID);
}
