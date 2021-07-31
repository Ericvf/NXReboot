#include <string.h>
#include <stdio.h>

#include <switch.h>

#define R_TRY(res_expr) ({ \
    const Result _tmp_r_try_rc = res_expr; \
    if (R_FAILED(_tmp_r_try_rc)) { \
        return _tmp_r_try_rc; \
    } \
})

int PerformShutdown(bool do_reboot) {
    R_TRY(spsmInitialize());
    R_TRY(spsmShutdown(do_reboot));
    spsmExit();

    return 0;
}

int main(int argc, char **argv)
{
    consoleInit(NULL);
    PerformShutdown(true);
    return 0;
}

