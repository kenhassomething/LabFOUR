/*
  Lab FOUR
  Kenneth Steffens

  This program asks the user to enter a positive integer. Before this input can
  be accepted, it must be at least 1 or higher. Then it lets the user know if
  this integer is a prime number. Finally, they are given the option to check if
  another number is positive.
*/

#include <iostream>
#include <string>

using namespace std;

int getInput();
bool isPrime(int posNum);

const int POS_INT_MIN = 1;

int main() {

  int uInt;
  char answer;

  do {

    // Prompt user for a positive integer
    uInt = getInput();

    // Check if number is a prime number and notifiy the user the result.
    cout << uInt << " is ";
    if (isPrime(uInt)) {
      cout << "a prime number.\n";
    } else if (!isPrime(uInt)) {
      cout << "not a prime number.\n";
    } else {
      cout << "unknown. Please try again.\n";
    }

    // Prompt user if they want to continue and wait for response.
    cout << "\n";
    do {
      cout << "Would you like to continue? (Y/N):\n>> ";
      cin >> answer;
      cin.get();

      if ((toupper(answer) != 'Y') && (toupper(answer) != 'N')) {
        cout << "\n(Answer must be yes (Y) or no (N)) ";
      }

    } while ((toupper(answer) != 'Y') && (toupper(answer) != 'N'));

    cout << "\n";

    // Keep going until the user says no.
  } while (toupper(answer) == 'Y');

  cout << "Have a good day!";

  return 0;
}

/* getInput
    Recieves an inputed postive integer from the user.
*/
int getInput() {

  int uPosInt;

  do {

    cout << "Enter a positive integer:\n>> ";
    cin >> uPosInt;

    if (uPosInt < POS_INT_MIN) {
      cout << "\n(Integer must be at least " << POS_INT_MIN << " or greater) ";
    }

  } while (uPosInt < POS_INT_MIN);

  return uPosInt;
}

/* isPrime
   Checks if a passed positive integer is a prime number. If the passed number
   is a prime number, then it returns true. Otherwise, it returns false. Note,
   this does not exactly mean that false means the number is compositie, as
   1 is neither of those.
*/
bool isPrime(int posNum) {

  const int NUM_FACTORS_PRIME = 2;
  int numFactors = 0;

  if (posNum == POS_INT_MIN) {
    return false;

  } else if (posNum % 2 == 0) { // Check if the number is even.

    return posNum == 2;
    // 2 is a prime number (true);
    // Any even number greater than 2 is not (false).

  } else if (posNum >= POS_INT_MIN) {

    // Count the number of factors that the passed number has.
    for (int count = posNum; count >= POS_INT_MIN; count--) {

      if (numFactors > NUM_FACTORS_PRIME) {
        return false;
      }

      if (posNum % count == 0) {
        numFactors++;
      }
    }

    return true;
  } else {
    cout << "Integer must be positive.";
  }
}