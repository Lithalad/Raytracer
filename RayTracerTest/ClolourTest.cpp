#include "stdafx.h"
#include "../RayTracer/Colour.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef double TestType;


namespace RayTracerTest
{
	TEST_CLASS(ClolourTest)
	{
	public:
		
		TEST_METHOD(ColourGetRedTest)
		{
			raytracer::Colour<TestType> colour(0.5, 0.4, 0.3);

			Assert::AreEqual(colour.GetRed(), 0.5);
		}

		TEST_METHOD(ColourGetGreenTest)
		{
			raytracer::Colour<TestType> colour(0.5, 0.4, 0.3);

			Assert::AreEqual(colour.GetGreen(), 0.4);
		}

		TEST_METHOD(ColourGetBlueTest)
		{
			raytracer::Colour<TestType> colour(0.5, 0.4, 0.3);

			Assert::AreEqual(colour.GetBlue(), 0.3);
		}

		TEST_METHOD(ColourSetRedTest)
		{
			raytracer::Colour<TestType> colour(0.5, 0.4, 0.3);
			colour.SetRed(1.0);

			Assert::AreEqual(colour.GetRed(), 1.0);
		}

		TEST_METHOD(ColourSetGreenTest)
		{
			raytracer::Colour<TestType> colour(0.5, 0.4, 0.3);
			colour.SetGreen(1.0);

			Assert::AreEqual(colour.GetGreen(), 1.0);
		}

		TEST_METHOD(ColourSetBlueTest)
		{
			raytracer::Colour<TestType> colour(0.5, 0.4, 0.3);
			colour.SetBlue(1.0);

			Assert::AreEqual(colour.GetBlue(), 1.0);
		}

		TEST_METHOD(ColourPlusEqualsTest)
		{
			raytracer::Colour<TestType> colour(0.5, 0.5, 0.5);
			colour += colour;

			Assert::AreEqual(colour.GetRed(), 1.0);
			Assert::AreEqual(colour.GetGreen(), 1.0);
			Assert::AreEqual(colour.GetBlue(), 1.0);

		}

		TEST_METHOD(ColourTimesEqualsTest)
		{
			raytracer::Colour<TestType> colour(0.5, 0.5, 0.5);
			colour *= colour;

			Assert::AreEqual(colour.GetRed(), 0.25);
			Assert::AreEqual(colour.GetGreen(), 0.25);
			Assert::AreEqual(colour.GetBlue(), 0.25);

		}

		TEST_METHOD(ColourTimesSkalarTest)
		{
			raytracer::Colour<TestType> colour(0.5, 0.5, 0.5);
			
			colour *= 0.5;

			Assert::AreEqual(colour.GetRed(), 0.25);
			Assert::AreEqual(colour.GetGreen(), 0.25);
			Assert::AreEqual(colour.GetBlue(), 0.25);

		}


	};
}