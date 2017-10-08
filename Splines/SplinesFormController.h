#pragma once

#include "CurvesDrawing.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class SplinesFormController
{

private:
	PictureBox^ pictureBox;
	List<Point>^ referenceVertices;
	CurvesDrawing^ curvesDrawing;

	List<Point>^ compositeCurvesReferenceVertices;

public:
	SplinesFormController(PictureBox^ pb);
	~SplinesFormController();

	void OnBezierCurveArbitaryOrderRadioButtonChecked(Point point);
	void OnBezierCurveCompositeRadioButton(Point point);
	void OnCloseCurveButtonClick();
};

