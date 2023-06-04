#include <iostream>
#include <iomanip>

using namespace std;

// Create function that displays average of scores;
double getTestScoreaverage(double *,int);

// creat acceding sort function;
void getSorted(double *,int);

int main()
{
    int size;
    int i;
    double *score;  //To dynamically allocate an array of scores;
    double average = 0.0;   // to hold average score;
    
    cout << "How many test scores will you enter? " << endl;
    cin >> size;

        while (size < 1)
    {
        cout << "Entered number of tests must be more than 1: " << endl;
        cout << "\nHow many test scores will you enter?  ";
        cin >> size;
    }
    
    // Dynamically alloctae;
    score = new double[size];
    
    for(i = 0; i < size; i++)
    {
        cout <<" \n Enter the score for test "<< i + 1 << ": ";
        cin >> *(score + i);
        
                while (*(score + i) < 0)
        {
            cout << "Test score can not be negative, Please enter again: ";
            cin >> *(score + i);
        }
    }


    // Display the result;
    getSorted(score,size);
    average = getTestScoreaverage(score,size);
    
    cout << "\nTest score in ascending order: " << endl;
    cout << "-------------------------------" << endl;
    for(i = 0; i < size; i++)
    {
        cout << "Score: " << setw(10) << score[i] << endl;
    }
    
    cout <<"\nAverage score: "<< average << endl;
    // Free dynamically alloctated the memory;
    delete [] score;
    
    return 0;
}

double getTestScoreaverage(double * array,int size)
{
    double sum = 0;

    for(int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    
    // Calculate the average score;
    sum = sum/((double)size);
    
    return sum;
}

void getSorted(double *score,int size)
{
    double mainnum;  // Accumulator;
    int i = 0;       // counter;
    int j;
    int mainindex;   
    
    for(i = 0; i < size; i++)
    {
        mainindex = i;
        mainnum = score[i];
        
        for(j = i+1; j < size; j++)
        {
            if(score[j] < mainnum)
            {
                mainnum = score[j];
                mainindex = j;
            }
        }
        
        score[mainindex] = score[i];
        score[i] = mainnum;
    }
}
