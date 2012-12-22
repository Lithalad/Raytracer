#include "stdafx.h"
#include "../Math/Matrix.h"
#include "CppUnitTest.h"
#include <stdlib.h>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define ROWS 3
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

		}

		TEST_METHOD(MatrixOperatorMinusEqualsTest)
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
					m3.Set(i, j, testValue1 - testValue2);
				}

			}

			m1 -= m2;
			Assert::AreEqual( m1, m3 );

		}

		TEST_METHOD(MatrixOperatorTimesEqualsTest)
		{
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m1(oneValue);
			raytracer::math::Matrix< TestType, COLUMNS, COLUMNS > m2(oneValue);
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m3(zeroValue);

			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					TestType testValue1 = rand();
					TestType testValue2 = rand();

					m1.Set(i, j, testValue1 );
					m2.Set(i, j, testValue2 );
				}

			}

			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					for(int k = 0; k < COLUMNS ; k++)
					{
						m3.Set(i, j, m1.Get(i, k) * m2.Get(k, j) + m3.Get(i, j));
					}
				}

			}

			m1 *= m2;
			Assert::AreEqual( m1, m3 );

		}

		TEST_METHOD(MatrixOperatorTimesSkalarEqualsTest)
		{
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m1(oneValue);
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m2(oneValue);
			TestType skalar = rand();


			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					TestType testValue = rand();
					

					m1.Set(i, j, testValue );
					m2.Set(i,j, testValue * skalar);
				}

			}

			m1 *= skalar;
			Assert::AreEqual( m1, m2 );

		}

		TEST_METHOD(MatrixOperatorDivEqualsTest)
		{
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m1(oneValue);
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m2(oneValue);
			TestType skalar = rand();


			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					TestType testValue = rand();
					

					m1.Set(i, j, testValue );
					m2.Set(i,j, testValue / skalar);
				}

			}

			m1 /= skalar;
			Assert::AreEqual( m1, m2 );

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

		TEST_METHOD(MatrixGetTransposed)
		{
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m1(oneValue);
			raytracer::math::Matrix< TestType, COLUMNS, ROWS > m2(oneValue);

			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					TestType testValue = rand();
					
					m1.Set(i, j, testValue );
					m2.Set(j, i, testValue );
				
				}
			}

			Assert::AreEqual( m1, m2.GetTransposed() );
			Assert::AreEqual( m1.GetTransposed(), m2 );
			Assert::AreEqual( m1, m1.GetTransposed().GetTransposed() );
		}

		TEST_METHOD(MatrixGetRow)
		{
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m1(oneValue);
			raytracer::math::Matrix< TestType, 1, COLUMNS > m2(oneValue);

			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					TestType testValue = rand();
					
					m1.Set(i, j, testValue );
				}
			}
			
			for( int row = 0; row < ROWS; row++)
			{
				m2 = m1.GetRow(row);
				for( int i = 0; i < COLUMNS; i++)
				{
					Assert::AreEqual( m1.Get(row, i), m2.Get(0, i ));
				}
			}
		}

		TEST_METHOD(MatrixGetColumn)
		{
			raytracer::math::Matrix< TestType, ROWS, COLUMNS > m1(oneValue);
			raytracer::math::Matrix< TestType, ROWS, 1 > m2(oneValue);

			for ( int i = 0; i < ROWS; i++)
			{
				for ( int j = 0; j < COLUMNS ; j++)
				{
					TestType testValue = rand();
					
					m1.Set(i, j, testValue );
				}
			}
			
			for( int column = 0; column < COLUMNS; column++)
			{
				m2 = m1.GetColumn(column);
				for( int i = 0; i < ROWS; i++)
				{
					Assert::AreEqual( m1.Get(i, column), m2.Get(i, 0 ));
				}
			}
		}
	};
}