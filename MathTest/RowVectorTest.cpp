#include "stdafx.h"
#include "../Math/RowVector.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include <iostream>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

#define SIZE 3

typedef double TestType;
extern TestType zeroValue;
extern TestType oneValue;

namespace MathTest
{
	TEST_CLASS(RowVectorTest)
	{
	public:
		
		TEST_METHOD(GetMagnitudeTest)
		{
			TestType magnitudeTest = 0;
			TestType magnitudeTest2 = 0;
			raytracer::math::RowVector< TestType, SIZE> m;
			srand( 100 );
			for(int i = 0; i < SIZE; i++)
			{
				TestType num = rand();
				m.Set(i, num);
				magnitudeTest2 += num * num;
			}
			magnitudeTest2 = sqrt(magnitudeTest2);
			magnitudeTest = m.GetMagnitude();

			Assert::AreEqual(magnitudeTest, magnitudeTest2);
		
		}

	};
}