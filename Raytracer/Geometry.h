#ifndef __GEOMETRY_H
#define __GEOMETRY_H
#include "Colour.h"
#include "Ray.h"
#include "ShadeRecord.h"


namespace raytracer
{
	template<class T> 
	class Geometry
	{
		private:
			Colour< T > colour;

		public:
			Geometry( const Colour<T>& colour) : colour (colour)
			{
			
			}

			const Colour<T>& GetColour() const
			{
				return colour;
			}

			void SetColour( const Colour<T>& colour )
			{
				this->Colour = colour;
			}

			virtual void hit( const Ray< T >& ray, ShadeRecord<T>& shadeRecord ) = 0;

	};

	template< class T>
	static std::wstring ToString(Geometry<T>* t) 
	{ RETURN_WIDE_STRING(""); }
}





#endif