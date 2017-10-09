#include "BSpline.h"



BSpline::BSpline(List<Point>^ p)
{
	vertices = p;
	
}


BSpline::~BSpline()
{
}

void BSpline::FindPoints()
{
	points = gcnew List<PointF>();
	for (float t = 0; t <= 1; t += 0.01)
	{
		points->Add(BSplineFunction(t));
	}
}

PointF BSpline::BSplineFunction(float t)
{

	float k0 = (1 - t) * (1 - t) * (1 - t);
	float k1 = 3 * t * t * t - 6 * t * t + 4;
	float k2 = -3 * t * t * t + 3 * t * t + 3 * t + 1;
	float k3 = t * t * t;

	float x0 = k0 * vertices[0].X;
	float x1 = k1 * vertices[1].X;
	float x2 = k2 * vertices[2].X;
	float x3 = k3 * vertices[3].X;

	float y0 = k0 * vertices[0].Y;
	float y1 = k1 * vertices[1].Y;
	float y2 = k2 * vertices[2].Y;
	float y3 = k3 * vertices[3].Y;

	float xS = x0 + x1 + x2 + x3;
	float yS = y0 + y1 + y2 + y3;

	float x = 0.17 * xS;
	float y = 0.17 * yS;

	PointF p;
	p.X = x;
	p.Y = y;

	return p;
}


