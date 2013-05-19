#ifndef __AXISALIGNEDBOX_H
#define __AXISALIGNEDBOX_H
#include "Geometry.h"
#include "Plane.h"
#include <vector>
#include <iostream>

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

			AxisAlignedBox(const Material<T>* mat,const math::ColumnVector< T, 3>& a, const math::ColumnVector< T, 3>& b)	:	Geometry (mat), a (a), b (b), 
				Left(mat, a, math::ColumnVector< T, 3>( -1, 0, 0) ), 
				Right(mat, b, math::ColumnVector< T, 3>( 1, 0, 0) ), 
				Top(mat, b, math::ColumnVector< T, 3>( 0, 1, 0) ), 
				Bottom(mat, a, math::ColumnVector< T, 3>( 0, -1, 0) ), 
				Near(mat, b, math::ColumnVector< T, 3>( 0, 0, 1) ), 
				Far(mat, a, math::ColumnVector< T, 3>( 0, 0, -1) )
			{
				
			}

			const math::ColumnVector< T, 3>& GetA() const
			{
				return a;
			}

			void SetA(const math::ColumnVector< T, 3>& aValue)
			{
				a = aValue;
				Left.SetA(a);
				Bottom.SetA(a);
				Far.SetA(a);
			}

			const math::ColumnVector< T, 3>& GetB() const
			{
				return b;
			}

			void SetB(const math::ColumnVector< T, 3>& bValue)
			{
				b = bValue;
				Right.SetA(b);
				Top.SetA(b);
				Near.SetA(b);
			}

			virtual void hit( const Ray< T >& ray, ShadeRecord<T>& shadeRecord ) const
			{
				//t = ((a-o)*n)/(d*n);
				std::vector<const Plane<T>*> planes;
				std::vector<const Plane<T>*> visiblePlanes;

				planes.push_back(&Left);
				planes.push_back(&Right);
				planes.push_back(&Bottom);
				planes.push_back(&Top);
				planes.push_back(&Near);
				planes.push_back(&Far);

				for (std::vector< const Plane<T>*>::const_iterator it = planes.cbegin(); it != planes.cend(); ++it)
				{

					if((ray.GetOrigin() - (*it)->GetA()).Dot((*it)->GetN()) > 0)
					{
						visiblePlanes.push_back((*it));
					}

				}

				int size = visiblePlanes.size();

				T biggestT = 0;
				for (std::vector< const Plane<T>*>::const_iterator it = visiblePlanes.cbegin(); it != visiblePlanes.cend(); ++it)
				{
					ShadeRecord<T> shade;

					(*it)->hit( ray, shade);
					
					if( shade.GetT() > biggestT)
					{
						biggestT = shade.GetT();
					}
				}

				 math::ColumnVector< T, 3> p = ray.At(biggestT);

				if(p.X() >= a.X() && p.X() <= b.X() && p.Y() >= a.Y() && p.Y() <= b.Y() && p.Z() >= a.Z() && p.Z() <= b.Z())
				{
					 if ( biggestT > 0 && (!shadeRecord.IsValid() || biggestT < shadeRecord.GetT()))
					 {
						 shadeRecord.SetGeometry(this);
						 shadeRecord.SetRay(&ray);
						 shadeRecord.SetT(biggestT);
						 shadeRecord.SetValid(true);
					 }
				}

			}

	};

}








#endif
