#include<unity.h>
#include<atm_operations.h>
#define PROJECT_NAME "ATM"


void check_pin();
void check_balance();
void deposit_cash();
void withdraw_cash();
void change_pin();
void transactions();

void setup(){}
void teardown(){}

int test_main()
{
    UNITY_BEGIN();

    RUN_TEST(check_pin);
    RUN_TEST(check_balance);
    RUN_TEST(deposit_cash);
    RUN_TEST(withdraw_cash);
    RUN_TEST(change_pin);
    RUN_TEST(transactions);

    return UNITY_END();
}

void check_pin(void)
{
    TEST_ASSERT_EQUAL(transactions(), check_pin());
    TEST_ASSERT_EQUAL(transactions(), check_pin());
}

void check_balance(void)
{
    TEST_ASSERT_EQUAL(10000, check_balance());
}

void deposit_cash(void)
{
    TEST_ASSERT_EQUAL(15000, deposit_cash(5000));
    TEST_ASSERT_EQUAL(20000, deposit_cash(10000));
}

void withdraw_cash(void)
{
    TEST_ASSERT_EQUAL();
}

