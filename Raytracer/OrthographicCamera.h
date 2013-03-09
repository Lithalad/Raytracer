#ifndef __ORTHOGRAPHICCAMERA_H
#define __ORTHOGRAPHICCAMERA_H
#include "Camera.h"


namespace raytracer
{
	template<class T>
	class OrthographicCamera	:	public Camera<T>
	{
		private:
			T S;
		public:
			OrthographicCamera( const unsigned int Width, const unsigned int Height,
				const raytracer::math::ColumnVector< T, 3>& Position, 
				const raytracer::math::ColumnVector< T, 3>& Direction,
				const raytracer::math::ColumnVector< T, 3>& UpVector, T S) 
				: Camera( Width, Height, Position, Direction, UpVector) , S(S)
			{
				
			}

			T GetS() const
			{
				return S;
			}

			void SetS(T s)
			{
				S = s;
			}

			virtual raytracer::Ray<T> RayFor(const unsigned int x, const unsigned int y)
			{
				raytracer::math::ColumnVector< TestType, 3> o( 0, 0, 0 );
				raytracer::math::ColumnVector< TestType, 3> d( 0, 0, -1);

				//d = -w;

				//o = e + a * s * ((px-((w-1)/2)) / ( w - 1)) * u + s *  ((py-((h-1)/2)) / ( h - 1)) *v;

				d = GetW() * -1.0;
				o = GetPosition() +
					(GetWidth() / GetHeight()) * S * ((x - ((GetWidth() -1) / 2)) / (GetWidth() - 1)) * GetU() +
					S * ((y - ((GetHeight() -1) / 2)) / (GetHeight() - 1)) * GetV();

				
				raytracer::Ray< TestType> testRay(o,d); 

				return testRay;
			}

	};
}














#endif