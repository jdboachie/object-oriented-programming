#include <iostream>

int largest_number(int *array, int size)
{
    int largest = array[0];
    for (int i = 0; i < size; i++)
    {
        if (array[i] > largest)
        {
            largest = array[i];
        }
    }
    return largest;
}

int main()
{
    int array[5] = {11, 2, 3, 4, 5};
    std::cout << largest_number(array, 5) << std::endl;
    return 0;
}
