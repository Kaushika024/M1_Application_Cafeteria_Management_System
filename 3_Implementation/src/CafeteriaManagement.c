int again;
int total=0;
float gst,cgst,sgst;
int beverrate[7][2]={  {0,20},
                    {1,25},
                    {2,20},
                    {3,10},
                    {4,40},
                    {5,50},
                    {6,30}
                };
int snackrate[7][2]={{0,30},
                {1,50},
                {2,30},
                {3,30},
                {4,70},
                {5,40},
                {6,130}};
int sandwich_rate[7][2]={{0,80},
                {1,120},
                {2,90},
                {3,100},
                {4,90},
                {5,150},
                {6,100}};
int purchased[][3]={{0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0}
                        };
int temp[][3]={{0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0}
                        };
void bever(char bevermenu[][100]);
void snack(char snackmenu[][100]);
void sandwich(char sandwichmenu[][100]);
void main_menu();
void display();
void snack_menucard();
void sandwich_menu();
void display_bever_bill(char bevermenu[][100]);
void display_snack_bill(char snackmenu[][100]);
void display_sandwich_bill(char sandwichmenu[][100]);
void display_bevermenu();
void repeatbever(char bevermenu[][100]);
void repeatsnack(char snackmenu[][100]);
void repeatsandwich(char sandwichmenu[][100]);
void display_total_words();
void main()
{
    char bevermenu[][100]={"Tea","Coffee","Lemon Tea","Milk","Milkshakes","Cold Coffee","Fresh Juices"};
    char snackmenu[][100]={"Veg puff","Chicken puff","Mushroom puff","Egg puff","Veg roll","Cutlet","French fries"};
    char sandwichmenu[][100]={"Veg sandwich","Chicken sandwich","Chilly Cheese","Egg Mayo sandwich","Panner sandwich","Grilled sandwich","Special sandwich"};
    char choice;
    do
    {
        enter:
        display();
        printf("Enter your choice here : ");
        scanf("%c", &choice);
        getchar();
        switch(choice)
        {
            case 'A':
            case 'a':printf("\nBeverages\n");
                    bever(bevermenu);
                    break;
            case 'B':
             case 'b':printf("\nSnacks\n");
                    snack(snackmenu);
                    break;
             case 'C':
            case 'c':printf("\nSandwiches\n");
                    sandwich(sandwichmenu);
                    break;
           default:printf("\nWrong choice entered Please enter the valid choice!!\n");
                    goto enter;
        }
    }while(choice!='d');
}
void display()
{
    printf("               WELCOME TO SNACK BAR         \n ");
    printf("             +============================+          \n\n");
    printf("  && Please select the meal that you would like to purchase. && \n\n");
    printf("\t\t      [1] Beverages\n");
    printf("\t\t      [2] Snacks\n");
    printf("\t\t      [3] sandwiches\n");
}
void display_bevermenu()
{
    printf("                WELCOME TO SNACK BAR          \n ");
    printf("             +============================+          \n\n");
    printf("                  $  Beverages Menu  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] Tea - Rs 20.00\n");
    printf("\t\t   [1] Coffee - Rs 20.00\n");
    printf("\t\t   [2] Lemon Tea - Rs 10.00\n");
    printf("\t\t   [3] Milk - Rs 15.00\n");
    printf("\t\t   [4] Milkshakes - Rs 40.00\n");
    printf("\t\t   [5] Cold Coffee - Rs 50.00\n");
    printf("\t\t   [6] Fresh Juices - Rs 30.00\n");
}
void bever(char bevermenu[][100]) 
{
    int choice = 0;
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    display_bevermenu();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    printf("Total is %d\n\n",total);
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*beverrate[code][1]; 
        total+=purchased[code][ 1];
        printf("Total is %d\n\n",total);
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        bever(bevermenu);
    }
    repeatbever(bevermenu);
}
void repeatbever(char bevermenu[][100])
{
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); 
    scanf("%d",&again);
    if (again == 1)
            bever(bevermenu);
    else if (again == 2 )
    {
        display_bever_bill(bevermenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatbever(bevermenu);
    }
}
void display_bever_bill(char bevermenu[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      SNACK BAR                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t%s\t\t",bevermenu[i]);
            printf("%d\n",purchased[i][1]); 
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n",total);
    display_total_words();
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~+          \n\n");

}
void display_snack_bill(char snackmenu[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      SNACK BAR                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",snackmenu[i]);
            printf("%d\n",purchased[i][1]);
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n",total);
    display_total_words();
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~+          \n\n");
}
void display_sandwich_bill(char sandwichmenu[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                     SNACK BAR                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",sandwichmenu[i]);
            printf("%d\n",purchased[i][1]);
        }

    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n\n",total);
    display_total_words();
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~+          \n\n");
}
void snack(char snackmenu[][100]) 
{
    int choice = 0; 
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    snack_menucard();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*snackrate[code][1];
         total+=purchased[code][ 1];
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
         snack(snackmenu);
    }
    repeatsnack(snackmenu);
}
void sandwich(char sandwichmenu[][100]) 
{
    int choice = 0;
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    sandwichmenu();

    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*sandwich_rate[code][1];
        total+=purchased[code][1];
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        sandwich(sandwichmenu);
    }
    repeatsandwich(sandwichmenu);
}
void snack_menucard()
{
    printf("                WELCOME TO SNACK BAR.          \n ");
    printf("             +============================+          \n\n");
    printf("                   $  SNACK Menu  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] Veg puff - Rs 30.00\n");
    printf("\t\t   [1] Chicken puff - Rs 50.00\n");
    printf("\t\t   [2] Mushroom puff - Rs 30.00\n");
    printf("\t\t   [3] Egg puff - Rs 30.00\n");
    printf("\t\t   [4] Veg roll- Rs 70.00\n");
    printf("\t\t   [5] Cutlet - Rs 40.00\n");
    printf("\t\t   [6] French fries - Rs 130.00\n");
    printf("Enter your choice here : ");
}
void sandwichmenu()
{
    printf("                WELCOME TO SNACK BAR          \n ");
    printf("             +============================+          \n\n");
    printf("                    $  SANDWICH Menu  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] Veg sandwich - Rs 80.00\n");
    printf("\t\t   [1] Chicken sandwich- Rs 120.00\n");
    printf("\t\t   [2] Chilly Cheese - Rs 90.00\n");
    printf("\t\t   [3] Egg Mayo sandwich - Rs 100.00\n");
    printf("\t\t   [4] Paneer sandwich - Rs 90.00\n");
    printf("\t\t   [5] Grilled Chicken sandwich - Rs 150.00\n");
    printf("\t\t   [6] Special sandwich - Rs 100.00\n");
}
void repeatsnack(char snackmenu[][100])
{
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); 
    scanf("%d",&again);
    if (again == 1)
            snack(snackmenu);
    else if (again == 2 )
    {
        display_snack_bill(snackmenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatsnack(snackmenu);
    }
}
void repeatsandwich(char sandwichmenu[][100])
{

    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
    scanf("%d",&again);
    if (again == 1)
    {
        sandwich(sandwichmenu);
    }
    else if (again == 2 )
    {
        display_sandwich_bill(sandwichmenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatsandwich(sandwichmenu);
    }
}
void display_total_words()
{
    int num=0,digits=0,temp=0;
    while(total != 0)
    {
        num=(num * 10)+(total % 10);
        total/= 10;
        digits++;
    }
    printf("\nNo of digits::%d\n",digits);
    while(num!= 0)
    {
        temp++;
        switch(num%10)
        {
            case 0:
                printf("Zero ");
                break;
            case 1:
                printf("One ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
        }
        num = num / 10;
    }
    if(num==0&&digits!=temp)
        printf(" Zero ");
    return;
}
