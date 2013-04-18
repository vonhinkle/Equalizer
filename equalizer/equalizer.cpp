#include "equalizer.h"
#include <iostream>
#include <fstream>

using namespace std;

void clear_screen();

int main()
{
	equalizer x;
	int select, gain;

	x.build_eq_array();

	do
	{
		x.display_eq();
		cout << "1. Preamp    2. 70 Hz   3. 180 Hz   4. 320 Hz" << endl;
		cout << "5. 600 Hz    6. 1 KHz   7. 3 KHz    8.  8 KHz" << endl;
		cout << "9. 12 KHz   10. 14 Khz  11. 16 KHz  0. Exit" << endl;

		cout << "Enter the number of the frequency you'd like to change: ";
		cin >> select;

		if(select != 0)
		{
			cout << "Enter the gain value (-6 dB to 6 dB): ";
			cin >> gain;
			x.set_db((select-1),gain);
			x.build_eq_array();
			
		}
		clear_screen();
	}while (select!=0);

	x.file_output();

	cin.get();

	return 0;
}

void clear_screen()
{
	for(int i=0; i<5; i++)
		cout << "\n\n\n\n\n\n\n\n";
}

void output(equalizer y)
{

}
