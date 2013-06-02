#ifndef __PHONGMATERIAL_H
#define __PHONGMATERIAL_H
#include "Material.h"
#include "World.h"
#include <cmath>

namespace raytracer
{
	template<class T>
	class PhongMaterial	:	public Material<T>
	{
	private:
		Colour<T> diffuseColour;
		Colour<T> SpecularColour;
		T p;

	public:

		PhongMaterial( const Colour<T>& diffuseColour,  const Colour<T>& SpecularColour, T p) : diffuseColour(diffuseColour), SpecularColour(SpecularColour), p(p)
		{

		}
		
		virtual Colour<T> ColourAt( const ShadeRecord<T>& sr, const World<T>* w, const Tracer<T>* tracer)	const
		{

			//c = color(ambienlight + (for(lights; colour *( 0 | skalar(n * L))

			Colour<T> c = w->GetAmbientlight() * diffuseColour;
			std::vector< const Light<T>* > lights = w->Getlights();

			for (std::vector< const Light<T>*>::const_iterator it = lights.cbegin(); it != lights.cend(); ++it)
			{
				if((*it)->VisibleAt(sr.GetRay()->At(sr.GetT()), w))
				{
					Colour<T> lightColour = (*it)->GetColour();
					math::ColumnVector< T, 3> l = (*it)->DirectionFrom(sr.GetRay()->At(sr.GetT()));
					math::ColumnVector< T, 3> r = l * -1.0 + (2 * sr.GetN().Dot(l) * sr.GetN());
					math::ColumnVector< T, 3> e = sr.GetRay()->GetDirection() * -1.0;

					c += diffuseColour * lightColour * max(0, l.Dot(sr.GetN()));
					c += SpecularColour * lightColour * pow(max(0, r.Dot(e)), p);
				}

			}

			return c;
		}
		

	};
}









#endif