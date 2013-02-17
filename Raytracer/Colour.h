#ifndef __COLOUR_H
#define __COLOUR_H

namespace raytracer
{
	template<class T>
	class Colour
	{
		T red;
		T green;
		T blue;

		public:
		Colour(const T& red, const T& green, const T& blue)	: red( red ), green( green ), blue( blue )
		{
			
		}

		const T& GetRed() const
		{
			return red;
		}

		const T& GetGreen() const
		{
			return green;
		}

		const T& GetBlue() const
		{
			return blue;
		}

		void SetRed( const T& red )
		{
			this->red = red;
		}

		void SetGreen( const T& green )
		{
			this->green = green;
		}

		void SetBlue( const T& blue )
		{
			this->blue = blue;
		}
		
		Colour<T>& operator+= (const Colour<T>& rhs)
		{
			
			this->SetRed(this->GetRed() + rhs.GetRed());
			this->SetGreen(this->GetGreen() + rhs.GetGreen());
			this->SetBlue(this->GetBlue() + rhs.GetBlue());

			return *this;
		}

		Colour<T>& operator*= (const Colour<T>& rhs)
		{
			
			this->SetRed(this->GetRed() * rhs.GetRed());
			this->SetGreen(this->GetGreen() * rhs.GetGreen());
			this->SetBlue(this->GetBlue() * rhs.GetBlue());

			return *this;
		}

		Colour<T>& operator*= (const T& rhs)
		{
			
			this->SetRed(this->GetRed() * rhs);
			this->SetGreen(this->GetGreen() * rhs);
			this->SetBlue(this->GetBlue() * rhs);

			return *this;
		}

	};
}


#endif