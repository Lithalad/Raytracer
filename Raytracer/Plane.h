#ifndef __PLANE_H
#define __PLANE_H
#include "Geometry.h"

namespace raytracer
{
	template<class T>
	class Plane	:	public Geometry<T>
	{
		private:

			math::ColumnVector< T, 3> a;
			math::ColumnVector< T, 3> h;
		public:

			Plane(const Colour<T>& colour,const math::ColumnVector< T, 3>& a, const math::ColumnVector< T, 3>& n)	:	Geometry (colour), a (a), n (n)
			{
				
			}

	};
}

#endif