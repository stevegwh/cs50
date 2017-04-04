bool sorted = false;
while(!sorted)
{
    int i = -1;
    int swapped = 0;
    while(i < (n-1))
    {
        i++;
        if(i != (n-1))
        {
            if(values[i] > values[i + 1])
            {
                int placeholder = values[i+1];
                values[i + 1] = values[i];
                values[i] = placeholder;
                i++;
                swapped++;
            }
        }
        else if(swapped == 0 && i == n - 1)
        {
            sorted = true;
        }
        else
        {
            break;
        }

    }
}
