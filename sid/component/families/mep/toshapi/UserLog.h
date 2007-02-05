#undef U_PL

#if USER_LOG_DISABLE

#define U_PL(lvl, fmt...) ((void)0)

#else

#define U_PL(lvl, fmt...) log ((lvl), fmt)

#endif
