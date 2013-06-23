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

		unsigned int counter;

		Tracer() : counter( 20 )
		{
		}

		Colour<T> Trace( const Ray<T> &ray, const World<T> &world)
		{
			if( counter == 0 )
			{
				return Colour< T >( 1.0, 0.0, 0.0 );
			}
			raytracer::ShadeRecord<T> shadeRecord;
			--counter;
			world.hit(ray, shadeRecord);

								
			if (shadeRecord.IsValid())		
			{
				
				auto c = shadeRecord.GetGeomety()->GetMaterial()->ColourAt(shadeRecord, &world, this);
				++counter;
				return c;

			}

			else
			{
				++counter;
				return world.GetBackgroundColour();
			}
			


		}



	};
}












					

					
					







#endif