#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

/// <summary>
/// ������ ��� SplinesForm
/// </summary>
public ref class SplinesForm : public System::Windows::Forms::Form
{
public:
	SplinesForm(void)
	{
		InitializeComponent();
		//
		//TODO: �������� ��� ������������
		//
	}

protected:
	/// <summary>
	/// ���������� ��� ������������ �������.
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

private:
	/// <summary>
	/// ������������ ���������� ������������.
	/// </summary>
	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// ��������� ����� ��� ��������� ������������ � �� ��������� 
	/// ���������� ����� ������ � ������� ��������� ����.
	/// </summary>
	void InitializeComponent(void)
	{
		this->pictureGroupBox = (gcnew System::Windows::Forms::GroupBox());
		this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
		this->pictureGroupBox->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
		this->SuspendLayout();
		// 
		// pictureGroupBox
		// 
		this->pictureGroupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			| System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->pictureGroupBox->Controls->Add(this->pictureBox);
		this->pictureGroupBox->Location = System::Drawing::Point(12, 12);
		this->pictureGroupBox->Name = L"pictureGroupBox";
		this->pictureGroupBox->Size = System::Drawing::Size(656, 423);
		this->pictureGroupBox->TabIndex = 0;
		this->pictureGroupBox->TabStop = false;
		this->pictureGroupBox->Text = L"�����������";
		this->pictureBox->Click += gcnew System::EventHandler(this, &SplinesForm::OnPictureBoxClick);
		// 
		// pictureBox
		// 
		this->pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
			| System::Windows::Forms::AnchorStyles::Left)
			| System::Windows::Forms::AnchorStyles::Right));
		this->pictureBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
		this->pictureBox->Location = System::Drawing::Point(6, 19);
		this->pictureBox->Name = L"pictureBox";
		this->pictureBox->Size = System::Drawing::Size(644, 398);
		this->pictureBox->TabIndex = 0;
		this->pictureBox->TabStop = false;
		// 
		// SplinesForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(680, 447);
		this->Controls->Add(this->pictureGroupBox);
		this->Name = L"SplinesForm";
		this->Text = L"SplinesForm";
		this->pictureGroupBox->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
		this->ResumeLayout(false);

	}
#pragma endregion
	void OnPictureBoxClick(System::Object ^sender, System::EventArgs ^e);
};



void SplinesForm::OnPictureBoxClick(System::Object ^sender, System::EventArgs ^e)
{
	
}
