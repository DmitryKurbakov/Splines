#include "SplinesFormController.h"



SplinesFormController::SplinesFormController(PictureBox^ pb)
{
	this->pictureBox = pb;
	referenceVertices = gcnew List<Point>();
	curvesDrawing = gcnew CurvesDrawing();
	compositeCurvesReferenceVertices = gcnew List<Point>();

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

void SplinesFormController::OnBezierCurveCompositeRadioButton(Point point)
{
	compositeCurvesReferenceVertices->Add(point);

	Bitmap^ bm = gcnew Bitmap(pictureBox->Image);
	Bitmap^ resultImage = curvesDrawing->DrawBrezierThirdOrder(bm, compositeCurvesReferenceVertices);

	delete pictureBox->Image;
	pictureBox->Image = resultImage;
	/*if (compositeCurvesReferenceVertices->Count == 4)
	{
		Bitmap^ bm = gcnew Bitmap(pictureBox->Image->Width, pictureBox->Image->Height);
		Bitmap^ resultImage = curvesDrawing->DrawBrezierCurves(bm, compositeCurvesReferenceVertices);

		delete pictureBox->Image;
		pictureBox->Image = resultImage;
	}

	if (compositeCurvesReferenceVertices->Count > 4 && (compositeCurvesReferenceVertices->Count - 1) % 3 == 0)
	{
		int deltaX = compositeCurvesReferenceVertices[compositeCurvesReferenceVertices->Count - 4].X -
			compositeCurvesReferenceVertices[compositeCurvesReferenceVertices->Count - 5].X;
		int deltaY = compositeCurvesReferenceVertices[compositeCurvesReferenceVertices->Count - 4].Y -
			compositeCurvesReferenceVertices[compositeCurvesReferenceVertices->Count - 5].Y;

		compositeCurvesReferenceVertices[compositeCurvesReferenceVertices->Count - 3].X =
			compositeCurvesReferenceVertices[compositeCurvesReferenceVertices->Count - 4].X + deltaX;

		compositeCurvesReferenceVertices[compositeCurvesReferenceVertices->Count - 3].Y =
			compositeCurvesReferenceVertices[compositeCurvesReferenceVertices->Count - 4].X + deltaY;

		Bitmap^ bm = gcnew Bitmap(pictureBox->Image);
		Bitmap^ resultImage = curvesDrawing->DrawBrezierCurves(bm, compositeCurvesReferenceVertices);

		delete pictureBox->Image;
		pictureBox->Image = resultImage;
	}*/
}
