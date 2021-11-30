#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

struct funny_comp
{
    bool operator() (int first, int second) const 
    {
        int sum1 = 1;
        int sum2 = 1;

        while (first)
        {
            sum1 *= first%10;
            first /=10;
        }

        while (second)
        {
            sum2 *= second%10;
            second /=10;
        }
        std::cerr << sum1 << "|" << sum2 << std::endl;
        return (sum1 < sum2);
    }
};

#endif