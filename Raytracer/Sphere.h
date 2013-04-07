#ifndef __SPHERE_H
#define __SPHERE_H
#include "Geometry.h"

namespace raytracer
{
	template<class T>
	class Sphere	:	public Geometry<T>
	{
		private:

			math::ColumnVector< T, 3> c;
			T r;

		public:

			Sphere(const Colour<T>& colour,const math::ColumnVector< T, 3>& c, const T& r)	:	Geometry (colour), r (r), c (c)
			{
				
			}

			const math::ColumnVector< T, 3>& GetC() const
			{
				return c;
			}

			void SetC(const math::ColumnVector< T, 3>& cValue)
			{
				c = cValue;
			}

			const T& GetR() const
			{
				return r;
			}

			void SetR(const T& radius)
			{
				r = radius;
			}

			virtual void hit( const Ray< T >& ray, ShadeRecord<T>& shadeRecord ) const
			{
				

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
