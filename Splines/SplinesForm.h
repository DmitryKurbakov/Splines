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
		this->bezierCurveCompositeRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->bezierCurveElementaryRadioButton = (gcnew System::Windows::Forms::RadioButton());
		this->clearButton = (gcnew System::Windows::Forms::Button());
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
		// 
		// toolsGroupBox
		// 
		this->toolsGroupBox->Controls->Add(this->bezierCurveCompositeRadioButton);
		this->toolsGroupBox->Controls->Add(this->bezierCurveElementaryRadioButton);
		this->toolsGroupBox->Location = System::Drawing::Point(12, 12);
		this->toolsGroupBox->Name = L"toolsGroupBox";
		this->toolsGroupBox->Size = System::Drawing::Size(138, 264);
		this->toolsGroupBox->TabIndex = 1;
		this->toolsGroupBox->TabStop = false;
		this->toolsGroupBox->Text = L"Инструменты";
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
		this->bezierCurveElementaryRadioButton->Text = L"Безье элементарная";
		this->bezierCurveElementaryRadioButton->UseVisualStyleBackColor = true;
		// 
		// clearButton
		// 
		this->clearButton->Location = System::Drawing::Point(12, 406);
		this->clearButton->Name = L"clearButton";
		this->clearButton->Size = System::Drawing::Size(75, 23);
		this->clearButton->TabIndex = 2;
		this->clearButton->Text = L"Очистить";
		this->clearButton->UseVisualStyleBackColor = true;
		this->clearButton->Click += gcnew System::EventHandler(this, &SplinesForm::clearButton_Click);
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

	Point cursorPoint = pictureBox->PointToClient(System::Windows::Forms::Cursor::Position);

	if (this->bezierCurveElementaryRadioButton->Checked)
	{
		controller->OnBezierCurveArbitaryOrderRadioButtonChecked(cursorPoint);
	}

	if (this->bezierCurveCompositeRadioButton->Checked)
	{
		controller->OnBezierCurveCompositeRadioButton(cursorPoint);
	}
}
private: System::Void clearButton_Click(System::Object^  sender, System::EventArgs^  e) {
	delete controller;
	controller = gcnew SplinesFormController(this->pictureBox);
}
};






