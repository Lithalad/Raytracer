#include "stdafx.h"
#include "../RayTracer/Ray.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef double TestType;

namespace RayTracerTest
{
	TEST_CLASS(RayTest)
	{
	public:
		
		TEST_METHOD(RayGetOriginTest)
		{
			raytracer::math::ColumnVector< TestType, 3> o( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> d( 0, 0, -1);

			raytracer::Ray< TestType> testRay(o,d); 

			Assert::AreEqual(testRay.GetOrigin(), o);
		}

		TEST_METHOD(RaySetOriginTest)
		{
			raytracer::math::ColumnVector< TestType, 3> o1( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> o2( 1, 1, 1 );
			raytracer::math::ColumnVector< TestType, 3> d( 0, 0, -1);

			raytracer::Ray< TestType> testRay(o1,d); 

			testRay.SetOrigin(o2);
			Assert::AreEqual(testRay.GetOrigin(), o2);
			Assert::AreNotEqual(testRay.GetOrigin(), o1);
		}

		TEST_METHOD(RayGetDirectionTest)
		{
			raytracer::math::ColumnVector< TestType, 3> o( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> d( 0, 0, -1);

			raytracer::Ray< TestType> testRay(o,d); 

			Assert::AreEqual(testRay.GetDirection(), d);
		}

		TEST_METHOD(RaySetDirectionTest)
		{
			raytracer::math::ColumnVector< TestType, 3> o1( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> d1( 0, 0, -1);
			raytracer::math::ColumnVector< TestType, 3> d2( 0, 0, 1);

			raytracer::Ray< TestType> testRay(o1,d1); 

			testRay.SetDirection(d2);
			Assert::AreEqual(testRay.GetDirection(), d2);
			Assert::AreNotEqual(testRay.GetDirection(), d1);
		}

		TEST_METHOD(RayAtTest)
		{
			raytracer::math::ColumnVector< TestType, 3> o( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> d( 0, 0, -1);
			
			raytracer::Ray< TestType> testRay(o,d); 
			
			raytracer::math::ColumnVector< TestType, 3> p = testRay.At(5);
			raytracer::math::ColumnVector< TestType, 3> p2 = o + d * 5.0;


			Assert::AreEqual(p, p2);
	
		}

		TEST_METHOD(RaytOfTest)
		{
			raytracer::math::ColumnVector< TestType, 3> o( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> d( 0, 0, -1);
			
			raytracer::Ray< TestType> testRay(o,d); 
			
			raytracer::math::ColumnVector< TestType, 3> p = testRay.At(5);
	
			Assert::AreEqual(testRay.TOf(p), 5.0);
	
		}

	};
}