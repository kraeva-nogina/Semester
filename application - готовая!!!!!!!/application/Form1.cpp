#include "stdafx.h"
#include "Form1.h"
#include <string>
#include <math.h>
#include <vector>
using namespace System;
using namespace std;
#include "Calc.h"

using namespace application;

void Check(TextBox^ Chat, ErrorProvider^  error1, ErrorProvider^  error2, int &number)
{
	if (number>0)
			{
				error1->SetError(Chat, "");
				error2->SetError(Chat, "correct");
				Chat->BackColor = Color::Honeydew;
			 }
		else
		{ 
			error1->SetError(Chat, "Please enter only numbers");
			error2->SetError(Chat, "");
			Chat->BackColor = Color::MistyRose;
		 }
	
}

void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if ((textBox1->BackColor == Color::Honeydew) && (textBox2->BackColor == Color::Honeydew) && (textBox3->BackColor == Color::Honeydew) && ((radioButton1->Checked) || (radioButton2->Checked)) && (comboBox2->BackColor == Color::Honeydew) && (comboBox1->BackColor == Color::Honeydew) && (comboBox3->BackColor == Color::Honeydew))
	{
		int amount_of_days = 0, days_in_month = 0, row = 0, i = 0, num = 0, point = 0, number_of_month = 0, Months = 0;
		double Rate = 0, PresentValue = 0, percent = 0, FutureValue = 0;
		String^ year, ^month; 
		vector <string> date, percentage, deposit;

		Readout(PresentValue, Rate, Months, month, year, number_of_month, point, num); //считывание данных

		F2 = gcnew table();
		F2->Show();

		int balance = Months % num;  //остаток мес€цев
		Months = Months - balance;  

		for (i = 0; i < Months; i++) 
		{
			AmountOfDays(number_of_month, days_in_month, amount_of_days);
			if ((i + 1) % num == 0)  //по истечению периода
			{
				CalculateInterest(point, PresentValue, Rate, amount_of_days, percent, FutureValue, row, number_of_month, year, date, percentage, deposit);
				amount_of_days = 0; 
			}
			FinishYear(number_of_month, year);
		}

		amount_of_days = 0; //остаток мес€цев
		if (balance != 0)
			for ( i = 0; i < balance; i++) 
			{	
				AmountOfDays(number_of_month, days_in_month, amount_of_days); //вычисление количества дней в периоде
				if (i == balance-1)
					CalculateInterest(point,PresentValue, Rate, amount_of_days, percent, FutureValue, row, number_of_month, year,  date, percentage, deposit);
				FinishYear(number_of_month, year);
			}		
		
		Output(row, date, percentage, deposit); //вывод таблицы		
		Totals(point, FutureValue, row, PresentValue); //вывод текста перед таблицей
		if (F2->Enabled==true) Clean();  //отчищение
	}
}
void Form1::textBox1_Validated(System::Object^  sender, System::EventArgs^  e) {
	if (textBox1->Text == "")
	{
		errorProvider1->SetError(textBox1, "please enter value");
		errorProvider2->SetError(textBox1, "");
		textBox1->BackColor = Color::White;
	 }
	else {
		int number = -1;
		Int32::TryParse(textBox1->Text, number);
		Check(textBox1, errorProvider1, errorProvider2, number);
	}
}		 
void Form1::textBox2_Validated(System::Object^  sender, System::EventArgs^  e) {
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
void Form1::textBox3_Validated(System::Object^  sender, System::EventArgs^  e) {
	if (textBox3->Text == "")
	{
		errorProvider1->SetError(textBox3, "please enter value");
		errorProvider2->SetError(textBox3, "");
		textBox3->BackColor = Color::White;
	}
	else {
		int number = -1;
		Int32::TryParse(textBox3->Text, number);
		Check(textBox3, errorProvider1, errorProvider2, number);
	}
}	 
void Form1::radioButton1_Validated(System::Object^  sender, System::EventArgs^  e) {
	if (radioButton1->Checked) {
		errorProvider1->SetError(radioButton2, "");
		errorProvider2->SetError(radioButton2, "correct");
	}
}
void Form1::radioButton2_Validated(System::Object^  sender, System::EventArgs^  e) {
	if (radioButton2->Checked) {
		errorProvider1->SetError(radioButton2, "");
		errorProvider2->SetError(radioButton2, "correct");
	}
}
void Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e) {
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
void Form1::comboBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
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
void Form1::comboBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
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
void Form1::comboBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
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
	