#ifdef WIN32
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#if defined(WIN32) || defined(__APPLE__)
static int int_val;

DLLEXPORT void set_int_val(int val)
{
    int_val = val;
}
#else
extern int int_val;
#endif

extern int get_val_in_exe(void);

DLLEXPORT int get_val_in_dll()
{
    return int_val;
}

DLLEXPORT int get_val_in_exe_from_dll()
{
    return get_val_in_exe();
}

DLLEXPORT int get_val_in_dll_from_dll()
{
    return get_val_in_dll();
}
