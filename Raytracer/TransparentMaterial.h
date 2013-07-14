#ifndef __TRANSPARENTMATERIAL_H
#define __TRANSPARENTMATERIAL_H
#include "Material.h"
#include "World.h"
#include <cmath>
#include "Ray.h"
#include <iostream>

namespace raytracer
{
	template<class T>
	class TransparentMaterial	:	public Material<T>
	{
	private:
		/*Colour<T> diffuseColour;
		Colour<T> SpecularColour;
		Colour<T> ReflectionColour;
		T p;*/
		T Eta;

	public:

		/*TransparentMaterial( const Colour<T>& diffuseColour, const Colour<T>& SpecularColour,const Colour<T>& ReflectionColour,  T p) : diffuseColour(diffuseColour), SpecularColour(SpecularColour),ReflectionColour(ReflectionColour),  p(p)
		{

		}*/

		TransparentMaterial(T Eta)	: Eta ( Eta)
		{
			
		}

		const T& GetEta() const
		{
			return Eta;
		}

		void SetEta( const T& Eta )
		{
			this->Eta = Eta;
		}
		
		virtual Colour<T> ColourAt( const ShadeRecord<T>& sr, const World<T>* w, Tracer<T>* tracer)	const
		{

			T eta = this->GetEta() / w->GetEta();
			math::ColumnVector<T, 3> n = sr.GetN();
			math::ColumnVector<T, 3> e = sr.GetRay()->GetDirection() * -1.0;
			e = e / sr.GetRay()->GetDirection().GetMagnitude();
			auto nd = sr.GetRay()->GetDirection() / sr.GetRay()->GetDirection().GetMagnitude();
			T R0 = pow(( w->GetEta() - this->GetEta()) / ( w->GetEta() + this->GetEta()), 2.0);

			if(e.Dot(n) < 0.0)
			{
				n = n * -1.0;
				eta = w->GetEta() / this->GetEta();
				R0 = pow(( this->GetEta() - w->GetEta()) / (this->GetEta() +  w->GetEta()), 2.0);

			}			
			
			
			T phi1 = e.Dot(n);
			T h = 1.0 -(1 / pow(eta, 2.0)) * (1.0 - pow(phi1, 2.0));
			math::ColumnVector<T, 3> r = nd + 2.0 * phi1 *n;
			math::ColumnVector< T, 3> p = sr.GetRay()->At(sr.GetT());

			Ray<T> reflectionRay(p, r); 
			std::cout << h << std::endl;
			if( h >= 0.0)
			{
				T phi2 = sqrt(h); 

				
				//math::ColumnVector<T, 3> t =  (sr.GetRay()->GetDirection() * eta) - (n * ( phi2 - eta * phi1));
				math::ColumnVector<T, 3> t =  ((1 / eta) * nd) - (n * (phi2 - ((1 / eta) * phi1)));
			
				T R = R0 + ( 1.0 - R0) * pow( 1.0 - phi1, 5.0);
				T T2 = 1.0 - R;
				
				Ray<T> reflectedRay(p, t); 

				auto c1 = tracer->Trace(reflectionRay, *w) * R;
				auto c2 = tracer->Trace(reflectedRay, *w) * T2;
				return c2 + c1; 
				
			}

			return tracer->Trace(reflectionRay, *w);

		}
		

	};
}









#endif