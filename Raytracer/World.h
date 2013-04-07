#ifndef __WORLD_H
#define __WORLD_H
#include "Colour.h"
#include "Geometry.h"
#include <vector>

namespace raytracer
{
	template<class T>
	class World
	{
		private:

			Colour<T> backgroundColour;
			std::vector< const Geometry<T>* > geometries;  

		public:

			World ( const Colour<T>& bgColour) : backgroundColour (bgColour)
			{
			
			}

			const Colour<T>& GetBackgroundColour() const
			{
				return backgroundColour;
			}

			void SetBackgroundColour(const Colour<T>& bgColour) 
			{
				backgroundColour = bgColour;
			}

			void addGeometry( const Geometry<T>& geo )
			{
				geometries.push_back(&geo );
			}

			void hit( const Ray< T >& ray, ShadeRecord<T>& shadeRecord ) const
			{
				
				for (std::vector< const Geometry<T>*>::const_iterator it = geometries.cbegin(); it != geometries.cend(); ++it)
				{
					(*it)->hit(ray, shadeRecord);

				}
			
			}

	};




}











#endif