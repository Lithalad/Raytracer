#ifndef __LAMBERTMATERIAL_H
#define __LAMBERTMATERIAL_H
#include "Material.h"
#include "World.h"
#include <cmath>

namespace raytracer
{
	template<class T>
	class LambertMaterial	:	public Material<T>
	{
	private:
		Colour<T> colour;

	public:

		LambertMaterial( const Colour<T>& colour) : colour(colour)
		{

		}
		
		virtual Colour<T> ColourAt( const ShadeRecord<T>& sr, const World<T>* w, const Tracer<T>* tracer)	const
		{

			//c = color(ambienlight + (for(lights; colour *( 0 | skalar(n * L))

			Colour<T> c = w->GetAmbientlight();
			std::vector< const Light<T>* > lights = w->Getlights();

			for (std::vector< const Light<T>*>::const_iterator it = lights.cbegin(); it != lights.cend(); ++it)
			{
				if((*it)->VisibleAt(sr.GetRay()->At(sr.GetT()), w))
				{
					Colour<T> lightColour = (*it)->GetColour();
					math::ColumnVector< T, 3> l = (*it)->DirectionFrom(sr.GetRay()->At(sr.GetT()));

					c += lightColour * max(0, l.Dot(sr.GetN()));
				}

			}

			return colour * c;
		}
		

	};
}









#endif