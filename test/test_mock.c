
#include "unity.h"
#include "mocker.h"

TEST_MOCK(void, func, uint8_t a);

void test_mocker(void)
{
    func_expect();
    func_expect();
    func_mock(1);
    // func_mock(2);
    func_verify();
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_mocker);
    return UNITY_END();
}
