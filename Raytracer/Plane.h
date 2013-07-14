#ifndef __PLANE_H
#define __PLANE_H
#include "Geometry.h"

namespace raytracer
{
	template<class T>
	class Plane	:	public Geometry<T>
	{
	private:

		math::ColumnVector< T, 3> n;

	public:

		Plane(const Material<T>* mat)	:	Geometry (mat), n (0, 1, 0)
		{

		}

		virtual void hit( const Ray< T >& ray, ShadeRecord<T>& shadeRecord ) const
		{
			//t = ((a-o)*n)/(d*n);

			if ((ray.GetDirection().Dot(n)) != 0)
			{
				math::ColumnVector< T, 3> temp = ray.GetOrigin() * -1.0;
				T t = temp.Dot(n)/ray.GetDirection().Dot(n);

				if ( t > 0.001 && (!shadeRecord.IsValid() || t < shadeRecord.GetT()))
				{
					shadeRecord.SetGeometry(this);
					shadeRecord.SetRay(&ray);
					shadeRecord.SetT(t);
					shadeRecord.SetValid(true);
					shadeRecord.SetN(n);
				}

			}
		}



	};
}

#endif