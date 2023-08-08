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
void sobel_filter( char *llvm_cbe_in,  char *llvm_cbe_out);


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

void sobel_filter( char *llvm_cbe_in,  char *llvm_cbe_out) {
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
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge6_count = 0;
  unsigned int llvm_cbe_storemerge6;
  unsigned int llvm_cbe_storemerge6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge15_count = 0;
  unsigned int llvm_cbe_storemerge15;
  unsigned int llvm_cbe_storemerge15__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  unsigned int llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned char llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned int llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned long long llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
   char *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned char llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned long long llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
   char *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  unsigned char llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
   char *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  unsigned char llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned long long llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
   char *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned char llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  unsigned int llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  unsigned long long llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
   char *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned char llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_sum_count = 0;
  unsigned int llvm_cbe_sum;
  static  unsigned long long aesl_llvm_cbe_sum7_count = 0;
  unsigned int llvm_cbe_sum7;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned int llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  unsigned int llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned long long llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
   char *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned char llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned int llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  unsigned int llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
   char *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned char llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  unsigned int llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  unsigned int llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  unsigned int llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe__2e__count = 0;
  unsigned int llvm_cbe__2e_;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  unsigned int llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  unsigned char llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned long long llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
   char *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned int llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond8_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @sobel_filter\n");
  llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge6 = phi i32 [ 1, %%0 ], [ %%70, %%69  for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_storemerge6_count);
  llvm_cbe_storemerge6 = (unsigned int )llvm_cbe_storemerge6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge6 = 0x%X",llvm_cbe_storemerge6);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",llvm_cbe_tmp__66);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = shl i32 %%storemerge6, 9, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__1 = (unsigned int )llvm_cbe_storemerge6 << 9u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add i32 %%1, -1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_68_count);
  llvm_cbe_tmp__2 = (unsigned int )((unsigned int )(llvm_cbe_tmp__1&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__2&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = add i32 %%1, -512, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(llvm_cbe_tmp__1&4294967295ull)) + ((unsigned int )(4294966784u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__3&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i32 %%1, 512, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__4 = (unsigned int )((unsigned int )(llvm_cbe_tmp__1&4294967295ull)) + ((unsigned int )(512u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__4&4294967295ull)));
  llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__67;

llvm_cbe_tmp__68:
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = add nsw i32 %%storemerge6, 1, !dbg !4 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__66 = (unsigned int )((unsigned int )(llvm_cbe_storemerge6&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__66&4294967295ull)));
  if (((llvm_cbe_tmp__66&4294967295U) == (511u&4294967295U))) {
    goto llvm_cbe_tmp__69;
  } else {
    llvm_cbe_storemerge6__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__66;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__67:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge15 = phi i32 [ 1, %%.preheader ], [ %%28, %%5  for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_storemerge15_count);
  llvm_cbe_storemerge15 = (unsigned int )llvm_cbe_storemerge15__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge15 = 0x%X",llvm_cbe_storemerge15);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i32 %%storemerge15, %%1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__5 = (unsigned int )((unsigned int )(llvm_cbe_storemerge15&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__1&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__5&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = add i32 %%6, -513, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__6 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(4294966783u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__6&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sext i32 %%7 to i64, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__7 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i8* %%in, i64 %%8, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__8 = ( char *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__7))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__7));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%9, align 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__9 = (unsigned char )*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i8 %%10 to i32, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__9&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add i32 %%2, %%storemerge15, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__11 = (unsigned int )((unsigned int )(llvm_cbe_tmp__2&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge15&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__11&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = sext i32 %%12 to i64, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__12 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i8* %%in, i64 %%13, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__13 = ( char *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__12))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__12));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8* %%14, align 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__14 = (unsigned char )*llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i8 %%15 to i32, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__15 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__14&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = shl nuw nsw i32 %%16, 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_83_count);
  llvm_cbe_tmp__16 = (unsigned int )llvm_cbe_tmp__15 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add i32 %%6, 511, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(511u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%18 to i64, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__18 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds i8* %%in, i64 %%19, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__19 = ( char *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__18))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__18));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i8* %%20, align 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__20 = (unsigned char )*llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = zext i8 %%21 to i32, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__21 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__20&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add i32 %%6, -511, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(4294966785u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = sext i32 %%23 to i64, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__23 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__22);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds i8* %%in, i64 %%24, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__24 = ( char *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__23))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__23));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load i8* %%25, align 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__25 = (unsigned char )*llvm_cbe_tmp__24;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = zext i8 %%26 to i32, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__25&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = add nsw i32 %%storemerge15, 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__27 = (unsigned int )((unsigned int )(llvm_cbe_storemerge15&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__27&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = add nsw i32 %%28, %%1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_95_count);
  llvm_cbe_tmp__28 = (unsigned int )((unsigned int )(llvm_cbe_tmp__27&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__1&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__28&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = sext i32 %%29 to i64, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__29 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds i8* %%in, i64 %%30, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__30 = ( char *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__29))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__29));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = load i8* %%31, align 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__31 = (unsigned char )*llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = zext i8 %%32 to i32, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__32 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__31&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = shl nuw nsw i32 %%33, 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__33 = (unsigned int )llvm_cbe_tmp__32 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = add i32 %%6, 513, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__34 = (unsigned int )((unsigned int )(llvm_cbe_tmp__5&4294967295ull)) + ((unsigned int )(513u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__34&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sext i32 %%35 to i64, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__35 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds i8* %%in, i64 %%36, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__36 = ( char *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__35))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__35));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i8* %%37, align 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__37 = (unsigned char )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = zext i8 %%38 to i32, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__38 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__37&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%sum = add i32 %%17, %%11, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_sum_count);
  llvm_cbe_sum = (unsigned int )((unsigned int )(llvm_cbe_tmp__16&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__10&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nsum = 0x%X\n", ((unsigned int )(llvm_cbe_sum&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%sum7 = add i32 %%sum, %%22, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_sum7_count);
  llvm_cbe_sum7 = (unsigned int )((unsigned int )(llvm_cbe_sum&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__21&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\nsum7 = 0x%X\n", ((unsigned int )(llvm_cbe_sum7&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = sub i32 %%27, %%sum7, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__39 = (unsigned int )((unsigned int )(llvm_cbe_tmp__26&4294967295ull)) - ((unsigned int )(llvm_cbe_sum7&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__39&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add i32 %%40, %%39, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__40 = (unsigned int )((unsigned int )(llvm_cbe_tmp__39&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__38&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__40&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add i32 %%41, %%34, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__41 = (unsigned int )((unsigned int )(llvm_cbe_tmp__40&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__33&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__41&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i32 %%3, %%storemerge15, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__42 = (unsigned int )((unsigned int )(llvm_cbe_tmp__3&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge15&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__42&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = sext i32 %%43 to i64, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__43 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds i8* %%in, i64 %%44, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__44 = ( char *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__43))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__43));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = load i8* %%45, align 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__45 = (unsigned char )*llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = zext i8 %%46 to i32, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__46 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__45&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = shl nuw nsw i32 %%47, 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__47 = (unsigned int )llvm_cbe_tmp__46 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add i32 %%4, %%storemerge15, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__48 = (unsigned int )((unsigned int )(llvm_cbe_tmp__4&4294967295ull)) + ((unsigned int )(llvm_cbe_storemerge15&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__48&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = sext i32 %%49 to i64, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__49 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__48);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = getelementptr inbounds i8* %%in, i64 %%50, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__50 = ( char *)(&llvm_cbe_in[(((signed long long )llvm_cbe_tmp__49))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__49));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = load i8* %%51, align 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__51 = (unsigned char )*llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = zext i8 %%52 to i32, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__52 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__51&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = shl nuw nsw i32 %%53, 1, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__53 = (unsigned int )llvm_cbe_tmp__52 << 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = sub i32 %%11, %%22, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__54 = (unsigned int )((unsigned int )(llvm_cbe_tmp__10&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__21&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__54&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = add i32 %%55, %%27, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_127_count);
  llvm_cbe_tmp__55 = (unsigned int )((unsigned int )(llvm_cbe_tmp__54&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__26&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__55&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = sub i32 %%56, %%39, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__56 = (unsigned int )((unsigned int )(llvm_cbe_tmp__55&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__38&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__56&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = add i32 %%57, %%48, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(llvm_cbe_tmp__56&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__47&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__57&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = sub i32 %%58, %%54, !dbg !2 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__58 = (unsigned int )((unsigned int )(llvm_cbe_tmp__57&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__53&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__58&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = sub nsw i32 0, %%42, !dbg !3 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__59 = (unsigned int )-(llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__59&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = select i1 %%60, i32 %%61, i32 %%42, !dbg !3 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__60 = (unsigned int )(((((signed int )llvm_cbe_tmp__41) < ((signed int )0u))) ? ((unsigned int )llvm_cbe_tmp__59) : ((unsigned int )llvm_cbe_tmp__41));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = sub nsw i32 0, %%59, !dbg !3 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__61 = (unsigned int )-(llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__61&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%. = select i1 %%63, i32 %%64, i32 %%59, !dbg !3 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe__2e__count);
  llvm_cbe__2e_ = (unsigned int )(((((signed int )llvm_cbe_tmp__58) < ((signed int )0u))) ? ((unsigned int )llvm_cbe_tmp__61) : ((unsigned int )llvm_cbe_tmp__58));
if (AESL_DEBUG_TRACE)
printf("\n. = 0x%X\n", llvm_cbe__2e_);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = add nsw i32 %%., %%62, !dbg !3 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__62 = (unsigned int )((unsigned int )(llvm_cbe__2e_&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__60&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__62&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = trunc i32 %%65 to i8, !dbg !3 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__63 = (unsigned char )((unsigned char )llvm_cbe_tmp__62&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = sext i32 %%6 to i64, !dbg !3 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__64 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = getelementptr inbounds i8* %%out, i64 %%67, !dbg !3 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__65 = ( char *)(&llvm_cbe_out[(((signed long long )llvm_cbe_tmp__64))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__64));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%66, i8* %%68, align 1, !dbg !3 for 0x%I64xth hint within @sobel_filter  --> \n", ++aesl_llvm_cbe_156_count);
  *llvm_cbe_tmp__65 = llvm_cbe_tmp__63;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
  if (((llvm_cbe_tmp__27&4294967295U) == (511u&4294967295U))) {
    goto llvm_cbe_tmp__68;
  } else {
    llvm_cbe_storemerge15__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__27;   /* for PHI node */
    goto llvm_cbe_tmp__67;
  }

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__69:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @sobel_filter}\n");
  return;
}

