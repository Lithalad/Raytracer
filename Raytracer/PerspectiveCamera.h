#ifndef __PERSPECTIVECAMERA_H
#define __PERSPECTIVECAMERA_H
#include "Camera.h"
#include <cmath>

namespace raytracer
{
	template<class T>
	class PerspectiveCamera	:	public Camera<T>
	{
		private:
			T Angle;
		public:
			PerspectiveCamera( const unsigned int Width, const unsigned int Height,
				const raytracer::math::ColumnVector< T, 3>& Position, 
				const raytracer::math::ColumnVector< T, 3>& Direction,
				const raytracer::math::ColumnVector< T, 3>& UpVector, T Angle) 
				: Camera( Width, Height, Position, Direction, UpVector) , Angle(Angle)
			{
				
			}

			T GetAngle() const
			{
				return Angle;
			}

			void SetAngle(T angle)
			{
				Angle = angle;
			}

			virtual raytracer::Ray<T> RayFor(const unsigned int x, const unsigned int y)
			{
				raytracer::math::ColumnVector< T, 3> o( 0, 0, 0 );
				raytracer::math::ColumnVector< T, 3> d( 0, 0, -1);
				raytracer::math::ColumnVector< T, 3> r( 0, 0, 0);

				//o = e
				//r = ((h/2) / (tan(Angle))) * w *-1 + (px - (( w-1) / 2)) * U + (py - (( h-1) / 2)) * V

				o = GetPosition();
				r = ((GetHeight() / 2) / (tan(Angle))) * GetW() * -1.0 +
					GetU() * ((T)x -((GetWidth() - 1.0) / 2.0)) +
					((T)y -((GetHeight() - 1.0) / 2.0)) * GetV();
				d = r/r.GetMagnitude();

				raytracer::Ray< T> testRay(o,d); 
				

				return testRay;
			}

	};
}















#endif