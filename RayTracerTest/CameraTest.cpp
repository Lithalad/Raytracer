#include "stdafx.h"
#include "../RayTracer/Camera.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef double TestType;

namespace RayTracerTest
{
	template<class T>
	class TestCamera : public raytracer::Camera<T>
	{
		public:
			TestCamera( const unsigned int Width, const unsigned int Height,
				const raytracer::math::ColumnVector< T, 3>& Position, 
				const raytracer::math::ColumnVector< T, 3>& Direction,
				const raytracer::math::ColumnVector< T, 3>& UpVector) 
				: Camera( Width, Height, Position, Direction, UpVector)
			{
				
			}

			virtual raytracer::Ray<T> RayFor(const unsigned int x, const unsigned int y)
			{
				raytracer::math::ColumnVector< TestType, 3> o( 0, 0, 0 );
				raytracer::math::ColumnVector< TestType, 3> d( 0, 0, -1);

				raytracer::Ray< TestType> testRay(o,d); 

				return testRay;
			}
	};


	TEST_CLASS(CameraTest)
	{
	public:
		
		TEST_METHOD(CameraConstructorTest)
		{
			raytracer::math::ColumnVector< TestType, 3> e( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> g( 0, 0, -1);
			raytracer::math::ColumnVector< TestType, 3> t( 0, 1, 0);

			raytracer::math::ColumnVector< TestType, 3> x( 1, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> y( 0, 1, 0);
			raytracer::math::ColumnVector< TestType, 3> z( 0, 0, 1);

			TestCamera<TestType> Cam( 640, 480, e, g, t);

			Assert::AreEqual(Cam.GetWidth(), 640u);
			Assert::AreEqual(Cam.GetHeight(), 480u);
			Assert::AreEqual(Cam.GetPosition(), e);
			Assert::AreEqual(Cam.GetDirection(), g);
			Assert::AreEqual(Cam.GetUpVector(), t);

			Assert::AreEqual(Cam.GetU(), x);
			Assert::AreEqual(Cam.GetV(), y);
			Assert::AreEqual(Cam.GetW(), z);
		}

		TEST_METHOD(CameraSetWidthTest)
		{
			raytracer::math::ColumnVector< TestType, 3> e( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> g( 0, 0, -1);
			raytracer::math::ColumnVector< TestType, 3> t( 0, 1, 0);
			unsigned int Width = 640;

			TestCamera<TestType> Cam( Width, 480, e, g, t);
			Cam.SetWidth(1920);

			Assert::AreEqual(Cam.GetWidth(), 1920u);

		}

		TEST_METHOD(CameraSetHeightTest)
		{
			raytracer::math::ColumnVector< TestType, 3> e( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> g( 0, 0, -1);
			raytracer::math::ColumnVector< TestType, 3> t( 0, 1, 0);
			unsigned int Height = 480;

			TestCamera<TestType> Cam( 640, Height, e, g, t);
			Cam.SetHeight(1080);

			Assert::AreEqual(Cam.GetHeight(), 1080u);

		}

		TEST_METHOD(CameraSetPositionTest)
		{
			raytracer::math::ColumnVector< TestType, 3> e( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> g( 0, 0, -1);
			raytracer::math::ColumnVector< TestType, 3> t( 0, 1, 0);

			raytracer::math::ColumnVector< TestType, 3> testVector( 1, 1, 1);
			
			TestCamera<TestType> Cam( 640, 480, e, g, t);

			Cam.SetPosition(testVector);

			Assert::AreEqual(Cam.GetPosition(), testVector);

		}

		TEST_METHOD(CameraSetDirectionTest)
		{
			raytracer::math::ColumnVector< TestType, 3> e( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> g( 0, 0, -1);
			raytracer::math::ColumnVector< TestType, 3> t( 0, 1, 0);

			raytracer::math::ColumnVector< TestType, 3> x( -1, 0, 0);
			raytracer::math::ColumnVector< TestType, 3> y( 0, 1, 0);
			raytracer::math::ColumnVector< TestType, 3> z( 0, 0, -1);

			raytracer::math::ColumnVector< TestType, 3> testVector( 0, 0, 1);
			
			TestCamera<TestType> Cam( 640, 480, e, g, t);

			Cam.SetDirection(testVector);

			Assert::AreEqual(Cam.GetDirection(), testVector);
			Assert::AreEqual(Cam.GetU(), x);
			Assert::AreEqual(Cam.GetV(), y);
			Assert::AreEqual(Cam.GetW(), z);

		}

		TEST_METHOD(CameraSetUpVectorTest)
		{
			raytracer::math::ColumnVector< TestType, 3> e( 0, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> g( 0, 0, -1);
			raytracer::math::ColumnVector< TestType, 3> t( 0, 1, 0);

			raytracer::math::ColumnVector< TestType, 3> x( -1, 0, 0 );
			raytracer::math::ColumnVector< TestType, 3> y( 0, -1, 0);
			raytracer::math::ColumnVector< TestType, 3> z( 0, 0, 1);

			raytracer::math::ColumnVector< TestType, 3> testVector( 0, -1, 0);
			
			TestCamera<TestType> Cam( 640, 480, e, g, t);

			Cam.SetUpVector(testVector);

			Assert::AreEqual(Cam.GetUpVector(), testVector);
			Assert::AreEqual(Cam.GetU(), x);
			Assert::AreEqual(Cam.GetV(), y);
			Assert::AreEqual(Cam.GetW(), z);

		}


	};
}