#include <iostream>
#include <conio.h> // For _getch() function

using namespace std;

int main()
{
    int *nums[5];
    int count = 1;
    char key;
    bool exit = false;


    while (!exit)
    {
        key = _getch();

        // chek if key is a number
        if (key >= '0' && key <= '9')
        {
            count++;
            // convert key to int
            int num = key - '0';

            // store num in nums
            nums[num] = new int(num);
        }
        else if ((key == 27) || ( count >= 5)) // ASCII code for Esc key
        {
            exit = true;
        }
    }

    // Calculate total
    int total = 0;
    for (int i = 0; i < count; i++)
    {
        total += *nums[i];
    }
    cout << "Average: " << total / count << endl;
    return 0;
}