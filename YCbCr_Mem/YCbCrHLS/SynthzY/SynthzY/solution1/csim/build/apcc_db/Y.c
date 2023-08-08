/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
unsigned char Y( char llvm_cbe_R,  char llvm_cbe_G,  char llvm_cbe_B);


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

unsigned char Y( char llvm_cbe_R,  char llvm_cbe_G,  char llvm_cbe_B) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond4_count = 0;
  bool llvm_cbe_or_2e_cond4;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond3_count = 0;
  bool llvm_cbe_or_2e_cond3;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  double llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  double llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  double llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  double llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  double llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  double llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  double llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  double llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  double llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned char llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned char llvm_cbe_storemerge;
  unsigned char llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @Y\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond4 = and i1 %%1, %%2, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_or_2e_cond4_count);
  llvm_cbe_or_2e_cond4 = (bool )(((((unsigned char )llvm_cbe_R&255U) < ((unsigned char )((unsigned char )66)&255U)) & (((unsigned char )llvm_cbe_R&255U) > ((unsigned char )((unsigned char )26)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond4 = 0x%X\n", llvm_cbe_or_2e_cond4);
  if (llvm_cbe_or_2e_cond4) {
    goto llvm_cbe_tmp__14;
  } else {
    goto llvm_cbe_tmp__15;
  }

llvm_cbe_tmp__14:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = and i1 %%4, %%5, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )(((((unsigned char )llvm_cbe_G&255U) < ((unsigned char )((unsigned char )76)&255U)) & (((unsigned char )llvm_cbe_G&255U) > ((unsigned char )((unsigned char )36)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    goto llvm_cbe_tmp__16;
  } else {
    goto llvm_cbe_tmp__15;
  }

llvm_cbe_tmp__16:
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond3 = and i1 %%7, %%8, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_or_2e_cond3_count);
  llvm_cbe_or_2e_cond3 = (bool )(((((unsigned char )llvm_cbe_B&255U) < ((unsigned char )((unsigned char )85)&255U)) & (((unsigned char )llvm_cbe_B&255U) > ((unsigned char )((unsigned char )45)&255U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond3 = 0x%X\n", llvm_cbe_or_2e_cond3);
  if (llvm_cbe_or_2e_cond3) {
    llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned char )((unsigned char )62);   /* for PHI node */
    goto llvm_cbe_tmp__17;
  } else {
    goto llvm_cbe_tmp__15;
  }

llvm_cbe_tmp__15:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = zext i8 %%R to i32, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__1 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_R&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sitofp i32 %%10 to double, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__2 = (double )((double )(signed int )llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__2, *(long long*)(&llvm_cbe_tmp__2));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = fmul double %%11, 2.570000e-01, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__3 = (double )llvm_cbe_tmp__2 * 0x1.072b020c49ba6p-2;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__3, *(long long*)(&llvm_cbe_tmp__3));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = zext i8 %%G to i32, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_G&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = sitofp i32 %%13 to double, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__5 = (double )((double )(signed int )llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__5, *(long long*)(&llvm_cbe_tmp__5));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fmul double %%14, 5.040000e-01, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_29_count);
  llvm_cbe_tmp__6 = (double )llvm_cbe_tmp__5 * 0x1.020c49ba5e354p-1;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__6, *(long long*)(&llvm_cbe_tmp__6));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = fadd double %%12, %%15, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__7 = (double )llvm_cbe_tmp__3 + llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__7, *(long long*)(&llvm_cbe_tmp__7));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = zext i8 %%B to i32, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__8 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_B&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sitofp i32 %%17 to double, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__9 = (double )((double )(signed int )llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__9, *(long long*)(&llvm_cbe_tmp__9));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = fmul double %%18, 9.800000e-02, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__10 = (double )llvm_cbe_tmp__9 * 0x1.916872b020c4ap-4;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__10, *(long long*)(&llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = fadd double %%16, %%19, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__11 = (double )llvm_cbe_tmp__7 + llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__11, *(long long*)(&llvm_cbe_tmp__11));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = fadd double %%20, 1.600000e+01, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__12 = (double )llvm_cbe_tmp__11 + 0x1p4;
if (AESL_DEBUG_TRACE)
printf("\n = %lf,  0x%llx\n", llvm_cbe_tmp__12, *(long long*)(&llvm_cbe_tmp__12));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = fptoui double %%21 to i8, !dbg !2 for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__13 = (unsigned char )((unsigned char )llvm_cbe_tmp__12&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned char )llvm_cbe_tmp__13;   /* for PHI node */
  goto llvm_cbe_tmp__17;

llvm_cbe_tmp__17:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i8 [ %%22, %%9 ], [ 62, %%6  for 0x%I64xth hint within @Y  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned char )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%X",llvm_cbe_storemerge);
printf("\n = 0x%X",llvm_cbe_tmp__13);
printf("\n = 0x%X",((unsigned char )62));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @Y}\n");
  return llvm_cbe_storemerge;
}

