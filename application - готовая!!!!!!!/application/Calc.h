//прописаны все объ€влени€ процедур, которые необходимы дл€ расчета процента

void NumberDays(int index, int &days_in_month); //определение кол-ва дней в мес€це	
void AmountOfDays(int index, int &days_in_month, int &amount_of_days);  //вычисление количества дней в периоде
void NameOfMonth(int number_of_month, String^ &name); //определение мес€ца
void FinishYear(int &number_of_month, String^ &year);  
void SimpleInterest(double PresentValue, double Rate, int amount_of_days, double &percent);  //вычисление простого процента
void CompoundInterest(double &PresentValue, double Rate, int amount_of_days, double &percent, double &FutureValue);  //вычисление процента с капитализацией (сложного процента)
void Filling(vector <string> &percentage, vector <string> &deposit, vector <string> &date, String^ year, int index, double percent, double PresentValue, int &row);  //заполнение массивов дл€ вывода
void CalculateInterest(int point, double &PresentValue, double &Rate, int &amount_of_days, double &percent, double &FutureValue, int &row, int &index, String^ &year, vector<string> &date, vector<string> &percentage, vector<string> &deposit); //вычисление процента

