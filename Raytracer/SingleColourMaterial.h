#ifndef __SINGLECOLOURMATERIAL_H
#define __SINGLECOLOURMATERIAL_H
#include "Material.h"

namespace raytracer
{
	template<class T>
	class SingleColourMaterial	:	public Material<T>
	{
	private:
		Colour<T> colour;

	public:

		SingleColourMaterial( const Colour<T>& colour) : colour(colour)
		{

		}
		
		virtual Colour<T> ColourAt( const ShadeRecord<T>& sr, const World<T>* w, const Tracer<T>* tracer)	const
		{
			return colour;
		}
		

	};
}









#endif