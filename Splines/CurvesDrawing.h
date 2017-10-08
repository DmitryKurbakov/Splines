#pragma once

#include "Algorithms.h"



ref class CurvesDrawing :
public Algorithms

{
public:
	CurvesDrawing();
	~CurvesDrawing();

	Bitmap^ DrawBrezierCurves(Bitmap^ bm, List<Point>^ points);
};

