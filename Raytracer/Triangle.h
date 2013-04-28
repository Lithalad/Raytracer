#ifndef __TRIANGLE_H
#define __TRIANGLE_H
#include "Geometry.h"
#include "../Math/SquareMatrix.h"


namespace raytracer
{
	template<class T> 
	class Triangle	:	public Geometry<T>
	{

		private:

			math::ColumnVector< T, 3> a;
			math::ColumnVector< T, 3> b;
			math::ColumnVector< T, 3> c;
			

		public:

			Triangle(const Colour<T>& colour,const math::ColumnVector< T, 3>& a, const math::ColumnVector< T, 3>& b, const math::ColumnVector< T, 3>& c )	:	Geometry (colour), a (a), b (b), c (c)
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

			const math::ColumnVector< T, 3>& GetB() const
			{
				return b;
			}

			void SetB(const math::ColumnVector< T, 3>& bValue)
			{
				b = bValue;
			}

			const math::ColumnVector< T, 3>& GetC() const
			{
				return c;
			}

			void SetC(const math::ColumnVector< T, 3>& cValue)
			{
				c = cValue;
			}

			virtual void hit( const Ray< T >& ray, ShadeRecord<T>& shadeRecord ) const
			{
				
				math::SquareMatrix <T,3> m(0);
				m.SetColumn(0, a - b);
				m.SetColumn(1, a - c);
				m.SetColumn(2, ray.GetDirection());

				math::ColumnVector<T,3> v = a - ray.GetOrigin();

				math::SquareMatrix <T,3> m1 = m;
				math::SquareMatrix <T,3> m2 = m;
				math::SquareMatrix <T,3> m3 = m;

				m1.SetColumn(0,v);
				m2.SetColumn(1,v);
				m3.SetColumn(2,v);

				T beta = m1.GetDeterminant()/ m.GetDeterminant();
				T gamma = m2.GetDeterminant()/ m.GetDeterminant();
				T t = m3.GetDeterminant()/ m.GetDeterminant();

				if( beta >= 0 && beta <= 1 && gamma >= 0 && gamma <= 1 && (beta + gamma) <= 1 && t > 0)
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