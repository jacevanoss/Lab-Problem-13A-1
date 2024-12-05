#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

void pressEnterToConinue(void);

int main() {

	string fileName;
	cout << "Enter filename: ";
	cin >> fileName;
	ifstream file(fileName);
	if (!file) {
		cout << "Error opening the file" << endl;
		return 1;
	}
	int letterCount[26] = { 0 };
	int totalLetters = 0;
	char letter;
	while (file.get(letter)) {
		if (isalpha(letter)) {
			letter = tolower(letter);
			letterCount[letter - 'a']++;
			totalLetters++;
		}
	}
	cout << "Total number of letters: " << totalLetters << endl;
	cout << "Frequency: " << endl;
	for (int i = 0; i < 26; i++) {
		double frequency = (double)letterCount[i] / totalLetters * 100;
		cout << "'" << (char)('A' + i) << "': " << fixed << setprecision(3) << frequency << endl;
	}
	pressEnterToConinue();

	return 0;
}
// used to keep the console window open long enough to see your programs output
void pressEnterToConinue(void) {
	char c;
	cout << "Press Enter to continue...";
	cin.ignore(1024, '\n');
	do { cin.get(c); } while (c != '\n' && c != EOF);
	return;
}