#pragma once

namespace application {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для table
	/// </summary>
	public ref class table : public System::Windows::Forms::Form
	{
	public: 
		table(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~table()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^  dataGridView1;
	public: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	public: 
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	public: System::Windows::Forms::Label^  label5;
	public: System::Windows::Forms::Label^  label9;
	public: System::Windows::Forms::Label^  label10;
	public: System::Windows::Forms::Label^  label11;
	public: System::Windows::Forms::Label^  label12;

	protected: 

	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->Column1, 
				this->Column2, this->Column4, this->Column5});
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle6;
			this->dataGridView1->Location = System::Drawing::Point(12, 158);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle7->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle7->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle7->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle7->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle7;
			this->dataGridView1->Size = System::Drawing::Size(503, 332);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->Column1->DefaultCellStyle = dataGridViewCellStyle2;
			this->Column1->HeaderText = L"№";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 30;
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->Column2->DefaultCellStyle = dataGridViewCellStyle3;
			this->Column2->HeaderText = L"Дата";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 69;
			// 
			// Column4
			// 
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->Format = L"C2";
			dataGridViewCellStyle4->NullValue = nullptr;
			this->Column4->DefaultCellStyle = dataGridViewCellStyle4;
			this->Column4->HeaderText = L"Начисленные проценты %";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 150;
			// 
			// Column5
			// 
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle5->Format = L"N2";
			dataGridViewCellStyle5->NullValue = nullptr;
			this->Column5->DefaultCellStyle = dataGridViewCellStyle5;
			this->Column5->HeaderText = L"Остаток вклада";
			this->Column5->Name = L"Column5";
			this->Column5->Width = 150;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 17.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(162, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(187, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"График вклада";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(12, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Вклад";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(147, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 20);
			this->label3->TabIndex = 3;
			this->label3->Text = L"на";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(242, 57);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(117, 20);
			this->label4->TabIndex = 4;
			this->label4->Text = L"месяцев под";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(416, 57);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(99, 20);
			this->label6->TabIndex = 6;
			this->label6->Text = L"% годовых";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(12, 91);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(195, 20);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Сумма на конец срока";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(12, 124);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(210, 20);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Начисленные проценты";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(83, 58);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 20);
			this->label5->TabIndex = 9;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(196, 58);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 20);
			this->label9->TabIndex = 10;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(378, 58);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 20);
			this->label10->TabIndex = 11;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(218, 91);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 20);
			this->label11->TabIndex = 12;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(231, 124);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(0, 20);
			this->label12->TabIndex = 13;
			// 
			// table
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(534, 426);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"table";
			this->Text = L"Рассчет вклада";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

};
}
