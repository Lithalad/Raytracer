#ifndef __AXISALIGNEDBOX_H
#define __AXISALIGNEDBOX_H
#include "Geometry.h"
#include "Plane.h"
#include <vector>
#include <iostream>
#include "Node.h"

#define PI 3.14159

namespace raytracer
{
	template<class T> 
	class AxisAlignedBox	:	public Geometry<T>
	{
		private:

			Node<T> Left;
			Node<T> Right;
			Node<T> Top;
			Node<T> Bottom;
			Node<T> Near;
			Node<T> Far;
			math::ColumnVector< T, 3> a;
			math::ColumnVector< T, 3> b;
			

		public:

			AxisAlignedBox(const Material<T>* mat,const math::ColumnVector< T, 3>& a, const math::ColumnVector< T, 3>& b)	:	Geometry (mat), a (-0.5, -0.5, -0.5), b (0.5, 0.5, 0.5), 

				Left(Transform<T>().Translate(a.X(), a.Y(), a.Z()).RotationZ(PI / 2.0)),		// a
				Right(Transform<T>().Translate(b.X(), b.Y(), b.Z()).RotationZ(PI / 2.0 * -1)),		// b
				Top(Transform<T>().Translate(b.X(), b.Y(), b.Z())),		// b
				Bottom(Transform<T>().Translate(a.X(), a.Y(), a.Z()).RotationZ(PI)),	// a
				Near(Transform<T>().Translate(b.X(), b.Y(), b.Z()).RotationX(PI / 2.0)),		// b
				Far(Transform<T>().Translate(a.X(), a.Y(), a.Z()).RotationX(PI / 2.0 * -1))		// a

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

				ShadeRecord<T> shade;

				for (std::vector< const Node<T>*>::const_iterator it = visiblePlanes.cbegin(); it != visiblePlanes.cend(); ++it)
				{
					

					(*it)->hit( ray, shade);
					
					if( shade.GetT() > biggestT)
					{
						biggestT = shade.GetT();
						//n = (*it)->GetN();
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
						 shadeRecord.SetN(n);
					 }
				}

			}

	};

}








#endif
