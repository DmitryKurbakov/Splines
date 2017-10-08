#include "CurvesDrawing.h"



CurvesDrawing::CurvesDrawing()
{
}


CurvesDrawing::~CurvesDrawing()
{
}

Bitmap ^ CurvesDrawing::DrawBrezierCurves(Bitmap ^ bm, List<Point>^ points)
{
	BrezierCurves(points);

	Graphics^ gr = Graphics::FromImage(bm);
	Pen^ pen = gcnew Pen(Color::Blue);

	for (int i = 0; i < brezierCurvesPointsList->Count - 1; i++)
	{
		gr->DrawLine(pen, brezierCurvesPointsList[i].X, brezierCurvesPointsList[i].Y,
			brezierCurvesPointsList[i + 1].X, brezierCurvesPointsList[i + 1].Y);
	}

	delete gr;
	delete pen;

	return bm;
}
