#include <iostream>
#include <string.h>
// #include <stdio.h>

using namespace std;

int main()
{
	cout << "How many lines should output? 2-32768" << endl;

	uint16_t iLines;

	cin >> iLines;

	if(1 < iLines <= 32768)
	{
		uint16_t i;

		uint32_t j, l,
		         iMultiLines = ++iLines * 2,
		         iAlloc = (iMultiLines * (iLines - 1) / 4 * 3) - iLines + 2;		// Last character '\0'.

		// Сreating a buffer to build a string in it. Everytime calling the system to output is very slow.
		char *psOutput = new char[iAlloc];

		cout << "Memory alloc: " << iAlloc << " bytes" << endl;

		for(i = 1, l = 0; i < iLines; i++)
		{
			for(j = 1; j < iMultiLines;)
			{
				if(++j >= iLines + i)
				{
					break;
				}

				psOutput[l++] = (j > iLines - i) ? '*' : ' ';
			}

			psOutput[l++] = '\n';
		}

		psOutput[l] = '\0';

		cout << "Length: " << l << endl;

		cout << endl << psOutput << endl;

		delete[] psOutput;
	}

	system("pause");

	// On failure.
	return 0;
}
