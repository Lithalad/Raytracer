#ifndef __RAY_H
#define __RAY_H
#include "../Math/ColumnVector.h"

namespace raytracer
{
	template<class T>
	class Ray
	{
		private:
			math::ColumnVector< T, 3> Origin;
			math::ColumnVector< T, 3> Direction;

		public:
			Ray(const math::ColumnVector< T, 3>& Origin,const math::ColumnVector< T, 3>& Direction) : Origin( Origin ), Direction( Direction )
			{

			}

			const math::ColumnVector<T,3>& GetOrigin() const
			{
				return Origin;
			}

			void SetOrigin(const math::ColumnVector<T,3>& vector) 
			{
				Origin = vector;
			}

			const math::ColumnVector<T,3>& GetDirection() const
			{
				return Direction;
			}

			void SetDirection(const math::ColumnVector<T,3>& vector) 
			{
				Direction = vector;
			}

			math::ColumnVector<T,3> At(const T& t) const
			{
				return Origin + Direction * t;
			}

			T TOf(const math::ColumnVector<T,3>& p) const
			{
				return (p - Origin).GetMagnitude() / Direction.GetMagnitude();
			}

	};

	template< class T>
	static std::wstring ToString(Ray<T>* t) 
	{ RETURN_WIDE_STRING(""); }
}





#endif