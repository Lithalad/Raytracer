// Playground.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../Math/Matrix.h"


int _tmain(int argc, _TCHAR* argv[])
{
	raytracer::math::Matrix< double, 4, 4 > m1( 1.0 );
	raytracer::math::Matrix< double, 4, 4 > m2( 1.0 );
	m1 == m2;
	return 0;
}

