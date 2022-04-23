//
//  TestLibPriv.hpp
//  TestLib
//
//  Created by Kusyumov Nikita on 23.04.2022.
//

/* The classes below are not exported */
#pragma GCC visibility push(hidden)

class TestLibPriv
{
    public:
    std::string getHelloString(std::string);
};

#pragma GCC visibility pop
