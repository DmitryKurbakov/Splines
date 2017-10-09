#pragma once

#include "CurvesDrawing.h"
#include "Marker.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class SplinesFormController
{

private:
	PictureBox^ pictureBox;
	

public:

	List<Point>^ referenceVertices;
	List<Point>^ compositeCurvesReferenceVertices;
	List<Point>^ bSplinesCurveVertices;

	CurvesDrawing^ curvesDrawing;



	bool isDrag = false;

	List<Marker^>^ markers;

	SplinesFormController(PictureBox^ pb);
	~SplinesFormController();

	void OnBezierCurveArbitaryOrderRadioButtonChecked(Point point, bool addToList);
	void OnBezierCurveCompositeRadioButton(Point point, bool addToList);
	void OnBSplineCurveRadioButton(Point p, bool addToList);

	void OnCloseCurveButtonClick();
	void OnCloseBSplineButtonClick();

	int ChooseMarker(Point p);
};

