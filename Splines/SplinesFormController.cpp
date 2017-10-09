#include "SplinesFormController.h"



SplinesFormController::SplinesFormController(PictureBox^ pb)
{
	this->pictureBox = pb;
	referenceVertices = gcnew List<Point>();
	curvesDrawing = gcnew CurvesDrawing();
	compositeCurvesReferenceVertices = gcnew List<Point>();
	bSplinesCurveVertices = gcnew List<Point>();

	Bitmap^ bm = gcnew Bitmap(1920, 1080);

	pictureBox->Image = bm;

	markers = gcnew List<Marker^>();
}


SplinesFormController::~SplinesFormController()
{
}

void SplinesFormController::OnBezierCurveArbitaryOrderRadioButtonChecked(Point point, bool addToList)
{
	if (addToList)
	{
		referenceVertices->Add(point);
		Marker^ marker = gcnew Marker(point.X, point.Y);

		markers->Add(marker);
	}	

	if (referenceVertices->Count > 0)
	{
		Bitmap^ bm = gcnew Bitmap(pictureBox->Image->Width, pictureBox->Image->Height);
		Bitmap^ resultImage = curvesDrawing->DrawBrezierCurves(bm, referenceVertices);

		delete pictureBox->Image;
		pictureBox->Image = resultImage;
	}
}

void SplinesFormController::OnBezierCurveCompositeRadioButton(Point point, bool addToList)
{

	if (addToList)
	{
		compositeCurvesReferenceVertices->Add(point);
		//Marker^ marker = gcnew Marker(point.X, point.Y);

		//markers->Add(marker);
	}
	

	Bitmap^ bm = gcnew Bitmap(pictureBox->Image);
	Bitmap^ resultImage = curvesDrawing->DrawBrezierThirdOrder(bm, compositeCurvesReferenceVertices);

	delete pictureBox->Image;
	pictureBox->Image = resultImage;

}

void SplinesFormController::OnBSplineCurveRadioButton(Point p, bool addToList)
{
	Bitmap^ bm = gcnew Bitmap(pictureBox->Image->Width, pictureBox->Image->Height);
	Bitmap^ resultImage;
	if (addToList)
	{
		bSplinesCurveVertices->Add(p);
		Marker^ m = gcnew Marker(p.X, p.Y);

		markers->Add(m);
	}
	
	resultImage = curvesDrawing->DrawBSplines(bm, bSplinesCurveVertices);
	
	
	delete pictureBox->Image;
	pictureBox->Image = resultImage;
	
}

void SplinesFormController::OnCloseCurveButtonClick()
{
	Bitmap^ bm = gcnew Bitmap(pictureBox->Image);
	Bitmap^ resultImage = curvesDrawing->DrawCloseCurve(bm, compositeCurvesReferenceVertices);

	delete pictureBox->Image;
	pictureBox->Image = resultImage;

	compositeCurvesReferenceVertices->Clear();

}

void SplinesFormController::OnCloseBSplineButtonClick()
{
	Bitmap^ bm = gcnew Bitmap(pictureBox->Image);
	Bitmap^ resultImage = curvesDrawing->DrawCloseBSpline(bm);

	delete pictureBox->Image;
	pictureBox->Image = resultImage;
}

int SplinesFormController::ChooseMarker(Point p)
{
	int min = 100000;
	int d = 0;
	int index = -1;

	if (markers->Count == 0)
	{
		return -1;
	}

	for each (Marker^ m in markers)
	{
		int r = m->radius;

		if ((p.X <= m->x + r) && (p.X >= m->x - r) && (p.Y <= m->y + r) && (p.Y >= m->y - r))
		{
			d = sqrt((p.X - m->x) * (p.X - m->x) + (p.Y - m->y) * (p.Y - m->y));

			if (d < min)
			{
				min = d;
				index = markers->IndexOf(m);
			}
		}
	}

	return index;

}
