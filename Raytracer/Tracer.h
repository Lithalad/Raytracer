#ifndef __TRACER_H
#define __TRACER_H
#include "../Math/ColumnVector.h"
#include "Ray.h"
#include "Colour.h"
#include "ShadeRecord.h"
#include "World.h"

namespace raytracer
{

	template<class T>
	class Tracer
	{
	public:

		Colour<T> Trace( const Ray<T> &ray, const World<T> &world)	const
		{
			raytracer::ShadeRecord<T> shadeRecord;
			world.hit(ray, shadeRecord);

								
			if (shadeRecord.IsValid())		
			{
				return shadeRecord.GetGeomety()->GetMaterial()->ColourAt(shadeRecord, &world, this);
			}

			else
			{
				return world.GetBackgroundColour();
			}


		}



	};
}












					

					
					







#endif