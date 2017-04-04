int minB = 0;
int maxB = n;

while(true)
{
    // init half every loop to ensure the half is being calculated!
    int half = (minB + maxB)/2;
    if(values[half] == value) //if we luckily got the number, then return true
    {
        return true;
        break;
    }
    else if(half == minB || half == maxB) //if the search is now down to two results
    {
        if(values[minB] == value)
        {
            return true;
            break;
        }
        else if(values[maxB] == value)
        {
            return true;
            break;
        }
        else
        {
            return false;
            break;
        }
    }
    else if(values[half] > value) //if the value is greater than the value at half then it must be in the "Left side", so reduce maxB to the left side
    {
        maxB = half - 1;
    }
    else if(values[half] < value) //likewise shift the search the right side of the array
    {
        minB = half + 1;
    }
}
