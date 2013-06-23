#ifndef __TRANSFORM_H
#define __TRANSFORM_H
#include "..\Math\SquareMatrix.h"
#include <cmath>


namespace raytracer
{

	template<class T>
	class Transform
	{
	private:

		math::SquareMatrix<T, 4> M;
		math::SquareMatrix<T, 4> I;

	public:

		Transform()	: M (1), I (1)
		{
			
		}

		Transform<T>& Translate (const T x, const T y, const T z)
		{
			math::SquareMatrix<T, 4> Matrix;
			Matrix.Set(0, 3, x);
			Matrix.Set(1, 3, y);
			Matrix.Set(2, 3, z);

			M = M * Matrix;

			math::SquareMatrix<T, 4> Inverse;
			Inverse.Set(0, 3, -x);
			Inverse.Set(1, 3, -y);
			Inverse.Set(2, 3, -z);

			I = Inverse * I;

			return *(this);
		}

		Transform<T>& Scale (const T x, const T y, const T z)
		{
			math::SquareMatrix<T, 4> Matrix;
			Matrix.Set(0, 0, x);
			Matrix.Set(1, 1, y);
			Matrix.Set(2, 2, z);

			M = M * Matrix;

			math::SquareMatrix<T, 4> Inverse;
			Inverse.Set(0, 0, 1/x);
			Inverse.Set(1, 1, 1/y);
			Inverse.Set(2, 2, 1/z);

			I = Inverse * I;

			return *(this);
		}

		Transform<T>& RotationX (const T x)
		{
			math::SquareMatrix<T, 4> Matrix;
			Matrix.Set(1, 1, cos(x));
			Matrix.Set(1, 2, -sin(x));
			Matrix.Set(2, 1, sin(x));
			Matrix.Set(2, 2, cos(x));

			M = M * Matrix;

			math::SquareMatrix<T, 4> Inverse;
			Inverse.Set(1, 1, cos(x));
			Inverse.Set(1, 2, sin(x));
			Inverse.Set(2, 1, -sin(x));
			Inverse.Set(2, 2, cos(x));

			I = Inverse * I;

			return *(this);
		}

		Transform<T>& RotationY (const T y)
		{
			math::SquareMatrix<T, 4> Matrix;
			Matrix.Set(0, 0, cos(y));
			Matrix.Set(0, 2, sin(y));
			Matrix.Set(2, 0, -sin(y));
			Matrix.Set(2, 2, cos(y));

			M = M * Matrix;

			math::SquareMatrix<T, 4> Inverse;
			Inverse.Set(1, 1, cos(y));
			Inverse.Set(0, 2, -sin(y));
			Inverse.Set(2, 0, sin(y));
			Inverse.Set(2, 2, cos(y));

			I = Inverse * I;

			return *(this);
		}

		Transform<T>& RotationZ (const T z)
		{
			math::SquareMatrix<T, 4> Matrix;
			Matrix.Set(0, 0, cos(z));
			Matrix.Set(0, 1, -sin(z));
			Matrix.Set(1, 0, sin(z));
			Matrix.Set(1, 1, cos(z));

			M = M * Matrix;

			math::SquareMatrix<T, 4> Inverse;
			Inverse.Set(0, 0, cos(z));
			Inverse.Set(0, 1, sin(z));
			Inverse.Set(1, 0, -sin(z));
			Inverse.Set(1, 1, cos(z));

			I = Inverse * I;

			return *(this);
		}


	};



}







#endif
