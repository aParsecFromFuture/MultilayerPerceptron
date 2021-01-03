#pragma once
#include "neural_network.h"
#include <chrono>

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			srand(time(0));
			InitializeComponent();
			float interval_x = (float)pictureBox1->Width / GRID_X;
			float interval_y = (float)pictureBox1->Height / GRID_Y;

			GRID_DATA = new float[INPUT_COUNT * GRID_X * GRID_Y];

			for (int i = 0; i < GRID_X; i++) {
				for (int j = 0; j < GRID_Y; j++) {
					GRID_DATA[(i * GRID_Y + j) * INPUT_COUNT] = (i * interval_x) - (pictureBox1->Width >> 1);
					GRID_DATA[(i * GRID_Y + j) * INPUT_COUNT + 1] = (pictureBox1->Height >> 1) - (j * interval_y);
				}
			}
		}
		const int INPUT_COUNT = 2;
		const int GRID_X = 100;
		const int GRID_Y = 136;
		int HIDDEN_LAYER_COUNT = -1;
		int SAMPLE_COUNT = 0;
		int* NEURON_COUNT = 0;
		int CATEGORY_COUNT = -1;
		int CATEGORY_NOW = -1;
		float* TARGET = 0;
		float* DATASET = 0;
		int* CATEGORY = 0;
		float* GRID_DATA = 0;
		float** WEIGHT;
		float** BIAS;
		float* GRID_CATEGORY = 0;
		int PROGRAM_STATE = 0;
		const float LEARNING_RATE = 0.1f;
		const float MOMENTUM = 0.99f;
		const int ANIMATION_FRAME_COUNT = 10;
		int EPOCHS = -1;
		int BATCH_SIZE = -1;
		bool MAPPING_MODE = 0;
		bool VERBOSE = 0;
		bool SHOW_AXES = 1;
		bool SHOW_SAMPLES = 1;

	private: System::Windows::Forms::Label^ errorValueLabel;
	private: System::Windows::Forms::Label^ sampleCountLabel;
	private: System::Windows::Forms::Label^ sampleCountTitle;
	private: System::Windows::Forms::ComboBox^ categorySelectCombobox;
	private: System::Windows::Forms::ToolStripMenuItem^ menu;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::OpenFileDialog^ openDataFileDialog;
	private: System::Windows::Forms::SaveFileDialog^ saveDataFileDialog;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ToolStripMenuItem^ cOLORMODEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fILEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ wRITEDATASETToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ rEADDATASETToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ eDITToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ menuUndo;
	private: System::Windows::Forms::ToolStripMenuItem^ cLEARWEIGHTSToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ menuTrain;
	private: System::Windows::Forms::ToolStripMenuItem^ tRAINANIMATIONToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ cLEARDATAToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ menuReset;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ToolStripMenuItem^ activationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ reluToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ leakyReluToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ eluToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tanhToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ sigmoidToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ bipolarSigmoidToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ sinusexperimentalToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ noneToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ vERBOSEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showAxesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ showSamplesToolStripMenuItem;
	public:
	private: System::Windows::Forms::Label^ label4;

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ window_title;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ categoryCombobox;
	private: System::ComponentModel::IContainer^ components;
	protected:
	private:
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->window_title = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->categoryCombobox = (gcnew System::Windows::Forms::ComboBox());
			this->categorySelectCombobox = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cOLORMODEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showAxesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showSamplesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fILEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cLEARDATAToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rEADDATASETToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wRITEDATASETToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eDITToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuUndo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuReset = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cLEARWEIGHTSToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuTrain = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tRAINANIMATIONToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->activationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reluToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->leakyReluToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eluToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tanhToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sigmoidToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->bipolarSigmoidToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sinusexperimentalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->noneToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->vERBOSEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->errorValueLabel = (gcnew System::Windows::Forms::Label());
			this->openDataFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveDataFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->sampleCountLabel = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox1->Location = System::Drawing::Point(0, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1068, 670);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
			// 
			// window_title
			// 
			this->window_title->AutoSize = true;
			this->window_title->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->window_title->Location = System::Drawing::Point(31, 12);
			this->window_title->Name = L"window_title";
			this->window_title->Size = System::Drawing::Size(127, 27);
			this->window_title->TabIndex = 1;
			this->window_title->Text = L"Welcome to";
			this->window_title->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(35, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 22);
			this->label1->TabIndex = 4;
			this->label1->Text = L"category count";
			// 
			// categoryCombobox
			// 
			this->categoryCombobox->FormattingEnabled = true;
			this->categoryCombobox->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"2", L"3", L"4", L"5", L"6", L"7" });
			this->categoryCombobox->Location = System::Drawing::Point(38, 52);
			this->categoryCombobox->Name = L"categoryCombobox";
			this->categoryCombobox->Size = System::Drawing::Size(121, 24);
			this->categoryCombobox->TabIndex = 5;
			this->categoryCombobox->SelectedValueChanged += gcnew System::EventHandler(this, &Form1::categoryCombobox_SelectedValueChanged);
			// 
			// categorySelectCombobox
			// 
			this->categorySelectCombobox->FormattingEnabled = true;
			this->categorySelectCombobox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"RED", L"BLUE", L"GREEN", L"YELLOW",
					L"PURPLE", L"CYAN", L"ORANGE"
			});
			this->categorySelectCombobox->Location = System::Drawing::Point(40, 47);
			this->categorySelectCombobox->Name = L"categorySelectCombobox";
			this->categorySelectCombobox->Size = System::Drawing::Size(121, 24);
			this->categorySelectCombobox->TabIndex = 17;
			this->categorySelectCombobox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::categorySelectCombobox_SelectedIndexChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->Location = System::Drawing::Point(59, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(77, 22);
			this->label4->TabIndex = 16;
			this->label4->Text = L"category";
			// 
			// menu
			// 
			this->menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->cOLORMODEToolStripMenuItem,
					this->showAxesToolStripMenuItem, this->showSamplesToolStripMenuItem
			});
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(55, 24);
			this->menu->Text = L"View";
			// 
			// cOLORMODEToolStripMenuItem
			// 
			this->cOLORMODEToolStripMenuItem->CheckOnClick = true;
			this->cOLORMODEToolStripMenuItem->Name = L"cOLORMODEToolStripMenuItem";
			this->cOLORMODEToolStripMenuItem->Size = System::Drawing::Size(204, 26);
			this->cOLORMODEToolStripMenuItem->Text = L"Continuous color";
			this->cOLORMODEToolStripMenuItem->CheckedChanged += gcnew System::EventHandler(this, &Form1::cOLORMODEToolStripMenuItem_CheckedChanged);
			// 
			// showAxesToolStripMenuItem
			// 
			this->showAxesToolStripMenuItem->Checked = true;
			this->showAxesToolStripMenuItem->CheckOnClick = true;
			this->showAxesToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->showAxesToolStripMenuItem->Name = L"showAxesToolStripMenuItem";
			this->showAxesToolStripMenuItem->Size = System::Drawing::Size(204, 26);
			this->showAxesToolStripMenuItem->Text = L"Show axes";
			this->showAxesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showAxesToolStripMenuItem_Click);
			// 
			// showSamplesToolStripMenuItem
			// 
			this->showSamplesToolStripMenuItem->Checked = true;
			this->showSamplesToolStripMenuItem->CheckOnClick = true;
			this->showSamplesToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->showSamplesToolStripMenuItem->Name = L"showSamplesToolStripMenuItem";
			this->showSamplesToolStripMenuItem->Size = System::Drawing::Size(204, 26);
			this->showSamplesToolStripMenuItem->Text = L"Show samples";
			this->showSamplesToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::showSamplesToolStripMenuItem_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fILEToolStripMenuItem,
					this->eDITToolStripMenuItem, this->menu, this->trainToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1315, 28);
			this->menuStrip1->TabIndex = 15;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fILEToolStripMenuItem
			// 
			this->fILEToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->cLEARDATAToolStripMenuItem,
					this->rEADDATASETToolStripMenuItem, this->wRITEDATASETToolStripMenuItem
			});
			this->fILEToolStripMenuItem->Name = L"fILEToolStripMenuItem";
			this->fILEToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fILEToolStripMenuItem->Text = L"File";
			// 
			// cLEARDATAToolStripMenuItem
			// 
			this->cLEARDATAToolStripMenuItem->Name = L"cLEARDATAToolStripMenuItem";
			this->cLEARDATAToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->cLEARDATAToolStripMenuItem->Text = L"New";
			this->cLEARDATAToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::cLEARDATAToolStripMenuItem_Click);
			// 
			// rEADDATASETToolStripMenuItem
			// 
			this->rEADDATASETToolStripMenuItem->Name = L"rEADDATASETToolStripMenuItem";
			this->rEADDATASETToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->rEADDATASETToolStripMenuItem->Text = L"Open";
			this->rEADDATASETToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::rEADDATASETToolStripMenuItem_Click);
			// 
			// wRITEDATASETToolStripMenuItem
			// 
			this->wRITEDATASETToolStripMenuItem->Name = L"wRITEDATASETToolStripMenuItem";
			this->wRITEDATASETToolStripMenuItem->Size = System::Drawing::Size(128, 26);
			this->wRITEDATASETToolStripMenuItem->Text = L"Save";
			this->wRITEDATASETToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::wRITEDATASETToolStripMenuItem_Click);
			// 
			// eDITToolStripMenuItem
			// 
			this->eDITToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menuUndo,
					this->menuReset, this->cLEARWEIGHTSToolStripMenuItem
			});
			this->eDITToolStripMenuItem->Name = L"eDITToolStripMenuItem";
			this->eDITToolStripMenuItem->Size = System::Drawing::Size(49, 24);
			this->eDITToolStripMenuItem->Text = L"Edit";
			// 
			// menuUndo
			// 
			this->menuUndo->Name = L"menuUndo";
			this->menuUndo->Size = System::Drawing::Size(191, 26);
			this->menuUndo->Text = L"Undo";
			this->menuUndo->Click += gcnew System::EventHandler(this, &Form1::menuUndo_Click);
			// 
			// menuReset
			// 
			this->menuReset->Name = L"menuReset";
			this->menuReset->Size = System::Drawing::Size(191, 26);
			this->menuReset->Text = L"Reset";
			this->menuReset->Click += gcnew System::EventHandler(this, &Form1::menuReset_Click);
			// 
			// cLEARWEIGHTSToolStripMenuItem
			// 
			this->cLEARWEIGHTSToolStripMenuItem->Name = L"cLEARWEIGHTSToolStripMenuItem";
			this->cLEARWEIGHTSToolStripMenuItem->Size = System::Drawing::Size(191, 26);
			this->cLEARWEIGHTSToolStripMenuItem->Text = L"Clear (weights)";
			this->cLEARWEIGHTSToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::cLEARWEIGHTSToolStripMenuItem_Click);
			// 
			// trainToolStripMenuItem
			// 
			this->trainToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->menuTrain,
					this->tRAINANIMATIONToolStripMenuItem, this->activationToolStripMenuItem, this->vERBOSEToolStripMenuItem
			});
			this->trainToolStripMenuItem->Name = L"trainToolStripMenuItem";
			this->trainToolStripMenuItem->Size = System::Drawing::Size(55, 24);
			this->trainToolStripMenuItem->Text = L"Train";
			// 
			// menuTrain
			// 
			this->menuTrain->Name = L"menuTrain";
			this->menuTrain->Size = System::Drawing::Size(198, 26);
			this->menuTrain->Text = L"Run";
			this->menuTrain->Click += gcnew System::EventHandler(this, &Form1::menuTrain_Click);
			// 
			// tRAINANIMATIONToolStripMenuItem
			// 
			this->tRAINANIMATIONToolStripMenuItem->Name = L"tRAINANIMATIONToolStripMenuItem";
			this->tRAINANIMATIONToolStripMenuItem->Size = System::Drawing::Size(198, 26);
			this->tRAINANIMATIONToolStripMenuItem->Text = L"Run (animation)";
			this->tRAINANIMATIONToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::tRAINANIMATIONToolStripMenuItem_Click);
			// 
			// activationToolStripMenuItem
			// 
			this->activationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->reluToolStripMenuItem,
					this->leakyReluToolStripMenuItem, this->eluToolStripMenuItem, this->tanhToolStripMenuItem, this->sigmoidToolStripMenuItem, this->bipolarSigmoidToolStripMenuItem,
					this->sinusexperimentalToolStripMenuItem, this->noneToolStripMenuItem
			});
			this->activationToolStripMenuItem->Name = L"activationToolStripMenuItem";
			this->activationToolStripMenuItem->Size = System::Drawing::Size(198, 26);
			this->activationToolStripMenuItem->Text = L"Activation";
			// 
			// reluToolStripMenuItem
			// 
			this->reluToolStripMenuItem->Checked = true;
			this->reluToolStripMenuItem->CheckOnClick = true;
			this->reluToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->reluToolStripMenuItem->Name = L"reluToolStripMenuItem";
			this->reluToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->reluToolStripMenuItem->Text = L"Relu";
			this->reluToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::activationToolStripMenuItem_Click);
			// 
			// leakyReluToolStripMenuItem
			// 
			this->leakyReluToolStripMenuItem->CheckOnClick = true;
			this->leakyReluToolStripMenuItem->Name = L"leakyReluToolStripMenuItem";
			this->leakyReluToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->leakyReluToolStripMenuItem->Text = L"Leaky Relu";
			this->leakyReluToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::activationToolStripMenuItem_Click);
			// 
			// eluToolStripMenuItem
			// 
			this->eluToolStripMenuItem->CheckOnClick = true;
			this->eluToolStripMenuItem->Name = L"eluToolStripMenuItem";
			this->eluToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->eluToolStripMenuItem->Text = L"Elu";
			this->eluToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::activationToolStripMenuItem_Click);
			// 
			// tanhToolStripMenuItem
			// 
			this->tanhToolStripMenuItem->CheckOnClick = true;
			this->tanhToolStripMenuItem->Name = L"tanhToolStripMenuItem";
			this->tanhToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->tanhToolStripMenuItem->Text = L"Tanh";
			this->tanhToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::activationToolStripMenuItem_Click);
			// 
			// sigmoidToolStripMenuItem
			// 
			this->sigmoidToolStripMenuItem->CheckOnClick = true;
			this->sigmoidToolStripMenuItem->Name = L"sigmoidToolStripMenuItem";
			this->sigmoidToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->sigmoidToolStripMenuItem->Text = L"Sigmoid";
			this->sigmoidToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::activationToolStripMenuItem_Click);
			// 
			// bipolarSigmoidToolStripMenuItem
			// 
			this->bipolarSigmoidToolStripMenuItem->CheckOnClick = true;
			this->bipolarSigmoidToolStripMenuItem->Name = L"bipolarSigmoidToolStripMenuItem";
			this->bipolarSigmoidToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->bipolarSigmoidToolStripMenuItem->Text = L"Bipolar Sigmoid";
			this->bipolarSigmoidToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::activationToolStripMenuItem_Click);
			// 
			// sinusexperimentalToolStripMenuItem
			// 
			this->sinusexperimentalToolStripMenuItem->CheckOnClick = true;
			this->sinusexperimentalToolStripMenuItem->Name = L"sinusexperimentalToolStripMenuItem";
			this->sinusexperimentalToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->sinusexperimentalToolStripMenuItem->Text = L"Sinus (experimental)";
			this->sinusexperimentalToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::activationToolStripMenuItem_Click);
			// 
			// noneToolStripMenuItem
			// 
			this->noneToolStripMenuItem->Name = L"noneToolStripMenuItem";
			this->noneToolStripMenuItem->Size = System::Drawing::Size(227, 26);
			this->noneToolStripMenuItem->Text = L"None";
			this->noneToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::activationToolStripMenuItem_Click);
			// 
			// vERBOSEToolStripMenuItem
			// 
			this->vERBOSEToolStripMenuItem->CheckOnClick = true;
			this->vERBOSEToolStripMenuItem->Name = L"vERBOSEToolStripMenuItem";
			this->vERBOSEToolStripMenuItem->Size = System::Drawing::Size(198, 26);
			this->vERBOSEToolStripMenuItem->Text = L"Verbose";
			this->vERBOSEToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::vERBOSEToolStripMenuItem_CheckedChanged);
			// 
			// errorValueLabel
			// 
			this->errorValueLabel->AutoSize = true;
			this->errorValueLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->errorValueLabel->Location = System::Drawing::Point(22, 40);
			this->errorValueLabel->Name = L"errorValueLabel";
			this->errorValueLabel->Size = System::Drawing::Size(71, 22);
			this->errorValueLabel->TabIndex = 18;
			this->errorValueLabel->Text = L"error: 0";
			// 
			// openDataFileDialog
			// 
			this->openDataFileDialog->FileName = L"openFileDialog1";
			// 
			// sampleCountLabel
			// 
			this->sampleCountLabel->AutoSize = true;
			this->sampleCountLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->sampleCountLabel->Location = System::Drawing::Point(22, 18);
			this->sampleCountLabel->Name = L"sampleCountLabel";
			this->sampleCountLabel->Size = System::Drawing::Size(134, 22);
			this->sampleCountLabel->TabIndex = 20;
			this->sampleCountLabel->Text = L"sample count: 0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->Location = System::Drawing::Point(24, 89);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(155, 22);
			this->label5->TabIndex = 24;
			this->label5->Text = L"hidden layer count";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"None", L"1", L"2", L"3", L"4", L"5" });
			this->comboBox1->Location = System::Drawing::Point(39, 114);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 25;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(48, 178);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 26;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(43, 153);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(116, 22);
			this->label2->TabIndex = 27;
			this->label2->Text = L"hidden layers";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(8) { L"1", L"2", L"4", L"8", L"16", L"32", L"64", L"All" });
			this->comboBox2->Location = System::Drawing::Point(38, 103);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 29;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->Location = System::Drawing::Point(59, 78);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(88, 22);
			this->label3->TabIndex = 28;
			this->label3->Text = L"batch size";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"50", L"100", L"250", L"500", L"1000" });
			this->comboBox3->Location = System::Drawing::Point(39, 158);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(121, 24);
			this->comboBox3->TabIndex = 31;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox3_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label6->Location = System::Drawing::Point(46, 133);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(104, 22);
			this->label6->TabIndex = 30;
			this->label6->Text = L"epoch count";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label7->Location = System::Drawing::Point(85, 39);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(107, 27);
			this->label7->TabIndex = 32;
			this->label7->Text = L"my World";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->categoryCombobox);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Location = System::Drawing::Point(27, 83);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 218);
			this->groupBox1->TabIndex = 35;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Architecture";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->categorySelectCombobox);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->comboBox2);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->comboBox3);
			this->groupBox2->Location = System::Drawing::Point(27, 316);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(200, 202);
			this->groupBox2->TabIndex = 36;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Training";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->sampleCountLabel);
			this->groupBox3->Controls->Add(this->errorValueLabel);
			this->groupBox3->Location = System::Drawing::Point(27, 538);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(200, 99);
			this->groupBox3->TabIndex = 37;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Results";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label9->Location = System::Drawing::Point(22, 62);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(73, 22);
			this->label9->TabIndex = 38;
			this->label9->Text = L"time: 0s";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->window_title);
			this->panel1->Controls->Add(this->groupBox3);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->groupBox2);
			this->panel1->Controls->Add(this->groupBox1);
			this->panel1->Location = System::Drawing::Point(1061, 31);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(254, 670);
			this->panel1->TabIndex = 38;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ClientSize = System::Drawing::Size(1315, 697);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void categoryCombobox_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e) {
		if (PROGRAM_STATE != 1)
			CATEGORY_COUNT = System::Convert::ToInt32(categoryCombobox->SelectedItem->ToString());
		else
			MessageBox::Show("Category count can't change during run mode");
	}

	private: System::Void menuTrain_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PROGRAM_STATE == 0) {
			MessageBox::Show("Please init the program before running");
			return;
		}
		if (BATCH_SIZE == -1) {
			MessageBox::Show("Please select the batch size before running");
			return;
		}
		if (EPOCHS == -1) {
			MessageBox::Show("Please select the epoch count before running");
			return;
		}
		if (SAMPLE_COUNT != 0) {
			float* mean = new float[INPUT_COUNT];
			float* variance = new float[INPUT_COUNT];

			float* normalized_data = batch_normalization_train(DATASET, SAMPLE_COUNT, INPUT_COUNT, mean, variance);
			float* normalized_grid_data = batch_normalization_test(GRID_DATA, GRID_X * GRID_Y, INPUT_COUNT, mean, variance);

			std::chrono::steady_clock::time_point begin, end;
			begin = std::chrono::steady_clock::now();

			errorValueLabel->Text = "error: " + Convert::ToString(train(
				SAMPLE_COUNT,
				HIDDEN_LAYER_COUNT + 2,
				NEURON_COUNT,
				normalized_data,
				TARGET,
				WEIGHT,
				BIAS,
				LEARNING_RATE,
				MOMENTUM,
				EPOCHS,
				BATCH_SIZE,
				VERBOSE
			));

			end = std::chrono::steady_clock::now();
			label9->Text = "time: " + Convert::ToString(std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() * 0.001f) + "s";

			get_output(
				(GRID_X * GRID_Y),
				HIDDEN_LAYER_COUNT + 2,
				NEURON_COUNT,
				normalized_grid_data,
				WEIGHT,
				BIAS,
				GRID_CATEGORY
			);

			delete[] normalized_data;
			delete[] normalized_grid_data;
			delete[] mean;
			delete[] variance;
			pictureBox1->Refresh();
		}
	}

	private: System::Void menuReset_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show(
			"Are you sure?",
			"Program Reset", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			if (DATASET)
				delete[] DATASET;
			if (TARGET)
				delete[] TARGET;
			if (CATEGORY)
				delete[] CATEGORY;

			for (int i = 0; i < HIDDEN_LAYER_COUNT + 1; i++) {
				if (WEIGHT[i])
					delete[] WEIGHT[i];
				if (BIAS[i])
					delete[] BIAS[i];
			}

			if (WEIGHT)
				delete[] WEIGHT;
			if (BIAS)
				delete[] BIAS;

			for (int i = 0; i < (GRID_X * GRID_Y * CATEGORY_COUNT); i++)
				GRID_CATEGORY[i] = -1.0f;

			SAMPLE_COUNT = 0;
			NEURON_COUNT = 0;
			HIDDEN_LAYER_COUNT = -1;
			CATEGORY_COUNT = -1;
			CATEGORY_NOW = -1;
			TARGET = 0;
			DATASET = 0;
			CATEGORY = 0;
			WEIGHT = 0;
			BIAS = 0;
			PROGRAM_STATE = 0;
			BATCH_SIZE = -1;
			EPOCHS = -1;

			categorySelectCombobox->Text = "";
			categoryCombobox->Text = "";
			comboBox1->Text = "";
			comboBox2->Text = "";
			comboBox3->Text = "";

			sampleCountLabel->Text = "sample count: " + Convert::ToString(SAMPLE_COUNT);
			errorValueLabel->Text = "error: 0";
			label9->Text = "time: 0s";
			textBox1->Text = "";

			pictureBox1->Refresh();
		}
	}

	private: System::Void menuUndo_Click(System::Object^ sender, System::EventArgs^ e) {
		float* swap;
		int* category_swap;
		int i;

		if (SAMPLE_COUNT != 0) {
			if (SAMPLE_COUNT == 1) {
				delete[] DATASET;
				delete[] TARGET;
				delete[] CATEGORY;

				DATASET = 0;
				TARGET = 0;
				CATEGORY = 0;
				SAMPLE_COUNT = 0;
			}
			else {
				swap = DATASET;
				DATASET = new float[(SAMPLE_COUNT - 1) * INPUT_COUNT];
				for (i = 0; i < ((SAMPLE_COUNT - 1) * INPUT_COUNT); i++)
					DATASET[i] = swap[i];
				if (swap)
					delete[] swap;

				swap = TARGET;
				TARGET = new float[(SAMPLE_COUNT - 1) * CATEGORY_COUNT];
				for (i = 0; i < ((SAMPLE_COUNT - 1) * CATEGORY_COUNT); i++)
					TARGET[i] = swap[i];
				if (swap)
					delete[] swap;

				category_swap = CATEGORY;
				CATEGORY = new int[(SAMPLE_COUNT - 1)];
				for (i = 0; i < (SAMPLE_COUNT - 1); i++)
					CATEGORY[i] = category_swap[i];
				if (category_swap)
					delete[] category_swap;

				SAMPLE_COUNT--;
			}
			pictureBox1->Refresh();
		}
	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Pen^ pen = gcnew Pen(Color::Gray, 1.0f);
		int max_category;
		int i, j, k;
		float x1, x2, center_width, center_height, rect_width, rect_height;
		const float* sample;
		float max;
		float color[3] = { 0.0f, 0.0f, 0.0f };
		const float colors[7][3] = {
			{255.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 255.0f},
			{0.0f, 255.0f, 0.0f},
			{255.0f, 255.0f, 0.0f},
			{128.0f, 0.0f, 128.0f},
			{0.0f, 255.0f, 255.0f},
			{255.0f, 165.0f, 42.0f}
		};
		SolidBrush^ brush = gcnew SolidBrush(Color::Black);

		center_width = pictureBox1->Width * 0.5f;
		center_height = pictureBox1->Height * 0.5f;

		rect_width = (float)pictureBox1->Width / GRID_X;
		rect_height = (float)pictureBox1->Height / GRID_Y;

		if (GRID_DATA && GRID_CATEGORY && GRID_CATEGORY[0] != -1) {
			for (i = 0; i < (GRID_X * GRID_Y); i++) {
				sample = &GRID_DATA[i * INPUT_COUNT];
				x1 = sample[0] + (pictureBox1->Width >> 1);
				x2 = (pictureBox1->Height >> 1) - sample[1];
				Drawing::Rectangle pixel = Drawing::Rectangle((int)(x1 - (rect_width * 0.5f)), (int)(x2 - (rect_height * 0.5f)), (int)rect_width, (int)rect_height);

				max = 0.0f;
				max_category = -1;

				color[0] = color[1] = color[2] = 0.0f;
				
				if (MAPPING_MODE == 0) {
					for (j = 0; j < CATEGORY_COUNT; j++) {
						for (k = 0; k < 3; k++)
							color[k] += GRID_CATEGORY[i * CATEGORY_COUNT + j] * colors[j][k];

						if (max < GRID_CATEGORY[i * CATEGORY_COUNT + j]) {
							max = GRID_CATEGORY[i * CATEGORY_COUNT + j];
							max_category = j;
						}
					}

					switch (max_category) {
						case 0: brush->Color = Color::FromArgb(80, 255, 0, 0); break;
						case 1: brush->Color = Color::FromArgb(80, 0, 0, 255); break;
						case 2: brush->Color = Color::FromArgb(80, 0, 255, 0); break;
						case 3: brush->Color = Color::FromArgb(80, 255, 255, 0); break;
						case 4: brush->Color = Color::FromArgb(80, 128, 0, 128); break;
						case 5: brush->Color = Color::FromArgb(80, 0, 255, 255); break;
						case 6: brush->Color = Color::FromArgb(80, 255, 165, 0); break;
					}
					e->Graphics->FillRectangle(brush, pixel);
				}

				if (MAPPING_MODE == 1) {
					for (j = 0; j < CATEGORY_COUNT; j++) {
						for (k = 0; k < 3; k++)
							color[k] += GRID_CATEGORY[i * CATEGORY_COUNT + j] * colors[j][k];

						if (max < GRID_CATEGORY[i * CATEGORY_COUNT + j]) {
							max = GRID_CATEGORY[i * CATEGORY_COUNT + j];
							max_category = j;
						}
					}
					if (isnan(color[0]) || isnan(color[1]) || isnan(color[2]))
						continue;

					brush->Color = Color::FromArgb(80, (int)color[0], (int)color[1], (int)color[2]);
					e->Graphics->FillRectangle(brush, pixel);
				}
			}
		}
		
		if (SHOW_SAMPLES) {
			pen->Width = 2.0f;

			for (i = 0; i < SAMPLE_COUNT; i++) {
				sample = &DATASET[INPUT_COUNT * i];
				pen->Color = color_of(CATEGORY[i]);

				x1 = sample[0] + (pictureBox1->Width >> 1);
				x2 = (pictureBox1->Height >> 1) - sample[1];

				e->Graphics->DrawLine(pen, x1, x2 - 4, x1, x2 + 4);
				e->Graphics->DrawLine(pen, x1 - 4, x2, x1 + 4, x2);
			}
		}
		if (SHOW_AXES) {
			pen->Color = Color::Gray;
			pen->Width = 1.0f;

			e->Graphics->DrawLine(pen, (int)center_width, 0, (int)center_width, pictureBox1->Height);
			e->Graphics->DrawLine(pen, 0, (int)center_height, pictureBox1->Width, (int)center_height);
		}
	}

	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		float* swap;
		int* category_swap;
		int i;

		if (PROGRAM_STATE != 0) {
			if (CATEGORY_NOW == -1) {
				MessageBox::Show("Please select a category");
				return;
			}

			swap = DATASET;
			DATASET = new float[(SAMPLE_COUNT + 1) * INPUT_COUNT];
			for (i = 0; i < (SAMPLE_COUNT * INPUT_COUNT); i++)
				DATASET[i] = swap[i];
			if (swap)
				delete[] swap;

			swap = TARGET;
			TARGET = new float[(SAMPLE_COUNT + 1) * CATEGORY_COUNT];
			for (i = 0; i < (SAMPLE_COUNT * CATEGORY_COUNT); i++)
				TARGET[i] = swap[i];
			if (swap)
				delete[] swap;

			category_swap = CATEGORY;
			CATEGORY = new int[(SAMPLE_COUNT + 1)];
			for (i = 0; i < SAMPLE_COUNT; i++)
				CATEGORY[i] = category_swap[i];
			if (category_swap)
				delete[] category_swap;

			SAMPLE_COUNT++;

			DATASET[(SAMPLE_COUNT - 1) * INPUT_COUNT] = (float)(e->X - (pictureBox1->Width >> 1));
			DATASET[(SAMPLE_COUNT - 1) * INPUT_COUNT + 1] = (float)((pictureBox1->Height >> 1) - e->Y);

			for (i = 0; i < CATEGORY_COUNT; i++)
				if (i == CATEGORY_NOW)
					TARGET[(SAMPLE_COUNT - 1) * CATEGORY_COUNT + i] = 1.0f;
				else
					TARGET[(SAMPLE_COUNT - 1) * CATEGORY_COUNT + i] = 0.0f;

			CATEGORY[SAMPLE_COUNT - 1] = CATEGORY_NOW;

			if (comboBox2->GetItemText(comboBox2->SelectedItem) == "All")
				BATCH_SIZE = SAMPLE_COUNT;

			sampleCountLabel->Text = "sample count: " + Convert::ToString(SAMPLE_COUNT);
			pictureBox1->Refresh();
		}
	}

	private: System::Void categorySelectCombobox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (PROGRAM_STATE != 0) {
			if (categorySelectCombobox->SelectedIndex >= CATEGORY_COUNT) {
				MessageBox::Show("Category can't be higher than category count");
				return;
			}
			CATEGORY_NOW = categorySelectCombobox->SelectedIndex;
		}
		else
			MessageBox::Show("You should initialize the program first");
	}

	private: Drawing::Color color_of(int category) {
		switch (category) {
		case 0: return Color::Red;
		case 1: return Color::Blue;
		case 2: return Color::Green;
		case 3: return Color::FromArgb(200, 200, 0);
		case 4: return Color::Purple;
		case 5: return Color::DarkCyan;
		default:return Color::Orange;
		}
	}

	private: System::Void cLEARWEIGHTSToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PROGRAM_STATE == 0) {
			MessageBox::Show("You can only clear the weights during running mode");
			return;
		}

		int i;

		for (i = 0; i < HIDDEN_LAYER_COUNT + 1; i++) {
			if (WEIGHT[i])
				delete[] WEIGHT[i];
			if (BIAS[i])
				delete[] BIAS[i];
		}

		if (WEIGHT)
			delete[] WEIGHT;
		if (BIAS)
			delete[] BIAS;

		WEIGHT = new float* [HIDDEN_LAYER_COUNT + 1];
		BIAS = new float* [HIDDEN_LAYER_COUNT + 1];

		for (i = 0; i < HIDDEN_LAYER_COUNT + 1; i++) {
			WEIGHT[i] = init_array_random(NEURON_COUNT[i + 1] * NEURON_COUNT[i]);
			BIAS[i] = init_array_random(NEURON_COUNT[i + 1]);
		}

		for (i = 0; i < (GRID_X * GRID_Y * CATEGORY_COUNT); i++)
			GRID_CATEGORY[i] = -1;

		pictureBox1->Refresh();
	}

	private: System::Void rEADDATASETToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PROGRAM_STATE == 0) {
			MessageBox::Show("You should init the program before loading data");
			return;
		}
		if (openDataFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			try {
				System::IO::StreamReader^ din = System::IO::File::OpenText(openDataFileDialog->FileName);
				String^ str;
				int i, count;

				array<String^>^ StringArray = din->ReadLine()->Split(',');

				if (CATEGORY_COUNT < Convert::ToInt32(StringArray[1])) {
					MessageBox::Show("Category count is " + Convert::ToString(CATEGORY_COUNT) + " but there are " + Convert::ToString(Convert::ToInt32(StringArray[1]) + " categories in the file"));
					return;
				}

				SAMPLE_COUNT = Convert::ToInt32(StringArray[0]);
				sampleCountLabel->Text = "sample count: " + Convert::ToString(SAMPLE_COUNT);

				if(DATASET)
					delete[] DATASET;
				DATASET = new float[SAMPLE_COUNT * INPUT_COUNT];
				if(CATEGORY)
					delete[] CATEGORY;
				CATEGORY = new int[SAMPLE_COUNT];
				if(TARGET)
					delete[] TARGET;
				TARGET = new float[SAMPLE_COUNT * CATEGORY_COUNT];

				count = 0;
				while ((str = din->ReadLine()) != nullptr) {
					array<String^>^ StringArray = str->Split(',');
					DATASET[count * INPUT_COUNT] = (float)Convert::ToInt32(StringArray[0]);
					DATASET[count * INPUT_COUNT + 1] = (float)Convert::ToInt32(StringArray[1]);
					CATEGORY[count] = Convert::ToInt32(StringArray[2]);

					for (i = 0; i < CATEGORY_COUNT; i++)
						if (i == CATEGORY[count])
							TARGET[count * CATEGORY_COUNT + i] = 1.0f;
						else
							TARGET[count * CATEGORY_COUNT + i] = 0.0f;

					count++;
				}

				if (comboBox2->GetItemText(comboBox2->SelectedItem) == "All")
					BATCH_SIZE = SAMPLE_COUNT;

				pictureBox1->Refresh();
				MessageBox::Show(Convert::ToString(SAMPLE_COUNT) + " sample has been loaded");
			}
			catch (Exception^ e) {
				if (dynamic_cast<System::IO::FileNotFoundException^>(e))
					Console::WriteLine("file '{0}' not found", openDataFileDialog->FileName);
				else
					Console::WriteLine("problem reading file '{0}'", openDataFileDialog->FileName);
			}

		}
	}

	private: System::Void wRITEDATASETToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PROGRAM_STATE == 0) {
			MessageBox::Show("You should init the program before saving the data");
			return;
		}
		if (saveDataFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			IO::StreamWriter^ sw = gcnew IO::StreamWriter(saveDataFileDialog->FileName);
			sw->WriteLine("{0}, {1}, 0", SAMPLE_COUNT, CATEGORY_COUNT);
			for (int i = 0; i < SAMPLE_COUNT; i++)
				sw->WriteLine("{0}, {1}, {2}", DATASET[i * INPUT_COUNT], DATASET[i * INPUT_COUNT + 1], CATEGORY[i]);
			sw->Close();
			MessageBox::Show("a new file ('" + saveDataFileDialog->FileName + "') has been written");
		}
	}

	private: System::Void tRAINANIMATIONToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PROGRAM_STATE == 0) {
			MessageBox::Show("Please init the program before running");
			return;
		}
		if (BATCH_SIZE == -1) {
			MessageBox::Show("Please select the batch size before running");
			return;
		}
		if (EPOCHS == -1) {
			MessageBox::Show("Please select the epoch count before running");
			return;
		}
		if (SAMPLE_COUNT != 0) {
			float* mean = new float[INPUT_COUNT];
			float* variance = new float[INPUT_COUNT];

			float* normalized_data = batch_normalization_train(DATASET, SAMPLE_COUNT, INPUT_COUNT, mean, variance);
			float* normalized_grid_data = batch_normalization_test(GRID_DATA, GRID_X * GRID_Y, INPUT_COUNT, mean, variance);

			int frame_id, i;
			float error;

			std::chrono::steady_clock::time_point begin, end;
			begin = std::chrono::steady_clock::now();

			float* frames = new float[ANIMATION_FRAME_COUNT * GRID_X * GRID_Y * CATEGORY_COUNT];

			for (frame_id = 0; frame_id < ANIMATION_FRAME_COUNT; frame_id++) {
				error = train(
					SAMPLE_COUNT,
					HIDDEN_LAYER_COUNT + 2,
					NEURON_COUNT,
					normalized_data,
					TARGET,
					WEIGHT,
					BIAS,
					LEARNING_RATE,
					MOMENTUM,
					EPOCHS / ANIMATION_FRAME_COUNT,
					BATCH_SIZE,
					0
				);

				get_output(
					(GRID_X * GRID_Y),
					HIDDEN_LAYER_COUNT + 2,
					NEURON_COUNT,
					normalized_grid_data,
					WEIGHT,
					BIAS,
					&frames[frame_id * GRID_X * GRID_Y * CATEGORY_COUNT]
				);
			}

			float* tmp = GRID_CATEGORY;

			for (frame_id = 0; frame_id < ANIMATION_FRAME_COUNT; frame_id++) {
				GRID_CATEGORY = &frames[frame_id * GRID_X * GRID_Y * CATEGORY_COUNT];
				pictureBox1->Refresh();
				System::Threading::Thread::Sleep(TimeSpan::FromSeconds(0.25));
			}

			GRID_CATEGORY = tmp;

			for(i = 0; i < GRID_X * GRID_Y * CATEGORY_COUNT; i++)
				GRID_CATEGORY[i] = frames[(ANIMATION_FRAME_COUNT - 1) * GRID_X * GRID_Y * CATEGORY_COUNT + i];

			end = std::chrono::steady_clock::now();
			errorValueLabel->Text = "error: " + Convert::ToString(error);
			label9->Text = "time: " + Convert::ToString(std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() * 0.001f) + "s";
			delete[] normalized_data;
			delete[] normalized_grid_data;
			delete[] mean;
			delete[] variance;
			delete[] frames;
		}
	}

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (PROGRAM_STATE == 0)
			HIDDEN_LAYER_COUNT = comboBox1->SelectedIndex;
		else
			MessageBox::Show("You can't change ann architecture in running mode");
	}

	private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if ((int)e->KeyChar == 13) {
			if (PROGRAM_STATE == 1) {
				MessageBox::Show("You can't change ann architecture in running mode");
				return;
			}
			if (CATEGORY_COUNT == -1) {
				MessageBox::Show("You should set category count first");
				return;
			}
			if (HIDDEN_LAYER_COUNT == -1) {
				MessageBox::Show("You should set hidden layer count first");
				return;
			}
			if (!System::Text::RegularExpressions::Regex::IsMatch(textBox1->Text, "^((\\d+\\s)*\\d+)$|^$")) {
				MessageBox::Show("Please check architecture format");
				return;
			}

			array<String^>^ StringArray = textBox1->Text->Split(' ');
			int arrayLength = (textBox1->Text == "") ? 0 : StringArray->Length;

			if (arrayLength != HIDDEN_LAYER_COUNT)
				MessageBox::Show("There should be " + Convert::ToString(HIDDEN_LAYER_COUNT) + " layers, but you have " + Convert::ToString(arrayLength) + " layers.");
			else {
				if (NEURON_COUNT)
					delete[] NEURON_COUNT;

				NEURON_COUNT = new int[HIDDEN_LAYER_COUNT + 2];

				NEURON_COUNT[0] = INPUT_COUNT;
				for (int i = 0; i < HIDDEN_LAYER_COUNT; i++)
					NEURON_COUNT[i + 1] = Convert::ToInt32(StringArray[i]);
				NEURON_COUNT[HIDDEN_LAYER_COUNT + 1] = CATEGORY_COUNT;

				WEIGHT = new float* [HIDDEN_LAYER_COUNT + 1];
				BIAS = new float* [HIDDEN_LAYER_COUNT + 1];

				WEIGHT[0] = init_array_random(NEURON_COUNT[1] * NEURON_COUNT[0]);
				BIAS[0] = init_array_random(NEURON_COUNT[1]);

				for (int i = 1; i < HIDDEN_LAYER_COUNT + 1; i++) {
					WEIGHT[i] = init_array_random(NEURON_COUNT[i + 1] * NEURON_COUNT[i]);
					BIAS[i] = init_array_random(NEURON_COUNT[i + 1]);
				}

				GRID_CATEGORY = new float[GRID_X * GRID_Y * CATEGORY_COUNT];
				for (int i = 0; i < (GRID_X * GRID_Y * CATEGORY_COUNT); i++)
					GRID_CATEGORY[i] = -1;

				PROGRAM_STATE = 1;

				MessageBox::Show("Architecture is ready!");
			}
		}
	}

	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (PROGRAM_STATE == 0) {
			MessageBox::Show("You should init the program before the batch size decision");
			return;
		}

		if (comboBox2->GetItemText(comboBox2->SelectedItem) == "All")
			BATCH_SIZE = SAMPLE_COUNT;
		else
			BATCH_SIZE = Convert::ToInt32(comboBox2->GetItemText(comboBox2->SelectedItem));
	}

	private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (PROGRAM_STATE == 0) {
			MessageBox::Show("You should init the program before the batch size decision");
			return;
		}

		EPOCHS = Convert::ToInt32(comboBox3->GetItemText(comboBox3->SelectedItem));
	}

	private: System::Void cLEARDATAToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (PROGRAM_STATE == 0) {
			MessageBox::Show("You can only clear the data during running mode");
			return;
		}

		if (MessageBox::Show(
			"Are you sure?",
			"Clear Data", MessageBoxButtons::YesNo,
			MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			delete[] DATASET;
			delete[] TARGET;
			delete[] CATEGORY;

			DATASET = 0;
			TARGET = 0;
			CATEGORY = 0;
			SAMPLE_COUNT = 0;

			pictureBox1->Refresh();
		}
	}
	private: System::Void vERBOSEToolStripMenuItem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		VERBOSE = !VERBOSE;
	}
	private: System::Void cOLORMODEToolStripMenuItem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		MAPPING_MODE = !MAPPING_MODE;
		pictureBox1->Refresh();
	}
	private: System::Void activationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ToolStripMenuItem^ checkbox = safe_cast<ToolStripMenuItem^>(sender);

		if (reluToolStripMenuItem == checkbox) {
			ACTIVATION = &RELU;
			ACTIVATION_DER = &RELU_DER;
			reluToolStripMenuItem->Checked = true;
		}else
			reluToolStripMenuItem->Checked = false;

		if (leakyReluToolStripMenuItem == checkbox) {
			ACTIVATION = &LEAKY_RELU;
			ACTIVATION_DER = &LEAKY_RELU_DER;
			leakyReluToolStripMenuItem->Checked = true;
		}
		else
			leakyReluToolStripMenuItem->Checked = false;

		if (eluToolStripMenuItem == checkbox) {
			ACTIVATION = &ELU;
			ACTIVATION_DER = &ELU_DER;
			eluToolStripMenuItem->Checked = true;
		}
		else
			eluToolStripMenuItem->Checked = false;

		if (tanhToolStripMenuItem == checkbox) {
			ACTIVATION = &TANH;
			ACTIVATION_DER = &TANH_DER;
			tanhToolStripMenuItem->Checked = true;
		}
		else
			tanhToolStripMenuItem->Checked = false;

		if (sigmoidToolStripMenuItem == checkbox) {
			ACTIVATION = &SIGMOID;
			ACTIVATION_DER = &SIGMOID_DER;
			sigmoidToolStripMenuItem->Checked = true;
		}
		else
			sigmoidToolStripMenuItem->Checked = false;

		if (bipolarSigmoidToolStripMenuItem == checkbox) {
			ACTIVATION = &BIPOLAR_SIGMOID;
			ACTIVATION_DER = &BIPOLAR_SIGMOID_DER;
			bipolarSigmoidToolStripMenuItem->Checked = true;
		}
		else
			bipolarSigmoidToolStripMenuItem->Checked = false;
		
		if (sinusexperimentalToolStripMenuItem == checkbox) {
			ACTIVATION = &SINUS;
			ACTIVATION_DER = &SINUS_DER;
			sinusexperimentalToolStripMenuItem->Checked = true;
		}
		else
			sinusexperimentalToolStripMenuItem->Checked = false;

		if (noneToolStripMenuItem == checkbox) {
			ACTIVATION = &NONE;
			ACTIVATION_DER = &NONE_DER;
			noneToolStripMenuItem->Checked = true;
		}
		else
			noneToolStripMenuItem->Checked = false;

	}
	private: System::Void showAxesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SHOW_AXES = !SHOW_AXES;
		pictureBox1->Refresh();
	}
	private: System::Void showSamplesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		SHOW_SAMPLES = !SHOW_SAMPLES;
		pictureBox1->Refresh();
	}
};
}
