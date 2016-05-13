#ifndef MY_H
#define MY_H
#include <string>
#include <math.h>
#include <vector>
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace std;

void NumberDays(int index, int &days_in_month) //����������� ���-�� ���� � ������	
{
	if ((index==0)||(index==2)||(index==4)||(index==6)||(index==7)||(index==9)||(index==11)) days_in_month = 31;
	if ((index==3)||(index==5)||(index==8)||(index==10)) days_in_month = 30;
	if (index==1) days_in_month = 28;
}
void AmountOfDays(int index, int &days_in_month, int &amount_of_days)  //���������� ���������� ���� � �������
{
	NumberDays(index, days_in_month);
	amount_of_days = amount_of_days + days_in_month;
}
void NameOfMonth(int number_of_month, String^ &name) //����������� ������
{
	if (number_of_month==0) name = "������"; if (number_of_month==1) name = "�������"; if (number_of_month==2) name = "����";
	if (number_of_month==3) name = "������"; if (number_of_month==4) name = "���"; if (number_of_month==5) name = "����";
	if (number_of_month==6) name = "����"; if (number_of_month==7) name = "������"; if (number_of_month==8) name = "��������";
	if (number_of_month==9) name = "�������"; if (number_of_month==10) name = "������"; if (number_of_month==11) name = "�������";
}
void FinishYear(int &number_of_month, String^ &year)  
{	
	number_of_month++;
	if (number_of_month == 12) { 
		number_of_month = 0; 
		year = (Convert::ToInt32(year) + 1).ToString();
	} 
}
void SimpleInterest(double PresentValue, double Rate, int amount_of_days, double &percent)  //���������� �������� ��������
{
	percent = (PresentValue*Rate*amount_of_days)/(365*100);	
}
void CompoundInterest(double &PresentValue, double Rate, int amount_of_days, double &percent, double &FutureValue)  //���������� �������� � �������������� (�������� ��������)
{
	double multiplier = 1 + (Rate * amount_of_days)/(365 * 100); 
	percent = PresentValue * multiplier - PresentValue;    //����� ��������� (�������)
	FutureValue = PresentValue * multiplier;  //������� ���������
	PresentValue = FutureValue;
}
void Filling(vector <string> &percentage, vector <string> &deposit, vector <string> &date, String^ year, int index, double percent, double PresentValue, int &row) {  //���������� �������� ��� ������
	string percent1 = msclr::interop::marshal_as<std::string>(String::Format("{0:0.00}", percent));
	string PresentValue1 = msclr::interop::marshal_as<std::string>(String::Format("{0:0.00}", PresentValue));
	percentage.push_back(percent1); //������ ���������
	deposit.push_back(PresentValue1); //������  �������� ������
	String^ name; 
	NameOfMonth(index,name);
	string name1 =  msclr::interop::marshal_as<std::string>("01 " + name + " " + year);  
	date.push_back(name1); //������ ���
	row++;
}
void CalculateInterest(int point, double &PresentValue, double &Rate, int &amount_of_days, double &percent, double &FutureValue, int &row, int &index, String^ &year, vector<string> &date, vector<string> &percentage, vector<string> &deposit) //���������� ��������
{
	if (point == 0) 
		SimpleInterest(PresentValue, Rate, amount_of_days, percent);  //���������� �������� ��������
	else 
		CompoundInterest(PresentValue, Rate, amount_of_days, percent, FutureValue); //���������� �������� ��������

	Filling(percentage, deposit, date, year, index, percent, PresentValue, row);
}
		
#endif
