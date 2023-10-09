#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double readBalance(string fileName);
void displayBalance(double balance);
void setNewBalance(double* balance);
void writeNewBalance(double balance, string fileName);

int main()
{
    double balance;
    string fileName;
    cout << "What is the file name? (ex: file.txt) " << endl;
    cin  >> fileName;
    balance = readBalance(fileName);
    displayBalance(balance);
    setNewBalance(&balance);
    displayBalance(balance);
    writeNewBalance(balance, fileName);
    balance = readBalance(fileName);
    displayBalance(balance);

    return 0;
}

double readBalance(string fileName)
{
    // First, declare a file stream object.
    std::ifstream fin;
    // Declare line
    std::string line;
    // Declare balance.
    double balance;
    // Open the file.
    fin.open(fileName);
    // Check if file exists.

    // If the file data.txt exists, then put the balance on the screen by calling a function you wrote called displayBalance(). 
    // On the other hand, if you cannot read the number from the file, 
    // then set the balance to 0.00 and display the message Unable to open data.txt.
    if (fin.fail())
    {
        balance = 0.00;
        cout << "Unable to open " << fileName;
    }
    else
    {
        // Read data.
        getline(fin, line);
        // Convert string to double.
        balance = stod(line);

    }
    // Close the output stream.
    fin.close();
    return balance;
}

void displayBalance(double balance)
{
    cout << "Account Balance is $" << balance << endl;

}

void setNewBalance(double* balance)
{
    string line;
    cout << "What is the new balance? " << endl;
    cin >> line;
    *balance = stod(line);
}

void writeNewBalance(double balance, string fileName)
{
    // If you were able to write the updated balance to the file, then display the message Balance successfully written to data.txt. 
    // Otherwise, display the message Unable to write balance to data.txt.
    
    // First, declare a file stream object.
    std::ofstream fout;

    // Next, open the file.
    fout.open(fileName);

    // Try to write to the file
    if (fout.fail())
    {
        cout << "Unable to write balance to " << fileName << endl;
    }
    else
    {
        fout << balance;
        cout << "Balance successfully written to " << fileName << endl;

    }
    fout.close();
}