#ifndef __CAMERA_H
#define __CAMERA_H
#include "../Math/ColumnVector.h"
#include "Ray.h"


namespace raytracer
{
	template<class T>
	class Camera 
	{	
		private:
			math::ColumnVector< T, 3> Position;
			math::ColumnVector< T, 3> Direction;
			math::ColumnVector< T, 3> UpVector;
			math::ColumnVector< T, 3> U;
			math::ColumnVector< T, 3> V;
			math::ColumnVector< T, 3> W;
			unsigned int Height;
			unsigned int Width;

			void CalcUVW()
			{
				//U = t x w / |t x w|
				//V = w x u
				//W = - g / |g|
				

				W = (Direction / Direction.GetMagnitude()) * -1.0;
				U = (UpVector.cross(W)) / (UpVector.cross(W)).GetMagnitude();
				V = W.cross(U);
			}

		public:
			Camera( const unsigned int Width, const unsigned int Height,
				const math::ColumnVector< T, 3>& Position, 
				const math::ColumnVector< T, 3>& Direction,
				const math::ColumnVector< T, 3>& UpVector) 
				: Position( Position ),
				Direction( Direction ),
				UpVector( UpVector ),
				Height( Height ), Width( Width )
			{
				this->CalcUVW();
			}

			virtual Ray<T> RayFor(const unsigned int x, const unsigned int y) = 0;

			const math::ColumnVector< T, 3>& GetPosition() const
			{
				return Position; 
			}

			void SetPosition( const math::ColumnVector< T, 3>& position)
			{
				Position = position;
			}

			const math::ColumnVector< T, 3>& GetDirection() const
			{
				return Direction; 
			}

			void SetDirection( const math::ColumnVector< T, 3>& direction)
			{
				Direction = direction;
				this->CalcUVW();
			}

			const math::ColumnVector< T, 3>& GetUpVector() const
			{
				return UpVector; 
			}

			void SetUpVector( const math::ColumnVector< T, 3>& upVector)
			{
				UpVector = upVector;
				this->CalcUVW();
			}
			
			unsigned int GetWidth() const
			{
				return Width;
			}

			void SetWidth(const unsigned int w)
			{
				Width = w;
			}

			unsigned int GetHeight() const
			{
				return Height;
			}

			void SetHeight(const unsigned int h) 
			{
				Height = h;
			}

			const math::ColumnVector< T, 3>& GetU()
			{
				return U;
			}

			const math::ColumnVector< T, 3>& GetV()
			{
				return V;
			}

			const math::ColumnVector< T, 3>& GetW()
			{
				return W;
			}

	
	};
}








#endif