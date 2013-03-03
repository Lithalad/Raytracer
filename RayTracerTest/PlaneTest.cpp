#include "stdafx.h"
#include "../RayTracer/Plane.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include <iostream>
#include "../RayTracer/Colour.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef double TestType;
raytracer::math::ColumnVector< TestType, 3> a( 0, 0, 0 );
raytracer::math::ColumnVector< TestType, 3> n( 0, 1, 0 );
raytracer::Colour<TestType> colour(0.5, 0.4, 0.3);

namespace RayTracerTest
{
	TEST_CLASS(PlaneTest)
	{
	public:
		
		TEST_METHOD(PlaneConstuctorTest)
		{
			raytracer::Plane< TestType> plane(colour, a, n);

			Assert::AreEqual(a, plane.GetA());
			Assert::AreEqual(n, plane.GetN());
			Assert::AreEqual(colour, plane.GetColour());
		}

		TEST_METHOD(PlaneGetAndSetATest)
		{
			raytracer::Plane< TestType> plane(colour, a, n);
			raytracer::math::ColumnVector< TestType, 3> a2( 1, 1, 1 );

			plane.SetA(a2);
			Assert::AreEqual(a2, plane.GetA());
			
		}

		TEST_METHOD(PlaneGetAndSetNTest)
		{
			raytracer::Plane< TestType> plane(colour, a, n);
			raytracer::math::ColumnVector< TestType, 3> n2( 0, -1, 0 );

			plane.SetN(n2);
			Assert::AreEqual(n2, plane.GetN());
		}

		TEST_METHOD(PlaneHitTest)
		{
			raytracer::math::ColumnVector< TestType, 3> o( 0, 1, 0 );
			raytracer::math::ColumnVector< TestType, 3> d( 0, -1, 0 );
			raytracer::ShadeRecord<TestType> shadeRecord;
			raytracer::Plane< TestType> plane(colour, a, n);
			raytracer::Ray< TestType> testRay(o,d);

			plane.hit(testRay, shadeRecord);
			
			Assert::AreEqual(shadeRecord.IsValid(), true);
			Assert::AreEqual(shadeRecord.GetT(), 1.0);
			Assert::AreEqual(shadeRecord.GetGeomety(), (raytracer::Geometry<TestType>*) &plane);
			Assert::AreEqual(shadeRecord.GetRay(), (const raytracer::Ray<TestType>*) &testRay);
		}


	};
}