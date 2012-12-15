
#ifndef __MATRIX_H
#define __MATRIX_H
#include <string>
namespace raytracer 
{
	namespace math
	{
		template< class T, unsigned int ROWS, unsigned int COLUMNS > class Matrix;

		template< class T, unsigned int ROWS, unsigned int COLUMNS >
		bool operator==(const Matrix<T,ROWS,COLUMNS>& lhs, const Matrix<T,ROWS,COLUMNS>& rhs) 
		{
		
			for(int i = 0;i < ROWS; i++)
			{
				for(int j = 0 ; j <  COLUMNS; j++)
				{
					if( lhs.Get(i,j) != rhs.Get(i,j) )
					{
						return false;
					}
				}
			}

			return true;
		}

		template< class T, unsigned int ROWS, unsigned int COLUMNS >
		bool operator!=(const Matrix<T,ROWS,COLUMNS>& lhs, const Matrix<T,ROWS,COLUMNS>& rhs) 
		{
			return !( rhs == lhs);
		}

		template< class T, unsigned int ROWS, unsigned int COLUMNS > class Matrix
		{
		private:
			T m[ROWS * COLUMNS];

		public:
			Matrix(const T& v)
			{
				for (unsigned int i = 0; i < ROWS ; i++ )
				{
					for (unsigned int j = 0; j < COLUMNS; j++ )
					{
						if( i == j)
						{
							this->Set(i, j, v);
						}

						else
						{
							this->Set(i, j, 0);
						}
					}
				}
			}

			const T& Get (const unsigned int row, const unsigned int column ) const
			{
				return m[column + (row * COLUMNS)];
			}

			void Set (const unsigned int row, const unsigned int column, const T& v )
			{
				m[column + (row * COLUMNS)] = v;
			}

			Matrix<T,ROWS,COLUMNS>& operator+= (const Matrix<T,ROWS,COLUMNS>& rhs)
			{
				for (unsigned int i = 0; i < ROWS ; i++ )
				{
					for (unsigned int j = 0; j < COLUMNS; j++ )
					{
						this->Set(i, j, this->Get(i, j) + rhs.Get(i,j));
					}
				}
				return *this;
			}

			Matrix<T,ROWS,COLUMNS>& operator*= (const Matrix<T,COLUMNS,COLUMNS>& rhs)
			{
				Matrix <T,ROWS,COLUMNS> TempMatrix(0);
				for (unsigned int i = 0; i < ROWS ; i++ )
				{
					for (unsigned int j = 0; j < COLUMNS; j++ )
					{

						for (unsigned int k = 0; k < COLUMNS; k++ )
						{
							TempMatrix.Set(i,j, TempMatrix.Get(i, j ) + (this->Get(i, k) * rhs.Get(k, j)));
						}
					}
				}
				*this = TempMatrix;
				return *this;
			}

			
			friend bool operator== <> (const Matrix<T,ROWS,COLUMNS>& lhs, const Matrix<T,ROWS,COLUMNS>& rhs);
			friend bool operator!= <> (const Matrix<T,ROWS,COLUMNS>& lhs, const Matrix<T,ROWS,COLUMNS>& rhs);

		};

		

		template< class T, unsigned int ROWS, unsigned int COLUMNS >
		static std::wstring ToString(const Matrix<T,ROWS,COLUMNS>& t) 
		{ RETURN_WIDE_STRING(""); }
	}
}



#endif 