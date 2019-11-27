#include <stdio.h>

#define DAYS_IN_MONTH 30
#define MONTHS_IN_YEAR 12
#define ONE_HUNDRED 100
#define ONE_THOSEND 10000
#define BOOLEAN unsigned short
#define TRUE 1
#define FALSE 0
#define SEVEN 7
#define EIGHT 8
#define TEN 10
#define TWELVE 12
#define THIRTY 30
#define ZERO 0
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define TAKE_SIGNED_MATH(x) (((2 * (x)) + 1) % 2)
#define TAKE_SIGNED(x) ((x) < 0) ? -1 : 1
#define ABS(x) (x) * (((2 * (x)) + 1) % 2)
#define MAX(x, y) (x > y) ? x : y
#define MIN(x, y) (x < y) ? x : y
#define BACKSLASH_ZERO '\0'
#define MAX_SIZE_STRING 256
#define MASK_FIRST_BIT 0x1

typedef char string[MAX_SIZE_STRING];
typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned int dblword;


//---------------------------------------------------------------------------------------
//                                              ChangeYearsToMonths
//                                              -------------------
//
// General      : Change years to months.
//
// Parameters   :  
//          years - number (short)
//
// Return value : years as month.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
void ChangeYearsToMonths(int *years, short *month)
{
    (*month) = (*years) * MONTHS_IN_YEAR;
}

void SwapNumbers(int *ptr_number1, int *ptr_number2)
{
    int temp_number = *ptr_number2;
    *ptr_number2 = *ptr_number1;
    *ptr_number1 = temp_number;
}

void SwapChars(char *ptr_char1, char *ptr_char2)
{
    char temp_char = *ptr_char2;
    *ptr_char2 = *ptr_char1;
    *ptr_char1 = temp_char;
}

//---------------------------------------------------------------------------------------
//                                              ChangeMonthsToDays
//                                              ------------------
//
// General      : change months to days.
//
// Parameters   :  
//          month - first number (short)
//
// Return value : month as days.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
void ChangeMonthsToDays(short *months, int *days)
{
    (*days) = (*months) * DAYS_IN_MONTH;
}

//---------------------------------------------------------------------------------------
//                                              ChangeDateToDays
//                                              ----------------
//
// General      : change date to days (from ddmmyyyy).
//
// Parameters   :  
//          date - first number (int)
//
// Return value : date as days.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
void ChangeDateToDays(int *date, int *days)
{
    int years;
    short months;

    years = *date % ONE_THOSEND;
    *date /= ONE_THOSEND;
    months = *date % ONE_HUNDRED;
    *date /= ONE_HUNDRED;
    *days = *date;
    ChangeYearsToMonths(&years, &months);
    ChangeMonthsToDays(&months, days);
}

//---------------------------------------------------------------------------------------
//                                              ChangeDaysToMonths
//                                              ------------------
//
// General      : Change days to months.
//
// Parameters   :  
//          days - first number (int)
//
// Return value : Days as months.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
void ChangeDaysToMonths(int *days, int *months)
{
    *months = *days / DAYS_IN_MONTH;
}

//---------------------------------------------------------------------------------------
//                                              ChangeMonthsToYears
//                                              -------------------
//
// General      : Change months to years.
//
// Parameters   :  
//          month - first number (int)
//
// Return value : months as years.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
void ChangeMonthsToYears(int *months, int *years)
{
    *years = *months / MONTHS_IN_YEAR;
}

//---------------------------------------------------------------------------------------
//                                              ChangeDaysToDate
//                                              ----------------
//
// General      : Change days to date (format: ddmmyyyy)
//
// Parameters   :  
//          days - first number (int)
//
// Return value : days as date by format ddmmyyyy
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
void ChangeDaysToDate(int *days, int *date)
{
    int months,
        years;
    ChangeDaysToMonths(days, &months),
    ChangeMonthsToYears(&months, &years);
    *date = (*days - (months * DAYS_IN_MONTH));
    *date *= ONE_HUNDRED;
    *date += (months - (years * MONTHS_IN_YEAR));
    *date *= ONE_THOSEND;
    *date += years; 
}

//---------------------------------------------------------------------------------------
//                                              DifferentDates
//                                              ---------------
//
// General      : Sub between two dates (ddmmyyyy).
//
// Parameters   :  
//          date1 - first date (int)
//          date2 - second date (int)
//
// Return value : the different between two dates.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
int DifferentDates(int *date1, int *date2, int *different)
{
    int days1, 
    days2,
    new_date;
    ChangeDateToDays(date1, &days1);
    ChangeDateToDays(date2, &days2);
    new_date = days1 - days2;
    ChangeDaysToDate(&new_date, different);
}

//---------------------------------------------------------------------------------------
//                                              EvenNumber
//                                              ----------
//
// General      : Check if the num is even
//
// Parameters   :  
//          num - first num (int)
//
// Return value : 0 - FALSE, 0 - TRUE.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
BOOLEAN EvenNumber(int num)
{
    return (!(num & MASK_FIRST_BIT));
}

//---------------------------------------------------------------------------------------
//                                              OppositeNumber
//                                              --------------
//
// General      : Change number order to Opposite. (123 -> 321)
//
// Parameters   :  
//          num - first number (int)
//
// Return value : Number order opposite
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
int OppositeNumber(int num)
{
    int temp_num = num,
        new_num = ZERO;
    for (; temp_num; temp_num /= TEN) 
    {
        new_num *= TEN;
        new_num += temp_num % TEN;
    }

    return (new_num);
}

//---------------------------------------------------------------------------------------
//                                              OddDigitsInNumber
//                                              -----------------
//
// General      : Take tne odd digits from number and component a 
//                new number
//
// Parameters   :  
//          num - first number (int)
//
// Return value : A number that consists of odd numbers.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
int OddDigitsInNumber(int num)
{
    int temp = num,
        new_num = ZERO;
    short digit = ZERO;

    for (; temp; temp /= TEN)
    {
        digit = temp % TEN;
        if (!EvenNumber(digit))
        {
            new_num *= TEN;
            new_num += digit;
        } 
    }

    return (new_num);
}

//---------------------------------------------------------------------------------------
//                                              EvenDigitsInNumber
//                                              ------------------
//
// General      : Take tne even digits from number and component a 
//                new number
//
// Parameters   :  
//          num - first number (int)
//
// Return value : A number that consists of even numbers.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
int EvenDigitsInNumber(int num)
{
    int temp = num,
        new_num = ZERO;
    short digit = ZERO;

    for (; temp; temp /= TEN)
    {
        digit = temp % TEN;
        if (EvenNumber(digit))
        {
            new_num *= TEN;
            new_num += digit;
        } 
    }

    return (new_num);
}

//---------------------------------------------------------------------------------------
//                  SumOfNumberWithPositiveDigitsAndNumberWithNegativeDigits
//                  --------------------------------------------------------
//
// General      : Sum Of Number With Positive Digits And Number With Negative Digits.
//
// Parameters   :  
//          num - first number (int)
//
// Return value : Sum Of Number With Positive Digits And Number With Negative Digits.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
int SumOfNumberWithPositiveDigitsAndNumberWithNegativeDigits(int num)
{
    int temp_num = OppositeNumber(num);
    int new_num = EvenDigitsInNumber(temp_num) +
                  OddDigitsInNumber(temp_num);

    return (num);
}

//---------------------------------------------------------------------------------------
//                                              Power
//                                              -----
//
// General      : Power on number.
//
// Parameters   :  
//          num - first number (float)
//          pow - first second (short)
//
// Return value : number powerd.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
double Power(float num, short pow)
{
    double new_num = ONE;
    short sign = ZERO;

    for (sign = (TAKE_SIGNED_MATH(pow) * -ONE); pow; pow += sign)
    {
        new_num *= num;
    }
    new_num = (sign == -ONE) ? (new_num) : ((float)ONE / new_num);
    return (new_num);
}

//---------------------------------------------------------------------------------------
//                                              GetRest
//                                              -------
//
// General      : Get the rest from double number.
//
// Parameters   :  
//          num          - first number (double)
//          count_digits - second number (unsigned short)
//
// Return value : The rest of a number like int.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
int GetRest(double num, unsigned short count_digits)
{
    int tens = Power((float)TEN, count_digits);
    return (int)(((int)(num * tens)) % tens);
}

//---------------------------------------------------------------------------------------
//                                              CountDigits
//                                              -----------
//
// General      : COunt digit in number.
//
// Parameters   :  
//          num - first number (int)
//
// Return value : Number of digits count in a number.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
unsigned short CountDigits(int num)
{
    unsigned short count;
    for (count = ZERO; num; num /= TEN, count++);
    
    return (count);
}

//---------------------------------------------------------------------------------------
//                                              ConvertBaseToDeciaml
//                                              --------------------
//
// General      : Convert a number from some base to base 10.
//
// Parameters   :  
//          num       - first number (float) 
//          base      - second number (float) 
//          rest_size - third number (unsigned short)
//
// Return value : A number that converted from some base to number from base 10.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 26.09.2019
//---------------------------------------------------------------------------------------
float ConvertBaseToDeciaml(float num, float base, unsigned short rest_size)
{
    int temp_num = num;
    float new_num = ZERO;
    int rest = GetRest(num, (rest_size % TEN));
    short pow;
    float new_rest = ZERO;
    float result = ZERO;
    for (pow = ZERO; temp_num; temp_num /= TEN)
    {
        new_num +=  ((temp_num % TEN) * Power(base, pow));
        pow++;
    }
    for (pow = (CountDigits(rest) * -ONE); rest; rest /= TEN)
    {
        new_rest += ((rest % TEN) * Power(base, pow));
        pow++;
    }
    
    return new_num + new_rest;
}

//---------------------------------------------------------------------------------------
//                                              Sum
//                                              ---
//
// General      : Sum of two numbers.
//
// Parameters   :  
//          number1 - first number (double) 
//          number2 - second number (double) 
//
// Return value : Sum of two numbers (double).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
double Sum(double number1, double number2)
{
    double result = number1 + number2;

    return (result);
}

//---------------------------------------------------------------------------------------
//                                              SumOfDigitsNumber
//                                              -----------------
//
// General      : Sum digits of number.
//
// Parameters   :  
//          number - first number (double) 
//
// Return value : Sum digits of number (int).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
int SumOfDigitsNumber(double number)
{
    int new_num = number * Power(TEN, 6);
    int sum = 0;
    for (; new_num; new_num /= TEN)
    {
        sum += new_num % TEN;
    }

    return (sum);
    
}

//---------------------------------------------------------------------------------------
//                                              SumEvenDigits
//                                              -------------
//
// General      : Sum even digits of number.
//
// Parameters   :  
//          number - first number (double) 
//
// Return value : Sum even digits of number (int).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
int SumEvenDigits(double number)
{
    int new_num = number * Power(TEN, 6);;

    return (SumOfDigitsNumber(EvenDigitsInNumber(new_num))); 
}

//---------------------------------------------------------------------------------------
//                                              SumOddDigits
//                                              ------------
//
// General      : Sum odd digits of number.
//
// Parameters   :  
//          number - first number (double) 
//
// Return value : Sum odd digits of number (int).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
int SumOddDigits(double number)
{
    int new_num = number * Power(TEN, 6);;

    return (SumOfDigitsNumber(OddDigitsInNumber(new_num))); 
}

//---------------------------------------------------------------------------------------
//                                              CommonDigitsInTwoNumbers
//                                              ------------------------
//
// General      : Check if have common digits in two numbers.
//
// Parameters   :  
//          number1 - first number (double) 
//          number2 - second number (double) 
//
// Return value : If have common digits in two numbers (BOOLEAN).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN CommonDigitsInTwoNumbers(double number1, double number2)
{
    int new_number1 = number1 * Power(10, 6);
    int new_number2 = number2 * Power(10, 6);
    short num1_digit;
    BOOLEAN answer = FALSE;

    for (num1_digit = new_number1 % TEN; new_number1 && !answer; new_number2 /= TEN)
    {
        if (new_number2)
        {
            new_number1 /= TEN;
            num1_digit = new_number1 % TEN;
            new_number2 = number2;
        }
        answer = (num1_digit == new_number2 % TEN) ? TRUE : FALSE;
    }

    return(answer);
}

//---------------------------------------------------------------------------------------
//                                              Sqrt
//                                              ----
//
// General      : Math sqrt 
//
// Parameters   :  
//          number - number (double) 
//          root   - root of sqrt, second number (short) 
//
// Return value : Math sqrt on number (double).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
double Sqrt(double number, short root)
{
    double max = number,
        min = ZERO,
        temp_min,
        difference = ONE,
        power_min;
    while(number != Power(min, root))
    {
        difference = (max - min) / TWO;

        temp_min = min + difference;

        power_min = Power(temp_min, root);
        number = ((float)temp_min == (float)min) ? power_min: number;

        min = (power_min <= number) ? temp_min : min;
        max = (power_min > number) ? temp_min : max;
    }

    return min;
}

//---------------------------------------------------------------------------------------
//                                              PrimeNumber
//                                              -----------
//
// General      : Check if number is a prime number.
//
// Parameters   :  
//          number - first number (int)
//
// Return value : If the number is a prime (BOOLEAN).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN PrimeNumber(int number)
{
    BOOLEAN answer = TRUE;
    short counter,
        max = Sqrt(number, TWO) + ONE;
    for (counter = TWO; counter < max; counter++)
    {
        answer *= (number % counter != ZERO);
    }

    return (answer);
}

double Module(double number, double div) // TODO : FIX IT
{
    unsigned int count;
    double temp_number = number;
    for (count = ZERO; temp_number > div; temp_number -= div)
    {
        count++;
    }

    return (temp_number);
}

//---------------------------------------------------------------------------------------
//                                              DigitInNumber
//                                              -------------
//
// General      : Check if digit in the number.
//
// Parameters   :  
//          number - first number (double)
//          digit - second number (unsigned short)
//
// Return value : If the the digit exists in the number (BOOLEAN).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN DigitInNumber(double number, unsigned short digit)
{
    int new_num = (number * 6) + GetRest(number, 6);
    BOOLEAN answer = FALSE;
    for (; new_num && !answer; new_num /= TEN)
    {
        answer = (new_num % 10 == digit);
    }

    return (answer);
    
}

//---------------------------------------------------------------------------------------
//                                              ConcatenationNumbers
//                                              --------------------
//
// General      : Concatenation two numbers to one number.
//
// Parameters   :  
//          number1 - first number (short)
//          number2 - second number (short)
//
// Return value : Number with two number (int).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
int ConcatenationNumbers(short number1, short number2)
{
    int new_number = number1;
    new_number *= Power(TEN, CountDigits(number2));
    new_number += number2;

    return (new_number);
}

int Multiplication(short number1, short multiply) // TODO : FIX IT
{
    int new_number = ZERO;
    for (; multiply > ZERO; multiply--)
    {
        new_number += number1;
    }

    return (new_number);
}

//---------------------------------------------------------------------------------------
//                                              GetDenominator
//                                              ---------------
//
// General      : Calculates the denominator of a number with a decimal point.
//
// Parameters   :  
//          number - first number (double)
//
// Return value : Denominator (int).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
int GetDenominator(double number)
{
    int denominator;
    double temp_number = number;
    for (denominator = ONE ; (float)((short)temp_number != (float)temp_number);
         temp_number += number)
    {
        denominator++;
    }

    return (denominator);
}

//---------------------------------------------------------------------------------------
//                                              GetCounter
//                                              ----------
//
// General      : Calculates the numerator of a number with a decimal point.
//
// Parameters   :  
//          number - first number (double)
//
// Return value : Counter (int).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
short GetCounter(double number)
{
    double temp_number = number;
    while ((float)((short)temp_number) != (float)temp_number)
    {
        temp_number += number;
    }

    return (temp_number);
} 

double Divide(double number, double div) // TODO : FIX IT
{
    double count_high,
        temp_number = number;
    for (count_high = ZERO; temp_number >= div; temp_number -= div)
    {
        count_high++;
    }
    return (count_high);
}

//---------------------------------------------------------------------------------------
//                                              SumInArray
//                                              ----------
//
// General      : Checks if there are two numbers whose sum is equal to 
//                the number entered as "sum".
//
// Parameters   :  
//          array[] - array (int)
//          size    - array size (unsigned int)
//          sum     - The amount required (int)
//
// Return value : Counter (int).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN SumInArray(int array[], unsigned int size, int sum)
{
    BOOLEAN answer = FALSE;
    unsigned int temp_size = size,
                    count;
    double temp_sum;

    for (count = ZERO; count < temp_size && !answer;)
    {
        temp_sum = array[count] + array[temp_size];
        answer = (temp_sum == sum) ? TRUE : FALSE;
        count += (temp_sum < sum) ? ONE : ZERO;
        temp_size -= (temp_sum > sum) ? ONE : ZERO;
    }
    
    return (answer);
}

//---------------------------------------------------------------------------------------
//                                              ChangeBool
//                                              ----------
//
// General      : Boolean variable inverse.
//
// Parameters   :  
//          bool1 -  Boolean variable (BOOLEAN)
//
// Return value : Boolean variable (BOOLEAN).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN ChangeBool(BOOLEAN bool1)
{
    BOOLEAN answer = ++bool1 % TWO;
    return answer;
}

//---------------------------------------------------------------------------------------
//                                              Equality
//                                              --------
//
// General      : Checks whether two numbers are equal in value.
//
// Parameters   :  
//          number1 -  first number (int)
//          number2 -  second number (int)
//
// Return value : If there is an equality between the two numbers (BOOLEAN).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN Equality(int number1, int number2)
{
    int sub = number1 - number2;
    BOOLEAN answer = (ONE / (ABS(sub) + ONE));
    return answer;
}

//---------------------------------------------------------------------------------------
//                                              NumBBiggerThenNumA
//                                              ------------------
//
// General      : Checks if the second number (B) is greater than the first number (A).
//
// Parameters   :  
//          number1 -  first number (int)
//          number2 -  second number (int)
//
// Return value : If the second number (B) is greater than the first number (A) (BOOLEAN).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN NumBBiggerThenNumA(int a, int b)
{
    int sub = a - b + ONE;
    BOOLEAN answer = (ONE / (ABS(sub) + (sub) + ONE));
    return answer;
}

//---------------------------------------------------------------------------------------
//                                SumOfTimesCharsArray1InCharsArray2
//                                ----------------------------------
//
// General      : Checks the number of times the first array values are in the 
//                second array in the appropriate order.
//
// Parameters   :  
//          array1[]    -  first array (char[])
//          array1_size -  size of array1 (unsigned int)
//          array2[]    -  second array (char[])
//          array2_size -  size of array2 (unsigned int)
//
// Return value : The number of times the first array is in the 
//                second array (unsigned int).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
unsigned int SumOfTimesCharsArray1InCharsArray2(char array1[],
                                                unsigned int array1_size,
                                                char array2[],
                                                unsigned int array2_size)
{
    unsigned int count = ZERO,
                is_in = TRUE,
                count_loop_array1,
                count_loop_array2;
        
    for (count_loop_array2 = ZERO; count_loop_array2 < array2_size; count_loop_array2++)
    {
        for (count_loop_array1 = ZERO;
             count_loop_array1 < array1_size && is_in; count_loop_array1++)
        {
            is_in *= Equality(array1[count_loop_array1],
                              array2[count_loop_array2 + count_loop_array1]);
        }
        count += is_in;
    }

    return (count);
}

//---------------------------------------------------------------------------------------
//                                CreateMask
//                                ----------
//
// General      : Creates a number with identical digits.
//
// Parameters   :  
//          size          -  digits count of number (unsigned short)
//          digit_of_mask -  type of digits (unsigned short)
//
// Return value : A number that all the digits are the same (unsigned int)
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
unsigned int CreateMask(unsigned short size, unsigned short digit_of_mask)
{
    unsigned int mask = digit_of_mask;
    unsigned short counter;
    for (counter = ONE; counter < size; counter++)
    {
        mask *= TEN;
        mask += digit_of_mask;
    }
    
    return mask;
}

//---------------------------------------------------------------------------------------
//                                CountADigitInNumber
//                                -------------------
//
// General      : Count the number of times her story appears in number.
//
// Parameters   :  
//          number - a number (int)
//          digit  - a digit (unsigned short)
//
// Return value : The number of times the number appears in the number (unsigned short)
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
unsigned short CountADigitInNumber(int number, unsigned short digit)
{
    int temp_num = number;
    unsigned count = FALSE;
    for (; temp_num; temp_num /= TEN)
    {
        count += Equality(temp_num % TEN, digit);
    }

    return (count);
    
}

//---------------------------------------------------------------------------------------
//                                GetDigit
//                                --------
//
// General      : Takes the digit from the required location.
//
// Parameters   :  
//          number   - a number (int)
//          location - index of digit (unsigned short)
//
// Return value : The number that is in the number where you want it (short)
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
short GetDigit(int number, unsigned short location)
{
    int temp_num = number;
    unsigned short digit;
    for (; location; location--)
    {
        temp_num /= TEN;
    }
    digit = temp_num % TEN;

    return (digit);
}

//---------------------------------------------------------------------------------------
//                                CountOfIdenticalDigitsInSomeIndex
//                                ---------------------------------
//
// General      : Count the number of times there are identical digits between 
//                two numbers and in the same location.
//
// Parameters   :  
//          number1 - first number (int)
//          number2 - second number (int)
//
// Return value : The number of times there are identical 
//                digits between two numbers and in the same location (unsigned short)
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
unsigned short CountOfIdenticalDigitsInSomeIndex(int number1, int number2)
{
    int temp_num1,
        temp_num2;
    unsigned short count = ZERO;
    for (temp_num1 = MIN(number1, number2), temp_num2 = MAX(number1, number2);
            temp_num1;
            temp_num1 /= TEN, temp_num2 /= TEN)
    {
        count += Equality(temp_num1 % TEN, temp_num2 % TEN);
    }

    return (count);
}

//---------------------------------------------------------------------------------------
//                                CountOfIdenticalDigits
//                                ----------------------
//
// General      : Count the number of times there are identical digits
//                between two numbers.
//
// Parameters   :  
//          number1 - first number (int)
//          number2 - second number (int)
//
// Return value : The number of times there are identical digits
//                between two numbers (unsigned short)
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
unsigned short CountOfIdenticalDigits(int number1, int number2)
{
    int temp_num1,
        temp_num2;
    unsigned short count = ZERO,
                    digit_num1;
    for (temp_num1 = number1; temp_num1; temp_num1 /= TEN)
    {   
        digit_num1 = temp_num1 % TEN;
        for (temp_num2 = number2; temp_num2; temp_num2 /= TEN)
        {
            count += Equality(digit_num1, temp_num2 % TEN);
        }
        temp_num2 = number2;
    }

    return (count);
}

//---------------------------------------------------------------------------------------
//                                ForeignDigits
//                                -------------
//
// General      : Checks whether all digits are foreign to each other by number.
//
// Parameters   :  
//          number - first number (int)
//
// Return value : If all the numbers are foreign to each other in number (BOOLEAN)
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 21.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN ForeignDigits(int number)
{
    int temp_num = number;
    BOOLEAN answer = TRUE;
    for (; temp_num; temp_num /= TEN)
    {
        answer *= NumBBiggerThenNumA(CountADigitInNumber(temp_num, temp_num % TEN), TWO);
    }
    
    return (answer);
}

//---------------------------------------------------------------------------------------
//                                        CharInString
//                                        ------------
//
// General      :CHecks if the char exist in string.
//
// Parameters   :  
//          text - string (char[])
//          c    - char (char)
//
// Return value : If the char exist in string (BOOLEAN).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN CharInString(char text[], char c)
{
    BOOLEAN exist = FALSE;
    unsigned short counter = ZERO;
    while ((text[counter] != c) * text[counter++]);
    exist = (text[--counter] == c);

    return (exist);
}

char * LastCharOfString(char * start_string)
{
    while (*(start_string++));

    return (--start_string);
}

//---------------------------------------------------------------------------------------
//                                        StringLenght
//                                        ------------
//
// General      : Checks the lenght of string.
//
// Parameters   :  
//          text - string (char[])
//
// Return value : Lenght of string (unsigned short).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
unsigned short StringLenght(char *start_string)
{
    return (LastCharOfString(start_string) - start_string);
}

//---------------------------------------------------------------------------------------
//                                        StringCompare
//                                        ------------------------
//
// General      : Compare 2 strings.
//
// Parameters   :  
//          text1 - string (char[])
//          text2 - string (char[])
//
// Return value : If this 2 strings are equals (BOOLEAN).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN StringCompare(char *start_stringA_index, char *start_stringB_index)
{
    while ((*start_stringA_index) && (*(start_stringA_index++) == *(start_stringB_index++)));

    return (*--start_stringA_index == *--start_stringB_index);
}

//---------------------------------------------------------------------------------------
//                                        IndexCharInPointers
//                                        -------------------
//
// General      : Find the index of char in the string.
//
// Parameters   :  
//          text - string (char[])
//          c    - char (char)
//
// Return value : The first index of the char in the string (unsigned short).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
char * IndexCharInPointers(char *start_pointer, char *end_pointer , char c)
{
    while ((*start_pointer) != c && start_pointer++ < end_pointer);

    return (start_pointer);
}

//---------------------------------------------------------------------------------------
//                                        CountCharInString
//                                        -----------------
//
// General      : Count how many the char is in the string.
//
// Parameters   :  
//          text - string (char[])
//          c    - char (char)
//
// Return value : Count of char in the string (unsigned short).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
unsigned short CountCharInString(char *start_string_index, char *c)
{
    unsigned short count = ZERO;
    while (*start_string_index)
    {
        count += (*(start_string_index++) == *c);
    }

    return (count);
}

//---------------------------------------------------------------------------------------
//                                        CutString
//                                        ---------
//
// General      : Cut the string.
//
// Parameters   :  
//          text  - string (char[])
//          start - from where (unsigned short)
//
// Return value : If the equation is ok (BOOLEAN).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : None
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
void CutString(char *start_textA_index, char *end_textA_index, char *start_textB_index)
{
    while (start_textA_index < end_textA_index)
    {
        *(start_textB_index++) = *(start_textA_index++);
    }
    *start_textB_index = BACKSLASH_ZERO;
    
}

//---------------------------------------------------------------------------------------
//                                        CopyString
//                                        ----------
//
// General      : Copy second string into first string.
//
// Parameters   :  
//          text  - first text (char[])
//          copy  - second text (char[])
//          start - from where to start (unsigned short)
//
// Return value : None.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
void CopyString(char *start_string_index, char *start_copy_index)
{
    while (*start_copy_index)
    {
        *(start_string_index++) = *(start_copy_index++);
    }
    *(start_string_index) = BACKSLASH_ZERO;
}

//---------------------------------------------------------------------------------------
//                                        LinkingString
//                                        -------------
//
// General      : Copy second string into end of first string.
//
// Parameters   :  
//          textA  - first text (char[])
//          textB  - second text (char[])
//
// Return value : None.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
void LinkingString(char *start_stringA_index, char *start_stringB_index)
{
    CopyString(LastCharOfString(start_stringA_index), start_stringB_index);
}

//---------------------------------------------------------------------------------------
//                                        ReverseString
//                                        -------------
//
// General      : Chnage to oppsite the string.
//
// Parameters   :  
//          textA  - first text (char[])
//
// Return value : None.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
void ReverseString(char textA[])
{
    unsigned short textA_lenght = StringLenght(textA) - ONE,
                 counter,
                 loop_lenght = (textA_lenght + ONE) / TWO;
    char temp_char;
    for (counter = ZERO; counter < loop_lenght; counter++)
    {
        temp_char = textA[counter];
        textA[counter] = textA[textA_lenght - counter];
        textA[textA_lenght - counter] = temp_char;
    }
}

//---------------------------------------------------------------------------------------
//                                        StringBInStringA
//                                        ----------------
//
// General      : Check if string B exists in string A.
//
// Parameters   :  
//          textA  - first text (char[])
//          textB  - second text (char[])
//
// Return value : If string B exists in string A (BOOLEAN).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN StringBInStringA(char *start_string_a, char *start_string_b)
{
    char *ptr_string_a_temp = start_string_a;
    char temp = BACKSLASH_ZERO;
    BOOLEAN flag = FALSE;
    unsigned short textB_lenght = StringLenght(start_string_b);
    char *address = (ptr_string_a_temp + textB_lenght);
    while ((*(address - ONE)) * !flag)
    {
        SwapChars(&temp, address);
        flag = StringCompare(ptr_string_a_temp, start_string_b);
        SwapChars(&temp, address);
        address = ((++ptr_string_a_temp) + textB_lenght);
    }
    
    return (flag);
}

//---------------------------------------------------------------------------------------
//                                        IndexStringBInStringA
//                                        ---------------------
//
// General      : Find the index of string B in string A.
//
// Parameters   :  
//          textA  - first text (char[])
//          textB  - second text (char[])
//
// Return value : Index of string B in string A (unsigned short).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
char * IndexStringBInStringA(char *start_string_a, char *start_string_b)
{
    char *ptr_string_a_temp = start_string_a;
    char temp = BACKSLASH_ZERO;
    BOOLEAN flag = FALSE;
    unsigned short textB_lenght = StringLenght(start_string_b);
    char *address = (ptr_string_a_temp + textB_lenght);
    while ((*(address - ONE)) * !flag)
    {
        SwapChars(&temp, address);
        flag = StringCompare(ptr_string_a_temp, start_string_b);
        SwapChars(&temp, address);
        address = ((++ptr_string_a_temp) + textB_lenght);
    }
    
    return (--ptr_string_a_temp);
}

//---------------------------------------------------------------------------------------
//                                        CountStringBInStringA
//                                        ---------------------
//
// General      : Counting how many times stringB in stringA.
//
// Parameters   :  
//          *start_string_a - Pointer of first string (char[])
//          *start_string_b - Pointer of second string (char[])
//
// Return value : Count second string in first string (unsigned int).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
unsigned int CountStringBInStringA(char *start_string_a, char *start_string_b)
{
    char *ptr_string_a_temp = start_string_a;
    char temp = BACKSLASH_ZERO;
    unsigned short count = ZERO;
    unsigned short textB_lenght = StringLenght(start_string_b);
    char *address = (ptr_string_a_temp + textB_lenght);
    while (*(address - ONE))
    {
        SwapChars(&temp, address);
        count += StringCompare(ptr_string_a_temp, start_string_b);
        SwapChars(&temp, address);
        address = ((++ptr_string_a_temp) + textB_lenght);
    }
    
    return (count);
}

//---------------------------------------------------------------------------------------
//                                        CountStringBInStringA
//                                        ---------------------
//
// General      : Remove first string B from string A.
//
// Parameters   :  
//          textA  - first text (char[])
//          textB  - second text (char[])
//
// Return value : None.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
void RemoveStringBFromStringA(char *start_string_a, char *start_string_b)
{
    unsigned short textB_lenght = StringLenght(start_string_b);
    char *ptr_index_stringB_in_stringA = IndexStringBInStringA(start_string_a, start_string_b);
    CopyString(ptr_index_stringB_in_stringA, ptr_index_stringB_in_stringA + textB_lenght);
}

//---------------------------------------------------------------------------------------
//                                        CountStringBInStringA
//                                        ---------------------
//
// General      : Remove ALL string B from string A.
//
// Parameters   :  
//          textA  - first text (char[])
//          textB  - second text (char[])
//
// Return value : None.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
void RemoveAllStringBFromStringA(char *start_stringA_index, char *start_stringB_index)
{
    unsigned short loop_lenght = CountStringBInStringA(start_stringA_index, start_stringB_index);
    unsigned short counter;
    for (counter = ZERO; counter < loop_lenght; counter++)
    {
        RemoveStringBFromStringA(start_stringA_index, start_stringB_index);
    }
}

//---------------------------------------------------------------------------------------
//                                        ValidParenthesesTemplate
//                                        ------------------------
//
// General      : checks if the string is a good equation.
//
// Parameters   :  
//          text - string (char[])
//
// Return value : If the equation is ok (BOOLEAN).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
BOOLEAN ValidParenthesesTemplate(char text[])
{
    unsigned short counter = ZERO;
    short count_parenthesis = ZERO;
    while (text[counter] * (count_parenthesis + ONE))
    {
        count_parenthesis += (text[counter] == '(');
        count_parenthesis -= (text[counter] == ')');
    }

    return (!count_parenthesis);
}

unsigned short CharToNumber(char *c)
{
    return (unsigned short)((*c) - '0'); 
}

//---------------------------------------------------------------------------------------
//                                        MaxCountCharInString
//                                        --------------------
//
// General      : Checks which character is most often in the string.
//
// Parameters   :  
//          *start_string_index - Pointer of string (char[])
//
// Return value : The number of times the character appears most often (unsigned int).
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 12.11.19
//---------------------------------------------------------------------------------------
unsigned int MaxCountCharInString(char *start_string_index)
{
    unsigned int max = ZERO,
                 count_temp;
    while (*start_string_index)
    {
        count_temp = CountCharInString(start_string_index++, start_string_index);
        max = (count_temp > max) ? count_temp : max;
    }
    
    return (max);
}

//---------------------------------------------------------------------------------------
//                                        CopyPointers
//                                        ------------
//
// General      : Copy second string into first string.
//
// Parameters   :  
//          text  - first text (char[])
//          copy  - second text (char[])
//          start - from where to start (unsigned short)
//
// Return value : None.
//
//---------------------------------------------------------------------------------------
// Programmer : Cohen Idan
// Student No : 211675038
// Date       : 04.10.2019
//---------------------------------------------------------------------------------------
void CopyPointers(char *start_string_index, char *start_copy_index, char *end_copy_index)
{
    while (start_copy_index <= end_copy_index)
    {
        *(start_string_index++) = *(start_copy_index++);
    }
}

void PrintVector(int *ptr_vec, int *ptr_vec_end)
{
    while (ptr_vec++ < ptr_vec_end)
    {
        printf("%hu, ", *ptr_vec);
    }
}

void PrintMatrix(int *ptr_mat, int *ptr_mat_end, unsigned short col)
{
    int *end_vector;
    for (; ptr_mat < ptr_mat_end; ptr_mat += col)
    {
        end_vector = ptr_mat + col;
        PrintVector(ptr_mat, end_vector);
        printf("\n");
    }
}

BOOLEAN EvenBits(byte b)
{
    BOOLEAN even = TRUE;
    unsigned short loop_length;
    for (loop_length = sizeof(b) * EIGHT; loop_length; loop_length--)
    {
        even ^= b & MASK_FIRST_BIT;
        b >>= ONE;
    }
    
    return (even);
}

unsigned short CountBits(byte b)
{
    unsigned short counter = ZERO,
                    loop_length = sizeof(b) * EIGHT;
    while (loop_length--)
    {
        counter += !EvenNumber(b);
        b >>= ONE;
    }

    return (counter);
}