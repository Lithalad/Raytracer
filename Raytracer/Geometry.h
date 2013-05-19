#ifndef __GEOMETRY_H
#define __GEOMETRY_H
#include "Colour.h"
#include "Ray.h"
#include "ShadeRecord.h"
#include "Material.h"


namespace raytracer
{
	template<class T> 
	class Geometry
	{
		private:

			const Material<T>* mat;

		public:
			Geometry( const Material<T>* mat) : mat (mat)
			{
			
			}

			const Material<T>* GetMaterial() const
			{
				return mat;
			}

			void SetMaterial( const Material<T>* mat )
			{
				this->mat = mat;
			}

			virtual void hit( const Ray< T >& ray, ShadeRecord<T>& shadeRecord ) const = 0;

	};

	template< class T>
	static std::wstring ToString(const Geometry<T>* t) 
	{ RETURN_WIDE_STRING(""); }
}





#endif