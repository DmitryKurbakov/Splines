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
	Pen^ bluePen = gcnew Pen(Color::Blue, 3);
	Pen^ blackPen = gcnew Pen(Color::Green, 0.01f);

	for (int i = 0; i < brezierCurvesPointsList->Count - 1; i++)
	{
		gr->DrawLine(bluePen, brezierCurvesPointsList[i].X, brezierCurvesPointsList[i].Y,
			brezierCurvesPointsList[i + 1].X, brezierCurvesPointsList[i + 1].Y);
	}	

	for (int i = 0; i < points->Count - 1; i++)
	{
		gr->DrawLine(blackPen, points[i].X, points[i].Y, points[i + 1].X, points[i + 1].Y);
	}	

	for (int i = 0; i < points->Count; i++)
	{
		gr->FillEllipse(Brushes::Red, points[i].X - 7, points[i].Y - 7, 15, 15);
	}

	delete gr;
	delete bluePen;
	delete blackPen;
	return bm;
}

Bitmap ^ CurvesDrawing::DrawBrezierThirdOrder(Bitmap ^ bm, List<Point>^ points)
{

	isDrew = false;

	Graphics^ gr = Graphics::FromImage(bm);
	Pen^ bluePen = gcnew Pen(Color::Blue, 3);
	Pen^ blackPen = gcnew Pen(Color::Black, 0.01f);

	if (points->Count == 4)
	{
		isDrew = true;
		ThirdOrderCurve(points);

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

		isDrew = true;

		p->Add(points[points->Count - 4]);
		p->Add(points[points->Count - 3]);
		p->Add(points[points->Count - 2]);
		p->Add(points[points->Count - 1]);

		ThirdOrderCurve(p);

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

	delete gr;
	delete bluePen;
	delete blackPen;
	return bm;
}

Bitmap ^ CurvesDrawing::DrawCloseCurve(Bitmap ^ bm, List<Point>^ points)
{


	Graphics^ gr = Graphics::FromImage(bm);
	Pen^ bluePen = gcnew Pen(Color::Blue, 3);
	Pen^ blackPen = gcnew Pen(Color::Black, 0.01f);


	List<Point>^ p = gcnew List<Point>;

	Point tempP0;
	Point tempP1;

	int deltaX0 = points[points->Count - 2].X - points[points->Count - 1].X;
	int deltaY0 = points[points->Count - 2].Y - points[points->Count - 1].Y;
	int deltaX1 = points[0].X - points[1].X;
	int deltaY1 = points[0].Y - points[1].Y;

	tempP0.X = points[points->Count - 1].X - deltaX0;
	tempP0.Y = points[points->Count - 1].Y - deltaY0;

	tempP1.X = points[0].X + deltaX1;
	tempP1.Y = points[0].Y + deltaY1;

	p->Add(points[points->Count - 1]);
	p->Add(tempP0);
	p->Add(tempP1);
	p->Add(points[0]);

	ThirdOrderCurve(p);

	for (int i = 0; i < brezierCompositeCurve->Count - 1; i++)
	{
		gr->DrawLine(bluePen, brezierCompositeCurve[i].X, brezierCompositeCurve[i].Y,
			brezierCompositeCurve[i + 1].X, brezierCompositeCurve[i + 1].Y);
	}

	for (int i = 0; i < p->Count - 1; i++)
	{
		gr->DrawLine(blackPen, p[i].X,p[i].Y, p[i + 1].X, p[i + 1].Y);
	}

	delete gr;
	delete bluePen;
	delete blackPen;
	return bm;
}

Bitmap ^ CurvesDrawing::DrawBSplines(Bitmap ^ bm, List<Point>^ points)
{
	
	BSpline^ s = gcnew BSpline(points);
	s->FindPoints();

	bSplines.Add(s);

	Graphics^ gr = Graphics::FromImage(bm);
	Pen^ bluePen = gcnew Pen(Color::Blue, 3);
	Pen^ blackPen = gcnew Pen(Color::Black, 0.01f);

	for (int i = 0; i < s->points->Count - 1; i++)
	{
		gr->DrawLine(bluePen, s->points[i].X, s->points[i].Y, s->points[i + 1].X, s->points[i + 1].Y);
	}

	delete gr;
	delete bluePen;
	delete blackPen;
	return bm;
}
