#ifndef __AXISALIGNEDBOX_H
#define __AXISALIGNEDBOX_H
#include "Geometry.h"
#include "Plane.h"

namespace raytracer
{
	template<class T> 
	class AxisAlignedBox	:	public Geometry<T>
	{
		private:

			Plane<T> Left;
			Plane<T> Right;
			Plane<T> Top;
			Plane<T> Bottom;
			Plane<T> Near;
			Plane<T> Far;
			math::ColumnVector< T, 3> a;
			math::ColumnVector< T, 3> b;

		public:

			AxisAlignedBox(const Colour<T>& colour,const math::ColumnVector< T, 3>& a, const math::ColumnVector< T, 3>& b)	:	Geometry (colour), a (a), b (b)
			{
				
			}



	};

}








#endif
