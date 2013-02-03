#include "stdafx.h"
#include "../Math/ColumnVector.h"
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
		
		TEST_METHOD(ColumnVectorGetMagnitudeTest)
		{
			TestType magnitudeTest = 0;
			TestType magnitudeTest2 = 0;
			raytracer::math::ColumnVector< TestType, SIZE> m;
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


		TEST_METHOD(ColumnVectorDotProducktTest)
		{
			raytracer::math::ColumnVector< TestType, SIZE> m1;
			raytracer::math::ColumnVector< TestType, SIZE> m2;
		
			TestType skalar = 0;
			TestType skalar2 = 0;
			for (int i = 0; i < SIZE; i++)
			{
				m1.Set(i, rand());
				m2.Set(i, rand());
			}

			skalar = m1.Dot(m2);

			for (int i = 0; i < SIZE; i++)
			{
				skalar2 += m1.Get(i) * m2.Get(i);
			}

			Assert::AreEqual(skalar, skalar2);
		}

		TEST_METHOD(ColumnVectorCrossProducktTest)
		{
			raytracer::math::ColumnVector< TestType, SIZE> m1(1,2,3);
			raytracer::math::ColumnVector< TestType, SIZE> m2(-7,8,9);
			raytracer::math::ColumnVector< TestType, SIZE> m3(-6,-30,22);

			
			Assert::AreEqual(m1.cross(m2), m3);
		}

	};
}