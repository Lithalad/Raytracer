#ifndef __SQUAREMATRIX_H
#define __SQUAREMATRIX_H
#include "Matrix.h"
#include <cmath>

namespace raytracer 
{
	namespace math
	{
		template< class T, unsigned int SIZE>
		class SquareMatrix	:	public Matrix<T, SIZE, SIZE>
		{
		public:
			SquareMatrix(const T& v) : Matrix(v)
			{
				
			}

			T GetDeterminant() const
			{
				T det = 0;
				for (int i = 0; i < SIZE; i++)
				{
					
					
					det += pow(- 1, i) * Get(0,i) * GetMinor(0,i).GetDeterminant();
		
				}
				return det;
			}

			SquareMatrix<T, SIZE> GetInverse() const
			{
				Matrix< T, SIZE,SIZE*2> tempMatrix(0);
				

				for(int i = 0; i < SIZE;i++)
				{
					for(int j = 0; j < SIZE;j++)
					{
					
						tempMatrix.Set(i,j,this->Get(i,j));

						if( i ==j)
						{
							tempMatrix.Set(i,j + 3,1);
						}

						else
						{
							tempMatrix.Set(i,j + 3,0);
						}
					}
				}

				for(int i = 0, i < SIZE, i++)
				{
					if( tempMatrix.Get(i,i) == 0)
					{
						for(int j = i+1, j < SIZE, j++)
						{
							if( tempMatrix.Get(j,i) != 0)
							{
								Matrix< T, 1,SIZE*2> tempMatrix2(0);
								tempMatrix2 = tempMatrix.GetRow(i);
								tempMatrix.SetRow(i,tempMatrix.GetRow(j));
								tempMatrix.SetRow(j,tempMatrix2);
							}
						}
					}
					tempMatrix.SetRow(i,tempMatrix.GetRow(i) / tempMatrix.Get(i,i) );
					for(int j = i+1, j < SIZE, j++)
					{
						if( tempMatrix.Get(j,i) != 0)
						{
							Matrix< T, 1,SIZE*2> tempMatrix2(0);
							tempMatrix2 = tempMatrix.GetRow(i);
							tempMatrix2 *= tempMatrix.Get( j, i );
							// HIER WEITER
							
						}
					}
				}
			}


			SquareMatrix<T, SIZE - 1> GetMinor(unsigned int row, unsigned int column) const
			{
				SquareMatrix< T, SIZE - 1 > tempMatrix(0);

				for(unsigned int i = 0; i < SIZE; i++)
				{
					int ii = i;
					if (i == row)
					{
						continue;
					}

					if (i > row)
					{
						ii--;
					}

					for(unsigned int j = 0; j < SIZE; j++)
					{
						int jj = j;
						if (j == column)
						{
							continue;
						}

						if (j > column)
						{
							jj--;
						}

						tempMatrix.Set(ii,jj, Get(i,j));
					}
	
				}


				return tempMatrix;
			}
		};

		template < class T >
		class SquareMatrix< T, 2>	:	public Matrix<T, 2, 2>
		{
			public:
			SquareMatrix(const T& v) : Matrix(v)
			{
				
			}

			T GetDeterminant() const
			{
				return Get(0,0) * Get(1,1) - Get(1,0) * Get(0,1);
			}
		};
	}
}

#endif