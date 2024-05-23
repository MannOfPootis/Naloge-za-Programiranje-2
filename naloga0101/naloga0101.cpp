#include <iostream>
#include <ctime>

using namespace std;

void menu() {
    cout << "============================" << endl;
    cout << "=========== MENU ===========" << endl;
    cout << "============================" << endl;
    cout << "1 ... GENERATE EXPENSES" << endl;
    cout << "2 ... PRINT EXPENSES" << endl;
    cout << "3 ... PRINT ROUNDED" << endl;
    cout << "4 ... PRINT AVERAGE" << endl;
    cout << "5 ... PRINT MINIMAL" << endl;
    cout << "6 ... PRINT NUMBER OF ALL THAT ARE ABOVE 100" << endl;
    cout << "7 ... PRINT NUMBER OF ALL THAT ARE ABOVE AND BELOW AVERAGE " << endl;


    cout << "0 ... EXIT1" << endl;
    cout << "============================" << endl;
    cout << "Select: ";
}

void fillArray(float *array, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        array[i] = 0.5f + i;
    }
}

void printArray(const float *array, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
}

void randomizeArray(float *array, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        array[i] = 0.5f + (float) (rand() % 14950) / 100;
    }
}

void printRoundedArray(const float *array, const unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        int cut = (int) array[i];
        if (array[i] - cut > 0.5)cut++;
        cout << cut << endl;
    }
}

double avg(const float *array, const unsigned int size) {
    float sum = 0;
    for (unsigned int i = 0; i < size; i++) {
        sum += array[i];

    }
    return sum / size;
}

double min(const float *array, const unsigned int size) {
    float min = array[0];
    for (unsigned int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

float countAbove(float bar, const float *array, const unsigned int size) {
    float sum = 0;
    for (unsigned int i = 0; i < size; i++) {
        if (array[i] > bar) {
            sum++;
        }
    }
    return sum;
}

float countBellow(float bar, const float *array, const unsigned int size) {
    float sum = 0;
    for (unsigned int i = 0; i < size; i++) {
        if (array[i] < bar) {
            sum++;
        }
    }
    return sum;
}


int main() {
    const unsigned int numOfExpenses = 20;
    float *expenses = new float[numOfExpenses];

    srand(time(nullptr));

    bool running = true;
    int selection;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            /* case 1:
                 randomizeArray(expenses, numOfExpenses);
                 break;*/
            case 1:
                randomizeArray(expenses, numOfExpenses);
                break;
            case 2:
                printArray(expenses, numOfExpenses);
                break;
            case 3:
                printRoundedArray(expenses, numOfExpenses);
                break;
            case 4:
                cout << avg(expenses, numOfExpenses) << endl;
                break;
            case 5:
                cout << min(expenses, numOfExpenses) << endl;
                break;
            case 6:
                cout << countAbove(100, expenses, numOfExpenses) << endl;
                break;
            case 7:
                cout << "nad povprečjem jih je: " << countAbove(avg(expenses, numOfExpenses), expenses, numOfExpenses)
                     << endl;
                cout << "pod povprečjem jih je: " << countBellow(avg(expenses, numOfExpenses), expenses, numOfExpenses)
                     << endl;
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Wrong selection!" << endl;
                break;
        }
        cout << endl;
    } while (running);

    delete[] expenses;

    return 0;
}