#ifndef __DIRECTIONALLIGHT_H
#define __DIRECTIONALLIGHT_H
#include "Light.h"


namespace raytracer
{
	
	template<class T>
	class DirectionalLight	:	public Light<T>
	{
		private:

			math::ColumnVector<T, 3> d;

		public:
			DirectionalLight(const Colour<T>& c , const math::ColumnVector<T, 3>& p, const math::ColumnVector<T, 3>& d) : Light(c, p), d (d)
			{
			
			}

			const math::ColumnVector< T, 3>& GetD() const
			{
				return d;
			}

			void SetD(const math::ColumnVector< T, 3>& dValue)
			{
				d = dValue;
			}

			virtual bool VisibleAt( const math::ColumnVector<T, 3>& p) const
			{
				return true;
			}

			virtual math::ColumnVector<T, 3> DirectionFrom(const math::ColumnVector<T, 3>& p) const
			{
				return d * -1;
			}
	
	
	};



}












#endif