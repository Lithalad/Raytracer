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
			math::ColumnVector< T, 3> n;
		public:

			Plane(const Material<T>* mat,const math::ColumnVector< T, 3>& a, const math::ColumnVector< T, 3>& n)	:	Geometry (mat), a (a), n (n)
			{
				
			}

			const math::ColumnVector< T, 3>& GetA() const
			{
				return a;
			}

			void SetA(const math::ColumnVector< T, 3>& aValue)
			{
				a = aValue;
			}

			const math::ColumnVector< T, 3>& GetN() const
			{
				return n;
			}

			void SetN(const math::ColumnVector< T, 3>& nValue)
			{
				n = nValue;
			}

			virtual void hit( const Ray< T >& ray, ShadeRecord<T>& shadeRecord ) const
			{
				//t = ((a-o)*n)/(d*n);

				if ((ray.GetDirection().Dot(n)) != 0)
				{
					 T t = (a - ray.GetOrigin()).Dot(n)/ray.GetDirection().Dot(n);

					 if ( t > 0 && (!shadeRecord.IsValid() || t < shadeRecord.GetT()))
					 {
						 shadeRecord.SetGeometry(this);
						 shadeRecord.SetRay(&ray);
						 shadeRecord.SetT(t);
						 shadeRecord.SetValid(true);
					 }

				}
			}



	};
}

#endif