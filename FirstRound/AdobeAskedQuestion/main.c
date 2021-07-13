#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    int sal;printf("Enter salary : ");scanf("%d",&sal);
    char lan[30];printf("Enter lan (Yes/No : ");scanf("%s",lan);
    char dep[30];printf("Enter department (ADM/TEC) : ");scanf("%s",dep);
    int exp;printf("Enter experience : ");scanf("%d",&exp);
    char deg[30];printf("Enter degree (Yes/No) : ");scanf("%s",deg);
    char phd[30];printf("Enter PHD (Yes/No) : ");scanf("%s",phd);
    float incsal = sal + sal * (0.25);
    if(dep[0] == 'A')
    {
        if(exp > 5)
        {
            incsal += (sal * 0.05);
            printf("For Experience 5per increased\n");
        }
        if(lan[0] == 'Y')
        {
            incsal += (sal * 0.02);
            printf("For Language 2per increased\n");
        }
    }
    else if(dep[0] == 'T')
    {
        if(deg[0] == 'Y')
        {
            incsal += (sal * 0.03);
            printf("For Degree 3per increased\n");
            if(phd[0] == 'Y')
            {
                incsal += (sal * 0.10);
                printf("For phd 10per increased\n");
            }
        }
        else if(phd[0] == 'Y')
        {
            incsal += (sal * 0.10);
            printf("For PhD 10per increased\n");
        }
        if(lan[0] == 'Y')
        {
            incsal += (sal * 0.02);
            printf("For language 2per increased\n");
        }
    }
    printf("%.6f",incsal);
    return 0;
}
