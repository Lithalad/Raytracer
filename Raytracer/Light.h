///implementaion of the Light class
///basic ligth class other lights derive from
///inludes get and set for colour, point of origin 
///and a virtual function for seting direction and cheking if visible at a certain point
///
#ifndef __LIGHT_H
#define __LIGHT_H
#include "..\Math\Columnvector.h"
#include "Colour.h"


namespace raytracer
{
	template<class T>
	class World;

	template <class T>
	class Light
	{
		private:

			Colour<T> c;
			math::ColumnVector<T, 3> p;
	
		public:

			Light (const Colour<T>& c , const math::ColumnVector<T, 3>& p) : c (c), p (p)
			{
				
			}

			const Colour< T>& GetColour() const
			{
				return c;
			}

			void SetColour(const Colour< T>& cValue)
			{
				c = cValue;
			}

			const math::ColumnVector< T, 3>& GetP() const
			{
				return p;
			}

			void SetP(const math::ColumnVector< T, 3>& pValue)
			{
				p = pValue;
			}

			virtual bool VisibleAt( const math::ColumnVector<T, 3>& p, const World<T>* world) const = 0;
			virtual math::ColumnVector<T, 3> DirectionFrom(const math::ColumnVector<T, 3>& p) const =0;
	};


}




#endif