#pragma once
//#include "menu.h"
# include <string.h>
# include <string>
# include "IDictionary.h"
namespace chartlaba31 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Gistogramma
	/// </summary>
	
	public ref class Gistogramma : public System::Windows::Forms::Form
	{
	public:
		Gistogramma(void)
		{
			InitializeComponent();
				//area.AxisX.Interval = 1


			//
			//TODO: добавьте код конструктора
			//
		}
	
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Gistogramma()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ построитьГрафикToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ очиститьГрафикToolStripMenuItem;


	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ start;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ step;

	private: System::Windows::Forms::TextBox^ end;
	private: System::Windows::Forms::TextBox^ count;


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->построитьГрафикToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->очиститьГрафикToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->count = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->step = (gcnew System::Windows::Forms::TextBox());
			this->end = (gcnew System::Windows::Forms::TextBox());
			this->start = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menuStrip1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->выходToolStripMenuItem,
					this->построитьГрафикToolStripMenuItem, this->очиститьГрафикToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1379, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(66, 24);
			this->выходToolStripMenuItem->Text = L"выход";
			// 
			// построитьГрафикToolStripMenuItem
			// 
			this->построитьГрафикToolStripMenuItem->Name = L"построитьГрафикToolStripMenuItem";
			this->построитьГрафикToolStripMenuItem->Size = System::Drawing::Size(148, 24);
			this->построитьГрафикToolStripMenuItem->Text = L"построить график";
			this->построитьГрафикToolStripMenuItem->Click += gcnew System::EventHandler(this, &Gistogramma::построитьГрафикToolStripMenuItem_Click);
			// 
			// очиститьГрафикToolStripMenuItem
			// 
			this->очиститьГрафикToolStripMenuItem->Name = L"очиститьГрафикToolStripMenuItem";
			this->очиститьГрафикToolStripMenuItem->Size = System::Drawing::Size(138, 24);
			this->очиститьГрафикToolStripMenuItem->Text = L"очистить график";
			this->очиститьГрафикToolStripMenuItem->Click += gcnew System::EventHandler(this, &Gistogramma::очиститьГрафикToolStripMenuItem_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->count);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->step);
			this->groupBox2->Controls->Add(this->end);
			this->groupBox2->Controls->Add(this->start);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Location = System::Drawing::Point(1041, 61);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(326, 209);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"параметры";
			// 
			// count
			// 
			this->count->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->count->Location = System::Drawing::Point(213, 151);
			this->count->Name = L"count";
			this->count->Size = System::Drawing::Size(98, 30);
			this->count->TabIndex = 7;
			this->count->TextChanged += gcnew System::EventHandler(this, &Gistogramma::textBox4_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(6, 154);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(184, 25);
			this->label4->TabIndex = 6;
			this->label4->Text = L"кол-во элементов";
			// 
			// step
			// 
			this->step->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->step->Location = System::Drawing::Point(123, 111);
			this->step->Name = L"step";
			this->step->Size = System::Drawing::Size(98, 30);
			this->step->TabIndex = 5;
			// 
			// end
			// 
			this->end->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->end->Location = System::Drawing::Point(146, 68);
			this->end->Name = L"end";
			this->end->Size = System::Drawing::Size(98, 30);
			this->end->TabIndex = 4;
			this->end->TextChanged += gcnew System::EventHandler(this, &Gistogramma::textBox2_TextChanged);
			// 
			// start
			// 
			this->start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->start->Location = System::Drawing::Point(146, 29);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(98, 30);
			this->start->TabIndex = 3;
			this->start->TextChanged += gcnew System::EventHandler(this, &Gistogramma::textBox1_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(6, 114);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"диапазон";
			this->label3->Click += gcnew System::EventHandler(this, &Gistogramma::label3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(6, 73);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"B (конец)";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(6, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"A (начало)";
			this->label1->Click += gcnew System::EventHandler(this, &Gistogramma::label1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"Int", L"Float", L"ComplexNumber", L"String",
					L"Student", L"Teacher"
			});
			this->comboBox1->Location = System::Drawing::Point(1041, 322);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(221, 24);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Gistogramma::comboBox1_SelectedIndexChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(1036, 294);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(163, 25);
			this->label5->TabIndex = 8;
			this->label5->Text = L"тип элементов:";
			this->label5->Click += gcnew System::EventHandler(this, &Gistogramma::label5_Click);
			// 
			// chart1
			// 
			chartArea1->AxisX->Interval = 2;
			chartArea1->AxisX->LabelAutoFitMinFontSize = 5;
			chartArea1->AxisX->LabelAutoFitStyle = System::Windows::Forms::DataVisualization::Charting::LabelAutoFitStyles::WordWrap;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 61);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->MarkerSize = 2;
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(1018, 524);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &Gistogramma::chart1_Click);
			// 
			// Gistogramma
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1379, 759);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Gistogramma";
			this->Text = L"Gistogramma";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void построитьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Dictionary<string, int>* result;
	if (count->Text != "" && step->Text != "" && start->Text != "" && end->Text != "" && comboBox1->SelectedIndex != -1) {
		int countInt = Convert::ToInt64(count->Text);
		int stepInt = Convert::ToInt64(step->Text);

		
		extern void InputSequence(int dataType, int count, int min, int max);
		
		extern Dictionary<string, int>* GetPointsForGistogramm(int start, int end, int step, int dataType);
		

		if (comboBox1->SelectedIndex < 3)
		{
			stepInt = max(stepInt, 1);
			this->chart1->ChartAreas[0]->AxisX->Interval=stepInt;
			int startInt = Convert::ToInt64(start->Text);
			int endInt = Convert::ToInt64(end->Text);
			InputSequence(comboBox1->SelectedIndex, countInt, startInt, endInt);
			result = GetPointsForGistogramm(startInt, endInt, stepInt, comboBox1->SelectedIndex);

			if (startInt < stepInt) { startInt = stepInt ; }
			for (int i = startInt; i < endInt; i += stepInt )
			{
				if (result->ContainsKey(std::to_string(i))) this->chart1->Series[0]->Points->AddXY(i, result->Get(std::to_string(i)));
			}
		}
	}
		if (comboBox1->SelectedIndex >= 3 && count->Text != "" && comboBox1->SelectedIndex != -1)
		{
			int countInt = Convert::ToInt64(count->Text);
			this->chart1->ChartAreas[0]->AxisX->Interval = 1;
			extern void InputSequence(int dataType, int count);
			extern Dictionary<string, int>* GetPointsForGistogramm( int dataType);
			InputSequence(comboBox1->SelectedIndex, countInt);
			result=GetPointsForGistogramm(comboBox1->SelectedIndex);
			
			
			
			if (result->ContainsKey("A")) this->chart1->Series[0]->Points->AddXY("A", result->Get("A"));
			if (result->ContainsKey("B")) this->chart1->Series[0]->Points->AddXY("B", result->Get("B"));
			if (result->ContainsKey("C")) this->chart1->Series[0]->Points->AddXY("C", result->Get("C"));
			if (result->ContainsKey("D")) this->chart1->Series[0]->Points->AddXY("D", result->Get("D"));
			if (result->ContainsKey("E")) this->chart1->Series[0]->Points->AddXY("E", result->Get("E"));
			if (result->ContainsKey("F")) this->chart1->Series[0]->Points->AddXY("F", result->Get("F"));
			if (result->ContainsKey("G")) this->chart1->Series[0]->Points->AddXY("G", result->Get("G"));
			if (result->ContainsKey("H")) this->chart1->Series[0]->Points->AddXY("H", result->Get("H"));
			if (result->ContainsKey("I")) this->chart1->Series[0]->Points->AddXY("I", result->Get("I"));
			if (result->ContainsKey("J")) this->chart1->Series[0]->Points->AddXY("J", result->Get("J"));
			if (result->ContainsKey("K")) this->chart1->Series[0]->Points->AddXY("K", result->Get("K"));
			if (result->ContainsKey("L")) this->chart1->Series[0]->Points->AddXY("L", result->Get("L"));
			if (result->ContainsKey("M")) this->chart1->Series[0]->Points->AddXY("M", result->Get("M"));
			if (result->ContainsKey("N")) this->chart1->Series[0]->Points->AddXY("N", result->Get("N"));
			if (result->ContainsKey("O")) this->chart1->Series[0]->Points->AddXY("O", result->Get("O"));
			if (result->ContainsKey("P")) this->chart1->Series[0]->Points->AddXY("P", result->Get("P"));
			if (result->ContainsKey("Q")) this->chart1->Series[0]->Points->AddXY("Q", result->Get("Q"));
			if (result->ContainsKey("R")) this->chart1->Series[0]->Points->AddXY("R", result->Get("R"));
			if (result->ContainsKey("S")) this->chart1->Series[0]->Points->AddXY("S", result->Get("S"));
			if (result->ContainsKey("T")) this->chart1->Series[0]->Points->AddXY("T", result->Get("T"));
			if (result->ContainsKey("U")) this->chart1->Series[0]->Points->AddXY("U", result->Get("U"));
			if (result->ContainsKey("V")) this->chart1->Series[0]->Points->AddXY("V", result->Get("V"));
			if (result->ContainsKey("W")) this->chart1->Series[0]->Points->AddXY("W", result->Get("W"));
			if (result->ContainsKey("X")) this->chart1->Series[0]->Points->AddXY("X", result->Get("X"));
			if (result->ContainsKey("Y")) this->chart1->Series[0]->Points->AddXY("Y", result->Get("Y"));
			if (result->ContainsKey("Z")) this->chart1->Series[0]->Points->AddXY("Z", result->Get("Z"));
				//if (result->ContainsKey(std::to_string(i))) this->chart1->Series[0]->Points->AddXY(x[i], result->Get(std::to_string(i)));

		}
	
}
private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void очиститьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->chart1->Series[0]->Points->Clear();
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void chart1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
