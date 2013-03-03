#ifndef __SHADERECORD_H
#define __SHADERECORD_H
#include "Ray.h"

namespace raytracer
{
	template< class T > class Geometry;

	template <class T>
	class ShadeRecord
	{
		private:
			Geometry<T>* geometry;
			const Ray<T>* ray;
			T t;
			bool valid;

		public:

			ShadeRecord ()	: geometry ( NULL), ray ( NULL), t(0), valid( false)
			{
				
			}

			Geometry<T>* GetGeomety() 
			{
				return geometry;
			}
		
			void SetGeometry (Geometry<T>* geometry)
			{
				this->geometry = geometry;
			}

			const Ray<T>* GetRay() 
			{
				return ray;
			}
		
			void SetRay (const Ray<T>* ray)
			{
				this->ray = ray;
			}

			const T& GetT() 
			{
				return t;
			}
		
			void SetT(const T& t)
			{
				this->t = t;
			}
	
			bool IsValid() const 
			{
				return valid;
			}
		
			void SetValid (const bool valid) 
			{
				this->valid = valid;
			}
	
	
	};

}









#endif