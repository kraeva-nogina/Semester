//��������� ��� ���������� ��������, ������� ���������� ��� ������� ��������

void NumberDays(int index, int &days_in_month); //����������� ���-�� ���� � ������	
void AmountOfDays(int index, int &days_in_month, int &amount_of_days);  //���������� ���������� ���� � �������
void NameOfMonth(int number_of_month, String^ &name); //����������� ������
void FinishYear(int &number_of_month, String^ &year);  
void SimpleInterest(double PresentValue, double Rate, int amount_of_days, double &percent);  //���������� �������� ��������
void CompoundInterest(double &PresentValue, double Rate, int amount_of_days, double &percent, double &FutureValue);  //���������� �������� � �������������� (�������� ��������)
void Filling(vector <string> &percentage, vector <string> &deposit, vector <string> &date, String^ year, int index, double percent, double PresentValue, int &row);  //���������� �������� ��� ������
void CalculateInterest(int point, double &PresentValue, double &Rate, int &amount_of_days, double &percent, double &FutureValue, int &row, int &index, String^ &year, vector<string> &date, vector<string> &percentage, vector<string> &deposit); //���������� ��������

