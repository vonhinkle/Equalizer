#pragma once
#include <iostream>
#include <fstream>


using namespace std;

class equalizer
{
public:
	char equal[13][11];
	int	e[11];
	int freq[10];
	void build_eq_array(void);
	void set_db(int x, int y);
	void display_eq(void);
	void file_output(void);
	equalizer();
	~equalizer();
};

//membfer function definitions
equalizer::equalizer(void)
{
	freq[0]=70;
	freq[1]=180;
	freq[2]=320;
	freq[3]=600;
	freq[4]=1000;
	freq[5]=3000;
	freq[6]=6000;
	freq[7]=12000;
	freq[8]=14000;
	freq[9]=16000;
	for(int i=0; i <= 10; i++)
		e[i] = 0;
}

equalizer::~equalizer(void)
{

}

void equalizer::build_eq_array(void)
{
	for(int i=0;i<=12;i++)
	{
		for(int j=0; j<=10; j++)
		{
			if(e[j]==(i-6))
				equal[i][j]='=';
			else
				equal[i][j]=' ';
		}
	}
}

void equalizer::set_db(int x, int y)
{
	e[x] = y;
}

void equalizer::display_eq(void)
{
	int j,k=6;

	cout << "**************************************************************" << endl;
	cout << "**************************************************************" << endl;
	cout << "**************************************************************" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "   Pre  700  180  320  600   1k   3k   6k  12k  14k  16k  Hz" << endl;

	for (int i = 12; i >= 0; i--)
	{
		for(j = 0;j <= 10; j++)
		{
			cout << "    " << equal[i][j];
		}
		if(k>=0)
			cout << "    " << k << " dB" << endl;
		else
			cout << "   " << k << " dB" << endl;
		k--;

	}

	cout << "   Pre  700  180  320  600   1k   3k   6k  12k  14k  16k  Hz" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "**************************************************************" << endl;
	cout << "**************************************************************" << endl;
	cout << "**************************************************************" << endl;

}

void equalizer::file_output(void)
{
	ofstream a_file("config.txt");

	a_file << "Filter Settings File \n\n";
	a_file << "Preamp: " << e[0] << " db\n\n";
	for(int i=1;i<=10;i++)
	{
		a_file << "Filter " << i << ": ON PK     Fc     " << freq[i-1] <<" Hz    Gain  " << e[i] << " db Q 2.0\n";
	}
	a_file.close();


}