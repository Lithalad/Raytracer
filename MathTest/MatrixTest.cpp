#include "stdafx.h"
#include "../Math/Matrix.h"
#include "CppUnitTest.h"
#include <stdlib.h>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define ROWS 4
#define COLUMNS 4

typedef double TestType;
TestType zeroValue = 0.0;
TestType oneValue = 1.0;


namespace MathTest
{		
	TEST_CLASS(MatrixTest)
	{
	public:
		
		TEST_METHOD(MatrixConstructorTest)
		{
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m(oneValue);

			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					if (i == j)
					{
						Assert::AreEqual( m.Get( i, j ), oneValue );
					}

					else
					{
						Assert::AreEqual( m.Get( i, j ), zeroValue );
					}

				}

			}
		}

		TEST_METHOD(MatrixGetSetTest)
		{
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m(oneValue);

			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					TestType testValue = rand();
					m.Set(i, j, testValue );
					Assert::AreEqual( m.Get( i, j ), testValue );
				}

			}
	
		}

		TEST_METHOD(MatrixOperatorPlusEqualsTest)
		{
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m1(oneValue);
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m2(oneValue);
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m3(oneValue);

			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					TestType testValue1 = rand();
					TestType testValue2 = rand();

					m1.Set(i, j, testValue1 );
					m2.Set(i, j, testValue2 );
					m3.Set(i, j, testValue1 + testValue2);
				}

			}

			m1 += m2;
			Assert::AreEqual( m1, m3 );


			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					Assert::AreEqual( m1.Get( i, j ), m3.Get( i, j ) );
				}
			}

		}

		TEST_METHOD(MatrixOperatorAsignTest)
		{
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m1(oneValue);
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m2(oneValue);

			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					TestType testValue = rand();
					m2.Set(i, j, testValue );
				}
			}
			m1 = m2;
			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					Assert::AreEqual( m1.Get( i, j ), m2.Get( i, j ) );
				}
			}
			m1.Set( 0, 0, (TestType)rand() );
			Assert::AreNotEqual( m1.Get( 0, 0 ), m2.Get( 0, 0 ) );
	
		}

		TEST_METHOD(MatrixEqualsTest)
		{
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m1(oneValue);
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m2(oneValue);
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m3(oneValue);

			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					TestType testValue1 = rand();
					TestType testValue2 = rand();

					m1.Set(i, j, testValue1 );
					m2.Set(i, j, testValue1 );
					m3.Set(i, j, testValue2 );
				}
			}
			
			Assert::AreEqual( m1, m2 );
			Assert::AreNotEqual( m1, m3 );
			Assert::AreNotEqual( m2, m3 );
		}

	};
}