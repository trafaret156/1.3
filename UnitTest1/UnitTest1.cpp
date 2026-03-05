#include "pch.h"
#include "CppUnitTest.h"
#include "../1.3/Money.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MoneyTests
{
    TEST_CLASS(MoneyLogicTests)
    {
    public:

        TEST_METHOD(TestAddition)
        {
            Money m1, m2;
            int h1[9] = { 0, 0, 0, 0, 0, 0, 0, 1, 0 }; 
            int p1[6] = { 1, 0, 0, 0, 0, 0 };          
            m1.Init(h1, p1); 

            int h2[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 1 }; 
            int p2[6] = { 0, 1, 0, 0, 0, 0 }; 
            m2.Init(h2, p2);

            Money result = m1.Add(m2);

            Assert::AreEqual(std::string("3,75"), result.ToString());
        }
    };
}