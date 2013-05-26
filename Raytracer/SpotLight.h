#ifndef __SPOTLIGHT_H
#define __SPOTLIGHT_H
#include "Light.h"
#include <cmath>


namespace raytracer
{

	template<class T>
	class SpotLight	:	public Light<T>
	{
		private:

			math::ColumnVector<T, 3> d;
			T angle;

		public:

			SpotLight(const Colour<T>& c , const math::ColumnVector<T, 3>& p,  const math::ColumnVector<T, 3>& d, T angle) : Light(c, p),  d (d), angle (angle) 
			{
			
			}

			const T& GetAngle() const
			{
				return angle;
			}

			void SetAngle(const Colour< T>& angleValue)
			{
				angle = angleValue;
			}

			const math::ColumnVector< T, 3>& GetD() const
			{
				return d;
			}

			void SetD(const math::ColumnVector< T, 3>& dValue)
			{
				d = dValue;
			}

			virtual bool VisibleAt( const math::ColumnVector<T, 3>& p, const World<T>* world) const
			{
				math::ColumnVector<T, 3> l = p- this->GetP();
				l = l / ( l.GetMagnitude());
				T v = l.cross(d / d.GetMagnitude()).GetMagnitude();

				return v <= sin(angle);
				
			}

			virtual math::ColumnVector<T, 3> DirectionFrom(const math::ColumnVector<T, 3>& p) const
			{
				math::ColumnVector<T, 3> l = this->GetP() - p;

				return l / ( l.GetMagnitude());
			}
	
	
	};



}



#endif