#include "stdafx.h"
#include "../RayTracer/ShadeRecord.h"
#include "../RayTracer/Geometry.h"
#include "../RayTracer/Ray.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

typedef double TestType;

namespace RayTracerTest
{
	TEST_CLASS(ShadeRecordTest)
	{
	public:
		
		TEST_METHOD(ShadeRecordConstructorTest)
		{
			raytracer::ShadeRecord<TestType> shadeRecord;
			Assert::AreEqual(shadeRecord.IsValid(), false);
			Assert::AreEqual(shadeRecord.GetT(), 0.0);
			Assert::AreEqual(shadeRecord.GetGeomety(), (raytracer::Geometry<TestType>*)NULL);
			Assert::AreEqual(shadeRecord.GetRay(), (raytracer::Ray<TestType>*)NULL);
		}

		TEST_METHOD(ShadeRecordGetAndSetTTest)
		{
			raytracer::ShadeRecord<TestType> shadeRecord;
			
			shadeRecord.SetT(5.0);
			Assert::AreEqual(shadeRecord.GetT(), 5.0);
		}

		TEST_METHOD(ShadeRecordIsAndSetValidTest)
		{
			raytracer::ShadeRecord<TestType> shadeRecord;
			
			shadeRecord.SetValid(true);
			Assert::AreEqual(shadeRecord.IsValid(), true);
		}

		TEST_METHOD(ShadeRecordGetAndSetGeometryTest)
		{
			raytracer::ShadeRecord<TestType> shadeRecord;
			
			shadeRecord.SetGeometry( (raytracer::Geometry<TestType>*)5);
			Assert::AreEqual(shadeRecord.GetGeomety(),(raytracer::Geometry<TestType>*)5);
		}

		TEST_METHOD(ShadeRecordGetAndSetRayTest)
		{
			raytracer::ShadeRecord<TestType> shadeRecord;
			
			shadeRecord.SetRay( (raytracer::Ray<TestType>*)5);
			Assert::AreEqual(shadeRecord.GetRay(),(raytracer::Ray<TestType>*)5);
		}



	};
}