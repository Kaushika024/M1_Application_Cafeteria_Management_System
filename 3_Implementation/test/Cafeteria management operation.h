#include "unity.h"
#include <Cafeteria_management.h>

/* Modify these two lines according to the project */
#include <Cafeteria_management.h>
#define PROJECT_NAME    "Cafeteria management system"

/* Prototypes for all the test functions */
void bever(char bevermenu[][100]);
void snack( char snackmenu[][100]);
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
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();
  
/* Run Test functions */
  RUN_TEST(test_bever_menu);
  RUN_TEST(test_snack_menu);
  RUN_TEST(test_sandwich_menu);
  RUN_TEST(test_main_menu);
  RUN_TEST(test_display);
  RUN_TEST(test_snack_menucard);
  RUN_TEST(test_sandwich_menu);
  RUN_TEST(test_display_bever_bill);
  RUN_TEST(test_display_snack_bill);
  RUN_TEST(test_sandwich_bill);
  RUN_TEST(test_display_bevermenu);
  RUN_TEST(test_repeatbever);
  RUN_TEST(test_repeatsnack);
  RUN_TEST(test_repeatsandwich);
  RUN_TEST(test_display_total_words);



  /* Close the Unity Test Framework */
  return UNITY_END()
  }
    
    void test_total_bill(void){
    float qty1 = 5, qty2 = 5, price1 = 27, price2 = 5;
    float ans1 = 135, ans2 = 25;
    TEST_ASSERT_EQUAL(ans1, total_bill(qty1,price1));
    TEST_ASSERT_EQUAL(25, total_bill(qty2,price2));
}

void test_net_total(void){
    float num1 = 40,num2 = 80,num3 = 135;
    float ans1 = 36,ans2 = 72,ans3 = 121.5;
    TEST_ASSERT_EQUAL(ans1, net_total(num1));
    TEST_ASSERT_EQUAL(ans2, net_total(num2));
    TEST_ASSERT_EQUAL(ans3, net_total(num3));
}

void test_grand_total(void){
    float input1 = 80, input2 = 140, input3 = 121.5;
    float ans1 = 94.4, ans2 = 165.2, ans3 = 143.37; 
    TEST_ASSERT_EQUAL(ans1, grand_total(input1));
    TEST_ASSERT_EQUAL(ans2, grand_total(input2));
    TEST_ASSERT_EQUAL(ans3, grand_total(input3));
}
void test_negative_total(void){
  float qty1 = -5, qty2 = -32000, qty3 = 25, qty4 = -5, price1 = -76, price2 = -7600, price3 = -63,price4 = 34 ;
  float ans = 0;
  TEST_ASSERT_EQUAL(ans, total_bill(qty1,price1));
  TEST_ASSERT_EQUAL(ans, total_bill(qty2,price2));
  TEST_ASSERT_EQUAL(ans, total_bill(qty3,price3));
  TEST_ASSERT_EQUAL(ans, total_bill(qty4,price4));
}
void test_negative_net_total(void){
  float input1 = -32000, input2 = -1;
  float ans =0;
  TEST_ASSERT_EQUAL(0, net_total(-32000));
  TEST_ASSERT_EQUAL(0, net_total(-1));
}

void test_negative_grand_total(void){
  float input1 = -32000, input2 = -1;
  float ans = 0;
  TEST_ASSERT_EQUAL(0, grand_total(-32000));
  TEST_ASSERT_EQUAL(0, grand_total(-1));
}
