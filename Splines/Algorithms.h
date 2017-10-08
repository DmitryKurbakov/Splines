#pragma once

#include <cmath>

using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class Algorithms	
{
public:

	List<PointF>^ brezierCurvesPointsList;

	Algorithms();
	~Algorithms();

	void BrezierCurves(List<Point>^ rv);

	float Fact(float x);
	PointF BezierFunction(float t, List<Point>^ rv);
};

