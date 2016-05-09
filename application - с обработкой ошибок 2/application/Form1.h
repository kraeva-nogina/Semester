#pragma once
#include "table.h"
#include <string>
#include <cstdlib>
#include <sstream>
#include <math.h>


namespace application {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:

		void NumberDays(int index, int & days) //опредение кол-ва дней в мес€це	
		{
			if ((index==0)||(index==2)||(index==4)||(index==6)||(index==7)||(index==9)||(index==11)) days = 31;
			if ((index==3)||(index==5)||(index==8)||(index==10)) days = 30;
			if (index==1) days = 28;
		}
		void AmountOfDays(int index, int & days, int & sum)  //вычисление количества дней в периоде
		{
			NumberDays(index, days);
			sum = sum + days;
		}
		void NameOfMonth(int index, String^ & name) //определение мес€ца
		{
			if (index==0) name = "€нварь"; if (index==1) name = "февраль"; if (index==2) name = "март";
			if (index==3) name = "апрель"; if (index==4) name = "май"; if (index==5) name = "июнь";
			if (index==6) name = "июль"; if (index==7) name = "август"; if (index==8) name = "сент€брь";
			if (index==9) name = "окт€брь"; if (index==10) name = "но€брь"; if (index==11) name = "декабрь";
		}
		void FinishYear(int & index, String^ & year)
		{
			index++;
			if (index == 12) { 
				index = 0; 
				year = (Convert::ToInt32(year) + 1).ToString();
			} 
		}
		void Filling(int row, int index, String^ year, int point, double FutureValue, double percent) //заполнение таблицы
		{
			F2->dataGridView1->Rows->Add(); //добавление строки в таблицу
			F2->dataGridView1->Rows[row]->Cells[0]->Value = (row+1).ToString();
			F2->dataGridView1->Rows[row]->Cells[2]->Value = String::Format("{0:0.00}", percent);
			if (point == 0) F2->dataGridView1->Rows[row]->Cells[3]->Value = textBox1->Text;
			else F2->dataGridView1->Rows[row]->Cells[3]->Value =String::Format("{0:0.00}", FutureValue);
			String^ name; 
			NameOfMonth(index,name);
			F2->dataGridView1->Rows[row]->Cells[1]->Value = "01 " + name + " " + year;  //дата
		}
		void SimpleInterest(double PresentValue, double Rate, int sum, double & percent)  //вычисление простого процента
		{
			percent = (PresentValue*Rate*sum)/(365*100);	
		}
		void CompoundInterest(double PresentValue, double Rate, int sum, int power, double & percent, double & FutureValue)  //вычисление процента с капитализацией (сложного процента)
		{
			double st = pow((1+(Rate*sum)/(365*100)), power); 
			percent = PresentValue*st - PresentValue;    //сумма процентов (доходов)
			FutureValue = PresentValue*st;  //будуща€ стоимость
		}
		void CalculateInterest(int point, double & PresentValue, double & Rate, int &sum, double &percent, double &FutureValue, int &row, int &index, String ^&year) //вычисление процента
		{
			if (point == 0) SimpleInterest(PresentValue, Rate, sum, percent);  //вычисление простого процента
				else { 
					CompoundInterest(PresentValue, Rate, sum, 1, percent, FutureValue); //вычисление сложного процента
					PresentValue = FutureValue;
				}  
			Filling(row, index, year, point, FutureValue, percent);
			row ++;
		}
		void ChoosePeriod (int & num) {
			if (comboBox2->Text == "ежемес€чно") num = 1;
			if (comboBox2->Text == "1 раз в 3 мес€ца") num = 3;
			if (comboBox2->Text == "раз в полгодие") num = 6;
			if (comboBox2->Text == "раз в год") num = 12;
		}		
		void Totals(int point, double FutureValue, int row, double PresentValue)
		{
			double percent = 0;
			F2->label5->Text = textBox1->Text;
			F2->label9->Text = textBox3->Text;
			F2->label10->Text = textBox2->Text;
			if (point == 1) F2->label11->Text = String::Format("{0:0.00}", FutureValue);
			else {
				for (int i = 0; i < row; i ++)
					PresentValue = PresentValue + Convert::ToDouble(F2->dataGridView1->Rows[i]->Cells[2]->Value);
				F2->label11->Text = String::Format("{0:0.00}", PresentValue);
			}
			for (int i = 0; i <= row; i++)	
				percent = percent + Convert::ToDouble(F2->dataGridView1->Rows[i]->Cells[2]->Value);
			F2->label12->Text = percent.ToString();
		}
		void Clean()
		{
			textBox1->Text = "";
			textBox2->Text = "";
			textBox3->Text = "";
			radioButton1->Checked = false;
			radioButton2->Checked = false;
			comboBox1->Text = "мес€ц";
			comboBox3->Text = "год";
			comboBox2->Text = "";
		}

		table ^ F2;
		int Months;
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	public: 
	private: System::Windows::Forms::ErrorProvider^  errorProvider2;

	private: System::Windows::Forms::ComboBox^  comboBox3;
	public: 
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 

	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button1;
private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->errorProvider2 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(82, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(273, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ƒепозитный калькул€тор";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(25, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 22);
			this->label2->TabIndex = 1;
			this->label2->Text = L"—умма вклада";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(191, 72);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(122, 27);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_Validated);
			this->textBox1->Validated += gcnew System::EventHandler(this, &Form1::textBox1_Validated);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(191, 116);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(122, 27);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_Validated);
			this->textBox2->Validated += gcnew System::EventHandler(this, &Form1::textBox2_Validated);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(191, 165);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(122, 27);
			this->textBox3->TabIndex = 4;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_Validated);
			this->textBox3->Validated += gcnew System::EventHandler(this, &Form1::textBox3_Validated);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 117);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(173, 22);
			this->label3->TabIndex = 5;
			this->label3->Text = L"ѕроцентна€ ставка";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(323, 75);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(48, 22);
			this->label4->TabIndex = 6;
			this->label4->Text = L"RUB";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(323, 119);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 22);
			this->label5->TabIndex = 7;
			this->label5->Text = L"% годовых";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(37, 165);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(117, 22);
			this->label6->TabIndex = 8;
			this->label6->Text = L"—рок вклада";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(323, 168);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(83, 22);
			this->label7->TabIndex = 9;
			this->label7->Text = L"мес€цев";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(25, 212);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(135, 44);
			this->label8->TabIndex = 10;
			this->label8->Text = L"ƒата открыти€\r\n       вклада";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"€нварь", L"февраль", L"март", L"апрель", L"май", 
				L"июнь", L"июль", L"август", L"сент€брь", L"окт€брь", L"но€брь", L"декабрь"});
			this->comboBox1->Location = System::Drawing::Point(191, 226);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(102, 30);
			this->comboBox1->TabIndex = 11;
			this->comboBox1->Text = L"мес€ц";
			this->comboBox1->TextChanged += gcnew System::EventHandler(this, &Form1::comboBox1_TextChanged);
			this->comboBox1->Validated += gcnew System::EventHandler(this, &Form1::comboBox1_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(25, 280);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(140, 44);
			this->label9->TabIndex = 13;
			this->label9->Text = L" апитализаци€\r\n       вклада";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(217, 292);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(59, 26);
			this->radioButton1->TabIndex = 14;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Ќет";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_Validated);
			this->radioButton1->Validated += gcnew System::EventHandler(this, &Form1::radioButton1_Validated);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(303, 292);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(52, 26);
			this->radioButton2->TabIndex = 15;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"ƒа";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_Validated);
			this->radioButton2->Validated += gcnew System::EventHandler(this, &Form1::radioButton2_Validated);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(37, 348);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(112, 44);
			this->label10->TabIndex = 16;
			this->label10->Text = L"Ќачисление\r\n процентов";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"ежемес€чно", L"1 раз в 3 мес€ца", L"раз в полгодие", 
				L"раз в год"});
			this->comboBox2->Location = System::Drawing::Point(191, 361);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(189, 30);
			this->comboBox2->TabIndex = 17;
			this->comboBox2->TextChanged += gcnew System::EventHandler(this, &Form1::comboBox2_TextChanged);
			this->comboBox2->Validated += gcnew System::EventHandler(this, &Form1::comboBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(138, 412);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(155, 50);
			this->button1->TabIndex = 18;
			this->button1->Text = L"–ассчитать";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// comboBox3
			// 
			this->comboBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"2016", L"2017", L"2018", L"2019", L"2020"});
			this->comboBox3->Location = System::Drawing::Point(304, 226);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(102, 30);
			this->comboBox3->TabIndex = 19;
			this->comboBox3->Text = L"год";
			this->comboBox3->TextChanged += gcnew System::EventHandler(this, &Form1::comboBox3_TextChanged);
			this->comboBox3->Validated += gcnew System::EventHandler(this, &Form1::comboBox3_TextChanged);
			// 
			// errorProvider1
			// 
			this->errorProvider1->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProvider1->ContainerControl = this;
			// 
			// errorProvider2
			// 
			this->errorProvider2->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProvider2->ContainerControl = this;
			this->errorProvider2->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"errorProvider2.Icon")));
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(428, 474);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L" алькул€тор";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->errorProvider2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		double Rate = 0, PresentValue = 0;
		PresentValue = Convert::ToInt32(textBox1->Text);//первоначальна€ сумма
		Rate = Convert::ToDouble(textBox2->Text); //годова€ ставка
		Months = Convert::ToInt32(textBox3->Text); //кол-во мес€цев
		String ^month = comboBox1->Text; //мес€ц

		double percent = 0, FutureValue = 0;
		int index = comboBox1->FindString( comboBox1->Text );

		int sum = 0, days = 0, row = 0, i = 0, num = 0, point = 0 ;

		F2=gcnew table();
		F2->Show();
		String^ year = comboBox3->Text;

		ChoosePeriod(num); //выбираем периодичность выплат 

		if (radioButton1->Checked) point = 0;
		if (radioButton2->Checked) point = 1;

		int balance = Months % num;  //остаток мес€цев
		Months = Months - balance;  

		for (i = 0; i < Months; i++) 
		{
			AmountOfDays(index, days, sum);
			if ((i + 1) % num == 0)  //по истечению определенного кол-ва мес€цев
			{
				CalculateInterest(point, PresentValue, Rate, sum, percent, FutureValue, row, index, year);
				sum = 0; 
			}
			FinishYear(index, year);
		}


		sum = 0; 
		//остаток мес€цев
		if (balance != 0) {
			for ( i = 0; i < balance; i++) 
			{	
				AmountOfDays(index, days, sum); //вычисление количества дней в периоде
				if (i==balance-1)
					CalculateInterest(point,PresentValue, Rate, sum, percent, FutureValue, row, index, year);
				FinishYear(index, year);
			}		
		}
				
		Totals(point, FutureValue, row, PresentValue);
		
		if (F2->Enabled==true) Clean();

	}
	private: System::Void textBox1_Validated(System::Object^  sender, System::EventArgs^  e) {
			 if (textBox1->Text == "")
			 {
				 errorProvider1->SetError(textBox1, "please enter value");
				 errorProvider2->SetError(textBox1, "");
				 textBox1->BackColor = Color::White;
			 }
			 else {
				 int number = -1;
				 if (Int32::TryParse(textBox1->Text, number))
					 {if (number>0)
					 {
						errorProvider1->SetError(textBox1, "");
						errorProvider2->SetError(textBox1, "correct");
						textBox1->BackColor = Color::Honeydew;
				 }}
				else
				{ 
					errorProvider1->SetError(textBox1, "Please enter only numbers");
					errorProvider2->SetError(textBox1, "");
					textBox1->BackColor = Color::MistyRose;
				 }
			 }
		 }		 
	private: System::Void textBox2_Validated(System::Object^  sender, System::EventArgs^  e) {
			 if (textBox2->Text == "")
			 {
				 errorProvider1->SetError(textBox2, "please enter value");
				 errorProvider2->SetError(textBox2, "");
				 textBox2->BackColor = Color::White;
			 }
			 else {
				 double number = -1;
				 if (Double::TryParse(textBox2->Text, number))
					 {if (number>0)
					 {
						errorProvider1->SetError(textBox2, "");
						errorProvider2->SetError(textBox2, "correct");
						textBox2->BackColor = Color::Honeydew;
				 }}
				else
				{ 
					errorProvider1->SetError(textBox2, "Please enter only numbers");
					errorProvider2->SetError(textBox2, "");
					textBox2->BackColor = Color::MistyRose;
				 }
			 }
		 }
	private: System::Void textBox3_Validated(System::Object^  sender, System::EventArgs^  e) {
			  if (textBox3->Text == "")
			 {
				 errorProvider1->SetError(textBox3, "please enter value");
				 errorProvider2->SetError(textBox3, "");
				 textBox3->BackColor = Color::White;
			 }
			 else {
				 int number = -1;
				 if (Int32::TryParse(textBox3->Text, number))
					 {if (number>0)
					 {
						errorProvider1->SetError(textBox3, "");
						errorProvider2->SetError(textBox3, "correct");
						textBox3->BackColor = Color::Honeydew;
				 }}
				else
				{ 
					errorProvider1->SetError(textBox3, "Please enter only numbers");
					errorProvider2->SetError(textBox3, "");
					textBox3->BackColor = Color::MistyRose;
				 }
			 }
		 }	 
	private: System::Void radioButton1_Validated(System::Object^  sender, System::EventArgs^  e) {

			 if (radioButton1->Checked) {
						errorProvider1->SetError(radioButton2, "");
						errorProvider2->SetError(radioButton2, "correct");
			 }
		 }
	private: System::Void radioButton2_Validated(System::Object^  sender, System::EventArgs^  e) {
			 
			 if (radioButton2->Checked) {
						errorProvider1->SetError(radioButton2, "");
						errorProvider2->SetError(radioButton2, "correct");
			 }
		 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

		errorProvider1->SetError(textBox1, "please enter value");
		errorProvider2->SetError(textBox1, ""); 

		errorProvider1->SetError(textBox2, "please enter value");
		errorProvider2->SetError(textBox2, "");  

		errorProvider1->SetError(textBox3, "please enter value");
		errorProvider2->SetError(textBox3, "");  
			
		errorProvider1->SetError(comboBox3, "please enter value");
		errorProvider2->SetError(comboBox3, "");

		errorProvider1->SetError(radioButton2, "please enter value");
		errorProvider2->SetError(radioButton2, "");

		errorProvider1->SetError(comboBox2, "please enter value");
		errorProvider2->SetError(comboBox2, "");

		 }
	private: System::Void comboBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 int num = 0;
			 ChoosePeriod(num);
			 if (num != 0) {
				errorProvider1->SetError(comboBox2, "");
				errorProvider2->SetError(comboBox2, "correct");
				comboBox2->BackColor = Color::Honeydew;
			 }
			 else
			 {
				 errorProvider1->SetError(comboBox2, "please enter value");
				 errorProvider2->SetError(comboBox2, "");
				 comboBox2->BackColor = Color::MistyRose;
			 }
		 }
	private: System::Void comboBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			int k = 0, k1 = 0;
			if ((comboBox1->Text =="€нварь") || (comboBox1->Text == "февраль") || (comboBox1->Text == "март") || (comboBox1->Text =="апрель") || (comboBox1->Text =="май") || (comboBox1->Text =="июнь") || (comboBox1->Text =="июль") || (comboBox1->Text =="август") || (comboBox1->Text =="сент€брь") || (comboBox1->Text =="окт€брь") || (comboBox1->Text =="но€брь") || (comboBox1->Text =="декабрь"))
			{
				k = 1;
				comboBox1->BackColor = Color::Honeydew;
			}
			else
				comboBox1->BackColor = Color::MistyRose;

			if ((comboBox3->Text == "2016") || (comboBox3->Text == "2017") || (comboBox3->Text == "2018") || (comboBox3->Text =="2019") || (comboBox3->Text =="2020"))
				k1 = 1;

			if ((k == 1) && (k1 == 1 )) {
				errorProvider1->SetError(comboBox3, "");
				errorProvider2->SetError(comboBox3, "correct");
			 }
			 else
			 {
				 errorProvider1->SetError(comboBox3, "please enter value");
				 errorProvider2->SetError(comboBox3, "");
			 }
		 }
	private: System::Void comboBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			int k = 0, k1 = 0;
			if ((comboBox3->Text == "2016") || (comboBox3->Text == "2017") || (comboBox3->Text == "2018") || (comboBox3->Text =="2019") || (comboBox3->Text =="2020"))
			{
				k1 = 1;
				comboBox3->BackColor = Color::Honeydew;
			}
			else
				comboBox3->BackColor = Color::MistyRose;

			if ((comboBox1->Text =="€нварь") || (comboBox1->Text == "февраль") || (comboBox1->Text == "март") || (comboBox1->Text =="апрель") || (comboBox1->Text =="май") || (comboBox1->Text =="июнь") || (comboBox1->Text =="июль") || (comboBox1->Text =="август") || (comboBox1->Text =="сент€брь") || (comboBox1->Text =="окт€брь") || (comboBox1->Text =="но€брь") || (comboBox1->Text =="декабрь"))
				k = 1;

			if ((k == 1) && (k1 == 1 )) {
				errorProvider1->SetError(comboBox3, "");
				errorProvider2->SetError(comboBox3, "correct");
			 }
			 else
			 {
				 errorProvider1->SetError(comboBox3, "please enter value");
				 errorProvider2->SetError(comboBox3, "");
			 }
		 }
};
}

