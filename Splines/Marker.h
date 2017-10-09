#pragma once


ref class Marker
{

public:

	int x;
	int y;
	int radius = 20;

	bool isDrag;
	Marker(int x, int y);
	~Marker();

	void MouseDown()
	{
		isDrag = true;
	}

	void MouseUp()
	{
		isDrag = false;
	}

	//void MouseMove();
};

