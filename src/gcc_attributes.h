#include <unistd.h>

#if __GNU__ >= 3

#undef inline
#define inline __attribute__((always_inline))
#define __pure __attribute__((pure))
#define __noreturn __attribute__((noreturn))
#define __deprecated__ __attribute__((deprecated))

#define __used __attribute__((used))

#define __unused __attribute__((used))
#define __packed __attribute__((packed))

#else

#define __deprecated
#define __inline
#define __pure
#define __noreturn
#define __used
#define __unused
#define __packed

#endif

/*
#ifdef __GNUC__
#define __pure __attribute__((pure))
#else
#define __pure
#endif


__attribute ((pure)) int foo() {
    int x = 10;
    return x;
}

__packed __pure int pull() {
    return 10;
}

__inline int main() {
    pull();
    return foo();
}

*/
