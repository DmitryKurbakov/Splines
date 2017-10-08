#include "Algorithms.h"



Algorithms::Algorithms()
{
	
}


Algorithms::~Algorithms()
{
}

void Algorithms::BrezierCurves(List<Point>^ rv)
{
	brezierCurvesPointsList = gcnew List<PointF>();

	for (float t = 0.; t <= 1; t += 0.01)
	{
		brezierCurvesPointsList->Add(BezierFunction(t, rv));
	}
}

void Algorithms::ThirdOrderCurve(List<Point>^ rv)
{
	brezierCompositeCurve = gcnew List<PointF>();

	for (float t = 0.; t <= 1; t += 0.01)
	{
		brezierCompositeCurve->Add(BezierFunction(t, rv));
	}
}

float Algorithms::Fact(float x)
{
	if (x == 0)
		return 1;
	return x*Fact(x - 1);
}

PointF Algorithms::BezierFunction(float t, List<Point>^ rv)
{
	
	array<float>^ c = gcnew array<float>(rv->Count);

	for  (int i = 0; i < c->Length; i++)
	{
		c[i] = (Fact(c->Length - 1) * pow(t, i) * pow(1 - t, c->Length - 1 - i)) /
			(Fact(i) * Fact(c->Length - 1 - i));
	}

	float x = 0.;
	float y = 0.;

	for (int i = 0; i < rv->Count; i++)
	{
		x += c[i] * rv[i].X;
		y += c[i] * rv[i].Y;
	}

	/*float c0 = (1 - t) * (1 - t) * (1 - t);
	float c1 = (1 - t) * (1 - t) * 3 * t;
	float c2 = (1 - t) * t * 3 * t;
	float c3 = t * t * t;

	float x = c0 * rv[0].X + c1 * rv[1].X + c2 * rv[2].X + c3 * rv[3].X;
	float y = c0 * rv[0].Y + c1 * rv[1].Y + c2 * rv[2].Y + c3 * rv[3].Y;*/

	PointF p;
	p.X = x;
	p.Y = y;

	return p;
}



