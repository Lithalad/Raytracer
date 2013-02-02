#ifndef __ROWVECTOR_H
#define __ROWVECTOR_H
#include "Matrix.h"
#include <cmath>

namespace raytracer 
{
	namespace math
	{
		template< class T, unsigned int SIZE>
		class RowVector	:	public Matrix<T, 1, SIZE>
		{
			public:

			RowVector() : Matrix(0)
			{
				
			}

			const T& Get ( const unsigned int column ) const
			{
				return Matrix::Get(0,column);
			}

			void Set (const unsigned int column, const T& v )
			{
				Matrix::Set(0,column,v);
			}

			T GetMagnitude(  ) const
			{
				T magnitude = 0;
				for( int i = 0; i < SIZE; i++)
				{
					magnitude += this->Get(i) * this->Get(i);
				}

				return sqrt(magnitude);
			}

			T Dot (const RowVector <T, SIZE>& vector) const
			{
				T skalar = 0;
				for( int i = 0; i < SIZE; i++)
				{
					skalar += vector.Get(i) * this->Get(i);
				}

				return skalar;
			}
		};
	}
}





#endif