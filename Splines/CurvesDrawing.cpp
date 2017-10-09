#include "CurvesDrawing.h"



CurvesDrawing::CurvesDrawing()
{
	bSplines = gcnew List<BSpline^>();
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
	Graphics^ gr = Graphics::FromImage(bm);
	Pen^ bluePen = gcnew Pen(Color::Blue, 3);
	Pen^ blackPen = gcnew Pen(Color::Green, 0.01f);

	for (int i = 0; i < points->Count - 1; i++)
	{
		gr->DrawLine(blackPen, points[i].X, points[i].Y, points[i + 1].X, points[i + 1].Y);
	}

	for each (Point p in points)
	{
		gr->FillEllipse(Brushes::Red, p.X - 7, p.Y - 7, 15, 15);
	}

	if (points->Count == 4)
	{

		BSpline^ s = gcnew BSpline(points);
		s->FindPoints();
		bSplines->Clear();
		bSplines->Add(s);
	}	

	if (points->Count > 4)
	{
		List<Point>^ bsp1 = gcnew List<Point>();
		List<Point>^ bsp = gcnew List<Point>();
		bsp->Clear();
		bSplines->Clear();

		bsp->Add(points[0]);
		bsp->Add(points[1]);
		bsp->Add(points[2]);
		bsp->Add(points[3]);

		BSpline^ bs = gcnew BSpline(bsp);
		bs->FindPoints();

		bSplines->Add(bs);

		for (int i = 1; i < points->Count - 3; i++)
		{

			bsp1->Clear();
		
			bsp1->Add(points[i]);
			bsp1->Add(points[i + 1]);
			bsp1->Add(points[i + 2]);
			bsp1->Add(points[i + 3]);

			BSpline^ bs = gcnew BSpline(bsp1);
			bs->FindPoints();
			
			bSplines->Add(bs);
		}
		

		/*bsp->Add(points[points->Count - 4]);
		bsp->Add(points[points->Count - 3]);
		bsp->Add(points[points->Count - 2]);
		bsp->Add(points[points->Count - 1]);

		BSpline^ bs = gcnew BSpline(bsp);
		bs->FindPoints();

		bSplines->Add(bs);		*/
	}

	delete gr;
	delete bluePen;
	delete blackPen;
	
	return DrawBSplinesUsingList(bm);
}

Bitmap ^ CurvesDrawing::DrawBSplinesUsingList(Bitmap^ bm)
{
	Graphics^ gr = Graphics::FromImage(bm);
	Pen^ bluePen = gcnew Pen(Color::Blue, 3);
	Pen^ blackPen = gcnew Pen(Color::Green, 0.01f);

	for each (BSpline^ bs in bSplines)
	{
		for (int i = 0; i < bs->points->Count - 1; i++)
		{
			gr->DrawLine(bluePen, bs->points[i].X, bs->points[i].Y, bs->points[i + 1].X, bs->points[i + 1].Y);
		}		
	}

	delete gr;
	delete bluePen;
	delete blackPen;
	return bm;
}

Bitmap ^ CurvesDrawing::DrawCloseBSpline(Bitmap ^ bm)
{
	List<Point>^ points0 = gcnew List<Point>();

	points0->Add(bSplines[bSplines->Count - 1]->vertices[1]);
	points0->Add(bSplines[bSplines->Count - 1]->vertices[2]);
	points0->Add(bSplines[bSplines->Count - 1]->vertices[3]);
	points0->Add(bSplines[0]->vertices[0]);

	BSpline^ bs0 = gcnew BSpline(points0);
	bs0->FindPoints();

	List<Point>^ points1 = gcnew List<Point>();
	
	points1->Add(bSplines[bSplines->Count - 1]->vertices[2]);
	points1->Add(bSplines[bSplines->Count - 1]->vertices[3]);
	points1->Add(bSplines[0]->vertices[0]);
	points1->Add(bSplines[0]->vertices[1]);

	BSpline^ bs1 = gcnew BSpline(points1);
	bs1->FindPoints();

	List<Point>^ points2 = gcnew List<Point>();
	
	points2->Add(bSplines[bSplines->Count - 1]->vertices[3]);
	points2->Add(bSplines[0]->vertices[0]);
	points2->Add(bSplines[0]->vertices[1]);
	points2->Add(bSplines[0]->vertices[2]);

	BSpline^ bs2 = gcnew BSpline(points2);
	bs2->FindPoints();


	bSplines->Add(bs0);
	bSplines->Add(bs1);
	bSplines->Add(bs2);

	return DrawBSplinesUsingList(bm);
}
