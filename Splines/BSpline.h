#pragma once

using namespace System::Collections::Generic;
using namespace System::Drawing;

ref class BSpline
{
public:

	List<Point>^ vertices;
	List<PointF>^ points;
	

	BSpline(List<Point>^ p);
	~BSpline();


	void FindPoints();

	PointF BSplineFunction(float t);
};

