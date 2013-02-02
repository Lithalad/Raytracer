#ifndef __COLUMNVECTOR_H
#define __COLUMNVECTOR_H
#include "Matrix.h"
#include <cmath>

namespace raytracer 
{
	namespace math
	{
		template< class T, unsigned int SIZE>
		class ColumnVector	:	public Matrix<T, SIZE, 1>
		{
			public:

			ColumnVector() : Matrix(0)
			{
				
			}

			const T& Get ( const unsigned int row ) const
			{
				return this->Get(row,0);
			}

			void Set (const unsigned int row, const T& v )
			{
				this->Set(row,0,v);
			}
		};
	}
}





#endif