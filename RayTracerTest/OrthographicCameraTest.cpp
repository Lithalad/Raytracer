#include "stdafx.h"
#include "../RayTracer/OrthographicCamera.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef double TestType;

namespace RayTracerTest
{
	TEST_CLASS(OrthographicCameraTest)
	{
	public:
		
		TEST_METHOD(OrthographicCameraConstructorTest)
		{

			raytracer::math::ColumnVector< TestType, 3> e( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> g( 0, 0, -1);
			raytracer::math::ColumnVector< TestType, 3> t( 0, 1, 0);
			double s = 1.0;
			
			raytracer::OrthographicCamera<TestType> Cam ( 640,480,e,g,t,s);

			Assert::AreEqual(Cam.GetS(), s);
			Assert::AreEqual(Cam.GetWidth(), 640u);
			Assert::AreEqual(Cam.GetHeight(), 480u);
			Assert::AreEqual(Cam.GetPosition(), e);
			Assert::AreEqual(Cam.GetDirection(), g);
			Assert::AreEqual(Cam.GetUpVector(), t);
			
		}

		TEST_METHOD(OrthographicCameraSetSTest)
		{

			raytracer::math::ColumnVector< TestType, 3> e( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> g( 0, 0, -1);
			raytracer::math::ColumnVector< TestType, 3> t( 0, 1, 0);
			double s = 1.0;
			
			raytracer::OrthographicCamera<TestType> Cam ( 640,480,e,g,t,s);
			Cam.SetS(5.0);

			Assert::AreEqual(Cam.GetS(), 5.0);

		}

		TEST_METHOD(OrthographicCameraRayForTest)
		{
			raytracer::math::ColumnVector< TestType, 3> o( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> d( 0, 0, -1);

			raytracer::Ray< TestType> testRay(o,d); 

			raytracer::math::ColumnVector< TestType, 3> e( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> g( 0, 0, -1);
			raytracer::math::ColumnVector< TestType, 3> t( 0, 1, 0);
			double s = 1.0;

			raytracer::OrthographicCamera<TestType> Cam ( 480,480,e,g,t,s);

			
			//Assert::AreEqual(Cam.RayFor(0,0), testRay);
			Assert::AreEqual(Cam.RayFor(240,240).GetOrigin(), o);
			Assert::AreEqual(Cam.RayFor(0,0).GetDirection(), d);
		}



	};
}