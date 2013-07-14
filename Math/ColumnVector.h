#ifndef __COLUMNVECTOR_H
#define __COLUMNVECTOR_H
#include "Matrix.h"
#include <cmath>

namespace raytracer 
{
	namespace math
	{

		template< class T, unsigned int SIZE> class ColumnVector;//	:	public Matrix<T, SIZE, 1>;

		template< class T, unsigned int ROWS, unsigned int COLUMNS>
		ColumnVector<T, ROWS> operator*(const Matrix<T,ROWS,COLUMNS>& lhs, const ColumnVector<T, ROWS>& rhs) 
		{
			ColumnVector<T, ROWS> tempVector;
			for(unsigned int i = 0; i < ROWS; i++)
			{
				for( unsigned int k = 0; k < COLUMNS; k++)
				{
					tempVector.Set(i, tempVector.Get(i) + lhs.Get(i,k) * rhs.Get(k));
				}
				
			}
			return tempVector;
		}

		template< class T, unsigned int SIZE >
		ColumnVector<T,SIZE> operator*(const T lhs, const ColumnVector<T,SIZE>& rhs) 
		{
			ColumnVector<T,SIZE> tempMatrix;
			for(unsigned int i = 0; i < SIZE; i++)
			{
				tempMatrix.Set(i, lhs * rhs.Get(i));
			}

			return tempMatrix;
		}

		template< class T, unsigned int SIZE>
		ColumnVector<T,SIZE> operator*(const ColumnVector<T,SIZE>& lhs, const T rhs) 
		{
			ColumnVector<T,SIZE> tempMatrix;
			for(unsigned int i = 0; i < SIZE; i++)
			{
				tempMatrix.Set(i, lhs.Get(i) * rhs);
			}

			return tempMatrix;
		}

		template< class T, unsigned int SIZE>
		ColumnVector<T,SIZE> operator/(const ColumnVector<T,SIZE>& lhs, const T& rhs) 
		{
			ColumnVector<T,SIZE> tempMatrix;
			for(unsigned int i = 0; i < SIZE; i++)
			{
				tempMatrix.Set(i, lhs.Get(i) / rhs);
			}

			return tempMatrix;
		}

		
		template< class T, unsigned int SIZE >
		ColumnVector<T,SIZE> operator+(const ColumnVector<T,SIZE>& lhs, const ColumnVector<T,SIZE>& rhs) 
		{
			ColumnVector<T,SIZE> tempMatrix;
			for(unsigned int i = 0; i < SIZE; i++)
			{
				tempMatrix.Set(i, lhs.Get(i) + rhs.Get(i));
			}

			return tempMatrix;
		}

		template< class T, unsigned int SIZE >
		ColumnVector<T,SIZE> operator-(const ColumnVector<T,SIZE>& lhs, const ColumnVector<T,SIZE>& rhs) 
		{
			ColumnVector<T,SIZE> tempMatrix;
			for(unsigned int i = 0; i < SIZE; i++)
			{
				tempMatrix.Set(i, lhs.Get(i) - rhs.Get(i));
			}

			return tempMatrix;
		}

		template< class T, unsigned int SIZE>
		class ColumnVector	:	public Matrix<T, SIZE, 1>
		{
			public:

			ColumnVector() : Matrix(0)
			{
				
			}

			const T& Get ( const unsigned int row ) const
			{
				return Matrix<T, SIZE, 1>::Get(row,0);
			}

			void Set (const unsigned int row, const T& v )
			{
				Matrix<T, SIZE, 1>::Set(row,0,v);
			}

			T GetMagnitude() const
			{
				T magnitude = 0;
				for( int i = 0; i < SIZE; i++)
				{
					magnitude += this->Get(i) * this->Get(i);
				}

				return sqrt(magnitude);
			}

			T Dot (const ColumnVector <T, SIZE>& vector) const
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
		class ColumnVector< T, 3>	:	public Matrix<T, 3, 1>
		{
			public:
			ColumnVector() : Matrix(0)
			{
				
			}

			ColumnVector(const T& x, const T& y, const T& z) : Matrix(0)
			{
				this->Set(0,x);
				this->Set(1,y);
				this->Set(2,z);
			}

			const T& Get ( const unsigned int row ) const
			{
				return Matrix<T, 3, 1>::Get(row,0);
			}

			void Set (const unsigned int row, const T& v )
			{
				Matrix<T, 3, 1>::Set(row,0,v);
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

			T Dot (const ColumnVector <T, 3>& vector) const
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

			ColumnVector<T, 3> cross (const ColumnVector <T, 3>& vector) const
			{
				return ColumnVector< T, 3 >( this->Y()*vector.Z()-this->Z()*vector.Y(), this->Z()*vector.X()-this->X()*vector.Z(), this->X()*vector.Y()-this->Y()*vector.X ());  
			}
		};

		template< class T, unsigned int SIZE>
		static std::wstring ToString(const ColumnVector<T,SIZE>& t) 
		{ RETURN_WIDE_STRING(""); }
	}
}




#endif