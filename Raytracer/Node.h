#ifndef __NODE_H
#define __NODE_H

#include "Geometry.h"
#include "Transform.h"
#include <vector>

namespace raytracer
{
	template<class T>
	class Node	:	public Geometry<T>
	{
	private:

		std::vector< const Geometry<T>* > geometries;
		Transform<T> transformation;

	public:

		Node(const Transform<T> transformation)	:	transformation(transformation), Geometry (&SingleColourMaterial<T> (Colour<T>(1,1,1)))
		{

		}

		void addGeometry( const Geometry<T>& geo )
		{
			geometries.push_back(&geo );
		}

		const T& GetTransformation() const
		{
			return transformation;
		}

		void SetTransformation( const T& transformation )
		{
			this->transformation = transformation;
		}

		virtual void hit( const Ray< T >& ray, ShadeRecord<T>& shadeRecord ) const
		{

			Ray<T> tempRay = transformation * ray;

			for (std::vector< const Geometry<T>*>::const_iterator it = geometries.cbegin(); it != geometries.cend(); ++it)
			{
				(*it)->hit(tempRay, shadeRecord);

			}

			shadeRecord.SetRay(&ray);
			shadeRecord.SetN(transformation * shadeRecord.GetN());

		}

	};
}




#endif