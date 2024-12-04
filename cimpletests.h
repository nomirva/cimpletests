#ifndef CIMPLETESTS_H
#define CIMPLETESTS_H

#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

static double getUnixTime() {
#ifdef _WIN32
    FILETIME ft;
    ULARGE_INTEGER ull;
    GetSystemTimeAsFileTime(&ft);
    ull.LowPart = ft.dwLowDateTime;
    ull.HighPart = ft.dwHighDateTime;
    return (double)(ull.QuadPart / 10000.0);
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)(tv.tv_sec * 1000LL) + (double)(tv.tv_usec / 1000.0);
#endif
}

#define Test(x) TestRun(#x, x)

static double testStart = 0;
static double testEnd = 0;

static int testsPassed = 0;
static int testsFailed = 0;

static void TestRun(char *name, char *(test)()) {
    char *result = test();
    testEnd = getUnixTime();
    testStart += testStart ? 0 : getUnixTime();
    result ? testsFailed++ : testsPassed++;
    printf("%s \033[90m->\033[0m \033[35m%s\033[0m %s %s\n", (result ? "\033[31mX\033[0m" : "\033[32mV\033[0m"), name, (result ? "\033[90m:\033[0m" : ""), (result ? result : ""));
}

void TestResults() {
    printf("\033[32mPassed %d\033[0m \033[31mFailed %d\033[0m \033[90m(%.1fms)\033[0m\n", testsPassed, testsFailed, testEnd - testStart);
}

#endif // CIMPLETESTS_H