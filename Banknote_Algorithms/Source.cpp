#include<iostream>
#include<locale.h>
using namespace std;

void ekranTemizle() {
	system("cls");
}

int toplamiktar(int parasay�s�[], int banknot[]) {
	int toplam = 0;
	//Toplam miktar� s�rayla paralar�n ttugumuz miktarlar�
	//ve banknot de�erleriyle �arparak hesapl�yoruz
	for (int i = 0; i < 6; i++) {
		toplam += parasay�s�[i] * banknot[i];
	}
	return toplam;
}
//En az say�da banknot kullanarak yap�lan i�lem
void enazbanknot(int girilenparasay�s�[], int banknot[], int miktar)
{
	int temp;
	int parasay�s�[6] = { 0,0,0,0,0,0 };
	//E�er girilen say� eldeki toplam paradan b�y�kse hata mesaj�
	if (toplamiktar(girilenparasay�s�, banknot) < miktar || miktar < 0)
	{
		cout << "The amount of money entered is too much or a negative amount!!" << endl;
	}

	temp = miktar;
	//Girilen paradan bir y�kse�ini bulmak i�in
	//5 e b�l�nebilsin diye ekleme yap�yoruz
	if (miktar % 5 != 0)
		miktar -= (miktar % 5) - 5;

	for (int i = 5; i >= 0; i--) {
		if (girilenparasay�s�[i] == 0)
			miktar += banknot[i];
		else
			break;
	}
	//S�rayla b�y�kten k����e do�ru 
	//banknotlar� veriyoruz ve verdi�imiz banknot de�erini miktardan d���yoruz
	for (int i = 0; i < 6;) {
		if (miktar >= banknot[i] && girilenparasay�s�[i] > parasay�s�[i]) {
			parasay�s�[i]++;
			miktar -= banknot[i];
		}
		else
			i++;
	}
	//Tam olarak t�m paray� hala verememi�se
	//elinde kalan en k���k paray� ekliyoruz
	if (miktar > 0) {
		for (int i = 0; i < 6; i++)
			parasay�s�[i] = 0;
		for (int i = 5; i >= 0; i--)
			if (banknot[i] > temp) {
				parasay�s�[i]++;
				break;
			}
	}
	//Fonksiyonu ekrana yazd�rma
	cout << girilenparasay�s�[0] << " banknote 200$," << " " << girilenparasay�s�[1] << " banknote 100$," << " " << girilenparasay�s�[2] << " banknote 50$, " << " " << girilenparasay�s�[3] << " banknote 20$, " << " " << girilenparasay�s�[4] << " banknote 10$, " << " " << girilenparasay�s�[5] << " banknote 5$, " << endl;
	cout << "Target\t:" << temp << endl;
	cout << "Result\t:" << parasay�s�[0] << " banknote 200$" << " " << parasay�s�[1] << " banknote 100$" << " " << parasay�s�[2] << " banknote 50$" << " " << parasay�s�[3] << " banknote 20$" << " " << parasay�s�[4] << " banknote 10$" << " " << parasay�s�[5] << " banknote 5$" << " " << endl;
}
//�nce en y�ksek banknotlar� veren fonskiyon
void yuksekparakullan(int girilenparasay�s�[], int banknot[], int miktar)
{
	int temp;
	int parasay�s�[6] = { 0,0,0,0,0,0 };
	//Girilen toplam miktar eldeki paradan b�y�kse uyar� 
	if (toplamiktar(girilenparasay�s�, banknot) < miktar || miktar < 0)
	{
		cout << "The amount of money entered is too much or a negative amount!!" << endl;
	}
	temp = miktar;
	//�nce en y�ksek banknotu elimizde kalmayana kadar verip
	//toplam miktara ula�ma
	for (int i = 0; i < 6;) {
		if (miktar > 0 && girilenparasay�s�[i] > parasay�s�[i]) {
			miktar -= banknot[i];
			parasay�s�[i]++;
		}
		else
			i++;
	}
	//Fonsiyonu ekrana yazd�rma
	cout << girilenparasay�s�[0] << " banknote 200$," << " " << girilenparasay�s�[1] << " banknote 100$," << " " << girilenparasay�s�[2] << " banknote 50$, " << " " << girilenparasay�s�[3] << " banknote 20$, " << " " << girilenparasay�s�[4] << " banknote 10$, " << " " << girilenparasay�s�[5] << " banknote 5$, " << endl;
	cout << "Target\t:" << temp << endl;
	cout << "Result\t:" << parasay�s�[0] << " banknote 200$" << " " << parasay�s�[1] << " banknote 100$" << " " << parasay�s�[2] << " banknote 50$" << " " << parasay�s�[3] << " banknote 20$" << " " << parasay�s�[4] << " banknote 10$" << " " << parasay�s�[5] << " banknote 5$" << " " << endl;
}
//En fazla banknotu veren fonksiyon
void encokbanknot(int girilenparasay�s�[], int banknot[], int miktar)
{
	int temp;
	int parasay�s�[6];
	//Girilen toplam miktar eldeki paradan b�y�kse uyar� 
	if (toplamiktar(girilenparasay�s�, banknot) < miktar || miktar < 0)
	{
		cout << "The amount of money entered is too much or a negative amount!!" << endl;
	}
	temp = miktar;
	//Paray� 5 e tam b�l�nebilir hale getirme
	if (miktar % 5 != 0)
		miktar -= (miktar % 5) + 5;
	//Eldeki banknot say�lar�n� bir diziye atama
	for (int i = 0; i < 6; i++)
		parasay�s�[i] = girilenparasay�s�[i];
	//�ncelikle k���k banknot verecek �ekilde en fazla
	//en fazla banknotu vererek istenen miktara ula�ma
	for (int i = 0; i < 6;) {
		if (toplamiktar(parasay�s�, banknot) - banknot[i] >= miktar && parasay�s�[i] > 0) {
			parasay�s�[i]--;
		}
		else
			i++;
	}
	//fonksiyonu ekrana yazd�rma
	cout << girilenparasay�s�[0] << " banknote 200$," << " " << girilenparasay�s�[1] << " banknote 100$," << " " << girilenparasay�s�[2] << " banknote 50$, " << " " << girilenparasay�s�[3] << " banknote 20$, " << " " << girilenparasay�s�[4] << " banknote 10$, " << " " << girilenparasay�s�[5] << " banknote 5$, " << endl;
	cout << "Target\t:" << temp << endl;
	cout << "Result\t:" << parasay�s�[0] << " banknote 200$" << " " << parasay�s�[1] << " banknote 100$" << " " << parasay�s�[2] << " banknote 50$" << " " << parasay�s�[3] << " banknote 20$" << " " << parasay�s�[4] << " banknote 10$" << " " << parasay�s�[5] << " banknote 5$" << " " << endl;
}
int main()
{
	int miktar;
	int secim;
	setlocale(LC_ALL, "Turkish");
	int banknot[] = { 200,100,50,20,10,5 };
	int parasay�s�[6] = { 0,0,0,0,0,0 };
	//Banknot de�erlerini ve ka� tane bulundu�unu tutan iki dizi olu�turuyoruz
	//Kullan�c�dan s�rayla ka� adet banknot de�erleri olmas�n� istiyoruz 
	//Kullan�c�dan ula�mak istenen miktar� istiyoruz
	cout << "How many get $200 banknotes : ";
	cin >> parasay�s�[0];
	cout << endl;
	cout << "How many get $100 banknotes : ";
	cin >> parasay�s�[1];
	cout << endl;
	cout << "How many get $50 banknotes : ";
	cin >> parasay�s�[2];
	cout << endl;
	cout << "How many get $20 banknotes : ";
	cin >> parasay�s�[3];
	cout << endl;
	cout << "How many get $10 banknotes : ";
	cin >> parasay�s�[4];
	cout << endl;
	cout << "How many get $5 banknotes: ";
	cin >> parasay�s�[5];
	cout << endl;
	cout << "Enter the total amount you've targeted. ";
	cin >> miktar;
	cout << endl;
	//Do-while ile bir men� olu�turuyoruz
	do
	{
		cout << "\n\n\n\t******** MEN� *******\n\n";
		cout << "\n\t1 - Minimum Number of Banknotes \n";
		cout << "\t2 - Using High Banknotes \n";
		cout << "\t3 - Maximum Number of Banknotes \n";
		cout << "\t0 - ��k�� \n";
		cout << "\t\n\n\nPlease choose the function:\n";
		cin >> secim;
		    //Kullan�c�dan se�im de�i�keninin de�erini al�yoruz
		switch (secim) {
			//1. se�im i�in en az banknot hesaplama
		case 1:
			ekranTemizle();
			enazbanknot(parasay�s�, banknot, miktar);
			break;
			//2. se�im i�in y�ksek paralarla hesaplama
		case 2:
			ekranTemizle();
			yuksekparakullan(parasay�s�, banknot, miktar);
			break;
			//3. se�im i�in en �ok banknotu kullanarak hesaplama
		case 3:
			ekranTemizle();
			encokbanknot(parasay�s�, banknot, miktar);
			break;
		case 0:
			break;
			//Hatal� se�im i�in uyar�
		default:
			cout << "Wrong choice ";   //hatal� se�im i�in uyar� olu�turuyoruz
			break;
		}
	} while (secim != 0);
	system("pause");
	return 0;
}