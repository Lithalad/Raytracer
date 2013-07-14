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

			Sphere(const Material<T>* mat)	:	Geometry (mat), r (1.0), c (0, 0, 0)
			{
				
			}

			virtual void hit( const Ray< T >& ray, ShadeRecord<T>& shadeRecord ) const
			{
				
				//x1,2= (-b +- sqrt(b^2-4ac) ) / 2a

				// a = d * d
				// b = d*(2*(o-c))
				// c = (o - c) * (o - c) - r^2

				auto omc = ray.GetOrigin() - this->c;
				T a = ray.GetDirection().Dot(ray.GetDirection());
				T b = ray.GetDirection().Dot( omc * 2.0 );
				
				T c = omc.Dot(omc) - r*r;
				T d = b*b - 4.0 * a * c;

				if( d < 0)
				{
					return;
				}

				if( d == 0)
				{
					T t = -b / (2.0 * a);


					if ( t > 0.001 && (!shadeRecord.IsValid() || t < shadeRecord.GetT()))
					{
						auto n = (ray.At(t) - this->c) / ( (ray.At(t) - this->c).GetMagnitude());

						shadeRecord.SetGeometry(this);
						shadeRecord.SetRay(&ray);
						shadeRecord.SetT(t);
						shadeRecord.SetValid(true);
						shadeRecord.SetN(n);
					}
				}

				if( d > 0)
				{
					T t = 0;
					T t1 = (-b + sqrt(d)) / ( 2.0 * a);
					T t2 = (-b - sqrt(d)) / ( 2.0 * a);

					if( t1 <= 0.0 && t2 <= 0.0)
					{
						return;
					}

					else
					{
						if(t2 >= 0.00001)
						{
							t = t2;
						}

						else if( t1 >= 0.00001)
						{
							t = t1;
						} else return;
					}


					if ( t > 0.00001 && (!shadeRecord.IsValid() || t < shadeRecord.GetT()))
					{

						auto n = (ray.At(t) - this->c) / ( (ray.At(t) - this->c).GetMagnitude());

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
