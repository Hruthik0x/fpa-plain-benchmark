#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u16 saurabh_sol_store(char* str, u8 len)
{
    u16 res;
    if (len == 6) //100.00
    {
        res = 10000;
    }
    else if (len == 5)  // 10.00 - 99.99
    {
        res = ((str[0] - '0') * 10 + str[1] - '0') * 100 + (str[3] - '0') * 10 + (str[4] - '0') ;
    }
    else 
    {
        res = (str[0] - '0') * 100 + (str[2] - '0') * 10 + str[3] - '0';
    }
    return res;
}

void hruthik_sol_store(char* str, u8 len, u8 res[2])
{
    if (len == 6)   // 100.00
    {
        res[0] = 100;
        res[1] = 100;
    }
    else if (len == 5)  // 10.00 - 99.99
    {
        res[0] = (str[0] - '0') * 10 + str[1] - '0';
        res[1] = (str[3] - '0') * 10 + str[4] - '0';
    }
    else // 0.00 - 9.99
    {
        res[0] = str[0] - '0';
        res[1] = (str[2] - '0') * 10 + str[3] - '0';
    }
}

void benchmark_store(u32 rounds)
{
    clock_t start, end;
    double cpu_time;
    char str[6];

    printf("----------------------Benchmarking store functions----------------------\n\n");

    start = clock();

    u8 res[2];
    for (u16 _ = 0 ; _ < rounds ; _++)
    {
        for (u8 a = 0 ; a < 100 ; a++)
        {
            for (u8 b = 0 ; b < 100 ; b++)
            {
                sprintf(str, "%d.%02d", a, b);
                hruthik_sol_store(str, strlen(str), res);
            }
        }
    }

    hruthik_sol_store("100.00", 6, res);

    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Total time Hruthik's sol : %lf\n", cpu_time);
    printf("Avg per round (%d rounds) : %f\n\n", rounds, cpu_time / rounds);

        start = clock();

    for (u16 _ = 0 ; _ < rounds ; _++)
    {
        for (u8 a = 0 ; a < 100 ; a++)
        {
            for (u8 b = 0 ; b < 100 ; b++)
            {
                sprintf(str, "%d.%02d", a, b);
                saurabh_sol_store(str, strlen(str));
            }
        }
    }

    saurabh_sol_store("100.00", 6);

    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;


    printf("Total time Saurabh's sol : %lf\n", cpu_time);
    printf("Avg per round (%d rounds) : %f\n\n\n", rounds, cpu_time / rounds);
}

void gen_rand_percent(char* str)
{
    u8 a = rand() % 101;
    u8 b = rand() % 100;
    sprintf(str, "%d.%02d", a, b);
}

// Overflow has to explicitly handled in hruthik's solution
void hruthik_sol_addition(u8 num1[2], u8 num2[2], u8 out[2])
{
    out[1] = num1[1] + num2[1];
    if (out[1] >= 100)
    {
        out[1] -= 100;
        out[0] = num2[0] + num1[0] + 1;
    }
    else 
    {
        out[0] = num2[0] + num1[0];
    }

}

// Overflow is handled implicitly in saurabh's solution
u16 saurabh_sol_addition(u16 num1, u16 num2)
{
    return num1 + num2;
}

void benchmark_add(u32 rounds)
{
    clock_t start, end;
    double cpu_time;

    char num1s[rounds][6];
    char num2s[rounds][6];

    u8 num1[2], num2[2];
    u8 h_res[rounds][2];

    u16 num3, num4;
    u16 s_res[rounds];

    printf("-----------------------Benchmarking add functions-----------------------\n\n");

    for (u32 a = 0 ; a < rounds ; a++)
    {
        gen_rand_percent(num1s[a]);
        gen_rand_percent(num2s[a]);
    }

    start = clock();

    for (u32 a = 0 ; a < rounds ; a++)
    {
        hruthik_sol_store(num1s[a], strlen(num1s[a]), num1);
        hruthik_sol_store(num2s[a], strlen(num2s[a]), num2);
        hruthik_sol_addition(num1, num2, h_res[a]);   
    }

    end = clock(); 

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Total time Hruthik's sol : %lf\n", cpu_time);
    printf("Avg per round (%d rounds) : %f\n\n", rounds, cpu_time / rounds);

    start = clock();

    for (u32 a = 0 ; a < rounds ; a++)
    {
        num3 = saurabh_sol_store(num1s[a], strlen(num1s[a]));
        num4 = saurabh_sol_store(num2s[a], strlen(num2s[a]));
        s_res[a] = saurabh_sol_addition(num3, num4);
    }

    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Total time Saurabh's sol : %lf\n", cpu_time);
    printf("Avg per round (%d rounds) : %f\n\n", rounds, cpu_time / rounds);

}

void hruthik_sol_retrieve(char* str, u8 nums[2])
{
    if (nums[0] == 100)
    {
        sprintf(str, "100.00");
    }
    else if (nums[0] >= 10)
    {
        sprintf(str, "%d.%02d", nums[0], nums[1]);
    }
    else 
    {
        sprintf(str, "%d.%02d", nums[0], nums[1]);
    }
}

void sauabh_sol_retrieve(char* str, u16 nums)
{
    sprintf(str, "%d.%02d", nums / 100, nums % 100);
}

void benchmark_retrieval(u32 rounds)
{
    char str[rounds][6];
    u8 nums_h[rounds][2];
    u16 nums_s[rounds];
    char buff[6];


    clock_t start, end;
    double cpu_time;

    printf("-------------------Benchmarking retrieval functions-------------------\n\n");

    for (u32 a = 0 ; a < rounds ; a++)
    {
        gen_rand_percent(str[a]);
        hruthik_sol_store(str[a], strlen(str[a]), nums_h[a]);
        nums_s[a] = saurabh_sol_store(str[a], strlen(str[a]));
    }

    start = clock();
    for (u32 a = 0 ; a < rounds ; a++)
    {
        hruthik_sol_retrieve(buff, nums_h[a]);
    }
    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Total time Hruthik's sol : %lf\n", cpu_time);
    printf("Avg per round (%d rounds) : %f\n\n", rounds, cpu_time / rounds);

    start = clock();
    for (u32 a = 0 ; a < rounds ; a++)
    {
        sauabh_sol_retrieve(buff, nums_s[a]);
    }
    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Total time Saurabh's sol : %lf\n", cpu_time);
    printf("Avg per round (%d rounds) : %f\n\n", rounds, cpu_time / rounds);

}

int main()
{
    u32 rounds = 1000;

    // benchmark_store stores **all** floats from 0.00 to 100.00
    benchmark_store(rounds);

    rounds = 500000;

    // benchmark_add performs addition for rounds no.of times among 2*rounds random floats
    benchmark_add(rounds);

    benchmark_retrieval(rounds);
    return 0;
}