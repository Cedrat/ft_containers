
struct funny_comp
{
    bool operator() (int first, int second) const 
    {
        int sum1;
        int sum2;

        while (first)
        {
            sum1 += first%10;
        }

        while (second)
        {
            sum2 += second%10;
        }


        return (sum1 < sum2);
    }
};