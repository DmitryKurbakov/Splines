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
	Pen^ bluePen = gcnew Pen(Color::Blue);
	Pen^ blackPen = gcnew Pen(Color::Black);

	for (int i = 0; i < brezierCurvesPointsList->Count - 1; i++)
	{
		gr->DrawLine(bluePen, brezierCurvesPointsList[i].X, brezierCurvesPointsList[i].Y,
			brezierCurvesPointsList[i + 1].X, brezierCurvesPointsList[i + 1].Y);
	}

	for (int i = 0; i < points->Count - 1; i++)
	{
		gr->DrawLine(blackPen, points[i].X, points[i].Y, points[i + 1].X, points[i + 1].Y);
	}

	delete gr;
	delete bluePen;
	delete blackPen;
	return bm;
}

Bitmap ^ CurvesDrawing::DrawBrezierThirdOrder(Bitmap ^ bm, List<Point>^ points)
{
	if (points->Count == 4)
	{
		ThirdOrderCurve(points);

		Graphics^ gr = Graphics::FromImage(bm);
		Pen^ bluePen = gcnew Pen(Color::Blue);
		Pen^ blackPen = gcnew Pen(Color::Black);

		for (int i = 0; i < brezierCompositeCurve->Count - 1; i++)
		{
			gr->DrawLine(bluePen, brezierCompositeCurve[i].X, brezierCompositeCurve[i].Y,
				brezierCompositeCurve[i + 1].X, brezierCompositeCurve[i + 1].Y);
		}

		for (int i = 0; i < points->Count - 1; i++)
		{
			gr->DrawLine(blackPen, points[i].X, points[i].Y, points[i + 1].X, points[i + 1].Y);
		}

		delete gr;
		delete bluePen;
		delete blackPen;
		return bm;
	}

	if (points->Count > 4 && (points->Count - 1) % 3 == 0)
	{
		List<Point>^ p = gcnew List<Point>;

		int deltaX = points[points->Count - 4].X - points[points->Count - 5].X;
		int deltaY = points[points->Count - 4].Y - points[points->Count - 5].Y;

		
		Point tempP;
		tempP.X = points[points->Count - 4].X + deltaX;
		tempP.Y = points[points->Count - 4].Y + deltaY;

		points[points->Count - 3] = tempP;

		p->Add(points[points->Count - 4]);
		p->Add(points[points->Count - 3]);
		p->Add(points[points->Count - 2]);
		p->Add(points[points->Count - 1]);

		ThirdOrderCurve(p);

		Graphics^ gr = Graphics::FromImage(bm);
		Pen^ bluePen = gcnew Pen(Color::Blue);
		Pen^ blackPen = gcnew Pen(Color::Black);

		for (int i = 0; i < brezierCompositeCurve->Count - 1; i++)
		{
			gr->DrawLine(bluePen, brezierCompositeCurve[i].X, brezierCompositeCurve[i].Y,
				brezierCompositeCurve[i + 1].X, brezierCompositeCurve[i + 1].Y);
		}

		for (int i = 0; i < points->Count - 1; i++)
		{
			gr->DrawLine(blackPen, points[i].X, points[i].Y, points[i + 1].X, points[i + 1].Y);
		}

		delete gr;
		delete bluePen;
		delete blackPen;
		return bm;
	}

	return bm;
}
