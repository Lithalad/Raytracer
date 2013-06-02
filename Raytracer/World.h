#ifndef __WORLD_H
#define __WORLD_H
#include "Colour.h"
#include "Geometry.h"
#include <vector>
#include "Light.h"

namespace raytracer
{
	template<class T>
	class World
	{
		private:

			Colour<T> backgroundColour;
			Colour<T> ambientlight;
			std::vector< const Geometry<T>* > geometries; 
			std::vector< const Light<T>* > lights;
			T Eta;

		public:

			World ( const Colour<T>& bgColour, const Colour<T>& ambientlight, T Eta) : backgroundColour (bgColour), ambientlight(ambientlight), Eta ( Eta)
			{
			
			}

			const Colour<T>& GetBackgroundColour() const
			{
				return backgroundColour;
			}

			void SetBackgroundColour(const Colour<T>& bgColour) 
			{
				backgroundColour = bgColour;
			}

			void addGeometry( const Geometry<T>& geo )
			{
				geometries.push_back(&geo );
			}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

			const Colour<T>& GetAmbientlight() const
			{
				return ambientlight;
			}

			void SetAmbientlight(const Colour<T>& aLight) 
			{
				ambientlight = aLight;
			}

			const std::vector< const Light<T>* >& Getlights() const
			{
				return lights;
			}

			void addLight( const Light<T>& light )
			{
				lights.push_back(&light );
			}

			const T& GetEta() const
			{
				return Eta;
			}

			void SetEta( const T& Eta )
			{
				this->Eta = Eta;
			}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

			void hit( const Ray< T >& ray, ShadeRecord<T>& shadeRecord ) const
			{
				
				for (std::vector< const Geometry<T>*>::const_iterator it = geometries.cbegin(); it != geometries.cend(); ++it)
				{
					(*it)->hit(ray, shadeRecord);

				}
			
			}

	};




}











#endif