#ifndef __MATERIAL_H
#define __MATERIAL_H
#include "Colour.h"
#include "ShadeRecord.h"


namespace raytracer
{
	template<class T>
	class World;

	template<class T>
	class Tracer;

	template<class T>
	class Material
	{
	public:
		Material()
		{
			
		}
		
		virtual Colour<T> ColourAt( const ShadeRecord<T>& sr,const  World<T>* w, const Tracer<T>* tracer) const = 0;
		

	};
}









#endif