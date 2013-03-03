#ifndef __CAMERA_H
#define __CAMERA_H
#include "../Math/ColumnVector.h"


namespace raytracer
{
	template<class T>
	class Camera 
	{	
		private:
			math::ColumnVector< T, 3> Position;
			math::ColumnVector< T, 3> Direction;
			math::ColumnVector< T, 3> UpVector;
			unsigned int H;
			unsigned int W;

		public:
			Camera( const unsigned int W, const unsigned int H,
				const math::ColumnVector< T, 3>& Position, 
				const math::ColumnVector< T, 3>& Direction,
				const math::ColumnVector< T, 3>& UpVector) 
				: Position( Position ),
				Direction( Direction ),
				UpVector( UpVector ),
				H( H ), W( W )
			{
			
			}


	
	};
}








#endif