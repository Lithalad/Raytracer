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


		template < class T >
		class RowVector< T, 3>	:	public Matrix<T, 1, 3>
		{
			public:
			RowVector() : Matrix(0)
			{
				
			}

			RowVector(const T& x, const T& y, const T& z) : Matrix(0)
			{
				this->Set(0,x);
				this->Set(1,y);
				this->Set(2,z);
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
				for( int i = 0; i < 3; i++)
				{
					magnitude += this->Get(i) * this->Get(i);
				}

				return sqrt(magnitude);
			}

			T Dot (const RowVector <T, 3>& vector) const
			{
				T skalar = 0;
				for( int i = 0; i < 3; i++)
				{
					skalar += vector.Get(i) * this->Get(i);
				}

				return skalar;
			}

			const T& X ( ) const
			{
				return this->Get(0);
			}

			const T& Y ( ) const
			{
				return this->Get(1);
			}

			const T& Z ( ) const
			{
				return this->Get(2);
			}

			RowVector<T, 3> cross (const RowVector <T, 3>& vector) const
			{
				return RowVector< T, 3 >( this->Y()*vector.Z()-this->Z()*vector.Y(), this->Z()*vector.X()-this->X()*vector.Z(), this->X()*vector.Y()-this->Y()*vector.X ());  
			}
		};

		template< class T, unsigned int SIZE>
		static std::wstring ToString(const RowVector<T,SIZE>& t) 
		{ RETURN_WIDE_STRING(""); }
	}
}





#endif