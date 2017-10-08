#include "SplinesFormController.h"



SplinesFormController::SplinesFormController(PictureBox^ pb)
{
	this->pictureBox = pb;
	referenceVertices = gcnew List<Point>();
	curvesDrawing = gcnew CurvesDrawing();

	Bitmap^ bm = gcnew Bitmap(800, 600);

	pictureBox->Image = bm;
}


SplinesFormController::~SplinesFormController()
{
}

void SplinesFormController::OnBezierCurveArbitaryOrderRadioButtonChecked(Point point)
{
	referenceVertices->Add(point);

	if (referenceVertices->Count > 1)
	{
		Bitmap^ bm = gcnew Bitmap(pictureBox->Image->Width, pictureBox->Image->Height);
		Bitmap^ resultImage = curvesDrawing->DrawBrezierCurves(bm, referenceVertices);

		delete pictureBox->Image;
		pictureBox->Image = resultImage;
	}
}
