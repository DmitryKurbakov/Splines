#pragma once

#include "Algorithms.h"
#include "BSpline.h"

using namespace System::Collections::Generic;

ref class CurvesDrawing :
public Algorithms


{
public:
	List<BSpline^>^ bSplines;

	bool isDrew;

	CurvesDrawing();
	~CurvesDrawing();

	Bitmap^ DrawBrezierCurves(Bitmap^ bm, List<Point>^ points);
	Bitmap^ DrawBrezierThirdOrder(Bitmap^ bm, List<Point>^ points);
	Bitmap^ DrawCloseCurve(Bitmap^ bm, List<Point>^ points);

	Bitmap^ DrawBSplines(Bitmap^ bm, List<Point>^ points);

	Bitmap^ DrawBSplinesUsingList(Bitmap^ bm);
};

