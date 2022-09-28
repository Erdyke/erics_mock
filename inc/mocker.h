#ifndef MOCKER_H
#define MOCKER_H

#define STRINGIFY(s) #s

#define CREATE_EXPECT_FUNC(func)\
static uint8_t func##_expects;\
void func##_expect(void)\
{\
    func##_expects++;\
}

#define CREATE_VERIFY_MOCK(func)\
void func##_verify(void)\
{\
    TEST_ASSERT_EQUAL(func##_expects, func##_calls);\
}

#define TEST_MOCK(ret, func, ...)\
static uint8_t func##_calls;\
CREATE_EXPECT_FUNC(func);\
CREATE_VERIFY_MOCK(func);\
ret func##_mock(__VA_ARGS__)   \
{                       \
    func##_calls++;\
    fprintf(stderr, "%s: %d\n", STRINGIFY(func##_calls), func##_calls);\
}



#endif

