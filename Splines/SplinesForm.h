#pragma once

#include "SplinesFormController.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// Сводка для SplinesForm
/// </summary>
public ref class SplinesForm : public System::Windows::Forms::Form
{
public:
	SplinesFormController^ controller;
private: System::Windows::Forms::RadioButton^  bSplineCurveRadioButton;
private: System::Windows::Forms::Button^  closeBSplineButton;
public:
	int mi = -1;

	SplinesForm(void)
	{
		InitializeComponent();

		controller = gcnew SplinesFormController(this->pictureBox);
	}

protected:
	/// <summary>
	/// Освободить все используемые ресурсы.
	/// </summary>
	~SplinesForm()
	{
		if (components)
		{
			delete components;
		}
	}
private: System::Windows::Forms::GroupBox^  pictureGroupBox;
protected:
private: System::Windows::Forms::PictureBox^  pictureBox;
private: System::Windows::Forms::GroupBox^  toolsGroupBox;
private: System::Windows::Forms::RadioButton^  bezierCurveElementaryRadioButton;
private: System::Windows::Forms::RadioButton^  bezierCurveCompositeRadioButton;
private: System::Windows::Forms::Button^  clearButton;
private: System::Windows::Forms::Button^  closeCurveButton;







private:
	/// <summary>
	/// Обязательная переменная конструктора.
	/// </summary>
	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Требуемый метод для поддержки конструктора — не изменяйте 
	/// содержимое этого метода с помощью редактора кода.
	/// </summary>
	void InitializeComponent(void)
	{
		this->pictureGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
		this->toolsGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->bSplineCurveRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->closeCurveButton = (gcnew System::Windows::Forms::Button());
		this->bezierCurveCompositeRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->bezierCurveElementaryRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->clearButton = (gcnew System::Windows::Forms::Button());
		this->closeBSplineButton = (gcnew System::Windows::Forms::Button());
		this->pictureGroupBox->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
		this->toolsGroupBox->SuspendLayout();
		this->SuspendLayout();
		// 
		// pictureGroupBox
		// 
		this->pictureGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			| System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->pictureGroupBox->Controls->Add(this->pictureBox);
		this->pictureGroupBox->Location = System::Drawing::Point(156, 12);
		this->pictureGroupBox->Name = L"pictureGroupBox";
		this->pictureGroupBox->Size = System::Drawing::Size(512, 423);
		this->pictureGroupBox->TabIndex = 0;
		this->pictureGroupBox->TabStop = false;
		this->pictureGroupBox->Text = L"Изображение";
		// 
		// pictureBox
		// 
		this->pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			| System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->pictureBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
		this->pictureBox->Location = System::Drawing::Point(6, 19);
		this->pictureBox->Name = L"pictureBox";
		this->pictureBox->Size = System::Drawing::Size(500, 398);
		this->pictureBox->TabIndex = 0;
		this->pictureBox->TabStop = false;
		this->pictureBox->Click += gcnew System::EventHandler(this, &SplinesForm::pictureBox_Click);
		this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &SplinesForm::OnMouseDown);
		this->pictureBox->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &SplinesForm::OnMouseMove);
		this->pictureBox->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &SplinesForm::OnMouseUp);
		// 
		// toolsGroupBox
		// 
		this->toolsGroupBox->Controls->Add(this->closeBSplineButton);
		this->toolsGroupBox->Controls->Add(this->bSplineCurveRadioButton);
		this->toolsGroupBox->Controls->Add(this->closeCurveButton);
		this->toolsGroupBox->Controls->Add(this->bezierCurveCompositeRadioButton);
		this->toolsGroupBox->Controls->Add(this->bezierCurveElementaryRadioButton);
		this->toolsGroupBox->Location = System::Drawing::Point(12, 12);
		this->toolsGroupBox->Name = L"toolsGroupBox";
		this->toolsGroupBox->Size = System::Drawing::Size(138, 264);
		this->toolsGroupBox->TabIndex = 1;
		this->toolsGroupBox->TabStop = false;
		this->toolsGroupBox->Text = L"Инструменты";
		// 
		// bSplineCurveRadioButton
		// 
		this->bSplineCurveRadioButton->AutoSize = true;
		this->bSplineCurveRadioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->bSplineCurveRadioButton->Location = System::Drawing::Point(6, 86);
		this->bSplineCurveRadioButton->Name = L"bSplineCurveRadioButton";
		this->bSplineCurveRadioButton->Size = System::Drawing::Size(98, 13);
		this->bSplineCurveRadioButton->TabIndex = 3;
		this->bSplineCurveRadioButton->Text = L"B-сплайновая кривая";
		this->bSplineCurveRadioButton->UseVisualStyleBackColor = true;
		this->bSplineCurveRadioButton->CheckedChanged += gcnew System::EventHandler(this, &SplinesForm::OnCheckedbSplineChanged);
		// 
		// closeCurveButton
		// 
		this->closeCurveButton->Enabled = false;
		this->closeCurveButton->Location = System::Drawing::Point(13, 57);
		this->closeCurveButton->Name = L"closeCurveButton";
		this->closeCurveButton->Size = System::Drawing::Size(75, 23);
		this->closeCurveButton->TabIndex = 2;
		this->closeCurveButton->Text = L"Замкнуть";
		this->closeCurveButton->UseVisualStyleBackColor = true;
		this->closeCurveButton->Click += gcnew System::EventHandler(this, &SplinesForm::closeCurveButton_Click);
		// 
		// bezierCurveCompositeRadioButton
		// 
		this->bezierCurveCompositeRadioButton->AutoSize = true;
		this->bezierCurveCompositeRadioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->bezierCurveCompositeRadioButton->Location = System::Drawing::Point(6, 38);
		this->bezierCurveCompositeRadioButton->Name = L"bezierCurveCompositeRadioButton";
		this->bezierCurveCompositeRadioButton->Size = System::Drawing::Size(82, 13);
		this->bezierCurveCompositeRadioButton->TabIndex = 1;
		this->bezierCurveCompositeRadioButton->Text = L"Безье cоставная";
		this->bezierCurveCompositeRadioButton->UseVisualStyleBackColor = true;
		this->bezierCurveCompositeRadioButton->CheckedChanged += gcnew System::EventHandler(this, &SplinesForm::OnCompositeChanged);
		// 
		// bezierCurveElementaryRadioButton
		// 
		this->bezierCurveElementaryRadioButton->AutoSize = true;
		this->bezierCurveElementaryRadioButton->Checked = true;
		this->bezierCurveElementaryRadioButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular,
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
		this->bezierCurveElementaryRadioButton->Location = System::Drawing::Point(6, 19);
		this->bezierCurveElementaryRadioButton->Name = L"bezierCurveElementaryRadioButton";
		this->bezierCurveElementaryRadioButton->Size = System::Drawing::Size(97, 13);
		this->bezierCurveElementaryRadioButton->TabIndex = 0;
		this->bezierCurveElementaryRadioButton->TabStop = true;
		this->bezierCurveElementaryRadioButton->Text = L"Безье элементарная";
		this->bezierCurveElementaryRadioButton->UseVisualStyleBackColor = true;
		this->bezierCurveElementaryRadioButton->CheckedChanged += gcnew System::EventHandler(this, &SplinesForm::OnCheckedChanged);
		// 
		// clearButton
		// 
		this->clearButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->clearButton->Location = System::Drawing::Point(12, 406);
		this->clearButton->Name = L"clearButton";
		this->clearButton->Size = System::Drawing::Size(75, 23);
		this->clearButton->TabIndex = 2;
		this->clearButton->Text = L"Очистить";
		this->clearButton->UseVisualStyleBackColor = true;
		this->clearButton->Click += gcnew System::EventHandler(this, &SplinesForm::clearButton_Click);
		// 
		// closeBSplineButton
		// 
		this->closeBSplineButton->Enabled = false;
		this->closeBSplineButton->Location = System::Drawing::Point(13, 105);
		this->closeBSplineButton->Name = L"closeBSplineButton";
		this->closeBSplineButton->Size = System::Drawing::Size(75, 23);
		this->closeBSplineButton->TabIndex = 4;
		this->closeBSplineButton->Text = L"Замкнуть";
		this->closeBSplineButton->UseVisualStyleBackColor = true;
		this->closeBSplineButton->Click += gcnew System::EventHandler(this, &SplinesForm::closeBSplineButton_Click);
		// 
		// SplinesForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(680, 447);
		this->Controls->Add(this->clearButton);
		this->Controls->Add(this->toolsGroupBox);
		this->Controls->Add(this->pictureGroupBox);
		this->Name = L"SplinesForm";
		this->Text = L"SplinesForm";
		this->pictureGroupBox->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
		this->toolsGroupBox->ResumeLayout(false);
		this->toolsGroupBox->PerformLayout();
		this->ResumeLayout(false);

	}
#pragma endregion

private: System::Void pictureBox_Click(System::Object^  sender, System::EventArgs^  e) {

	if (mi != -1) return;

	Point cursorPoint = pictureBox->PointToClient(System::Windows::Forms::Cursor::Position);

	if (this->bezierCurveElementaryRadioButton->Checked)
	{
		controller->OnBezierCurveArbitaryOrderRadioButtonChecked(cursorPoint, true);
	}

	if (this->bezierCurveCompositeRadioButton->Checked)
	{
		controller->OnBezierCurveCompositeRadioButton(cursorPoint, true);
		if (controller->curvesDrawing->isDrew)
		{
			closeCurveButton->Enabled = true;
		}
		else { closeCurveButton->Enabled = false; }
	}

	if (this->bSplineCurveRadioButton->Checked)
	{
		controller->OnBSplineCurveRadioButton(cursorPoint, true);
	}
}
private: System::Void clearButton_Click(System::Object^  sender, System::EventArgs^  e) {
	delete controller;
	delete pictureBox->Image;

	controller = gcnew SplinesFormController(this->pictureBox);
}
private: System::Void closeCurveButton_Click(System::Object^  sender, System::EventArgs^  e) {
	controller->OnCloseCurveButtonClick();
	closeCurveButton->Enabled = false;
}
		 void OnMouseDown(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e);
		 void OnMouseUp(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e);
		 void OnMouseMove(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e);
		 void OnCheckedChanged(System::Object ^sender, System::EventArgs ^e);
		 void OnCompositeChanged(System::Object ^sender, System::EventArgs ^e);
private: System::Void closeBSplineButton_Click(System::Object^  sender, System::EventArgs^  e) {
	controller->OnCloseBSplineButtonClick();
}
		 void OnCheckedbSplineChanged(System::Object ^sender, System::EventArgs ^e);
};




void SplinesForm::OnMouseDown(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e)
{
	Point cursorPoint = pictureBox->PointToClient(System::Windows::Forms::Cursor::Position);

	mi = controller->ChooseMarker(cursorPoint);
	if (mi != -1)
	{
		controller->markers[mi]->MouseDown();
	}
}


void SplinesForm::OnMouseUp(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e)
{
	if (mi != -1)
	{
		controller->markers[mi]->MouseUp();
	}
	mi = -1;
}


void SplinesForm::OnMouseMove(System::Object ^sender, System::Windows::Forms::MouseEventArgs ^e)
{
	Point cursorPoint = pictureBox->PointToClient(System::Windows::Forms::Cursor::Position);

	if (mi != -1)
	{
		if (controller->markers[mi]->isDrag)
		{
			
			controller->markers[mi]->x = cursorPoint.X; 
			controller->markers[mi]->y = cursorPoint.Y;

			if (bezierCurveElementaryRadioButton->Checked)
			{
				controller->referenceVertices[mi] = cursorPoint;
				controller->OnBezierCurveArbitaryOrderRadioButtonChecked(cursorPoint, false);
			}
			if (bezierCurveCompositeRadioButton->Checked)
			{
				controller->compositeCurvesReferenceVertices[mi] = cursorPoint;
				controller->OnBezierCurveCompositeRadioButton(cursorPoint, false);
			}
			if (bSplineCurveRadioButton->Checked)
			{
				controller->bSplinesCurveVertices[mi] = cursorPoint;
				controller->OnBSplineCurveRadioButton(cursorPoint, false);
			}
		}
	}
}


void SplinesForm::OnCheckedChanged(System::Object ^sender, System::EventArgs ^e)
{
	closeBSplineButton->Enabled = false;
	closeCurveButton->Enabled = false;
	delete controller;
	controller = gcnew SplinesFormController(this->pictureBox);
	//controller->markers->Clear();
}


void SplinesForm::OnCompositeChanged(System::Object ^sender, System::EventArgs ^e)
{
	closeBSplineButton->Enabled = false;
	//closeCurveButton->Enabled = true;
	delete controller;
	controller = gcnew SplinesFormController(this->pictureBox);
}


void SplinesForm::OnCheckedbSplineChanged(System::Object ^sender, System::EventArgs ^e)
{
	closeBSplineButton->Enabled = true;
}
