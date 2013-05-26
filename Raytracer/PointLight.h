#ifndef __POINTLIGHT_H
#define __POINTLIGHT_H
#include "Light.h"


namespace raytracer
{
	
	template<class T>
	class PointLight	:	public Light<T>
	{

	public:
		PointLight(const Colour<T>& c , const math::ColumnVector<T, 3>& p) : Light(c, p) 
		{
			
		}

		virtual bool VisibleAt( const math::ColumnVector<T, 3>& p, const World<T>* world) const
		{
			math::ColumnVector<T, 3> l = this->GetP() - p;
			Ray<T> shadowRay (p, l);
			ShadeRecord<T> sr;
			world->hit(shadowRay, sr);

			return (!sr.IsValid() || sr.GetT() > 1);
		}

		virtual math::ColumnVector<T, 3> DirectionFrom(const math::ColumnVector<T, 3>& p) const
		{
			math::ColumnVector<T, 3> l = this->GetP() - p;

			return l / ( l.GetMagnitude());
		}
	
	
	};



}












#endif