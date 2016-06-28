#ifndef __OBJC2__
#define __OBJC2__
#endif
struct objc_selector; struct objc_class;
struct __rw_objc_super { 
	struct objc_object *object; 
	struct objc_object *superClass; 
	__rw_objc_super(struct objc_object *o, struct objc_object *s) : object(o), superClass(s) {} 
};
#ifndef _REWRITER_typedef_Protocol
typedef struct objc_object Protocol;
#define _REWRITER_typedef_Protocol
#endif
#define __OBJC_RW_DLLIMPORT extern
__OBJC_RW_DLLIMPORT void objc_msgSend(void);
__OBJC_RW_DLLIMPORT void objc_msgSendSuper(void);
__OBJC_RW_DLLIMPORT void objc_msgSend_stret(void);
__OBJC_RW_DLLIMPORT void objc_msgSendSuper_stret(void);
__OBJC_RW_DLLIMPORT void objc_msgSend_fpret(void);
__OBJC_RW_DLLIMPORT struct objc_class *objc_getClass(const char *);
__OBJC_RW_DLLIMPORT struct objc_class *class_getSuperclass(struct objc_class *);
__OBJC_RW_DLLIMPORT struct objc_class *objc_getMetaClass(const char *);
__OBJC_RW_DLLIMPORT void objc_exception_throw( struct objc_object *);
__OBJC_RW_DLLIMPORT int objc_sync_enter( struct objc_object *);
__OBJC_RW_DLLIMPORT int objc_sync_exit( struct objc_object *);
__OBJC_RW_DLLIMPORT Protocol *objc_getProtocol(const char *);
#ifdef _WIN64
typedef unsigned long long  _WIN_NSUInteger;
#else
typedef unsigned int _WIN_NSUInteger;
#endif
#ifndef __FASTENUMERATIONSTATE
struct __objcFastEnumerationState {
	unsigned long state;
	void **itemsPtr;
	unsigned long *mutationsPtr;
	unsigned long extra[5];
};
__OBJC_RW_DLLIMPORT void objc_enumerationMutation(struct objc_object *);
#define __FASTENUMERATIONSTATE
#endif
#ifndef __NSCONSTANTSTRINGIMPL
struct __NSConstantStringImpl {
  int *isa;
  int flags;
  char *str;
#if _WIN64
  long long length;
#else
  long length;
#endif
};
#ifdef CF_EXPORT_CONSTANT_STRING
extern "C" __declspec(dllexport) int __CFConstantStringClassReference[];
#else
__OBJC_RW_DLLIMPORT int __CFConstantStringClassReference[];
#endif
#define __NSCONSTANTSTRINGIMPL
#endif
#ifndef BLOCK_IMPL
#define BLOCK_IMPL
struct __block_impl {
  void *isa;
  int Flags;
  int Reserved;
  void *FuncPtr;
};
// Runtime copy/destroy helper functions (from Block_private.h)
#ifdef __OBJC_EXPORT_BLOCKS
extern "C" __declspec(dllexport) void _Block_object_assign(void *, const void *, const int);
extern "C" __declspec(dllexport) void _Block_object_dispose(const void *, const int);
extern "C" __declspec(dllexport) void *_NSConcreteGlobalBlock[32];
extern "C" __declspec(dllexport) void *_NSConcreteStackBlock[32];
#else
__OBJC_RW_DLLIMPORT void _Block_object_assign(void *, const void *, const int);
__OBJC_RW_DLLIMPORT void _Block_object_dispose(const void *, const int);
__OBJC_RW_DLLIMPORT void *_NSConcreteGlobalBlock[32];
__OBJC_RW_DLLIMPORT void *_NSConcreteStackBlock[32];
#endif
#endif
#define __block
#define __weak

#include <stdarg.h>
struct __NSContainer_literal {
  void * *arr;
  __NSContainer_literal (unsigned int count, ...) {
	va_list marker;
	va_start(marker, count);
	arr = new void *[count];
	for (unsigned i = 0; i < count; i++)
	  arr[i] = va_arg(marker, void *);
	va_end( marker );
  };
  ~__NSContainer_literal() {
	delete[] arr;
  }
};
extern "C" __declspec(dllimport) void * objc_autoreleasePoolPush(void);
extern "C" __declspec(dllimport) void objc_autoreleasePoolPop(void *);

struct __AtAutoreleasePool {
  __AtAutoreleasePool() {atautoreleasepoolobj = objc_autoreleasePoolPush();}
  ~__AtAutoreleasePool() {objc_autoreleasePoolPop(atautoreleasepoolobj);}
  void * atautoreleasepoolobj;
};

#define __OFFSETOFIVAR__(TYPE, MEMBER) ((long long) &((TYPE *)0)->MEMBER)









typedef signed char __int8_t;



typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;

typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
typedef int __darwin_ct_rune_t;





typedef union {
 char __mbstate8[128];
 long long _mbstateL;
} __mbstate_t;

typedef __mbstate_t __darwin_mbstate_t;


typedef long int __darwin_ptrdiff_t;







typedef long unsigned int __darwin_size_t;





typedef __builtin_va_list __darwin_va_list;





typedef int __darwin_wchar_t;




typedef __darwin_wchar_t __darwin_rune_t;


typedef int __darwin_wint_t;




typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;





typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;

typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;


typedef int64_t register_t;





typedef __darwin_intptr_t intptr_t;
typedef unsigned long uintptr_t;



typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;







typedef u_int64_t syscall_arg_t;
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;

typedef __darwin_ino64_t __darwin_ino_t;



typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];


struct __darwin_pthread_handler_rec {
 void (*__routine)(void *);
 void *__arg;
 struct __darwin_pthread_handler_rec *__next;
};

struct _opaque_pthread_attr_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_cond_t {
 long __sig;
 char __opaque[40];
};

struct _opaque_pthread_condattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_mutex_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_mutexattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_once_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_rwlock_t {
 long __sig;
 char __opaque[192];
};

struct _opaque_pthread_rwlockattr_t {
 long __sig;
 char __opaque[16];
};

struct _opaque_pthread_t {
 long __sig;
 struct __darwin_pthread_handler_rec *__cleanup_stack;
 char __opaque[8176];
};

typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t *__darwin_pthread_t;

static inline
__uint16_t
_OSSwapInt16(
    __uint16_t _data
)
{
    return ((__uint16_t)((_data << 8) | (_data >> 8)));
}

static inline
__uint32_t
_OSSwapInt32(
    __uint32_t _data
)
{

    return __builtin_bswap32(_data);




}


static inline
__uint64_t
_OSSwapInt64(
    __uint64_t _data
)
{
    return __builtin_bswap64(_data);
}


typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;

typedef unsigned long u_long;


typedef unsigned short ushort;
typedef unsigned int uint;


typedef u_int64_t u_quad_t;
typedef int64_t quad_t;
typedef quad_t * qaddr_t;

typedef char * caddr_t;
typedef int32_t daddr_t;


typedef __darwin_dev_t dev_t;

typedef u_int32_t fixpt_t;


typedef __darwin_blkcnt_t blkcnt_t;
typedef __darwin_blksize_t blksize_t;
typedef __darwin_gid_t gid_t;
typedef __uint32_t in_addr_t;
typedef __uint16_t in_port_t;
typedef __darwin_ino_t ino_t;


typedef __darwin_ino64_t ino64_t;


typedef __int32_t key_t;
typedef __darwin_mode_t mode_t;
typedef __uint16_t nlink_t;
typedef __darwin_id_t id_t;
typedef __darwin_pid_t pid_t;
typedef __darwin_off_t off_t;

typedef int32_t segsz_t;
typedef int32_t swblk_t;


typedef __darwin_uid_t uid_t;
static inline __int32_t major(__uint32_t _x)
{
 return (__int32_t)(((__uint32_t)_x >> 24) & 0xff);
}

static inline __int32_t minor(__uint32_t _x)
{
 return (__int32_t)((_x) & 0xffffff);
}

static inline dev_t makedev(__uint32_t _major, __uint32_t _minor)
{
 return (dev_t)(((_major) << 24) | (_minor));
}
typedef __darwin_clock_t clock_t;
typedef __darwin_size_t size_t;
typedef __darwin_ssize_t ssize_t;
typedef __darwin_time_t time_t;

typedef __darwin_useconds_t useconds_t;
typedef __darwin_suseconds_t suseconds_t;


typedef __darwin_size_t rsize_t;
typedef int errno_t;








extern "C" {
typedef struct fd_set {
 __int32_t fds_bits[((((1024) % ((sizeof(__int32_t) * 8))) == 0) ? ((1024) / ((sizeof(__int32_t) * 8))) : (((1024) / ((sizeof(__int32_t) * 8))) + 1))];
} fd_set;
}


static inline int
__darwin_fd_isset(int _n, const struct fd_set *_p)
{
 return (_p->fds_bits[(unsigned long)_n/(sizeof(__int32_t) * 8)] & ((__int32_t)(1<<((unsigned long)_n % (sizeof(__int32_t) * 8)))));
}




typedef __int32_t fd_mask;










typedef __darwin_pthread_attr_t pthread_attr_t;
typedef __darwin_pthread_cond_t pthread_cond_t;
typedef __darwin_pthread_condattr_t pthread_condattr_t;
typedef __darwin_pthread_mutex_t pthread_mutex_t;
typedef __darwin_pthread_mutexattr_t pthread_mutexattr_t;
typedef __darwin_pthread_once_t pthread_once_t;
typedef __darwin_pthread_rwlock_t pthread_rwlock_t;
typedef __darwin_pthread_rwlockattr_t pthread_rwlockattr_t;
typedef __darwin_pthread_t pthread_t;



typedef __darwin_pthread_key_t pthread_key_t;




typedef __darwin_fsblkcnt_t fsblkcnt_t;
typedef __darwin_fsfilcnt_t fsfilcnt_t;
typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;

typedef enum {
 P_ALL,
 P_PID,
 P_PGID
} idtype_t;
typedef int sig_atomic_t;
struct __darwin_i386_thread_state
{
    unsigned int __eax;
    unsigned int __ebx;
    unsigned int __ecx;
    unsigned int __edx;
    unsigned int __edi;
    unsigned int __esi;
    unsigned int __ebp;
    unsigned int __esp;
    unsigned int __ss;
    unsigned int __eflags;
    unsigned int __eip;
    unsigned int __cs;
    unsigned int __ds;
    unsigned int __es;
    unsigned int __fs;
    unsigned int __gs;
};
struct __darwin_fp_control
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
      :2,
    __pc :2,





    __rc :2,






             :1,
      :3;
};
typedef struct __darwin_fp_control __darwin_fp_control_t;
struct __darwin_fp_status
{
    unsigned short __invalid :1,
        __denorm :1,
    __zdiv :1,
    __ovrfl :1,
    __undfl :1,
    __precis :1,
    __stkflt :1,
    __errsumm :1,
    __c0 :1,
    __c1 :1,
    __c2 :1,
    __tos :3,
    __c3 :1,
    __busy :1;
};
typedef struct __darwin_fp_status __darwin_fp_status_t;
struct __darwin_mmst_reg
{
 char __mmst_reg[10];
 char __mmst_rsrv[6];
};
struct __darwin_xmm_reg
{
 char __xmm_reg[16];
};
struct __darwin_i386_float_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
};


struct __darwin_i386_avx_state
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;
 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;
 __uint16_t __fpu_rsrv2;
 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;
 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 char __fpu_rsrv4[14*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
};
struct __darwin_i386_exception_state
{
 __uint16_t __trapno;
 __uint16_t __cpu;
 __uint32_t __err;
 __uint32_t __faultvaddr;
};
struct __darwin_x86_debug_state32
{
 unsigned int __dr0;
 unsigned int __dr1;
 unsigned int __dr2;
 unsigned int __dr3;
 unsigned int __dr4;
 unsigned int __dr5;
 unsigned int __dr6;
 unsigned int __dr7;
};
struct __darwin_x86_thread_state64
{
 __uint64_t __rax;
 __uint64_t __rbx;
 __uint64_t __rcx;
 __uint64_t __rdx;
 __uint64_t __rdi;
 __uint64_t __rsi;
 __uint64_t __rbp;
 __uint64_t __rsp;
 __uint64_t __r8;
 __uint64_t __r9;
 __uint64_t __r10;
 __uint64_t __r11;
 __uint64_t __r12;
 __uint64_t __r13;
 __uint64_t __r14;
 __uint64_t __r15;
 __uint64_t __rip;
 __uint64_t __rflags;
 __uint64_t __cs;
 __uint64_t __fs;
 __uint64_t __gs;
};
struct __darwin_x86_float_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;


 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;

 __uint16_t __fpu_rsrv2;


 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;

 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
};


struct __darwin_x86_avx_state64
{
 int __fpu_reserved[2];
 struct __darwin_fp_control __fpu_fcw;
 struct __darwin_fp_status __fpu_fsw;
 __uint8_t __fpu_ftw;
 __uint8_t __fpu_rsrv1;
 __uint16_t __fpu_fop;


 __uint32_t __fpu_ip;
 __uint16_t __fpu_cs;

 __uint16_t __fpu_rsrv2;


 __uint32_t __fpu_dp;
 __uint16_t __fpu_ds;

 __uint16_t __fpu_rsrv3;
 __uint32_t __fpu_mxcsr;
 __uint32_t __fpu_mxcsrmask;
 struct __darwin_mmst_reg __fpu_stmm0;
 struct __darwin_mmst_reg __fpu_stmm1;
 struct __darwin_mmst_reg __fpu_stmm2;
 struct __darwin_mmst_reg __fpu_stmm3;
 struct __darwin_mmst_reg __fpu_stmm4;
 struct __darwin_mmst_reg __fpu_stmm5;
 struct __darwin_mmst_reg __fpu_stmm6;
 struct __darwin_mmst_reg __fpu_stmm7;
 struct __darwin_xmm_reg __fpu_xmm0;
 struct __darwin_xmm_reg __fpu_xmm1;
 struct __darwin_xmm_reg __fpu_xmm2;
 struct __darwin_xmm_reg __fpu_xmm3;
 struct __darwin_xmm_reg __fpu_xmm4;
 struct __darwin_xmm_reg __fpu_xmm5;
 struct __darwin_xmm_reg __fpu_xmm6;
 struct __darwin_xmm_reg __fpu_xmm7;
 struct __darwin_xmm_reg __fpu_xmm8;
 struct __darwin_xmm_reg __fpu_xmm9;
 struct __darwin_xmm_reg __fpu_xmm10;
 struct __darwin_xmm_reg __fpu_xmm11;
 struct __darwin_xmm_reg __fpu_xmm12;
 struct __darwin_xmm_reg __fpu_xmm13;
 struct __darwin_xmm_reg __fpu_xmm14;
 struct __darwin_xmm_reg __fpu_xmm15;
 char __fpu_rsrv4[6*16];
 int __fpu_reserved1;
 char __avx_reserved1[64];
 struct __darwin_xmm_reg __fpu_ymmh0;
 struct __darwin_xmm_reg __fpu_ymmh1;
 struct __darwin_xmm_reg __fpu_ymmh2;
 struct __darwin_xmm_reg __fpu_ymmh3;
 struct __darwin_xmm_reg __fpu_ymmh4;
 struct __darwin_xmm_reg __fpu_ymmh5;
 struct __darwin_xmm_reg __fpu_ymmh6;
 struct __darwin_xmm_reg __fpu_ymmh7;
 struct __darwin_xmm_reg __fpu_ymmh8;
 struct __darwin_xmm_reg __fpu_ymmh9;
 struct __darwin_xmm_reg __fpu_ymmh10;
 struct __darwin_xmm_reg __fpu_ymmh11;
 struct __darwin_xmm_reg __fpu_ymmh12;
 struct __darwin_xmm_reg __fpu_ymmh13;
 struct __darwin_xmm_reg __fpu_ymmh14;
 struct __darwin_xmm_reg __fpu_ymmh15;
};
struct __darwin_x86_exception_state64
{
    __uint16_t __trapno;
    __uint16_t __cpu;
    __uint32_t __err;
    __uint64_t __faultvaddr;
};
struct __darwin_x86_debug_state64
{
 __uint64_t __dr0;
 __uint64_t __dr1;
 __uint64_t __dr2;
 __uint64_t __dr3;
 __uint64_t __dr4;
 __uint64_t __dr5;
 __uint64_t __dr6;
 __uint64_t __dr7;
};




struct __darwin_mcontext32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_float_state __fs;
};


struct __darwin_mcontext_avx32
{
 struct __darwin_i386_exception_state __es;
 struct __darwin_i386_thread_state __ss;
 struct __darwin_i386_avx_state __fs;
};
struct __darwin_mcontext64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_float_state64 __fs;
};


struct __darwin_mcontext_avx64
{
 struct __darwin_x86_exception_state64 __es;
 struct __darwin_x86_thread_state64 __ss;
 struct __darwin_x86_avx_state64 __fs;
};
typedef struct __darwin_mcontext64 *mcontext_t;



struct __darwin_sigaltstack
{
 void *ss_sp;
 __darwin_size_t ss_size;
 int ss_flags;
};
typedef struct __darwin_sigaltstack stack_t;
struct __darwin_ucontext
{
 int uc_onstack;
 __darwin_sigset_t uc_sigmask;
 struct __darwin_sigaltstack uc_stack;
 struct __darwin_ucontext *uc_link;
 __darwin_size_t uc_mcsize;
 struct __darwin_mcontext64 *uc_mcontext;



};


typedef struct __darwin_ucontext ucontext_t;


typedef __darwin_sigset_t sigset_t;



union sigval {

 int sival_int;
 void *sival_ptr;
};





struct sigevent {
 int sigev_notify;
 int sigev_signo;
 union sigval sigev_value;
 void (*sigev_notify_function)(union sigval);
 pthread_attr_t *sigev_notify_attributes;
};


typedef struct __siginfo {
 int si_signo;
 int si_errno;
 int si_code;
 pid_t si_pid;
 uid_t si_uid;
 int si_status;
 void *si_addr;
 union sigval si_value;
 long si_band;
 unsigned long __pad[7];
} siginfo_t;
union __sigaction_u {
 void (*__sa_handler)(int);
 void (*__sa_sigaction)(int, struct __siginfo *,
         void *);
};


struct __sigaction {
 union __sigaction_u __sigaction_u;
 void (*sa_tramp)(void *, int, int, siginfo_t *, void *);
 sigset_t sa_mask;
 int sa_flags;
};




struct sigaction {
 union __sigaction_u __sigaction_u;
 sigset_t sa_mask;
 int sa_flags;
};
typedef void (*sig_t)(int);
struct sigvec {
 void (*sv_handler)(int);
 int sv_mask;
 int sv_flags;
};
struct sigstack {
 char *ss_sp;
 int ss_onstack;
};
extern "C" {
void (*signal(int, void (*)(int)))(int);
}
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;
typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;



typedef int8_t int_fast8_t;
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef int64_t int_fast64_t;
typedef uint8_t uint_fast8_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
typedef uint64_t uint_fast64_t;
typedef long int intmax_t;
typedef long unsigned int uintmax_t;







struct timeval
{
 __darwin_time_t tv_sec;
 __darwin_suseconds_t tv_usec;
};








typedef __uint64_t rlim_t;
struct rusage {
 struct timeval ru_utime;
 struct timeval ru_stime;
 long ru_maxrss;

 long ru_ixrss;
 long ru_idrss;
 long ru_isrss;
 long ru_minflt;
 long ru_majflt;
 long ru_nswap;
 long ru_inblock;
 long ru_oublock;
 long ru_msgsnd;
 long ru_msgrcv;
 long ru_nsignals;
 long ru_nvcsw;
 long ru_nivcsw;


};
typedef void *rusage_info_t;

struct rusage_info_v0 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
};

struct rusage_info_v1 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
};

struct rusage_info_v2 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
};

struct rusage_info_v3 {
 uint8_t ri_uuid[16];
 uint64_t ri_user_time;
 uint64_t ri_system_time;
 uint64_t ri_pkg_idle_wkups;
 uint64_t ri_interrupt_wkups;
 uint64_t ri_pageins;
 uint64_t ri_wired_size;
 uint64_t ri_resident_size;
 uint64_t ri_phys_footprint;
 uint64_t ri_proc_start_abstime;
 uint64_t ri_proc_exit_abstime;
 uint64_t ri_child_user_time;
 uint64_t ri_child_system_time;
 uint64_t ri_child_pkg_idle_wkups;
 uint64_t ri_child_interrupt_wkups;
 uint64_t ri_child_pageins;
 uint64_t ri_child_elapsed_abstime;
 uint64_t ri_diskio_bytesread;
 uint64_t ri_diskio_byteswritten;
 uint64_t ri_cpu_time_qos_default;
 uint64_t ri_cpu_time_qos_maintenance;
 uint64_t ri_cpu_time_qos_background;
 uint64_t ri_cpu_time_qos_utility;
 uint64_t ri_cpu_time_qos_legacy;
 uint64_t ri_cpu_time_qos_user_initiated;
 uint64_t ri_cpu_time_qos_user_interactive;
 uint64_t ri_billed_system_time;
 uint64_t ri_serviced_system_time;
};

typedef struct rusage_info_v3 rusage_info_current;
struct rlimit {
 rlim_t rlim_cur;
 rlim_t rlim_max;
};
struct proc_rlimit_control_wakeupmon {
 uint32_t wm_flags;
 int32_t wm_rate;
};
extern "C" {
int getpriority(int, id_t);

int getiopolicy_np(int, int) __attribute__((availability(macosx,introduced=10.5)));

int getrlimit(int, struct rlimit *) __asm("_" "getrlimit" );
int getrusage(int, struct rusage *);
int setpriority(int, id_t, int);

int setiopolicy_np(int, int, int) __attribute__((availability(macosx,introduced=10.5)));

int setrlimit(int, const struct rlimit *) __asm("_" "setrlimit" );
}
union wait {
 int w_status;



 struct {

  unsigned int w_Termsig:7,
    w_Coredump:1,
    w_Retcode:8,
    w_Filler:16;







 } w_T;





 struct {

  unsigned int w_Stopval:8,
    w_Stopsig:8,
    w_Filler:16;






 } w_S;
};
extern "C" {
pid_t wait(int *) __asm("_" "wait" );
pid_t waitpid(pid_t, int *, int) __asm("_" "waitpid" );

int waitid(idtype_t, id_t, siginfo_t *, int) __asm("_" "waitid" );


pid_t wait3(int *, int, struct rusage *);
pid_t wait4(pid_t, int *, int, struct rusage *);

}

extern "C" {
void *alloca(size_t);
}








typedef __darwin_ct_rune_t ct_rune_t;
typedef __darwin_rune_t rune_t;



typedef struct {
 int quot;
 int rem;
} div_t;

typedef struct {
 long quot;
 long rem;
} ldiv_t;


typedef struct {
 long long quot;
 long long rem;
} lldiv_t;



extern int __mb_cur_max;
extern "C" {
void abort(void) __attribute__((noreturn));
int abs(int) __attribute__((const));
int atexit(void (*)(void));
double atof(const char *);
int atoi(const char *);
long atol(const char *);

long long
  atoll(const char *);

void *bsearch(const void *, const void *, size_t,
     size_t, int (*)(const void *, const void *));
void *calloc(size_t, size_t);
div_t div(int, int) __attribute__((const));
void exit(int) __attribute__((noreturn));
void free(void *);
char *getenv(const char *);
long labs(long) __attribute__((const));
ldiv_t ldiv(long, long) __attribute__((const));

long long
  llabs(long long);
lldiv_t lldiv(long long, long long);

void *malloc(size_t);
int mblen(const char *, size_t);
size_t mbstowcs(wchar_t * , const char * , size_t);
int mbtowc(wchar_t * , const char * , size_t);
int posix_memalign(void **, size_t, size_t) __attribute__((availability(macosx,introduced=10.6)));
void qsort(void *, size_t, size_t,
     int (*)(const void *, const void *));
int rand(void);
void *realloc(void *, size_t);
void srand(unsigned);
double strtod(const char *, char **) __asm("_" "strtod" );
float strtof(const char *, char **) __asm("_" "strtof" );
long strtol(const char *, char **, int);
long double
  strtold(const char *, char **);

long long
  strtoll(const char *, char **, int);

unsigned long
  strtoul(const char *, char **, int);

unsigned long long
  strtoull(const char *, char **, int);

int system(const char *) __asm("_" "system" ) __attribute__((availability(macosx,introduced=10.0))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
size_t wcstombs(char * , const wchar_t * , size_t);
int wctomb(char *, wchar_t);


void _Exit(int) __attribute__((noreturn));
long a64l(const char *);
double drand48(void);
char *ecvt(double, int, int *, int *);
double erand48(unsigned short[3]);
char *fcvt(double, int, int *, int *);
char *gcvt(double, int, char *);
int getsubopt(char **, char * const *, char **);
int grantpt(int);

char *initstate(unsigned, char *, size_t);



long jrand48(unsigned short[3]);
char *l64a(long);
void lcong48(unsigned short[7]);
long lrand48(void);
char *mktemp(char *);
int mkstemp(char *);
long mrand48(void);
long nrand48(unsigned short[3]);
int posix_openpt(int);
char *ptsname(int);
int putenv(char *) __asm("_" "putenv" );
long random(void);
int rand_r(unsigned *);

char *realpath(const char * , char * ) __asm("_" "realpath" "$DARWIN_EXTSN");



unsigned short
 *seed48(unsigned short[3]);
int setenv(const char *, const char *, int) __asm("_" "setenv" );

void setkey(const char *) __asm("_" "setkey" );



char *setstate(const char *);
void srand48(long);

void srandom(unsigned);



int unlockpt(int);

int unsetenv(const char *) __asm("_" "unsetenv" );
u_int32_t arc4random(void);
void arc4random_addrandom(unsigned char * , int );
void arc4random_buf(void * , size_t ) __attribute__((availability(macosx,introduced=10.7)));
void arc4random_stir(void);
u_int32_t
  arc4random_uniform(u_int32_t ) __attribute__((availability(macosx,introduced=10.7)));

int atexit_b(void (*)(void)) __attribute__((availability(macosx,introduced=10.6)));
void *bsearch_b(const void *, const void *, size_t,
     size_t, int (*)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));



char *cgetcap(char *, const char *, int);
int cgetclose(void);
int cgetent(char **, char **, const char *);
int cgetfirst(char **, char **);
int cgetmatch(const char *, const char *);
int cgetnext(char **, char **);
int cgetnum(char *, const char *, long *);
int cgetset(const char *);
int cgetstr(char *, const char *, char **);
int cgetustr(char *, const char *, char **);

int daemon(int, int) __asm("_" "daemon" ) __attribute__((availability(macosx,introduced=10.0,deprecated=10.5,message="Use posix_spawn APIs instead."))) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
char *devname(dev_t, mode_t);
char *devname_r(dev_t, mode_t, char *buf, int len);
char *getbsize(int *, long *);
int getloadavg(double [], int);
const char
 *getprogname(void);

int heapsort(void *, size_t, size_t,
     int (*)(const void *, const void *));

int heapsort_b(void *, size_t, size_t,
     int (*)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

int mergesort(void *, size_t, size_t,
     int (*)(const void *, const void *));

int mergesort_b(void *, size_t, size_t,
     int (*)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

void psort(void *, size_t, size_t,
     int (*)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

void psort_b(void *, size_t, size_t,
     int (*)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

void psort_r(void *, size_t, size_t, void *,
     int (*)(void *, const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

void qsort_b(void *, size_t, size_t,
     int (*)(const void *, const void *)) __attribute__((availability(macosx,introduced=10.6)));

void qsort_r(void *, size_t, size_t, void *,
     int (*)(void *, const void *, const void *));
int radixsort(const unsigned char **, int, const unsigned char *,
     unsigned);
void setprogname(const char *);
int sradixsort(const unsigned char **, int, const unsigned char *,
     unsigned);
void sranddev(void);
void srandomdev(void);
void *reallocf(void *, size_t);

long long
  strtoq(const char *, char **, int);
unsigned long long
  strtouq(const char *, char **, int);

extern char *suboptarg;
void *valloc(size_t);






}
extern "C" {
void __assert_rtn(const char *, const char *, int, const char *) __attribute__((noreturn));



}
typedef __darwin_wint_t wint_t;
typedef struct {
 __darwin_rune_t __min;
 __darwin_rune_t __max;
 __darwin_rune_t __map;
 __uint32_t *__types;
} _RuneEntry;

typedef struct {
 int __nranges;
 _RuneEntry *__ranges;
} _RuneRange;

typedef struct {
 char __name[14];
 __uint32_t __mask;
} _RuneCharClass;

typedef struct {
 char __magic[8];
 char __encoding[32];

 __darwin_rune_t (*__sgetrune)(const char *, __darwin_size_t, char const **);
 int (*__sputrune)(__darwin_rune_t, char *, __darwin_size_t, char **);
 __darwin_rune_t __invalid_rune;

 __uint32_t __runetype[(1 <<8 )];
 __darwin_rune_t __maplower[(1 <<8 )];
 __darwin_rune_t __mapupper[(1 <<8 )];






 _RuneRange __runetype_ext;
 _RuneRange __maplower_ext;
 _RuneRange __mapupper_ext;

 void *__variable;
 int __variable_len;




 int __ncharclasses;
 _RuneCharClass *__charclasses;
} _RuneLocale;



extern "C" {
extern _RuneLocale _DefaultRuneLocale;
extern _RuneLocale *_CurrentRuneLocale;
}
extern "C" {
unsigned long ___runetype(__darwin_ct_rune_t);
__darwin_ct_rune_t ___tolower(__darwin_ct_rune_t);
__darwin_ct_rune_t ___toupper(__darwin_ct_rune_t);
}

inline int
isascii(int _c)
{
 return ((_c & ~0x7F) == 0);
}
extern "C" {
int __maskrune(__darwin_ct_rune_t, unsigned long);
}


inline int
__istype(__darwin_ct_rune_t _c, unsigned long _f)
{



 return (isascii(_c) ? !!(_DefaultRuneLocale.__runetype[_c] & _f)
  : !!__maskrune(_c, _f));

}

inline __darwin_ct_rune_t
__isctype(__darwin_ct_rune_t _c, unsigned long _f)
{



 return (_c < 0 || _c >= (1 <<8 )) ? 0 :
  !!(_DefaultRuneLocale.__runetype[_c] & _f);

}
extern "C" {
__darwin_ct_rune_t __toupper(__darwin_ct_rune_t);
__darwin_ct_rune_t __tolower(__darwin_ct_rune_t);
}


inline int
__wcwidth(__darwin_ct_rune_t _c)
{
 unsigned int _x;

 if (_c == 0)
  return (0);
 _x = (unsigned int)__maskrune(_c, 0xe0000000L|0x00040000L);
 if ((_x & 0xe0000000L) != 0)
  return ((_x & 0xe0000000L) >> 30);
 return ((_x & 0x00040000L) != 0 ? 1 : -1);
}






inline int
isalnum(int _c)
{
 return (__istype(_c, 0x00000100L|0x00000400L));
}

inline int
isalpha(int _c)
{
 return (__istype(_c, 0x00000100L));
}

inline int
isblank(int _c)
{
 return (__istype(_c, 0x00020000L));
}

inline int
iscntrl(int _c)
{
 return (__istype(_c, 0x00000200L));
}


inline int
isdigit(int _c)
{
 return (__isctype(_c, 0x00000400L));
}

inline int
isgraph(int _c)
{
 return (__istype(_c, 0x00000800L));
}

inline int
islower(int _c)
{
 return (__istype(_c, 0x00001000L));
}

inline int
isprint(int _c)
{
 return (__istype(_c, 0x00040000L));
}

inline int
ispunct(int _c)
{
 return (__istype(_c, 0x00002000L));
}

inline int
isspace(int _c)
{
 return (__istype(_c, 0x00004000L));
}

inline int
isupper(int _c)
{
 return (__istype(_c, 0x00008000L));
}


inline int
isxdigit(int _c)
{
 return (__isctype(_c, 0x00010000L));
}

inline int
toascii(int _c)
{
 return (_c & 0x7F);
}

inline int
tolower(int _c)
{
        return (__tolower(_c));
}

inline int
toupper(int _c)
{
        return (__toupper(_c));
}


inline int
digittoint(int _c)
{
 return (__maskrune(_c, 0x0F));
}

inline int
ishexnumber(int _c)
{
 return (__istype(_c, 0x00010000L));
}

inline int
isideogram(int _c)
{
 return (__istype(_c, 0x00080000L));
}

inline int
isnumber(int _c)
{
 return (__istype(_c, 0x00000400L));
}

inline int
isphonogram(int _c)
{
 return (__istype(_c, 0x00200000L));
}

inline int
isrune(int _c)
{
 return (__istype(_c, 0xFFFFFFF0L));
}

inline int
isspecial(int _c)
{
 return (__istype(_c, 0x00100000L));
}
extern "C" {
extern int * __error(void);

}





struct lconv {
 char *decimal_point;
 char *thousands_sep;
 char *grouping;
 char *int_curr_symbol;
 char *currency_symbol;
 char *mon_decimal_point;
 char *mon_thousands_sep;
 char *mon_grouping;
 char *positive_sign;
 char *negative_sign;
 char int_frac_digits;
 char frac_digits;
 char p_cs_precedes;
 char p_sep_by_space;
 char n_cs_precedes;
 char n_sep_by_space;
 char p_sign_posn;
 char n_sign_posn;
 char int_p_cs_precedes;
 char int_n_cs_precedes;
 char int_p_sep_by_space;
 char int_n_sep_by_space;
 char int_p_sign_posn;
 char int_n_sign_posn;
};



extern "C" {
struct lconv *localeconv(void);
}
extern "C" {
char *setlocale(int, const char *);
}
extern "C" {
    typedef float float_t;
    typedef double double_t;
extern int __math_errhandling(void);
extern int __fpclassifyf(float);
extern int __fpclassifyd(double);
extern int __fpclassifyl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float);
inline __attribute__ ((__always_inline__)) int __inline_isfinited(double);
inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double);
inline __attribute__ ((__always_inline__)) int __inline_isinff(float);
inline __attribute__ ((__always_inline__)) int __inline_isinfd(double);
inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isnanf(float);
inline __attribute__ ((__always_inline__)) int __inline_isnand(double);
inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double);
inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float);
inline __attribute__ ((__always_inline__)) int __inline_isnormald(double);
inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double);
inline __attribute__ ((__always_inline__)) int __inline_signbitf(float);
inline __attribute__ ((__always_inline__)) int __inline_signbitd(double);
inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double);

inline __attribute__ ((__always_inline__)) int __inline_isfinitef(float __x) {
    return __x == __x && __builtin_fabsf(__x) != __builtin_inff();
}
inline __attribute__ ((__always_inline__)) int __inline_isfinited(double __x) {
    return __x == __x && __builtin_fabs(__x) != __builtin_inf();
}
inline __attribute__ ((__always_inline__)) int __inline_isfinitel(long double __x) {
    return __x == __x && __builtin_fabsl(__x) != __builtin_infl();
}
inline __attribute__ ((__always_inline__)) int __inline_isinff(float __x) {
    return __builtin_fabsf(__x) == __builtin_inff();
}
inline __attribute__ ((__always_inline__)) int __inline_isinfd(double __x) {
    return __builtin_fabs(__x) == __builtin_inf();
}
inline __attribute__ ((__always_inline__)) int __inline_isinfl(long double __x) {
    return __builtin_fabsl(__x) == __builtin_infl();
}
inline __attribute__ ((__always_inline__)) int __inline_isnanf(float __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_isnand(double __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_isnanl(long double __x) {
    return __x != __x;
}
inline __attribute__ ((__always_inline__)) int __inline_signbitf(float __x) {
    union { float __f; unsigned int __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 31);
}
inline __attribute__ ((__always_inline__)) int __inline_signbitd(double __x) {
    union { double __f; unsigned long long __u; } __u;
    __u.__f = __x;
    return (int)(__u.__u >> 63);
}

inline __attribute__ ((__always_inline__)) int __inline_signbitl(long double __x) {
    union {
        long double __ld;
        struct{ unsigned long long __m; unsigned short __sexp; } __p;
    } __u;
    __u.__ld = __x;
    return (int)(__u.__p.__sexp >> 15);
}







inline __attribute__ ((__always_inline__)) int __inline_isnormalf(float __x) {
    return __inline_isfinitef(__x) && __builtin_fabsf(__x) >= 1.17549435e-38F;
}
inline __attribute__ ((__always_inline__)) int __inline_isnormald(double __x) {
    return __inline_isfinited(__x) && __builtin_fabs(__x) >= 2.2250738585072014e-308;
}
inline __attribute__ ((__always_inline__)) int __inline_isnormall(long double __x) {
    return __inline_isfinitel(__x) && __builtin_fabsl(__x) >= 3.36210314311209350626e-4932L;
}
extern float acosf(float);
extern double acos(double);
extern long double acosl(long double);

extern float asinf(float);
extern double asin(double);
extern long double asinl(long double);

extern float atanf(float);
extern double atan(double);
extern long double atanl(long double);

extern float atan2f(float, float);
extern double atan2(double, double);
extern long double atan2l(long double, long double);

extern float cosf(float);
extern double cos(double);
extern long double cosl(long double);

extern float sinf(float);
extern double sin(double);
extern long double sinl(long double);

extern float tanf(float);
extern double tan(double);
extern long double tanl(long double);

extern float acoshf(float);
extern double acosh(double);
extern long double acoshl(long double);

extern float asinhf(float);
extern double asinh(double);
extern long double asinhl(long double);

extern float atanhf(float);
extern double atanh(double);
extern long double atanhl(long double);

extern float coshf(float);
extern double cosh(double);
extern long double coshl(long double);

extern float sinhf(float);
extern double sinh(double);
extern long double sinhl(long double);

extern float tanhf(float);
extern double tanh(double);
extern long double tanhl(long double);

extern float expf(float);
extern double exp(double);
extern long double expl(long double);

extern float exp2f(float);
extern double exp2(double);
extern long double exp2l(long double);

extern float expm1f(float);
extern double expm1(double);
extern long double expm1l(long double);

extern float logf(float);
extern double log(double);
extern long double logl(long double);

extern float log10f(float);
extern double log10(double);
extern long double log10l(long double);

extern float log2f(float);
extern double log2(double);
extern long double log2l(long double);

extern float log1pf(float);
extern double log1p(double);
extern long double log1pl(long double);

extern float logbf(float);
extern double logb(double);
extern long double logbl(long double);

extern float modff(float, float *);
extern double modf(double, double *);
extern long double modfl(long double, long double *);

extern float ldexpf(float, int);
extern double ldexp(double, int);
extern long double ldexpl(long double, int);

extern float frexpf(float, int *);
extern double frexp(double, int *);
extern long double frexpl(long double, int *);

extern int ilogbf(float);
extern int ilogb(double);
extern int ilogbl(long double);

extern float scalbnf(float, int);
extern double scalbn(double, int);
extern long double scalbnl(long double, int);

extern float scalblnf(float, long int);
extern double scalbln(double, long int);
extern long double scalblnl(long double, long int);

extern float fabsf(float);
extern double fabs(double);
extern long double fabsl(long double);

extern float cbrtf(float);
extern double cbrt(double);
extern long double cbrtl(long double);

extern float hypotf(float, float);
extern double hypot(double, double);
extern long double hypotl(long double, long double);

extern float powf(float, float);
extern double pow(double, double);
extern long double powl(long double, long double);

extern float sqrtf(float);
extern double sqrt(double);
extern long double sqrtl(long double);

extern float erff(float);
extern double erf(double);
extern long double erfl(long double);

extern float erfcf(float);
extern double erfc(double);
extern long double erfcl(long double);




extern float lgammaf(float);
extern double lgamma(double);
extern long double lgammal(long double);

extern float tgammaf(float);
extern double tgamma(double);
extern long double tgammal(long double);

extern float ceilf(float);
extern double ceil(double);
extern long double ceill(long double);

extern float floorf(float);
extern double floor(double);
extern long double floorl(long double);

extern float nearbyintf(float);
extern double nearbyint(double);
extern long double nearbyintl(long double);

extern float rintf(float);
extern double rint(double);
extern long double rintl(long double);

extern long int lrintf(float);
extern long int lrint(double);
extern long int lrintl(long double);

extern float roundf(float);
extern double round(double);
extern long double roundl(long double);

extern long int lroundf(float);
extern long int lround(double);
extern long int lroundl(long double);




extern long long int llrintf(float);
extern long long int llrint(double);
extern long long int llrintl(long double);

extern long long int llroundf(float);
extern long long int llround(double);
extern long long int llroundl(long double);


extern float truncf(float);
extern double trunc(double);
extern long double truncl(long double);

extern float fmodf(float, float);
extern double fmod(double, double);
extern long double fmodl(long double, long double);

extern float remainderf(float, float);
extern double remainder(double, double);
extern long double remainderl(long double, long double);

extern float remquof(float, float, int *);
extern double remquo(double, double, int *);
extern long double remquol(long double, long double, int *);

extern float copysignf(float, float);
extern double copysign(double, double);
extern long double copysignl(long double, long double);

extern float nanf(const char *);
extern double nan(const char *);
extern long double nanl(const char *);

extern float nextafterf(float, float);
extern double nextafter(double, double);
extern long double nextafterl(long double, long double);

extern double nexttoward(double, long double);
extern float nexttowardf(float, long double);
extern long double nexttowardl(long double, long double);

extern float fdimf(float, float);
extern double fdim(double, double);
extern long double fdiml(long double, long double);

extern float fmaxf(float, float);
extern double fmax(double, double);
extern long double fmaxl(long double, long double);

extern float fminf(float, float);
extern double fmin(double, double);
extern long double fminl(long double, long double);

extern float fmaf(float, float, float);
extern double fma(double, double, double);
extern long double fmal(long double, long double, long double);
extern float __inff(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));
extern double __inf(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));
extern long double __infl(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern float __nan(void) __attribute__((availability(macosx,introduced=10.0)));
extern float __exp10f(float) __attribute__((availability(macosx,introduced=10.9)));
extern double __exp10(double) __attribute__((availability(macosx,introduced=10.9)));





inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp);
inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp);
extern float __cospif(float) __attribute__((availability(macosx,introduced=10.9)));
extern double __cospi(double) __attribute__((availability(macosx,introduced=10.9)));
extern float __sinpif(float) __attribute__((availability(macosx,introduced=10.9)));
extern double __sinpi(double) __attribute__((availability(macosx,introduced=10.9)));
extern float __tanpif(float) __attribute__((availability(macosx,introduced=10.9)));
extern double __tanpi(double) __attribute__((availability(macosx,introduced=10.9)));
inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp);
inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp);






struct __float2 { float __sinval; float __cosval; };
struct __double2 { double __sinval; double __cosval; };

extern struct __float2 __sincosf_stret(float);
extern struct __double2 __sincos_stret(double);
extern struct __float2 __sincospif_stret(float);
extern struct __double2 __sincospi_stret(double);

inline __attribute__ ((__always_inline__)) void __sincosf(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincosf_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincos(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincos_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincospif(float __x, float *__sinp, float *__cosp) {
    const struct __float2 __stret = __sincospif_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}

inline __attribute__ ((__always_inline__)) void __sincospi(double __x, double *__sinp, double *__cosp) {
    const struct __double2 __stret = __sincospi_stret(__x);
    *__sinp = __stret.__sinval; *__cosp = __stret.__cosval;
}







extern double j0(double) __attribute__((availability(macosx,introduced=10.0)));
extern double j1(double) __attribute__((availability(macosx,introduced=10.0)));
extern double jn(int, double) __attribute__((availability(macosx,introduced=10.0)));
extern double y0(double) __attribute__((availability(macosx,introduced=10.0)));
extern double y1(double) __attribute__((availability(macosx,introduced=10.0)));
extern double yn(int, double) __attribute__((availability(macosx,introduced=10.0)));
extern double scalb(double, double);
extern int signgam;
extern long int rinttol(double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern long int roundtol(double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern double drem(double, double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern int finite(double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern double gamma(double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));

extern double significand(double) __attribute__((availability(macosx,introduced=10.0,deprecated=10.9)));
}
typedef int jmp_buf[((9 * 2) + 3 + 16)];
typedef int sigjmp_buf[((9 * 2) + 3 + 16) + 1];
extern "C" {
extern int setjmp(jmp_buf);
extern void longjmp(jmp_buf, int) __attribute__((noreturn));


int _setjmp(jmp_buf);
void _longjmp(jmp_buf, int) __attribute__((noreturn));
int sigsetjmp(sigjmp_buf, int);
void siglongjmp(sigjmp_buf, int) __attribute__((noreturn));



void longjmperror(void);

}
extern const char *const sys_signame[32];
extern const char *const sys_siglist[32];


extern "C" {
int raise(int);
}


extern "C" {
void (*bsd_signal(int, void (*)(int)))(int);
int kill(pid_t, int) __asm("_" "kill" );
int killpg(pid_t, int) __asm("_" "killpg" );
int pthread_kill(pthread_t, int);
int pthread_sigmask(int, const sigset_t *, sigset_t *) __asm("_" "pthread_sigmask" );
int sigaction(int, const struct sigaction * ,
     struct sigaction * );
int sigaddset(sigset_t *, int);
int sigaltstack(const stack_t * , stack_t * ) __asm("_" "sigaltstack" ) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int sigdelset(sigset_t *, int);
int sigemptyset(sigset_t *);
int sigfillset(sigset_t *);
int sighold(int);
int sigignore(int);
int siginterrupt(int, int);
int sigismember(const sigset_t *, int);
int sigpause(int) __asm("_" "sigpause" );
int sigpending(sigset_t *);
int sigprocmask(int, const sigset_t * , sigset_t * );
int sigrelse(int);
void (*sigset(int, void (*)(int)))(int);
int sigsuspend(const sigset_t *) __asm("_" "sigsuspend" );
int sigwait(const sigset_t * , int * ) __asm("_" "sigwait" );

void psignal(unsigned int, const char *);
int sigblock(int);
int sigsetmask(int);
int sigvec(int, struct sigvec *, struct sigvec *);

}




inline __attribute__ ((__always_inline__)) int
__sigbits(int __signo)
{
    return __signo > 32 ? 0 : (1 << (__signo - 1));
}
typedef long int ptrdiff_t;
typedef __darwin_va_list va_list;



extern "C" {

int renameat(int, const char *, int, const char *) __attribute__((availability(macosx,introduced=10.10)));

}

typedef __darwin_off_t fpos_t;
struct __sbuf {
 unsigned char *_base;
 int _size;
};


struct __sFILEX;
typedef struct __sFILE {
 unsigned char *_p;
 int _r;
 int _w;
 short _flags;
 short _file;
 struct __sbuf _bf;
 int _lbfsize;


 void *_cookie;
 int (*_close)(void *);
 int (*_read) (void *, char *, int);
 fpos_t (*_seek) (void *, fpos_t, int);
 int (*_write)(void *, const char *, int);


 struct __sbuf _ub;
 struct __sFILEX *_extra;
 int _ur;


 unsigned char _ubuf[3];
 unsigned char _nbuf[1];


 struct __sbuf _lb;


 int _blksize;
 fpos_t _offset;
} FILE;

extern "C" {
extern FILE *__stdinp;
extern FILE *__stdoutp;
extern FILE *__stderrp;
}
extern "C" {
void clearerr(FILE *);
int fclose(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE * , fpos_t *);
char *fgets(char * , int, FILE *);



FILE *fopen(const char * , const char * ) __asm("_" "fopen" );

int fprintf(FILE * , const char * , ...) __attribute__((__format__ (__printf__, 2, 3)));
int fputc(int, FILE *);
int fputs(const char * , FILE * ) __asm("_" "fputs" );
size_t fread(void * , size_t, size_t, FILE * );
FILE *freopen(const char * , const char * ,
                 FILE * ) __asm("_" "freopen" );
int fscanf(FILE * , const char * , ...) __attribute__((__format__ (__scanf__, 2, 3)));
int fseek(FILE *, long, int);
int fsetpos(FILE *, const fpos_t *);
long ftell(FILE *);
size_t fwrite(const void * , size_t, size_t, FILE * ) __asm("_" "fwrite" );
int getc(FILE *);
int getchar(void);
char *gets(char *);
void perror(const char *);
int printf(const char * , ...) __attribute__((__format__ (__printf__, 1, 2)));
int putc(int, FILE *);
int putchar(int);
int puts(const char *);
int remove(const char *);
int rename (const char *, const char *);
void rewind(FILE *);
int scanf(const char * , ...) __attribute__((__format__ (__scanf__, 1, 2)));
void setbuf(FILE * , char * );
int setvbuf(FILE * , char * , int, size_t);
int sprintf(char * , const char * , ...) __attribute__((__format__ (__printf__, 2, 3)));
int sscanf(const char * , const char * , ...) __attribute__((__format__ (__scanf__, 2, 3)));
FILE *tmpfile(void);


__attribute__((deprecated("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tmpnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tmpnam(char *);
int ungetc(int, FILE *);
int vfprintf(FILE * , const char * , va_list) __attribute__((__format__ (__printf__, 2, 0)));
int vprintf(const char * , va_list) __attribute__((__format__ (__printf__, 1, 0)));
int vsprintf(char * , const char * , va_list) __attribute__((__format__ (__printf__, 2, 0)));
}
extern "C" {



char *ctermid(char *);





FILE *fdopen(int, const char *) __asm("_" "fdopen" );

int fileno(FILE *);
}
extern "C" {
int pclose(FILE *);



FILE *popen(const char *, const char *) __asm("_" "popen" );

}
extern "C" {
int __srget(FILE *);
int __svfscanf(FILE *, const char *, va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int __swbuf(int, FILE *);
}







inline __attribute__ ((__always_inline__)) int __sputc(int _c, FILE *_p) {
 if (--_p->_w >= 0 || (_p->_w >= _p->_lbfsize && (char)_c != '\n'))
  return (*_p->_p++ = _c);
 else
  return (__swbuf(_c, _p));
}
extern "C" {
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);



int getw(FILE *);
int putw(int, FILE *);



__attribute__((deprecated("This function is provided for compatibility reasons only.  Due to security concerns inherent in the design of tempnam(3), it is highly recommended that you use mkstemp(3) instead.")))

char *tempnam(const char *, const char *) __asm("_" "tempnam" );
}
extern "C" {
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
}



extern "C" {
int snprintf(char * , size_t, const char * , ...) __attribute__((__format__ (__printf__, 3, 4)));
int vfscanf(FILE * , const char * , va_list) __attribute__((__format__ (__scanf__, 2, 0)));
int vscanf(const char * , va_list) __attribute__((__format__ (__scanf__, 1, 0)));
int vsnprintf(char * , size_t, const char * , va_list) __attribute__((__format__ (__printf__, 3, 0)));
int vsscanf(const char * , const char * , va_list) __attribute__((__format__ (__scanf__, 2, 0)));
}
extern "C" {
int dprintf(int, const char * , ...) __attribute__((__format__ (__printf__, 2, 3))) __attribute__((availability(macosx,introduced=10.7)));
int vdprintf(int, const char * , va_list) __attribute__((__format__ (__printf__, 2, 0))) __attribute__((availability(macosx,introduced=10.7)));
ssize_t getdelim(char ** , size_t * , int, FILE * ) __attribute__((availability(macosx,introduced=10.7)));
ssize_t getline(char ** , size_t * , FILE * ) __attribute__((availability(macosx,introduced=10.7)));
}







extern "C" {
extern const int sys_nerr;
extern const char *const sys_errlist[];

int asprintf(char ** , const char * , ...) __attribute__((__format__ (__printf__, 2, 3)));
char *ctermid_r(char *);
char *fgetln(FILE *, size_t *);
const char *fmtcheck(const char *, const char *);
int fpurge(FILE *);
void setbuffer(FILE *, char *, int);
int setlinebuf(FILE *);
int vasprintf(char ** , const char * , va_list) __attribute__((__format__ (__printf__, 2, 0)));
FILE *zopen(const char *, const char *, int);





FILE *funopen(const void *,
                 int (*)(void *, char *, int),
                 int (*)(void *, const char *, int),
                 fpos_t (*)(void *, fpos_t, int),
                 int (*)(void *));
}

extern "C" {
void *memchr(const void *, int, size_t);
int memcmp(const void *, const void *, size_t);
void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *memset(void *, int, size_t);
char *strcat(char *, const char *);
char *strchr(const char *, int);
int strcmp(const char *, const char *);
int strcoll(const char *, const char *);
char *strcpy(char *, const char *);
size_t strcspn(const char *, const char *);
char *strerror(int) __asm("_" "strerror" );
size_t strlen(const char *);
char *strncat(char *, const char *, size_t);
int strncmp(const char *, const char *, size_t);
char *strncpy(char *, const char *, size_t);
char *strpbrk(const char *, const char *);
char *strrchr(const char *, int);
size_t strspn(const char *, const char *);
char *strstr(const char *, const char *);
char *strtok(char *, const char *);
size_t strxfrm(char *, const char *, size_t);
}
extern "C" {
char *strtok_r(char *, const char *, char **);
}
extern "C" {
int strerror_r(int, char *, size_t);
char *strdup(const char *);
void *memccpy(void *, const void *, int, size_t);
}
extern "C" {
char *stpcpy(char *, const char *);
char *stpncpy(char *, const char *, size_t) __attribute__((availability(macosx,introduced=10.7)));
char *strndup(const char *, size_t) __attribute__((availability(macosx,introduced=10.7)));
size_t strnlen(const char *, size_t) __attribute__((availability(macosx,introduced=10.7)));
char *strsignal(int sig);
}
extern "C" {
errno_t memset_s(void *, rsize_t, int, rsize_t) __attribute__((availability(macosx,introduced=10.9)));
}







extern "C" {
void *memmem(const void *, size_t, const void *, size_t) __attribute__((availability(macosx,introduced=10.7)));
void memset_pattern4(void *, const void *, size_t) __attribute__((availability(macosx,introduced=10.5)));
void memset_pattern8(void *, const void *, size_t) __attribute__((availability(macosx,introduced=10.5)));
void memset_pattern16(void *, const void *, size_t) __attribute__((availability(macosx,introduced=10.5)));

char *strcasestr(const char *, const char *);
char *strnstr(const char *, const char *, size_t);
size_t strlcat(char *, const char *, size_t);
size_t strlcpy(char *, const char *, size_t);
void strmode(int, char *);
char *strsep(char **, const char *);


void swab(const void * , void * , ssize_t);
}







extern "C" {


int bcmp(const void *, const void *, size_t) ;
void bcopy(const void *, void *, size_t) ;
void bzero(void *, size_t) ;
char *index(const char *, int) ;
char *rindex(const char *, int) ;


int ffs(int);
int strcasecmp(const char *, const char *);
int strncasecmp(const char *, const char *, size_t);
}



extern "C" {
int ffsl(long) __attribute__((availability(macosx,introduced=10.5)));
int ffsll(long long) __attribute__((availability(macosx,introduced=10.9)));
int fls(int) __attribute__((availability(macosx,introduced=10.5)));
int flsl(long) __attribute__((availability(macosx,introduced=10.5)));
int flsll(long long) __attribute__((availability(macosx,introduced=10.9)));
}


struct timespec
{
 __darwin_time_t tv_sec;
 long tv_nsec;
};

struct tm {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
 long tm_gmtoff;
 char *tm_zone;
};
extern char *tzname[];


extern int getdate_err;

extern long timezone __asm("_" "timezone" );

extern int daylight;

extern "C" {
char *asctime(const struct tm *);
clock_t clock(void) __asm("_" "clock" );
char *ctime(const time_t *);
double difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *localtime(const time_t *);
time_t mktime(struct tm *) __asm("_" "mktime" );
size_t strftime(char * , size_t, const char * , const struct tm * ) __asm("_" "strftime" );
char *strptime(const char * , const char * , struct tm * ) __asm("_" "strptime" );
time_t time(time_t *);


void tzset(void);



char *asctime_r(const struct tm * , char * );
char *ctime_r(const time_t *, char *);
struct tm *gmtime_r(const time_t * , struct tm * );
struct tm *localtime_r(const time_t * , struct tm * );


time_t posix2time(time_t);



void tzsetwall(void);
time_t time2posix(time_t);
time_t timelocal(struct tm * const);
time_t timegm(struct tm * const);



int nanosleep(const struct timespec *, struct timespec *) __asm("_" "nanosleep" );

}










extern "C" {





extern "C" void *_Block_copy(const void *aBlock)
    __attribute__((availability(macosx,introduced=10.6)));


extern "C" void _Block_release(const void *aBlock)
    __attribute__((availability(macosx,introduced=10.6)));



extern "C" void _Block_object_assign(void *, const void *, const int)
    __attribute__((availability(macosx,introduced=10.6)));


extern "C" void _Block_object_dispose(const void *, const int)
    __attribute__((availability(macosx,introduced=10.6)));


extern "C" void * _NSConcreteGlobalBlock[32]
    __attribute__((availability(macosx,introduced=10.6)));
extern "C" void * _NSConcreteStackBlock[32]
    __attribute__((availability(macosx,introduced=10.6)));



}




extern "C" {


#pragma pack(push, 2)
typedef unsigned char UInt8;
typedef signed char SInt8;
typedef unsigned short UInt16;
typedef signed short SInt16;


typedef unsigned int UInt32;
typedef signed int SInt32;
struct wide {
  UInt32 lo;
  SInt32 hi;
};
typedef struct wide wide;
struct UnsignedWide {
  UInt32 lo;
  UInt32 hi;
};
typedef struct UnsignedWide UnsignedWide;
      typedef signed long long SInt64;
        typedef unsigned long long UInt64;
typedef SInt32 Fixed;
typedef Fixed * FixedPtr;
typedef SInt32 Fract;
typedef Fract * FractPtr;
typedef UInt32 UnsignedFixed;
typedef UnsignedFixed * UnsignedFixedPtr;
typedef short ShortFixed;
typedef ShortFixed * ShortFixedPtr;
typedef float Float32;
typedef double Float64;
struct Float80 {
    SInt16 exp;
    UInt16 man[4];
};
typedef struct Float80 Float80;

struct Float96 {
    SInt16 exp[2];
    UInt16 man[4];
};
typedef struct Float96 Float96;
struct Float32Point {
    Float32 x;
    Float32 y;
};
typedef struct Float32Point Float32Point;
typedef char * Ptr;
typedef Ptr * Handle;
typedef long Size;
typedef SInt16 OSErr;
typedef SInt32 OSStatus;
typedef void * LogicalAddress;
typedef const void * ConstLogicalAddress;
typedef void * PhysicalAddress;
typedef UInt8 * BytePtr;
typedef unsigned long ByteCount;
typedef unsigned long ByteOffset;
typedef SInt32 Duration;
typedef UnsignedWide AbsoluteTime;
typedef UInt32 OptionBits;
typedef unsigned long ItemCount;
typedef UInt32 PBVersion;
typedef SInt16 ScriptCode;
typedef SInt16 LangCode;
typedef SInt16 RegionCode;
typedef UInt32 FourCharCode;
typedef FourCharCode OSType;
typedef FourCharCode ResType;
typedef OSType * OSTypePtr;
typedef ResType * ResTypePtr;
typedef unsigned char Boolean;
typedef long ( * ProcPtr)();
typedef void ( * Register68kProcPtr)();




typedef ProcPtr UniversalProcPtr;


typedef ProcPtr * ProcHandle;
typedef UniversalProcPtr * UniversalProcHandle;
typedef void * PRefCon;

typedef void * URefCon;
typedef void * SRefCon;
enum {
  noErr = 0
};

enum {
  kNilOptions = 0
};


enum {
  kVariableLengthArray


  __attribute__((deprecated))


  = 1
};

enum {
  kUnknownType = 0x3F3F3F3F
};
typedef UInt32 UnicodeScalarValue;
typedef UInt32 UTF32Char;
typedef UInt16 UniChar;
typedef UInt16 UTF16Char;
typedef UInt8 UTF8Char;
typedef UniChar * UniCharPtr;
typedef unsigned long UniCharCount;
typedef UniCharCount * UniCharCountPtr;
typedef unsigned char Str255[256];
typedef unsigned char Str63[64];
typedef unsigned char Str32[33];
typedef unsigned char Str31[32];
typedef unsigned char Str27[28];
typedef unsigned char Str15[16];
typedef unsigned char Str32Field[34];
typedef Str63 StrFileName;
typedef unsigned char * StringPtr;
typedef StringPtr * StringHandle;
typedef const unsigned char * ConstStringPtr;
typedef const unsigned char * ConstStr255Param;
typedef const unsigned char * ConstStr63Param;
typedef const unsigned char * ConstStr32Param;
typedef const unsigned char * ConstStr31Param;
typedef const unsigned char * ConstStr27Param;
typedef const unsigned char * ConstStr15Param;
typedef ConstStr63Param ConstStrFileNameParam;

inline unsigned char StrLength(ConstStr255Param string) { return (*string); }
struct ProcessSerialNumber {
  UInt32 highLongOfPSN;
  UInt32 lowLongOfPSN;
};
typedef struct ProcessSerialNumber ProcessSerialNumber;
typedef ProcessSerialNumber * ProcessSerialNumberPtr;
struct Point {
  short v;
  short h;
};
typedef struct Point Point;
typedef Point * PointPtr;
struct Rect {
  short top;
  short left;
  short bottom;
  short right;
};
typedef struct Rect Rect;
typedef Rect * RectPtr;
struct FixedPoint {
  Fixed x;
  Fixed y;
};
typedef struct FixedPoint FixedPoint;
struct FixedRect {
  Fixed left;
  Fixed top;
  Fixed right;
  Fixed bottom;
};
typedef struct FixedRect FixedRect;

typedef short CharParameter;
enum {
  normal = 0,
  bold = 1,
  italic = 2,
  underline = 4,
  outline = 8,
  shadow = 0x10,
  condense = 0x20,
  extend = 0x40
};

typedef unsigned char Style;
typedef short StyleParameter;
typedef Style StyleField;
typedef SInt32 TimeValue;
typedef SInt32 TimeScale;
typedef wide CompTimeValue;
typedef SInt64 TimeValue64;
typedef struct TimeBaseRecord* TimeBase;
struct TimeRecord {
  CompTimeValue value;
  TimeScale scale;
  TimeBase base;
};
typedef struct TimeRecord TimeRecord;
struct NumVersion {

  UInt8 nonRelRev;
  UInt8 stage;
  UInt8 minorAndBugRev;
  UInt8 majorRev;
};
typedef struct NumVersion NumVersion;


enum {

  developStage = 0x20,
  alphaStage = 0x40,
  betaStage = 0x60,
  finalStage = 0x80
};

union NumVersionVariant {

  NumVersion parts;
  UInt32 whole;
};
typedef union NumVersionVariant NumVersionVariant;
typedef NumVersionVariant * NumVersionVariantPtr;
typedef NumVersionVariantPtr * NumVersionVariantHandle;
struct VersRec {

  NumVersion numericVersion;
  short countryCode;
  Str255 shortVersion;
  Str255 reserved;
};
typedef struct VersRec VersRec;
typedef VersRec * VersRecPtr;
typedef VersRecPtr * VersRecHndl;





typedef UInt8 Byte;
typedef SInt8 SignedByte;
typedef wide * WidePtr;
typedef UnsignedWide * UnsignedWidePtr;
typedef Float80 extended80;
typedef Float96 extended96;
typedef SInt8 VHSelect;
extern void
Debugger(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
extern void
DebugStr(ConstStr255Param debuggerMsg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
extern void
SysBreak(void) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
extern void
SysBreakStr(ConstStr255Param debuggerMsg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
extern void
SysBreakFunc(ConstStr255Param debuggerMsg) __attribute__((availability(macosx,introduced=10.0,deprecated=10.8)));
#pragma pack(pop)


}
extern "C" {
// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

// @class NSAttributedString;
#ifndef _REWRITER_typedef_NSAttributedString
#define _REWRITER_typedef_NSAttributedString
typedef struct objc_object NSAttributedString;
typedef struct {} _objc_exc_NSAttributedString;
#endif

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @class NSNull;
#ifndef _REWRITER_typedef_NSNull
#define _REWRITER_typedef_NSNull
typedef struct objc_object NSNull;
typedef struct {} _objc_exc_NSNull;
#endif

// @class NSCharacterSet;
#ifndef _REWRITER_typedef_NSCharacterSet
#define _REWRITER_typedef_NSCharacterSet
typedef struct objc_object NSCharacterSet;
typedef struct {} _objc_exc_NSCharacterSet;
#endif

// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

// @class NSDate;
#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

// @class NSTimeZone;
#ifndef _REWRITER_typedef_NSTimeZone
#define _REWRITER_typedef_NSTimeZone
typedef struct objc_object NSTimeZone;
typedef struct {} _objc_exc_NSTimeZone;
#endif

// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

// @class NSError;
#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

// @class NSLocale;
#ifndef _REWRITER_typedef_NSLocale
#define _REWRITER_typedef_NSLocale
typedef struct objc_object NSLocale;
typedef struct {} _objc_exc_NSLocale;
#endif

// @class NSNumber;
#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
typedef struct objc_object NSNumber;
typedef struct {} _objc_exc_NSNumber;
#endif

// @class NSSet;
#ifndef _REWRITER_typedef_NSSet
#define _REWRITER_typedef_NSSet
typedef struct objc_object NSSet;
typedef struct {} _objc_exc_NSSet;
#endif

// @class NSURL;
#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

extern double kCFCoreFoundationVersionNumber;
typedef unsigned long CFTypeID;
typedef unsigned long CFOptionFlags;
typedef unsigned long CFHashCode;
typedef signed long CFIndex;



typedef const __attribute__((objc_bridge(id))) void * CFTypeRef;

typedef const struct __attribute__((objc_bridge(NSString))) __CFString * CFStringRef;
typedef struct __attribute__((objc_bridge_mutable(NSMutableString))) __CFString * CFMutableStringRef;






typedef __attribute__((objc_bridge(id))) CFTypeRef CFPropertyListRef;


typedef CFIndex CFComparisonResult; enum {
    kCFCompareLessThan = -1L,
    kCFCompareEqualTo = 0,
    kCFCompareGreaterThan = 1
};


typedef CFComparisonResult (*CFComparatorFunction)(const void *val1, const void *val2, void *context);


static const CFIndex kCFNotFound = -1;



typedef struct {
    CFIndex location;
    CFIndex length;
} CFRange;


static __inline__ __attribute__((always_inline)) CFRange CFRangeMake(CFIndex loc, CFIndex len) {
    CFRange range;
    range.location = loc;
    range.length = len;
    return range;
}





extern
CFRange __CFRangeMake(CFIndex loc, CFIndex len);




typedef const struct __attribute__((objc_bridge(NSNull))) __CFNull * CFNullRef;

extern
CFTypeID CFNullGetTypeID(void);

extern
const CFNullRef kCFNull;
typedef const struct __attribute__((objc_bridge(id))) __CFAllocator * CFAllocatorRef;


extern
const CFAllocatorRef kCFAllocatorDefault;


extern
const CFAllocatorRef kCFAllocatorSystemDefault;







extern
const CFAllocatorRef kCFAllocatorMalloc;





extern
const CFAllocatorRef kCFAllocatorMallocZone;





extern
const CFAllocatorRef kCFAllocatorNull;





extern
const CFAllocatorRef kCFAllocatorUseContext;

typedef const void * (*CFAllocatorRetainCallBack)(const void *info);
typedef void (*CFAllocatorReleaseCallBack)(const void *info);
typedef CFStringRef (*CFAllocatorCopyDescriptionCallBack)(const void *info);
typedef void * (*CFAllocatorAllocateCallBack)(CFIndex allocSize, CFOptionFlags hint, void *info);
typedef void * (*CFAllocatorReallocateCallBack)(void *ptr, CFIndex newsize, CFOptionFlags hint, void *info);
typedef void (*CFAllocatorDeallocateCallBack)(void *ptr, void *info);
typedef CFIndex (*CFAllocatorPreferredSizeCallBack)(CFIndex size, CFOptionFlags hint, void *info);
typedef struct {
    CFIndex version;
    void * info;
    CFAllocatorRetainCallBack retain;
    CFAllocatorReleaseCallBack release;
    CFAllocatorCopyDescriptionCallBack copyDescription;
    CFAllocatorAllocateCallBack allocate;
    CFAllocatorReallocateCallBack reallocate;
    CFAllocatorDeallocateCallBack deallocate;
    CFAllocatorPreferredSizeCallBack preferredSize;
} CFAllocatorContext;

extern
CFTypeID CFAllocatorGetTypeID(void);
extern
void CFAllocatorSetDefault(CFAllocatorRef allocator);

extern
CFAllocatorRef CFAllocatorGetDefault(void);

extern
CFAllocatorRef CFAllocatorCreate(CFAllocatorRef allocator, CFAllocatorContext *context);

extern
void *CFAllocatorAllocate(CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);

extern
void *CFAllocatorReallocate(CFAllocatorRef allocator, void *ptr, CFIndex newsize, CFOptionFlags hint);

extern
void CFAllocatorDeallocate(CFAllocatorRef allocator, void *ptr);

extern
CFIndex CFAllocatorGetPreferredSizeForSize(CFAllocatorRef allocator, CFIndex size, CFOptionFlags hint);

extern
void CFAllocatorGetContext(CFAllocatorRef allocator, CFAllocatorContext *context);






extern
CFTypeID CFGetTypeID(CFTypeRef cf);

extern
CFStringRef CFCopyTypeIDDescription(CFTypeID type_id);

extern
CFTypeRef CFRetain(CFTypeRef cf);

extern
void CFRelease(CFTypeRef cf);

extern
CFTypeRef CFAutorelease(CFTypeRef __attribute__((cf_consumed)) arg) __attribute__((availability(ios,introduced=7_0)));

extern
CFIndex CFGetRetainCount(CFTypeRef cf);

extern
Boolean CFEqual(CFTypeRef cf1, CFTypeRef cf2);

extern
CFHashCode CFHash(CFTypeRef cf);

extern
CFStringRef CFCopyDescription(CFTypeRef cf);

extern
CFAllocatorRef CFGetAllocator(CFTypeRef cf);




extern
CFTypeRef CFMakeCollectable(CFTypeRef cf) __attribute__((unavailable("not available in automatic reference counting mode")));

}
extern "C" {
typedef const void * (*CFArrayRetainCallBack)(CFAllocatorRef allocator, const void *value);
typedef void (*CFArrayReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef CFStringRef (*CFArrayCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFArrayEqualCallBack)(const void *value1, const void *value2);
typedef struct {
    CFIndex version;
    CFArrayRetainCallBack retain;
    CFArrayReleaseCallBack release;
    CFArrayCopyDescriptionCallBack copyDescription;
    CFArrayEqualCallBack equal;
} CFArrayCallBacks;






extern
const CFArrayCallBacks kCFTypeArrayCallBacks;
typedef void (*CFArrayApplierFunction)(const void *value, void *context);





typedef const struct __attribute__((objc_bridge(NSArray))) __CFArray * CFArrayRef;





typedef struct __attribute__((objc_bridge_mutable(NSMutableArray))) __CFArray * CFMutableArrayRef;





extern
CFTypeID CFArrayGetTypeID(void);
extern
CFArrayRef CFArrayCreate(CFAllocatorRef allocator, const void **values, CFIndex numValues, const CFArrayCallBacks *callBacks);
extern
CFArrayRef CFArrayCreateCopy(CFAllocatorRef allocator, CFArrayRef theArray);
extern
CFMutableArrayRef CFArrayCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFArrayCallBacks *callBacks);
extern
CFMutableArrayRef CFArrayCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFArrayRef theArray);
extern
CFIndex CFArrayGetCount(CFArrayRef theArray);
extern
CFIndex CFArrayGetCountOfValue(CFArrayRef theArray, CFRange range, const void *value);
extern
Boolean CFArrayContainsValue(CFArrayRef theArray, CFRange range, const void *value);
extern
const void *CFArrayGetValueAtIndex(CFArrayRef theArray, CFIndex idx);
extern
void CFArrayGetValues(CFArrayRef theArray, CFRange range, const void **values);
extern
void CFArrayApplyFunction(CFArrayRef theArray, CFRange range, CFArrayApplierFunction applier, void *context);
extern
CFIndex CFArrayGetFirstIndexOfValue(CFArrayRef theArray, CFRange range, const void *value);
extern
CFIndex CFArrayGetLastIndexOfValue(CFArrayRef theArray, CFRange range, const void *value);
extern
CFIndex CFArrayBSearchValues(CFArrayRef theArray, CFRange range, const void *value, CFComparatorFunction comparator, void *context);
extern
void CFArrayAppendValue(CFMutableArrayRef theArray, const void *value);
extern
void CFArrayInsertValueAtIndex(CFMutableArrayRef theArray, CFIndex idx, const void *value);
extern
void CFArraySetValueAtIndex(CFMutableArrayRef theArray, CFIndex idx, const void *value);
extern
void CFArrayRemoveValueAtIndex(CFMutableArrayRef theArray, CFIndex idx);
extern
void CFArrayRemoveAllValues(CFMutableArrayRef theArray);
extern
void CFArrayReplaceValues(CFMutableArrayRef theArray, CFRange range, const void **newValues, CFIndex newCount);
extern
void CFArrayExchangeValuesAtIndices(CFMutableArrayRef theArray, CFIndex idx1, CFIndex idx2);
extern
void CFArraySortValues(CFMutableArrayRef theArray, CFRange range, CFComparatorFunction comparator, void *context);
extern
void CFArrayAppendArray(CFMutableArrayRef theArray, CFArrayRef otherArray, CFRange otherRange);

}
extern "C" {

typedef const void * (*CFBagRetainCallBack)(CFAllocatorRef allocator, const void *value);
typedef void (*CFBagReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef CFStringRef (*CFBagCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFBagEqualCallBack)(const void *value1, const void *value2);
typedef CFHashCode (*CFBagHashCallBack)(const void *value);
typedef struct {
    CFIndex version;
    CFBagRetainCallBack retain;
    CFBagReleaseCallBack release;
    CFBagCopyDescriptionCallBack copyDescription;
    CFBagEqualCallBack equal;
    CFBagHashCallBack hash;
} CFBagCallBacks;

extern
const CFBagCallBacks kCFTypeBagCallBacks;
extern
const CFBagCallBacks kCFCopyStringBagCallBacks;

typedef void (*CFBagApplierFunction)(const void *value, void *context);

typedef const struct __attribute__((objc_bridge(id))) __CFBag * CFBagRef;
typedef struct __attribute__((objc_bridge_mutable(id))) __CFBag * CFMutableBagRef;

extern
CFTypeID CFBagGetTypeID(void);

extern
CFBagRef CFBagCreate(CFAllocatorRef allocator, const void **values, CFIndex numValues, const CFBagCallBacks *callBacks);

extern
CFBagRef CFBagCreateCopy(CFAllocatorRef allocator, CFBagRef theBag);

extern
CFMutableBagRef CFBagCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFBagCallBacks *callBacks);

extern
CFMutableBagRef CFBagCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFBagRef theBag);

extern
CFIndex CFBagGetCount(CFBagRef theBag);

extern
CFIndex CFBagGetCountOfValue(CFBagRef theBag, const void *value);

extern
Boolean CFBagContainsValue(CFBagRef theBag, const void *value);

extern
const void *CFBagGetValue(CFBagRef theBag, const void *value);

extern
Boolean CFBagGetValueIfPresent(CFBagRef theBag, const void *candidate, const void **value);

extern
void CFBagGetValues(CFBagRef theBag, const void **values);

extern
void CFBagApplyFunction(CFBagRef theBag, CFBagApplierFunction applier, void *context);

extern
void CFBagAddValue(CFMutableBagRef theBag, const void *value);

extern
void CFBagReplaceValue(CFMutableBagRef theBag, const void *value);

extern
void CFBagSetValue(CFMutableBagRef theBag, const void *value);

extern
void CFBagRemoveValue(CFMutableBagRef theBag, const void *value);

extern
void CFBagRemoveAllValues(CFMutableBagRef theBag);

}
extern "C" {

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFBinaryHeapCompareContext;
typedef struct {
    CFIndex version;
    const void *(*retain)(CFAllocatorRef allocator, const void *ptr);
    void (*release)(CFAllocatorRef allocator, const void *ptr);
    CFStringRef (*copyDescription)(const void *ptr);
    CFComparisonResult (*compare)(const void *ptr1, const void *ptr2, void *context);
} CFBinaryHeapCallBacks;







extern const CFBinaryHeapCallBacks kCFStringBinaryHeapCallBacks;
typedef void (*CFBinaryHeapApplierFunction)(const void *val, void *context);





typedef struct __attribute__((objc_bridge_mutable(id))) __CFBinaryHeap * CFBinaryHeapRef;





extern CFTypeID CFBinaryHeapGetTypeID(void);
extern CFBinaryHeapRef CFBinaryHeapCreate(CFAllocatorRef allocator, CFIndex capacity, const CFBinaryHeapCallBacks *callBacks, const CFBinaryHeapCompareContext *compareContext);
extern CFBinaryHeapRef CFBinaryHeapCreateCopy(CFAllocatorRef allocator, CFIndex capacity, CFBinaryHeapRef heap);
extern CFIndex CFBinaryHeapGetCount(CFBinaryHeapRef heap);
extern CFIndex CFBinaryHeapGetCountOfValue(CFBinaryHeapRef heap, const void *value);
extern Boolean CFBinaryHeapContainsValue(CFBinaryHeapRef heap, const void *value);
extern const void * CFBinaryHeapGetMinimum(CFBinaryHeapRef heap);
extern Boolean CFBinaryHeapGetMinimumIfPresent(CFBinaryHeapRef heap, const void **value);
extern void CFBinaryHeapGetValues(CFBinaryHeapRef heap, const void **values);
extern void CFBinaryHeapApplyFunction(CFBinaryHeapRef heap, CFBinaryHeapApplierFunction applier, void *context);
extern void CFBinaryHeapAddValue(CFBinaryHeapRef heap, const void *value);







extern void CFBinaryHeapRemoveMinimumValue(CFBinaryHeapRef heap);
extern void CFBinaryHeapRemoveAllValues(CFBinaryHeapRef heap);

}
extern "C" {

typedef UInt32 CFBit;

typedef const struct __attribute__((objc_bridge(id))) __CFBitVector * CFBitVectorRef;
typedef struct __attribute__((objc_bridge_mutable(id))) __CFBitVector * CFMutableBitVectorRef;

extern CFTypeID CFBitVectorGetTypeID(void);

extern CFBitVectorRef CFBitVectorCreate(CFAllocatorRef allocator, const UInt8 *bytes, CFIndex numBits);
extern CFBitVectorRef CFBitVectorCreateCopy(CFAllocatorRef allocator, CFBitVectorRef bv);
extern CFMutableBitVectorRef CFBitVectorCreateMutable(CFAllocatorRef allocator, CFIndex capacity);
extern CFMutableBitVectorRef CFBitVectorCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFBitVectorRef bv);

extern CFIndex CFBitVectorGetCount(CFBitVectorRef bv);
extern CFIndex CFBitVectorGetCountOfBit(CFBitVectorRef bv, CFRange range, CFBit value);
extern Boolean CFBitVectorContainsBit(CFBitVectorRef bv, CFRange range, CFBit value);
extern CFBit CFBitVectorGetBitAtIndex(CFBitVectorRef bv, CFIndex idx);
extern void CFBitVectorGetBits(CFBitVectorRef bv, CFRange range, UInt8 *bytes);
extern CFIndex CFBitVectorGetFirstIndexOfBit(CFBitVectorRef bv, CFRange range, CFBit value);
extern CFIndex CFBitVectorGetLastIndexOfBit(CFBitVectorRef bv, CFRange range, CFBit value);

extern void CFBitVectorSetCount(CFMutableBitVectorRef bv, CFIndex count);
extern void CFBitVectorFlipBitAtIndex(CFMutableBitVectorRef bv, CFIndex idx);
extern void CFBitVectorFlipBits(CFMutableBitVectorRef bv, CFRange range);
extern void CFBitVectorSetBitAtIndex(CFMutableBitVectorRef bv, CFIndex idx, CFBit value);
extern void CFBitVectorSetBits(CFMutableBitVectorRef bv, CFRange range, CFBit value);
extern void CFBitVectorSetAllBits(CFMutableBitVectorRef bv, CFBit value);

}



static __inline__
uint16_t
OSReadSwapInt16(
    const volatile void * base,
    uintptr_t byteOffset
)
{
    uint16_t result;

    result = *(volatile uint16_t *)((uintptr_t)base + byteOffset);
    return _OSSwapInt16(result);
}

static __inline__
uint32_t
OSReadSwapInt32(
    const volatile void * base,
    uintptr_t byteOffset
)
{
    uint32_t result;

    result = *(volatile uint32_t *)((uintptr_t)base + byteOffset);
    return _OSSwapInt32(result);
}

static __inline__
uint64_t
OSReadSwapInt64(
    const volatile void * base,
    uintptr_t byteOffset
)
{
    uint64_t result;

    result = *(volatile uint64_t *)((uintptr_t)base + byteOffset);
    return _OSSwapInt64(result);
}



static __inline__
void
OSWriteSwapInt16(
    volatile void * base,
    uintptr_t byteOffset,
    uint16_t data
)
{
    *(volatile uint16_t *)((uintptr_t)base + byteOffset) = _OSSwapInt16(data);
}

static __inline__
void
OSWriteSwapInt32(
    volatile void * base,
    uintptr_t byteOffset,
    uint32_t data
)
{
    *(volatile uint32_t *)((uintptr_t)base + byteOffset) = _OSSwapInt32(data);
}

static __inline__
void
OSWriteSwapInt64(
    volatile void * base,
    uintptr_t byteOffset,
    uint64_t data
)
{
    *(volatile uint64_t *)((uintptr_t)base + byteOffset) = _OSSwapInt64(data);
}
enum {
    OSUnknownByteOrder,
    OSLittleEndian,
    OSBigEndian
};

static __inline__
int32_t
OSHostByteOrder(void) {

    return OSLittleEndian;





}
static __inline__
uint16_t
_OSReadInt16(
    const volatile void * base,
    uintptr_t byteOffset
)
{
    return *(volatile uint16_t *)((uintptr_t)base + byteOffset);
}

static __inline__
uint32_t
_OSReadInt32(
    const volatile void * base,
    uintptr_t byteOffset
)
{
    return *(volatile uint32_t *)((uintptr_t)base + byteOffset);
}

static __inline__
uint64_t
_OSReadInt64(
    const volatile void * base,
    uintptr_t byteOffset
)
{
    return *(volatile uint64_t *)((uintptr_t)base + byteOffset);
}



static __inline__
void
_OSWriteInt16(
    volatile void * base,
    uintptr_t byteOffset,
    uint16_t data
)
{
    *(volatile uint16_t *)((uintptr_t)base + byteOffset) = data;
}

static __inline__
void
_OSWriteInt32(
    volatile void * base,
    uintptr_t byteOffset,
    uint32_t data
)
{
    *(volatile uint32_t *)((uintptr_t)base + byteOffset) = data;
}

static __inline__
void
_OSWriteInt64(
    volatile void * base,
    uintptr_t byteOffset,
    uint64_t data
)
{
    *(volatile uint64_t *)((uintptr_t)base + byteOffset) = data;
}



extern "C" {

enum __CFByteOrder {
    CFByteOrderUnknown,
    CFByteOrderLittleEndian,
    CFByteOrderBigEndian
};
typedef CFIndex CFByteOrder;

static __inline__ __attribute__((always_inline)) CFByteOrder CFByteOrderGetCurrent(void) {

    int32_t byteOrder = OSHostByteOrder();
    switch (byteOrder) {
    case OSLittleEndian: return CFByteOrderLittleEndian;
    case OSBigEndian: return CFByteOrderBigEndian;
    default: break;
    }
    return CFByteOrderUnknown;
}

static __inline__ __attribute__((always_inline)) uint16_t CFSwapInt16(uint16_t arg) {

    return ((__uint16_t)(__builtin_constant_p(arg) ? ((__uint16_t)((((__uint16_t)(arg) & 0xff00) >> 8) | (((__uint16_t)(arg) & 0x00ff) << 8))) : _OSSwapInt16(arg)));





}

static __inline__ __attribute__((always_inline)) uint32_t CFSwapInt32(uint32_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint32_t)((((__uint32_t)(arg) & 0xff000000) >> 24) | (((__uint32_t)(arg) & 0x00ff0000) >> 8) | (((__uint32_t)(arg) & 0x0000ff00) << 8) | (((__uint32_t)(arg) & 0x000000ff) << 24))) : _OSSwapInt32(arg));





}

static __inline__ __attribute__((always_inline)) uint64_t CFSwapInt64(uint64_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint64_t)((((__uint64_t)(arg) & 0xff00000000000000ULL) >> 56) | (((__uint64_t)(arg) & 0x00ff000000000000ULL) >> 40) | (((__uint64_t)(arg) & 0x0000ff0000000000ULL) >> 24) | (((__uint64_t)(arg) & 0x000000ff00000000ULL) >> 8) | (((__uint64_t)(arg) & 0x00000000ff000000ULL) << 8) | (((__uint64_t)(arg) & 0x0000000000ff0000ULL) << 24) | (((__uint64_t)(arg) & 0x000000000000ff00ULL) << 40) | (((__uint64_t)(arg) & 0x00000000000000ffULL) << 56))) : _OSSwapInt64(arg));
}

static __inline__ __attribute__((always_inline)) uint16_t CFSwapInt16BigToHost(uint16_t arg) {

    return ((__uint16_t)(__builtin_constant_p(arg) ? ((__uint16_t)((((__uint16_t)(arg) & 0xff00) >> 8) | (((__uint16_t)(arg) & 0x00ff) << 8))) : _OSSwapInt16(arg)));





}

static __inline__ __attribute__((always_inline)) uint32_t CFSwapInt32BigToHost(uint32_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint32_t)((((__uint32_t)(arg) & 0xff000000) >> 24) | (((__uint32_t)(arg) & 0x00ff0000) >> 8) | (((__uint32_t)(arg) & 0x0000ff00) << 8) | (((__uint32_t)(arg) & 0x000000ff) << 24))) : _OSSwapInt32(arg));





}

static __inline__ __attribute__((always_inline)) uint64_t CFSwapInt64BigToHost(uint64_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint64_t)((((__uint64_t)(arg) & 0xff00000000000000ULL) >> 56) | (((__uint64_t)(arg) & 0x00ff000000000000ULL) >> 40) | (((__uint64_t)(arg) & 0x0000ff0000000000ULL) >> 24) | (((__uint64_t)(arg) & 0x000000ff00000000ULL) >> 8) | (((__uint64_t)(arg) & 0x00000000ff000000ULL) << 8) | (((__uint64_t)(arg) & 0x0000000000ff0000ULL) << 24) | (((__uint64_t)(arg) & 0x000000000000ff00ULL) << 40) | (((__uint64_t)(arg) & 0x00000000000000ffULL) << 56))) : _OSSwapInt64(arg));





}

static __inline__ __attribute__((always_inline)) uint16_t CFSwapInt16HostToBig(uint16_t arg) {

    return ((__uint16_t)(__builtin_constant_p(arg) ? ((__uint16_t)((((__uint16_t)(arg) & 0xff00) >> 8) | (((__uint16_t)(arg) & 0x00ff) << 8))) : _OSSwapInt16(arg)));





}

static __inline__ __attribute__((always_inline)) uint32_t CFSwapInt32HostToBig(uint32_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint32_t)((((__uint32_t)(arg) & 0xff000000) >> 24) | (((__uint32_t)(arg) & 0x00ff0000) >> 8) | (((__uint32_t)(arg) & 0x0000ff00) << 8) | (((__uint32_t)(arg) & 0x000000ff) << 24))) : _OSSwapInt32(arg));





}

static __inline__ __attribute__((always_inline)) uint64_t CFSwapInt64HostToBig(uint64_t arg) {

    return (__builtin_constant_p(arg) ? ((__uint64_t)((((__uint64_t)(arg) & 0xff00000000000000ULL) >> 56) | (((__uint64_t)(arg) & 0x00ff000000000000ULL) >> 40) | (((__uint64_t)(arg) & 0x0000ff0000000000ULL) >> 24) | (((__uint64_t)(arg) & 0x000000ff00000000ULL) >> 8) | (((__uint64_t)(arg) & 0x00000000ff000000ULL) << 8) | (((__uint64_t)(arg) & 0x0000000000ff0000ULL) << 24) | (((__uint64_t)(arg) & 0x000000000000ff00ULL) << 40) | (((__uint64_t)(arg) & 0x00000000000000ffULL) << 56))) : _OSSwapInt64(arg));





}

static __inline__ __attribute__((always_inline)) uint16_t CFSwapInt16LittleToHost(uint16_t arg) {

    return ((uint16_t)(arg));





}

static __inline__ __attribute__((always_inline)) uint32_t CFSwapInt32LittleToHost(uint32_t arg) {

    return ((uint32_t)(arg));





}

static __inline__ __attribute__((always_inline)) uint64_t CFSwapInt64LittleToHost(uint64_t arg) {

    return ((uint64_t)(arg));





}

static __inline__ __attribute__((always_inline)) uint16_t CFSwapInt16HostToLittle(uint16_t arg) {

    return ((uint16_t)(arg));





}

static __inline__ __attribute__((always_inline)) uint32_t CFSwapInt32HostToLittle(uint32_t arg) {

    return ((uint32_t)(arg));





}

static __inline__ __attribute__((always_inline)) uint64_t CFSwapInt64HostToLittle(uint64_t arg) {

    return ((uint64_t)(arg));





}

typedef struct {uint32_t v;} CFSwappedFloat32;
typedef struct {uint64_t v;} CFSwappedFloat64;

static __inline__ __attribute__((always_inline)) CFSwappedFloat32 CFConvertFloat32HostToSwapped(Float32 arg) {
    union CFSwap {
 Float32 v;
 CFSwappedFloat32 sv;
    } result;
    result.v = arg;

    result.sv.v = CFSwapInt32(result.sv.v);

    return result.sv;
}

static __inline__ __attribute__((always_inline)) Float32 CFConvertFloat32SwappedToHost(CFSwappedFloat32 arg) {
    union CFSwap {
 Float32 v;
 CFSwappedFloat32 sv;
    } result;
    result.sv = arg;

    result.sv.v = CFSwapInt32(result.sv.v);

    return result.v;
}

static __inline__ __attribute__((always_inline)) CFSwappedFloat64 CFConvertFloat64HostToSwapped(Float64 arg) {
    union CFSwap {
 Float64 v;
 CFSwappedFloat64 sv;
    } result;
    result.v = arg;

    result.sv.v = CFSwapInt64(result.sv.v);

    return result.sv;
}

static __inline__ __attribute__((always_inline)) Float64 CFConvertFloat64SwappedToHost(CFSwappedFloat64 arg) {
    union CFSwap {
 Float64 v;
 CFSwappedFloat64 sv;
    } result;
    result.sv = arg;

    result.sv.v = CFSwapInt64(result.sv.v);

    return result.v;
}

static __inline__ __attribute__((always_inline)) CFSwappedFloat32 CFConvertFloatHostToSwapped(float arg) {
    union CFSwap {
 float v;
 CFSwappedFloat32 sv;
    } result;
    result.v = arg;

    result.sv.v = CFSwapInt32(result.sv.v);

    return result.sv;
}

static __inline__ __attribute__((always_inline)) float CFConvertFloatSwappedToHost(CFSwappedFloat32 arg) {
    union CFSwap {
 float v;
 CFSwappedFloat32 sv;
    } result;
    result.sv = arg;

    result.sv.v = CFSwapInt32(result.sv.v);

    return result.v;
}

static __inline__ __attribute__((always_inline)) CFSwappedFloat64 CFConvertDoubleHostToSwapped(double arg) {
    union CFSwap {
 double v;
 CFSwappedFloat64 sv;
    } result;
    result.v = arg;

    result.sv.v = CFSwapInt64(result.sv.v);

    return result.sv;
}

static __inline__ __attribute__((always_inline)) double CFConvertDoubleSwappedToHost(CFSwappedFloat64 arg) {
    union CFSwap {
 double v;
 CFSwappedFloat64 sv;
    } result;
    result.sv = arg;

    result.sv.v = CFSwapInt64(result.sv.v);

    return result.v;
}

}








extern "C" {
typedef const void * (*CFDictionaryRetainCallBack)(CFAllocatorRef allocator, const void *value);
typedef void (*CFDictionaryReleaseCallBack)(CFAllocatorRef allocator, const void *value);
typedef CFStringRef (*CFDictionaryCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFDictionaryEqualCallBack)(const void *value1, const void *value2);
typedef CFHashCode (*CFDictionaryHashCallBack)(const void *value);
typedef struct {
    CFIndex version;
    CFDictionaryRetainCallBack retain;
    CFDictionaryReleaseCallBack release;
    CFDictionaryCopyDescriptionCallBack copyDescription;
    CFDictionaryEqualCallBack equal;
    CFDictionaryHashCallBack hash;
} CFDictionaryKeyCallBacks;







extern
const CFDictionaryKeyCallBacks kCFTypeDictionaryKeyCallBacks;
extern
const CFDictionaryKeyCallBacks kCFCopyStringDictionaryKeyCallBacks;
typedef struct {
    CFIndex version;
    CFDictionaryRetainCallBack retain;
    CFDictionaryReleaseCallBack release;
    CFDictionaryCopyDescriptionCallBack copyDescription;
    CFDictionaryEqualCallBack equal;
} CFDictionaryValueCallBacks;







extern
const CFDictionaryValueCallBacks kCFTypeDictionaryValueCallBacks;
typedef void (*CFDictionaryApplierFunction)(const void *key, const void *value, void *context);





typedef const struct __attribute__((objc_bridge(NSDictionary))) __CFDictionary * CFDictionaryRef;





typedef struct __attribute__((objc_bridge_mutable(NSMutableDictionary))) __CFDictionary * CFMutableDictionaryRef;





extern
CFTypeID CFDictionaryGetTypeID(void);
extern
CFDictionaryRef CFDictionaryCreate(CFAllocatorRef allocator, const void **keys, const void **values, CFIndex numValues, const CFDictionaryKeyCallBacks *keyCallBacks, const CFDictionaryValueCallBacks *valueCallBacks);
extern
CFDictionaryRef CFDictionaryCreateCopy(CFAllocatorRef allocator, CFDictionaryRef theDict);
extern
CFMutableDictionaryRef CFDictionaryCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFDictionaryKeyCallBacks *keyCallBacks, const CFDictionaryValueCallBacks *valueCallBacks);
extern
CFMutableDictionaryRef CFDictionaryCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFDictionaryRef theDict);
extern
CFIndex CFDictionaryGetCount(CFDictionaryRef theDict);
extern
CFIndex CFDictionaryGetCountOfKey(CFDictionaryRef theDict, const void *key);
extern
CFIndex CFDictionaryGetCountOfValue(CFDictionaryRef theDict, const void *value);
extern
Boolean CFDictionaryContainsKey(CFDictionaryRef theDict, const void *key);
extern
Boolean CFDictionaryContainsValue(CFDictionaryRef theDict, const void *value);
extern
const void *CFDictionaryGetValue(CFDictionaryRef theDict, const void *key);
extern
Boolean CFDictionaryGetValueIfPresent(CFDictionaryRef theDict, const void *key, const void **value);
extern
void CFDictionaryGetKeysAndValues(CFDictionaryRef theDict, const void **keys, const void **values);
extern
void CFDictionaryApplyFunction(CFDictionaryRef theDict, CFDictionaryApplierFunction applier, void *context);
extern
void CFDictionaryAddValue(CFMutableDictionaryRef theDict, const void *key, const void *value);
extern
void CFDictionarySetValue(CFMutableDictionaryRef theDict, const void *key, const void *value);
extern
void CFDictionaryReplaceValue(CFMutableDictionaryRef theDict, const void *key, const void *value);
extern
void CFDictionaryRemoveValue(CFMutableDictionaryRef theDict, const void *key);
extern
void CFDictionaryRemoveAllValues(CFMutableDictionaryRef theDict);

}


extern "C" {

typedef const struct __attribute__((objc_bridge(NSLocale))) __CFLocale *CFLocaleRef;

extern
CFTypeID CFLocaleGetTypeID(void);

extern
CFLocaleRef CFLocaleGetSystem(void);


extern
CFLocaleRef CFLocaleCopyCurrent(void);
extern
CFArrayRef CFLocaleCopyAvailableLocaleIdentifiers(void);



extern
CFArrayRef CFLocaleCopyISOLanguageCodes(void);




extern
CFArrayRef CFLocaleCopyISOCountryCodes(void);




extern
CFArrayRef CFLocaleCopyISOCurrencyCodes(void);




extern
CFArrayRef CFLocaleCopyCommonISOCurrencyCodes(void) __attribute__((availability(ios,introduced=2_0)));



extern
CFArrayRef CFLocaleCopyPreferredLanguages(void) __attribute__((availability(ios,introduced=2_0)));


extern
CFStringRef CFLocaleCreateCanonicalLanguageIdentifierFromString(CFAllocatorRef allocator, CFStringRef localeIdentifier);



extern
CFStringRef CFLocaleCreateCanonicalLocaleIdentifierFromString(CFAllocatorRef allocator, CFStringRef localeIdentifier);



extern
CFStringRef CFLocaleCreateCanonicalLocaleIdentifierFromScriptManagerCodes(CFAllocatorRef allocator, LangCode lcode, RegionCode rcode);


extern
CFStringRef CFLocaleCreateLocaleIdentifierFromWindowsLocaleCode(CFAllocatorRef allocator, uint32_t lcid) __attribute__((availability(ios,introduced=4_0)));


extern
uint32_t CFLocaleGetWindowsLocaleCodeFromLocaleIdentifier(CFStringRef localeIdentifier) __attribute__((availability(ios,introduced=4_0)));


typedef CFIndex CFLocaleLanguageDirection; enum {
    kCFLocaleLanguageDirectionUnknown = 0,
    kCFLocaleLanguageDirectionLeftToRight = 1,
    kCFLocaleLanguageDirectionRightToLeft = 2,
    kCFLocaleLanguageDirectionTopToBottom = 3,
    kCFLocaleLanguageDirectionBottomToTop = 4
};

extern
CFLocaleLanguageDirection CFLocaleGetLanguageCharacterDirection(CFStringRef isoLangCode) __attribute__((availability(ios,introduced=4_0)));

extern
CFLocaleLanguageDirection CFLocaleGetLanguageLineDirection(CFStringRef isoLangCode) __attribute__((availability(ios,introduced=4_0)));

extern
CFDictionaryRef CFLocaleCreateComponentsFromLocaleIdentifier(CFAllocatorRef allocator, CFStringRef localeID);
extern
CFStringRef CFLocaleCreateLocaleIdentifierFromComponents(CFAllocatorRef allocator, CFDictionaryRef dictionary);






extern
CFLocaleRef CFLocaleCreate(CFAllocatorRef allocator, CFStringRef localeIdentifier);


extern
CFLocaleRef CFLocaleCreateCopy(CFAllocatorRef allocator, CFLocaleRef locale);




extern
CFStringRef CFLocaleGetIdentifier(CFLocaleRef locale);



extern
CFTypeRef CFLocaleGetValue(CFLocaleRef locale, CFStringRef key);



extern
CFStringRef CFLocaleCopyDisplayNameForPropertyValue(CFLocaleRef displayLocale, CFStringRef key, CFStringRef value);





extern const CFStringRef kCFLocaleCurrentLocaleDidChangeNotification __attribute__((availability(ios,introduced=2_0)));



extern const CFStringRef kCFLocaleIdentifier;
extern const CFStringRef kCFLocaleLanguageCode;
extern const CFStringRef kCFLocaleCountryCode;
extern const CFStringRef kCFLocaleScriptCode;
extern const CFStringRef kCFLocaleVariantCode;

extern const CFStringRef kCFLocaleExemplarCharacterSet;
extern const CFStringRef kCFLocaleCalendarIdentifier;
extern const CFStringRef kCFLocaleCalendar;
extern const CFStringRef kCFLocaleCollationIdentifier;
extern const CFStringRef kCFLocaleUsesMetricSystem;
extern const CFStringRef kCFLocaleMeasurementSystem;
extern const CFStringRef kCFLocaleDecimalSeparator;
extern const CFStringRef kCFLocaleGroupingSeparator;
extern const CFStringRef kCFLocaleCurrencySymbol;
extern const CFStringRef kCFLocaleCurrencyCode;
extern const CFStringRef kCFLocaleCollatorIdentifier __attribute__((availability(ios,introduced=4_0)));
extern const CFStringRef kCFLocaleQuotationBeginDelimiterKey __attribute__((availability(ios,introduced=4_0)));
extern const CFStringRef kCFLocaleQuotationEndDelimiterKey __attribute__((availability(ios,introduced=4_0)));
extern const CFStringRef kCFLocaleAlternateQuotationBeginDelimiterKey __attribute__((availability(ios,introduced=4_0)));
extern const CFStringRef kCFLocaleAlternateQuotationEndDelimiterKey __attribute__((availability(ios,introduced=4_0)));


extern const CFStringRef kCFGregorianCalendar;
extern const CFStringRef kCFBuddhistCalendar;
extern const CFStringRef kCFChineseCalendar;
extern const CFStringRef kCFHebrewCalendar;
extern const CFStringRef kCFIslamicCalendar;
extern const CFStringRef kCFIslamicCivilCalendar;
extern const CFStringRef kCFJapaneseCalendar;
extern const CFStringRef kCFRepublicOfChinaCalendar __attribute__((availability(ios,introduced=4_0)));
extern const CFStringRef kCFPersianCalendar __attribute__((availability(ios,introduced=4_0)));
extern const CFStringRef kCFIndianCalendar __attribute__((availability(ios,introduced=4_0)));
extern const CFStringRef kCFISO8601Calendar __attribute__((availability(ios,introduced=4_0)));
extern const CFStringRef kCFIslamicTabularCalendar __attribute__((availability(ios,introduced=8_0)));
extern const CFStringRef kCFIslamicUmmAlQuraCalendar __attribute__((availability(ios,introduced=8_0)));

}
extern "C" {

typedef double CFTimeInterval;
typedef CFTimeInterval CFAbsoluteTime;



extern
CFAbsoluteTime CFAbsoluteTimeGetCurrent(void);

extern
const CFTimeInterval kCFAbsoluteTimeIntervalSince1970;
extern
const CFTimeInterval kCFAbsoluteTimeIntervalSince1904;

typedef const struct __attribute__((objc_bridge(NSDate))) __CFDate * CFDateRef;

extern
CFTypeID CFDateGetTypeID(void);

extern
CFDateRef CFDateCreate(CFAllocatorRef allocator, CFAbsoluteTime at);

extern
CFAbsoluteTime CFDateGetAbsoluteTime(CFDateRef theDate);

extern
CFTimeInterval CFDateGetTimeIntervalSinceDate(CFDateRef theDate, CFDateRef otherDate);

extern
CFComparisonResult CFDateCompare(CFDateRef theDate, CFDateRef otherDate, void *context);



typedef const struct __attribute__((objc_bridge(NSTimeZone))) __CFTimeZone * CFTimeZoneRef;
typedef struct {
    SInt32 year;
    SInt8 month;
    SInt8 day;
    SInt8 hour;
    SInt8 minute;
    double second;
} CFGregorianDate __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead")));

typedef struct {
    SInt32 years;
    SInt32 months;
    SInt32 days;
    SInt32 hours;
    SInt32 minutes;
    double seconds;
} CFGregorianUnits __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead")));

typedef CFOptionFlags CFGregorianUnitFlags; enum {
    kCFGregorianUnitsYears __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead"))) = (1UL << 0),
    kCFGregorianUnitsMonths __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead"))) = (1UL << 1),
    kCFGregorianUnitsDays __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead"))) = (1UL << 2),
    kCFGregorianUnitsHours __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead"))) = (1UL << 3),
    kCFGregorianUnitsMinutes __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead"))) = (1UL << 4),
    kCFGregorianUnitsSeconds __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead"))) = (1UL << 5),
    kCFGregorianAllUnits __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead"))) = 0x00FFFFFF
};

extern
Boolean CFGregorianDateIsValid(CFGregorianDate gdate, CFOptionFlags unitFlags) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead")));

extern
CFAbsoluteTime CFGregorianDateGetAbsoluteTime(CFGregorianDate gdate, CFTimeZoneRef tz) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead")));

extern
CFGregorianDate CFAbsoluteTimeGetGregorianDate(CFAbsoluteTime at, CFTimeZoneRef tz) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead")));

extern
CFAbsoluteTime CFAbsoluteTimeAddGregorianUnits(CFAbsoluteTime at, CFTimeZoneRef tz, CFGregorianUnits units) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead")));

extern
CFGregorianUnits CFAbsoluteTimeGetDifferenceAsGregorianUnits(CFAbsoluteTime at1, CFAbsoluteTime at2, CFTimeZoneRef tz, CFOptionFlags unitFlags) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead")));

extern
SInt32 CFAbsoluteTimeGetDayOfWeek(CFAbsoluteTime at, CFTimeZoneRef tz) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead")));

extern
SInt32 CFAbsoluteTimeGetDayOfYear(CFAbsoluteTime at, CFTimeZoneRef tz) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead")));

extern
SInt32 CFAbsoluteTimeGetWeekOfYear(CFAbsoluteTime at, CFTimeZoneRef tz) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFCalendar or NSCalendar API instead")));

}
extern "C" {

typedef const struct __attribute__((objc_bridge(NSData))) __CFData * CFDataRef;
typedef struct __attribute__((objc_bridge_mutable(NSMutableData))) __CFData * CFMutableDataRef;

extern
CFTypeID CFDataGetTypeID(void);

extern
CFDataRef CFDataCreate(CFAllocatorRef allocator, const UInt8 *bytes, CFIndex length);

extern
CFDataRef CFDataCreateWithBytesNoCopy(CFAllocatorRef allocator, const UInt8 *bytes, CFIndex length, CFAllocatorRef bytesDeallocator);


extern
CFDataRef CFDataCreateCopy(CFAllocatorRef allocator, CFDataRef theData);

extern
CFMutableDataRef CFDataCreateMutable(CFAllocatorRef allocator, CFIndex capacity);

extern
CFMutableDataRef CFDataCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFDataRef theData);

extern
CFIndex CFDataGetLength(CFDataRef theData);

extern
const UInt8 *CFDataGetBytePtr(CFDataRef theData);

extern
UInt8 *CFDataGetMutableBytePtr(CFMutableDataRef theData);

extern
void CFDataGetBytes(CFDataRef theData, CFRange range, UInt8 *buffer);

extern
void CFDataSetLength(CFMutableDataRef theData, CFIndex length);

extern
void CFDataIncreaseLength(CFMutableDataRef theData, CFIndex extraLength);

extern
void CFDataAppendBytes(CFMutableDataRef theData, const UInt8 *bytes, CFIndex length);

extern
void CFDataReplaceBytes(CFMutableDataRef theData, CFRange range, const UInt8 *newBytes, CFIndex newLength);

extern
void CFDataDeleteBytes(CFMutableDataRef theData, CFRange range);

typedef CFOptionFlags CFDataSearchFlags; enum {
    kCFDataSearchBackwards = 1UL << 0,
    kCFDataSearchAnchored = 1UL << 1
} __attribute__((availability(ios,introduced=4_0)));

extern
CFRange CFDataFind(CFDataRef theData, CFDataRef dataToFind, CFRange searchRange, CFDataSearchFlags compareOptions) __attribute__((availability(ios,introduced=4_0)));

}


extern "C" {





typedef const struct __attribute__((objc_bridge(NSCharacterSet))) __CFCharacterSet * CFCharacterSetRef;





typedef struct __attribute__((objc_bridge_mutable(NSMutableCharacterSet))) __CFCharacterSet * CFMutableCharacterSetRef;






typedef CFIndex CFCharacterSetPredefinedSet; enum {
    kCFCharacterSetControl = 1,
    kCFCharacterSetWhitespace,
    kCFCharacterSetWhitespaceAndNewline,
    kCFCharacterSetDecimalDigit,
    kCFCharacterSetLetter,
    kCFCharacterSetLowercaseLetter,
    kCFCharacterSetUppercaseLetter,
    kCFCharacterSetNonBase,
    kCFCharacterSetDecomposable,
    kCFCharacterSetAlphaNumeric,
    kCFCharacterSetPunctuation,
    kCFCharacterSetCapitalizedLetter = 13,
    kCFCharacterSetSymbol = 14,
    kCFCharacterSetNewline __attribute__((availability(ios,introduced=2_0))) = 15,
    kCFCharacterSetIllegal = 12
};





extern
CFTypeID CFCharacterSetGetTypeID(void);
extern
CFCharacterSetRef CFCharacterSetGetPredefined(CFCharacterSetPredefinedSet theSetIdentifier);
extern
CFCharacterSetRef CFCharacterSetCreateWithCharactersInRange(CFAllocatorRef alloc, CFRange theRange);
extern
CFCharacterSetRef CFCharacterSetCreateWithCharactersInString(CFAllocatorRef alloc, CFStringRef theString);
extern
CFCharacterSetRef CFCharacterSetCreateWithBitmapRepresentation(CFAllocatorRef alloc, CFDataRef theData);
extern CFCharacterSetRef CFCharacterSetCreateInvertedSet(CFAllocatorRef alloc, CFCharacterSetRef theSet);
extern Boolean CFCharacterSetIsSupersetOfSet(CFCharacterSetRef theSet, CFCharacterSetRef theOtherset);
extern Boolean CFCharacterSetHasMemberInPlane(CFCharacterSetRef theSet, CFIndex thePlane);
extern
CFMutableCharacterSetRef CFCharacterSetCreateMutable(CFAllocatorRef alloc);
extern
CFCharacterSetRef CFCharacterSetCreateCopy(CFAllocatorRef alloc, CFCharacterSetRef theSet);
extern
CFMutableCharacterSetRef CFCharacterSetCreateMutableCopy(CFAllocatorRef alloc, CFCharacterSetRef theSet);
extern
Boolean CFCharacterSetIsCharacterMember(CFCharacterSetRef theSet, UniChar theChar);
extern Boolean CFCharacterSetIsLongCharacterMember(CFCharacterSetRef theSet, UTF32Char theChar);
extern
CFDataRef CFCharacterSetCreateBitmapRepresentation(CFAllocatorRef alloc, CFCharacterSetRef theSet);
extern
void CFCharacterSetAddCharactersInRange(CFMutableCharacterSetRef theSet, CFRange theRange);
extern
void CFCharacterSetRemoveCharactersInRange(CFMutableCharacterSetRef theSet, CFRange theRange);
extern
void CFCharacterSetAddCharactersInString(CFMutableCharacterSetRef theSet, CFStringRef theString);
extern
void CFCharacterSetRemoveCharactersInString(CFMutableCharacterSetRef theSet, CFStringRef theString);
extern
void CFCharacterSetUnion(CFMutableCharacterSetRef theSet, CFCharacterSetRef theOtherSet);
extern
void CFCharacterSetIntersect(CFMutableCharacterSetRef theSet, CFCharacterSetRef theOtherSet);
extern
void CFCharacterSetInvert(CFMutableCharacterSetRef theSet);

}




extern "C" {
typedef UInt32 CFStringEncoding;





typedef CFStringEncoding CFStringBuiltInEncodings; enum {
    kCFStringEncodingMacRoman = 0,
    kCFStringEncodingWindowsLatin1 = 0x0500,
    kCFStringEncodingISOLatin1 = 0x0201,
    kCFStringEncodingNextStepLatin = 0x0B01,
    kCFStringEncodingASCII = 0x0600,
    kCFStringEncodingUnicode = 0x0100,
    kCFStringEncodingUTF8 = 0x08000100,
    kCFStringEncodingNonLossyASCII = 0x0BFF,

    kCFStringEncodingUTF16 = 0x0100,
    kCFStringEncodingUTF16BE = 0x10000100,
    kCFStringEncodingUTF16LE = 0x14000100,

    kCFStringEncodingUTF32 = 0x0c000100,
    kCFStringEncodingUTF32BE = 0x18000100,
    kCFStringEncodingUTF32LE = 0x1c000100
};



extern
CFTypeID CFStringGetTypeID(void);
extern
CFStringRef CFStringCreateWithPascalString(CFAllocatorRef alloc, ConstStr255Param pStr, CFStringEncoding encoding);

extern
CFStringRef CFStringCreateWithCString(CFAllocatorRef alloc, const char *cStr, CFStringEncoding encoding);



extern
CFStringRef CFStringCreateWithBytes(CFAllocatorRef alloc, const UInt8 *bytes, CFIndex numBytes, CFStringEncoding encoding, Boolean isExternalRepresentation);

extern
CFStringRef CFStringCreateWithCharacters(CFAllocatorRef alloc, const UniChar *chars, CFIndex numChars);
extern
CFStringRef CFStringCreateWithPascalStringNoCopy(CFAllocatorRef alloc, ConstStr255Param pStr, CFStringEncoding encoding, CFAllocatorRef contentsDeallocator);

extern
CFStringRef CFStringCreateWithCStringNoCopy(CFAllocatorRef alloc, const char *cStr, CFStringEncoding encoding, CFAllocatorRef contentsDeallocator);



extern
CFStringRef CFStringCreateWithBytesNoCopy(CFAllocatorRef alloc, const UInt8 *bytes, CFIndex numBytes, CFStringEncoding encoding, Boolean isExternalRepresentation, CFAllocatorRef contentsDeallocator);

extern
CFStringRef CFStringCreateWithCharactersNoCopy(CFAllocatorRef alloc, const UniChar *chars, CFIndex numChars, CFAllocatorRef contentsDeallocator);



extern
CFStringRef CFStringCreateWithSubstring(CFAllocatorRef alloc, CFStringRef str, CFRange range);

extern
CFStringRef CFStringCreateCopy(CFAllocatorRef alloc, CFStringRef theString);



extern
CFStringRef CFStringCreateWithFormat(CFAllocatorRef alloc, CFDictionaryRef formatOptions, CFStringRef format, ...) __attribute__((format(CFString, 3, 4)));

extern
CFStringRef CFStringCreateWithFormatAndArguments(CFAllocatorRef alloc, CFDictionaryRef formatOptions, CFStringRef format, va_list arguments) __attribute__((format(CFString, 3, 0)));



extern
CFMutableStringRef CFStringCreateMutable(CFAllocatorRef alloc, CFIndex maxLength);

extern
CFMutableStringRef CFStringCreateMutableCopy(CFAllocatorRef alloc, CFIndex maxLength, CFStringRef theString);







extern
CFMutableStringRef CFStringCreateMutableWithExternalCharactersNoCopy(CFAllocatorRef alloc, UniChar *chars, CFIndex numChars, CFIndex capacity, CFAllocatorRef externalCharactersAllocator);





extern
CFIndex CFStringGetLength(CFStringRef theString);






extern
UniChar CFStringGetCharacterAtIndex(CFStringRef theString, CFIndex idx);

extern
void CFStringGetCharacters(CFStringRef theString, CFRange range, UniChar *buffer);
extern
Boolean CFStringGetPascalString(CFStringRef theString, StringPtr buffer, CFIndex bufferSize, CFStringEncoding encoding);

extern
Boolean CFStringGetCString(CFStringRef theString, char *buffer, CFIndex bufferSize, CFStringEncoding encoding);






extern
ConstStringPtr CFStringGetPascalStringPtr(CFStringRef theString, CFStringEncoding encoding);

extern
const char *CFStringGetCStringPtr(CFStringRef theString, CFStringEncoding encoding);

extern
const UniChar *CFStringGetCharactersPtr(CFStringRef theString);
extern
CFIndex CFStringGetBytes(CFStringRef theString, CFRange range, CFStringEncoding encoding, UInt8 lossByte, Boolean isExternalRepresentation, UInt8 *buffer, CFIndex maxBufLen, CFIndex *usedBufLen);







extern
CFStringRef CFStringCreateFromExternalRepresentation(CFAllocatorRef alloc, CFDataRef data, CFStringEncoding encoding);

extern
CFDataRef CFStringCreateExternalRepresentation(CFAllocatorRef alloc, CFStringRef theString, CFStringEncoding encoding, UInt8 lossByte);



extern
CFStringEncoding CFStringGetSmallestEncoding(CFStringRef theString);

extern
CFStringEncoding CFStringGetFastestEncoding(CFStringRef theString);



extern
CFStringEncoding CFStringGetSystemEncoding(void);

extern
CFIndex CFStringGetMaximumSizeForEncoding(CFIndex length, CFStringEncoding encoding);






extern
Boolean CFStringGetFileSystemRepresentation(CFStringRef string, char *buffer, CFIndex maxBufLen);



extern
CFIndex CFStringGetMaximumSizeOfFileSystemRepresentation(CFStringRef string);



extern
CFStringRef CFStringCreateWithFileSystemRepresentation(CFAllocatorRef alloc, const char *buffer);






typedef CFOptionFlags CFStringCompareFlags; enum {
    kCFCompareCaseInsensitive = 1,
    kCFCompareBackwards = 4,
    kCFCompareAnchored = 8,
    kCFCompareNonliteral = 16,
    kCFCompareLocalized = 32,
    kCFCompareNumerically = 64,
    kCFCompareDiacriticInsensitive __attribute__((availability(ios,introduced=2_0))) = 128,
    kCFCompareWidthInsensitive __attribute__((availability(ios,introduced=2_0))) = 256,
    kCFCompareForcedOrdering __attribute__((availability(ios,introduced=2_0))) = 512
};







extern
CFComparisonResult CFStringCompareWithOptionsAndLocale(CFStringRef theString1, CFStringRef theString2, CFRange rangeToCompare, CFStringCompareFlags compareOptions, CFLocaleRef locale) __attribute__((availability(ios,introduced=2_0)));



extern
CFComparisonResult CFStringCompareWithOptions(CFStringRef theString1, CFStringRef theString2, CFRange rangeToCompare, CFStringCompareFlags compareOptions);





extern
CFComparisonResult CFStringCompare(CFStringRef theString1, CFStringRef theString2, CFStringCompareFlags compareOptions);







extern
Boolean CFStringFindWithOptionsAndLocale(CFStringRef theString, CFStringRef stringToFind, CFRange rangeToSearch, CFStringCompareFlags searchOptions, CFLocaleRef locale, CFRange *result) __attribute__((availability(ios,introduced=2_0)));



extern
Boolean CFStringFindWithOptions(CFStringRef theString, CFStringRef stringToFind, CFRange rangeToSearch, CFStringCompareFlags searchOptions, CFRange *result);
extern
CFArrayRef CFStringCreateArrayWithFindResults(CFAllocatorRef alloc, CFStringRef theString, CFStringRef stringToFind, CFRange rangeToSearch, CFStringCompareFlags compareOptions);



extern
CFRange CFStringFind(CFStringRef theString, CFStringRef stringToFind, CFStringCompareFlags compareOptions);

extern
Boolean CFStringHasPrefix(CFStringRef theString, CFStringRef prefix);

extern
Boolean CFStringHasSuffix(CFStringRef theString, CFStringRef suffix);
extern CFRange CFStringGetRangeOfComposedCharactersAtIndex(CFStringRef theString, CFIndex theIndex);
extern Boolean CFStringFindCharacterFromSet(CFStringRef theString, CFCharacterSetRef theSet, CFRange rangeToSearch, CFStringCompareFlags searchOptions, CFRange *result);
extern
void CFStringGetLineBounds(CFStringRef theString, CFRange range, CFIndex *lineBeginIndex, CFIndex *lineEndIndex, CFIndex *contentsEndIndex);



extern
void CFStringGetParagraphBounds(CFStringRef string, CFRange range, CFIndex *parBeginIndex, CFIndex *parEndIndex, CFIndex *contentsEndIndex) __attribute__((availability(ios,introduced=2_0)));
extern
CFIndex CFStringGetHyphenationLocationBeforeIndex(CFStringRef string, CFIndex location, CFRange limitRange, CFOptionFlags options, CFLocaleRef locale, UTF32Char *character) __attribute__((availability(ios,introduced=4_2)));

extern
Boolean CFStringIsHyphenationAvailableForLocale(CFLocaleRef locale) __attribute__((availability(ios,introduced=4_3)));



extern
CFStringRef CFStringCreateByCombiningStrings(CFAllocatorRef alloc, CFArrayRef theArray, CFStringRef separatorString);

extern
CFArrayRef CFStringCreateArrayBySeparatingStrings(CFAllocatorRef alloc, CFStringRef theString, CFStringRef separatorString);




extern
SInt32 CFStringGetIntValue(CFStringRef str);

extern
double CFStringGetDoubleValue(CFStringRef str);
extern
void CFStringAppend(CFMutableStringRef theString, CFStringRef appendedString);

extern
void CFStringAppendCharacters(CFMutableStringRef theString, const UniChar *chars, CFIndex numChars);

extern
void CFStringAppendPascalString(CFMutableStringRef theString, ConstStr255Param pStr, CFStringEncoding encoding);

extern
void CFStringAppendCString(CFMutableStringRef theString, const char *cStr, CFStringEncoding encoding);

extern
void CFStringAppendFormat(CFMutableStringRef theString, CFDictionaryRef formatOptions, CFStringRef format, ...) __attribute__((format(CFString, 3, 4)));

extern
void CFStringAppendFormatAndArguments(CFMutableStringRef theString, CFDictionaryRef formatOptions, CFStringRef format, va_list arguments) __attribute__((format(CFString, 3, 0)));

extern
void CFStringInsert(CFMutableStringRef str, CFIndex idx, CFStringRef insertedStr);

extern
void CFStringDelete(CFMutableStringRef theString, CFRange range);

extern
void CFStringReplace(CFMutableStringRef theString, CFRange range, CFStringRef replacement);

extern
void CFStringReplaceAll(CFMutableStringRef theString, CFStringRef replacement);
extern
CFIndex CFStringFindAndReplace(CFMutableStringRef theString, CFStringRef stringToFind, CFStringRef replacementString, CFRange rangeToSearch, CFStringCompareFlags compareOptions);
extern
void CFStringSetExternalCharactersNoCopy(CFMutableStringRef theString, UniChar *chars, CFIndex length, CFIndex capacity);
extern
void CFStringPad(CFMutableStringRef theString, CFStringRef padString, CFIndex length, CFIndex indexIntoPad);

extern
void CFStringTrim(CFMutableStringRef theString, CFStringRef trimString);

extern
void CFStringTrimWhitespace(CFMutableStringRef theString);

extern
void CFStringLowercase(CFMutableStringRef theString, CFLocaleRef locale);

extern
void CFStringUppercase(CFMutableStringRef theString, CFLocaleRef locale);

extern
void CFStringCapitalize(CFMutableStringRef theString, CFLocaleRef locale);







typedef CFIndex CFStringNormalizationForm; enum {
 kCFStringNormalizationFormD = 0,
 kCFStringNormalizationFormKD,
 kCFStringNormalizationFormC,
 kCFStringNormalizationFormKC
};
extern void CFStringNormalize(CFMutableStringRef theString, CFStringNormalizationForm theForm);
extern
void CFStringFold(CFMutableStringRef theString, CFStringCompareFlags theFlags, CFLocaleRef theLocale) __attribute__((availability(ios,introduced=2_0)));





extern
Boolean CFStringTransform(CFMutableStringRef string, CFRange *range, CFStringRef transform, Boolean reverse);



extern const CFStringRef kCFStringTransformStripCombiningMarks;
extern const CFStringRef kCFStringTransformToLatin;
extern const CFStringRef kCFStringTransformFullwidthHalfwidth;
extern const CFStringRef kCFStringTransformLatinKatakana;
extern const CFStringRef kCFStringTransformLatinHiragana;
extern const CFStringRef kCFStringTransformHiraganaKatakana;
extern const CFStringRef kCFStringTransformMandarinLatin;
extern const CFStringRef kCFStringTransformLatinHangul;
extern const CFStringRef kCFStringTransformLatinArabic;
extern const CFStringRef kCFStringTransformLatinHebrew;
extern const CFStringRef kCFStringTransformLatinThai;
extern const CFStringRef kCFStringTransformLatinCyrillic;
extern const CFStringRef kCFStringTransformLatinGreek;
extern const CFStringRef kCFStringTransformToXMLHex;
extern const CFStringRef kCFStringTransformToUnicodeName;
extern const CFStringRef kCFStringTransformStripDiacritics __attribute__((availability(ios,introduced=2_0)));






extern
Boolean CFStringIsEncodingAvailable(CFStringEncoding encoding);



extern
const CFStringEncoding *CFStringGetListOfAvailableEncodings(void);



extern
CFStringRef CFStringGetNameOfEncoding(CFStringEncoding encoding);



extern
unsigned long CFStringConvertEncodingToNSStringEncoding(CFStringEncoding encoding);

extern
CFStringEncoding CFStringConvertNSStringEncodingToEncoding(unsigned long encoding);



extern
UInt32 CFStringConvertEncodingToWindowsCodepage(CFStringEncoding encoding);

extern
CFStringEncoding CFStringConvertWindowsCodepageToEncoding(UInt32 codepage);



extern
CFStringEncoding CFStringConvertIANACharSetNameToEncoding(CFStringRef theString);

extern
CFStringRef CFStringConvertEncodingToIANACharSetName(CFStringEncoding encoding);





extern
CFStringEncoding CFStringGetMostCompatibleMacStringEncoding(CFStringEncoding encoding);
typedef struct {
    UniChar buffer[64];
    CFStringRef theString;
    const UniChar *directUniCharBuffer;
    const char *directCStringBuffer;
    CFRange rangeToBuffer;
    CFIndex bufferedRangeStart;
    CFIndex bufferedRangeEnd;
} CFStringInlineBuffer;


static __inline__ __attribute__((always_inline)) void CFStringInitInlineBuffer(CFStringRef str, CFStringInlineBuffer *buf, CFRange range) {
    buf->theString = str;
    buf->rangeToBuffer = range;
    buf->directCStringBuffer = (buf->directUniCharBuffer = CFStringGetCharactersPtr(str)) ? __null : CFStringGetCStringPtr(str, kCFStringEncodingASCII);
    buf->bufferedRangeStart = buf->bufferedRangeEnd = 0;
}

static __inline__ __attribute__((always_inline)) UniChar CFStringGetCharacterFromInlineBuffer(CFStringInlineBuffer *buf, CFIndex idx) {
    if (idx < 0 || idx >= buf->rangeToBuffer.length) return 0;
    if (buf->directUniCharBuffer) return buf->directUniCharBuffer[idx + buf->rangeToBuffer.location];
    if (buf->directCStringBuffer) return (UniChar)(buf->directCStringBuffer[idx + buf->rangeToBuffer.location]);
    if (idx >= buf->bufferedRangeEnd || idx < buf->bufferedRangeStart) {
 if ((buf->bufferedRangeStart = idx - 4) < 0) buf->bufferedRangeStart = 0;
 buf->bufferedRangeEnd = buf->bufferedRangeStart + 64;
 if (buf->bufferedRangeEnd > buf->rangeToBuffer.length) buf->bufferedRangeEnd = buf->rangeToBuffer.length;
 CFStringGetCharacters(buf->theString, CFRangeMake(buf->rangeToBuffer.location + buf->bufferedRangeStart, buf->bufferedRangeEnd - buf->bufferedRangeStart), buf->buffer);
    }
    return buf->buffer[idx - buf->bufferedRangeStart];
}
static __inline__ __attribute__((always_inline)) Boolean CFStringIsSurrogateHighCharacter(UniChar character) {
    return ((character >= 0xD800UL) && (character <= 0xDBFFUL) ? true : false);
}

static __inline__ __attribute__((always_inline)) Boolean CFStringIsSurrogateLowCharacter(UniChar character) {
    return ((character >= 0xDC00UL) && (character <= 0xDFFFUL) ? true : false);
}

static __inline__ __attribute__((always_inline)) UTF32Char CFStringGetLongCharacterForSurrogatePair(UniChar surrogateHigh, UniChar surrogateLow) {
    return (UTF32Char)(((surrogateHigh - 0xD800UL) << 10) + (surrogateLow - 0xDC00UL) + 0x0010000UL);
}


static __inline__ __attribute__((always_inline)) Boolean CFStringGetSurrogatePairForLongCharacter(UTF32Char character, UniChar *surrogates) {
    if ((character > 0xFFFFUL) && (character < 0x110000UL)) {
        character -= 0x10000;
        if (__null != surrogates) {
            surrogates[0] = (UniChar)((character >> 10) + 0xD800UL);
            surrogates[1] = (UniChar)((character & 0x3FF) + 0xDC00UL);
        }
        return true;
    } else {
        if (__null != surrogates) *surrogates = (UniChar)character;
        return false;
    }
}







extern
void CFShow(CFTypeRef obj);

extern
void CFShowStr(CFStringRef str);


extern
CFStringRef __CFStringMakeConstantString(const char *cStr) __attribute__((format_arg(1)));

}


extern "C" {

extern
CFTypeID CFTimeZoneGetTypeID(void);

extern
CFTimeZoneRef CFTimeZoneCopySystem(void);

extern
void CFTimeZoneResetSystem(void);

extern
CFTimeZoneRef CFTimeZoneCopyDefault(void);

extern
void CFTimeZoneSetDefault(CFTimeZoneRef tz);

extern
CFArrayRef CFTimeZoneCopyKnownNames(void);

extern
CFDictionaryRef CFTimeZoneCopyAbbreviationDictionary(void);

extern
void CFTimeZoneSetAbbreviationDictionary(CFDictionaryRef dict);

extern
CFTimeZoneRef CFTimeZoneCreate(CFAllocatorRef allocator, CFStringRef name, CFDataRef data);

extern
CFTimeZoneRef CFTimeZoneCreateWithTimeIntervalFromGMT(CFAllocatorRef allocator, CFTimeInterval ti);

extern
CFTimeZoneRef CFTimeZoneCreateWithName(CFAllocatorRef allocator, CFStringRef name, Boolean tryAbbrev);

extern
CFStringRef CFTimeZoneGetName(CFTimeZoneRef tz);

extern
CFDataRef CFTimeZoneGetData(CFTimeZoneRef tz);

extern
CFTimeInterval CFTimeZoneGetSecondsFromGMT(CFTimeZoneRef tz, CFAbsoluteTime at);

extern
CFStringRef CFTimeZoneCopyAbbreviation(CFTimeZoneRef tz, CFAbsoluteTime at);

extern
Boolean CFTimeZoneIsDaylightSavingTime(CFTimeZoneRef tz, CFAbsoluteTime at);

extern
CFTimeInterval CFTimeZoneGetDaylightSavingTimeOffset(CFTimeZoneRef tz, CFAbsoluteTime at) __attribute__((availability(ios,introduced=2_0)));

extern
CFAbsoluteTime CFTimeZoneGetNextDaylightSavingTimeTransition(CFTimeZoneRef tz, CFAbsoluteTime at) __attribute__((availability(ios,introduced=2_0)));

typedef CFIndex CFTimeZoneNameStyle; enum {
 kCFTimeZoneNameStyleStandard,
 kCFTimeZoneNameStyleShortStandard,
 kCFTimeZoneNameStyleDaylightSaving,
 kCFTimeZoneNameStyleShortDaylightSaving,
 kCFTimeZoneNameStyleGeneric,
 kCFTimeZoneNameStyleShortGeneric
} __attribute__((availability(ios,introduced=2_0)));

extern
CFStringRef CFTimeZoneCopyLocalizedName(CFTimeZoneRef tz, CFTimeZoneNameStyle style, CFLocaleRef locale) __attribute__((availability(ios,introduced=2_0)));

extern
const CFStringRef kCFTimeZoneSystemTimeZoneDidChangeNotification __attribute__((availability(ios,introduced=2_0)));

}


extern "C" {

typedef struct __attribute__((objc_bridge_mutable(NSCalendar))) __CFCalendar * CFCalendarRef;

extern
CFTypeID CFCalendarGetTypeID(void);

extern
CFCalendarRef CFCalendarCopyCurrent(void);

extern
CFCalendarRef CFCalendarCreateWithIdentifier(CFAllocatorRef allocator, CFStringRef identifier);



extern
CFStringRef CFCalendarGetIdentifier(CFCalendarRef calendar);


extern
CFLocaleRef CFCalendarCopyLocale(CFCalendarRef calendar);

extern
void CFCalendarSetLocale(CFCalendarRef calendar, CFLocaleRef locale);

extern
CFTimeZoneRef CFCalendarCopyTimeZone(CFCalendarRef calendar);

extern
void CFCalendarSetTimeZone(CFCalendarRef calendar, CFTimeZoneRef tz);

extern
CFIndex CFCalendarGetFirstWeekday(CFCalendarRef calendar);

extern
void CFCalendarSetFirstWeekday(CFCalendarRef calendar, CFIndex wkdy);

extern
CFIndex CFCalendarGetMinimumDaysInFirstWeek(CFCalendarRef calendar);

extern
void CFCalendarSetMinimumDaysInFirstWeek(CFCalendarRef calendar, CFIndex mwd);


typedef CFOptionFlags CFCalendarUnit; enum {
 kCFCalendarUnitEra = (1UL << 1),
 kCFCalendarUnitYear = (1UL << 2),
 kCFCalendarUnitMonth = (1UL << 3),
 kCFCalendarUnitDay = (1UL << 4),
 kCFCalendarUnitHour = (1UL << 5),
 kCFCalendarUnitMinute = (1UL << 6),
 kCFCalendarUnitSecond = (1UL << 7),
 kCFCalendarUnitWeek __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" ))) = (1UL << 8),
 kCFCalendarUnitWeekday = (1UL << 9),
 kCFCalendarUnitWeekdayOrdinal = (1UL << 10),
 kCFCalendarUnitQuarter __attribute__((availability(ios,introduced=4_0))) = (1UL << 11),
 kCFCalendarUnitWeekOfMonth __attribute__((availability(ios,introduced=5_0))) = (1UL << 12),
 kCFCalendarUnitWeekOfYear __attribute__((availability(ios,introduced=5_0))) = (1UL << 13),
 kCFCalendarUnitYearForWeekOfYear __attribute__((availability(ios,introduced=5_0))) = (1UL << 14),
};

extern
CFRange CFCalendarGetMinimumRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit unit);

extern
CFRange CFCalendarGetMaximumRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit unit);

extern
CFRange CFCalendarGetRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit smallerUnit, CFCalendarUnit biggerUnit, CFAbsoluteTime at);

extern
CFIndex CFCalendarGetOrdinalityOfUnit(CFCalendarRef calendar, CFCalendarUnit smallerUnit, CFCalendarUnit biggerUnit, CFAbsoluteTime at);

extern
Boolean CFCalendarGetTimeRangeOfUnit(CFCalendarRef calendar, CFCalendarUnit unit, CFAbsoluteTime at, CFAbsoluteTime *startp, CFTimeInterval *tip) __attribute__((availability(ios,introduced=2_0)));

extern
Boolean CFCalendarComposeAbsoluteTime(CFCalendarRef calendar, CFAbsoluteTime *at, const char *componentDesc, ...);

extern
Boolean CFCalendarDecomposeAbsoluteTime(CFCalendarRef calendar, CFAbsoluteTime at, const char *componentDesc, ...);


enum {
    kCFCalendarComponentsWrap = (1UL << 0)
};

extern
Boolean CFCalendarAddComponents(CFCalendarRef calendar, CFAbsoluteTime *at, CFOptionFlags options, const char *componentDesc, ...);

extern
Boolean CFCalendarGetComponentDifference(CFCalendarRef calendar, CFAbsoluteTime startingAT, CFAbsoluteTime resultAT, CFOptionFlags options, const char *componentDesc, ...);


}



extern "C" {

typedef struct __attribute__((objc_bridge_mutable(id))) __CFDateFormatter *CFDateFormatterRef;



extern
CFStringRef CFDateFormatterCreateDateFormatFromTemplate(CFAllocatorRef allocator, CFStringRef tmplate, CFOptionFlags options, CFLocaleRef locale) __attribute__((availability(ios,introduced=4_0)));


extern
CFTypeID CFDateFormatterGetTypeID(void);

typedef CFIndex CFDateFormatterStyle; enum {
 kCFDateFormatterNoStyle = 0,
 kCFDateFormatterShortStyle = 1,
 kCFDateFormatterMediumStyle = 2,
 kCFDateFormatterLongStyle = 3,
 kCFDateFormatterFullStyle = 4
};
extern
CFDateFormatterRef CFDateFormatterCreate(CFAllocatorRef allocator, CFLocaleRef locale, CFDateFormatterStyle dateStyle, CFDateFormatterStyle timeStyle);



extern
CFLocaleRef CFDateFormatterGetLocale(CFDateFormatterRef formatter);

extern
CFDateFormatterStyle CFDateFormatterGetDateStyle(CFDateFormatterRef formatter);

extern
CFDateFormatterStyle CFDateFormatterGetTimeStyle(CFDateFormatterRef formatter);


extern
CFStringRef CFDateFormatterGetFormat(CFDateFormatterRef formatter);

extern
void CFDateFormatterSetFormat(CFDateFormatterRef formatter, CFStringRef formatString);







extern
CFStringRef CFDateFormatterCreateStringWithDate(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFDateRef date);

extern
CFStringRef CFDateFormatterCreateStringWithAbsoluteTime(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFAbsoluteTime at);




extern
CFDateRef CFDateFormatterCreateDateFromString(CFAllocatorRef allocator, CFDateFormatterRef formatter, CFStringRef string, CFRange *rangep);

extern
Boolean CFDateFormatterGetAbsoluteTimeFromString(CFDateFormatterRef formatter, CFStringRef string, CFRange *rangep, CFAbsoluteTime *atp);
extern
void CFDateFormatterSetProperty(CFDateFormatterRef formatter, CFStringRef key, CFTypeRef value);

extern
CFTypeRef CFDateFormatterCopyProperty(CFDateFormatterRef formatter, CFStringRef key);



extern const CFStringRef kCFDateFormatterIsLenient;
extern const CFStringRef kCFDateFormatterTimeZone;
extern const CFStringRef kCFDateFormatterCalendarName;
extern const CFStringRef kCFDateFormatterDefaultFormat;
extern const CFStringRef kCFDateFormatterTwoDigitStartDate;
extern const CFStringRef kCFDateFormatterDefaultDate;
extern const CFStringRef kCFDateFormatterCalendar;
extern const CFStringRef kCFDateFormatterEraSymbols;
extern const CFStringRef kCFDateFormatterMonthSymbols;
extern const CFStringRef kCFDateFormatterShortMonthSymbols;
extern const CFStringRef kCFDateFormatterWeekdaySymbols;
extern const CFStringRef kCFDateFormatterShortWeekdaySymbols;
extern const CFStringRef kCFDateFormatterAMSymbol;
extern const CFStringRef kCFDateFormatterPMSymbol;
extern const CFStringRef kCFDateFormatterLongEraSymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterVeryShortMonthSymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterStandaloneMonthSymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterShortStandaloneMonthSymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterVeryShortStandaloneMonthSymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterVeryShortWeekdaySymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterStandaloneWeekdaySymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterShortStandaloneWeekdaySymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterVeryShortStandaloneWeekdaySymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterQuarterSymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterShortQuarterSymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterStandaloneQuarterSymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterShortStandaloneQuarterSymbols __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterGregorianStartDate __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDateFormatterDoesRelativeDateFormattingKey __attribute__((availability(ios,introduced=4_0)));
}

extern "C" {





typedef struct __attribute__((objc_bridge(NSError))) __CFError * CFErrorRef;





extern
CFTypeID CFErrorGetTypeID(void) __attribute__((availability(ios,introduced=2_0)));



extern const CFStringRef kCFErrorDomainPOSIX __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFErrorDomainOSStatus __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFErrorDomainMach __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFErrorDomainCocoa __attribute__((availability(ios,introduced=2_0)));


extern const CFStringRef kCFErrorLocalizedDescriptionKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFErrorLocalizedFailureReasonKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFErrorLocalizedRecoverySuggestionKey __attribute__((availability(ios,introduced=2_0)));


extern const CFStringRef kCFErrorDescriptionKey __attribute__((availability(ios,introduced=2_0)));


extern const CFStringRef kCFErrorUnderlyingErrorKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFErrorURLKey __attribute__((availability(ios,introduced=5_0)));
extern const CFStringRef kCFErrorFilePathKey __attribute__((availability(ios,introduced=5_0)));
extern
CFErrorRef CFErrorCreate(CFAllocatorRef allocator, CFStringRef domain, CFIndex code, CFDictionaryRef userInfo) __attribute__((availability(ios,introduced=2_0)));
extern
CFErrorRef CFErrorCreateWithUserInfoKeysAndValues(CFAllocatorRef allocator, CFStringRef domain, CFIndex code, const void *const *userInfoKeys, const void *const *userInfoValues, CFIndex numUserInfoValues) __attribute__((availability(ios,introduced=2_0)));







extern
CFStringRef CFErrorGetDomain(CFErrorRef err) __attribute__((availability(ios,introduced=2_0)));







extern
CFIndex CFErrorGetCode(CFErrorRef err) __attribute__((availability(ios,introduced=2_0)));
extern
CFDictionaryRef CFErrorCopyUserInfo(CFErrorRef err) __attribute__((availability(ios,introduced=2_0)));
extern
CFStringRef CFErrorCopyDescription(CFErrorRef err) __attribute__((availability(ios,introduced=2_0)));
extern
CFStringRef CFErrorCopyFailureReason(CFErrorRef err) __attribute__((availability(ios,introduced=2_0)));
extern
CFStringRef CFErrorCopyRecoverySuggestion(CFErrorRef err) __attribute__((availability(ios,introduced=2_0)));



}

extern "C" {

typedef const struct __attribute__((objc_bridge(NSNumber))) __CFBoolean * CFBooleanRef;

extern
const CFBooleanRef kCFBooleanTrue;
extern
const CFBooleanRef kCFBooleanFalse;

extern
CFTypeID CFBooleanGetTypeID(void);

extern
Boolean CFBooleanGetValue(CFBooleanRef boolean);

typedef CFIndex CFNumberType; enum {

    kCFNumberSInt8Type = 1,
    kCFNumberSInt16Type = 2,
    kCFNumberSInt32Type = 3,
    kCFNumberSInt64Type = 4,
    kCFNumberFloat32Type = 5,
    kCFNumberFloat64Type = 6,

    kCFNumberCharType = 7,
    kCFNumberShortType = 8,
    kCFNumberIntType = 9,
    kCFNumberLongType = 10,
    kCFNumberLongLongType = 11,
    kCFNumberFloatType = 12,
    kCFNumberDoubleType = 13,

    kCFNumberCFIndexType = 14,
    kCFNumberNSIntegerType __attribute__((availability(ios,introduced=2_0))) = 15,
    kCFNumberCGFloatType __attribute__((availability(ios,introduced=2_0))) = 16,
    kCFNumberMaxType = 16
};

typedef const struct __attribute__((objc_bridge(NSNumber))) __CFNumber * CFNumberRef;

extern
const CFNumberRef kCFNumberPositiveInfinity;
extern
const CFNumberRef kCFNumberNegativeInfinity;
extern
const CFNumberRef kCFNumberNaN;

extern
CFTypeID CFNumberGetTypeID(void);
extern
CFNumberRef CFNumberCreate(CFAllocatorRef allocator, CFNumberType theType, const void *valuePtr);





extern
CFNumberType CFNumberGetType(CFNumberRef number);




extern
CFIndex CFNumberGetByteSize(CFNumberRef number);





extern
Boolean CFNumberIsFloatType(CFNumberRef number);
extern
Boolean CFNumberGetValue(CFNumberRef number, CFNumberType theType, void *valuePtr);
extern
CFComparisonResult CFNumberCompare(CFNumberRef number, CFNumberRef otherNumber, void *context);

}
extern "C" {

typedef struct __attribute__((objc_bridge_mutable(id))) __CFNumberFormatter *CFNumberFormatterRef;



extern
CFTypeID CFNumberFormatterGetTypeID(void);

typedef CFIndex CFNumberFormatterStyle; enum {
 kCFNumberFormatterNoStyle = 0,
 kCFNumberFormatterDecimalStyle = 1,
 kCFNumberFormatterCurrencyStyle = 2,
 kCFNumberFormatterPercentStyle = 3,
 kCFNumberFormatterScientificStyle = 4,
 kCFNumberFormatterSpellOutStyle = 5,
 kCFNumberFormatterOrdinalStyle __attribute__((availability(ios,introduced=9_0))) = 6,
 kCFNumberFormatterCurrencyISOCodeStyle __attribute__((availability(ios,introduced=9_0))) = 8,
 kCFNumberFormatterCurrencyPluralStyle __attribute__((availability(ios,introduced=9_0))) = 9,
 kCFNumberFormatterCurrencyAccountingStyle __attribute__((availability(ios,introduced=9_0))) = 10,
};


extern
CFNumberFormatterRef CFNumberFormatterCreate(CFAllocatorRef allocator, CFLocaleRef locale, CFNumberFormatterStyle style);



extern
CFLocaleRef CFNumberFormatterGetLocale(CFNumberFormatterRef formatter);

extern
CFNumberFormatterStyle CFNumberFormatterGetStyle(CFNumberFormatterRef formatter);


extern
CFStringRef CFNumberFormatterGetFormat(CFNumberFormatterRef formatter);

extern
void CFNumberFormatterSetFormat(CFNumberFormatterRef formatter, CFStringRef formatString);
extern
CFStringRef CFNumberFormatterCreateStringWithNumber(CFAllocatorRef allocator, CFNumberFormatterRef formatter, CFNumberRef number);

extern
CFStringRef CFNumberFormatterCreateStringWithValue(CFAllocatorRef allocator, CFNumberFormatterRef formatter, CFNumberType numberType, const void *valuePtr);




typedef CFOptionFlags CFNumberFormatterOptionFlags; enum {
    kCFNumberFormatterParseIntegersOnly = 1
};

extern
CFNumberRef CFNumberFormatterCreateNumberFromString(CFAllocatorRef allocator, CFNumberFormatterRef formatter, CFStringRef string, CFRange *rangep, CFOptionFlags options);

extern
Boolean CFNumberFormatterGetValueFromString(CFNumberFormatterRef formatter, CFStringRef string, CFRange *rangep, CFNumberType numberType, void *valuePtr);
extern
void CFNumberFormatterSetProperty(CFNumberFormatterRef formatter, CFStringRef key, CFTypeRef value);

extern
CFTypeRef CFNumberFormatterCopyProperty(CFNumberFormatterRef formatter, CFStringRef key);



extern const CFStringRef kCFNumberFormatterCurrencyCode;
extern const CFStringRef kCFNumberFormatterDecimalSeparator;
extern const CFStringRef kCFNumberFormatterCurrencyDecimalSeparator;
extern const CFStringRef kCFNumberFormatterAlwaysShowDecimalSeparator;
extern const CFStringRef kCFNumberFormatterGroupingSeparator;
extern const CFStringRef kCFNumberFormatterUseGroupingSeparator;
extern const CFStringRef kCFNumberFormatterPercentSymbol;
extern const CFStringRef kCFNumberFormatterZeroSymbol;
extern const CFStringRef kCFNumberFormatterNaNSymbol;
extern const CFStringRef kCFNumberFormatterInfinitySymbol;
extern const CFStringRef kCFNumberFormatterMinusSign;
extern const CFStringRef kCFNumberFormatterPlusSign;
extern const CFStringRef kCFNumberFormatterCurrencySymbol;
extern const CFStringRef kCFNumberFormatterExponentSymbol;
extern const CFStringRef kCFNumberFormatterMinIntegerDigits;
extern const CFStringRef kCFNumberFormatterMaxIntegerDigits;
extern const CFStringRef kCFNumberFormatterMinFractionDigits;
extern const CFStringRef kCFNumberFormatterMaxFractionDigits;
extern const CFStringRef kCFNumberFormatterGroupingSize;
extern const CFStringRef kCFNumberFormatterSecondaryGroupingSize;
extern const CFStringRef kCFNumberFormatterRoundingMode;
extern const CFStringRef kCFNumberFormatterRoundingIncrement;
extern const CFStringRef kCFNumberFormatterFormatWidth;
extern const CFStringRef kCFNumberFormatterPaddingPosition;
extern const CFStringRef kCFNumberFormatterPaddingCharacter;
extern const CFStringRef kCFNumberFormatterDefaultFormat;
extern const CFStringRef kCFNumberFormatterMultiplier;
extern const CFStringRef kCFNumberFormatterPositivePrefix;
extern const CFStringRef kCFNumberFormatterPositiveSuffix;
extern const CFStringRef kCFNumberFormatterNegativePrefix;
extern const CFStringRef kCFNumberFormatterNegativeSuffix;
extern const CFStringRef kCFNumberFormatterPerMillSymbol;
extern const CFStringRef kCFNumberFormatterInternationalCurrencySymbol;
extern const CFStringRef kCFNumberFormatterCurrencyGroupingSeparator __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFNumberFormatterIsLenient __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFNumberFormatterUseSignificantDigits __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFNumberFormatterMinSignificantDigits __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFNumberFormatterMaxSignificantDigits __attribute__((availability(ios,introduced=2_0)));

typedef CFIndex CFNumberFormatterRoundingMode; enum {
    kCFNumberFormatterRoundCeiling = 0,
    kCFNumberFormatterRoundFloor = 1,
    kCFNumberFormatterRoundDown = 2,
    kCFNumberFormatterRoundUp = 3,
    kCFNumberFormatterRoundHalfEven = 4,
    kCFNumberFormatterRoundHalfDown = 5,
    kCFNumberFormatterRoundHalfUp = 6
};

typedef CFIndex CFNumberFormatterPadPosition; enum {
    kCFNumberFormatterPadBeforePrefix = 0,
    kCFNumberFormatterPadAfterPrefix = 1,
    kCFNumberFormatterPadBeforeSuffix = 2,
    kCFNumberFormatterPadAfterSuffix = 3
};


extern
Boolean CFNumberFormatterGetDecimalInfoForCurrencyCode(CFStringRef currencyCode, int32_t *defaultFractionDigits, double *roundingIncrement);






}
extern "C" {

extern
const CFStringRef kCFPreferencesAnyApplication;
extern
const CFStringRef kCFPreferencesCurrentApplication;
extern
const CFStringRef kCFPreferencesAnyHost;
extern
const CFStringRef kCFPreferencesCurrentHost;
extern
const CFStringRef kCFPreferencesAnyUser;
extern
const CFStringRef kCFPreferencesCurrentUser;
extern
CFPropertyListRef CFPreferencesCopyAppValue(CFStringRef key, CFStringRef applicationID);




extern
Boolean CFPreferencesGetAppBooleanValue(CFStringRef key, CFStringRef applicationID, Boolean *keyExistsAndHasValidFormat);




extern
CFIndex CFPreferencesGetAppIntegerValue(CFStringRef key, CFStringRef applicationID, Boolean *keyExistsAndHasValidFormat);




extern
void CFPreferencesSetAppValue(CFStringRef key, CFPropertyListRef value, CFStringRef applicationID);





extern
void CFPreferencesAddSuitePreferencesToApp(CFStringRef applicationID, CFStringRef suiteID);

extern
void CFPreferencesRemoveSuitePreferencesFromApp(CFStringRef applicationID, CFStringRef suiteID);



extern
Boolean CFPreferencesAppSynchronize(CFStringRef applicationID);





extern
CFPropertyListRef CFPreferencesCopyValue(CFStringRef key, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);





extern
CFDictionaryRef CFPreferencesCopyMultiple(CFArrayRef keysToFetch, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);



extern
void CFPreferencesSetValue(CFStringRef key, CFPropertyListRef value, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);



extern
void CFPreferencesSetMultiple(CFDictionaryRef keysToSet, CFArrayRef keysToRemove, CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);

extern
Boolean CFPreferencesSynchronize(CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);





extern
CFArrayRef CFPreferencesCopyApplicationList(CFStringRef userName, CFStringRef hostName) __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" )));




extern
CFArrayRef CFPreferencesCopyKeyList(CFStringRef applicationID, CFStringRef userName, CFStringRef hostName);







extern
Boolean CFPreferencesAppValueIsForced(CFStringRef key, CFStringRef applicationID);



}
extern "C" {

typedef CFIndex CFURLPathStyle; enum {
    kCFURLPOSIXPathStyle = 0,
    kCFURLHFSPathStyle __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" ))),
    kCFURLWindowsPathStyle
};

typedef const struct __attribute__((objc_bridge(NSURL))) __CFURL * CFURLRef;
extern
CFTypeID CFURLGetTypeID(void);
extern
CFURLRef CFURLCreateWithBytes(CFAllocatorRef allocator, const UInt8 *URLBytes, CFIndex length, CFStringEncoding encoding, CFURLRef baseURL);





extern
CFDataRef CFURLCreateData(CFAllocatorRef allocator, CFURLRef url, CFStringEncoding encoding, Boolean escapeWhitespace);


extern
CFURLRef CFURLCreateWithString(CFAllocatorRef allocator, CFStringRef URLString, CFURLRef baseURL);
extern
CFURLRef CFURLCreateAbsoluteURLWithBytes(CFAllocatorRef alloc, const UInt8 *relativeURLBytes, CFIndex length, CFStringEncoding encoding, CFURLRef baseURL, Boolean useCompatibilityMode);







extern
CFURLRef CFURLCreateWithFileSystemPath(CFAllocatorRef allocator, CFStringRef filePath, CFURLPathStyle pathStyle, Boolean isDirectory);

extern
CFURLRef CFURLCreateFromFileSystemRepresentation(CFAllocatorRef allocator, const UInt8 *buffer, CFIndex bufLen, Boolean isDirectory);







extern
CFURLRef CFURLCreateWithFileSystemPathRelativeToBase(CFAllocatorRef allocator, CFStringRef filePath, CFURLPathStyle pathStyle, Boolean isDirectory, CFURLRef baseURL);

extern
CFURLRef CFURLCreateFromFileSystemRepresentationRelativeToBase(CFAllocatorRef allocator, const UInt8 *buffer, CFIndex bufLen, Boolean isDirectory, CFURLRef baseURL);
extern
Boolean CFURLGetFileSystemRepresentation(CFURLRef url, Boolean resolveAgainstBase, UInt8 *buffer, CFIndex maxBufLen);


extern
CFURLRef CFURLCopyAbsoluteURL(CFURLRef relativeURL);


extern
CFStringRef CFURLGetString(CFURLRef anURL);


extern
CFURLRef CFURLGetBaseURL(CFURLRef anURL);
extern
Boolean CFURLCanBeDecomposed(CFURLRef anURL);



extern
CFStringRef CFURLCopyScheme(CFURLRef anURL);


extern
CFStringRef CFURLCopyNetLocation(CFURLRef anURL);
extern
CFStringRef CFURLCopyPath(CFURLRef anURL);

extern
CFStringRef CFURLCopyStrictPath(CFURLRef anURL, Boolean *isAbsolute);

extern
CFStringRef CFURLCopyFileSystemPath(CFURLRef anURL, CFURLPathStyle pathStyle);



extern
Boolean CFURLHasDirectoryPath(CFURLRef anURL);



extern
CFStringRef CFURLCopyResourceSpecifier(CFURLRef anURL);

extern
CFStringRef CFURLCopyHostName(CFURLRef anURL);

extern
SInt32 CFURLGetPortNumber(CFURLRef anURL);

extern
CFStringRef CFURLCopyUserName(CFURLRef anURL);

extern
CFStringRef CFURLCopyPassword(CFURLRef anURL);






extern
CFStringRef CFURLCopyParameterString(CFURLRef anURL, CFStringRef charactersToLeaveEscaped);

extern
CFStringRef CFURLCopyQueryString(CFURLRef anURL, CFStringRef charactersToLeaveEscaped);

extern
CFStringRef CFURLCopyFragment(CFURLRef anURL, CFStringRef charactersToLeaveEscaped);

extern
CFStringRef CFURLCopyLastPathComponent(CFURLRef url);

extern
CFStringRef CFURLCopyPathExtension(CFURLRef url);





extern
CFURLRef CFURLCreateCopyAppendingPathComponent(CFAllocatorRef allocator, CFURLRef url, CFStringRef pathComponent, Boolean isDirectory);

extern
CFURLRef CFURLCreateCopyDeletingLastPathComponent(CFAllocatorRef allocator, CFURLRef url);

extern
CFURLRef CFURLCreateCopyAppendingPathExtension(CFAllocatorRef allocator, CFURLRef url, CFStringRef extension);

extern
CFURLRef CFURLCreateCopyDeletingPathExtension(CFAllocatorRef allocator, CFURLRef url);







extern
CFIndex CFURLGetBytes(CFURLRef url, UInt8 *buffer, CFIndex bufferLength);

typedef CFIndex CFURLComponentType; enum {
 kCFURLComponentScheme = 1,
 kCFURLComponentNetLocation = 2,
 kCFURLComponentPath = 3,
 kCFURLComponentResourceSpecifier = 4,

 kCFURLComponentUser = 5,
 kCFURLComponentPassword = 6,
 kCFURLComponentUserInfo = 7,
 kCFURLComponentHost = 8,
 kCFURLComponentPort = 9,
 kCFURLComponentParameterString = 10,
 kCFURLComponentQuery = 11,
 kCFURLComponentFragment = 12
};
extern
CFRange CFURLGetByteRangeForComponent(CFURLRef url, CFURLComponentType component, CFRange *rangeIncludingSeparators);
extern
CFStringRef CFURLCreateStringByReplacingPercentEscapes(CFAllocatorRef allocator, CFStringRef originalString, CFStringRef charactersToLeaveEscaped);


extern
CFStringRef CFURLCreateStringByReplacingPercentEscapesUsingEncoding(CFAllocatorRef allocator, CFStringRef origString, CFStringRef charsToLeaveEscaped, CFStringEncoding encoding) __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use [NSString stringByRemovingPercentEncoding] or CFURLCreateStringByReplacingPercentEscapes() instead, which always uses the recommended UTF-8 encoding.")));
extern
CFStringRef CFURLCreateStringByAddingPercentEscapes(CFAllocatorRef allocator, CFStringRef originalString, CFStringRef charactersToLeaveUnescaped, CFStringRef legalURLCharactersToBeEscaped, CFStringEncoding encoding) __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use [NSString stringByAddingPercentEncodingWithAllowedCharacters:] instead, which always uses the recommended UTF-8 encoding, and which encodes for a specific URL component or subcomponent (since each URL component or subcomponent has different rules for what characters are valid).")));
extern
Boolean CFURLIsFileReferenceURL(CFURLRef url) __attribute__((availability(ios,introduced=7_0)));
extern
CFURLRef CFURLCreateFileReferenceURL(CFAllocatorRef allocator, CFURLRef url, CFErrorRef *error) __attribute__((availability(ios,introduced=4_0)));
extern
CFURLRef CFURLCreateFilePathURL(CFAllocatorRef allocator, CFURLRef url, CFErrorRef *error) __attribute__((availability(ios,introduced=4_0)));







struct FSRef;



extern
CFURLRef CFURLCreateFromFSRef(CFAllocatorRef allocator, const struct FSRef *fsRef) __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" )));

extern
Boolean CFURLGetFSRef(CFURLRef url, struct FSRef *fsRef) __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" )));
extern
Boolean CFURLCopyResourcePropertyForKey(CFURLRef url, CFStringRef key, void *propertyValueTypeRefPtr, CFErrorRef *error) __attribute__((availability(ios,introduced=4_0)));
extern
CFDictionaryRef CFURLCopyResourcePropertiesForKeys(CFURLRef url, CFArrayRef keys, CFErrorRef *error) __attribute__((availability(ios,introduced=4_0)));
extern
Boolean CFURLSetResourcePropertyForKey(CFURLRef url, CFStringRef key, CFTypeRef propertyValue, CFErrorRef *error) __attribute__((availability(ios,introduced=4_0)));
extern
Boolean CFURLSetResourcePropertiesForKeys(CFURLRef url, CFDictionaryRef keyedPropertyValues, CFErrorRef *error) __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLKeysOfUnsetValuesKey __attribute__((availability(ios,introduced=5_0)));
extern
void CFURLClearResourcePropertyCacheForKey(CFURLRef url, CFStringRef key) __attribute__((availability(ios,introduced=4_0)));
extern
void CFURLClearResourcePropertyCache(CFURLRef url) __attribute__((availability(ios,introduced=4_0)));
extern
void CFURLSetTemporaryResourcePropertyForKey(CFURLRef url, CFStringRef key, CFTypeRef propertyValue) __attribute__((availability(ios,introduced=4_0)));
extern
Boolean CFURLResourceIsReachable(CFURLRef url, CFErrorRef *error) __attribute__((availability(ios,introduced=4_0)));






extern
const CFStringRef kCFURLNameKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLLocalizedNameKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLIsRegularFileKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLIsDirectoryKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLIsSymbolicLinkKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLIsVolumeKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLIsPackageKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLIsApplicationKey __attribute__((availability(ios,introduced=9_0)));


extern
const CFStringRef kCFURLApplicationIsScriptableKey __attribute__((availability(ios,introduced=NA)));


extern
const CFStringRef kCFURLIsSystemImmutableKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLIsUserImmutableKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLIsHiddenKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLHasHiddenExtensionKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLCreationDateKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLContentAccessDateKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLContentModificationDateKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLAttributeModificationDateKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLLinkCountKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLParentDirectoryURLKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeURLKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLTypeIdentifierKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLLocalizedTypeDescriptionKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLLabelNumberKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLLabelColorKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLLocalizedLabelKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLEffectiveIconKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLCustomIconKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLFileResourceIdentifierKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeIdentifierKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLPreferredIOBlockSizeKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLIsReadableKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLIsWritableKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLIsExecutableKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLFileSecurityKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLIsExcludedFromBackupKey __attribute__((availability(ios,introduced=5_1)));


extern
const CFStringRef kCFURLTagNamesKey __attribute__((availability(ios,introduced=NA)));


extern
const CFStringRef kCFURLPathKey __attribute__((availability(ios,introduced=6_0)));


extern
const CFStringRef kCFURLIsMountTriggerKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLGenerationIdentifierKey __attribute__((availability(ios,introduced=8_0)));


extern
const CFStringRef kCFURLDocumentIdentifierKey __attribute__((availability(ios,introduced=8_0)));


extern
const CFStringRef kCFURLAddedToDirectoryDateKey __attribute__((availability(ios,introduced=8_0)));


extern
const CFStringRef kCFURLQuarantinePropertiesKey __attribute__((availability(ios,introduced=NA)));


extern
const CFStringRef kCFURLFileResourceTypeKey __attribute__((availability(ios,introduced=5_0)));



extern
const CFStringRef kCFURLFileResourceTypeNamedPipe __attribute__((availability(ios,introduced=5_0)));
extern
const CFStringRef kCFURLFileResourceTypeCharacterSpecial __attribute__((availability(ios,introduced=5_0)));
extern
const CFStringRef kCFURLFileResourceTypeDirectory __attribute__((availability(ios,introduced=5_0)));
extern
const CFStringRef kCFURLFileResourceTypeBlockSpecial __attribute__((availability(ios,introduced=5_0)));
extern
const CFStringRef kCFURLFileResourceTypeRegular __attribute__((availability(ios,introduced=5_0)));
extern
const CFStringRef kCFURLFileResourceTypeSymbolicLink __attribute__((availability(ios,introduced=5_0)));
extern
const CFStringRef kCFURLFileResourceTypeSocket __attribute__((availability(ios,introduced=5_0)));
extern
const CFStringRef kCFURLFileResourceTypeUnknown __attribute__((availability(ios,introduced=5_0)));



extern
const CFStringRef kCFURLFileSizeKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLFileAllocatedSizeKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLTotalFileSizeKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLTotalFileAllocatedSizeKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLIsAliasFileKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLFileProtectionKey __attribute__((availability(ios,introduced=9_0)));



extern
const CFStringRef kCFURLFileProtectionNone __attribute__((availability(ios,introduced=9_0)));

extern
const CFStringRef kCFURLFileProtectionComplete __attribute__((availability(ios,introduced=9_0)));

extern
const CFStringRef kCFURLFileProtectionCompleteUnlessOpen __attribute__((availability(ios,introduced=9_0)));

extern
const CFStringRef kCFURLFileProtectionCompleteUntilFirstUserAuthentication __attribute__((availability(ios,introduced=9_0)));





extern
const CFStringRef kCFURLVolumeLocalizedFormatDescriptionKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeTotalCapacityKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeAvailableCapacityKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeResourceCountKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeSupportsPersistentIDsKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeSupportsSymbolicLinksKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeSupportsHardLinksKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeSupportsJournalingKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeIsJournalingKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeSupportsSparseFilesKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeSupportsZeroRunsKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeSupportsCaseSensitiveNamesKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeSupportsCasePreservedNamesKey __attribute__((availability(ios,introduced=4_0)));


extern
const CFStringRef kCFURLVolumeSupportsRootDirectoryDatesKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeSupportsVolumeSizesKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeSupportsRenamingKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeSupportsAdvisoryFileLockingKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeSupportsExtendedSecurityKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeIsBrowsableKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeMaximumFileSizeKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeIsEjectableKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeIsRemovableKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeIsInternalKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeIsAutomountedKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeIsLocalKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeIsReadOnlyKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeCreationDateKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeURLForRemountingKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeUUIDStringKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeNameKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLVolumeLocalizedNameKey __attribute__((availability(ios,introduced=5_0)));




extern
const CFStringRef kCFURLIsUbiquitousItemKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLUbiquitousItemHasUnresolvedConflictsKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLUbiquitousItemIsDownloadedKey __attribute__((availability(ios,introduced=5_0,deprecated=7_0,message="" "Use kCFURLUbiquitousItemDownloadingStatusKey instead")));


extern
const CFStringRef kCFURLUbiquitousItemIsDownloadingKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLUbiquitousItemIsUploadedKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLUbiquitousItemIsUploadingKey __attribute__((availability(ios,introduced=5_0)));


extern
const CFStringRef kCFURLUbiquitousItemPercentDownloadedKey __attribute__((availability(ios,introduced=5_0,deprecated=6_0,message="" "Use NSMetadataQuery and NSMetadataUbiquitousItemPercentDownloadedKey on NSMetadataItem instead")));


extern
const CFStringRef kCFURLUbiquitousItemPercentUploadedKey __attribute__((availability(ios,introduced=5_0,deprecated=6_0,message="" "Use NSMetadataQuery and NSMetadataUbiquitousItemPercentUploadedKey on NSMetadataItem instead")));


extern
const CFStringRef kCFURLUbiquitousItemDownloadingStatusKey __attribute__((availability(ios,introduced=7_0)));


extern
const CFStringRef kCFURLUbiquitousItemDownloadingErrorKey __attribute__((availability(ios,introduced=7_0)));


extern
const CFStringRef kCFURLUbiquitousItemUploadingErrorKey __attribute__((availability(ios,introduced=7_0)));




extern
const CFStringRef kCFURLUbiquitousItemDownloadingStatusNotDownloaded __attribute__((availability(ios,introduced=7_0)));


extern
const CFStringRef kCFURLUbiquitousItemDownloadingStatusDownloaded __attribute__((availability(ios,introduced=7_0)));


extern
const CFStringRef kCFURLUbiquitousItemDownloadingStatusCurrent __attribute__((availability(ios,introduced=7_0)));



typedef CFOptionFlags CFURLBookmarkCreationOptions; enum {
    kCFURLBookmarkCreationMinimalBookmarkMask = ( 1UL << 9 ),
    kCFURLBookmarkCreationSuitableForBookmarkFile = ( 1UL << 10 ),
    kCFURLBookmarkCreationWithSecurityScope __attribute__((availability(ios,introduced=NA))) = ( 1UL << 11 ),
    kCFURLBookmarkCreationSecurityScopeAllowOnlyReadAccess __attribute__((availability(ios,introduced=NA))) = ( 1UL << 12 ),


    kCFURLBookmarkCreationPreferFileIDResolutionMask __attribute__((availability(ios,introduced=4_0,deprecated=7_0,message="" "kCFURLBookmarkCreationPreferFileIDResolutionMask does nothing and has no effect on bookmark resolution"))) = ( 1UL << 8 ),
} __attribute__((availability(ios,introduced=4_0)));

typedef CFOptionFlags CFURLBookmarkResolutionOptions; enum {
    kCFURLBookmarkResolutionWithoutUIMask = ( 1UL << 8 ),
    kCFURLBookmarkResolutionWithoutMountingMask = ( 1UL << 9 ),
    kCFURLBookmarkResolutionWithSecurityScope __attribute__((availability(ios,introduced=NA))) = ( 1UL << 10 ),

    kCFBookmarkResolutionWithoutUIMask = kCFURLBookmarkResolutionWithoutUIMask,
    kCFBookmarkResolutionWithoutMountingMask = kCFURLBookmarkResolutionWithoutMountingMask,
} __attribute__((availability(ios,introduced=4_0)));

typedef CFOptionFlags CFURLBookmarkFileCreationOptions;





extern
CFDataRef CFURLCreateBookmarkData ( CFAllocatorRef allocator, CFURLRef url, CFURLBookmarkCreationOptions options, CFArrayRef resourcePropertiesToInclude, CFURLRef relativeToURL, CFErrorRef* error ) __attribute__((availability(ios,introduced=4_0)));



extern
CFURLRef CFURLCreateByResolvingBookmarkData ( CFAllocatorRef allocator, CFDataRef bookmark, CFURLBookmarkResolutionOptions options, CFURLRef relativeToURL, CFArrayRef resourcePropertiesToInclude, Boolean* isStale, CFErrorRef* error ) __attribute__((availability(ios,introduced=4_0)));



extern
CFDictionaryRef CFURLCreateResourcePropertiesForKeysFromBookmarkData ( CFAllocatorRef allocator, CFArrayRef resourcePropertiesToReturn, CFDataRef bookmark ) __attribute__((availability(ios,introduced=4_0)));



extern
CFTypeRef CFURLCreateResourcePropertyForKeyFromBookmarkData( CFAllocatorRef allocator, CFStringRef resourcePropertyKey, CFDataRef bookmark ) __attribute__((availability(ios,introduced=4_0)));



extern
CFDataRef CFURLCreateBookmarkDataFromFile(CFAllocatorRef allocator, CFURLRef fileURL, CFErrorRef *errorRef ) __attribute__((availability(ios,introduced=5_0)));



extern
Boolean CFURLWriteBookmarkDataToFile( CFDataRef bookmarkRef, CFURLRef fileURL, CFURLBookmarkFileCreationOptions options, CFErrorRef *errorRef ) __attribute__((availability(ios,introduced=5_0)));



extern
CFDataRef CFURLCreateBookmarkDataFromAliasRecord ( CFAllocatorRef allocatorRef, CFDataRef aliasRecordDataRef ) __attribute__((availability(ios,unavailable)));





extern
Boolean CFURLStartAccessingSecurityScopedResource(CFURLRef url) __attribute__((availability(ios,introduced=8_0)));



extern
void CFURLStopAccessingSecurityScopedResource(CFURLRef url) __attribute__((availability(ios,introduced=8_0)));



}
typedef unsigned int boolean_t;
typedef __darwin_natural_t natural_t;
typedef int integer_t;






typedef uintptr_t vm_offset_t;
typedef uintptr_t vm_size_t;
typedef uint64_t mach_vm_address_t;
typedef uint64_t mach_vm_offset_t;
typedef uint64_t mach_vm_size_t;

typedef uint64_t vm_map_offset_t;
typedef uint64_t vm_map_address_t;
typedef uint64_t vm_map_size_t;

typedef mach_vm_address_t mach_port_context_t;
typedef natural_t mach_port_name_t;
typedef mach_port_name_t *mach_port_name_array_t;
typedef __darwin_mach_port_t mach_port_t;


typedef mach_port_t *mach_port_array_t;
typedef natural_t mach_port_right_t;
typedef natural_t mach_port_type_t;
typedef mach_port_type_t *mach_port_type_array_t;
typedef natural_t mach_port_urefs_t;
typedef integer_t mach_port_delta_t;



typedef natural_t mach_port_seqno_t;
typedef natural_t mach_port_mscount_t;
typedef natural_t mach_port_msgcount_t;
typedef natural_t mach_port_rights_t;






typedef unsigned int mach_port_srights_t;

typedef struct mach_port_status {
 mach_port_rights_t mps_pset;
 mach_port_seqno_t mps_seqno;
 mach_port_mscount_t mps_mscount;
 mach_port_msgcount_t mps_qlimit;
 mach_port_msgcount_t mps_msgcount;
 mach_port_rights_t mps_sorights;
 boolean_t mps_srights;
 boolean_t mps_pdrequest;
 boolean_t mps_nsrequest;
 natural_t mps_flags;
} mach_port_status_t;
typedef struct mach_port_limits {
 mach_port_msgcount_t mpl_qlimit;
} mach_port_limits_t;
typedef struct mach_port_info_ext {
 mach_port_status_t mpie_status;
 mach_port_msgcount_t mpie_boost_cnt;
 uint32_t reserved[6];
} mach_port_info_ext_t;

typedef integer_t *mach_port_info_t;


typedef int mach_port_flavor_t;
typedef struct mach_port_qos {
 unsigned int name:1;
 unsigned int prealloc:1;
 boolean_t pad1:30;
 natural_t len;
} mach_port_qos_t;
typedef struct mach_port_options {
 uint32_t flags;
 mach_port_limits_t mpl;
 uint64_t reserved[2];
}mach_port_options_t;

typedef mach_port_options_t *mach_port_options_ptr_t;
enum mach_port_guard_exception_codes {
 kGUARD_EXC_DESTROY = 1u << 0,
 kGUARD_EXC_MOD_REFS = 1u << 1,
 kGUARD_EXC_SET_CONTEXT = 1u << 2,
 kGUARD_EXC_UNGUARDED = 1u << 3,
 kGUARD_EXC_INCORRECT_GUARD = 1u << 4
};



extern "C" {

typedef struct __attribute__((objc_bridge_mutable(id))) __CFRunLoop * CFRunLoopRef;

typedef struct __attribute__((objc_bridge_mutable(id))) __CFRunLoopSource * CFRunLoopSourceRef;

typedef struct __attribute__((objc_bridge_mutable(id))) __CFRunLoopObserver * CFRunLoopObserverRef;

typedef struct __attribute__((objc_bridge_mutable(NSTimer))) __CFRunLoopTimer * CFRunLoopTimerRef;


typedef SInt32 CFRunLoopRunResult; enum {
    kCFRunLoopRunFinished = 1,
    kCFRunLoopRunStopped = 2,
    kCFRunLoopRunTimedOut = 3,
    kCFRunLoopRunHandledSource = 4
};


typedef CFOptionFlags CFRunLoopActivity; enum {
    kCFRunLoopEntry = (1UL << 0),
    kCFRunLoopBeforeTimers = (1UL << 1),
    kCFRunLoopBeforeSources = (1UL << 2),
    kCFRunLoopBeforeWaiting = (1UL << 5),
    kCFRunLoopAfterWaiting = (1UL << 6),
    kCFRunLoopExit = (1UL << 7),
    kCFRunLoopAllActivities = 0x0FFFFFFFU
};

extern const CFStringRef kCFRunLoopDefaultMode;
extern const CFStringRef kCFRunLoopCommonModes;

extern CFTypeID CFRunLoopGetTypeID(void);

extern CFRunLoopRef CFRunLoopGetCurrent(void);
extern CFRunLoopRef CFRunLoopGetMain(void);

extern CFStringRef CFRunLoopCopyCurrentMode(CFRunLoopRef rl);

extern CFArrayRef CFRunLoopCopyAllModes(CFRunLoopRef rl);

extern void CFRunLoopAddCommonMode(CFRunLoopRef rl, CFStringRef mode);

extern CFAbsoluteTime CFRunLoopGetNextTimerFireDate(CFRunLoopRef rl, CFStringRef mode);

extern void CFRunLoopRun(void);
extern CFRunLoopRunResult CFRunLoopRunInMode(CFStringRef mode, CFTimeInterval seconds, Boolean returnAfterSourceHandled);
extern Boolean CFRunLoopIsWaiting(CFRunLoopRef rl);
extern void CFRunLoopWakeUp(CFRunLoopRef rl);
extern void CFRunLoopStop(CFRunLoopRef rl);


extern void CFRunLoopPerformBlock(CFRunLoopRef rl, CFTypeRef mode, void (*block)(void)) __attribute__((availability(ios,introduced=4_0)));


extern Boolean CFRunLoopContainsSource(CFRunLoopRef rl, CFRunLoopSourceRef source, CFStringRef mode);
extern void CFRunLoopAddSource(CFRunLoopRef rl, CFRunLoopSourceRef source, CFStringRef mode);
extern void CFRunLoopRemoveSource(CFRunLoopRef rl, CFRunLoopSourceRef source, CFStringRef mode);

extern Boolean CFRunLoopContainsObserver(CFRunLoopRef rl, CFRunLoopObserverRef observer, CFStringRef mode);
extern void CFRunLoopAddObserver(CFRunLoopRef rl, CFRunLoopObserverRef observer, CFStringRef mode);
extern void CFRunLoopRemoveObserver(CFRunLoopRef rl, CFRunLoopObserverRef observer, CFStringRef mode);

extern Boolean CFRunLoopContainsTimer(CFRunLoopRef rl, CFRunLoopTimerRef timer, CFStringRef mode);
extern void CFRunLoopAddTimer(CFRunLoopRef rl, CFRunLoopTimerRef timer, CFStringRef mode);
extern void CFRunLoopRemoveTimer(CFRunLoopRef rl, CFRunLoopTimerRef timer, CFStringRef mode);

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
    Boolean (*equal)(const void *info1, const void *info2);
    CFHashCode (*hash)(const void *info);
    void (*schedule)(void *info, CFRunLoopRef rl, CFStringRef mode);
    void (*cancel)(void *info, CFRunLoopRef rl, CFStringRef mode);
    void (*perform)(void *info);
} CFRunLoopSourceContext;

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
    Boolean (*equal)(const void *info1, const void *info2);
    CFHashCode (*hash)(const void *info);

    mach_port_t (*getPort)(void *info);
    void * (*perform)(void *msg, CFIndex size, CFAllocatorRef allocator, void *info);




} CFRunLoopSourceContext1;

extern CFTypeID CFRunLoopSourceGetTypeID(void);

extern CFRunLoopSourceRef CFRunLoopSourceCreate(CFAllocatorRef allocator, CFIndex order, CFRunLoopSourceContext *context);

extern CFIndex CFRunLoopSourceGetOrder(CFRunLoopSourceRef source);
extern void CFRunLoopSourceInvalidate(CFRunLoopSourceRef source);
extern Boolean CFRunLoopSourceIsValid(CFRunLoopSourceRef source);
extern void CFRunLoopSourceGetContext(CFRunLoopSourceRef source, CFRunLoopSourceContext *context);
extern void CFRunLoopSourceSignal(CFRunLoopSourceRef source);

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFRunLoopObserverContext;

typedef void (*CFRunLoopObserverCallBack)(CFRunLoopObserverRef observer, CFRunLoopActivity activity, void *info);

extern CFTypeID CFRunLoopObserverGetTypeID(void);

extern CFRunLoopObserverRef CFRunLoopObserverCreate(CFAllocatorRef allocator, CFOptionFlags activities, Boolean repeats, CFIndex order, CFRunLoopObserverCallBack callout, CFRunLoopObserverContext *context);

extern CFRunLoopObserverRef CFRunLoopObserverCreateWithHandler(CFAllocatorRef allocator, CFOptionFlags activities, Boolean repeats, CFIndex order, void (*block) (CFRunLoopObserverRef observer, CFRunLoopActivity activity)) __attribute__((availability(ios,introduced=5_0)));


extern CFOptionFlags CFRunLoopObserverGetActivities(CFRunLoopObserverRef observer);
extern Boolean CFRunLoopObserverDoesRepeat(CFRunLoopObserverRef observer);
extern CFIndex CFRunLoopObserverGetOrder(CFRunLoopObserverRef observer);
extern void CFRunLoopObserverInvalidate(CFRunLoopObserverRef observer);
extern Boolean CFRunLoopObserverIsValid(CFRunLoopObserverRef observer);
extern void CFRunLoopObserverGetContext(CFRunLoopObserverRef observer, CFRunLoopObserverContext *context);

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFRunLoopTimerContext;

typedef void (*CFRunLoopTimerCallBack)(CFRunLoopTimerRef timer, void *info);

extern CFTypeID CFRunLoopTimerGetTypeID(void);

extern CFRunLoopTimerRef CFRunLoopTimerCreate(CFAllocatorRef allocator, CFAbsoluteTime fireDate, CFTimeInterval interval, CFOptionFlags flags, CFIndex order, CFRunLoopTimerCallBack callout, CFRunLoopTimerContext *context);

extern CFRunLoopTimerRef CFRunLoopTimerCreateWithHandler(CFAllocatorRef allocator, CFAbsoluteTime fireDate, CFTimeInterval interval, CFOptionFlags flags, CFIndex order, void (*block) (CFRunLoopTimerRef timer)) __attribute__((availability(ios,introduced=5_0)));


extern CFAbsoluteTime CFRunLoopTimerGetNextFireDate(CFRunLoopTimerRef timer);
extern void CFRunLoopTimerSetNextFireDate(CFRunLoopTimerRef timer, CFAbsoluteTime fireDate);
extern CFTimeInterval CFRunLoopTimerGetInterval(CFRunLoopTimerRef timer);
extern Boolean CFRunLoopTimerDoesRepeat(CFRunLoopTimerRef timer);
extern CFIndex CFRunLoopTimerGetOrder(CFRunLoopTimerRef timer);
extern void CFRunLoopTimerInvalidate(CFRunLoopTimerRef timer);
extern Boolean CFRunLoopTimerIsValid(CFRunLoopTimerRef timer);
extern void CFRunLoopTimerGetContext(CFRunLoopTimerRef timer, CFRunLoopTimerContext *context);



extern CFTimeInterval CFRunLoopTimerGetTolerance(CFRunLoopTimerRef timer) __attribute__((availability(ios,introduced=7_0)));
extern void CFRunLoopTimerSetTolerance(CFRunLoopTimerRef timer, CFTimeInterval tolerance) __attribute__((availability(ios,introduced=7_0)));

}
extern "C" {

typedef struct __attribute__((objc_bridge_mutable(id))) __CFSocket * CFSocketRef;
typedef CFIndex CFSocketError; enum {
    kCFSocketSuccess = 0,
    kCFSocketError = -1L,
    kCFSocketTimeout = -2L
};

typedef struct {
    SInt32 protocolFamily;
    SInt32 socketType;
    SInt32 protocol;
    CFDataRef address;
} CFSocketSignature;


typedef CFOptionFlags CFSocketCallBackType; enum {
    kCFSocketNoCallBack = 0,
    kCFSocketReadCallBack = 1,
    kCFSocketAcceptCallBack = 2,
    kCFSocketDataCallBack = 3,
    kCFSocketConnectCallBack = 4,
    kCFSocketWriteCallBack = 8
};


enum {
    kCFSocketAutomaticallyReenableReadCallBack = 1,
    kCFSocketAutomaticallyReenableAcceptCallBack = 2,
    kCFSocketAutomaticallyReenableDataCallBack = 3,
    kCFSocketAutomaticallyReenableWriteCallBack = 8,
    kCFSocketLeaveErrors __attribute__((availability(ios,introduced=2_0))) = 64,
    kCFSocketCloseOnInvalidate = 128
};

typedef void (*CFSocketCallBack)(CFSocketRef s, CFSocketCallBackType type, CFDataRef address, const void *data, void *info);


typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFSocketContext;




typedef int CFSocketNativeHandle;


extern CFTypeID CFSocketGetTypeID(void);

extern CFSocketRef CFSocketCreate(CFAllocatorRef allocator, SInt32 protocolFamily, SInt32 socketType, SInt32 protocol, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context);
extern CFSocketRef CFSocketCreateWithNative(CFAllocatorRef allocator, CFSocketNativeHandle sock, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context);
extern CFSocketRef CFSocketCreateWithSocketSignature(CFAllocatorRef allocator, const CFSocketSignature *signature, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context);

extern CFSocketRef CFSocketCreateConnectedToSocketSignature(CFAllocatorRef allocator, const CFSocketSignature *signature, CFOptionFlags callBackTypes, CFSocketCallBack callout, const CFSocketContext *context, CFTimeInterval timeout);


extern CFSocketError CFSocketSetAddress(CFSocketRef s, CFDataRef address);
extern CFSocketError CFSocketConnectToAddress(CFSocketRef s, CFDataRef address, CFTimeInterval timeout);
extern void CFSocketInvalidate(CFSocketRef s);

extern Boolean CFSocketIsValid(CFSocketRef s);
extern CFDataRef CFSocketCopyAddress(CFSocketRef s);
extern CFDataRef CFSocketCopyPeerAddress(CFSocketRef s);
extern void CFSocketGetContext(CFSocketRef s, CFSocketContext *context);
extern CFSocketNativeHandle CFSocketGetNative(CFSocketRef s);

extern CFRunLoopSourceRef CFSocketCreateRunLoopSource(CFAllocatorRef allocator, CFSocketRef s, CFIndex order);

extern CFOptionFlags CFSocketGetSocketFlags(CFSocketRef s);
extern void CFSocketSetSocketFlags(CFSocketRef s, CFOptionFlags flags);
extern void CFSocketDisableCallBacks(CFSocketRef s, CFOptionFlags callBackTypes);
extern void CFSocketEnableCallBacks(CFSocketRef s, CFOptionFlags callBackTypes);



extern CFSocketError CFSocketSendData(CFSocketRef s, CFDataRef address, CFDataRef data, CFTimeInterval timeout);
extern CFSocketError CFSocketRegisterValue(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, CFPropertyListRef value);
extern CFSocketError CFSocketCopyRegisteredValue(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, CFPropertyListRef *value, CFDataRef *nameServerAddress);

extern CFSocketError CFSocketRegisterSocketSignature(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, const CFSocketSignature *signature);
extern CFSocketError CFSocketCopyRegisteredSocketSignature(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name, CFSocketSignature *signature, CFDataRef *nameServerAddress);

extern CFSocketError CFSocketUnregister(const CFSocketSignature *nameServerSignature, CFTimeInterval timeout, CFStringRef name);

extern void CFSocketSetDefaultNameRegistryPortNumber(UInt16 port);
extern UInt16 CFSocketGetDefaultNameRegistryPortNumber(void);


extern const CFStringRef kCFSocketCommandKey;
extern const CFStringRef kCFSocketNameKey;
extern const CFStringRef kCFSocketValueKey;
extern const CFStringRef kCFSocketResultKey;
extern const CFStringRef kCFSocketErrorKey;
extern const CFStringRef kCFSocketRegisterCommand;
extern const CFStringRef kCFSocketRetrieveCommand;

}




struct accessx_descriptor {
 unsigned int ad_name_offset;
 int ad_flags;
 int ad_pad[2];
};
extern "C" {

int getattrlistbulk(int, void *, void *, size_t, uint64_t) __attribute__((availability(macosx,introduced=10.10)));

}
extern "C" {

int faccessat(int, const char *, int, int) __attribute__((availability(macosx,introduced=10.10)));
int fchownat(int, const char *, uid_t, gid_t, int) __attribute__((availability(macosx,introduced=10.10)));
int linkat(int, const char *, int, const char *, int) __attribute__((availability(macosx,introduced=10.10)));
ssize_t readlinkat(int, const char *, char *, size_t) __attribute__((availability(macosx,introduced=10.10)));
int symlinkat(const char *, int, const char *) __attribute__((availability(macosx,introduced=10.10)));
int unlinkat(int, const char *, int) __attribute__((availability(macosx,introduced=10.10)));
int getattrlistat(int, const char *, void *, void *, size_t, unsigned long) __attribute__((availability(macosx,introduced=10.10)));

}
extern "C" {
void _exit(int) __attribute__((noreturn));
int access(const char *, int);
unsigned int
  alarm(unsigned int);
int chdir(const char *);
int chown(const char *, uid_t, gid_t);

int close(int) __asm("_" "close" );

int dup(int);
int dup2(int, int);
int execl(const char *, const char *, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execle(const char *, const char *, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execlp(const char *, const char *, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execv(const char *, char * const *) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execve(const char *, char * const *, char * const *) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execvp(const char *, char * const *) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
pid_t fork(void) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
long fpathconf(int, int);
char *getcwd(char *, size_t);
gid_t getegid(void);
uid_t geteuid(void);
gid_t getgid(void);



int getgroups(int, gid_t []);

char *getlogin(void);
pid_t getpgrp(void);
pid_t getpid(void);
pid_t getppid(void);
uid_t getuid(void);
int isatty(int);
int link(const char *, const char *);
off_t lseek(int, off_t, int);
long pathconf(const char *, int);

int pause(void) __asm("_" "pause" );

int pipe(int [2]);

ssize_t read(int, void *, size_t) __asm("_" "read" );

int rmdir(const char *);
int setgid(gid_t);
int setpgid(pid_t, pid_t);
pid_t setsid(void);
int setuid(uid_t);

unsigned int
  sleep(unsigned int) __asm("_" "sleep" );

long sysconf(int);
pid_t tcgetpgrp(int);
int tcsetpgrp(int, pid_t);
char *ttyname(int);


int ttyname_r(int, char *, size_t) __asm("_" "ttyname_r" );




int unlink(const char *);

ssize_t write(int, const void *, size_t) __asm("_" "write" );
}
extern "C" {
size_t confstr(int, char *, size_t) __asm("_" "confstr" );

int getopt(int, char * const [], const char *) __asm("_" "getopt" );

extern char *optarg;
extern int optind, opterr, optopt;
}
 extern "C" {





__attribute__((deprecated)) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))

void *brk(const void *);
int chroot(const char *) ;


char *crypt(const char *, const char *);






void encrypt(char *, int) __asm("_" "encrypt" );



int fchdir(int);
long gethostid(void);
pid_t getpgid(pid_t);
pid_t getsid(pid_t);



int getdtablesize(void) ;
int getpagesize(void) __attribute__((const)) ;
char *getpass(const char *) ;




char *getwd(char *) ;


int lchown(const char *, uid_t, gid_t) __asm("_" "lchown" );

int lockf(int, int, off_t) __asm("_" "lockf" );

int nice(int) __asm("_" "nice" );

ssize_t pread(int, void *, size_t, off_t) __asm("_" "pread" );

ssize_t pwrite(int, const void *, size_t, off_t) __asm("_" "pwrite" );






__attribute__((deprecated)) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))

void *sbrk(int);



pid_t setpgrp(void) __asm("_" "setpgrp" );




int setregid(gid_t, gid_t) __asm("_" "setregid" );

int setreuid(uid_t, uid_t) __asm("_" "setreuid" );

void swab(const void * , void * , ssize_t);
void sync(void);
int truncate(const char *, off_t);
useconds_t ualarm(useconds_t, useconds_t);
int usleep(useconds_t) __asm("_" "usleep" );
pid_t vfork(void) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));


int fsync(int) __asm("_" "fsync" );

int ftruncate(int, off_t);
int getlogin_r(char *, size_t);
}
extern "C" {
int fchown(int, uid_t, gid_t);
int gethostname(char *, size_t);
ssize_t readlink(const char * , char * , size_t);
int setegid(gid_t);
int seteuid(uid_t);
int symlink(const char *, const char *);
}








extern "C" {


int pselect(int, fd_set * , fd_set * ,
  fd_set * , const struct timespec * ,
  const sigset_t * )




  __asm("_" "pselect" )




  ;



int select(int, fd_set * , fd_set * ,
  fd_set * , struct timeval * )




  __asm("_" "select" )




  ;

}



typedef __darwin_uuid_t uuid_t;

extern "C" {
void _Exit(int) __attribute__((noreturn));
int accessx_np(const struct accessx_descriptor *, size_t, int *, uid_t);
int acct(const char *);
int add_profil(char *, size_t, unsigned long, unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
void endusershell(void);
int execvP(const char *, const char *, char * const *) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
char *fflagstostr(unsigned long);
int getdomainname(char *, int);
int getgrouplist(const char *, int, int *, int *);





int gethostuuid(uuid_t, const struct timespec *) __attribute__((availability(macosx,introduced=10.5)));




mode_t getmode(const void *, mode_t);
int getpeereid(int, uid_t *, gid_t *);
int getsgroups_np(int *, uuid_t);
char *getusershell(void);
int getwgroups_np(int *, uuid_t);
int initgroups(const char *, int);
int iruserok(unsigned long, int, const char *, const char *);
int iruserok_sa(const void *, int, int, const char *, const char *);
int issetugid(void);
char *mkdtemp(char *);
int mknod(const char *, mode_t, dev_t);
int mkpath_np(const char *path, mode_t omode) __attribute__((availability(macosx,introduced=10.8)));
int mkstemp(char *);
int mkstemps(char *, int);
char *mktemp(char *);
int nfssvc(int, void *);
int profil(char *, size_t, unsigned long, unsigned int);
int pthread_setugid_np(uid_t, gid_t);
int pthread_getugid_np( uid_t *, gid_t *);
int rcmd(char **, int, const char *, const char *, const char *, int *);
int rcmd_af(char **, int, const char *, const char *, const char *, int *,
  int);
int reboot(int);
int revoke(const char *);
int rresvport(int *);
int rresvport_af(int *, int);
int ruserok(const char *, int, const char *, const char *);
int setdomainname(const char *, int);
int setgroups(int, const gid_t *);
void sethostid(long);
int sethostname(const char *, int);

void setkey(const char *) __asm("_" "setkey" );



int setlogin(const char *);
void *setmode(const char *) __asm("_" "setmode" );
int setrgid(gid_t);
int setruid(uid_t);
int setsgroups_np(int, const uuid_t);
void setusershell(void);
int setwgroups_np(int, const uuid_t);
int strtofflags(char **, unsigned long *, unsigned long *);
int swapon(const char *);
int syscall(int, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int ttyslot(void);
int undelete(const char *);
int unwhiteout(const char *);
void *valloc(size_t);

extern char *suboptarg;
int getsubopt(char **, char * const *, char **);



int fgetattrlist(int,void*,void*,size_t,unsigned int) __attribute__((availability(macosx,introduced=10.6)));
int fsetattrlist(int,void*,void*,size_t,unsigned int) __attribute__((availability(macosx,introduced=10.6)));
int getattrlist(const char*,void*,void*,size_t,unsigned int) __asm("_" "getattrlist" );
int setattrlist(const char*,void*,void*,size_t,unsigned int) __asm("_" "setattrlist" );
int exchangedata(const char*,const char*,unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int getdirentriesattr(int,void*,void*,size_t,unsigned int*,unsigned int*,unsigned int*,unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
struct fssearchblock;
struct searchstate;

int searchfs(const char *, struct fssearchblock *, unsigned long *, unsigned int, unsigned int, struct searchstate *) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int fsctl(const char *,unsigned long,void*,unsigned int);
int ffsctl(int,unsigned long,void*,unsigned int) __attribute__((availability(macosx,introduced=10.6)));




int fsync_volume_np(int, int) __attribute__((availability(macosx,introduced=10.8)));
int sync_volume_np(const char *, int) __attribute__((availability(macosx,introduced=10.8)));

extern int optreset;

}





struct flock {
 off_t l_start;
 off_t l_len;
 pid_t l_pid;
 short l_type;
 short l_whence;
};
struct flocktimeout {
 struct flock fl;
 struct timespec timeout;
};
struct radvisory {
       off_t ra_offset;
       int ra_count;
};



typedef struct fcodeblobs {
 void *f_cd_hash;
 size_t f_hash_size;
 void *f_cd_buffer;
 size_t f_cd_size;
 unsigned int *f_out_size;
 int f_arch;
 int __padding;
} fcodeblobs_t;
typedef struct fsignatures {
 off_t fs_file_start;
 void *fs_blob_start;
 size_t fs_blob_size;
} fsignatures_t;
typedef struct fstore {
 unsigned int fst_flags;
 int fst_posmode;
 off_t fst_offset;
 off_t fst_length;
 off_t fst_bytesalloc;
} fstore_t;



typedef struct fbootstraptransfer {
  off_t fbt_offset;
  size_t fbt_length;
  void *fbt_buffer;
} fbootstraptransfer_t;
#pragma pack(4)

struct log2phys {
 unsigned int l2p_flags;
 off_t l2p_contigbytes;


 off_t l2p_devoffset;


};

#pragma pack()
struct _filesec;
typedef struct _filesec *filesec_t;

typedef enum {
 FILESEC_OWNER = 1,
 FILESEC_GROUP = 2,
 FILESEC_UUID = 3,
 FILESEC_MODE = 4,
 FILESEC_ACL = 5,
 FILESEC_GRPUUID = 6,


 FILESEC_ACL_RAW = 100,
 FILESEC_ACL_ALLOCSIZE = 101
} filesec_property_t;





extern "C" {
int open(const char *, int, ...) __asm("_" "open" );

int openat(int, const char *, int, ...) __asm("_" "openat" ) __attribute__((availability(macosx,introduced=10.10)));

int creat(const char *, mode_t) __asm("_" "creat" );
int fcntl(int, int, ...) __asm("_" "fcntl" );


int openx_np(const char *, int, filesec_t);




int open_dprotected_np ( const char *, int, int, int, ...);
int flock(int, int);
filesec_t filesec_init(void);
filesec_t filesec_dup(filesec_t);
void filesec_free(filesec_t);
int filesec_get_property(filesec_t, filesec_property_t, void *);
int filesec_query_property(filesec_t, filesec_property_t, int *);
int filesec_set_property(filesec_t, filesec_property_t, const void *);
int filesec_unset_property(filesec_t, filesec_property_t) __attribute__((availability(macosx,introduced=10.6)));



}




typedef struct objc_class *Class;


struct objc_object {
    Class isa __attribute__((deprecated));
};


typedef struct objc_object *id;



typedef struct objc_selector *SEL;





typedef id (*IMP)(id, SEL, ...);







typedef bool BOOL;
extern "C" __attribute__((visibility("default"))) const char *sel_getName(SEL sel)
    __attribute__((availability(macosx,introduced=10.0)));
extern "C" __attribute__((visibility("default"))) SEL sel_registerName(const char *str)
    __attribute__((availability(macosx,introduced=10.0)));
extern "C" __attribute__((visibility("default"))) const char *object_getClassName(id obj)
    __attribute__((availability(macosx,introduced=10.0)));
extern "C" __attribute__((visibility("default"))) void *object_getIndexedIvars(id obj)
    __attribute__((availability(macosx,introduced=10.0)));
extern "C" __attribute__((visibility("default"))) BOOL sel_isMapped(SEL sel)
    __attribute__((availability(macosx,introduced=10.0)));
extern "C" __attribute__((visibility("default"))) SEL sel_getUid(const char *str)
    __attribute__((availability(macosx,introduced=10.0)));





typedef const void* objc_objectptr_t;
typedef long NSInteger;
typedef unsigned long NSUInteger;

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSMethodSignature
#define _REWRITER_typedef_NSMethodSignature
typedef struct objc_object NSMethodSignature;
typedef struct {} _objc_exc_NSMethodSignature;
#endif

#ifndef _REWRITER_typedef_NSInvocation
#define _REWRITER_typedef_NSInvocation
typedef struct objc_object NSInvocation;
typedef struct {} _objc_exc_NSInvocation;
#endif


// @protocol NSObject

// - (BOOL)isEqual:(id)object;
// @property (readonly) NSUInteger hash;

// @property (readonly) Class superclass;
// - (Class)class __attribute__((availability(swift, unavailable, message="use 'anObject.dynamicType' instead")));
// - (instancetype)self;

// - (id)performSelector:(SEL)aSelector;
// - (id)performSelector:(SEL)aSelector withObject:(id)object;
// - (id)performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2;

// - (BOOL)isProxy;

// - (BOOL)isKindOfClass:(Class)aClass;
// - (BOOL)isMemberOfClass:(Class)aClass;
// - (BOOL)conformsToProtocol:(Protocol *)aProtocol;

// - (BOOL)respondsToSelector:(SEL)aSelector;

// - (instancetype)retain __attribute__((unavailable("not available in automatic reference counting mode")));
// - (oneway void)release __attribute__((unavailable("not available in automatic reference counting mode")));
// - (instancetype)autorelease __attribute__((unavailable("not available in automatic reference counting mode")));
// - (NSUInteger)retainCount __attribute__((unavailable("not available in automatic reference counting mode")));

// - (struct _NSZone *)zone __attribute__((unavailable("not available in automatic reference counting mode")));

// @property (readonly, copy) NSString *description;
/* @optional */
// @property (readonly, copy) NSString *debugDescription;

/* @end */



__attribute__((availability(macosx,introduced=10.0)))
__attribute__((objc_root_class))
extern "C" __attribute__((visibility("default")))

#ifndef _REWRITER_typedef_NSObject
#define _REWRITER_typedef_NSObject
typedef struct objc_object NSObject;
typedef struct {} _objc_exc_NSObject;
#endif

struct NSObject_IMPL {
	__unsafe_unretained Class isa;
};


// + (void)load;

// + (void)initialize;
#if 0
- (instancetype)init

    __attribute__((objc_designated_initializer))

    ;
#endif


// + (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
// + (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((availability(swift, unavailable, message="use object initializers instead")));
// + (instancetype)alloc __attribute__((availability(swift, unavailable, message="use object initializers instead")));
// - (void)dealloc __attribute__((availability(swift, unavailable, message="use 'deinit' to define a de-initializer")));

// - (void)finalize;

// - (id)copy;
// - (id)mutableCopy;

// + (id)copyWithZone:(struct _NSZone *)zone __attribute__((unavailable("not available in automatic reference counting mode")));
// + (id)mutableCopyWithZone:(struct _NSZone *)zone __attribute__((unavailable("not available in automatic reference counting mode")));

// + (BOOL)instancesRespondToSelector:(SEL)aSelector;
// + (BOOL)conformsToProtocol:(Protocol *)protocol;
// - (IMP)methodForSelector:(SEL)aSelector;
// + (IMP)instanceMethodForSelector:(SEL)aSelector;
// - (void)doesNotRecognizeSelector:(SEL)aSelector;

// - (id)forwardingTargetForSelector:(SEL)aSelector __attribute__((availability(macosx,introduced=10.5)));
// - (void)forwardInvocation:(NSInvocation *)anInvocation __attribute__((availability(swift, unavailable, message="")));
// - (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector __attribute__((availability(swift, unavailable, message="")));

// + (NSMethodSignature *)instanceMethodSignatureForSelector:(SEL)aSelector __attribute__((availability(swift, unavailable, message="")));

// - (BOOL)allowsWeakReference __attribute__((unavailable));
// - (BOOL)retainWeakReference __attribute__((unavailable));

// + (BOOL)isSubclassOfClass:(Class)aClass;

// + (BOOL)resolveClassMethod:(SEL)sel __attribute__((availability(macosx,introduced=10.5)));
// + (BOOL)resolveInstanceMethod:(SEL)sel __attribute__((availability(macosx,introduced=10.5)));

// + (NSUInteger)hash;
// + (Class)superclass;
// + (Class)class __attribute__((availability(swift, unavailable, message="use 'aClass.self' instead")));
// + (NSString *)description;
// + (NSString *)debugDescription;

/* @end */

extern "C" {
__attribute__((availability(macosx,introduced=10.10)))
extern __attribute__((__visibility__("default")))
void*
os_retain(void *object);
__attribute__((availability(macosx,introduced=10.10)))
extern __attribute__((__visibility__("default")))
void
os_release(void *object);





}
typedef void (*dispatch_function_t)(void *);
struct time_value {
 integer_t seconds;
 integer_t microseconds;
};

typedef struct time_value time_value_t;




typedef int alarm_type_t;
typedef int sleep_type_t;
typedef int clock_id_t;
typedef int clock_flavor_t;
typedef int *clock_attr_t;
typedef int clock_res_t;




struct mach_timespec {
 unsigned int tv_sec;
 clock_res_t tv_nsec;
};
typedef struct mach_timespec mach_timespec_t;
extern "C" {

struct timespec;
typedef uint64_t dispatch_time_t;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_time_t
dispatch_time(dispatch_time_t when, int64_t delta);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_time_t
dispatch_walltime(const struct timespec *when, int64_t delta);

}
// @protocol OS_dispatch_object <NSObject> /* @end */
 typedef NSObject/*<OS_dispatch_object>*/ *dispatch_object_t;



static __inline__ __attribute__((__always_inline__)) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
_dispatch_object_validate(dispatch_object_t object) {
 void *isa = *(void* volatile*)(__bridge void*)object;
 (void)isa;
}
typedef void (*dispatch_block_t)(void);


extern "C" {
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_retain(dispatch_object_t object);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_release(dispatch_object_t object);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__pure__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
void *
dispatch_get_context(dispatch_object_t object);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nothrow__))
void
dispatch_set_context(dispatch_object_t object, void *context);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nothrow__))
void
dispatch_set_finalizer_f(dispatch_object_t object,
  dispatch_function_t finalizer);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_suspend(dispatch_object_t object);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_resume(dispatch_object_t object);
__attribute__((__unavailable__))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
long
dispatch_wait(void *object, dispatch_time_t timeout);
__attribute__((__unavailable__))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_notify(void *object, dispatch_object_t queue,
  dispatch_block_t notification_block);
__attribute__((__unavailable__))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_cancel(void *object);
__attribute__((__unavailable__))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
long
dispatch_testcancel(void *object);
__attribute__((availability(macosx,introduced=10.6,deprecated=10.9)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nothrow__))
__attribute__((__format__(printf,2,3)))
void
dispatch_debug(dispatch_object_t object, const char *message, ...);

__attribute__((availability(macosx,introduced=10.6,deprecated=10.9)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nothrow__))
__attribute__((__format__(printf,2,0)))
void
dispatch_debugv(dispatch_object_t object, const char *message, va_list ap);

}
// @protocol OS_dispatch_queue <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_queue>*/ *dispatch_queue_t;

extern "C" {
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_async(dispatch_queue_t queue, dispatch_block_t block);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_async_f(dispatch_queue_t queue,
 void *context,
 dispatch_function_t work);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_sync(dispatch_queue_t queue, dispatch_block_t block);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_sync_f(dispatch_queue_t queue,
 void *context,
 dispatch_function_t work);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_apply(size_t iterations, dispatch_queue_t queue,
  void (*block)(size_t));
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(4))) __attribute__((__nothrow__))
void
dispatch_apply_f(size_t iterations, dispatch_queue_t queue,
 void *context,
 void (*work)(void *, size_t));
__attribute__((availability(macosx,introduced=10.6,deprecated=10.9)))
extern __attribute__((visibility("default"))) __attribute__((__pure__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_queue_t
dispatch_get_current_queue(void);

__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) struct dispatch_queue_s _dispatch_main_q;
static __inline__ __attribute__((__always_inline__)) __attribute__((__const__)) __attribute__((__nothrow__))
dispatch_queue_t
dispatch_get_main_queue(void)
{
 return ((__bridge dispatch_queue_t)&(_dispatch_main_q));
}
typedef long dispatch_queue_priority_t;







typedef enum : unsigned int { QOS_CLASS_USER_INTERACTIVE __attribute__((availability(macosx,introduced=10.10))) = 0x21, QOS_CLASS_USER_INITIATED __attribute__((availability(macosx,introduced=10.10))) = 0x19, QOS_CLASS_DEFAULT __attribute__((availability(macosx,introduced=10.10))) = 0x15, QOS_CLASS_UTILITY __attribute__((availability(macosx,introduced=10.10))) = 0x11, QOS_CLASS_BACKGROUND __attribute__((availability(macosx,introduced=10.10))) = 0x09, QOS_CLASS_UNSPECIFIED __attribute__((availability(macosx,introduced=10.10))) = 0x00, } qos_class_t;
extern "C" {
__attribute__((availability(macosx,introduced=10.10)))
qos_class_t
qos_class_self(void);
__attribute__((availability(macosx,introduced=10.10)))
qos_class_t
qos_class_main(void);

}
typedef qos_class_t dispatch_qos_class_t;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__const__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_queue_t
dispatch_get_global_queue(long identifier, unsigned long flags);







// @protocol OS_dispatch_queue_attr <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_queue_attr>*/ *dispatch_queue_attr_t;
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default")))
struct dispatch_queue_attr_s _dispatch_queue_attr_concurrent;
__attribute__((availability(macosx,introduced=10.10)))
extern __attribute__((visibility("default"))) __attribute__((__warn_unused_result__)) __attribute__((__pure__)) __attribute__((__nothrow__))
dispatch_queue_attr_t
dispatch_queue_attr_make_with_qos_class(dispatch_queue_attr_t attr,
  dispatch_qos_class_t qos_class, int relative_priority);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_queue_t
dispatch_queue_create(const char *label, dispatch_queue_attr_t attr);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__pure__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
const char *
dispatch_queue_get_label(dispatch_queue_t queue);
__attribute__((availability(macosx,introduced=10.10)))
extern __attribute__((visibility("default"))) __attribute__((__warn_unused_result__)) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
dispatch_qos_class_t
dispatch_queue_get_qos_class(dispatch_queue_t queue,
  int *relative_priority_ptr);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nothrow__))
void
dispatch_set_target_queue(dispatch_object_t object, dispatch_queue_t queue);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nothrow__)) __attribute__((__noreturn__))
void
dispatch_main(void);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_after(dispatch_time_t when,
 dispatch_queue_t queue,
 dispatch_block_t block);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nonnull__(4))) __attribute__((__nothrow__))
void
dispatch_after_f(dispatch_time_t when,
 dispatch_queue_t queue,
 void *context,
 dispatch_function_t work);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_barrier_async(dispatch_queue_t queue, dispatch_block_t block);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_barrier_async_f(dispatch_queue_t queue,
 void *context,
 dispatch_function_t work);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_barrier_sync(dispatch_queue_t queue, dispatch_block_t block);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_barrier_sync_f(dispatch_queue_t queue,
 void *context,
 dispatch_function_t work);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_queue_set_specific(dispatch_queue_t queue, const void *key,
 void *context, dispatch_function_t destructor);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__pure__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
void *
dispatch_queue_get_specific(dispatch_queue_t queue, const void *key);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__pure__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
void *
dispatch_get_specific(const void *key);

}
extern "C" {
typedef enum : unsigned long { DISPATCH_BLOCK_BARRIER __attribute__((availability(macosx,introduced=10.10))) = 0x1, DISPATCH_BLOCK_DETACHED __attribute__((availability(macosx,introduced=10.10))) = 0x2, DISPATCH_BLOCK_ASSIGN_CURRENT __attribute__((availability(macosx,introduced=10.10))) = 0x4, DISPATCH_BLOCK_NO_QOS_CLASS __attribute__((availability(macosx,introduced=10.10))) = 0x8, DISPATCH_BLOCK_INHERIT_QOS_CLASS __attribute__((availability(macosx,introduced=10.10))) = 0x10, DISPATCH_BLOCK_ENFORCE_QOS_CLASS __attribute__((availability(macosx,introduced=10.10))) = 0x20, } dispatch_block_flags_t;
__attribute__((availability(macosx,introduced=10.10)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_block_t
dispatch_block_create(dispatch_block_flags_t flags, dispatch_block_t block);
__attribute__((availability(macosx,introduced=10.10)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(4))) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_block_t
dispatch_block_create_with_qos_class(dispatch_block_flags_t flags,
  dispatch_qos_class_t qos_class, int relative_priority,
  dispatch_block_t block);
__attribute__((availability(macosx,introduced=10.10)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nothrow__))
void
dispatch_block_perform(dispatch_block_flags_t flags, dispatch_block_t block);
__attribute__((availability(macosx,introduced=10.10)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
long
dispatch_block_wait(dispatch_block_t block, dispatch_time_t timeout);
__attribute__((availability(macosx,introduced=10.10)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_block_notify(dispatch_block_t block, dispatch_queue_t queue,
  dispatch_block_t notification_block);
__attribute__((availability(macosx,introduced=10.10)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_block_cancel(dispatch_block_t block);
__attribute__((availability(macosx,introduced=10.10)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
long
dispatch_block_testcancel(dispatch_block_t block);

}
typedef int kern_return_t;
typedef natural_t mach_msg_timeout_t;
typedef unsigned int mach_msg_bits_t;
typedef natural_t mach_msg_size_t;
typedef integer_t mach_msg_id_t;




typedef unsigned int mach_msg_type_name_t;
typedef unsigned int mach_msg_copy_options_t;
typedef unsigned int mach_msg_descriptor_type_t;






#pragma pack(4)

typedef struct
{
  natural_t pad1;
  mach_msg_size_t pad2;
  unsigned int pad3 : 24;
  mach_msg_descriptor_type_t type : 8;
} mach_msg_type_descriptor_t;

typedef struct
{
  mach_port_t name;

  mach_msg_size_t pad1;
  unsigned int pad2 : 16;
  mach_msg_type_name_t disposition : 8;
  mach_msg_descriptor_type_t type : 8;
} mach_msg_port_descriptor_t;

typedef struct
{
  uint32_t address;
  mach_msg_size_t size;
  boolean_t deallocate: 8;
  mach_msg_copy_options_t copy: 8;
  unsigned int pad1: 8;
  mach_msg_descriptor_type_t type: 8;
} mach_msg_ool_descriptor32_t;

typedef struct
{
  uint64_t address;
  boolean_t deallocate: 8;
  mach_msg_copy_options_t copy: 8;
  unsigned int pad1: 8;
  mach_msg_descriptor_type_t type: 8;
  mach_msg_size_t size;
} mach_msg_ool_descriptor64_t;

typedef struct
{
  void* address;



  boolean_t deallocate: 8;
  mach_msg_copy_options_t copy: 8;
  unsigned int pad1: 8;
  mach_msg_descriptor_type_t type: 8;

  mach_msg_size_t size;

} mach_msg_ool_descriptor_t;

typedef struct
{
  uint32_t address;
  mach_msg_size_t count;
  boolean_t deallocate: 8;
  mach_msg_copy_options_t copy: 8;
  mach_msg_type_name_t disposition : 8;
  mach_msg_descriptor_type_t type : 8;
} mach_msg_ool_ports_descriptor32_t;

typedef struct
{
  uint64_t address;
  boolean_t deallocate: 8;
  mach_msg_copy_options_t copy: 8;
  mach_msg_type_name_t disposition : 8;
  mach_msg_descriptor_type_t type : 8;
  mach_msg_size_t count;
} mach_msg_ool_ports_descriptor64_t;

typedef struct
{
  void* address;



  boolean_t deallocate: 8;
  mach_msg_copy_options_t copy: 8;
  mach_msg_type_name_t disposition : 8;
  mach_msg_descriptor_type_t type : 8;

  mach_msg_size_t count;

} mach_msg_ool_ports_descriptor_t;






typedef union
{
  mach_msg_port_descriptor_t port;
  mach_msg_ool_descriptor_t out_of_line;
  mach_msg_ool_ports_descriptor_t ool_ports;
  mach_msg_type_descriptor_t type;
} mach_msg_descriptor_t;

typedef struct
{
        mach_msg_size_t msgh_descriptor_count;
} mach_msg_body_t;




typedef struct
{
  mach_msg_bits_t msgh_bits;
  mach_msg_size_t msgh_size;
  mach_port_t msgh_remote_port;
  mach_port_t msgh_local_port;
  mach_port_name_t msgh_voucher_port;
  mach_msg_id_t msgh_id;
} mach_msg_header_t;




typedef struct
{
        mach_msg_header_t header;
        mach_msg_body_t body;
} mach_msg_base_t;

typedef unsigned int mach_msg_trailer_type_t;



typedef unsigned int mach_msg_trailer_size_t;
typedef char *mach_msg_trailer_info_t;

typedef struct
{
  mach_msg_trailer_type_t msgh_trailer_type;
  mach_msg_trailer_size_t msgh_trailer_size;
} mach_msg_trailer_t;
typedef struct
{
  mach_msg_trailer_type_t msgh_trailer_type;
  mach_msg_trailer_size_t msgh_trailer_size;
  mach_port_seqno_t msgh_seqno;
} mach_msg_seqno_trailer_t;

typedef struct
{
  unsigned int val[2];
} security_token_t;

typedef struct
{
  mach_msg_trailer_type_t msgh_trailer_type;
  mach_msg_trailer_size_t msgh_trailer_size;
  mach_port_seqno_t msgh_seqno;
  security_token_t msgh_sender;
} mach_msg_security_trailer_t;
typedef struct
{
  unsigned int val[8];
} audit_token_t;

typedef struct
{
  mach_msg_trailer_type_t msgh_trailer_type;
  mach_msg_trailer_size_t msgh_trailer_size;
  mach_port_seqno_t msgh_seqno;
  security_token_t msgh_sender;
  audit_token_t msgh_audit;
} mach_msg_audit_trailer_t;

typedef struct
{
  mach_msg_trailer_type_t msgh_trailer_type;
  mach_msg_trailer_size_t msgh_trailer_size;
  mach_port_seqno_t msgh_seqno;
  security_token_t msgh_sender;
  audit_token_t msgh_audit;
  mach_port_context_t msgh_context;
} mach_msg_context_trailer_t;



typedef struct
{
  mach_port_name_t sender;
} msg_labels_t;






typedef struct
{
  mach_msg_trailer_type_t msgh_trailer_type;
  mach_msg_trailer_size_t msgh_trailer_size;
  mach_port_seqno_t msgh_seqno;
  security_token_t msgh_sender;
  audit_token_t msgh_audit;
  mach_port_context_t msgh_context;
  int msgh_ad;
  msg_labels_t msgh_labels;
} mach_msg_mac_trailer_t;
typedef mach_msg_mac_trailer_t mach_msg_max_trailer_t;
typedef mach_msg_security_trailer_t mach_msg_format_0_trailer_t;







extern security_token_t KERNEL_SECURITY_TOKEN;


extern audit_token_t KERNEL_AUDIT_TOKEN;

typedef integer_t mach_msg_options_t;

typedef struct
{
  mach_msg_header_t header;
} mach_msg_empty_send_t;

typedef struct
{
  mach_msg_header_t header;
  mach_msg_trailer_t trailer;
} mach_msg_empty_rcv_t;

typedef union
{
  mach_msg_empty_send_t send;
  mach_msg_empty_rcv_t rcv;
} mach_msg_empty_t;

#pragma pack()
typedef natural_t mach_msg_type_size_t;
typedef natural_t mach_msg_type_number_t;
typedef integer_t mach_msg_option_t;
typedef kern_return_t mach_msg_return_t;
extern "C" {
__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
extern mach_msg_return_t mach_msg_overwrite(
     mach_msg_header_t *msg,
     mach_msg_option_t option,
     mach_msg_size_t send_size,
     mach_msg_size_t rcv_size,
     mach_port_name_t rcv_name,
     mach_msg_timeout_t timeout,
     mach_port_name_t notify,
     mach_msg_header_t *rcv_msg,
     mach_msg_size_t rcv_limit);
__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
extern mach_msg_return_t mach_msg(
     mach_msg_header_t *msg,
     mach_msg_option_t option,
     mach_msg_size_t send_size,
     mach_msg_size_t rcv_size,
     mach_port_name_t rcv_name,
     mach_msg_timeout_t timeout,
     mach_port_name_t notify);







__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
extern kern_return_t mach_voucher_deallocate(
     mach_port_name_t voucher);


}
// @protocol OS_dispatch_source <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_source>*/ *dispatch_source_t;

extern "C" {
typedef const struct dispatch_source_type_s *dispatch_source_type_t;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_data_add;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_data_or;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_mach_send;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_mach_recv;
__attribute__((availability(macosx,introduced=10.9)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_memorypressure;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_proc;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_read;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_signal;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_timer;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_vnode;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) const struct dispatch_source_type_s _dispatch_source_type_write;
typedef unsigned long dispatch_source_mach_send_flags_t;
typedef unsigned long dispatch_source_memorypressure_flags_t;
typedef unsigned long dispatch_source_proc_flags_t;
typedef unsigned long dispatch_source_vnode_flags_t;
typedef unsigned long dispatch_source_timer_flags_t;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_source_t
dispatch_source_create(dispatch_source_type_t type,
 uintptr_t handle,
 unsigned long mask,
 dispatch_queue_t queue);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_event_handler(dispatch_source_t source,
 dispatch_block_t handler);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_event_handler_f(dispatch_source_t source,
 dispatch_function_t handler);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_cancel_handler(dispatch_source_t source,
 dispatch_block_t handler);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_cancel_handler_f(dispatch_source_t source,
 dispatch_function_t handler);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_source_cancel(dispatch_source_t source);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
long
dispatch_source_testcancel(dispatch_source_t source);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
uintptr_t
dispatch_source_get_handle(dispatch_source_t source);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
unsigned long
dispatch_source_get_mask(dispatch_source_t source);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__pure__))
__attribute__((__nothrow__))
unsigned long
dispatch_source_get_data(dispatch_source_t source);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_source_merge_data(dispatch_source_t source, unsigned long value);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_source_set_timer(dispatch_source_t source,
 dispatch_time_t start,
 uint64_t interval,
 uint64_t leeway);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_registration_handler(dispatch_source_t source,
 dispatch_block_t handler);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_source_set_registration_handler_f(dispatch_source_t source,
 dispatch_function_t handler);

}
// @protocol OS_dispatch_group <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_group>*/ *dispatch_group_t;

extern "C" {
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_group_t
dispatch_group_create(void);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_group_async(dispatch_group_t group,
 dispatch_queue_t queue,
 dispatch_block_t block);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(2))) __attribute__((__nonnull__(4)))
__attribute__((__nothrow__))
void
dispatch_group_async_f(dispatch_group_t group,
 dispatch_queue_t queue,
 void *context,
 dispatch_function_t work);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
long
dispatch_group_wait(dispatch_group_t group, dispatch_time_t timeout);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_group_notify(dispatch_group_t group,
 dispatch_queue_t queue,
 dispatch_block_t block);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(2))) __attribute__((__nonnull__(4)))
__attribute__((__nothrow__))
void
dispatch_group_notify_f(dispatch_group_t group,
 dispatch_queue_t queue,
 void *context,
 dispatch_function_t work);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_group_enter(dispatch_group_t group);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_group_leave(dispatch_group_t group);

}
// @protocol OS_dispatch_semaphore <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_semaphore>*/ *dispatch_semaphore_t;

extern "C" {
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_semaphore_t
dispatch_semaphore_create(long value);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
long
dispatch_semaphore_wait(dispatch_semaphore_t dsema, dispatch_time_t timeout);
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
long
dispatch_semaphore_signal(dispatch_semaphore_t dsema);

}
extern "C" {
typedef long dispatch_once_t;
__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_once(dispatch_once_t *predicate, dispatch_block_t block);

static __inline__ __attribute__((__always_inline__)) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
_dispatch_once(dispatch_once_t *predicate, dispatch_block_t block)
{
 if (__builtin_expect((*predicate), (~0l)) != ~0l) {
  dispatch_once(predicate, block);
 }
}




__attribute__((availability(macosx,introduced=10.6)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nothrow__))
void
dispatch_once_f(dispatch_once_t *predicate, void *context,
  dispatch_function_t function);

static __inline__ __attribute__((__always_inline__)) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3)))
__attribute__((__nothrow__))
void
_dispatch_once_f(dispatch_once_t *predicate, void *context,
  dispatch_function_t function)
{
 if (__builtin_expect((*predicate), (~0l)) != ~0l) {
  dispatch_once_f(predicate, context, function);
 }
}



}
extern "C" {
// @protocol OS_dispatch_data <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_data>*/ *dispatch_data_t;
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) struct dispatch_data_s _dispatch_data_empty;
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) const dispatch_block_t _dispatch_data_destructor_free;







__attribute__((availability(macosx,introduced=10.9)))
extern __attribute__((visibility("default"))) const dispatch_block_t _dispatch_data_destructor_munmap;
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_data_t
dispatch_data_create(const void *buffer,
 size_t size,
 dispatch_queue_t queue,
 dispatch_block_t destructor);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__pure__)) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
size_t
dispatch_data_get_size(dispatch_data_t data);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_data_t
dispatch_data_create_map(dispatch_data_t data,
 const void **buffer_ptr,
 size_t *size_ptr);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_data_t
dispatch_data_create_concat(dispatch_data_t data1, dispatch_data_t data2);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_data_t
dispatch_data_create_subrange(dispatch_data_t data,
 size_t offset,
 size_t length);
typedef bool (*dispatch_data_applier_t)(dispatch_data_t region,
 size_t offset,
 const void *buffer,
 size_t size);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
bool
dispatch_data_apply(dispatch_data_t data, dispatch_data_applier_t applier);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_data_t
dispatch_data_copy_region(dispatch_data_t data,
 size_t location,
 size_t *offset_ptr);

}
extern "C" {
typedef int dispatch_fd_t;
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(3))) __attribute__((__nonnull__(4))) __attribute__((__nothrow__))
void
dispatch_read(dispatch_fd_t fd,
 size_t length,
 dispatch_queue_t queue,
 void (*handler)(dispatch_data_t data, int error));
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__nonnull__(3))) __attribute__((__nonnull__(4)))
__attribute__((__nothrow__))
void
dispatch_write(dispatch_fd_t fd,
 dispatch_data_t data,
 dispatch_queue_t queue,
 void (*handler)(dispatch_data_t data, int error));
// @protocol OS_dispatch_io <OS_dispatch_object> /* @end */
 typedef NSObject/*<OS_dispatch_io>*/ *dispatch_io_t;
typedef unsigned long dispatch_io_type_t;
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__)) __attribute__((__warn_unused_result__))
__attribute__((__nothrow__))
dispatch_io_t
dispatch_io_create(dispatch_io_type_t type,
 dispatch_fd_t fd,
 dispatch_queue_t queue,
 void (*cleanup_handler)(int error));
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_io_t
dispatch_io_create_with_path(dispatch_io_type_t type,
 const char *path, int oflag, mode_t mode,
 dispatch_queue_t queue,
 void (*cleanup_handler)(int error));
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(2))) __attribute__((__malloc__)) __attribute__((__ns_returns_retained__))
__attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_io_t
dispatch_io_create_with_io(dispatch_io_type_t type,
 dispatch_io_t io,
 dispatch_queue_t queue,
 void (*cleanup_handler)(int error));
typedef void (*dispatch_io_handler_t)(bool done, dispatch_data_t data,
  int error);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(4))) __attribute__((__nonnull__(5)))
__attribute__((__nothrow__))
void
dispatch_io_read(dispatch_io_t channel,
 off_t offset,
 size_t length,
 dispatch_queue_t queue,
 dispatch_io_handler_t io_handler);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nonnull__(3))) __attribute__((__nonnull__(4)))
__attribute__((__nonnull__(5))) __attribute__((__nothrow__))
void
dispatch_io_write(dispatch_io_t channel,
 off_t offset,
 dispatch_data_t data,
 dispatch_queue_t queue,
 dispatch_io_handler_t io_handler);
typedef unsigned long dispatch_io_close_flags_t;
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_io_close(dispatch_io_t channel, dispatch_io_close_flags_t flags);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__nothrow__))
void
dispatch_io_barrier(dispatch_io_t channel, dispatch_block_t barrier);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__)) __attribute__((__warn_unused_result__)) __attribute__((__nothrow__))
dispatch_fd_t
dispatch_io_get_descriptor(dispatch_io_t channel);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_io_set_high_water(dispatch_io_t channel, size_t high_water);
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_io_set_low_water(dispatch_io_t channel, size_t low_water);
typedef unsigned long dispatch_io_interval_flags_t;
__attribute__((availability(macosx,introduced=10.7)))
extern __attribute__((visibility("default"))) __attribute__((__nonnull__(1))) __attribute__((__nothrow__))
void
dispatch_io_set_interval(dispatch_io_t channel,
 uint64_t interval,
 dispatch_io_interval_flags_t flags);

}


extern "C" {

typedef CFIndex CFStreamStatus; enum {
    kCFStreamStatusNotOpen = 0,
    kCFStreamStatusOpening,
    kCFStreamStatusOpen,
    kCFStreamStatusReading,
    kCFStreamStatusWriting,
    kCFStreamStatusAtEnd,
    kCFStreamStatusClosed,
    kCFStreamStatusError
};

typedef CFOptionFlags CFStreamEventType; enum {
    kCFStreamEventNone = 0,
    kCFStreamEventOpenCompleted = 1,
    kCFStreamEventHasBytesAvailable = 2,
    kCFStreamEventCanAcceptBytes = 4,
    kCFStreamEventErrorOccurred = 8,
    kCFStreamEventEndEncountered = 16
};

typedef struct {
    CFIndex version;
    void *info;
    void *(*retain)(void *info);
    void (*release)(void *info);
    CFStringRef (*copyDescription)(void *info);
} CFStreamClientContext;

typedef struct __attribute__((objc_bridge_mutable(NSInputStream))) __CFReadStream * CFReadStreamRef;
typedef struct __attribute__((objc_bridge_mutable(NSOutputStream))) __CFWriteStream * CFWriteStreamRef;

typedef void (*CFReadStreamClientCallBack)(CFReadStreamRef stream, CFStreamEventType type, void *clientCallBackInfo);
typedef void (*CFWriteStreamClientCallBack)(CFWriteStreamRef stream, CFStreamEventType type, void *clientCallBackInfo);

extern
CFTypeID CFReadStreamGetTypeID(void);
extern
CFTypeID CFWriteStreamGetTypeID(void);




extern
const CFStringRef kCFStreamPropertyDataWritten;


extern
CFReadStreamRef CFReadStreamCreateWithBytesNoCopy(CFAllocatorRef alloc, const UInt8 *bytes, CFIndex length, CFAllocatorRef bytesDeallocator);


extern
CFWriteStreamRef CFWriteStreamCreateWithBuffer(CFAllocatorRef alloc, UInt8 *buffer, CFIndex bufferCapacity);


extern
CFWriteStreamRef CFWriteStreamCreateWithAllocatedBuffers(CFAllocatorRef alloc, CFAllocatorRef bufferAllocator);


extern
CFReadStreamRef CFReadStreamCreateWithFile(CFAllocatorRef alloc, CFURLRef fileURL);
extern
CFWriteStreamRef CFWriteStreamCreateWithFile(CFAllocatorRef alloc, CFURLRef fileURL);

extern
void CFStreamCreateBoundPair(CFAllocatorRef alloc, CFReadStreamRef *readStream, CFWriteStreamRef *writeStream, CFIndex transferBufferSize);



extern
const CFStringRef kCFStreamPropertyAppendToFile;

extern
const CFStringRef kCFStreamPropertyFileCurrentOffset;





extern
const CFStringRef kCFStreamPropertySocketNativeHandle;


extern
const CFStringRef kCFStreamPropertySocketRemoteHostName;


extern
const CFStringRef kCFStreamPropertySocketRemotePortNumber;



extern
void CFStreamCreatePairWithSocket(CFAllocatorRef alloc, CFSocketNativeHandle sock, CFReadStreamRef *readStream, CFWriteStreamRef *writeStream);
extern
void CFStreamCreatePairWithSocketToHost(CFAllocatorRef alloc, CFStringRef host, UInt32 port, CFReadStreamRef *readStream, CFWriteStreamRef *writeStream);
extern
void CFStreamCreatePairWithPeerSocketSignature(CFAllocatorRef alloc, const CFSocketSignature *signature, CFReadStreamRef *readStream, CFWriteStreamRef *writeStream);




extern
CFStreamStatus CFReadStreamGetStatus(CFReadStreamRef stream);
extern
CFStreamStatus CFWriteStreamGetStatus(CFWriteStreamRef stream);


extern
CFErrorRef CFReadStreamCopyError(CFReadStreamRef stream) __attribute__((availability(ios,introduced=2_0)));
extern
CFErrorRef CFWriteStreamCopyError(CFWriteStreamRef stream) __attribute__((availability(ios,introduced=2_0)));






extern
Boolean CFReadStreamOpen(CFReadStreamRef stream);
extern
Boolean CFWriteStreamOpen(CFWriteStreamRef stream);




extern
void CFReadStreamClose(CFReadStreamRef stream);
extern
void CFWriteStreamClose(CFWriteStreamRef stream);



extern
Boolean CFReadStreamHasBytesAvailable(CFReadStreamRef stream);
extern
CFIndex CFReadStreamRead(CFReadStreamRef stream, UInt8 *buffer, CFIndex bufferLength);
extern
const UInt8 *CFReadStreamGetBuffer(CFReadStreamRef stream, CFIndex maxBytesToRead, CFIndex *numBytesRead);



extern
Boolean CFWriteStreamCanAcceptBytes(CFWriteStreamRef stream);






extern
CFIndex CFWriteStreamWrite(CFWriteStreamRef stream, const UInt8 *buffer, CFIndex bufferLength);
extern
CFTypeRef CFReadStreamCopyProperty(CFReadStreamRef stream, CFStringRef propertyName);
extern
CFTypeRef CFWriteStreamCopyProperty(CFWriteStreamRef stream, CFStringRef propertyName);



extern
Boolean CFReadStreamSetProperty(CFReadStreamRef stream, CFStringRef propertyName, CFTypeRef propertyValue);
extern
Boolean CFWriteStreamSetProperty(CFWriteStreamRef stream, CFStringRef propertyName, CFTypeRef propertyValue);
extern
Boolean CFReadStreamSetClient(CFReadStreamRef stream, CFOptionFlags streamEvents, CFReadStreamClientCallBack clientCB, CFStreamClientContext *clientContext);
extern
Boolean CFWriteStreamSetClient(CFWriteStreamRef stream, CFOptionFlags streamEvents, CFWriteStreamClientCallBack clientCB, CFStreamClientContext *clientContext);

extern
void CFReadStreamScheduleWithRunLoop(CFReadStreamRef stream, CFRunLoopRef runLoop, CFStringRef runLoopMode);
extern
void CFWriteStreamScheduleWithRunLoop(CFWriteStreamRef stream, CFRunLoopRef runLoop, CFStringRef runLoopMode);

extern
void CFReadStreamUnscheduleFromRunLoop(CFReadStreamRef stream, CFRunLoopRef runLoop, CFStringRef runLoopMode);
extern
void CFWriteStreamUnscheduleFromRunLoop(CFWriteStreamRef stream, CFRunLoopRef runLoop, CFStringRef runLoopMode);
extern
void CFReadStreamSetDispatchQueue(CFReadStreamRef stream, dispatch_queue_t q) __attribute__((availability(ios,introduced=7_0)));

extern
void CFWriteStreamSetDispatchQueue(CFWriteStreamRef stream, dispatch_queue_t q) __attribute__((availability(ios,introduced=7_0)));






extern
dispatch_queue_t CFReadStreamCopyDispatchQueue(CFReadStreamRef stream) __attribute__((availability(ios,introduced=7_0)));

extern
dispatch_queue_t CFWriteStreamCopyDispatchQueue(CFWriteStreamRef stream) __attribute__((availability(ios,introduced=7_0)));


typedef CFIndex CFStreamErrorDomain; enum {
    kCFStreamErrorDomainCustom = -1L,
    kCFStreamErrorDomainPOSIX = 1,
    kCFStreamErrorDomainMacOSStatus
};

typedef struct {
    CFIndex domain;
    SInt32 error;
} CFStreamError;
extern
CFStreamError CFReadStreamGetError(CFReadStreamRef stream);
extern
CFStreamError CFWriteStreamGetError(CFWriteStreamRef stream);


}



extern "C" {

typedef CFOptionFlags CFPropertyListMutabilityOptions; enum {
    kCFPropertyListImmutable = 0,
    kCFPropertyListMutableContainers,
    kCFPropertyListMutableContainersAndLeaves
};
extern
CFPropertyListRef CFPropertyListCreateFromXMLData(CFAllocatorRef allocator, CFDataRef xmlData, CFOptionFlags mutabilityOption, CFStringRef *errorString) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFPropertyListCreateWithData instead.")));
extern
CFDataRef CFPropertyListCreateXMLData(CFAllocatorRef allocator, CFPropertyListRef propertyList) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFPropertyListCreateData instead.")));
extern
CFPropertyListRef CFPropertyListCreateDeepCopy(CFAllocatorRef allocator, CFPropertyListRef propertyList, CFOptionFlags mutabilityOption);

typedef CFIndex CFPropertyListFormat; enum {
    kCFPropertyListOpenStepFormat = 1,
    kCFPropertyListXMLFormat_v1_0 = 100,
    kCFPropertyListBinaryFormat_v1_0 = 200
};






extern
Boolean CFPropertyListIsValid(CFPropertyListRef plist, CFPropertyListFormat format);
extern
CFIndex CFPropertyListWriteToStream(CFPropertyListRef propertyList, CFWriteStreamRef stream, CFPropertyListFormat format, CFStringRef *errorString) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFPropertyListWrite instead.")));
extern
CFPropertyListRef CFPropertyListCreateFromStream(CFAllocatorRef allocator, CFReadStreamRef stream, CFIndex streamLength, CFOptionFlags mutabilityOption, CFPropertyListFormat *format, CFStringRef *errorString) __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use CFPropertyListCreateWithStream instead.")));






enum {
    kCFPropertyListReadCorruptError = 3840,
    kCFPropertyListReadUnknownVersionError = 3841,
    kCFPropertyListReadStreamError = 3842,
    kCFPropertyListWriteStreamError = 3851,
} __attribute__((availability(ios,introduced=4_0)));



extern
CFPropertyListRef CFPropertyListCreateWithData(CFAllocatorRef allocator, CFDataRef data, CFOptionFlags options, CFPropertyListFormat *format, CFErrorRef *error) __attribute__((availability(ios,introduced=4_0)));





extern
CFPropertyListRef CFPropertyListCreateWithStream(CFAllocatorRef allocator, CFReadStreamRef stream, CFIndex streamLength, CFOptionFlags options, CFPropertyListFormat *format, CFErrorRef *error) __attribute__((availability(ios,introduced=4_0)));



extern
CFIndex CFPropertyListWrite(CFPropertyListRef propertyList, CFWriteStreamRef stream, CFPropertyListFormat format, CFOptionFlags options, CFErrorRef *error) __attribute__((availability(ios,introduced=4_0)));





extern
CFDataRef CFPropertyListCreateData(CFAllocatorRef allocator, CFPropertyListRef propertyList, CFPropertyListFormat format, CFOptionFlags options, CFErrorRef *error) __attribute__((availability(ios,introduced=4_0)));



}
extern "C" {
typedef const void * (*CFSetRetainCallBack)(CFAllocatorRef allocator, const void *value);







typedef void (*CFSetReleaseCallBack)(CFAllocatorRef allocator, const void *value);







typedef CFStringRef (*CFSetCopyDescriptionCallBack)(const void *value);
typedef Boolean (*CFSetEqualCallBack)(const void *value1, const void *value2);







typedef CFHashCode (*CFSetHashCallBack)(const void *value);
typedef struct {
    CFIndex version;
    CFSetRetainCallBack retain;
    CFSetReleaseCallBack release;
    CFSetCopyDescriptionCallBack copyDescription;
    CFSetEqualCallBack equal;
    CFSetHashCallBack hash;
} CFSetCallBacks;






extern
const CFSetCallBacks kCFTypeSetCallBacks;







extern
const CFSetCallBacks kCFCopyStringSetCallBacks;
typedef void (*CFSetApplierFunction)(const void *value, void *context);





typedef const struct __attribute__((objc_bridge(NSSet))) __CFSet * CFSetRef;





typedef struct __attribute__((objc_bridge_mutable(NSMutableSet))) __CFSet * CFMutableSetRef;





extern
CFTypeID CFSetGetTypeID(void);
extern
CFSetRef CFSetCreate(CFAllocatorRef allocator, const void **values, CFIndex numValues, const CFSetCallBacks *callBacks);
extern
CFSetRef CFSetCreateCopy(CFAllocatorRef allocator, CFSetRef theSet);
extern
CFMutableSetRef CFSetCreateMutable(CFAllocatorRef allocator, CFIndex capacity, const CFSetCallBacks *callBacks);
extern
CFMutableSetRef CFSetCreateMutableCopy(CFAllocatorRef allocator, CFIndex capacity, CFSetRef theSet);
extern
CFIndex CFSetGetCount(CFSetRef theSet);
extern
CFIndex CFSetGetCountOfValue(CFSetRef theSet, const void *value);
extern
Boolean CFSetContainsValue(CFSetRef theSet, const void *value);
extern
const void *CFSetGetValue(CFSetRef theSet, const void *value);
extern
Boolean CFSetGetValueIfPresent(CFSetRef theSet, const void *candidate, const void **value);
extern
void CFSetGetValues(CFSetRef theSet, const void **values);
extern
void CFSetApplyFunction(CFSetRef theSet, CFSetApplierFunction applier, void *context);
extern
void CFSetAddValue(CFMutableSetRef theSet, const void *value);
extern
void CFSetReplaceValue(CFMutableSetRef theSet, const void *value);
extern
void CFSetSetValue(CFMutableSetRef theSet, const void *value);
extern
void CFSetRemoveValue(CFMutableSetRef theSet, const void *value);
extern
void CFSetRemoveAllValues(CFMutableSetRef theSet);

}

extern "C" {

typedef CFIndex CFStringEncodings; enum {

    kCFStringEncodingMacJapanese = 1,
    kCFStringEncodingMacChineseTrad = 2,
    kCFStringEncodingMacKorean = 3,
    kCFStringEncodingMacArabic = 4,
    kCFStringEncodingMacHebrew = 5,
    kCFStringEncodingMacGreek = 6,
    kCFStringEncodingMacCyrillic = 7,
    kCFStringEncodingMacDevanagari = 9,
    kCFStringEncodingMacGurmukhi = 10,
    kCFStringEncodingMacGujarati = 11,
    kCFStringEncodingMacOriya = 12,
    kCFStringEncodingMacBengali = 13,
    kCFStringEncodingMacTamil = 14,
    kCFStringEncodingMacTelugu = 15,
    kCFStringEncodingMacKannada = 16,
    kCFStringEncodingMacMalayalam = 17,
    kCFStringEncodingMacSinhalese = 18,
    kCFStringEncodingMacBurmese = 19,
    kCFStringEncodingMacKhmer = 20,
    kCFStringEncodingMacThai = 21,
    kCFStringEncodingMacLaotian = 22,
    kCFStringEncodingMacGeorgian = 23,
    kCFStringEncodingMacArmenian = 24,
    kCFStringEncodingMacChineseSimp = 25,
    kCFStringEncodingMacTibetan = 26,
    kCFStringEncodingMacMongolian = 27,
    kCFStringEncodingMacEthiopic = 28,
    kCFStringEncodingMacCentralEurRoman = 29,
    kCFStringEncodingMacVietnamese = 30,
    kCFStringEncodingMacExtArabic = 31,

    kCFStringEncodingMacSymbol = 33,
    kCFStringEncodingMacDingbats = 34,
    kCFStringEncodingMacTurkish = 35,
    kCFStringEncodingMacCroatian = 36,
    kCFStringEncodingMacIcelandic = 37,
    kCFStringEncodingMacRomanian = 38,
    kCFStringEncodingMacCeltic = 39,
    kCFStringEncodingMacGaelic = 40,

    kCFStringEncodingMacFarsi = 0x8C,

    kCFStringEncodingMacUkrainian = 0x98,

    kCFStringEncodingMacInuit = 0xEC,
    kCFStringEncodingMacVT100 = 0xFC,

    kCFStringEncodingMacHFS = 0xFF,






    kCFStringEncodingISOLatin2 = 0x0202,
    kCFStringEncodingISOLatin3 = 0x0203,
    kCFStringEncodingISOLatin4 = 0x0204,
    kCFStringEncodingISOLatinCyrillic = 0x0205,
    kCFStringEncodingISOLatinArabic = 0x0206,
    kCFStringEncodingISOLatinGreek = 0x0207,
    kCFStringEncodingISOLatinHebrew = 0x0208,
    kCFStringEncodingISOLatin5 = 0x0209,
    kCFStringEncodingISOLatin6 = 0x020A,
    kCFStringEncodingISOLatinThai = 0x020B,
    kCFStringEncodingISOLatin7 = 0x020D,
    kCFStringEncodingISOLatin8 = 0x020E,
    kCFStringEncodingISOLatin9 = 0x020F,
    kCFStringEncodingISOLatin10 = 0x0210,


    kCFStringEncodingDOSLatinUS = 0x0400,
    kCFStringEncodingDOSGreek = 0x0405,
    kCFStringEncodingDOSBalticRim = 0x0406,
    kCFStringEncodingDOSLatin1 = 0x0410,
    kCFStringEncodingDOSGreek1 = 0x0411,
    kCFStringEncodingDOSLatin2 = 0x0412,
    kCFStringEncodingDOSCyrillic = 0x0413,
    kCFStringEncodingDOSTurkish = 0x0414,
    kCFStringEncodingDOSPortuguese = 0x0415,
    kCFStringEncodingDOSIcelandic = 0x0416,
    kCFStringEncodingDOSHebrew = 0x0417,
    kCFStringEncodingDOSCanadianFrench = 0x0418,
    kCFStringEncodingDOSArabic = 0x0419,
    kCFStringEncodingDOSNordic = 0x041A,
    kCFStringEncodingDOSRussian = 0x041B,
    kCFStringEncodingDOSGreek2 = 0x041C,
    kCFStringEncodingDOSThai = 0x041D,
    kCFStringEncodingDOSJapanese = 0x0420,
    kCFStringEncodingDOSChineseSimplif = 0x0421,
    kCFStringEncodingDOSKorean = 0x0422,
    kCFStringEncodingDOSChineseTrad = 0x0423,

    kCFStringEncodingWindowsLatin2 = 0x0501,
    kCFStringEncodingWindowsCyrillic = 0x0502,
    kCFStringEncodingWindowsGreek = 0x0503,
    kCFStringEncodingWindowsLatin5 = 0x0504,
    kCFStringEncodingWindowsHebrew = 0x0505,
    kCFStringEncodingWindowsArabic = 0x0506,
    kCFStringEncodingWindowsBalticRim = 0x0507,
    kCFStringEncodingWindowsVietnamese = 0x0508,
    kCFStringEncodingWindowsKoreanJohab = 0x0510,



    kCFStringEncodingANSEL = 0x0601,
    kCFStringEncodingJIS_X0201_76 = 0x0620,
    kCFStringEncodingJIS_X0208_83 = 0x0621,
    kCFStringEncodingJIS_X0208_90 = 0x0622,
    kCFStringEncodingJIS_X0212_90 = 0x0623,
    kCFStringEncodingJIS_C6226_78 = 0x0624,
    kCFStringEncodingShiftJIS_X0213 __attribute__((availability(ios,introduced=2_0))) = 0x0628,
    kCFStringEncodingShiftJIS_X0213_MenKuTen = 0x0629,
    kCFStringEncodingGB_2312_80 = 0x0630,
    kCFStringEncodingGBK_95 = 0x0631,
    kCFStringEncodingGB_18030_2000 = 0x0632,
    kCFStringEncodingKSC_5601_87 = 0x0640,
    kCFStringEncodingKSC_5601_92_Johab = 0x0641,
    kCFStringEncodingCNS_11643_92_P1 = 0x0651,
    kCFStringEncodingCNS_11643_92_P2 = 0x0652,
    kCFStringEncodingCNS_11643_92_P3 = 0x0653,


    kCFStringEncodingISO_2022_JP = 0x0820,
    kCFStringEncodingISO_2022_JP_2 = 0x0821,
    kCFStringEncodingISO_2022_JP_1 = 0x0822,
    kCFStringEncodingISO_2022_JP_3 = 0x0823,
    kCFStringEncodingISO_2022_CN = 0x0830,
    kCFStringEncodingISO_2022_CN_EXT = 0x0831,
    kCFStringEncodingISO_2022_KR = 0x0840,


    kCFStringEncodingEUC_JP = 0x0920,
    kCFStringEncodingEUC_CN = 0x0930,
    kCFStringEncodingEUC_TW = 0x0931,
    kCFStringEncodingEUC_KR = 0x0940,


    kCFStringEncodingShiftJIS = 0x0A01,
    kCFStringEncodingKOI8_R = 0x0A02,
    kCFStringEncodingBig5 = 0x0A03,
    kCFStringEncodingMacRomanLatin1 = 0x0A04,
    kCFStringEncodingHZ_GB_2312 = 0x0A05,
    kCFStringEncodingBig5_HKSCS_1999 = 0x0A06,
    kCFStringEncodingVISCII = 0x0A07,
    kCFStringEncodingKOI8_U = 0x0A08,
    kCFStringEncodingBig5_E = 0x0A09,



    kCFStringEncodingNextStepJapanese = 0x0B02,


    kCFStringEncodingEBCDIC_US = 0x0C01,
    kCFStringEncodingEBCDIC_CP037 = 0x0C02,

    kCFStringEncodingUTF7 __attribute__((availability(ios,introduced=4_0))) = 0x04000100,
    kCFStringEncodingUTF7_IMAP __attribute__((availability(ios,introduced=4_0))) = 0x0A10,


    kCFStringEncodingShiftJIS_X0213_00 = 0x0628
};

}

extern "C" {
typedef const void * (*CFTreeRetainCallBack)(const void *info);







typedef void (*CFTreeReleaseCallBack)(const void *info);
typedef CFStringRef (*CFTreeCopyDescriptionCallBack)(const void *info);
typedef struct {
    CFIndex version;
    void * info;
    CFTreeRetainCallBack retain;
    CFTreeReleaseCallBack release;
    CFTreeCopyDescriptionCallBack copyDescription;
} CFTreeContext;
typedef void (*CFTreeApplierFunction)(const void *value, void *context);





typedef struct __attribute__((objc_bridge_mutable(id))) __CFTree * CFTreeRef;





extern
CFTypeID CFTreeGetTypeID(void);
extern
CFTreeRef CFTreeCreate(CFAllocatorRef allocator, const CFTreeContext *context);
extern
CFTreeRef CFTreeGetParent(CFTreeRef tree);
extern
CFTreeRef CFTreeGetNextSibling(CFTreeRef tree);
extern
CFTreeRef CFTreeGetFirstChild(CFTreeRef tree);
extern
void CFTreeGetContext(CFTreeRef tree, CFTreeContext *context);
extern
CFIndex CFTreeGetChildCount(CFTreeRef tree);
extern
CFTreeRef CFTreeGetChildAtIndex(CFTreeRef tree, CFIndex idx);
extern
void CFTreeGetChildren(CFTreeRef tree, CFTreeRef *children);
extern
void CFTreeApplyFunctionToChildren(CFTreeRef tree, CFTreeApplierFunction applier, void *context);
extern
CFTreeRef CFTreeFindRoot(CFTreeRef tree);
extern
void CFTreeSetContext(CFTreeRef tree, const CFTreeContext *context);
extern
void CFTreePrependChild(CFTreeRef tree, CFTreeRef newChild);
extern
void CFTreeAppendChild(CFTreeRef tree, CFTreeRef newChild);
extern
void CFTreeInsertSibling(CFTreeRef tree, CFTreeRef newSibling);







extern
void CFTreeRemove(CFTreeRef tree);







extern
void CFTreeRemoveAllChildren(CFTreeRef tree);
extern
void CFTreeSortChildren(CFTreeRef tree, CFComparatorFunction comparator, void *context);

}

extern "C" {
extern
Boolean CFURLCreateDataAndPropertiesFromResource(CFAllocatorRef alloc, CFURLRef url, CFDataRef *resourceData, CFDictionaryRef *properties, CFArrayRef desiredProperties, SInt32 *errorCode) __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "For resource data, use the CFReadStream API. For file resource properties, use CFURLCopyResourcePropertiesForKeys.")));
extern
Boolean CFURLWriteDataAndPropertiesToResource(CFURLRef url, CFDataRef dataToWrite, CFDictionaryRef propertiesToWrite, SInt32 *errorCode) __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "For resource data, use the CFWriteStream API. For file resource properties, use CFURLSetResourcePropertiesForKeys.")));





extern
Boolean CFURLDestroyResource(CFURLRef url, SInt32 *errorCode) __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "Use CFURLGetFileSystemRepresentation and removefile(3) instead.")));





extern
CFTypeRef CFURLCreatePropertyFromResource(CFAllocatorRef alloc, CFURLRef url, CFStringRef property, SInt32 *errorCode) __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "For file resource properties, use CFURLCopyResourcePropertyForKey.")));



typedef CFIndex CFURLError; enum {
    kCFURLUnknownError = -10L,
    kCFURLUnknownSchemeError = -11L,
    kCFURLResourceNotFoundError = -12L,
    kCFURLResourceAccessViolationError = -13L,
    kCFURLRemoteHostUnavailableError = -14L,
    kCFURLImproperArgumentsError = -15L,
    kCFURLUnknownPropertyKeyError = -16L,
    kCFURLPropertyKeyUnavailableError = -17L,
    kCFURLTimeoutError = -18L
} __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" )));



extern
const CFStringRef kCFURLFileExists __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "Use CFURLResourceIsReachable instead.")));
extern
const CFStringRef kCFURLFileDirectoryContents __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "Use the CFURLEnumerator API instead.")));
extern
const CFStringRef kCFURLFileLength __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "Use CFURLCopyResourcePropertyForKey with kCFURLFileSizeKey instead.")));
extern
const CFStringRef kCFURLFileLastModificationTime __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "Use CFURLCopyResourcePropertyForKey with kCFURLContentModificationDateKey instead.")));
extern
const CFStringRef kCFURLFilePOSIXMode __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "Use CFURLCopyResourcePropertyForKey with kCFURLFileSecurityKey and then the CFFileSecurity API instead.")));
extern
const CFStringRef kCFURLFileOwnerID __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "Use CFURLCopyResourcePropertyForKey with kCFURLFileSecurityKey and then the CFFileSecurity API instead.")));
extern
const CFStringRef kCFURLHTTPStatusCode __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "Use NSHTTPURLResponse methods instead.")));
extern
const CFStringRef kCFURLHTTPStatusLine __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "Use NSHTTPURLResponse methods instead.")));
}
extern "C" {

typedef const struct __attribute__((objc_bridge(id))) __CFUUID * CFUUIDRef;

typedef struct {
    UInt8 byte0;
    UInt8 byte1;
    UInt8 byte2;
    UInt8 byte3;
    UInt8 byte4;
    UInt8 byte5;
    UInt8 byte6;
    UInt8 byte7;
    UInt8 byte8;
    UInt8 byte9;
    UInt8 byte10;
    UInt8 byte11;
    UInt8 byte12;
    UInt8 byte13;
    UInt8 byte14;
    UInt8 byte15;
} CFUUIDBytes;






extern
CFTypeID CFUUIDGetTypeID(void);

extern
CFUUIDRef CFUUIDCreate(CFAllocatorRef alloc);


extern
CFUUIDRef CFUUIDCreateWithBytes(CFAllocatorRef alloc, UInt8 byte0, UInt8 byte1, UInt8 byte2, UInt8 byte3, UInt8 byte4, UInt8 byte5, UInt8 byte6, UInt8 byte7, UInt8 byte8, UInt8 byte9, UInt8 byte10, UInt8 byte11, UInt8 byte12, UInt8 byte13, UInt8 byte14, UInt8 byte15);


extern
CFUUIDRef CFUUIDCreateFromString(CFAllocatorRef alloc, CFStringRef uuidStr);


extern
CFStringRef CFUUIDCreateString(CFAllocatorRef alloc, CFUUIDRef uuid);


extern
CFUUIDRef CFUUIDGetConstantUUIDWithBytes(CFAllocatorRef alloc, UInt8 byte0, UInt8 byte1, UInt8 byte2, UInt8 byte3, UInt8 byte4, UInt8 byte5, UInt8 byte6, UInt8 byte7, UInt8 byte8, UInt8 byte9, UInt8 byte10, UInt8 byte11, UInt8 byte12, UInt8 byte13, UInt8 byte14, UInt8 byte15);


extern
CFUUIDBytes CFUUIDGetUUIDBytes(CFUUIDRef uuid);

extern
CFUUIDRef CFUUIDCreateFromUUIDBytes(CFAllocatorRef alloc, CFUUIDBytes bytes);

}
extern "C" {

extern
CFURLRef CFCopyHomeDirectoryURL(void) __attribute__((availability(ios,introduced=5_0)));

}


extern "C" {

typedef struct __attribute__((objc_bridge(id))) __CFBundle *CFBundleRef;
typedef struct __attribute__((objc_bridge(id))) __CFBundle *CFPlugInRef;


extern
const CFStringRef kCFBundleInfoDictionaryVersionKey;

extern
const CFStringRef kCFBundleExecutableKey;

extern
const CFStringRef kCFBundleIdentifierKey;

extern
const CFStringRef kCFBundleVersionKey;



extern
const CFStringRef kCFBundleDevelopmentRegionKey;

extern
const CFStringRef kCFBundleNameKey;

extern
const CFStringRef kCFBundleLocalizationsKey;




extern
CFBundleRef CFBundleGetMainBundle(void);

extern
CFBundleRef CFBundleGetBundleWithIdentifier(CFStringRef bundleID);







extern
CFArrayRef CFBundleGetAllBundles(void);





extern
CFTypeID CFBundleGetTypeID(void);

extern
CFBundleRef CFBundleCreate(CFAllocatorRef allocator, CFURLRef bundleURL);


extern
CFArrayRef CFBundleCreateBundlesFromDirectory(CFAllocatorRef allocator, CFURLRef directoryURL, CFStringRef bundleType);





extern
CFURLRef CFBundleCopyBundleURL(CFBundleRef bundle);

extern
CFTypeRef CFBundleGetValueForInfoDictionaryKey(CFBundleRef bundle, CFStringRef key);



extern
CFDictionaryRef CFBundleGetInfoDictionary(CFBundleRef bundle);



extern
CFDictionaryRef CFBundleGetLocalInfoDictionary(CFBundleRef bundle);


extern
void CFBundleGetPackageInfo(CFBundleRef bundle, UInt32 *packageType, UInt32 *packageCreator);

extern
CFStringRef CFBundleGetIdentifier(CFBundleRef bundle);

extern
UInt32 CFBundleGetVersionNumber(CFBundleRef bundle);

extern
CFStringRef CFBundleGetDevelopmentRegion(CFBundleRef bundle);

extern
CFURLRef CFBundleCopySupportFilesDirectoryURL(CFBundleRef bundle);

extern
CFURLRef CFBundleCopyResourcesDirectoryURL(CFBundleRef bundle);

extern
CFURLRef CFBundleCopyPrivateFrameworksURL(CFBundleRef bundle);

extern
CFURLRef CFBundleCopySharedFrameworksURL(CFBundleRef bundle);

extern
CFURLRef CFBundleCopySharedSupportURL(CFBundleRef bundle);

extern
CFURLRef CFBundleCopyBuiltInPlugInsURL(CFBundleRef bundle);






extern
CFDictionaryRef CFBundleCopyInfoDictionaryInDirectory(CFURLRef bundleURL);

extern
Boolean CFBundleGetPackageInfoInDirectory(CFURLRef url, UInt32 *packageType, UInt32 *packageCreator);



extern
CFURLRef CFBundleCopyResourceURL(CFBundleRef bundle, CFStringRef resourceName, CFStringRef resourceType, CFStringRef subDirName);

extern
CFArrayRef CFBundleCopyResourceURLsOfType(CFBundleRef bundle, CFStringRef resourceType, CFStringRef subDirName);

extern
CFStringRef CFBundleCopyLocalizedString(CFBundleRef bundle, CFStringRef key, CFStringRef value, CFStringRef tableName) __attribute__((format_arg(2)));
extern
CFURLRef CFBundleCopyResourceURLInDirectory(CFURLRef bundleURL, CFStringRef resourceName, CFStringRef resourceType, CFStringRef subDirName);

extern
CFArrayRef CFBundleCopyResourceURLsOfTypeInDirectory(CFURLRef bundleURL, CFStringRef resourceType, CFStringRef subDirName);






extern
CFArrayRef CFBundleCopyBundleLocalizations(CFBundleRef bundle);


extern
CFArrayRef CFBundleCopyPreferredLocalizationsFromArray(CFArrayRef locArray);






extern
CFArrayRef CFBundleCopyLocalizationsForPreferences(CFArrayRef locArray, CFArrayRef prefArray);
extern
CFURLRef CFBundleCopyResourceURLForLocalization(CFBundleRef bundle, CFStringRef resourceName, CFStringRef resourceType, CFStringRef subDirName, CFStringRef localizationName);

extern
CFArrayRef CFBundleCopyResourceURLsOfTypeForLocalization(CFBundleRef bundle, CFStringRef resourceType, CFStringRef subDirName, CFStringRef localizationName);
extern
CFDictionaryRef CFBundleCopyInfoDictionaryForURL(CFURLRef url);





extern
CFArrayRef CFBundleCopyLocalizationsForURL(CFURLRef url);






extern
CFArrayRef CFBundleCopyExecutableArchitecturesForURL(CFURLRef url) __attribute__((availability(ios,introduced=2_0)));
extern
CFURLRef CFBundleCopyExecutableURL(CFBundleRef bundle);

enum {
    kCFBundleExecutableArchitectureI386 = 0x00000007,
    kCFBundleExecutableArchitecturePPC = 0x00000012,
    kCFBundleExecutableArchitectureX86_64 = 0x01000007,
    kCFBundleExecutableArchitecturePPC64 = 0x01000012
} __attribute__((availability(ios,introduced=2_0)));

extern
CFArrayRef CFBundleCopyExecutableArchitectures(CFBundleRef bundle) __attribute__((availability(ios,introduced=2_0)));





extern
Boolean CFBundlePreflightExecutable(CFBundleRef bundle, CFErrorRef *error) __attribute__((availability(ios,introduced=2_0)));






extern
Boolean CFBundleLoadExecutableAndReturnError(CFBundleRef bundle, CFErrorRef *error) __attribute__((availability(ios,introduced=2_0)));





extern
Boolean CFBundleLoadExecutable(CFBundleRef bundle);

extern
Boolean CFBundleIsExecutableLoaded(CFBundleRef bundle);

extern
void CFBundleUnloadExecutable(CFBundleRef bundle);

extern
void *CFBundleGetFunctionPointerForName(CFBundleRef bundle, CFStringRef functionName);

extern
void CFBundleGetFunctionPointersForNames(CFBundleRef bundle, CFArrayRef functionNames, void *ftbl[]);

extern
void *CFBundleGetDataPointerForName(CFBundleRef bundle, CFStringRef symbolName);

extern
void CFBundleGetDataPointersForNames(CFBundleRef bundle, CFArrayRef symbolNames, void *stbl[]);

extern
CFURLRef CFBundleCopyAuxiliaryExecutableURL(CFBundleRef bundle, CFStringRef executableName);
extern
CFPlugInRef CFBundleGetPlugIn(CFBundleRef bundle);




typedef int CFBundleRefNum;




extern
CFBundleRefNum CFBundleOpenBundleResourceMap(CFBundleRef bundle);






extern
SInt32 CFBundleOpenBundleResourceFiles(CFBundleRef bundle, CFBundleRefNum *refNum, CFBundleRefNum *localizedRefNum);



extern
void CFBundleCloseBundleResourceMap(CFBundleRef bundle, CFBundleRefNum refNum);

}
extern "C" {

typedef struct __attribute__((objc_bridge_mutable(NSMessagePort))) __CFMessagePort * CFMessagePortRef;

enum {
    kCFMessagePortSuccess = 0,
    kCFMessagePortSendTimeout = -1,
    kCFMessagePortReceiveTimeout = -2,
    kCFMessagePortIsInvalid = -3,
    kCFMessagePortTransportError = -4,
    kCFMessagePortBecameInvalidError = -5
};

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFMessagePortContext;

typedef CFDataRef (*CFMessagePortCallBack)(CFMessagePortRef local, SInt32 msgid, CFDataRef data, void *info);

typedef void (*CFMessagePortInvalidationCallBack)(CFMessagePortRef ms, void *info);

extern CFTypeID CFMessagePortGetTypeID(void);

extern CFMessagePortRef CFMessagePortCreateLocal(CFAllocatorRef allocator, CFStringRef name, CFMessagePortCallBack callout, CFMessagePortContext *context, Boolean *shouldFreeInfo);
extern CFMessagePortRef CFMessagePortCreateRemote(CFAllocatorRef allocator, CFStringRef name);

extern Boolean CFMessagePortIsRemote(CFMessagePortRef ms);
extern CFStringRef CFMessagePortGetName(CFMessagePortRef ms);
extern Boolean CFMessagePortSetName(CFMessagePortRef ms, CFStringRef newName);
extern void CFMessagePortGetContext(CFMessagePortRef ms, CFMessagePortContext *context);
extern void CFMessagePortInvalidate(CFMessagePortRef ms);
extern Boolean CFMessagePortIsValid(CFMessagePortRef ms);
extern CFMessagePortInvalidationCallBack CFMessagePortGetInvalidationCallBack(CFMessagePortRef ms);
extern void CFMessagePortSetInvalidationCallBack(CFMessagePortRef ms, CFMessagePortInvalidationCallBack callout);


extern SInt32 CFMessagePortSendRequest(CFMessagePortRef remote, SInt32 msgid, CFDataRef data, CFTimeInterval sendTimeout, CFTimeInterval rcvTimeout, CFStringRef replyMode, CFDataRef *returnData);

extern CFRunLoopSourceRef CFMessagePortCreateRunLoopSource(CFAllocatorRef allocator, CFMessagePortRef local, CFIndex order);

extern void CFMessagePortSetDispatchQueue(CFMessagePortRef ms, dispatch_queue_t queue) __attribute__((availability(ios,introduced=4_0)));

}
extern "C" {



extern const CFStringRef kCFPlugInDynamicRegistrationKey;
extern const CFStringRef kCFPlugInDynamicRegisterFunctionKey;
extern const CFStringRef kCFPlugInUnloadFunctionKey;
extern const CFStringRef kCFPlugInFactoriesKey;
extern const CFStringRef kCFPlugInTypesKey;




typedef void (*CFPlugInDynamicRegisterFunction)(CFPlugInRef plugIn);
typedef void (*CFPlugInUnloadFunction)(CFPlugInRef plugIn);
typedef void *(*CFPlugInFactoryFunction)(CFAllocatorRef allocator, CFUUIDRef typeUUID);



extern CFTypeID CFPlugInGetTypeID(void);

extern CFPlugInRef CFPlugInCreate(CFAllocatorRef allocator, CFURLRef plugInURL);


extern CFBundleRef CFPlugInGetBundle(CFPlugInRef plugIn);







extern void CFPlugInSetLoadOnDemand(CFPlugInRef plugIn, Boolean flag);

extern Boolean CFPlugInIsLoadOnDemand(CFPlugInRef plugIn);






extern CFArrayRef CFPlugInFindFactoriesForPlugInType(CFUUIDRef typeUUID) __attribute__((cf_returns_retained));



extern CFArrayRef CFPlugInFindFactoriesForPlugInTypeInPlugIn(CFUUIDRef typeUUID, CFPlugInRef plugIn) __attribute__((cf_returns_retained));


extern void *CFPlugInInstanceCreate(CFAllocatorRef allocator, CFUUIDRef factoryUUID, CFUUIDRef typeUUID);





extern Boolean CFPlugInRegisterFactoryFunction(CFUUIDRef factoryUUID, CFPlugInFactoryFunction func);

extern Boolean CFPlugInRegisterFactoryFunctionByName(CFUUIDRef factoryUUID, CFPlugInRef plugIn, CFStringRef functionName);

extern Boolean CFPlugInUnregisterFactory(CFUUIDRef factoryUUID);

extern Boolean CFPlugInRegisterPlugInType(CFUUIDRef factoryUUID, CFUUIDRef typeUUID);

extern Boolean CFPlugInUnregisterPlugInType(CFUUIDRef factoryUUID, CFUUIDRef typeUUID);





extern void CFPlugInAddInstanceForFactory(CFUUIDRef factoryID);

extern void CFPlugInRemoveInstanceForFactory(CFUUIDRef factoryID);




typedef struct __attribute__((objc_bridge(id))) __CFPlugInInstance *CFPlugInInstanceRef;

typedef Boolean (*CFPlugInInstanceGetInterfaceFunction)(CFPlugInInstanceRef instance, CFStringRef interfaceName, void **ftbl);
typedef void (*CFPlugInInstanceDeallocateInstanceDataFunction)(void *instanceData);

extern Boolean CFPlugInInstanceGetInterfaceFunctionTable(CFPlugInInstanceRef instance, CFStringRef interfaceName, void **ftbl);


extern CFStringRef CFPlugInInstanceGetFactoryName(CFPlugInInstanceRef instance) __attribute__((cf_returns_retained));

extern void *CFPlugInInstanceGetInstanceData(CFPlugInInstanceRef instance);

extern CFTypeID CFPlugInInstanceGetTypeID(void);

extern CFPlugInInstanceRef CFPlugInInstanceCreateWithInstanceDataSize(CFAllocatorRef allocator, CFIndex instanceDataSize, CFPlugInInstanceDeallocateInstanceDataFunction deallocateInstanceFunction, CFStringRef factoryName, CFPlugInInstanceGetInterfaceFunction getInterfaceFunction);

}





extern "C" {




typedef const struct __attribute__((objc_bridge(NSAttributedString))) __CFAttributedString *CFAttributedStringRef;
typedef struct __attribute__((objc_bridge_mutable(NSMutableAttributedString))) __CFAttributedString *CFMutableAttributedStringRef;




extern CFTypeID CFAttributedStringGetTypeID(void);
extern CFAttributedStringRef CFAttributedStringCreate(CFAllocatorRef alloc, CFStringRef str, CFDictionaryRef attributes);




extern CFAttributedStringRef CFAttributedStringCreateWithSubstring(CFAllocatorRef alloc, CFAttributedStringRef aStr, CFRange range);




extern CFAttributedStringRef CFAttributedStringCreateCopy(CFAllocatorRef alloc, CFAttributedStringRef aStr);




extern CFStringRef CFAttributedStringGetString(CFAttributedStringRef aStr);




extern CFIndex CFAttributedStringGetLength(CFAttributedStringRef aStr);






extern CFDictionaryRef CFAttributedStringGetAttributes(CFAttributedStringRef aStr, CFIndex loc, CFRange *effectiveRange);




extern CFTypeRef CFAttributedStringGetAttribute(CFAttributedStringRef aStr, CFIndex loc, CFStringRef attrName, CFRange *effectiveRange);




extern CFDictionaryRef CFAttributedStringGetAttributesAndLongestEffectiveRange(CFAttributedStringRef aStr, CFIndex loc, CFRange inRange, CFRange *longestEffectiveRange);




extern CFTypeRef CFAttributedStringGetAttributeAndLongestEffectiveRange(CFAttributedStringRef aStr, CFIndex loc, CFStringRef attrName, CFRange inRange, CFRange *longestEffectiveRange);
extern CFMutableAttributedStringRef CFAttributedStringCreateMutableCopy(CFAllocatorRef alloc, CFIndex maxLength, CFAttributedStringRef aStr);




extern CFMutableAttributedStringRef CFAttributedStringCreateMutable(CFAllocatorRef alloc, CFIndex maxLength);






extern void CFAttributedStringReplaceString(CFMutableAttributedStringRef aStr, CFRange range, CFStringRef replacement);






extern CFMutableStringRef CFAttributedStringGetMutableString(CFMutableAttributedStringRef aStr);




extern void CFAttributedStringSetAttributes(CFMutableAttributedStringRef aStr, CFRange range, CFDictionaryRef replacement, Boolean clearOtherAttributes);




extern void CFAttributedStringSetAttribute(CFMutableAttributedStringRef aStr, CFRange range, CFStringRef attrName, CFTypeRef value);




extern void CFAttributedStringRemoveAttribute(CFMutableAttributedStringRef aStr, CFRange range, CFStringRef attrName);




extern void CFAttributedStringReplaceAttributedString(CFMutableAttributedStringRef aStr, CFRange range, CFAttributedStringRef replacement);




extern void CFAttributedStringBeginEditing(CFMutableAttributedStringRef aStr);




extern void CFAttributedStringEndEditing(CFMutableAttributedStringRef aStr);


}
extern "C" {

typedef struct __attribute__((objc_bridge_mutable(id))) __CFNotificationCenter * CFNotificationCenterRef;

typedef void (*CFNotificationCallback)(CFNotificationCenterRef center, void *observer, CFStringRef name, const void *object, CFDictionaryRef userInfo);

typedef CFIndex CFNotificationSuspensionBehavior; enum {
    CFNotificationSuspensionBehaviorDrop = 1,

    CFNotificationSuspensionBehaviorCoalesce = 2,

    CFNotificationSuspensionBehaviorHold = 3,

    CFNotificationSuspensionBehaviorDeliverImmediately = 4

};

extern CFTypeID CFNotificationCenterGetTypeID(void);

extern CFNotificationCenterRef CFNotificationCenterGetLocalCenter(void);





extern CFNotificationCenterRef CFNotificationCenterGetDarwinNotifyCenter(void);
extern void CFNotificationCenterAddObserver(CFNotificationCenterRef center, const void *observer, CFNotificationCallback callBack, CFStringRef name, const void *object, CFNotificationSuspensionBehavior suspensionBehavior);

extern void CFNotificationCenterRemoveObserver(CFNotificationCenterRef center, const void *observer, CFStringRef name, const void *object);
extern void CFNotificationCenterRemoveEveryObserver(CFNotificationCenterRef center, const void *observer);

extern void CFNotificationCenterPostNotification(CFNotificationCenterRef center, CFStringRef name, const void *object, CFDictionaryRef userInfo, Boolean deliverImmediately);

enum {
    kCFNotificationDeliverImmediately = (1UL << 0),
    kCFNotificationPostToAllSessions = (1UL << 1)
};

extern void CFNotificationCenterPostNotificationWithOptions(CFNotificationCenterRef center, CFStringRef name, const void *object, CFDictionaryRef userInfo, CFOptionFlags options);


}
extern "C" {


typedef const struct __attribute__((objc_bridge_mutable(id))) __CFURLEnumerator *CFURLEnumeratorRef;


extern
CFTypeID CFURLEnumeratorGetTypeID( void ) __attribute__((availability(ios,introduced=4_0)));



typedef CFOptionFlags CFURLEnumeratorOptions; enum {
    kCFURLEnumeratorDefaultBehavior = 0,
    kCFURLEnumeratorDescendRecursively = 1UL << 0,
    kCFURLEnumeratorSkipInvisibles = 1UL << 1,
    kCFURLEnumeratorGenerateFileReferenceURLs = 1UL << 2,
    kCFURLEnumeratorSkipPackageContents = 1UL << 3,
    kCFURLEnumeratorIncludeDirectoriesPreOrder = 1UL << 4,
    kCFURLEnumeratorIncludeDirectoriesPostOrder = 1UL << 5,

};







extern
CFURLEnumeratorRef CFURLEnumeratorCreateForDirectoryURL( CFAllocatorRef alloc, CFURLRef directoryURL, CFURLEnumeratorOptions option, CFArrayRef propertyKeys ) __attribute__((availability(ios,introduced=4_0)));
extern
CFURLEnumeratorRef CFURLEnumeratorCreateForMountedVolumes( CFAllocatorRef alloc, CFURLEnumeratorOptions option, CFArrayRef propertyKeys ) __attribute__((availability(ios,introduced=4_0)));



typedef CFIndex CFURLEnumeratorResult; enum {
    kCFURLEnumeratorSuccess = 1,
    kCFURLEnumeratorEnd = 2,
    kCFURLEnumeratorError = 3,
    kCFURLEnumeratorDirectoryPostOrderSuccess = 4,
};





extern
CFURLEnumeratorResult CFURLEnumeratorGetNextURL( CFURLEnumeratorRef enumerator, CFURLRef *url, CFErrorRef *error ) __attribute__((availability(ios,introduced=4_0)));
extern
void CFURLEnumeratorSkipDescendents( CFURLEnumeratorRef enumerator ) __attribute__((availability(ios,introduced=4_0)));




extern
CFIndex CFURLEnumeratorGetDescendentLevel( CFURLEnumeratorRef enumerator ) __attribute__((availability(ios,introduced=4_0)));






extern
Boolean CFURLEnumeratorGetSourceDidChange( CFURLEnumeratorRef enumerator ) __attribute__((availability(ios,introduced=4_0,deprecated=5_0,message="" )));


}






typedef struct {

 unsigned char g_guid[16];
} guid_t;


#pragma pack(1)
typedef struct {
 u_int8_t sid_kind;
 u_int8_t sid_authcount;
 u_int8_t sid_authority[6];

 u_int32_t sid_authorities[16];
} ntsid_t;
#pragma pack()
struct kauth_identity_extlookup {
 u_int32_t el_seqno;
 u_int32_t el_result;





 u_int32_t el_flags;
 __darwin_pid_t el_info_pid;
 u_int64_t el_extend;
 u_int32_t el_info_reserved_1;

 uid_t el_uid;
 guid_t el_uguid;
 u_int32_t el_uguid_valid;
 ntsid_t el_usid;
 u_int32_t el_usid_valid;
 gid_t el_gid;
 guid_t el_gguid;
 u_int32_t el_gguid_valid;
 ntsid_t el_gsid;
 u_int32_t el_gsid_valid;
 u_int32_t el_member_valid;
  u_int32_t el_sup_grp_cnt;
  gid_t el_sup_groups[16];
};

struct kauth_cache_sizes {
 u_int32_t kcs_group_size;
 u_int32_t kcs_id_size;
};
typedef u_int32_t kauth_ace_rights_t;


struct kauth_ace {
 guid_t ace_applicable;
 u_int32_t ace_flags;
 kauth_ace_rights_t ace_rights;






};



typedef struct kauth_ace *kauth_ace_t;




struct kauth_acl {
 u_int32_t acl_entrycount;
 u_int32_t acl_flags;

 struct kauth_ace acl_ace[1];
};
typedef struct kauth_acl *kauth_acl_t;
struct kauth_filesec {
 u_int32_t fsec_magic;

 guid_t fsec_owner;
 guid_t fsec_group;

 struct kauth_acl fsec_acl;
};
typedef struct kauth_filesec *kauth_filesec_t;
typedef enum {
 ACL_READ_DATA = (1<<1),
 ACL_LIST_DIRECTORY = (1<<1),
 ACL_WRITE_DATA = (1<<2),
 ACL_ADD_FILE = (1<<2),
 ACL_EXECUTE = (1<<3),
 ACL_SEARCH = (1<<3),
 ACL_DELETE = (1<<4),
 ACL_APPEND_DATA = (1<<5),
 ACL_ADD_SUBDIRECTORY = (1<<5),
 ACL_DELETE_CHILD = (1<<6),
 ACL_READ_ATTRIBUTES = (1<<7),
 ACL_WRITE_ATTRIBUTES = (1<<8),
 ACL_READ_EXTATTRIBUTES = (1<<9),
 ACL_WRITE_EXTATTRIBUTES = (1<<10),
 ACL_READ_SECURITY = (1<<11),
 ACL_WRITE_SECURITY = (1<<12),
 ACL_CHANGE_OWNER = (1<<13),
 ACL_SYNCHRONIZE = (1<<20),
} acl_perm_t;


typedef enum {
 ACL_UNDEFINED_TAG = 0,
 ACL_EXTENDED_ALLOW = 1,
 ACL_EXTENDED_DENY = 2
} acl_tag_t;


typedef enum {
 ACL_TYPE_EXTENDED = 0x00000100,

 ACL_TYPE_ACCESS = 0x00000000,
 ACL_TYPE_DEFAULT = 0x00000001,

 ACL_TYPE_AFS = 0x00000002,
 ACL_TYPE_CODA = 0x00000003,
 ACL_TYPE_NTFS = 0x00000004,
 ACL_TYPE_NWFS = 0x00000005
} acl_type_t;






typedef enum {
 ACL_FIRST_ENTRY = 0,
 ACL_NEXT_ENTRY = -1,
 ACL_LAST_ENTRY = -2
} acl_entry_id_t;


typedef enum {
 ACL_FLAG_DEFER_INHERIT = (1 << 0),
 ACL_FLAG_NO_INHERIT = (1<<17),
 ACL_ENTRY_INHERITED = (1<<4),
 ACL_ENTRY_FILE_INHERIT = (1<<5),
 ACL_ENTRY_DIRECTORY_INHERIT = (1<<6),
 ACL_ENTRY_LIMIT_INHERIT = (1<<7),
 ACL_ENTRY_ONLY_INHERIT = (1<<8)
} acl_flag_t;



struct _acl;
struct _acl_entry;
struct _acl_permset;
struct _acl_flagset;

typedef struct _acl *acl_t;
typedef struct _acl_entry *acl_entry_t;
typedef struct _acl_permset *acl_permset_t;
typedef struct _acl_flagset *acl_flagset_t;

typedef u_int64_t acl_permset_mask_t;

extern "C" {

extern acl_t acl_dup(acl_t acl);
extern int acl_free(void *obj_p);
extern acl_t acl_init(int count);


extern int acl_copy_entry(acl_entry_t dest_d, acl_entry_t src_d);
extern int acl_create_entry(acl_t *acl_p, acl_entry_t *entry_p);
extern int acl_create_entry_np(acl_t *acl_p, acl_entry_t *entry_p, int entry_index);
extern int acl_delete_entry(acl_t acl, acl_entry_t entry_d);
extern int acl_get_entry(acl_t acl, int entry_id, acl_entry_t *entry_p);
extern int acl_valid(acl_t acl);
extern int acl_valid_fd_np(int fd, acl_type_t type, acl_t acl);
extern int acl_valid_file_np(const char *path, acl_type_t type, acl_t acl);
extern int acl_valid_link_np(const char *path, acl_type_t type, acl_t acl);


extern int acl_add_perm(acl_permset_t permset_d, acl_perm_t perm);
extern int acl_calc_mask(acl_t *acl_p);
extern int acl_clear_perms(acl_permset_t permset_d);
extern int acl_delete_perm(acl_permset_t permset_d, acl_perm_t perm);
extern int acl_get_perm_np(acl_permset_t permset_d, acl_perm_t perm);
extern int acl_get_permset(acl_entry_t entry_d, acl_permset_t *permset_p);
extern int acl_set_permset(acl_entry_t entry_d, acl_permset_t permset_d);


extern int acl_maximal_permset_mask_np(acl_permset_mask_t * mask_p) __attribute__((availability(macosx,introduced=10.7)));
extern int acl_get_permset_mask_np(acl_entry_t entry_d, acl_permset_mask_t * mask_p) __attribute__((availability(macosx,introduced=10.7)));
extern int acl_set_permset_mask_np(acl_entry_t entry_d, acl_permset_mask_t mask) __attribute__((availability(macosx,introduced=10.7)));


extern int acl_add_flag_np(acl_flagset_t flagset_d, acl_flag_t flag);
extern int acl_clear_flags_np(acl_flagset_t flagset_d);
extern int acl_delete_flag_np(acl_flagset_t flagset_d, acl_flag_t flag);
extern int acl_get_flag_np(acl_flagset_t flagset_d, acl_flag_t flag);
extern int acl_get_flagset_np(void *obj_p, acl_flagset_t *flagset_p);
extern int acl_set_flagset_np(void *obj_p, acl_flagset_t flagset_d);


extern void *acl_get_qualifier(acl_entry_t entry_d);
extern int acl_get_tag_type(acl_entry_t entry_d, acl_tag_t *tag_type_p);
extern int acl_set_qualifier(acl_entry_t entry_d, const void *tag_qualifier_p);
extern int acl_set_tag_type(acl_entry_t entry_d, acl_tag_t tag_type);


extern int acl_delete_def_file(const char *path_p);
extern acl_t acl_get_fd(int fd);
extern acl_t acl_get_fd_np(int fd, acl_type_t type);
extern acl_t acl_get_file(const char *path_p, acl_type_t type);
extern acl_t acl_get_link_np(const char *path_p, acl_type_t type);
extern int acl_set_fd(int fd, acl_t acl);
extern int acl_set_fd_np(int fd, acl_t acl, acl_type_t acl_type);
extern int acl_set_file(const char *path_p, acl_type_t type, acl_t acl);
extern int acl_set_link_np(const char *path_p, acl_type_t type, acl_t acl);


extern ssize_t acl_copy_ext(void *buf_p, acl_t acl, ssize_t size);
extern ssize_t acl_copy_ext_native(void *buf_p, acl_t acl, ssize_t size);
extern acl_t acl_copy_int(const void *buf_p);
extern acl_t acl_copy_int_native(const void *buf_p);
extern acl_t acl_from_text(const char *buf_p);
extern ssize_t acl_size(acl_t acl);
extern char *acl_to_text(acl_t acl, ssize_t *len_p);
}




extern "C" {





typedef struct __attribute__((objc_bridge_mutable(NSFileSecurity))) __CFFileSecurity* CFFileSecurityRef;







extern
CFTypeID CFFileSecurityGetTypeID(void) __attribute__((availability(ios,introduced=5_0)));
extern
CFFileSecurityRef CFFileSecurityCreate(CFAllocatorRef allocator) __attribute__((availability(ios,introduced=5_0)));
extern
CFFileSecurityRef CFFileSecurityCreateCopy(CFAllocatorRef allocator, CFFileSecurityRef fileSec) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecurityCopyOwnerUUID(CFFileSecurityRef fileSec, CFUUIDRef *ownerUUID) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecuritySetOwnerUUID(CFFileSecurityRef fileSec, CFUUIDRef ownerUUID) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecurityCopyGroupUUID(CFFileSecurityRef fileSec, CFUUIDRef *groupUUID) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecuritySetGroupUUID(CFFileSecurityRef fileSec, CFUUIDRef groupUUID) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecurityCopyAccessControlList(CFFileSecurityRef fileSec, acl_t *accessControlList) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecuritySetAccessControlList(CFFileSecurityRef fileSec, acl_t accessControlList) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecurityGetOwner(CFFileSecurityRef fileSec, uid_t *owner) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecuritySetOwner(CFFileSecurityRef fileSec, uid_t owner) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecurityGetGroup(CFFileSecurityRef fileSec, gid_t *group) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecuritySetGroup(CFFileSecurityRef fileSec, gid_t group) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecurityGetMode(CFFileSecurityRef fileSec, mode_t *mode) __attribute__((availability(ios,introduced=5_0)));
extern
Boolean CFFileSecuritySetMode(CFFileSecurityRef fileSec, mode_t mode) __attribute__((availability(ios,introduced=5_0)));



typedef CFOptionFlags CFFileSecurityClearOptions; enum {
    kCFFileSecurityClearOwner = 1UL << 0,
    kCFFileSecurityClearGroup = 1UL << 1,
    kCFFileSecurityClearMode = 1UL << 2,
    kCFFileSecurityClearOwnerUUID = 1UL << 3,
    kCFFileSecurityClearGroupUUID = 1UL << 4,
    kCFFileSecurityClearAccessControlList = 1UL << 5
} __attribute__((availability(ios,introduced=6_0)));
extern
Boolean CFFileSecurityClearProperties(CFFileSecurityRef fileSec, CFFileSecurityClearOptions clearPropertyMask) __attribute__((availability(ios,introduced=6_0)));


}
extern "C" {

typedef struct __attribute__((objc_bridge_mutable(NSMachPort))) __CFMachPort * CFMachPortRef;

typedef struct {
    CFIndex version;
    void * info;
    const void *(*retain)(const void *info);
    void (*release)(const void *info);
    CFStringRef (*copyDescription)(const void *info);
} CFMachPortContext;

typedef void (*CFMachPortCallBack)(CFMachPortRef port, void *msg, CFIndex size, void *info);
typedef void (*CFMachPortInvalidationCallBack)(CFMachPortRef port, void *info);

extern CFTypeID CFMachPortGetTypeID(void);

extern CFMachPortRef CFMachPortCreate(CFAllocatorRef allocator, CFMachPortCallBack callout, CFMachPortContext *context, Boolean *shouldFreeInfo);
extern CFMachPortRef CFMachPortCreateWithPort(CFAllocatorRef allocator, mach_port_t portNum, CFMachPortCallBack callout, CFMachPortContext *context, Boolean *shouldFreeInfo);

extern mach_port_t CFMachPortGetPort(CFMachPortRef port);
extern void CFMachPortGetContext(CFMachPortRef port, CFMachPortContext *context);
extern void CFMachPortInvalidate(CFMachPortRef port);
extern Boolean CFMachPortIsValid(CFMachPortRef port);
extern CFMachPortInvalidationCallBack CFMachPortGetInvalidationCallBack(CFMachPortRef port);
extern void CFMachPortSetInvalidationCallBack(CFMachPortRef port, CFMachPortInvalidationCallBack callout);

extern CFRunLoopSourceRef CFMachPortCreateRunLoopSource(CFAllocatorRef allocator, CFMachPortRef port, CFIndex order);

}
extern "C" {
extern
CFStringRef CFStringTokenizerCopyBestStringLanguage(CFStringRef string, CFRange range) __attribute__((availability(ios,introduced=3_0)));







typedef struct __attribute__((objc_bridge_mutable(id))) __CFStringTokenizer * CFStringTokenizerRef;




enum {






    kCFStringTokenizerUnitWord = 0,
    kCFStringTokenizerUnitSentence = 1,
    kCFStringTokenizerUnitParagraph = 2,
    kCFStringTokenizerUnitLineBreak = 3,




    kCFStringTokenizerUnitWordBoundary = 4,
    kCFStringTokenizerAttributeLatinTranscription = 1UL << 16,


    kCFStringTokenizerAttributeLanguage = 1UL << 17,
};






typedef CFOptionFlags CFStringTokenizerTokenType; enum {

    kCFStringTokenizerTokenNone = 0,


    kCFStringTokenizerTokenNormal = 1UL << 0,





    kCFStringTokenizerTokenHasSubTokensMask = 1UL << 1,






    kCFStringTokenizerTokenHasDerivedSubTokensMask = 1UL << 2,

    kCFStringTokenizerTokenHasHasNumbersMask = 1UL << 3,
    kCFStringTokenizerTokenHasNonLettersMask = 1UL << 4,
    kCFStringTokenizerTokenIsCJWordMask = 1UL << 5
};






extern
CFTypeID CFStringTokenizerGetTypeID(void) __attribute__((availability(ios,introduced=3_0)));
extern
CFStringTokenizerRef CFStringTokenizerCreate(CFAllocatorRef alloc, CFStringRef string, CFRange range, CFOptionFlags options, CFLocaleRef locale) __attribute__((availability(ios,introduced=3_0)));
extern
void CFStringTokenizerSetString(CFStringTokenizerRef tokenizer, CFStringRef string, CFRange range) __attribute__((availability(ios,introduced=3_0)));
extern
CFStringTokenizerTokenType CFStringTokenizerGoToTokenAtIndex(CFStringTokenizerRef tokenizer, CFIndex index) __attribute__((availability(ios,introduced=3_0)));
extern
CFStringTokenizerTokenType CFStringTokenizerAdvanceToNextToken(CFStringTokenizerRef tokenizer) __attribute__((availability(ios,introduced=3_0)));
extern
CFRange CFStringTokenizerGetCurrentTokenRange(CFStringTokenizerRef tokenizer) __attribute__((availability(ios,introduced=3_0)));
extern
CFTypeRef CFStringTokenizerCopyCurrentTokenAttribute(CFStringTokenizerRef tokenizer, CFOptionFlags attribute) __attribute__((availability(ios,introduced=3_0)));
extern
CFIndex CFStringTokenizerGetCurrentSubTokens(CFStringTokenizerRef tokenizer, CFRange *ranges, CFIndex maxRangeLength, CFMutableArrayRef derivedSubTokens) __attribute__((availability(ios,introduced=3_0)));

}
extern "C" {

typedef int CFFileDescriptorNativeDescriptor;

typedef struct __attribute__((objc_bridge_mutable(id))) __CFFileDescriptor * CFFileDescriptorRef;


enum {
    kCFFileDescriptorReadCallBack = 1UL << 0,
    kCFFileDescriptorWriteCallBack = 1UL << 1
};

typedef void (*CFFileDescriptorCallBack)(CFFileDescriptorRef f, CFOptionFlags callBackTypes, void *info);

typedef struct {
    CFIndex version;
    void * info;
    void * (*retain)(void *info);
    void (*release)(void *info);
    CFStringRef (*copyDescription)(void *info);
} CFFileDescriptorContext;

extern CFTypeID CFFileDescriptorGetTypeID(void) __attribute__((availability(ios,introduced=2_0)));

extern CFFileDescriptorRef CFFileDescriptorCreate(CFAllocatorRef allocator, CFFileDescriptorNativeDescriptor fd, Boolean closeOnInvalidate, CFFileDescriptorCallBack callout, const CFFileDescriptorContext *context) __attribute__((availability(ios,introduced=2_0)));

extern CFFileDescriptorNativeDescriptor CFFileDescriptorGetNativeDescriptor(CFFileDescriptorRef f) __attribute__((availability(ios,introduced=2_0)));

extern void CFFileDescriptorGetContext(CFFileDescriptorRef f, CFFileDescriptorContext *context) __attribute__((availability(ios,introduced=2_0)));

extern void CFFileDescriptorEnableCallBacks(CFFileDescriptorRef f, CFOptionFlags callBackTypes) __attribute__((availability(ios,introduced=2_0)));
extern void CFFileDescriptorDisableCallBacks(CFFileDescriptorRef f, CFOptionFlags callBackTypes) __attribute__((availability(ios,introduced=2_0)));

extern void CFFileDescriptorInvalidate(CFFileDescriptorRef f) __attribute__((availability(ios,introduced=2_0)));
extern Boolean CFFileDescriptorIsValid(CFFileDescriptorRef f) __attribute__((availability(ios,introduced=2_0)));

extern CFRunLoopSourceRef CFFileDescriptorCreateRunLoopSource(CFAllocatorRef allocator, CFFileDescriptorRef f, CFIndex order) __attribute__((availability(ios,introduced=2_0)));


}

extern "C" double NSFoundationVersionNumber;
// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_Protocol
#define _REWRITER_typedef_Protocol
typedef struct objc_object Protocol;
typedef struct {} _objc_exc_Protocol;
#endif


extern "C" NSString *NSStringFromSelector(SEL aSelector);
extern "C" SEL NSSelectorFromString(NSString *aSelectorName);

extern "C" NSString *NSStringFromClass(Class aClass);
extern "C" Class _Nullable NSClassFromString(NSString *aClassName);

extern "C" NSString *NSStringFromProtocol(Protocol *proto) __attribute__((availability(ios,introduced=2_0)));
extern "C" Protocol * _Nullable NSProtocolFromString(NSString *namestr) __attribute__((availability(ios,introduced=2_0)));

extern "C" const char *NSGetSizeAndAlignment(const char *typePtr, NSUInteger * _Nullable sizep, NSUInteger * _Nullable alignp);

extern "C" void NSLog(NSString *format, ...) __attribute__((format(__NSString__, 1, 2)));
extern "C" void NSLogv(NSString *format, va_list args) __attribute__((format(__NSString__, 1, 0)));

typedef NSInteger NSComparisonResult; enum {NSOrderedAscending = -1L, NSOrderedSame, NSOrderedDescending};


typedef NSComparisonResult (*NSComparator)(id obj1, id obj2);


typedef NSUInteger NSEnumerationOptions; enum {
    NSEnumerationConcurrent = (1UL << 0),
    NSEnumerationReverse = (1UL << 1),
};

typedef NSUInteger NSSortOptions; enum {
    NSSortConcurrent = (1UL << 0),
    NSSortStable = (1UL << 4),
};


typedef NSInteger NSQualityOfService; enum {

    NSQualityOfServiceUserInteractive = 0x21,


    NSQualityOfServiceUserInitiated = 0x19,


    NSQualityOfServiceUtility = 0x11,


    NSQualityOfServiceBackground = 0x09,


    NSQualityOfServiceDefault = -1
} __attribute__((availability(ios,introduced=8_0)));

static const NSInteger NSNotFound = 9223372036854775807L;



















// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif




typedef struct _NSZone NSZone;

extern "C" NSZone *NSDefaultMallocZone(void) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" NSZone *NSCreateZone(NSUInteger startSize, NSUInteger granularity, BOOL canFree) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" void NSRecycleZone(NSZone *zone)__attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));

extern "C" void NSSetZoneName(NSZone * _Nullable zone, NSString *name)__attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" NSString *NSZoneName(NSZone * _Nullable zone) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" NSZone * _Nullable NSZoneFromPointer(void *ptr) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));

extern "C" void *NSZoneMalloc(NSZone * _Nullable zone, NSUInteger size) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" void *NSZoneCalloc(NSZone * _Nullable zone, NSUInteger numElems, NSUInteger byteSize) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" void *NSZoneRealloc(NSZone * _Nullable zone, void * _Nullable ptr, NSUInteger size) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
extern "C" void NSZoneFree(NSZone * _Nullable zone, void *ptr) __attribute__((availability(swift, unavailable, message="Zone-based memory management is unavailable")));
static __inline__ __attribute__((always_inline)) __attribute__((ns_returns_retained)) id _Nullable NSMakeCollectable(CFTypeRef _Nullable __attribute__((cf_consumed)) cf) __attribute__((unavailable("not available in automatic reference counting mode"))) __attribute__((availability(swift, unavailable, message="Garbage Collection is not supported")));
static __inline__ __attribute__((always_inline)) __attribute__((ns_returns_retained)) id _Nullable NSMakeCollectable(CFTypeRef _Nullable __attribute__((cf_consumed)) cf) {

    return __null;



}

extern "C" NSUInteger NSPageSize(void);
extern "C" NSUInteger NSLogPageSize(void);
extern "C" NSUInteger NSRoundUpToMultipleOfPageSize(NSUInteger bytes);
extern "C" NSUInteger NSRoundDownToMultipleOfPageSize(NSUInteger bytes);
extern "C" void *NSAllocateMemoryPages(NSUInteger bytes);
extern "C" void NSDeallocateMemoryPages(void *ptr, NSUInteger bytes);
extern "C" void NSCopyMemoryPages(const void *source, void *dest, NSUInteger bytes);
extern "C" NSUInteger NSRealMemoryAvailable(void) __attribute__((availability(ios,introduced=2_0,deprecated=6_0,message="" )));

// @class NSInvocation;
#ifndef _REWRITER_typedef_NSInvocation
#define _REWRITER_typedef_NSInvocation
typedef struct objc_object NSInvocation;
typedef struct {} _objc_exc_NSInvocation;
#endif

#ifndef _REWRITER_typedef_NSMethodSignature
#define _REWRITER_typedef_NSMethodSignature
typedef struct objc_object NSMethodSignature;
typedef struct {} _objc_exc_NSMethodSignature;
#endif

#ifndef _REWRITER_typedef_NSCoder
#define _REWRITER_typedef_NSCoder
typedef struct objc_object NSCoder;
typedef struct {} _objc_exc_NSCoder;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSEnumerator
#define _REWRITER_typedef_NSEnumerator
typedef struct objc_object NSEnumerator;
typedef struct {} _objc_exc_NSEnumerator;
#endif

// @class Protocol;
#ifndef _REWRITER_typedef_Protocol
#define _REWRITER_typedef_Protocol
typedef struct objc_object Protocol;
typedef struct {} _objc_exc_Protocol;
#endif






// @protocol NSCopying

// - (id)copyWithZone:(nullable NSZone *)zone;

/* @end */


// @protocol NSMutableCopying

// - (id)mutableCopyWithZone:(nullable NSZone *)zone;

/* @end */


// @protocol NSCoding

// - (void)encodeWithCoder:(NSCoder *)aCoder;
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder;

/* @end */





// @protocol NSSecureCoding <NSCoding>
/* @required */


// + (BOOL)supportsSecureCoding;
/* @end */




// @interface NSObject (NSCoderMethods)

// + (NSInteger)version;
// + (void)setVersion:(NSInteger)aVersion;
// @property (readonly) Class classForCoder;
// - (nullable id)replacementObjectForCoder:(NSCoder *)aCoder;
// - (nullable id)awakeAfterUsingCoder:(NSCoder *)aDecoder __attribute__((ns_consumes_self)) __attribute__((ns_returns_retained));

/* @end */

// @protocol NSDiscardableContent
/* @required */
// - (BOOL)beginContentAccess;
// - (void)endContentAccess;
// - (void)discardContentIfPossible;
// - (BOOL)isContentDiscarded;
/* @end */


// @interface NSObject (NSDiscardableContentProxy)
// @property (readonly, retain) id autoContentAccessingProxy __attribute__((availability(ios,introduced=4_0)));
/* @end */




extern "C" id NSAllocateObject(Class aClass, NSUInteger extraBytes, NSZone * _Nullable zone) __attribute__((unavailable("not available in automatic reference counting mode")));

extern "C" void NSDeallocateObject(id object) __attribute__((unavailable("not available in automatic reference counting mode")));

extern "C" id NSCopyObject(id object, NSUInteger extraBytes, NSZone * _Nullable zone) __attribute__((unavailable("not available in automatic reference counting mode"))) __attribute__((availability(ios,introduced=2_0,deprecated=6_0,message="" )));

extern "C" BOOL NSShouldRetainWithZone(id anObject, NSZone * _Nullable requestedZone) __attribute__((unavailable("not available in automatic reference counting mode")));

extern "C" void NSIncrementExtraRefCount(id object) __attribute__((unavailable("not available in automatic reference counting mode")));

extern "C" BOOL NSDecrementExtraRefCountWasZero(id object) __attribute__((unavailable("not available in automatic reference counting mode")));

extern "C" NSUInteger NSExtraRefCount(id object) __attribute__((unavailable("not available in automatic reference counting mode")));




static __inline__ __attribute__((always_inline)) __attribute__((cf_returns_retained)) CFTypeRef _Nullable CFBridgingRetain(id _Nullable X) {
    return (__bridge_retained CFTypeRef)X;
}

static __inline__ __attribute__((always_inline)) id _Nullable CFBridgingRelease(CFTypeRef __attribute__((cf_consumed)) _Nullable X) {
    return (__bridge_transfer id)X;
}






// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

typedef struct {
    unsigned long state;
    id __attribute__((objc_ownership(none))) _Nullable * _Nullable itemsPtr;
    unsigned long * _Nullable mutationsPtr;
    unsigned long extra[5];
} NSFastEnumerationState;

// @protocol NSFastEnumeration

// - (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state objects:(id __attribute__((objc_ownership(none))) [])buffer count:(NSUInteger)len;

/* @end */



#ifndef _REWRITER_typedef_NSEnumerator
#define _REWRITER_typedef_NSEnumerator
typedef struct objc_object NSEnumerator;
typedef struct {} _objc_exc_NSEnumerator;
#endif

struct NSEnumerator_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// - (nullable ObjectType)nextObject;

/* @end */


// @interface NSEnumerator<ObjectType> (NSExtendedEnumerator)

// @property (readonly, copy) NSArray<ObjectType> *allObjects;

/* @end */











// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif





#ifndef _REWRITER_typedef_NSValue
#define _REWRITER_typedef_NSValue
typedef struct objc_object NSValue;
typedef struct {} _objc_exc_NSValue;
#endif

struct NSValue_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// - (void)getValue:(void *)value;
// @property (readonly) const char *objCType __attribute__((objc_returns_inner_pointer));

// - (instancetype)initWithBytes:(const void *)value objCType:(const char *)type __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSValue (NSValueCreation)

// + (NSValue *)valueWithBytes:(const void *)value objCType:(const char *)type;
// + (NSValue *)value:(const void *)value withObjCType:(const char *)type;

/* @end */


// @interface NSValue (NSValueExtensionMethods)

// + (NSValue *)valueWithNonretainedObject:(nullable id)anObject;
// @property (nullable, readonly) id nonretainedObjectValue;

// + (NSValue *)valueWithPointer:(nullable const void *)pointer;
// @property (nullable, readonly) void *pointerValue;

// - (BOOL)isEqualToValue:(NSValue *)value;

/* @end */



#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
typedef struct objc_object NSNumber;
typedef struct {} _objc_exc_NSNumber;
#endif

struct NSNumber_IMPL {
	struct NSValue_IMPL NSValue_IVARS;
};


// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithChar:(char)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedChar:(unsigned char)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithShort:(short)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedShort:(unsigned short)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithInt:(int)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedInt:(unsigned int)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithLong:(long)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedLong:(unsigned long)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithLongLong:(long long)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedLongLong:(unsigned long long)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithFloat:(float)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithDouble:(double)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithBool:(BOOL)value __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithInteger:(NSInteger)value __attribute__((availability(ios,introduced=2_0))) __attribute__((objc_designated_initializer));
// - (NSNumber *)initWithUnsignedInteger:(NSUInteger)value __attribute__((availability(ios,introduced=2_0))) __attribute__((objc_designated_initializer));

// @property (readonly) char charValue;
// @property (readonly) unsigned char unsignedCharValue;
// @property (readonly) short shortValue;
// @property (readonly) unsigned short unsignedShortValue;
// @property (readonly) int intValue;
// @property (readonly) unsigned int unsignedIntValue;
// @property (readonly) long longValue;
// @property (readonly) unsigned long unsignedLongValue;
// @property (readonly) long long longLongValue;
// @property (readonly) unsigned long long unsignedLongLongValue;
// @property (readonly) float floatValue;
// @property (readonly) double doubleValue;
// @property (readonly) BOOL boolValue;
// @property (readonly) NSInteger integerValue __attribute__((availability(ios,introduced=2_0)));
// @property (readonly) NSUInteger unsignedIntegerValue __attribute__((availability(ios,introduced=2_0)));

// @property (readonly, copy) NSString *stringValue;

// - (NSComparisonResult)compare:(NSNumber *)otherNumber;

// - (BOOL)isEqualToNumber:(NSNumber *)number;

// - (NSString *)descriptionWithLocale:(nullable id)locale;

/* @end */


// @interface NSNumber (NSNumberCreation)

// + (NSNumber *)numberWithChar:(char)value;
// + (NSNumber *)numberWithUnsignedChar:(unsigned char)value;
// + (NSNumber *)numberWithShort:(short)value;
// + (NSNumber *)numberWithUnsignedShort:(unsigned short)value;
// + (NSNumber *)numberWithInt:(int)value;
// + (NSNumber *)numberWithUnsignedInt:(unsigned int)value;
// + (NSNumber *)numberWithLong:(long)value;
// + (NSNumber *)numberWithUnsignedLong:(unsigned long)value;
// + (NSNumber *)numberWithLongLong:(long long)value;
// + (NSNumber *)numberWithUnsignedLongLong:(unsigned long long)value;
// + (NSNumber *)numberWithFloat:(float)value;
// + (NSNumber *)numberWithDouble:(double)value;
// + (NSNumber *)numberWithBool:(BOOL)value;
// + (NSNumber *)numberWithInteger:(NSInteger)value __attribute__((availability(ios,introduced=2_0)));
// + (NSNumber *)numberWithUnsignedInteger:(NSUInteger)value __attribute__((availability(ios,introduced=2_0)));

/* @end */



// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif




typedef struct _NSRange {
    NSUInteger location;
    NSUInteger length;
} NSRange;

typedef NSRange *NSRangePointer;

static __inline__ __attribute__((always_inline)) NSRange NSMakeRange(NSUInteger loc, NSUInteger len) {
    NSRange r;
    r.location = loc;
    r.length = len;
    return r;
}

static __inline__ __attribute__((always_inline)) NSUInteger NSMaxRange(NSRange range) {
    return (range.location + range.length);
}

static __inline__ __attribute__((always_inline)) BOOL NSLocationInRange(NSUInteger loc, NSRange range) {
    return (!(loc < range.location) && (loc - range.location) < range.length) ? ((bool)1) : ((bool)0);
}

static __inline__ __attribute__((always_inline)) BOOL NSEqualRanges(NSRange range1, NSRange range2) {
    return (range1.location == range2.location && range1.length == range2.length);
}

extern "C" NSRange NSUnionRange(NSRange range1, NSRange range2);
extern "C" NSRange NSIntersectionRange(NSRange range1, NSRange range2);
extern "C" NSString *NSStringFromRange(NSRange range);
extern "C" NSRange NSRangeFromString(NSString *aString);

// @interface NSValue (NSValueRangeExtensions)

// + (NSValue *)valueWithRange:(NSRange)range;
// @property (readonly) NSRange rangeValue;

/* @end */



// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSIndexSet
#define _REWRITER_typedef_NSIndexSet
typedef struct objc_object NSIndexSet;
typedef struct {} _objc_exc_NSIndexSet;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif







#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

struct NSArray_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly) NSUInteger count;
// - (ObjectType)objectAtIndex:(NSUInteger)index;
// - (instancetype)init __attribute__((objc_designated_initializer));
// - (instancetype)initWithObjects:(const ObjectType [])objects count:(NSUInteger)cnt __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSArray<ObjectType> (NSExtendedArray)

// - (NSArray<ObjectType> *)arrayByAddingObject:(ObjectType)anObject;
// - (NSArray<ObjectType> *)arrayByAddingObjectsFromArray:(NSArray<ObjectType> *)otherArray;
// - (NSString *)componentsJoinedByString:(NSString *)separator;
// - (BOOL)containsObject:(ObjectType)anObject;
// @property (readonly, copy) NSString *description;
// - (NSString *)descriptionWithLocale:(nullable id)locale;
// - (NSString *)descriptionWithLocale:(nullable id)locale indent:(NSUInteger)level;
// - (nullable ObjectType)firstObjectCommonWithArray:(NSArray<ObjectType> *)otherArray;
// - (void)getObjects:(ObjectType __attribute__((objc_ownership(none))) [])objects range:(NSRange)range;
// - (NSUInteger)indexOfObject:(ObjectType)anObject;
// - (NSUInteger)indexOfObject:(ObjectType)anObject inRange:(NSRange)range;
// - (NSUInteger)indexOfObjectIdenticalTo:(ObjectType)anObject;
// - (NSUInteger)indexOfObjectIdenticalTo:(ObjectType)anObject inRange:(NSRange)range;
// - (BOOL)isEqualToArray:(NSArray<ObjectType> *)otherArray;
// @property (nullable, nonatomic, readonly) ObjectType firstObject __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, nonatomic, readonly) ObjectType lastObject;
// - (NSEnumerator<ObjectType> *)objectEnumerator;
// - (NSEnumerator<ObjectType> *)reverseObjectEnumerator;
// @property (readonly, copy) NSData *sortedArrayHint;
// - (NSArray<ObjectType> *)sortedArrayUsingFunction:(NSInteger (*)(ObjectType, ObjectType, void * _Nullable))comparator context:(nullable void *)context;
// - (NSArray<ObjectType> *)sortedArrayUsingFunction:(NSInteger (*)(ObjectType, ObjectType, void * _Nullable))comparator context:(nullable void *)context hint:(nullable NSData *)hint;
// - (NSArray<ObjectType> *)sortedArrayUsingSelector:(SEL)comparator;
// - (NSArray<ObjectType> *)subarrayWithRange:(NSRange)range;
// - (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;
// - (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically;

// - (void)makeObjectsPerformSelector:(SEL)aSelector __attribute__((availability(swift, unavailable, message="Use enumerateObjectsUsingBlock: or a for loop instead")));
// - (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(nullable id)argument __attribute__((availability(swift, unavailable, message="Use enumerateObjectsUsingBlock: or a for loop instead")));

// - (NSArray<ObjectType> *)objectsAtIndexes:(NSIndexSet *)indexes;

// - (ObjectType)objectAtIndexedSubscript:(NSUInteger)idx __attribute__((availability(ios,introduced=6_0)));

// - (void)enumerateObjectsUsingBlock:(void (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));
// - (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));
// - (void)enumerateObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts usingBlock:(void (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));

// - (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));
// - (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));
// - (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));

// - (NSIndexSet *)indexesOfObjectsPassingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));
// - (NSIndexSet *)indexesOfObjectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));
// - (NSIndexSet *)indexesOfObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));

// - (NSArray<ObjectType> *)sortedArrayUsingComparator:(NSComparator)cmptr __attribute__((availability(ios,introduced=4_0)));
// - (NSArray<ObjectType> *)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr __attribute__((availability(ios,introduced=4_0)));

typedef NSUInteger NSBinarySearchingOptions; enum {
 NSBinarySearchingFirstEqual = (1UL << 8),
 NSBinarySearchingLastEqual = (1UL << 9),
 NSBinarySearchingInsertionIndex = (1UL << 10),
};

// - (NSUInteger)indexOfObject:(ObjectType)obj inSortedRange:(NSRange)r options:(NSBinarySearchingOptions)opts usingComparator:(NSComparator)cmp __attribute__((availability(ios,introduced=4_0)));

/* @end */


// @interface NSArray<ObjectType> (NSArrayCreation)

// + (instancetype)array;
// + (instancetype)arrayWithObject:(ObjectType)anObject;
// + (instancetype)arrayWithObjects:(const ObjectType [])objects count:(NSUInteger)cnt;
// + (instancetype)arrayWithObjects:(ObjectType)firstObj, ... __attribute__((sentinel(0,1)));
// + (instancetype)arrayWithArray:(NSArray<ObjectType> *)array;

// - (instancetype)initWithObjects:(ObjectType)firstObj, ... __attribute__((sentinel(0,1)));
// - (instancetype)initWithArray:(NSArray<ObjectType> *)array;
// - (instancetype)initWithArray:(NSArray<ObjectType> *)array copyItems:(BOOL)flag;

// + (nullable NSArray<ObjectType> *)arrayWithContentsOfFile:(NSString *)path;
// + (nullable NSArray<ObjectType> *)arrayWithContentsOfURL:(NSURL *)url;
// - (nullable NSArray<ObjectType> *)initWithContentsOfFile:(NSString *)path;
// - (nullable NSArray<ObjectType> *)initWithContentsOfURL:(NSURL *)url;

/* @end */


// @interface NSArray<ObjectType> (NSDeprecated)



// - (void)getObjects:(ObjectType __attribute__((objc_ownership(none))) [])objects;

/* @end */





#ifndef _REWRITER_typedef_NSMutableArray
#define _REWRITER_typedef_NSMutableArray
typedef struct objc_object NSMutableArray;
typedef struct {} _objc_exc_NSMutableArray;
#endif

struct NSMutableArray_IMPL {
	struct NSArray_IMPL NSArray_IVARS;
};


// - (void)addObject:(ObjectType)anObject;
// - (void)insertObject:(ObjectType)anObject atIndex:(NSUInteger)index;
// - (void)removeLastObject;
// - (void)removeObjectAtIndex:(NSUInteger)index;
// - (void)replaceObjectAtIndex:(NSUInteger)index withObject:(ObjectType)anObject;
// - (instancetype)init __attribute__((objc_designated_initializer));
// - (instancetype)initWithCapacity:(NSUInteger)numItems __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSMutableArray<ObjectType> (NSExtendedMutableArray)

// - (void)addObjectsFromArray:(NSArray<ObjectType> *)otherArray;
// - (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
// - (void)removeAllObjects;
// - (void)removeObject:(ObjectType)anObject inRange:(NSRange)range;
// - (void)removeObject:(ObjectType)anObject;
// - (void)removeObjectIdenticalTo:(ObjectType)anObject inRange:(NSRange)range;
// - (void)removeObjectIdenticalTo:(ObjectType)anObject;
// - (void)removeObjectsFromIndices:(NSUInteger *)indices numIndices:(NSUInteger)cnt __attribute__((availability(ios,introduced=2_0,deprecated=4_0,message="" )));
// - (void)removeObjectsInArray:(NSArray<ObjectType> *)otherArray;
// - (void)removeObjectsInRange:(NSRange)range;
// - (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(NSArray<ObjectType> *)otherArray range:(NSRange)otherRange;
// - (void)replaceObjectsInRange:(NSRange)range withObjectsFromArray:(NSArray<ObjectType> *)otherArray;
// - (void)setArray:(NSArray<ObjectType> *)otherArray;
// - (void)sortUsingFunction:(NSInteger (*)(ObjectType, ObjectType, void * _Nullable))compare context:(nullable void *)context;
// - (void)sortUsingSelector:(SEL)comparator;

// - (void)insertObjects:(NSArray<ObjectType> *)objects atIndexes:(NSIndexSet *)indexes;
// - (void)removeObjectsAtIndexes:(NSIndexSet *)indexes;
// - (void)replaceObjectsAtIndexes:(NSIndexSet *)indexes withObjects:(NSArray<ObjectType> *)objects;

// - (void)setObject:(ObjectType)obj atIndexedSubscript:(NSUInteger)idx __attribute__((availability(ios,introduced=6_0)));

// - (void)sortUsingComparator:(NSComparator)cmptr __attribute__((availability(ios,introduced=4_0)));
// - (void)sortWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr __attribute__((availability(ios,introduced=4_0)));

/* @end */


// @interface NSMutableArray<ObjectType> (NSMutableArrayCreation)

// + (instancetype)arrayWithCapacity:(NSUInteger)numItems;

// + (nullable NSMutableArray<ObjectType> *)arrayWithContentsOfFile:(NSString *)path;
// + (nullable NSMutableArray<ObjectType> *)arrayWithContentsOfURL:(NSURL *)url;
// - (nullable NSMutableArray<ObjectType> *)initWithContentsOfFile:(NSString *)path;
// - (nullable NSMutableArray<ObjectType> *)initWithContentsOfURL:(NSURL *)url;

/* @end */









__attribute__((unavailable("not available in automatic reference counting mode")))

#ifndef _REWRITER_typedef_NSAutoreleasePool
#define _REWRITER_typedef_NSAutoreleasePool
typedef struct objc_object NSAutoreleasePool;
typedef struct {} _objc_exc_NSAutoreleasePool;
#endif

struct NSAutoreleasePool_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *_token;
	void *_reserved3;
	void *_reserved2;
	void *_reserved;
};


// + (void)addObject:(id)anObject;

// - (void)addObject:(id)anObject;

// - (void)drain;

/* @end */










typedef unsigned short unichar;






// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSCharacterSet
#define _REWRITER_typedef_NSCharacterSet
typedef struct objc_object NSCharacterSet;
typedef struct {} _objc_exc_NSCharacterSet;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSLocale
#define _REWRITER_typedef_NSLocale
typedef struct objc_object NSLocale;
typedef struct {} _objc_exc_NSLocale;
#endif






typedef NSUInteger NSStringCompareOptions; enum {
    NSCaseInsensitiveSearch = 1,
    NSLiteralSearch = 2,
    NSBackwardsSearch = 4,
    NSAnchoredSearch = 8,
    NSNumericSearch = 64,
    NSDiacriticInsensitiveSearch __attribute__((availability(ios,introduced=2_0))) = 128,
    NSWidthInsensitiveSearch __attribute__((availability(ios,introduced=2_0))) = 256,
    NSForcedOrderingSearch __attribute__((availability(ios,introduced=2_0))) = 512,
    NSRegularExpressionSearch __attribute__((availability(ios,introduced=3_2))) = 1024
};





typedef NSUInteger NSStringEncoding;
enum {
    NSASCIIStringEncoding = 1,
    NSNEXTSTEPStringEncoding = 2,
    NSJapaneseEUCStringEncoding = 3,
    NSUTF8StringEncoding = 4,
    NSISOLatin1StringEncoding = 5,
    NSSymbolStringEncoding = 6,
    NSNonLossyASCIIStringEncoding = 7,
    NSShiftJISStringEncoding = 8,
    NSISOLatin2StringEncoding = 9,
    NSUnicodeStringEncoding = 10,
    NSWindowsCP1251StringEncoding = 11,
    NSWindowsCP1252StringEncoding = 12,
    NSWindowsCP1253StringEncoding = 13,
    NSWindowsCP1254StringEncoding = 14,
    NSWindowsCP1250StringEncoding = 15,
    NSISO2022JPStringEncoding = 21,
    NSMacOSRomanStringEncoding = 30,

    NSUTF16StringEncoding = NSUnicodeStringEncoding,

    NSUTF16BigEndianStringEncoding = 0x90000100,
    NSUTF16LittleEndianStringEncoding = 0x94000100,

    NSUTF32StringEncoding = 0x8c000100,
    NSUTF32BigEndianStringEncoding = 0x98000100,
    NSUTF32LittleEndianStringEncoding = 0x9c000100
};

typedef NSUInteger NSStringEncodingConversionOptions; enum {
    NSStringEncodingConversionAllowLossy = 1,
    NSStringEncodingConversionExternalRepresentation = 2
};



#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

struct NSString_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};






// @property (readonly) NSUInteger length;
// - (unichar)characterAtIndex:(NSUInteger)index;



// - (instancetype)init __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSString (NSStringExtensionMethods)
// - (NSString *)substringFromIndex:(NSUInteger)from;
// - (NSString *)substringToIndex:(NSUInteger)to;
// - (NSString *)substringWithRange:(NSRange)range;

// - (void)getCharacters:(unichar *)buffer range:(NSRange)range;






// - (NSComparisonResult)compare:(NSString *)string;
// - (NSComparisonResult)compare:(NSString *)string options:(NSStringCompareOptions)mask;
// - (NSComparisonResult)compare:(NSString *)string options:(NSStringCompareOptions)mask range:(NSRange)compareRange;
// - (NSComparisonResult)compare:(NSString *)string options:(NSStringCompareOptions)mask range:(NSRange)compareRange locale:(nullable id)locale;
// - (NSComparisonResult)caseInsensitiveCompare:(NSString *)string;
// - (NSComparisonResult)localizedCompare:(NSString *)string;
// - (NSComparisonResult)localizedCaseInsensitiveCompare:(NSString *)string;



// - (NSComparisonResult)localizedStandardCompare:(NSString *)string __attribute__((availability(ios,introduced=4_0)));

// - (BOOL)isEqualToString:(NSString *)aString;






// - (BOOL)hasPrefix:(NSString *)str;
// - (BOOL)hasSuffix:(NSString *)str;

// - (NSString *)commonPrefixWithString:(NSString *)str options:(NSStringCompareOptions)mask;



// - (BOOL)containsString:(NSString *)str __attribute__((availability(ios,introduced=8_0)));
// - (BOOL)localizedCaseInsensitiveContainsString:(NSString *)str __attribute__((availability(ios,introduced=8_0)));



// - (BOOL)localizedStandardContainsString:(NSString *)str __attribute__((availability(ios,introduced=9_0)));
// - (NSRange)localizedStandardRangeOfString:(NSString *)str __attribute__((availability(ios,introduced=9_0)));





// - (NSRange)rangeOfString:(NSString *)searchString;
// - (NSRange)rangeOfString:(NSString *)searchString options:(NSStringCompareOptions)mask;
// - (NSRange)rangeOfString:(NSString *)searchString options:(NSStringCompareOptions)mask range:(NSRange)searchRange;
// - (NSRange)rangeOfString:(NSString *)searchString options:(NSStringCompareOptions)mask range:(NSRange)searchRange locale:(nullable NSLocale *)locale __attribute__((availability(ios,introduced=2_0)));



// - (NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)searchSet;
// - (NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)searchSet options:(NSStringCompareOptions)mask;
// - (NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)searchSet options:(NSStringCompareOptions)mask range:(NSRange)searchRange;

// - (NSRange)rangeOfComposedCharacterSequenceAtIndex:(NSUInteger)index;
// - (NSRange)rangeOfComposedCharacterSequencesForRange:(NSRange)range __attribute__((availability(ios,introduced=2_0)));

// - (NSString *)stringByAppendingString:(NSString *)aString;
// - (NSString *)stringByAppendingFormat:(NSString *)format, ... __attribute__((format(__NSString__, 1, 2)));






// @property (readonly) double doubleValue;
// @property (readonly) float floatValue;
// @property (readonly) int intValue;
// @property (readonly) NSInteger integerValue __attribute__((availability(ios,introduced=2_0)));
// @property (readonly) long long longLongValue __attribute__((availability(ios,introduced=2_0)));
// @property (readonly) BOOL boolValue __attribute__((availability(ios,introduced=2_0)));






// @property (readonly, copy) NSString *uppercaseString;
// @property (readonly, copy) NSString *lowercaseString;
// @property (readonly, copy) NSString *capitalizedString;



// @property (readonly, copy) NSString *localizedUppercaseString __attribute__((availability(ios,introduced=9_0)));
// @property (readonly, copy) NSString *localizedLowercaseString __attribute__((availability(ios,introduced=9_0)));
// @property (readonly, copy) NSString *localizedCapitalizedString __attribute__((availability(ios,introduced=9_0)));



// - (NSString *)uppercaseStringWithLocale:(nullable NSLocale *)locale __attribute__((availability(ios,introduced=6_0)));
// - (NSString *)lowercaseStringWithLocale:(nullable NSLocale *)locale __attribute__((availability(ios,introduced=6_0)));
// - (NSString *)capitalizedStringWithLocale:(nullable NSLocale *)locale __attribute__((availability(ios,introduced=6_0)));




// - (void)getLineStart:(nullable NSUInteger *)startPtr end:(nullable NSUInteger *)lineEndPtr contentsEnd:(nullable NSUInteger *)contentsEndPtr forRange:(NSRange)range;
// - (NSRange)lineRangeForRange:(NSRange)range;

// - (void)getParagraphStart:(nullable NSUInteger *)startPtr end:(nullable NSUInteger *)parEndPtr contentsEnd:(nullable NSUInteger *)contentsEndPtr forRange:(NSRange)range;
// - (NSRange)paragraphRangeForRange:(NSRange)range;

typedef NSUInteger NSStringEnumerationOptions; enum {

    NSStringEnumerationByLines = 0,
    NSStringEnumerationByParagraphs = 1,
    NSStringEnumerationByComposedCharacterSequences = 2,
    NSStringEnumerationByWords = 3,
    NSStringEnumerationBySentences = 4,

    NSStringEnumerationReverse = 1UL << 8,
    NSStringEnumerationSubstringNotRequired = 1UL << 9,
    NSStringEnumerationLocalized = 1UL << 10
};



// - (void)enumerateSubstringsInRange:(NSRange)range options:(NSStringEnumerationOptions)opts usingBlock:(void (^)(NSString * _Nullable substring, NSRange substringRange, NSRange enclosingRange, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));
// - (void)enumerateLinesUsingBlock:(void (^)(NSString *line, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));




// @property (nullable, readonly) __attribute__((objc_ownership(strong))) const char *UTF8String __attribute__((objc_returns_inner_pointer));

// @property (readonly) NSStringEncoding fastestEncoding;
// @property (readonly) NSStringEncoding smallestEncoding;

// - (nullable NSData *)dataUsingEncoding:(NSStringEncoding)encoding allowLossyConversion:(BOOL)lossy;
// - (nullable NSData *)dataUsingEncoding:(NSStringEncoding)encoding;

// - (BOOL)canBeConvertedToEncoding:(NSStringEncoding)encoding;



// - (nullable __attribute__((objc_ownership(strong))) const char *)cStringUsingEncoding:(NSStringEncoding)encoding __attribute__((objc_returns_inner_pointer));
// - (BOOL)getCString:(char *)buffer maxLength:(NSUInteger)maxBufferCount encoding:(NSStringEncoding)encoding;
// - (BOOL)getBytes:(nullable void *)buffer maxLength:(NSUInteger)maxBufferCount usedLength:(nullable NSUInteger *)usedBufferCount encoding:(NSStringEncoding)encoding options:(NSStringEncodingConversionOptions)options range:(NSRange)range remainingRange:(nullable NSRangePointer)leftover;



// - (NSUInteger)maximumLengthOfBytesUsingEncoding:(NSStringEncoding)enc;
// - (NSUInteger)lengthOfBytesUsingEncoding:(NSStringEncoding)enc;

// + (const NSStringEncoding *)availableStringEncodings;
// + (NSString *)localizedNameOfStringEncoding:(NSStringEncoding)encoding;



// + (NSStringEncoding)defaultCStringEncoding;




// @property (readonly, copy) NSString *decomposedStringWithCanonicalMapping;
// @property (readonly, copy) NSString *precomposedStringWithCanonicalMapping;
// @property (readonly, copy) NSString *decomposedStringWithCompatibilityMapping;
// @property (readonly, copy) NSString *precomposedStringWithCompatibilityMapping;

// - (NSArray<NSString *> *)componentsSeparatedByString:(NSString *)separator;
// - (NSArray<NSString *> *)componentsSeparatedByCharactersInSet:(NSCharacterSet *)separator __attribute__((availability(ios,introduced=2_0)));

// - (NSString *)stringByTrimmingCharactersInSet:(NSCharacterSet *)set;
// - (NSString *)stringByPaddingToLength:(NSUInteger)newLength withString:(NSString *)padString startingAtIndex:(NSUInteger)padIndex;



// - (NSString *)stringByFoldingWithOptions:(NSStringCompareOptions)options locale:(nullable NSLocale *)locale __attribute__((availability(ios,introduced=2_0)));



// - (NSString *)stringByReplacingOccurrencesOfString:(NSString *)target withString:(NSString *)replacement options:(NSStringCompareOptions)options range:(NSRange)searchRange __attribute__((availability(ios,introduced=2_0)));



// - (NSString *)stringByReplacingOccurrencesOfString:(NSString *)target withString:(NSString *)replacement __attribute__((availability(ios,introduced=2_0)));



// - (NSString *)stringByReplacingCharactersInRange:(NSRange)range withString:(NSString *)replacement __attribute__((availability(ios,introduced=2_0)));



// - (nullable NSString *)stringByApplyingTransform:(NSString *)transform reverse:(BOOL)reverse __attribute__((availability(ios,introduced=9_0)));

extern "C" NSString * const NSStringTransformLatinToKatakana __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformLatinToHiragana __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformLatinToHangul __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformLatinToArabic __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformLatinToHebrew __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformLatinToThai __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformLatinToCyrillic __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformLatinToGreek __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformToLatin __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformMandarinToLatin __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformHiraganaToKatakana __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformFullwidthToHalfwidth __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformToXMLHex __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformToUnicodeName __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformStripCombiningMarks __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSStringTransformStripDiacritics __attribute__((availability(ios,introduced=9_0)));




// - (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)useAuxiliaryFile encoding:(NSStringEncoding)enc error:(NSError **)error;
// - (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile encoding:(NSStringEncoding)enc error:(NSError **)error;

// @property (readonly, copy) NSString *description;

// @property (readonly) NSUInteger hash;






// - (instancetype)initWithCharactersNoCopy:(unichar *)characters length:(NSUInteger)length freeWhenDone:(BOOL)freeBuffer;
// - (instancetype)initWithCharacters:(const unichar *)characters length:(NSUInteger)length;
// - (nullable instancetype)initWithUTF8String:(const char *)nullTerminatedCString;
// - (instancetype)initWithString:(NSString *)aString;
// - (instancetype)initWithFormat:(NSString *)format, ... __attribute__((format(__NSString__, 1, 2)));
// - (instancetype)initWithFormat:(NSString *)format arguments:(va_list)argList __attribute__((format(__NSString__, 1, 0)));
// - (instancetype)initWithFormat:(NSString *)format locale:(nullable id)locale, ... __attribute__((format(__NSString__, 1, 3)));
// - (instancetype)initWithFormat:(NSString *)format locale:(nullable id)locale arguments:(va_list)argList __attribute__((format(__NSString__, 1, 0)));
// - (nullable instancetype)initWithData:(NSData *)data encoding:(NSStringEncoding)encoding;
// - (nullable instancetype)initWithBytes:(const void *)bytes length:(NSUInteger)len encoding:(NSStringEncoding)encoding;
// - (nullable instancetype)initWithBytesNoCopy:(void *)bytes length:(NSUInteger)len encoding:(NSStringEncoding)encoding freeWhenDone:(BOOL)freeBuffer;

// + (instancetype)string;
// + (instancetype)stringWithString:(NSString *)string;
// + (instancetype)stringWithCharacters:(const unichar *)characters length:(NSUInteger)length;
// + (nullable instancetype)stringWithUTF8String:(const char *)nullTerminatedCString;
// + (instancetype)stringWithFormat:(NSString *)format, ... __attribute__((format(__NSString__, 1, 2)));
// + (instancetype)localizedStringWithFormat:(NSString *)format, ... __attribute__((format(__NSString__, 1, 2)));

// - (nullable instancetype)initWithCString:(const char *)nullTerminatedCString encoding:(NSStringEncoding)encoding;
// + (nullable instancetype)stringWithCString:(const char *)cString encoding:(NSStringEncoding)enc;



// - (nullable instancetype)initWithContentsOfURL:(NSURL *)url encoding:(NSStringEncoding)enc error:(NSError **)error;
// - (nullable instancetype)initWithContentsOfFile:(NSString *)path encoding:(NSStringEncoding)enc error:(NSError **)error;
// + (nullable instancetype)stringWithContentsOfURL:(NSURL *)url encoding:(NSStringEncoding)enc error:(NSError **)error;
// + (nullable instancetype)stringWithContentsOfFile:(NSString *)path encoding:(NSStringEncoding)enc error:(NSError **)error;



// - (nullable instancetype)initWithContentsOfURL:(NSURL *)url usedEncoding:(nullable NSStringEncoding *)enc error:(NSError **)error;
// - (nullable instancetype)initWithContentsOfFile:(NSString *)path usedEncoding:(nullable NSStringEncoding *)enc error:(NSError **)error;
// + (nullable instancetype)stringWithContentsOfURL:(NSURL *)url usedEncoding:(nullable NSStringEncoding *)enc error:(NSError **)error;
// + (nullable instancetype)stringWithContentsOfFile:(NSString *)path usedEncoding:(nullable NSStringEncoding *)enc error:(NSError **)error;

/* @end */



// @interface NSString (NSStringEncodingDetection)
#if 0
+ (NSStringEncoding)stringEncodingForData:(NSData *)data
                          encodingOptions:(nullable NSDictionary<NSString *, id> *)opts
                          convertedString:(NSString * _Nullable * _Nullable)string
                      usedLossyConversion:(nullable BOOL *)usedLossyConversion __attribute__((availability(ios,introduced=8_0)));
#endif




extern "C" NSString * const NSStringEncodingDetectionSuggestedEncodingsKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSStringEncodingDetectionDisallowedEncodingsKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSStringEncodingDetectionUseOnlySuggestedEncodingsKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSStringEncodingDetectionAllowLossyKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSStringEncodingDetectionFromWindowsKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSStringEncodingDetectionLossySubstitutionKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSStringEncodingDetectionLikelyLanguageKey __attribute__((availability(ios,introduced=8_0)));

/* @end */





#ifndef _REWRITER_typedef_NSMutableString
#define _REWRITER_typedef_NSMutableString
typedef struct objc_object NSMutableString;
typedef struct {} _objc_exc_NSMutableString;
#endif

struct NSMutableString_IMPL {
	struct NSString_IMPL NSString_IVARS;
};






// - (void)replaceCharactersInRange:(NSRange)range withString:(NSString *)aString;

/* @end */


// @interface NSMutableString (NSMutableStringExtensionMethods)



// - (void)insertString:(NSString *)aString atIndex:(NSUInteger)loc;
// - (void)deleteCharactersInRange:(NSRange)range;
// - (void)appendString:(NSString *)aString;
// - (void)appendFormat:(NSString *)format, ... __attribute__((format(__NSString__, 1, 2)));
// - (void)setString:(NSString *)aString;



// - (NSUInteger)replaceOccurrencesOfString:(NSString *)target withString:(NSString *)replacement options:(NSStringCompareOptions)options range:(NSRange)searchRange;



// - (BOOL)applyTransform:(NSString *)transform reverse:(BOOL)reverse range:(NSRange)range updatedRange:(nullable NSRangePointer)resultingRange __attribute__((availability(ios,introduced=9_0)));



// - (NSMutableString *)initWithCapacity:(NSUInteger)capacity;
// + (NSMutableString *)stringWithCapacity:(NSUInteger)capacity;

/* @end */




extern "C" NSString * const NSCharacterConversionException;
extern "C" NSString * const NSParseErrorException;




// @interface NSString (NSExtendedStringPropertyListParsing)



// - (id)propertyList;
// - (nullable NSDictionary *)propertyListFromStringsFileFormat;

/* @end */


// @interface NSString (NSStringDeprecated)



// - (nullable const char *)cString __attribute__((objc_returns_inner_pointer)) __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (nullable const char *)lossyCString __attribute__((objc_returns_inner_pointer)) __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (NSUInteger)cStringLength __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (void)getCString:(char *)bytes __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (void)getCString:(char *)bytes maxLength:(NSUInteger)maxLength __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (void)getCString:(char *)bytes maxLength:(NSUInteger)maxLength range:(NSRange)aRange remainingRange:(nullable NSRangePointer)leftoverRange __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));

// - (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));

// - (nullable id)initWithContentsOfFile:(NSString *)path __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (nullable id)initWithContentsOfURL:(NSURL *)url __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// + (nullable id)stringWithContentsOfFile:(NSString *)path __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// + (nullable id)stringWithContentsOfURL:(NSURL *)url __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));

// - (nullable id)initWithCStringNoCopy:(char *)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeBuffer __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (nullable id)initWithCString:(const char *)bytes length:(NSUInteger)length __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (nullable id)initWithCString:(const char *)bytes __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// + (nullable id)stringWithCString:(const char *)bytes length:(NSUInteger)length __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// + (nullable id)stringWithCString:(const char *)bytes __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));



// - (void)getCharacters:(unichar *)buffer;

/* @end */


enum {
    NSProprietaryStringEncoding = 65536
};

#ifndef _REWRITER_typedef_NSSimpleCString
#define _REWRITER_typedef_NSSimpleCString
typedef struct objc_object NSSimpleCString;
typedef struct {} _objc_exc_NSSimpleCString;
#endif

struct NSSimpleCString_IMPL {
	struct NSString_IMPL NSString_IVARS;
	char *bytes;
	int numBytes;
	int _unused;
};

/* @end */



#ifndef _REWRITER_typedef_NSConstantString
#define _REWRITER_typedef_NSConstantString
typedef struct objc_object NSConstantString;
typedef struct {} _objc_exc_NSConstantString;
#endif

struct NSConstantString_IMPL {
	struct NSSimpleCString_IMPL NSSimpleCString_IVARS;
};

/* @end */









// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSSet
#define _REWRITER_typedef_NSSet
typedef struct objc_object NSSet;
typedef struct {} _objc_exc_NSSet;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif







#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

struct NSDictionary_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly) NSUInteger count;
// - (nullable ObjectType)objectForKey:(KeyType)aKey;
// - (NSEnumerator<KeyType> *)keyEnumerator;
// - (instancetype)init __attribute__((objc_designated_initializer));



// - (instancetype)initWithObjects:(const ObjectType [])objects forKeys:(const KeyType <NSCopying> [])keys count:(NSUInteger)cnt __attribute__((objc_designated_initializer));

// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSDictionary<KeyType, ObjectType> (NSExtendedDictionary)

// @property (readonly, copy) NSArray<KeyType> *allKeys;
// - (NSArray<KeyType> *)allKeysForObject:(ObjectType)anObject;
// @property (readonly, copy) NSArray<ObjectType> *allValues;
// @property (readonly, copy) NSString *description;
// @property (readonly, copy) NSString *descriptionInStringsFileFormat;
// - (NSString *)descriptionWithLocale:(nullable id)locale;
// - (NSString *)descriptionWithLocale:(nullable id)locale indent:(NSUInteger)level;
// - (BOOL)isEqualToDictionary:(NSDictionary<KeyType, ObjectType> *)otherDictionary;
// - (NSEnumerator<ObjectType> *)objectEnumerator;
// - (NSArray<ObjectType> *)objectsForKeys:(NSArray<KeyType> *)keys notFoundMarker:(ObjectType)marker;
// - (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;
// - (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically;

// - (NSArray<KeyType> *)keysSortedByValueUsingSelector:(SEL)comparator;

// - (void)getObjects:(ObjectType __attribute__((objc_ownership(none))) [])objects andKeys:(KeyType __attribute__((objc_ownership(none))) [])keys count:(NSUInteger)count __attribute__((availability(ios,introduced=5_0)));

// - (nullable ObjectType)objectForKeyedSubscript:(KeyType)key __attribute__((availability(ios,introduced=6_0)));

// - (void)enumerateKeysAndObjectsUsingBlock:(void (^)(KeyType key, ObjectType obj, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));
// - (void)enumerateKeysAndObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(KeyType key, ObjectType obj, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));

// - (NSArray<KeyType> *)keysSortedByValueUsingComparator:(NSComparator)cmptr __attribute__((availability(ios,introduced=4_0)));
// - (NSArray<KeyType> *)keysSortedByValueWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr __attribute__((availability(ios,introduced=4_0)));

// - (NSSet<KeyType> *)keysOfEntriesPassingTest:(BOOL (^)(KeyType key, ObjectType obj, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));
// - (NSSet<KeyType> *)keysOfEntriesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(KeyType key, ObjectType obj, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));

/* @end */


// @interface NSDictionary<KeyType, ObjectType> (NSDeprecated)

// - (void)getObjects:(ObjectType __attribute__((objc_ownership(none))) [])objects andKeys:(KeyType __attribute__((objc_ownership(none))) [])keys;
/* @end */


// @interface NSDictionary<KeyType, ObjectType> (NSDictionaryCreation)

// + (instancetype)dictionary;
// + (instancetype)dictionaryWithObject:(ObjectType)object forKey:(KeyType <NSCopying>)key;



// + (instancetype)dictionaryWithObjects:(const ObjectType [])objects forKeys:(const KeyType <NSCopying> [])keys count:(NSUInteger)cnt;


// + (instancetype)dictionaryWithObjectsAndKeys:(id)firstObject, ... __attribute__((sentinel(0,1))) __attribute__((availability(swift, unavailable, message="Use dictionary literals instead")));

// + (instancetype)dictionaryWithDictionary:(NSDictionary<KeyType, ObjectType> *)dict;
// + (instancetype)dictionaryWithObjects:(NSArray<ObjectType> *)objects forKeys:(NSArray<KeyType <NSCopying>> *)keys;

// - (instancetype)initWithObjectsAndKeys:(id)firstObject, ... __attribute__((sentinel(0,1)));
// - (instancetype)initWithDictionary:(NSDictionary<KeyType, ObjectType> *)otherDictionary;
// - (instancetype)initWithDictionary:(NSDictionary<KeyType, ObjectType> *)otherDictionary copyItems:(BOOL)flag;
// - (instancetype)initWithObjects:(NSArray<ObjectType> *)objects forKeys:(NSArray<KeyType <NSCopying>> *)keys;

// + (nullable NSDictionary<KeyType, ObjectType> *)dictionaryWithContentsOfFile:(NSString *)path;
// + (nullable NSDictionary<KeyType, ObjectType> *)dictionaryWithContentsOfURL:(NSURL *)url;
// - (nullable NSDictionary<KeyType, ObjectType> *)initWithContentsOfFile:(NSString *)path;
// - (nullable NSDictionary<KeyType, ObjectType> *)initWithContentsOfURL:(NSURL *)url;

/* @end */





#ifndef _REWRITER_typedef_NSMutableDictionary
#define _REWRITER_typedef_NSMutableDictionary
typedef struct objc_object NSMutableDictionary;
typedef struct {} _objc_exc_NSMutableDictionary;
#endif

struct NSMutableDictionary_IMPL {
	struct NSDictionary_IMPL NSDictionary_IVARS;
};


// - (void)removeObjectForKey:(KeyType)aKey;
// - (void)setObject:(ObjectType)anObject forKey:(KeyType <NSCopying>)aKey;
// - (instancetype)init __attribute__((objc_designated_initializer));
// - (instancetype)initWithCapacity:(NSUInteger)numItems __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSMutableDictionary<KeyType, ObjectType> (NSExtendedMutableDictionary)

// - (void)addEntriesFromDictionary:(NSDictionary<KeyType, ObjectType> *)otherDictionary;
// - (void)removeAllObjects;
// - (void)removeObjectsForKeys:(NSArray<KeyType> *)keyArray;
// - (void)setDictionary:(NSDictionary<KeyType, ObjectType> *)otherDictionary;
// - (void)setObject:(nullable ObjectType)obj forKeyedSubscript:(KeyType <NSCopying>)key __attribute__((availability(ios,introduced=6_0)));

/* @end */


// @interface NSMutableDictionary<KeyType, ObjectType> (NSMutableDictionaryCreation)

// + (instancetype)dictionaryWithCapacity:(NSUInteger)numItems;

// + (nullable NSMutableDictionary<KeyType, ObjectType> *)dictionaryWithContentsOfFile:(NSString *)path;
// + (nullable NSMutableDictionary<KeyType, ObjectType> *)dictionaryWithContentsOfURL:(NSURL *)url;
// - (nullable NSMutableDictionary<KeyType, ObjectType> *)initWithContentsOfFile:(NSString *)path;
// - (nullable NSMutableDictionary<KeyType, ObjectType> *)initWithContentsOfURL:(NSURL *)url;

/* @end */


// @interface NSDictionary<KeyType, ObjectType> (NSSharedKeySetDictionary)
// + (id)sharedKeySetForKeys:(NSArray<KeyType <NSCopying>> *)keys __attribute__((availability(ios,introduced=6_0)));

/* @end */


// @interface NSMutableDictionary<KeyType, ObjectType> (NSSharedKeySetDictionary)







// + (NSMutableDictionary<KeyType, ObjectType> *)dictionaryWithSharedKeySet:(id)keyset __attribute__((availability(ios,introduced=6_0)));

/* @end */








// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif







#ifndef _REWRITER_typedef_NSSet
#define _REWRITER_typedef_NSSet
typedef struct objc_object NSSet;
typedef struct {} _objc_exc_NSSet;
#endif

struct NSSet_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly) NSUInteger count;
// - (nullable ObjectType)member:(ObjectType)object;
// - (NSEnumerator<ObjectType> *)objectEnumerator;
// - (instancetype)init __attribute__((objc_designated_initializer));
// - (instancetype)initWithObjects:(const ObjectType [])objects count:(NSUInteger)cnt __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSSet<ObjectType> (NSExtendedSet)

// @property (readonly, copy) NSArray<ObjectType> *allObjects;
// - (nullable ObjectType)anyObject;
// - (BOOL)containsObject:(ObjectType)anObject;
// @property (readonly, copy) NSString *description;
// - (NSString *)descriptionWithLocale:(nullable id)locale;
// - (BOOL)intersectsSet:(NSSet<ObjectType> *)otherSet;
// - (BOOL)isEqualToSet:(NSSet<ObjectType> *)otherSet;
// - (BOOL)isSubsetOfSet:(NSSet<ObjectType> *)otherSet;

// - (void)makeObjectsPerformSelector:(SEL)aSelector __attribute__((availability(swift, unavailable, message="Use enumerateObjectsUsingBlock: or a for loop instead")));
// - (void)makeObjectsPerformSelector:(SEL)aSelector withObject:(nullable id)argument __attribute__((availability(swift, unavailable, message="Use enumerateObjectsUsingBlock: or a for loop instead")));

// - (NSSet<ObjectType> *)setByAddingObject:(ObjectType)anObject __attribute__((availability(ios,introduced=2_0)));
// - (NSSet<ObjectType> *)setByAddingObjectsFromSet:(NSSet<ObjectType> *)other __attribute__((availability(ios,introduced=2_0)));
// - (NSSet<ObjectType> *)setByAddingObjectsFromArray:(NSArray<ObjectType> *)other __attribute__((availability(ios,introduced=2_0)));

// - (void)enumerateObjectsUsingBlock:(void (^)(ObjectType obj, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));
// - (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ObjectType obj, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));

// - (NSSet<ObjectType> *)objectsPassingTest:(BOOL (^)(ObjectType obj, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));
// - (NSSet<ObjectType> *)objectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ObjectType obj, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));

/* @end */


// @interface NSSet<ObjectType> (NSSetCreation)

// + (instancetype)set;
// + (instancetype)setWithObject:(ObjectType)object;
// + (instancetype)setWithObjects:(const ObjectType [])objects count:(NSUInteger)cnt;
// + (instancetype)setWithObjects:(ObjectType)firstObj, ... __attribute__((sentinel(0,1)));
// + (instancetype)setWithSet:(NSSet<ObjectType> *)set;
// + (instancetype)setWithArray:(NSArray<ObjectType> *)array;

// - (instancetype)initWithObjects:(ObjectType)firstObj, ... __attribute__((sentinel(0,1)));
// - (instancetype)initWithSet:(NSSet<ObjectType> *)set;
// - (instancetype)initWithSet:(NSSet<ObjectType> *)set copyItems:(BOOL)flag;
// - (instancetype)initWithArray:(NSArray<ObjectType> *)array;

/* @end */





#ifndef _REWRITER_typedef_NSMutableSet
#define _REWRITER_typedef_NSMutableSet
typedef struct objc_object NSMutableSet;
typedef struct {} _objc_exc_NSMutableSet;
#endif

struct NSMutableSet_IMPL {
	struct NSSet_IMPL NSSet_IVARS;
};


// - (void)addObject:(ObjectType)object;
// - (void)removeObject:(ObjectType)object;
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));
// - (instancetype)init __attribute__((objc_designated_initializer));
// - (instancetype)initWithCapacity:(NSUInteger)numItems __attribute__((objc_designated_initializer));

/* @end */


// @interface NSMutableSet<ObjectType> (NSExtendedMutableSet)

// - (void)addObjectsFromArray:(NSArray<ObjectType> *)array;
// - (void)intersectSet:(NSSet<ObjectType> *)otherSet;
// - (void)minusSet:(NSSet<ObjectType> *)otherSet;
// - (void)removeAllObjects;
// - (void)unionSet:(NSSet<ObjectType> *)otherSet;

// - (void)setSet:(NSSet<ObjectType> *)otherSet;

/* @end */


// @interface NSMutableSet<ObjectType> (NSMutableSetCreation)

// + (instancetype)setWithCapacity:(NSUInteger)numItems;

/* @end */





#ifndef _REWRITER_typedef_NSCountedSet
#define _REWRITER_typedef_NSCountedSet
typedef struct objc_object NSCountedSet;
typedef struct {} _objc_exc_NSCountedSet;
#endif

struct NSCountedSet_IMPL {
	struct NSMutableSet_IMPL NSMutableSet_IVARS;
	__strong id _table;
	void *_reserved;
};


// - (instancetype)initWithCapacity:(NSUInteger)numItems __attribute__((objc_designated_initializer));

// - (instancetype)initWithArray:(NSArray<ObjectType> *)array;
// - (instancetype)initWithSet:(NSSet<ObjectType> *)set;

// - (NSUInteger)countForObject:(ObjectType)object;

// - (NSEnumerator<ObjectType> *)objectEnumerator;
// - (void)addObject:(ObjectType)object;
// - (void)removeObject:(ObjectType)object;

/* @end */









// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSMutableDictionary
#define _REWRITER_typedef_NSMutableDictionary
typedef struct objc_object NSMutableDictionary;
typedef struct {} _objc_exc_NSMutableDictionary;
#endif

#ifndef _REWRITER_typedef_NSMutableSet
#define _REWRITER_typedef_NSMutableSet
typedef struct objc_object NSMutableSet;
typedef struct {} _objc_exc_NSMutableSet;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

#ifndef _REWRITER_typedef_NSUUID
#define _REWRITER_typedef_NSUUID
typedef struct objc_object NSUUID;
typedef struct {} _objc_exc_NSUUID;
#endif

#ifndef _REWRITER_typedef_NSXPCConnection
#define _REWRITER_typedef_NSXPCConnection
typedef struct objc_object NSXPCConnection;
typedef struct {} _objc_exc_NSXPCConnection;
#endif

#ifndef _REWRITER_typedef_NSLock
#define _REWRITER_typedef_NSLock
typedef struct objc_object NSLock;
typedef struct {} _objc_exc_NSLock;
#endif

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=7_0)))

#ifndef _REWRITER_typedef_NSProgress
#define _REWRITER_typedef_NSProgress
typedef struct objc_object NSProgress;
typedef struct {} _objc_exc_NSProgress;
#endif

struct NSProgress_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSProgress *__weak _parent;
	int64_t _reserved4;
	__strong id _values;
	void (*_resumingHandler)();
	void (*_cancellationHandler)();
	void (*_pausingHandler)();
	void (*_prioritizationHandler)();
	uint64_t _flags;
	__strong id _userInfoProxy;
	NSString *__strong _publisherID;
	NSXPCConnection *__strong _connection;
	NSInteger _unpublishingBlockageCount;
	NSInteger _disconnectingBlockageCount;
	NSInteger _remoteObserverCount;
	NSMutableDictionary *__strong _acknowledgementHandlersByBundleID;
	NSMutableDictionary *__strong _lastNotificationTimesByKey;
	NSMutableDictionary *__strong _userInfoLastNotificationTimesByKey;
	NSLock *__strong _lock;
	NSMutableSet *__strong _children;
};




// + (nullable NSProgress *)currentProgress;





// + (NSProgress *)progressWithTotalUnitCount:(int64_t)unitCount;



// + (NSProgress *)discreteProgressWithTotalUnitCount:(int64_t)unitCount __attribute__((availability(ios,introduced=9_0)));



// + (NSProgress *)progressWithTotalUnitCount:(int64_t)unitCount parent:(NSProgress *)parent pendingUnitCount:(int64_t)portionOfParentTotalUnitCount __attribute__((availability(ios,introduced=9_0)));



// - (instancetype)initWithParent:(nullable NSProgress *)parentProgressOrNil userInfo:(nullable NSDictionary *)userInfoOrNil __attribute__((objc_designated_initializer));





// - (void)becomeCurrentWithPendingUnitCount:(int64_t)unitCount;



// - (void)resignCurrent;



// - (void)addChild:(NSProgress *)child withPendingUnitCount:(int64_t)inUnitCount __attribute__((availability(ios,introduced=9_0)));







// @property int64_t totalUnitCount;
// @property int64_t completedUnitCount;
// @property (null_resettable, copy) NSString *localizedDescription;
// @property (null_resettable, copy) NSString *localizedAdditionalDescription;



// @property (getter=isCancellable) BOOL cancellable;
// @property (getter=isPausable) BOOL pausable;



// @property (readonly, getter=isCancelled) BOOL cancelled;
// @property (readonly, getter=isPaused) BOOL paused;



// @property (nullable, copy) void (^cancellationHandler)(void);



// @property (nullable, copy) void (^pausingHandler)(void);



// @property (nullable, copy) void (^resumingHandler)(void) __attribute__((availability(ios,introduced=9_0)));



// - (void)setUserInfoObject:(nullable id)objectOrNil forKey:(NSString *)key;





// @property (readonly, getter=isIndeterminate) BOOL indeterminate;



// @property (readonly) double fractionCompleted;



// - (void)cancel;



// - (void)pause;



// - (void)resume __attribute__((availability(ios,introduced=9_0)));



// @property (readonly, copy) NSDictionary *userInfo;



// @property (nullable, copy) NSString *kind;
// - (void)publish __attribute__((availability(ios,introduced=NA)));



// - (void)unpublish __attribute__((availability(ios,introduced=NA)));



typedef void (*NSProgressUnpublishingHandler)(void);
typedef _Nullable NSProgressUnpublishingHandler (*NSProgressPublishingHandler)(NSProgress *progress);



// + (id)addSubscriberForFileURL:(NSURL *)url withPublishingHandler:(NSProgressPublishingHandler)publishingHandler __attribute__((availability(ios,introduced=NA)));



// + (void)removeSubscriber:(id)subscriber __attribute__((availability(ios,introduced=NA)));





// @property (readonly, getter=isOld) BOOL old __attribute__((availability(ios,introduced=NA)));

/* @end */




// @protocol NSProgressReporting <NSObject>
// @property (readonly) NSProgress *progress;
/* @end */






extern "C" NSString *const NSProgressEstimatedTimeRemainingKey __attribute__((availability(ios,introduced=7_0)));



extern "C" NSString *const NSProgressThroughputKey __attribute__((availability(ios,introduced=7_0)));





extern "C" NSString *const NSProgressKindFile __attribute__((availability(ios,introduced=7_0)));



extern "C" NSString *const NSProgressFileOperationKindKey __attribute__((availability(ios,introduced=7_0)));



extern "C" NSString *const NSProgressFileOperationKindDownloading __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString *const NSProgressFileOperationKindDecompressingAfterDownloading __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString *const NSProgressFileOperationKindReceiving __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString *const NSProgressFileOperationKindCopying __attribute__((availability(ios,introduced=7_0)));



extern "C" NSString *const NSProgressFileURLKey __attribute__((availability(ios,introduced=7_0)));



extern "C" NSString *const NSProgressFileTotalCountKey __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString *const NSProgressFileCompletedCountKey __attribute__((availability(ios,introduced=7_0)));



extern "C" NSString *const NSProgressFileAnimationImageKey __attribute__((availability(ios,introduced=NA)));
extern "C" NSString *const NSProgressFileAnimationImageOriginalRectKey __attribute__((availability(ios,introduced=NA)));



extern "C" NSString *const NSProgressFileIconKey __attribute__((availability(ios,introduced=NA)));

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSUUID
#define _REWRITER_typedef_NSUUID
typedef struct objc_object NSUUID;
typedef struct {} _objc_exc_NSUUID;
#endif

#ifndef _REWRITER_typedef_NSLock
#define _REWRITER_typedef_NSLock
typedef struct objc_object NSLock;
typedef struct {} _objc_exc_NSLock;
#endif

#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
typedef struct objc_object NSNumber;
typedef struct {} _objc_exc_NSNumber;
#endif







#ifndef _REWRITER_typedef_NSBundle
#define _REWRITER_typedef_NSBundle
typedef struct objc_object NSBundle;
typedef struct {} _objc_exc_NSBundle;
#endif

struct NSBundle_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSUInteger _flags;
	__strong id _cfBundle;
	NSUInteger _reserved2;
	__unsafe_unretained Class _principalClass;
	__strong id _initialPath;
	__strong id _resolvedPath;
	__strong id _reserved3;
	__strong id _lock;
};



// + (NSBundle *)mainBundle;
// + (nullable instancetype)bundleWithPath:(NSString *)path;
// - (nullable instancetype)initWithPath:(NSString *)path __attribute__((objc_designated_initializer));

// + (nullable instancetype)bundleWithURL:(NSURL *)url __attribute__((availability(ios,introduced=4_0)));
// - (nullable instancetype)initWithURL:(NSURL *)url __attribute__((availability(ios,introduced=4_0)));

// + (NSBundle *)bundleForClass:(Class)aClass;
// + (nullable NSBundle *)bundleWithIdentifier:(NSString *)identifier;

// + (NSArray<NSBundle *> *)allBundles;
// + (NSArray<NSBundle *> *)allFrameworks;


// - (BOOL)load;
// @property (readonly, getter=isLoaded) BOOL loaded;
// - (BOOL)unload;

// - (BOOL)preflightAndReturnError:(NSError **)error __attribute__((availability(ios,introduced=2_0)));
// - (BOOL)loadAndReturnError:(NSError **)error __attribute__((availability(ios,introduced=2_0)));


// @property (readonly, copy) NSURL *bundleURL __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSURL *resourceURL __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSURL *executableURL __attribute__((availability(ios,introduced=4_0)));
// - (nullable NSURL *)URLForAuxiliaryExecutable:(NSString *)executableName __attribute__((availability(ios,introduced=4_0)));

// @property (nullable, readonly, copy) NSURL *privateFrameworksURL __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSURL *sharedFrameworksURL __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSURL *sharedSupportURL __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSURL *builtInPlugInsURL __attribute__((availability(ios,introduced=4_0)));

// @property (nullable, readonly, copy) NSURL *appStoreReceiptURL __attribute__((availability(ios,introduced=7_0)));

// @property (readonly, copy) NSString *bundlePath;
// @property (nullable, readonly, copy) NSString *resourcePath;
// @property (nullable, readonly, copy) NSString *executablePath;
// - (nullable NSString *)pathForAuxiliaryExecutable:(NSString *)executableName;

// @property (nullable, readonly, copy) NSString *privateFrameworksPath;
// @property (nullable, readonly, copy) NSString *sharedFrameworksPath;
// @property (nullable, readonly, copy) NSString *sharedSupportPath;
// @property (nullable, readonly, copy) NSString *builtInPlugInsPath;



// + (nullable NSURL *)URLForResource:(nullable NSString *)name withExtension:(nullable NSString *)ext subdirectory:(nullable NSString *)subpath inBundleWithURL:(NSURL *)bundleURL __attribute__((availability(ios,introduced=4_0)));
// + (nullable NSArray<NSURL *> *)URLsForResourcesWithExtension:(nullable NSString *)ext subdirectory:(nullable NSString *)subpath inBundleWithURL:(NSURL *)bundleURL __attribute__((availability(ios,introduced=4_0)));

// - (nullable NSURL *)URLForResource:(nullable NSString *)name withExtension:(nullable NSString *)ext __attribute__((availability(ios,introduced=4_0)));
// - (nullable NSURL *)URLForResource:(nullable NSString *)name withExtension:(nullable NSString *)ext subdirectory:(nullable NSString *)subpath __attribute__((availability(ios,introduced=4_0)));
// - (nullable NSURL *)URLForResource:(nullable NSString *)name withExtension:(nullable NSString *)ext subdirectory:(nullable NSString *)subpath localization:(nullable NSString *)localizationName __attribute__((availability(ios,introduced=4_0)));

// - (nullable NSArray<NSURL *> *)URLsForResourcesWithExtension:(nullable NSString *)ext subdirectory:(nullable NSString *)subpath __attribute__((availability(ios,introduced=4_0)));
// - (nullable NSArray<NSURL *> *)URLsForResourcesWithExtension:(nullable NSString *)ext subdirectory:(nullable NSString *)subpath localization:(nullable NSString *)localizationName __attribute__((availability(ios,introduced=4_0)));

// + (nullable NSString *)pathForResource:(nullable NSString *)name ofType:(nullable NSString *)ext inDirectory:(NSString *)bundlePath;
// + (NSArray<NSString *> *)pathsForResourcesOfType:(nullable NSString *)ext inDirectory:(NSString *)bundlePath;

// - (nullable NSString *)pathForResource:(nullable NSString *)name ofType:(nullable NSString *)ext;
// - (nullable NSString *)pathForResource:(nullable NSString *)name ofType:(nullable NSString *)ext inDirectory:(nullable NSString *)subpath;
// - (nullable NSString *)pathForResource:(nullable NSString *)name ofType:(nullable NSString *)ext inDirectory:(nullable NSString *)subpath forLocalization:(nullable NSString *)localizationName;

// - (NSArray<NSString *> *)pathsForResourcesOfType:(nullable NSString *)ext inDirectory:(nullable NSString *)subpath;
// - (NSArray<NSString *> *)pathsForResourcesOfType:(nullable NSString *)ext inDirectory:(nullable NSString *)subpath forLocalization:(nullable NSString *)localizationName;


// - (NSString *)localizedStringForKey:(NSString *)key value:(nullable NSString *)value table:(nullable NSString *)tableName __attribute__ ((format_arg(1)));


// @property (nullable, readonly, copy) NSString *bundleIdentifier;
// @property (nullable, readonly, copy) NSDictionary<NSString *, id> *infoDictionary;
// @property (nullable, readonly, copy) NSDictionary<NSString *, id> *localizedInfoDictionary;
// - (nullable id)objectForInfoDictionaryKey:(NSString *)key;
// - (nullable Class)classNamed:(NSString *)className;
// @property (nullable, readonly) Class principalClass;


// @property (readonly, copy) NSArray<NSString *> *preferredLocalizations;

// @property (readonly, copy) NSArray<NSString *> *localizations;
// @property (nullable, readonly, copy) NSString *developmentLocalization;

// + (NSArray<NSString *> *)preferredLocalizationsFromArray:(NSArray<NSString *> *)localizationsArray;
// + (NSArray<NSString *> *)preferredLocalizationsFromArray:(NSArray<NSString *> *)localizationsArray forPreferences:(nullable NSArray<NSString *> *)preferencesArray;


enum {
    NSBundleExecutableArchitectureI386 = 0x00000007,
    NSBundleExecutableArchitecturePPC = 0x00000012,
    NSBundleExecutableArchitectureX86_64 = 0x01000007,
    NSBundleExecutableArchitecturePPC64 = 0x01000012
};

// @property (nullable, readonly, copy) NSArray<NSNumber *> *executableArchitectures __attribute__((availability(ios,introduced=2_0)));

/* @end */

// @interface NSString (NSBundleExtensionMethods)



// - (NSString *)variantFittingPresentationWidth:(NSInteger)width __attribute__((availability(ios,introduced=9_0)));

/* @end */


extern "C" NSString * const NSBundleDidLoadNotification;
extern "C" NSString * const NSLoadedClasses;
__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=9_0)))

#ifndef _REWRITER_typedef_NSBundleResourceRequest
#define _REWRITER_typedef_NSBundleResourceRequest
typedef struct objc_object NSBundleResourceRequest;
typedef struct {} _objc_exc_NSBundleResourceRequest;
#endif

struct NSBundleResourceRequest_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// - (instancetype)init __attribute__((unavailable));




// - (instancetype)initWithTags:(NSSet<NSString *> *)tags;
// - (instancetype)initWithTags:(NSSet<NSString *> *)tags bundle:(NSBundle *)bundle __attribute__((objc_designated_initializer));






// @property double loadingPriority;




// @property (readonly, copy) NSSet<NSString *> *tags;




// @property (readonly, strong) NSBundle *bundle;
// - (void)beginAccessingResourcesWithCompletionHandler:(void (^)(NSError * _Nullable error))completionHandler;






// - (void)conditionallyBeginAccessingResourcesWithCompletionHandler:(void (^)(BOOL resourcesAvailable))completionHandler;




// - (void)endAccessingResources;




// @property (readonly, strong) NSProgress *progress;

/* @end */


// @interface NSBundle (NSBundleResourceRequestAdditions)







// - (void)setPreservationPriority:(double)priority forTags:(NSSet<NSString *> *)tags __attribute__((availability(ios,introduced=9_0)));
// - (double)preservationPriorityForTag:(NSString *)tag __attribute__((availability(ios,introduced=9_0)));

/* @end */

extern "C" NSString * const NSBundleResourceRequestLowDiskSpaceNotification __attribute__((availability(ios,introduced=9_0)));



extern "C" double const NSBundleResourceRequestLoadingPriorityUrgent __attribute__((availability(ios,introduced=9_0)));







enum {
    NS_UnknownByteOrder = CFByteOrderUnknown,
    NS_LittleEndian = CFByteOrderLittleEndian,
    NS_BigEndian = CFByteOrderBigEndian
};

static __inline__ __attribute__((always_inline)) long NSHostByteOrder(void) {
    return CFByteOrderGetCurrent();
}

static __inline__ __attribute__((always_inline)) unsigned short NSSwapShort(unsigned short inv) {
    return CFSwapInt16(inv);
}

static __inline__ __attribute__((always_inline)) unsigned int NSSwapInt(unsigned int inv) {
    return CFSwapInt32(inv);
}

static __inline__ __attribute__((always_inline)) unsigned long NSSwapLong(unsigned long inv) {

    return CFSwapInt64(inv);



}

static __inline__ __attribute__((always_inline)) unsigned long long NSSwapLongLong(unsigned long long inv) {
    return CFSwapInt64(inv);
}

static __inline__ __attribute__((always_inline)) unsigned short NSSwapBigShortToHost(unsigned short x) {
    return CFSwapInt16BigToHost(x);
}

static __inline__ __attribute__((always_inline)) unsigned int NSSwapBigIntToHost(unsigned int x) {
    return CFSwapInt32BigToHost(x);
}

static __inline__ __attribute__((always_inline)) unsigned long NSSwapBigLongToHost(unsigned long x) {

    return CFSwapInt64BigToHost(x);



}

static __inline__ __attribute__((always_inline)) unsigned long long NSSwapBigLongLongToHost(unsigned long long x) {
    return CFSwapInt64BigToHost(x);
}

static __inline__ __attribute__((always_inline)) unsigned short NSSwapHostShortToBig(unsigned short x) {
    return CFSwapInt16HostToBig(x);
}

static __inline__ __attribute__((always_inline)) unsigned int NSSwapHostIntToBig(unsigned int x) {
    return CFSwapInt32HostToBig(x);
}

static __inline__ __attribute__((always_inline)) unsigned long NSSwapHostLongToBig(unsigned long x) {

    return CFSwapInt64HostToBig(x);



}

static __inline__ __attribute__((always_inline)) unsigned long long NSSwapHostLongLongToBig(unsigned long long x) {
    return CFSwapInt64HostToBig(x);
}

static __inline__ __attribute__((always_inline)) unsigned short NSSwapLittleShortToHost(unsigned short x) {
    return CFSwapInt16LittleToHost(x);
}

static __inline__ __attribute__((always_inline)) unsigned int NSSwapLittleIntToHost(unsigned int x) {
    return CFSwapInt32LittleToHost(x);
}

static __inline__ __attribute__((always_inline)) unsigned long NSSwapLittleLongToHost(unsigned long x) {

    return CFSwapInt64LittleToHost(x);



}

static __inline__ __attribute__((always_inline)) unsigned long long NSSwapLittleLongLongToHost(unsigned long long x) {
    return CFSwapInt64LittleToHost(x);
}

static __inline__ __attribute__((always_inline)) unsigned short NSSwapHostShortToLittle(unsigned short x) {
    return CFSwapInt16HostToLittle(x);
}

static __inline__ __attribute__((always_inline)) unsigned int NSSwapHostIntToLittle(unsigned int x) {
    return CFSwapInt32HostToLittle(x);
}

static __inline__ __attribute__((always_inline)) unsigned long NSSwapHostLongToLittle(unsigned long x) {

    return CFSwapInt64HostToLittle(x);



}

static __inline__ __attribute__((always_inline)) unsigned long long NSSwapHostLongLongToLittle(unsigned long long x) {
    return CFSwapInt64HostToLittle(x);
}


typedef struct {unsigned int v;} NSSwappedFloat;
typedef struct {unsigned long long v;} NSSwappedDouble;

static __inline__ __attribute__((always_inline)) NSSwappedFloat NSConvertHostFloatToSwapped(float x) {
    union fconv {
 float number;
 NSSwappedFloat sf;
    };
    return ((union fconv *)&x)->sf;
}

static __inline__ __attribute__((always_inline)) float NSConvertSwappedFloatToHost(NSSwappedFloat x) {
    union fconv {
 float number;
 NSSwappedFloat sf;
    };
    return ((union fconv *)&x)->number;
}

static __inline__ __attribute__((always_inline)) NSSwappedDouble NSConvertHostDoubleToSwapped(double x) {
    union dconv {
 double number;
 NSSwappedDouble sd;
    };
    return ((union dconv *)&x)->sd;
}

static __inline__ __attribute__((always_inline)) double NSConvertSwappedDoubleToHost(NSSwappedDouble x) {
    union dconv {
 double number;
 NSSwappedDouble sd;
    };
    return ((union dconv *)&x)->number;
}

static __inline__ __attribute__((always_inline)) NSSwappedFloat NSSwapFloat(NSSwappedFloat x) {
    x.v = NSSwapInt(x.v);
    return x;
}

static __inline__ __attribute__((always_inline)) NSSwappedDouble NSSwapDouble(NSSwappedDouble x) {
    x.v = NSSwapLongLong(x.v);
    return x;
}
static __inline__ __attribute__((always_inline)) double NSSwapBigDoubleToHost(NSSwappedDouble x) {
    return NSConvertSwappedDoubleToHost(NSSwapDouble(x));
}

static __inline__ __attribute__((always_inline)) float NSSwapBigFloatToHost(NSSwappedFloat x) {
    return NSConvertSwappedFloatToHost(NSSwapFloat(x));
}

static __inline__ __attribute__((always_inline)) NSSwappedDouble NSSwapHostDoubleToBig(double x) {
    return NSSwapDouble(NSConvertHostDoubleToSwapped(x));
}

static __inline__ __attribute__((always_inline)) NSSwappedFloat NSSwapHostFloatToBig(float x) {
    return NSSwapFloat(NSConvertHostFloatToSwapped(x));
}

static __inline__ __attribute__((always_inline)) double NSSwapLittleDoubleToHost(NSSwappedDouble x) {
    return NSConvertSwappedDoubleToHost(x);
}

static __inline__ __attribute__((always_inline)) float NSSwapLittleFloatToHost(NSSwappedFloat x) {
    return NSConvertSwappedFloatToHost(x);
}

static __inline__ __attribute__((always_inline)) NSSwappedDouble NSSwapHostDoubleToLittle(double x) {
    return NSConvertHostDoubleToSwapped(x);
}

static __inline__ __attribute__((always_inline)) NSSwappedFloat NSSwapHostFloatToLittle(float x) {
    return NSConvertHostFloatToSwapped(x);
}












// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif




extern "C" NSString * const NSSystemClockDidChangeNotification __attribute__((availability(ios,introduced=4_0)));

typedef double NSTimeInterval;




#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

struct NSDate_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly) NSTimeInterval timeIntervalSinceReferenceDate;

// - (instancetype)init __attribute__((objc_designated_initializer));
// - (instancetype)initWithTimeIntervalSinceReferenceDate:(NSTimeInterval)ti __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSDate (NSExtendedDate)

// - (NSTimeInterval)timeIntervalSinceDate:(NSDate *)anotherDate;
// @property (readonly) NSTimeInterval timeIntervalSinceNow;
// @property (readonly) NSTimeInterval timeIntervalSince1970;

// - (id)addTimeInterval:(NSTimeInterval)seconds __attribute__((availability(ios,introduced=2_0,deprecated=4_0,message="" )));
// - (instancetype)dateByAddingTimeInterval:(NSTimeInterval)ti __attribute__((availability(ios,introduced=2_0)));

// - (NSDate *)earlierDate:(NSDate *)anotherDate;
// - (NSDate *)laterDate:(NSDate *)anotherDate;
// - (NSComparisonResult)compare:(NSDate *)other;
// - (BOOL)isEqualToDate:(NSDate *)otherDate;

// @property (readonly, copy) NSString *description;
// - (NSString *)descriptionWithLocale:(nullable id)locale;

// + (NSTimeInterval)timeIntervalSinceReferenceDate;

/* @end */


// @interface NSDate (NSDateCreation)

// + (instancetype)date;
// + (instancetype)dateWithTimeIntervalSinceNow:(NSTimeInterval)secs;
// + (instancetype)dateWithTimeIntervalSinceReferenceDate:(NSTimeInterval)ti;
// + (instancetype)dateWithTimeIntervalSince1970:(NSTimeInterval)secs;
// + (instancetype)dateWithTimeInterval:(NSTimeInterval)secsToBeAdded sinceDate:(NSDate *)date;

// + (NSDate *)distantFuture;
// + (NSDate *)distantPast;

// - (instancetype)initWithTimeIntervalSinceNow:(NSTimeInterval)secs;
// - (instancetype)initWithTimeIntervalSince1970:(NSTimeInterval)secs;
// - (instancetype)initWithTimeInterval:(NSTimeInterval)secsToBeAdded sinceDate:(NSDate *)date;

/* @end */



// @class NSDateComponents;
#ifndef _REWRITER_typedef_NSDateComponents
#define _REWRITER_typedef_NSDateComponents
typedef struct objc_object NSDateComponents;
typedef struct {} _objc_exc_NSDateComponents;
#endif

#ifndef _REWRITER_typedef_NSLocale
#define _REWRITER_typedef_NSLocale
typedef struct objc_object NSLocale;
typedef struct {} _objc_exc_NSLocale;
#endif

#ifndef _REWRITER_typedef_NSTimeZone
#define _REWRITER_typedef_NSTimeZone
typedef struct objc_object NSTimeZone;
typedef struct {} _objc_exc_NSTimeZone;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

extern "C" NSString * const NSCalendarIdentifierGregorian __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierBuddhist __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierChinese __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierCoptic __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierEthiopicAmeteMihret __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierEthiopicAmeteAlem __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierHebrew __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierISO8601 __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierIndian __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierIslamic __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierIslamicCivil __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierJapanese __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierPersian __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSCalendarIdentifierRepublicOfChina __attribute__((availability(ios,introduced=4_0)));

extern "C" NSString * const NSCalendarIdentifierIslamicTabular __attribute__((availability(ios,introduced=8_0)));

extern "C" NSString * const NSCalendarIdentifierIslamicUmmAlQura __attribute__((availability(ios,introduced=8_0)));


typedef NSUInteger NSCalendarUnit; enum {
        NSCalendarUnitEra = kCFCalendarUnitEra,
        NSCalendarUnitYear = kCFCalendarUnitYear,
        NSCalendarUnitMonth = kCFCalendarUnitMonth,
        NSCalendarUnitDay = kCFCalendarUnitDay,
        NSCalendarUnitHour = kCFCalendarUnitHour,
        NSCalendarUnitMinute = kCFCalendarUnitMinute,
        NSCalendarUnitSecond = kCFCalendarUnitSecond,
        NSCalendarUnitWeekday = kCFCalendarUnitWeekday,
        NSCalendarUnitWeekdayOrdinal = kCFCalendarUnitWeekdayOrdinal,
        NSCalendarUnitQuarter __attribute__((availability(ios,introduced=4_0))) = kCFCalendarUnitQuarter,
        NSCalendarUnitWeekOfMonth __attribute__((availability(ios,introduced=5_0))) = kCFCalendarUnitWeekOfMonth,
        NSCalendarUnitWeekOfYear __attribute__((availability(ios,introduced=5_0))) = kCFCalendarUnitWeekOfYear,
        NSCalendarUnitYearForWeekOfYear __attribute__((availability(ios,introduced=5_0))) = kCFCalendarUnitYearForWeekOfYear,
        NSCalendarUnitNanosecond __attribute__((availability(ios,introduced=5_0))) = (1 << 15),
        NSCalendarUnitCalendar __attribute__((availability(ios,introduced=4_0))) = (1 << 20),
        NSCalendarUnitTimeZone __attribute__((availability(ios,introduced=4_0))) = (1 << 21),

 NSEraCalendarUnit __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarUnitEra instead"))) = NSCalendarUnitEra,
 NSYearCalendarUnit __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarUnitYear instead"))) = NSCalendarUnitYear,
 NSMonthCalendarUnit __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarUnitMonth instead"))) = NSCalendarUnitMonth,
 NSDayCalendarUnit __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarUnitDay instead"))) = NSCalendarUnitDay,
 NSHourCalendarUnit __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarUnitHour instead"))) = NSCalendarUnitHour,
 NSMinuteCalendarUnit __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarUnitMinute instead"))) = NSCalendarUnitMinute,
 NSSecondCalendarUnit __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarUnitSecond instead"))) = NSCalendarUnitSecond,
 NSWeekCalendarUnit __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarUnitWeekOfMonth or NSCalendarUnitWeekOfYear, depending on which you mean"))) = kCFCalendarUnitWeek,
 NSWeekdayCalendarUnit __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarUnitWeekday instead"))) = NSCalendarUnitWeekday,
 NSWeekdayOrdinalCalendarUnit __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarUnitWeekdayOrdinal instead"))) = NSCalendarUnitWeekdayOrdinal,
 NSQuarterCalendarUnit __attribute__((availability(ios,introduced=4_0,deprecated=8_0,message="" "Use NSCalendarUnitQuarter instead"))) = NSCalendarUnitQuarter,
 NSWeekOfMonthCalendarUnit __attribute__((availability(ios,introduced=5_0,deprecated=8_0,message="" "Use NSCalendarUnitWeekOfMonth instead"))) = NSCalendarUnitWeekOfMonth,
 NSWeekOfYearCalendarUnit __attribute__((availability(ios,introduced=5_0,deprecated=8_0,message="" "Use NSCalendarUnitWeekOfYear instead"))) = NSCalendarUnitWeekOfYear,
 NSYearForWeekOfYearCalendarUnit __attribute__((availability(ios,introduced=5_0,deprecated=8_0,message="" "Use NSCalendarUnitYearForWeekOfYear instead"))) = NSCalendarUnitYearForWeekOfYear,
 NSCalendarCalendarUnit __attribute__((availability(ios,introduced=4_0,deprecated=8_0,message="" "Use NSCalendarUnitCalendar instead"))) = NSCalendarUnitCalendar,
 NSTimeZoneCalendarUnit __attribute__((availability(ios,introduced=4_0,deprecated=8_0,message="" "Use NSCalendarUnitTimeZone instead"))) = NSCalendarUnitTimeZone,
};

typedef NSUInteger NSCalendarOptions; enum {
 NSCalendarWrapComponents = (1UL << 0),

 NSCalendarMatchStrictly __attribute__((availability(ios,introduced=7_0))) = (1ULL << 1),
 NSCalendarSearchBackwards __attribute__((availability(ios,introduced=7_0))) = (1ULL << 2),

 NSCalendarMatchPreviousTimePreservingSmallerUnits __attribute__((availability(ios,introduced=7_0))) = (1ULL << 8),
 NSCalendarMatchNextTimePreservingSmallerUnits __attribute__((availability(ios,introduced=7_0))) = (1ULL << 9),
 NSCalendarMatchNextTime __attribute__((availability(ios,introduced=7_0))) = (1ULL << 10),

 NSCalendarMatchFirst __attribute__((availability(ios,introduced=7_0))) = (1ULL << 12),
 NSCalendarMatchLast __attribute__((availability(ios,introduced=7_0))) = (1ULL << 13)
};

enum {
 NSWrapCalendarComponents __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarWrapComponents instead"))) = NSCalendarWrapComponents,
};



#ifndef _REWRITER_typedef_NSCalendar
#define _REWRITER_typedef_NSCalendar
typedef struct objc_object NSCalendar;
typedef struct {} _objc_exc_NSCalendar;
#endif

struct NSCalendar_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};



// + (NSCalendar *)currentCalendar;
// + (NSCalendar *)autoupdatingCurrentCalendar __attribute__((availability(ios,introduced=2_0)));





// + (nullable NSCalendar *)calendarWithIdentifier:(NSString *)calendarIdentifierConstant __attribute__((availability(ios,introduced=8_0)));

// - (instancetype)init __attribute__((unavailable));

// - (nullable id)initWithCalendarIdentifier:(NSString *)ident __attribute__((objc_designated_initializer));

// @property (readonly, copy) NSString *calendarIdentifier;
// @property (nullable, copy) NSLocale *locale;
// @property (copy) NSTimeZone *timeZone;
// @property NSUInteger firstWeekday;
// @property NSUInteger minimumDaysInFirstWeek;



// @property (readonly, copy) NSArray<NSString *> *eraSymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *longEraSymbols __attribute__((availability(ios,introduced=5_0)));

// @property (readonly, copy) NSArray<NSString *> *monthSymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *shortMonthSymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *veryShortMonthSymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *standaloneMonthSymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *shortStandaloneMonthSymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *veryShortStandaloneMonthSymbols __attribute__((availability(ios,introduced=5_0)));

// @property (readonly, copy) NSArray<NSString *> *weekdaySymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *shortWeekdaySymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *veryShortWeekdaySymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *standaloneWeekdaySymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *shortStandaloneWeekdaySymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *veryShortStandaloneWeekdaySymbols __attribute__((availability(ios,introduced=5_0)));

// @property (readonly, copy) NSArray<NSString *> *quarterSymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *shortQuarterSymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *standaloneQuarterSymbols __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSArray<NSString *> *shortStandaloneQuarterSymbols __attribute__((availability(ios,introduced=5_0)));

// @property (readonly, copy) NSString *AMSymbol __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSString *PMSymbol __attribute__((availability(ios,introduced=5_0)));




// - (NSRange)minimumRangeOfUnit:(NSCalendarUnit)unit;
// - (NSRange)maximumRangeOfUnit:(NSCalendarUnit)unit;

// - (NSRange)rangeOfUnit:(NSCalendarUnit)smaller inUnit:(NSCalendarUnit)larger forDate:(NSDate *)date;
// - (NSUInteger)ordinalityOfUnit:(NSCalendarUnit)smaller inUnit:(NSCalendarUnit)larger forDate:(NSDate *)date;

// - (BOOL)rangeOfUnit:(NSCalendarUnit)unit startDate:(NSDate * _Nullable * _Nullable)datep interval:(nullable NSTimeInterval *)tip forDate:(NSDate *)date __attribute__((availability(ios,introduced=2_0)));

// - (nullable NSDate *)dateFromComponents:(NSDateComponents *)comps;
// - (NSDateComponents *)components:(NSCalendarUnit)unitFlags fromDate:(NSDate *)date;

// - (nullable NSDate *)dateByAddingComponents:(NSDateComponents *)comps toDate:(NSDate *)date options:(NSCalendarOptions)opts;

// - (NSDateComponents *)components:(NSCalendarUnit)unitFlags fromDate:(NSDate *)startingDate toDate:(NSDate *)resultDate options:(NSCalendarOptions)opts;






// - (void)getEra:(out nullable NSInteger *)eraValuePointer year:(out nullable NSInteger *)yearValuePointer month:(out nullable NSInteger *)monthValuePointer day:(out nullable NSInteger *)dayValuePointer fromDate:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));






// - (void)getEra:(out nullable NSInteger *)eraValuePointer yearForWeekOfYear:(out nullable NSInteger *)yearValuePointer weekOfYear:(out nullable NSInteger *)weekValuePointer weekday:(out nullable NSInteger *)weekdayValuePointer fromDate:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));






// - (void)getHour:(out nullable NSInteger *)hourValuePointer minute:(out nullable NSInteger *)minuteValuePointer second:(out nullable NSInteger *)secondValuePointer nanosecond:(out nullable NSInteger *)nanosecondValuePointer fromDate:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));





// - (NSInteger)component:(NSCalendarUnit)unit fromDate:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));






// - (nullable NSDate *)dateWithEra:(NSInteger)eraValue year:(NSInteger)yearValue month:(NSInteger)monthValue day:(NSInteger)dayValue hour:(NSInteger)hourValue minute:(NSInteger)minuteValue second:(NSInteger)secondValue nanosecond:(NSInteger)nanosecondValue __attribute__((availability(ios,introduced=8_0)));






// - (nullable NSDate *)dateWithEra:(NSInteger)eraValue yearForWeekOfYear:(NSInteger)yearValue weekOfYear:(NSInteger)weekValue weekday:(NSInteger)weekdayValue hour:(NSInteger)hourValue minute:(NSInteger)minuteValue second:(NSInteger)secondValue nanosecond:(NSInteger)nanosecondValue __attribute__((availability(ios,introduced=8_0)));







// - (NSDate *)startOfDayForDate:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));







// - (NSDateComponents *)componentsInTimeZone:(NSTimeZone *)timezone fromDate:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));





// - (NSComparisonResult)compareDate:(NSDate *)date1 toDate:(NSDate *)date2 toUnitGranularity:(NSCalendarUnit)unit __attribute__((availability(ios,introduced=8_0)));





// - (BOOL)isDate:(NSDate *)date1 equalToDate:(NSDate *)date2 toUnitGranularity:(NSCalendarUnit)unit __attribute__((availability(ios,introduced=8_0)));





// - (BOOL)isDate:(NSDate *)date1 inSameDayAsDate:(NSDate *)date2 __attribute__((availability(ios,introduced=8_0)));





// - (BOOL)isDateInToday:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));





// - (BOOL)isDateInYesterday:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));





// - (BOOL)isDateInTomorrow:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));





// - (BOOL)isDateInWeekend:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));







// - (BOOL)rangeOfWeekendStartDate:(out NSDate * _Nullable * _Nullable)datep interval:(out nullable NSTimeInterval *)tip containingDate:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));
// - (BOOL)nextWeekendStartDate:(out NSDate * _Nullable * _Nullable)datep interval:(out nullable NSTimeInterval *)tip options:(NSCalendarOptions)options afterDate:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));
// - (NSDateComponents *)components:(NSCalendarUnit)unitFlags fromDateComponents:(NSDateComponents *)startingDateComp toDateComponents:(NSDateComponents *)resultDateComp options:(NSCalendarOptions)options __attribute__((availability(ios,introduced=8_0)));






// - (nullable NSDate *)dateByAddingUnit:(NSCalendarUnit)unit value:(NSInteger)value toDate:(NSDate *)date options:(NSCalendarOptions)options __attribute__((availability(ios,introduced=8_0)));
// - (void)enumerateDatesStartingAfterDate:(NSDate *)start matchingComponents:(NSDateComponents *)comps options:(NSCalendarOptions)opts usingBlock:(void (^)(NSDate * _Nullable date, BOOL exactMatch, BOOL *stop))block __attribute__((availability(ios,introduced=8_0)));






// - (nullable NSDate *)nextDateAfterDate:(NSDate *)date matchingComponents:(NSDateComponents *)comps options:(NSCalendarOptions)options __attribute__((availability(ios,introduced=8_0)));







// - (nullable NSDate *)nextDateAfterDate:(NSDate *)date matchingUnit:(NSCalendarUnit)unit value:(NSInteger)value options:(NSCalendarOptions)options __attribute__((availability(ios,introduced=8_0)));







// - (nullable NSDate *)nextDateAfterDate:(NSDate *)date matchingHour:(NSInteger)hourValue minute:(NSInteger)minuteValue second:(NSInteger)secondValue options:(NSCalendarOptions)options __attribute__((availability(ios,introduced=8_0)));
// - (nullable NSDate *)dateBySettingUnit:(NSCalendarUnit)unit value:(NSInteger)v ofDate:(NSDate *)date options:(NSCalendarOptions)opts __attribute__((availability(ios,introduced=8_0)));







// - (nullable NSDate *)dateBySettingHour:(NSInteger)h minute:(NSInteger)m second:(NSInteger)s ofDate:(NSDate *)date options:(NSCalendarOptions)opts __attribute__((availability(ios,introduced=8_0)));






// - (BOOL)date:(NSDate *)date matchesComponents:(NSDateComponents *)components __attribute__((availability(ios,introduced=8_0)));

/* @end */

extern "C" NSString * const NSCalendarDayChangedNotification __attribute__((availability(ios,introduced=8_0)));
enum {
 NSDateComponentUndefined = 9223372036854775807L,

 NSUndefinedDateComponent __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSDateComponentUndefined instead"))) = NSDateComponentUndefined
};



#ifndef _REWRITER_typedef_NSDateComponents
#define _REWRITER_typedef_NSDateComponents
typedef struct objc_object NSDateComponents;
typedef struct {} _objc_exc_NSDateComponents;
#endif

struct NSDateComponents_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (nullable, copy) NSCalendar *calendar __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, copy) NSTimeZone *timeZone __attribute__((availability(ios,introduced=4_0)));
// @property NSInteger era;
// @property NSInteger year;
// @property NSInteger month;
// @property NSInteger day;
// @property NSInteger hour;
// @property NSInteger minute;
// @property NSInteger second;
// @property NSInteger nanosecond __attribute__((availability(ios,introduced=5_0)));
// @property NSInteger weekday;
// @property NSInteger weekdayOrdinal;
// @property NSInteger quarter __attribute__((availability(ios,introduced=4_0)));
// @property NSInteger weekOfMonth __attribute__((availability(ios,introduced=5_0)));
// @property NSInteger weekOfYear __attribute__((availability(ios,introduced=5_0)));
// @property NSInteger yearForWeekOfYear __attribute__((availability(ios,introduced=5_0)));
// @property (getter=isLeapMonth) BOOL leapMonth __attribute__((availability(ios,introduced=6_0)));
// @property (nullable, readonly, copy) NSDate *date __attribute__((availability(ios,introduced=4_0)));

// - (NSInteger)week __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "Use weekOfMonth or weekOfYear, depending on which you mean")));
// - (void)setWeek:(NSInteger)v __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" "Use setWeekOfMonth: or setWeekOfYear:, depending on which you mean")));





// - (void)setValue:(NSInteger)value forComponent:(NSCalendarUnit)unit __attribute__((availability(ios,introduced=8_0)));






// - (NSInteger)valueForComponent:(NSCalendarUnit)unit __attribute__((availability(ios,introduced=8_0)));
// @property (getter=isValidDate, readonly) BOOL validDate __attribute__((availability(ios,introduced=8_0)));
// - (BOOL)isValidDateInCalendar:(NSCalendar *)calendar __attribute__((availability(ios,introduced=8_0)));


/* @end */

// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif




enum {
    NSOpenStepUnicodeReservedBase = 0xF400
};


#ifndef _REWRITER_typedef_NSCharacterSet
#define _REWRITER_typedef_NSCharacterSet
typedef struct objc_object NSCharacterSet;
typedef struct {} _objc_exc_NSCharacterSet;
#endif

struct NSCharacterSet_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// + (NSCharacterSet *)controlCharacterSet;
// + (NSCharacterSet *)whitespaceCharacterSet;
// + (NSCharacterSet *)whitespaceAndNewlineCharacterSet;
// + (NSCharacterSet *)decimalDigitCharacterSet;
// + (NSCharacterSet *)letterCharacterSet;
// + (NSCharacterSet *)lowercaseLetterCharacterSet;
// + (NSCharacterSet *)uppercaseLetterCharacterSet;
// + (NSCharacterSet *)nonBaseCharacterSet;
// + (NSCharacterSet *)alphanumericCharacterSet;
// + (NSCharacterSet *)decomposableCharacterSet;
// + (NSCharacterSet *)illegalCharacterSet;
// + (NSCharacterSet *)punctuationCharacterSet;
// + (NSCharacterSet *)capitalizedLetterCharacterSet;
// + (NSCharacterSet *)symbolCharacterSet;
// + (NSCharacterSet *)newlineCharacterSet __attribute__((availability(ios,introduced=2_0)));

// + (NSCharacterSet *)characterSetWithRange:(NSRange)aRange;
// + (NSCharacterSet *)characterSetWithCharactersInString:(NSString *)aString;
// + (NSCharacterSet *)characterSetWithBitmapRepresentation:(NSData *)data;
// + (nullable NSCharacterSet *)characterSetWithContentsOfFile:(NSString *)fName;

// - (instancetype) initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

// - (BOOL)characterIsMember:(unichar)aCharacter;
// @property (readonly, copy) NSData *bitmapRepresentation;
// @property (readonly, copy) NSCharacterSet *invertedSet;


// - (BOOL)longCharacterIsMember:(UTF32Char)theLongChar;

// - (BOOL)isSupersetOfSet:(NSCharacterSet *)theOtherSet;
// - (BOOL)hasMemberInPlane:(uint8_t)thePlane;
/* @end */



#ifndef _REWRITER_typedef_NSMutableCharacterSet
#define _REWRITER_typedef_NSMutableCharacterSet
typedef struct objc_object NSMutableCharacterSet;
typedef struct {} _objc_exc_NSMutableCharacterSet;
#endif

struct NSMutableCharacterSet_IMPL {
	struct NSCharacterSet_IMPL NSCharacterSet_IVARS;
};


// - (void)addCharactersInRange:(NSRange)aRange;
// - (void)removeCharactersInRange:(NSRange)aRange;
// - (void)addCharactersInString:(NSString *)aString;
// - (void)removeCharactersInString:(NSString *)aString;
// - (void)formUnionWithCharacterSet:(NSCharacterSet *)otherSet;
// - (void)formIntersectionWithCharacterSet:(NSCharacterSet *)otherSet;
// - (void)invert;

// + (NSMutableCharacterSet *)controlCharacterSet;
// + (NSMutableCharacterSet *)whitespaceCharacterSet;
// + (NSMutableCharacterSet *)whitespaceAndNewlineCharacterSet;
// + (NSMutableCharacterSet *)decimalDigitCharacterSet;
// + (NSMutableCharacterSet *)letterCharacterSet;
// + (NSMutableCharacterSet *)lowercaseLetterCharacterSet;
// + (NSMutableCharacterSet *)uppercaseLetterCharacterSet;
// + (NSMutableCharacterSet *)nonBaseCharacterSet;
// + (NSMutableCharacterSet *)alphanumericCharacterSet;
// + (NSMutableCharacterSet *)decomposableCharacterSet;
// + (NSMutableCharacterSet *)illegalCharacterSet;
// + (NSMutableCharacterSet *)punctuationCharacterSet;
// + (NSMutableCharacterSet *)capitalizedLetterCharacterSet;
// + (NSMutableCharacterSet *)symbolCharacterSet;
// + (NSMutableCharacterSet *)newlineCharacterSet __attribute__((availability(ios,introduced=2_0)));

// + (NSMutableCharacterSet *)characterSetWithRange:(NSRange)aRange;
// + (NSMutableCharacterSet *)characterSetWithCharactersInString:(NSString *)aString;
// + (NSMutableCharacterSet *)characterSetWithBitmapRepresentation:(NSData *)data;
// + (nullable NSMutableCharacterSet *)characterSetWithContentsOfFile:(NSString *)fName;

/* @end */







// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSSet
#define _REWRITER_typedef_NSSet
typedef struct objc_object NSSet;
typedef struct {} _objc_exc_NSSet;
#endif





#ifndef _REWRITER_typedef_NSCoder
#define _REWRITER_typedef_NSCoder
typedef struct objc_object NSCoder;
typedef struct {} _objc_exc_NSCoder;
#endif

struct NSCoder_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// - (void)encodeValueOfObjCType:(const char *)type at:(const void *)addr;
// - (void)encodeDataObject:(NSData *)data;
// - (void)decodeValueOfObjCType:(const char *)type at:(void *)data;
// - (nullable NSData *)decodeDataObject;
// - (NSInteger)versionForClassName:(NSString *)className;

/* @end */


// @interface NSCoder (NSExtendedCoder)

// - (void)encodeObject:(nullable id)object;
// - (void)encodeRootObject:(id)rootObject;
// - (void)encodeBycopyObject:(nullable id)anObject;
// - (void)encodeByrefObject:(nullable id)anObject;
// - (void)encodeConditionalObject:(nullable id)object;
// - (void)encodeValuesOfObjCTypes:(const char *)types, ...;
// - (void)encodeArrayOfObjCType:(const char *)type count:(NSUInteger)count at:(const void *)array;
// - (void)encodeBytes:(nullable const void *)byteaddr length:(NSUInteger)length;

// - (nullable id)decodeObject;
// - (nullable id)decodeTopLevelObjectAndReturnError:(NSError **)error __attribute__((availability(ios,introduced=9_0))) __attribute__((availability(swift, unavailable, message="Use 'decodeTopLevelObject() throws' instead")));
// - (void)decodeValuesOfObjCTypes:(const char *)types, ...;
// - (void)decodeArrayOfObjCType:(const char *)itemType count:(NSUInteger)count at:(void *)array;
// - (nullable void *)decodeBytesWithReturnedLength:(NSUInteger *)lengthp __attribute__((objc_returns_inner_pointer));






// - (void)setObjectZone:(nullable NSZone *)zone __attribute__((unavailable("not available in automatic reference counting mode")));
// - (nullable NSZone *)objectZone __attribute__((unavailable("not available in automatic reference counting mode")));

// @property (readonly) unsigned int systemVersion;

// @property (readonly) BOOL allowsKeyedCoding;

// - (void)encodeObject:(nullable id)objv forKey:(NSString *)key;
// - (void)encodeConditionalObject:(nullable id)objv forKey:(NSString *)key;
// - (void)encodeBool:(BOOL)boolv forKey:(NSString *)key;
// - (void)encodeInt:(int)intv forKey:(NSString *)key;
// - (void)encodeInt32:(int32_t)intv forKey:(NSString *)key;
// - (void)encodeInt64:(int64_t)intv forKey:(NSString *)key;
// - (void)encodeFloat:(float)realv forKey:(NSString *)key;
// - (void)encodeDouble:(double)realv forKey:(NSString *)key;
// - (void)encodeBytes:(nullable const uint8_t *)bytesp length:(NSUInteger)lenv forKey:(NSString *)key;

// - (BOOL)containsValueForKey:(NSString *)key;
// - (nullable id)decodeObjectForKey:(NSString *)key;
// - (nullable id)decodeTopLevelObjectForKey:(NSString *)key error:(NSError **)error __attribute__((availability(ios,introduced=9_0))) __attribute__((availability(swift, unavailable, message="Use 'decodeObjectForKey(_:) throws' instead")));
// - (BOOL)decodeBoolForKey:(NSString *)key;
// - (int)decodeIntForKey:(NSString *)key;
// - (int32_t)decodeInt32ForKey:(NSString *)key;
// - (int64_t)decodeInt64ForKey:(NSString *)key;
// - (float)decodeFloatForKey:(NSString *)key;
// - (double)decodeDoubleForKey:(NSString *)key;
// - (nullable const uint8_t *)decodeBytesForKey:(NSString *)key returnedLength:(nullable NSUInteger *)lengthp __attribute__((objc_returns_inner_pointer));

// - (void)encodeInteger:(NSInteger)intv forKey:(NSString *)key __attribute__((availability(ios,introduced=2_0)));
// - (NSInteger)decodeIntegerForKey:(NSString *)key __attribute__((availability(ios,introduced=2_0)));


// @property (readonly) BOOL requiresSecureCoding __attribute__((availability(ios,introduced=6_0)));


// - (nullable id)decodeObjectOfClass:(Class)aClass forKey:(NSString *)key __attribute__((availability(ios,introduced=6_0)));
// - (nullable id)decodeTopLevelObjectOfClass:(Class)aClass forKey:(NSString *)key error:(NSError **)error __attribute__((availability(ios,introduced=9_0))) __attribute__((availability(swift, unavailable, message="Use 'decodeTopLevelObjectOfClass(_:,forKey:) throws instead")));


// - (nullable id)decodeObjectOfClasses:(nullable NSSet<Class> *)classes forKey:(NSString *)key __attribute__((availability(ios,introduced=6_0))) __attribute__((swift_private));
// - (nullable id)decodeTopLevelObjectOfClasses:(nullable NSSet<Class> *)classes forKey:(NSString *)key error:(NSError **)error __attribute__((availability(ios,introduced=9_0))) __attribute__((availability(swift, unavailable, message="Use 'decodeObjectOfClasses(_:,forKey:) throws' instead")));


// - (nullable id)decodePropertyListForKey:(NSString *)key __attribute__((availability(ios,introduced=6_0)));


// @property (nullable, readonly, copy) NSSet<Class> *allowedClasses __attribute__((availability(ios,introduced=6_0)));


// - (void)failWithError:(NSError *)error __attribute__((availability(ios,introduced=9_0)));

/* @end */








// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif






typedef NSUInteger NSDataReadingOptions; enum {
    NSDataReadingMappedIfSafe = 1UL << 0,
    NSDataReadingUncached = 1UL << 1,
    NSDataReadingMappedAlways __attribute__((availability(ios,introduced=5_0))) = 1UL << 3,


    NSDataReadingMapped = NSDataReadingMappedIfSafe,
    NSMappedRead = NSDataReadingMapped,
    NSUncachedRead = NSDataReadingUncached
};

typedef NSUInteger NSDataWritingOptions; enum {
    NSDataWritingAtomic = 1UL << 0,
    NSDataWritingWithoutOverwriting __attribute__((availability(ios,introduced=6_0))) = 1UL << 1,

    NSDataWritingFileProtectionNone __attribute__((availability(ios,introduced=4_0))) = 0x10000000,
    NSDataWritingFileProtectionComplete __attribute__((availability(ios,introduced=4_0))) = 0x20000000,
    NSDataWritingFileProtectionCompleteUnlessOpen __attribute__((availability(ios,introduced=5_0))) = 0x30000000,
    NSDataWritingFileProtectionCompleteUntilFirstUserAuthentication __attribute__((availability(ios,introduced=5_0))) = 0x40000000,
    NSDataWritingFileProtectionMask __attribute__((availability(ios,introduced=4_0))) = 0xf0000000,


    NSAtomicWrite = NSDataWritingAtomic
};




typedef NSUInteger NSDataSearchOptions; enum {
    NSDataSearchBackwards = 1UL << 0,
    NSDataSearchAnchored = 1UL << 1
} __attribute__((availability(ios,introduced=4_0)));




typedef NSUInteger NSDataBase64EncodingOptions; enum {

    NSDataBase64Encoding64CharacterLineLength = 1UL << 0,
    NSDataBase64Encoding76CharacterLineLength = 1UL << 1,


    NSDataBase64EncodingEndLineWithCarriageReturn = 1UL << 4,
    NSDataBase64EncodingEndLineWithLineFeed = 1UL << 5,

} __attribute__((availability(ios,introduced=7_0)));


typedef NSUInteger NSDataBase64DecodingOptions; enum {

    NSDataBase64DecodingIgnoreUnknownCharacters = 1UL << 0
} __attribute__((availability(ios,introduced=7_0)));





#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

struct NSData_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly) NSUInteger length;





// @property (readonly) const void *bytes __attribute__((objc_returns_inner_pointer));

/* @end */


// @interface NSData (NSExtendedData)

// @property (readonly, copy) NSString *description;
// - (void)getBytes:(void *)buffer length:(NSUInteger)length;
// - (void)getBytes:(void *)buffer range:(NSRange)range;
// - (BOOL)isEqualToData:(NSData *)other;
// - (NSData *)subdataWithRange:(NSRange)range;
// - (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile;
// - (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically;
// - (BOOL)writeToFile:(NSString *)path options:(NSDataWritingOptions)writeOptionsMask error:(NSError **)errorPtr;
// - (BOOL)writeToURL:(NSURL *)url options:(NSDataWritingOptions)writeOptionsMask error:(NSError **)errorPtr;
// - (NSRange)rangeOfData:(NSData *)dataToFind options:(NSDataSearchOptions)mask range:(NSRange)searchRange __attribute__((availability(ios,introduced=4_0)));




// - (void) enumerateByteRangesUsingBlock:(void (^)(const void *bytes, NSRange byteRange, BOOL *stop))block __attribute__((availability(ios,introduced=7_0)));

/* @end */


// @interface NSData (NSDataCreation)

// + (instancetype)data;
// + (instancetype)dataWithBytes:(nullable const void *)bytes length:(NSUInteger)length;
// + (instancetype)dataWithBytesNoCopy:(void *)bytes length:(NSUInteger)length;
// + (instancetype)dataWithBytesNoCopy:(void *)bytes length:(NSUInteger)length freeWhenDone:(BOOL)b;
// + (nullable instancetype)dataWithContentsOfFile:(NSString *)path options:(NSDataReadingOptions)readOptionsMask error:(NSError **)errorPtr;
// + (nullable instancetype)dataWithContentsOfURL:(NSURL *)url options:(NSDataReadingOptions)readOptionsMask error:(NSError **)errorPtr;
// + (nullable instancetype)dataWithContentsOfFile:(NSString *)path;
// + (nullable instancetype)dataWithContentsOfURL:(NSURL *)url;
// - (instancetype)initWithBytes:(nullable const void *)bytes length:(NSUInteger)length;
// - (instancetype)initWithBytesNoCopy:(void *)bytes length:(NSUInteger)length;
// - (instancetype)initWithBytesNoCopy:(void *)bytes length:(NSUInteger)length freeWhenDone:(BOOL)b;
// - (instancetype)initWithBytesNoCopy:(void *)bytes length:(NSUInteger)length deallocator:(nullable void (^)(void *bytes, NSUInteger length))deallocator __attribute__((availability(ios,introduced=7_0)));
// - (nullable instancetype)initWithContentsOfFile:(NSString *)path options:(NSDataReadingOptions)readOptionsMask error:(NSError **)errorPtr;
// - (nullable instancetype)initWithContentsOfURL:(NSURL *)url options:(NSDataReadingOptions)readOptionsMask error:(NSError **)errorPtr;
// - (nullable instancetype)initWithContentsOfFile:(NSString *)path;
// - (nullable instancetype)initWithContentsOfURL:(NSURL *)url;
// - (instancetype)initWithData:(NSData *)data;
// + (instancetype)dataWithData:(NSData *)data;

/* @end */


// @interface NSData (NSDataBase64Encoding)



// - (nullable instancetype)initWithBase64EncodedString:(NSString *)base64String options:(NSDataBase64DecodingOptions)options __attribute__((availability(ios,introduced=7_0)));



// - (NSString *)base64EncodedStringWithOptions:(NSDataBase64EncodingOptions)options __attribute__((availability(ios,introduced=7_0)));



// - (nullable instancetype)initWithBase64EncodedData:(NSData *)base64Data options:(NSDataBase64DecodingOptions)options __attribute__((availability(ios,introduced=7_0)));



// - (NSData *)base64EncodedDataWithOptions:(NSDataBase64EncodingOptions)options __attribute__((availability(ios,introduced=7_0)));

/* @end */



// @interface NSData (NSDeprecated)

// - (void)getBytes:(void *)buffer __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "This method is unsafe because it could potentially cause buffer overruns. Use -getBytes:length: instead.")));
// + (nullable id)dataWithContentsOfMappedFile:(NSString *)path __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use +dataWithContentsOfURL:options:error: and NSDataReadingMappedIfSafe or NSDataReadingMappedAlways instead.")));
// - (nullable id)initWithContentsOfMappedFile:(NSString *)path __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use -initWithContentsOfURL:options:error: and NSDataReadingMappedIfSafe or NSDataReadingMappedAlways instead.")));



// - (nullable id)initWithBase64Encoding:(NSString *)base64String __attribute__((availability(ios,introduced=4_0,deprecated=7_0,message="" )));
// - (NSString *)base64Encoding __attribute__((availability(ios,introduced=4_0,deprecated=7_0,message="" )));

/* @end */





#ifndef _REWRITER_typedef_NSMutableData
#define _REWRITER_typedef_NSMutableData
typedef struct objc_object NSMutableData;
typedef struct {} _objc_exc_NSMutableData;
#endif

struct NSMutableData_IMPL {
	struct NSData_IMPL NSData_IVARS;
};


// @property (readonly) void *mutableBytes __attribute__((objc_returns_inner_pointer));
// @property NSUInteger length;

/* @end */


// @interface NSMutableData (NSExtendedMutableData)

// - (void)appendBytes:(const void *)bytes length:(NSUInteger)length;
// - (void)appendData:(NSData *)other;
// - (void)increaseLengthBy:(NSUInteger)extraLength;
// - (void)replaceBytesInRange:(NSRange)range withBytes:(const void *)bytes;
// - (void)resetBytesInRange:(NSRange)range;
// - (void)setData:(NSData *)data;
// - (void)replaceBytesInRange:(NSRange)range withBytes:(nullable const void *)replacementBytes length:(NSUInteger)replacementLength;

/* @end */


// @interface NSMutableData (NSMutableDataCreation)

// + (nullable instancetype)dataWithCapacity:(NSUInteger)aNumItems;
// + (nullable instancetype)dataWithLength:(NSUInteger)length;
// - (nullable instancetype)initWithCapacity:(NSUInteger)capacity;
// - (nullable instancetype)initWithLength:(NSUInteger)length;

/* @end */




__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=4_0)))

#ifndef _REWRITER_typedef_NSPurgeableData
#define _REWRITER_typedef_NSPurgeableData
typedef struct objc_object NSPurgeableData;
typedef struct {} _objc_exc_NSPurgeableData;
#endif

struct NSPurgeableData_IMPL {
	struct NSMutableData_IMPL NSMutableData_IVARS;
	NSUInteger _length;
	int32_t _accessCount;
	uint8_t _private[32];
	void *_reserved;
};


/* @end */













// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @class NSAttributedString;
#ifndef _REWRITER_typedef_NSAttributedString
#define _REWRITER_typedef_NSAttributedString
typedef struct objc_object NSAttributedString;
typedef struct {} _objc_exc_NSAttributedString;
#endif

// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif




typedef NSInteger NSFormattingContext; enum {


    NSFormattingContextUnknown = 0,


    NSFormattingContextDynamic = 1,


    NSFormattingContextStandalone = 2,


    NSFormattingContextListItem = 3,


    NSFormattingContextBeginningOfSentence = 4,


    NSFormattingContextMiddleOfSentence = 5,

} __attribute__((availability(ios,introduced=8_0)));






typedef NSInteger NSFormattingUnitStyle; enum {
    NSFormattingUnitStyleShort = 1,
    NSFormattingUnitStyleMedium,
    NSFormattingUnitStyleLong,
} __attribute__((availability(ios,introduced=8_0)));


#ifndef _REWRITER_typedef_NSFormatter
#define _REWRITER_typedef_NSFormatter
typedef struct objc_object NSFormatter;
typedef struct {} _objc_exc_NSFormatter;
#endif

struct NSFormatter_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// - (nullable NSString *)stringForObjectValue:(id)obj;

// - (nullable NSAttributedString *)attributedStringForObjectValue:(id)obj withDefaultAttributes:(nullable NSDictionary<NSString *, id> *)attrs;

// - (nullable NSString *)editingStringForObjectValue:(id)obj;

// - (BOOL)getObjectValue:(out id _Nullable * _Nullable)obj forString:(NSString *)string errorDescription:(out NSString * _Nullable * _Nullable)error;

// - (BOOL)isPartialStringValid:(NSString *)partialString newEditingString:(NSString * _Nullable * _Nullable)newString errorDescription:(NSString * _Nullable * _Nullable)error;


// - (BOOL)isPartialStringValid:(NSString * _Nonnull * _Nonnull)partialStringPtr proposedSelectedRange:(nullable NSRangePointer)proposedSelRangePtr originalString:(NSString *)origString originalSelectedRange:(NSRange)origSelRange errorDescription:(NSString * _Nullable * _Nullable)error;

/* @end */



// @class NSLocale;
#ifndef _REWRITER_typedef_NSLocale
#define _REWRITER_typedef_NSLocale
typedef struct objc_object NSLocale;
typedef struct {} _objc_exc_NSLocale;
#endif

#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

#ifndef _REWRITER_typedef_NSCalendar
#define _REWRITER_typedef_NSCalendar
typedef struct objc_object NSCalendar;
typedef struct {} _objc_exc_NSCalendar;
#endif

#ifndef _REWRITER_typedef_NSTimeZone
#define _REWRITER_typedef_NSTimeZone
typedef struct objc_object NSTimeZone;
typedef struct {} _objc_exc_NSTimeZone;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSMutableDictionary
#define _REWRITER_typedef_NSMutableDictionary
typedef struct objc_object NSMutableDictionary;
typedef struct {} _objc_exc_NSMutableDictionary;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif


#ifndef _REWRITER_typedef_NSDateFormatter
#define _REWRITER_typedef_NSDateFormatter
typedef struct objc_object NSDateFormatter;
typedef struct {} _objc_exc_NSDateFormatter;
#endif

struct NSDateFormatter_IMPL {
	struct NSFormatter_IMPL NSFormatter_IVARS;
	NSMutableDictionary *__strong _attributes;
	CFDateFormatterRef _formatter;
	NSUInteger _counter;
};


// @property NSFormattingContext formattingContext __attribute__((availability(ios,introduced=8_0)));





// - (BOOL)getObjectValue:(out id _Nullable * _Nullable)obj forString:(NSString *)string range:(inout nullable NSRange *)rangep error:(out NSError **)error;




// - (NSString *)stringFromDate:(NSDate *)date;
// - (nullable NSDate *)dateFromString:(NSString *)string;

typedef NSUInteger NSDateFormatterStyle; enum {
    NSDateFormatterNoStyle = kCFDateFormatterNoStyle,
    NSDateFormatterShortStyle = kCFDateFormatterShortStyle,
    NSDateFormatterMediumStyle = kCFDateFormatterMediumStyle,
    NSDateFormatterLongStyle = kCFDateFormatterLongStyle,
    NSDateFormatterFullStyle = kCFDateFormatterFullStyle
};

typedef NSUInteger NSDateFormatterBehavior; enum {
    NSDateFormatterBehaviorDefault = 0,



    NSDateFormatterBehavior10_4 = 1040,
};


// + (NSString *)localizedStringFromDate:(NSDate *)date dateStyle:(NSDateFormatterStyle)dstyle timeStyle:(NSDateFormatterStyle)tstyle __attribute__((availability(ios,introduced=4_0)));

// + (nullable NSString *)dateFormatFromTemplate:(NSString *)tmplate options:(NSUInteger)opts locale:(nullable NSLocale *)locale __attribute__((availability(ios,introduced=4_0)));




// + (NSDateFormatterBehavior)defaultFormatterBehavior;
// + (void)setDefaultFormatterBehavior:(NSDateFormatterBehavior)behavior;
// - (void) setLocalizedDateFormatFromTemplate:(NSString *)dateFormatTemplate __attribute__((availability(ios,introduced=8_0)));

// @property (null_resettable, copy) NSString *dateFormat;
// @property NSDateFormatterStyle dateStyle;
// @property NSDateFormatterStyle timeStyle;
// @property (null_resettable, copy) NSLocale *locale;
// @property BOOL generatesCalendarDates;
// @property NSDateFormatterBehavior formatterBehavior;
// @property (null_resettable, copy) NSTimeZone *timeZone;
// @property (null_resettable, copy) NSCalendar *calendar;
// @property (getter=isLenient) BOOL lenient;
// @property (nullable, copy) NSDate *twoDigitStartDate;
// @property (nullable, copy) NSDate *defaultDate;
// @property (null_resettable, copy) NSArray<NSString *> *eraSymbols;
// @property (null_resettable, copy) NSArray<NSString *> *monthSymbols;
// @property (null_resettable, copy) NSArray<NSString *> *shortMonthSymbols;
// @property (null_resettable, copy) NSArray<NSString *> *weekdaySymbols;
// @property (null_resettable, copy) NSArray<NSString *> *shortWeekdaySymbols;
// @property (null_resettable, copy) NSString *AMSymbol;
// @property (null_resettable, copy) NSString *PMSymbol;
// @property (null_resettable, copy) NSArray<NSString *> *longEraSymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *veryShortMonthSymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *standaloneMonthSymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *shortStandaloneMonthSymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *veryShortStandaloneMonthSymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *veryShortWeekdaySymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *standaloneWeekdaySymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *shortStandaloneWeekdaySymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *veryShortStandaloneWeekdaySymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *quarterSymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *shortQuarterSymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *standaloneQuarterSymbols __attribute__((availability(ios,introduced=2_0)));
// @property (null_resettable, copy) NSArray<NSString *> *shortStandaloneQuarterSymbols __attribute__((availability(ios,introduced=2_0)));
// @property (nullable, copy) NSDate *gregorianStartDate __attribute__((availability(ios,introduced=2_0)));
// @property BOOL doesRelativeDateFormatting __attribute__((availability(ios,introduced=4_0)));

/* @end */







// @class NSLocale;
#ifndef _REWRITER_typedef_NSLocale
#define _REWRITER_typedef_NSLocale
typedef struct objc_object NSLocale;
typedef struct {} _objc_exc_NSLocale;
#endif

#ifndef _REWRITER_typedef_NSCalendar
#define _REWRITER_typedef_NSCalendar
typedef struct objc_object NSCalendar;
typedef struct {} _objc_exc_NSCalendar;
#endif

#ifndef _REWRITER_typedef_NSTimeZone
#define _REWRITER_typedef_NSTimeZone
typedef struct objc_object NSTimeZone;
typedef struct {} _objc_exc_NSTimeZone;
#endif

#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif




typedef NSUInteger NSDateIntervalFormatterStyle; enum {
    NSDateIntervalFormatterNoStyle = 0,
    NSDateIntervalFormatterShortStyle = 1,
    NSDateIntervalFormatterMediumStyle = 2,
    NSDateIntervalFormatterLongStyle = 3,
    NSDateIntervalFormatterFullStyle = 4
} __attribute__((availability(ios,introduced=8_0)));




__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=8_0)))

#ifndef _REWRITER_typedef_NSDateIntervalFormatter
#define _REWRITER_typedef_NSDateIntervalFormatter
typedef struct objc_object NSDateIntervalFormatter;
typedef struct {} _objc_exc_NSDateIntervalFormatter;
#endif

struct NSDateIntervalFormatter_IMPL {
	struct NSFormatter_IMPL NSFormatter_IVARS;
	NSLocale *__strong _locale;
	NSCalendar *__strong _calendar;
	NSTimeZone *__strong _timeZone;
	NSString *__strong _dateTemplate;
	NSString *__strong _dateTemplateFromStyles;
	void *_formatter;
	NSDateIntervalFormatterStyle _dateStyle;
	NSDateIntervalFormatterStyle _timeStyle;
	BOOL _modified;
	BOOL _useTemplate;
	__strong dispatch_semaphore_t _lock;
	void *_reserved[4];
};


// @property (null_resettable, copy) NSLocale *locale;
// @property (null_resettable, copy) NSCalendar *calendar;
// @property (null_resettable, copy) NSTimeZone *timeZone;
// @property (null_resettable, copy) NSString *dateTemplate;
// @property NSDateIntervalFormatterStyle dateStyle;
// @property NSDateIntervalFormatterStyle timeStyle;
// - (NSString *)stringFromDate:(NSDate *)fromDate toDate:(NSDate *)toDate;

/* @end */







// @class NSNumberFormatter;
#ifndef _REWRITER_typedef_NSNumberFormatter
#define _REWRITER_typedef_NSNumberFormatter
typedef struct objc_object NSNumberFormatter;
typedef struct {} _objc_exc_NSNumberFormatter;
#endif




typedef NSInteger NSMassFormatterUnit; enum {
    NSMassFormatterUnitGram = 11,
    NSMassFormatterUnitKilogram = 14,
    NSMassFormatterUnitOunce = (6 << 8) + 1,
    NSMassFormatterUnitPound = (6 << 8) + 2,
    NSMassFormatterUnitStone = (6 << 8) + 3,
} __attribute__((availability(ios,introduced=8_0)));

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=8_0)))

#ifndef _REWRITER_typedef_NSMassFormatter
#define _REWRITER_typedef_NSMassFormatter
typedef struct objc_object NSMassFormatter;
typedef struct {} _objc_exc_NSMassFormatter;
#endif

struct NSMassFormatter_IMPL {
	struct NSFormatter_IMPL NSFormatter_IVARS;
	void *_formatter;
	BOOL _isForPersonMassUse;
	void *_reserved[2];
};


// @property (null_resettable, copy) NSNumberFormatter *numberFormatter;
// @property NSFormattingUnitStyle unitStyle;
// @property (getter = isForPersonMassUse) BOOL forPersonMassUse;


// - (NSString *)stringFromValue:(double)value unit:(NSMassFormatterUnit)unit;


// - (NSString *)stringFromKilograms:(double)numberInKilograms;


// - (NSString *)unitStringFromValue:(double)value unit:(NSMassFormatterUnit)unit;


// - (NSString *)unitStringFromKilograms:(double)numberInKilograms usedUnit:(nullable NSMassFormatterUnit *)unitp;


// - (BOOL)getObjectValue:(out id _Nullable * _Nullable)obj forString:(NSString *)string errorDescription:(out NSString * _Nullable * _Nullable)error;
/* @end */









typedef NSInteger NSLengthFormatterUnit; enum {
    NSLengthFormatterUnitMillimeter = 8,
    NSLengthFormatterUnitCentimeter = 9,
    NSLengthFormatterUnitMeter = 11,
    NSLengthFormatterUnitKilometer = 14,
    NSLengthFormatterUnitInch = (5 << 8) + 1,
    NSLengthFormatterUnitFoot = (5 << 8) + 2,
    NSLengthFormatterUnitYard = (5 << 8) + 3,
    NSLengthFormatterUnitMile = (5 << 8) + 4,
} __attribute__((availability(ios,introduced=8_0)));

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=8_0)))

#ifndef _REWRITER_typedef_NSLengthFormatter
#define _REWRITER_typedef_NSLengthFormatter
typedef struct objc_object NSLengthFormatter;
typedef struct {} _objc_exc_NSLengthFormatter;
#endif

struct NSLengthFormatter_IMPL {
	struct NSFormatter_IMPL NSFormatter_IVARS;
	void *_formatter;
	BOOL _isForPersonHeight;
	void *_reserved[2];
};

// @property (null_resettable, copy) NSNumberFormatter *numberFormatter;
// @property NSFormattingUnitStyle unitStyle;

// @property (getter = isForPersonHeightUse) BOOL forPersonHeightUse;


// - (NSString *)stringFromValue:(double)value unit:(NSLengthFormatterUnit)unit;


// - (NSString *)stringFromMeters:(double)numberInMeters;


// - (NSString *)unitStringFromValue:(double)value unit:(NSLengthFormatterUnit)unit;


// - (NSString *)unitStringFromMeters:(double)numberInMeters usedUnit:(nullable NSLengthFormatterUnit *)unitp;


// - (BOOL)getObjectValue:(out id _Nullable * _Nullable)obj forString:(NSString *)string errorDescription:(out NSString * _Nullable * _Nullable)error;
/* @end */









typedef NSInteger NSEnergyFormatterUnit; enum {
    NSEnergyFormatterUnitJoule = 11,
    NSEnergyFormatterUnitKilojoule = 14,
    NSEnergyFormatterUnitCalorie = (7 << 8) + 1,
    NSEnergyFormatterUnitKilocalorie = (7 << 8) + 2,
} __attribute__((availability(ios,introduced=8_0)));

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=8_0)))

#ifndef _REWRITER_typedef_NSEnergyFormatter
#define _REWRITER_typedef_NSEnergyFormatter
typedef struct objc_object NSEnergyFormatter;
typedef struct {} _objc_exc_NSEnergyFormatter;
#endif

struct NSEnergyFormatter_IMPL {
	struct NSFormatter_IMPL NSFormatter_IVARS;
	void *_formatter;
	BOOL _isForFoodEnergyUse;
	void *_reserved[2];
};

// @property (null_resettable, copy) NSNumberFormatter *numberFormatter;
// @property NSFormattingUnitStyle unitStyle;
// @property (getter = isForFoodEnergyUse) BOOL forFoodEnergyUse;


// - (NSString *)stringFromValue:(double)value unit:(NSEnergyFormatterUnit)unit;


// - (NSString *)stringFromJoules:(double)numberInJoules;


// - (NSString *)unitStringFromValue:(double)value unit:(NSEnergyFormatterUnit)unit;


// - (NSString *)unitStringFromJoules:(double)numberInJoules usedUnit:(nullable NSEnergyFormatterUnit *)unitp;


// - (BOOL)getObjectValue:(out id _Nullable * _Nullable)obj forString:(NSString *)string errorDescription:(out NSString * _Nullable * _Nullable)error;
/* @end */

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=9_0)))

#ifndef _REWRITER_typedef_NSPersonNameComponents
#define _REWRITER_typedef_NSPersonNameComponents
typedef struct objc_object NSPersonNameComponents;
typedef struct {} _objc_exc_NSPersonNameComponents;
#endif

struct NSPersonNameComponents_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _private;
};





// @property (copy, nullable) NSString *namePrefix;


// @property (copy, nullable) NSString *givenName;


// @property (copy, nullable) NSString *middleName;


// @property (copy, nullable) NSString *familyName;


// @property (copy, nullable) NSString *nameSuffix;


// @property (copy, nullable) NSString *nickname;




// @property (copy, nullable) NSPersonNameComponents *phoneticRepresentation;

/* @end */

typedef NSInteger NSPersonNameComponentsFormatterStyle; enum {
    NSPersonNameComponentsFormatterStyleDefault = 0,



    NSPersonNameComponentsFormatterStyleShort,


    NSPersonNameComponentsFormatterStyleMedium,


    NSPersonNameComponentsFormatterStyleLong,


    NSPersonNameComponentsFormatterStyleAbbreviated
} __attribute__((availability(ios,introduced=9_0)));

typedef NSUInteger NSPersonNameComponentsFormatterOptions; enum {




    NSPersonNameComponentsFormatterPhonetic = (1UL << 1)
} __attribute__((availability(ios,introduced=9_0)));


__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=9_0)))

#ifndef _REWRITER_typedef_NSPersonNameComponentsFormatter
#define _REWRITER_typedef_NSPersonNameComponentsFormatter
typedef struct objc_object NSPersonNameComponentsFormatter;
typedef struct {} _objc_exc_NSPersonNameComponentsFormatter;
#endif

struct NSPersonNameComponentsFormatter_IMPL {
	struct NSFormatter_IMPL NSFormatter_IVARS;
	__strong id _private;
};




// @property NSPersonNameComponentsFormatterStyle style;



// @property (getter=isPhonetic) BOOL phonetic;




#if 0
+ (NSString *)localizedStringFromPersonNameComponents:(NSPersonNameComponents *)components
                                                style:(NSPersonNameComponentsFormatterStyle)nameFormatStyle
                                              options:(NSPersonNameComponentsFormatterOptions)nameOptions;
#endif




// - (NSString *)stringFromPersonNameComponents:(NSPersonNameComponents *)components;




// - (NSAttributedString *)annotatedStringFromPersonNameComponents:(NSPersonNameComponents *)components;



// - (BOOL)getObjectValue:(out id _Nullable * _Nullable)obj forString:(NSString *)string errorDescription:(out NSString * _Nullable * _Nullable)error;

/* @end */



extern "C" NSString * const NSPersonNameComponentKey __attribute__((availability(ios,introduced=9_0)));


extern "C" NSString * const NSPersonNameComponentGivenName __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSPersonNameComponentFamilyName __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSPersonNameComponentMiddleName __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSPersonNameComponentPrefix __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSPersonNameComponentSuffix __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSPersonNameComponentNickname __attribute__((availability(ios,introduced=9_0)));




extern "C" NSString * const NSPersonNameComponentDelimiter __attribute__((availability(ios,introduced=9_0)));







// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

typedef NSUInteger NSRoundingMode; enum {
    NSRoundPlain,
    NSRoundDown,
    NSRoundUp,
    NSRoundBankers
};

typedef NSUInteger NSCalculationError; enum {
    NSCalculationNoError = 0,
    NSCalculationLossOfPrecision,
    NSCalculationUnderflow,
    NSCalculationOverflow,
    NSCalculationDivideByZero
};






typedef struct {
    signed int _exponent:8;
    unsigned int _length:4;
    unsigned int _isNegative:1;
    unsigned int _isCompact:1;
    unsigned int _reserved:18;
    unsigned short _mantissa[(8)];
} NSDecimal;

static __inline__ __attribute__((always_inline)) BOOL NSDecimalIsNotANumber(const NSDecimal *dcm)
  { return ((dcm->_length == 0) && dcm->_isNegative); }



extern "C" void NSDecimalCopy(NSDecimal *destination, const NSDecimal *source);

extern "C" void NSDecimalCompact(NSDecimal *number);

extern "C" NSComparisonResult NSDecimalCompare(const NSDecimal *leftOperand, const NSDecimal *rightOperand);


extern "C" void NSDecimalRound(NSDecimal *result, const NSDecimal *number, NSInteger scale, NSRoundingMode roundingMode);




extern "C" NSCalculationError NSDecimalNormalize(NSDecimal *number1, NSDecimal *number2, NSRoundingMode roundingMode);

extern "C" NSCalculationError NSDecimalAdd(NSDecimal *result, const NSDecimal *leftOperand, const NSDecimal *rightOperand, NSRoundingMode roundingMode);


extern "C" NSCalculationError NSDecimalSubtract(NSDecimal *result, const NSDecimal *leftOperand, const NSDecimal *rightOperand, NSRoundingMode roundingMode);


extern "C" NSCalculationError NSDecimalMultiply(NSDecimal *result, const NSDecimal *leftOperand, const NSDecimal *rightOperand, NSRoundingMode roundingMode);


extern "C" NSCalculationError NSDecimalDivide(NSDecimal *result, const NSDecimal *leftOperand, const NSDecimal *rightOperand, NSRoundingMode roundingMode);



extern "C" NSCalculationError NSDecimalPower(NSDecimal *result, const NSDecimal *number, NSUInteger power, NSRoundingMode roundingMode);

extern "C" NSCalculationError NSDecimalMultiplyByPowerOf10(NSDecimal *result, const NSDecimal *number, short power, NSRoundingMode roundingMode);

extern "C" NSString *NSDecimalString(const NSDecimal *dcm, id _Nullable locale);











// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSCharacterSet
#define _REWRITER_typedef_NSCharacterSet
typedef struct objc_object NSCharacterSet;
typedef struct {} _objc_exc_NSCharacterSet;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif





#ifndef _REWRITER_typedef_NSScanner
#define _REWRITER_typedef_NSScanner
typedef struct objc_object NSScanner;
typedef struct {} _objc_exc_NSScanner;
#endif

struct NSScanner_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly, copy) NSString *string;
// @property NSUInteger scanLocation;
// @property (nullable, copy) NSCharacterSet *charactersToBeSkipped;
// @property BOOL caseSensitive;
// @property (nullable, retain) id locale;

// - (instancetype)initWithString:(NSString *)string __attribute__((objc_designated_initializer));

/* @end */


// @interface NSScanner (NSExtendedScanner)


// - (BOOL)scanInt:(nullable int *)result;
// - (BOOL)scanInteger:(nullable NSInteger *)result __attribute__((availability(ios,introduced=2_0)));
// - (BOOL)scanLongLong:(nullable long long *)result;
// - (BOOL)scanUnsignedLongLong:(nullable unsigned long long *)result __attribute__((availability(ios,introduced=7_0)));
// - (BOOL)scanFloat:(nullable float *)result;
// - (BOOL)scanDouble:(nullable double *)result;
// - (BOOL)scanHexInt:(nullable unsigned *)result;
// - (BOOL)scanHexLongLong:(nullable unsigned long long *)result __attribute__((availability(ios,introduced=2_0)));
// - (BOOL)scanHexFloat:(nullable float *)result __attribute__((availability(ios,introduced=2_0)));
// - (BOOL)scanHexDouble:(nullable double *)result __attribute__((availability(ios,introduced=2_0)));

// - (BOOL)scanString:(NSString *)string intoString:(NSString * _Nullable * _Nullable)result;
// - (BOOL)scanCharactersFromSet:(NSCharacterSet *)set intoString:(NSString * _Nullable * _Nullable)result;

// - (BOOL)scanUpToString:(NSString *)string intoString:(NSString * _Nullable * _Nullable)result;
// - (BOOL)scanUpToCharactersFromSet:(NSCharacterSet *)set intoString:(NSString * _Nullable * _Nullable)result;

// @property (getter=isAtEnd, readonly) BOOL atEnd;

// + (instancetype)scannerWithString:(NSString *)string;
// + (id)localizedScannerWithString:(NSString *)string;

/* @end */








extern "C" NSString * const NSDecimalNumberExactnessException;
extern "C" NSString * const NSDecimalNumberOverflowException;
extern "C" NSString * const NSDecimalNumberUnderflowException;
extern "C" NSString * const NSDecimalNumberDivideByZeroException;



// @class NSDecimalNumber;
#ifndef _REWRITER_typedef_NSDecimalNumber
#define _REWRITER_typedef_NSDecimalNumber
typedef struct objc_object NSDecimalNumber;
typedef struct {} _objc_exc_NSDecimalNumber;
#endif


// @protocol NSDecimalNumberBehaviors

// - (NSRoundingMode)roundingMode;

// - (short)scale;


// - (nullable NSDecimalNumber *)exceptionDuringOperation:(SEL)operation error:(NSCalculationError)error leftOperand:(NSDecimalNumber *)leftOperand rightOperand:(nullable NSDecimalNumber *)rightOperand;


/* @end */





#ifndef _REWRITER_typedef_NSDecimalNumber
#define _REWRITER_typedef_NSDecimalNumber
typedef struct objc_object NSDecimalNumber;
typedef struct {} _objc_exc_NSDecimalNumber;
#endif

	struct NSDecimalNumber__T_1 {
	int _exponent : 8;
	unsigned int _length : 4;
	unsigned int _isNegative : 1;
	unsigned int _isCompact : 1;
	unsigned int _reserved : 1;
	unsigned int _hasExternalRefCount : 1;
	unsigned int _refs : 16;
	} ;
struct NSDecimalNumber_IMPL {
	struct NSNumber_IMPL NSNumber_IVARS;
	struct NSDecimalNumber__T_1 NSDecimalNumber__GRBF_1;
	unsigned short _mantissa[0];
};


// - (instancetype)initWithMantissa:(unsigned long long)mantissa exponent:(short)exponent isNegative:(BOOL)flag;
// - (instancetype)initWithDecimal:(NSDecimal)dcm __attribute__((objc_designated_initializer));
// - (instancetype)initWithString:(nullable NSString *)numberValue;
// - (instancetype)initWithString:(nullable NSString *)numberValue locale:(nullable id)locale;

// - (NSString *)descriptionWithLocale:(nullable id)locale;

// @property (readonly) NSDecimal decimalValue;

// + (NSDecimalNumber *)decimalNumberWithMantissa:(unsigned long long)mantissa exponent:(short)exponent isNegative:(BOOL)flag;
// + (NSDecimalNumber *)decimalNumberWithDecimal:(NSDecimal)dcm;
// + (NSDecimalNumber *)decimalNumberWithString:(nullable NSString *)numberValue;
// + (NSDecimalNumber *)decimalNumberWithString:(nullable NSString *)numberValue locale:(nullable id)locale;

// + (NSDecimalNumber *)zero;
// + (NSDecimalNumber *)one;
// + (NSDecimalNumber *)minimumDecimalNumber;
// + (NSDecimalNumber *)maximumDecimalNumber;
// + (NSDecimalNumber *)notANumber;

// - (NSDecimalNumber *)decimalNumberByAdding:(NSDecimalNumber *)decimalNumber;
// - (NSDecimalNumber *)decimalNumberByAdding:(NSDecimalNumber *)decimalNumber withBehavior:(nullable id <NSDecimalNumberBehaviors>)behavior;

// - (NSDecimalNumber *)decimalNumberBySubtracting:(NSDecimalNumber *)decimalNumber;
// - (NSDecimalNumber *)decimalNumberBySubtracting:(NSDecimalNumber *)decimalNumber withBehavior:(nullable id <NSDecimalNumberBehaviors>)behavior;

// - (NSDecimalNumber *)decimalNumberByMultiplyingBy:(NSDecimalNumber *)decimalNumber;
// - (NSDecimalNumber *)decimalNumberByMultiplyingBy:(NSDecimalNumber *)decimalNumber withBehavior:(nullable id <NSDecimalNumberBehaviors>)behavior;

// - (NSDecimalNumber *)decimalNumberByDividingBy:(NSDecimalNumber *)decimalNumber;
// - (NSDecimalNumber *)decimalNumberByDividingBy:(NSDecimalNumber *)decimalNumber withBehavior:(nullable id <NSDecimalNumberBehaviors>)behavior;

// - (NSDecimalNumber *)decimalNumberByRaisingToPower:(NSUInteger)power;
// - (NSDecimalNumber *)decimalNumberByRaisingToPower:(NSUInteger)power withBehavior:(nullable id <NSDecimalNumberBehaviors>)behavior;

// - (NSDecimalNumber *)decimalNumberByMultiplyingByPowerOf10:(short)power;
// - (NSDecimalNumber *)decimalNumberByMultiplyingByPowerOf10:(short)power withBehavior:(nullable id <NSDecimalNumberBehaviors>)behavior;


// - (NSDecimalNumber *)decimalNumberByRoundingAccordingToBehavior:(nullable id <NSDecimalNumberBehaviors>)behavior;


// - (NSComparisonResult)compare:(NSNumber *)decimalNumber;


// + (void)setDefaultBehavior:(id <NSDecimalNumberBehaviors>)behavior;

// + (id <NSDecimalNumberBehaviors>)defaultBehavior;






// @property (readonly) const char *objCType __attribute__((objc_returns_inner_pointer));


// @property (readonly) double doubleValue;


/* @end */





#ifndef _REWRITER_typedef_NSDecimalNumberHandler
#define _REWRITER_typedef_NSDecimalNumberHandler
typedef struct objc_object NSDecimalNumberHandler;
typedef struct {} _objc_exc_NSDecimalNumberHandler;
#endif

	struct NSDecimalNumberHandler__T_1 {
	int _scale : 16;
	unsigned int _roundingMode : 3;
	unsigned int _raiseOnExactness : 1;
	unsigned int _raiseOnOverflow : 1;
	unsigned int _raiseOnUnderflow : 1;
	unsigned int _raiseOnDivideByZero : 1;
	unsigned int _unused : 9;
	} ;
struct NSDecimalNumberHandler_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	struct NSDecimalNumberHandler__T_1 NSDecimalNumberHandler__GRBF_1;
	void *_reserved2;
	void *_reserved;
};


// + (NSDecimalNumberHandler *)defaultDecimalNumberHandler;





// - (instancetype)initWithRoundingMode:(NSRoundingMode)roundingMode scale:(short)scale raiseOnExactness:(BOOL)exact raiseOnOverflow:(BOOL)overflow raiseOnUnderflow:(BOOL)underflow raiseOnDivideByZero:(BOOL)divideByZero __attribute__((objc_designated_initializer));

// + (instancetype)decimalNumberHandlerWithRoundingMode:(NSRoundingMode)roundingMode scale:(short)scale raiseOnExactness:(BOOL)exact raiseOnOverflow:(BOOL)overflow raiseOnUnderflow:(BOOL)underflow raiseOnDivideByZero:(BOOL)divideByZero;

/* @end */




// @interface NSNumber (NSDecimalNumberExtensions)

// @property (readonly) NSDecimal decimalValue;


/* @end */


// @interface NSScanner (NSDecimalNumberScanning)

// - (BOOL)scanDecimal:(nullable NSDecimal *)dcm;

/* @end */









// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif





extern "C" NSString *const NSCocoaErrorDomain;


extern "C" NSString *const NSPOSIXErrorDomain;
extern "C" NSString *const NSOSStatusErrorDomain;
extern "C" NSString *const NSMachErrorDomain;


extern "C" NSString *const NSUnderlyingErrorKey;


extern "C" NSString *const NSLocalizedDescriptionKey;
extern "C" NSString *const NSLocalizedFailureReasonErrorKey;
extern "C" NSString *const NSLocalizedRecoverySuggestionErrorKey;
extern "C" NSString *const NSLocalizedRecoveryOptionsErrorKey;
extern "C" NSString *const NSRecoveryAttempterErrorKey;
extern "C" NSString *const NSHelpAnchorErrorKey;


extern "C" NSString *const NSStringEncodingErrorKey ;
extern "C" NSString *const NSURLErrorKey;
extern "C" NSString *const NSFilePathErrorKey;




#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

struct NSError_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *_reserved;
	NSInteger _code;
	NSString *__strong _domain;
	NSDictionary *__strong _userInfo;
};




// - (instancetype)initWithDomain:(NSString *)domain code:(NSInteger)code userInfo:(nullable NSDictionary *)dict __attribute__((objc_designated_initializer));
// + (instancetype)errorWithDomain:(NSString *)domain code:(NSInteger)code userInfo:(nullable NSDictionary *)dict;



// @property (readonly, copy) NSString *domain;
// @property (readonly) NSInteger code;



// @property (readonly, copy) NSDictionary *userInfo;



// @property (readonly, copy) NSString *localizedDescription;



// @property (nullable, readonly, copy) NSString *localizedFailureReason;



// @property (nullable, readonly, copy) NSString *localizedRecoverySuggestion;



// @property (nullable, readonly, copy) NSArray<NSString *> *localizedRecoveryOptions;



// @property (nullable, readonly, strong) id recoveryAttempter;



// @property (nullable, readonly, copy) NSString *helpAnchor;
// + (void)setUserInfoValueProviderForDomain:(NSString *)errorDomain provider:(id _Nullable (^ _Nullable)(NSError *err, NSString *userInfoKey))provider __attribute__((availability(ios,introduced=9_0)));
// + (id _Nullable (^ _Nullable)(NSError *err, NSString *userInfoKey))userInfoValueProviderForDomain:(NSString *)errorDomain __attribute__((availability(ios,introduced=9_0)));

/* @end */



// @interface NSObject(NSErrorRecoveryAttempting)







// - (void)attemptRecoveryFromError:(NSError *)error optionIndex:(NSUInteger)recoveryOptionIndex delegate:(nullable id)delegate didRecoverSelector:(nullable SEL)didRecoverSelector contextInfo:(nullable void *)contextInfo;



// - (BOOL)attemptRecoveryFromError:(NSError *)error optionIndex:(NSUInteger)recoveryOptionIndex;

/* @end */

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
typedef struct objc_object NSNumber;
typedef struct {} _objc_exc_NSNumber;
#endif






extern "C" NSString * const NSGenericException;
extern "C" NSString * const NSRangeException;
extern "C" NSString * const NSInvalidArgumentException;
extern "C" NSString * const NSInternalInconsistencyException;

extern "C" NSString * const NSMallocException;

extern "C" NSString * const NSObjectInaccessibleException;
extern "C" NSString * const NSObjectNotAvailableException;
extern "C" NSString * const NSDestinationInvalidException;

extern "C" NSString * const NSPortTimeoutException;
extern "C" NSString * const NSInvalidSendPortException;
extern "C" NSString * const NSInvalidReceivePortException;
extern "C" NSString * const NSPortSendException;
extern "C" NSString * const NSPortReceiveException;

extern "C" NSString * const NSOldStyleException;




__attribute__((__objc_exception__))


#ifndef _REWRITER_typedef_NSException
#define _REWRITER_typedef_NSException
typedef struct objc_object NSException;
typedef struct {} _objc_exc_NSException;
#endif

struct NSException_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSString *__strong name;
	NSString *__strong reason;
	NSDictionary *__strong userInfo;
	__strong id reserved;
};


// + (NSException *)exceptionWithName:(NSString *)name reason:(nullable NSString *)reason userInfo:(nullable NSDictionary *)userInfo;
// - (instancetype)initWithName:(NSString *)aName reason:(nullable NSString *)aReason userInfo:(nullable NSDictionary *)aUserInfo __attribute__((objc_designated_initializer));

// @property (readonly, copy) NSString *name;
// @property (nullable, readonly, copy) NSString *reason;
// @property (nullable, readonly, copy) NSDictionary *userInfo;

// @property (readonly, copy) NSArray<NSNumber *> *callStackReturnAddresses __attribute__((availability(ios,introduced=2_0)));
// @property (readonly, copy) NSArray<NSString *> *callStackSymbols __attribute__((availability(ios,introduced=4_0)));

// - (void)raise;

/* @end */


// @interface NSException (NSExceptionRaisingConveniences)

// + (void)raise:(NSString *)name format:(NSString *)format, ... __attribute__((format(__NSString__, 2, 3)));
// + (void)raise:(NSString *)name format:(NSString *)format arguments:(va_list)argList __attribute__((format(__NSString__, 2, 0)));

/* @end */

typedef void NSUncaughtExceptionHandler(NSException *exception);

extern "C" NSUncaughtExceptionHandler * _Nullable NSGetUncaughtExceptionHandler(void);
extern "C" void NSSetUncaughtExceptionHandler(NSUncaughtExceptionHandler * _Nullable);
// @class NSAssertionHandler;
#ifndef _REWRITER_typedef_NSAssertionHandler
#define _REWRITER_typedef_NSAssertionHandler
typedef struct objc_object NSAssertionHandler;
typedef struct {} _objc_exc_NSAssertionHandler;
#endif

extern "C" NSString * const NSAssertionHandlerKey __attribute__((availability(ios,introduced=4_0)));


#ifndef _REWRITER_typedef_NSAssertionHandler
#define _REWRITER_typedef_NSAssertionHandler
typedef struct objc_object NSAssertionHandler;
typedef struct {} _objc_exc_NSAssertionHandler;
#endif

struct NSAssertionHandler_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *_reserved;
};


// + (NSAssertionHandler *)currentHandler;

// - (void)handleFailureInMethod:(SEL)selector object:(id)object file:(NSString *)fileName lineNumber:(NSInteger)line description:(nullable NSString *)format,... __attribute__((format(__NSString__, 5, 6)));

// - (void)handleFailureInFunction:(NSString *)functionName file:(NSString *)fileName lineNumber:(NSInteger)line description:(nullable NSString *)format,... __attribute__((format(__NSString__, 4, 5)));

/* @end */









// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif





#ifndef _REWRITER_typedef_NSFileHandle
#define _REWRITER_typedef_NSFileHandle
typedef struct objc_object NSFileHandle;
typedef struct {} _objc_exc_NSFileHandle;
#endif

struct NSFileHandle_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly, copy) NSData *availableData;

// - (NSData *)readDataToEndOfFile;
// - (NSData *)readDataOfLength:(NSUInteger)length;

// - (void)writeData:(NSData *)data;

// @property (readonly) unsigned long long offsetInFile;
// - (unsigned long long)seekToEndOfFile;
// - (void)seekToFileOffset:(unsigned long long)offset;

// - (void)truncateFileAtOffset:(unsigned long long)offset;
// - (void)synchronizeFile;
// - (void)closeFile;

// - (instancetype)initWithFileDescriptor:(int)fd closeOnDealloc:(BOOL)closeopt __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)coder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSFileHandle (NSFileHandleCreation)

// + (NSFileHandle *)fileHandleWithStandardInput;
// + (NSFileHandle *)fileHandleWithStandardOutput;
// + (NSFileHandle *)fileHandleWithStandardError;
// + (NSFileHandle *)fileHandleWithNullDevice;

// + (nullable instancetype)fileHandleForReadingAtPath:(NSString *)path;
// + (nullable instancetype)fileHandleForWritingAtPath:(NSString *)path;
// + (nullable instancetype)fileHandleForUpdatingAtPath:(NSString *)path;

// + (nullable instancetype)fileHandleForReadingFromURL:(NSURL *)url error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));
// + (nullable instancetype)fileHandleForWritingToURL:(NSURL *)url error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));
// + (nullable instancetype)fileHandleForUpdatingURL:(NSURL *)url error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));

/* @end */


extern "C" NSString * const NSFileHandleOperationException;

extern "C" NSString * const NSFileHandleReadCompletionNotification;
extern "C" NSString * const NSFileHandleReadToEndOfFileCompletionNotification;
extern "C" NSString * const NSFileHandleConnectionAcceptedNotification;
extern "C" NSString * const NSFileHandleDataAvailableNotification;

extern "C" NSString * const NSFileHandleNotificationDataItem;
extern "C" NSString * const NSFileHandleNotificationFileHandleItem;
extern "C" NSString * const NSFileHandleNotificationMonitorModes __attribute__((availability(ios,introduced=2_0,deprecated=5_0,message="" )));

// @interface NSFileHandle (NSFileHandleAsynchronousAccess)

// - (void)readInBackgroundAndNotifyForModes:(nullable NSArray<NSString *> *)modes;
// - (void)readInBackgroundAndNotify;

// - (void)readToEndOfFileInBackgroundAndNotifyForModes:(nullable NSArray<NSString *> *)modes;
// - (void)readToEndOfFileInBackgroundAndNotify;

// - (void)acceptConnectionInBackgroundAndNotifyForModes:(nullable NSArray<NSString *> *)modes;
// - (void)acceptConnectionInBackgroundAndNotify;

// - (void)waitForDataInBackgroundAndNotifyForModes:(nullable NSArray<NSString *> *)modes;
// - (void)waitForDataInBackgroundAndNotify;


// @property (nullable, copy) void (^readabilityHandler)(NSFileHandle *) __attribute__((availability(ios,introduced=5_0)));
// @property (nullable, copy) void (^writeabilityHandler)(NSFileHandle *) __attribute__((availability(ios,introduced=5_0)));


/* @end */


// @interface NSFileHandle (NSFileHandlePlatformSpecific)

// - (instancetype)initWithFileDescriptor:(int)fd;

// @property (readonly) int fileDescriptor;

/* @end */



#ifndef _REWRITER_typedef_NSPipe
#define _REWRITER_typedef_NSPipe
typedef struct objc_object NSPipe;
typedef struct {} _objc_exc_NSPipe;
#endif

struct NSPipe_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly, retain) NSFileHandle *fileHandleForReading;
// @property (readonly, retain) NSFileHandle *fileHandleForWriting;

// + (NSPipe *)pipe;

/* @end */








// @interface NSString (NSStringPathExtensions)

// + (NSString *)pathWithComponents:(NSArray<NSString *> *)components;
// @property (readonly, copy) NSArray<NSString *> *pathComponents;

// @property (getter=isAbsolutePath, readonly) BOOL absolutePath;

// @property (readonly, copy) NSString *lastPathComponent;
// @property (readonly, copy) NSString *stringByDeletingLastPathComponent;
// - (NSString *)stringByAppendingPathComponent:(NSString *)str;

// @property (readonly, copy) NSString *pathExtension;
// @property (readonly, copy) NSString *stringByDeletingPathExtension;
// - (nullable NSString *)stringByAppendingPathExtension:(NSString *)str;

// @property (readonly, copy) NSString *stringByAbbreviatingWithTildeInPath;
// @property (readonly, copy) NSString *stringByExpandingTildeInPath;

// @property (readonly, copy) NSString *stringByStandardizingPath;

// @property (readonly, copy) NSString *stringByResolvingSymlinksInPath;

// - (NSArray<NSString *> *)stringsByAppendingPaths:(NSArray<NSString *> *)paths;

// - (NSUInteger)completePathIntoString:(NSString * _Nonnull * _Nullable)outputName caseSensitive:(BOOL)flag matchesIntoArray:(NSArray<NSString *> * _Nonnull * _Nullable)outputArray filterTypes:(nullable NSArray<NSString *> *)filterTypes;

// @property (readonly) __attribute__((objc_ownership(strong))) const char *fileSystemRepresentation __attribute__((objc_returns_inner_pointer));
// - (BOOL)getFileSystemRepresentation:(char *)cname maxLength:(NSUInteger)max;

/* @end */


// @interface NSArray<ObjectType> (NSArrayPathExtensions)

// - (NSArray<NSString *> *)pathsMatchingExtensions:(NSArray<NSString *> *)filterTypes;

/* @end */


extern "C" NSString *NSUserName(void);
extern "C" NSString *NSFullUserName(void);

extern "C" NSString *NSHomeDirectory(void);
extern "C" NSString * _Nullable NSHomeDirectoryForUser(NSString * _Nullable userName);

extern "C" NSString *NSTemporaryDirectory(void);

extern "C" NSString *NSOpenStepRootDirectory(void);

typedef NSUInteger NSSearchPathDirectory; enum {
    NSApplicationDirectory = 1,
    NSDemoApplicationDirectory,
    NSDeveloperApplicationDirectory,
    NSAdminApplicationDirectory,
    NSLibraryDirectory,
    NSDeveloperDirectory,
    NSUserDirectory,
    NSDocumentationDirectory,
    NSDocumentDirectory,
    NSCoreServiceDirectory,
    NSAutosavedInformationDirectory __attribute__((availability(ios,introduced=4_0))) = 11,
    NSDesktopDirectory = 12,
    NSCachesDirectory = 13,
    NSApplicationSupportDirectory = 14,
    NSDownloadsDirectory __attribute__((availability(ios,introduced=2_0))) = 15,
    NSInputMethodsDirectory __attribute__((availability(ios,introduced=4_0))) = 16,
    NSMoviesDirectory __attribute__((availability(ios,introduced=4_0))) = 17,
    NSMusicDirectory __attribute__((availability(ios,introduced=4_0))) = 18,
    NSPicturesDirectory __attribute__((availability(ios,introduced=4_0))) = 19,
    NSPrinterDescriptionDirectory __attribute__((availability(ios,introduced=4_0))) = 20,
    NSSharedPublicDirectory __attribute__((availability(ios,introduced=4_0))) = 21,
    NSPreferencePanesDirectory __attribute__((availability(ios,introduced=4_0))) = 22,
    NSApplicationScriptsDirectory __attribute__((availability(ios,introduced=NA))) = 23,
    NSItemReplacementDirectory __attribute__((availability(ios,introduced=4_0))) = 99,
    NSAllApplicationsDirectory = 100,
    NSAllLibrariesDirectory = 101,
    NSTrashDirectory __attribute__((availability(ios,introduced=NA))) = 102

};

typedef NSUInteger NSSearchPathDomainMask; enum {
    NSUserDomainMask = 1,
    NSLocalDomainMask = 2,
    NSNetworkDomainMask = 4,
    NSSystemDomainMask = 8,
    NSAllDomainsMask = 0x0ffff
};

extern "C" NSArray<NSString *> *NSSearchPathForDirectoriesInDomains(NSSearchPathDirectory directory, NSSearchPathDomainMask domainMask, BOOL expandTilde);


// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

#ifndef _REWRITER_typedef_NSDirectoryEnumerator
#define _REWRITER_typedef_NSDirectoryEnumerator
typedef struct objc_object NSDirectoryEnumerator;
typedef struct {} _objc_exc_NSDirectoryEnumerator;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
typedef struct objc_object NSNumber;
typedef struct {} _objc_exc_NSNumber;
#endif

// @protocol NSFileManagerDelegate;







typedef NSUInteger NSVolumeEnumerationOptions; enum {


    NSVolumeEnumerationSkipHiddenVolumes = 1UL << 1,



    NSVolumeEnumerationProduceFileReferenceURLs = 1UL << 2
} __attribute__((availability(ios,introduced=4_0)));

typedef NSUInteger NSDirectoryEnumerationOptions; enum {


    NSDirectoryEnumerationSkipsSubdirectoryDescendants = 1UL << 0,



    NSDirectoryEnumerationSkipsPackageDescendants = 1UL << 1,



    NSDirectoryEnumerationSkipsHiddenFiles = 1UL << 2
} __attribute__((availability(ios,introduced=4_0)));

typedef NSUInteger NSFileManagerItemReplacementOptions; enum {


    NSFileManagerItemReplacementUsingNewMetadataOnly = 1UL << 0,



     NSFileManagerItemReplacementWithoutDeletingBackupItem = 1UL << 1
} __attribute__((availability(ios,introduced=4_0)));

typedef NSInteger NSURLRelationship; enum {
    NSURLRelationshipContains,
    NSURLRelationshipSame,
    NSURLRelationshipOther
} __attribute__((availability(ios,introduced=8_0)));


typedef NSUInteger NSFileManagerUnmountOptions; enum {


    NSFileManagerUnmountAllPartitionsAndEjectDisk = 1UL << 0,



    NSFileManagerUnmountWithoutUI = 1UL << 1,
} __attribute__((availability(ios,introduced=NA)));


extern "C" NSString *const NSFileManagerUnmountDissentingProcessIdentifierErrorKey __attribute__((availability(ios,introduced=NA)));



extern NSString * const NSUbiquityIdentityDidChangeNotification __attribute__((availability(ios,introduced=6_0)));


#ifndef _REWRITER_typedef_NSFileManager
#define _REWRITER_typedef_NSFileManager
typedef struct objc_object NSFileManager;
typedef struct {} _objc_exc_NSFileManager;
#endif

struct NSFileManager_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};




// + (NSFileManager *)defaultManager;



// - (nullable NSArray<NSURL *> *)mountedVolumeURLsIncludingResourceValuesForKeys:(nullable NSArray<NSString *> *)propertyKeys options:(NSVolumeEnumerationOptions)options __attribute__((availability(ios,introduced=4_0)));



// - (void)unmountVolumeAtURL:(NSURL *)url options:(NSFileManagerUnmountOptions)mask completionHandler:(void (^)(NSError * _Nullable errorOrNil))completionHandler __attribute__((availability(ios,introduced=NA)));







// - (nullable NSArray<NSURL *> *)contentsOfDirectoryAtURL:(NSURL *)url includingPropertiesForKeys:(nullable NSArray<NSString *> *)keys options:(NSDirectoryEnumerationOptions)mask error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));




// - (NSArray<NSURL *> *)URLsForDirectory:(NSSearchPathDirectory)directory inDomains:(NSSearchPathDomainMask)domainMask __attribute__((availability(ios,introduced=4_0)));





// - (nullable NSURL *)URLForDirectory:(NSSearchPathDirectory)directory inDomain:(NSSearchPathDomainMask)domain appropriateForURL:(nullable NSURL *)url create:(BOOL)shouldCreate error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));



// - (BOOL)getRelationship:(NSURLRelationship *)outRelationship ofDirectoryAtURL:(NSURL *)directoryURL toItemAtURL:(NSURL *)otherURL error:(NSError **)error __attribute__((availability(ios,introduced=8_0)));



// - (BOOL)getRelationship:(NSURLRelationship *)outRelationship ofDirectory:(NSSearchPathDirectory)directory inDomain:(NSSearchPathDomainMask)domainMask toItemAtURL:(NSURL *)url error:(NSError **)error __attribute__((availability(ios,introduced=8_0)));



// - (BOOL)createDirectoryAtURL:(NSURL *)url withIntermediateDirectories:(BOOL)createIntermediates attributes:(nullable NSDictionary<NSString *, id> *)attributes error:(NSError **)error __attribute__((availability(ios,introduced=5_0)));



// - (BOOL)createSymbolicLinkAtURL:(NSURL *)url withDestinationURL:(NSURL *)destURL error:(NSError **)error __attribute__((availability(ios,introduced=5_0)));



// @property (nullable, assign) id <NSFileManagerDelegate> delegate __attribute__((availability(ios,introduced=2_0)));





// - (BOOL)setAttributes:(NSDictionary<NSString *, id> *)attributes ofItemAtPath:(NSString *)path error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));





// - (BOOL)createDirectoryAtPath:(NSString *)path withIntermediateDirectories:(BOOL)createIntermediates attributes:(nullable NSDictionary<NSString *, id> *)attributes error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));





// - (nullable NSArray<NSString *> *)contentsOfDirectoryAtPath:(NSString *)path error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));





// - (nullable NSArray<NSString *> *)subpathsOfDirectoryAtPath:(NSString *)path error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));





// - (nullable NSDictionary<NSString *, id> *)attributesOfItemAtPath:(NSString *)path error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));





// - (nullable NSDictionary<NSString *, id> *)attributesOfFileSystemForPath:(NSString *)path error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));





// - (BOOL)createSymbolicLinkAtPath:(NSString *)path withDestinationPath:(NSString *)destPath error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));





// - (nullable NSString *)destinationOfSymbolicLinkAtPath:(NSString *)path error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));



// - (BOOL)copyItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));
// - (BOOL)moveItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));
// - (BOOL)linkItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));
// - (BOOL)removeItemAtPath:(NSString *)path error:(NSError **)error __attribute__((availability(ios,introduced=2_0)));



// - (BOOL)copyItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));
// - (BOOL)moveItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));
// - (BOOL)linkItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));
// - (BOOL)removeItemAtURL:(NSURL *)URL error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));





// - (BOOL)trashItemAtURL:(NSURL *)url resultingItemURL:(NSURL * _Nullable * _Nullable)outResultingURL error:(NSError **)error __attribute__((availability(ios,unavailable)));



// - (nullable NSDictionary *)fileAttributesAtPath:(NSString *)path traverseLink:(BOOL)yorn __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (BOOL)changeFileAttributes:(NSDictionary *)attributes atPath:(NSString *)path __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (nullable NSArray *)directoryContentsAtPath:(NSString *)path __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (nullable NSDictionary *)fileSystemAttributesAtPath:(NSString *)path __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (nullable NSString *)pathContentOfSymbolicLinkAtPath:(NSString *)path __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (BOOL)createSymbolicLinkAtPath:(NSString *)path pathContent:(NSString *)otherpath __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (BOOL)createDirectoryAtPath:(NSString *)path attributes:(NSDictionary *)attributes __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// @property (readonly, copy) NSString *currentDirectoryPath;
// - (BOOL)changeCurrentDirectoryPath:(NSString *)path;



// - (BOOL)fileExistsAtPath:(NSString *)path;
// - (BOOL)fileExistsAtPath:(NSString *)path isDirectory:(nullable BOOL *)isDirectory;
// - (BOOL)isReadableFileAtPath:(NSString *)path;
// - (BOOL)isWritableFileAtPath:(NSString *)path;
// - (BOOL)isExecutableFileAtPath:(NSString *)path;
// - (BOOL)isDeletableFileAtPath:(NSString *)path;



// - (BOOL)contentsEqualAtPath:(NSString *)path1 andPath:(NSString *)path2;



// - (NSString *)displayNameAtPath:(NSString *)path;



// - (nullable NSArray<NSString *> *)componentsToDisplayForPath:(NSString *)path;



// - (nullable NSDirectoryEnumerator<NSString *> *)enumeratorAtPath:(NSString *)path;





// - (nullable NSDirectoryEnumerator<NSURL *> *)enumeratorAtURL:(NSURL *)url includingPropertiesForKeys:(nullable NSArray<NSString *> *)keys options:(NSDirectoryEnumerationOptions)mask errorHandler:(nullable BOOL (^)(NSURL *url, NSError *error))handler __attribute__((availability(ios,introduced=4_0)));



// - (nullable NSArray<NSString *> *)subpathsAtPath:(NSString *)path;



// - (nullable NSData *)contentsAtPath:(NSString *)path;
// - (BOOL)createFileAtPath:(NSString *)path contents:(nullable NSData *)data attributes:(nullable NSDictionary<NSString *, id> *)attr;



// - (__attribute__((objc_ownership(strong))) const char *)fileSystemRepresentationWithPath:(NSString *)path __attribute__((objc_returns_inner_pointer));



// - (NSString *)stringWithFileSystemRepresentation:(const char *)str length:(NSUInteger)len;
// - (BOOL)replaceItemAtURL:(NSURL *)originalItemURL withItemAtURL:(NSURL *)newItemURL backupItemName:(nullable NSString *)backupItemName options:(NSFileManagerItemReplacementOptions)options resultingItemURL:(NSURL * _Nullable * _Nullable)resultingURL error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));




// - (BOOL)setUbiquitous:(BOOL)flag itemAtURL:(NSURL *)url destinationURL:(NSURL *)destinationURL error:(NSError **)error __attribute__((availability(ios,introduced=5_0)));



// - (BOOL)isUbiquitousItemAtURL:(NSURL *)url __attribute__((availability(ios,introduced=5_0)));



// - (BOOL)startDownloadingUbiquitousItemAtURL:(NSURL *)url error:(NSError **)error __attribute__((availability(ios,introduced=5_0)));



// - (BOOL)evictUbiquitousItemAtURL:(NSURL *)url error:(NSError **)error __attribute__((availability(ios,introduced=5_0)));



// - (nullable NSURL *)URLForUbiquityContainerIdentifier:(nullable NSString *)containerIdentifier __attribute__((availability(ios,introduced=5_0)));



// - (nullable NSURL *)URLForPublishingUbiquitousItemAtURL:(NSURL *)url expirationDate:(NSDate * _Nullable * _Nullable)outDate error:(NSError **)error __attribute__((availability(ios,introduced=5_0)));





// @property (nullable, readonly, copy) id<NSObject,NSCopying,NSCoding> ubiquityIdentityToken __attribute__((availability(ios,introduced=6_0)));



// - (nullable NSURL *)containerURLForSecurityApplicationGroupIdentifier:(NSString *)groupIdentifier __attribute__((availability(ios,introduced=7_0)));


/* @end */




// @interface NSObject (NSCopyLinkMoveHandler)
// - (BOOL)fileManager:(NSFileManager *)fm shouldProceedAfterError:(NSDictionary *)errorInfo __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
// - (void)fileManager:(NSFileManager *)fm willProcessPath:(NSString *)path __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));
/* @end */



// @protocol NSFileManagerDelegate <NSObject>
/* @optional */





// - (BOOL)fileManager:(NSFileManager *)fileManager shouldCopyItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
// - (BOOL)fileManager:(NSFileManager *)fileManager shouldCopyItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL __attribute__((availability(ios,introduced=4_0)));





// - (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error copyingItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
// - (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error copyingItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL __attribute__((availability(ios,introduced=4_0)));





// - (BOOL)fileManager:(NSFileManager *)fileManager shouldMoveItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
// - (BOOL)fileManager:(NSFileManager *)fileManager shouldMoveItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL __attribute__((availability(ios,introduced=4_0)));





// - (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error movingItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
// - (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error movingItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL __attribute__((availability(ios,introduced=4_0)));





// - (BOOL)fileManager:(NSFileManager *)fileManager shouldLinkItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
// - (BOOL)fileManager:(NSFileManager *)fileManager shouldLinkItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL __attribute__((availability(ios,introduced=4_0)));





// - (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error linkingItemAtPath:(NSString *)srcPath toPath:(NSString *)dstPath;
// - (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error linkingItemAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL __attribute__((availability(ios,introduced=4_0)));





// - (BOOL)fileManager:(NSFileManager *)fileManager shouldRemoveItemAtPath:(NSString *)path;
// - (BOOL)fileManager:(NSFileManager *)fileManager shouldRemoveItemAtURL:(NSURL *)URL __attribute__((availability(ios,introduced=4_0)));





// - (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error removingItemAtPath:(NSString *)path;
// - (BOOL)fileManager:(NSFileManager *)fileManager shouldProceedAfterError:(NSError *)error removingItemAtURL:(NSURL *)URL __attribute__((availability(ios,introduced=4_0)));

/* @end */




#ifndef _REWRITER_typedef_NSDirectoryEnumerator
#define _REWRITER_typedef_NSDirectoryEnumerator
typedef struct objc_object NSDirectoryEnumerator;
typedef struct {} _objc_exc_NSDirectoryEnumerator;
#endif

struct NSDirectoryEnumerator_IMPL {
	struct NSEnumerator_IMPL NSEnumerator_IVARS;
};




// @property (nullable, readonly, copy) NSDictionary<NSString *, id> *fileAttributes;
// @property (nullable, readonly, copy) NSDictionary<NSString *, id> *directoryAttributes;

// - (void)skipDescendents;



// @property (readonly) NSUInteger level __attribute__((availability(ios,introduced=4_0)));



// - (void)skipDescendants __attribute__((availability(ios,introduced=4_0)));

/* @end */


extern "C" NSString * const NSFileType;
extern "C" NSString * const NSFileTypeDirectory;
extern "C" NSString * const NSFileTypeRegular;
extern "C" NSString * const NSFileTypeSymbolicLink;
extern "C" NSString * const NSFileTypeSocket;
extern "C" NSString * const NSFileTypeCharacterSpecial;
extern "C" NSString * const NSFileTypeBlockSpecial;
extern "C" NSString * const NSFileTypeUnknown;
extern "C" NSString * const NSFileSize;
extern "C" NSString * const NSFileModificationDate;
extern "C" NSString * const NSFileReferenceCount;
extern "C" NSString * const NSFileDeviceIdentifier;
extern "C" NSString * const NSFileOwnerAccountName;
extern "C" NSString * const NSFileGroupOwnerAccountName;
extern "C" NSString * const NSFilePosixPermissions;
extern "C" NSString * const NSFileSystemNumber;
extern "C" NSString * const NSFileSystemFileNumber;
extern "C" NSString * const NSFileExtensionHidden;
extern "C" NSString * const NSFileHFSCreatorCode;
extern "C" NSString * const NSFileHFSTypeCode;
extern "C" NSString * const NSFileImmutable;
extern "C" NSString * const NSFileAppendOnly;
extern "C" NSString * const NSFileCreationDate;
extern "C" NSString * const NSFileOwnerAccountID;
extern "C" NSString * const NSFileGroupOwnerAccountID;
extern "C" NSString * const NSFileBusy;
extern "C" NSString * const NSFileProtectionKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSFileProtectionNone __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSFileProtectionComplete __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSFileProtectionCompleteUnlessOpen __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSFileProtectionCompleteUntilFirstUserAuthentication __attribute__((availability(ios,introduced=5_0)));

extern "C" NSString * const NSFileSystemSize;
extern "C" NSString * const NSFileSystemFreeSize;
extern "C" NSString * const NSFileSystemNodes;
extern "C" NSString * const NSFileSystemFreeNodes;

// @interface NSDictionary<KeyType, ObjectType> (NSFileAttributes)

// - (unsigned long long)fileSize;
// - (nullable NSDate *)fileModificationDate;
// - (nullable NSString *)fileType;
// - (NSUInteger)filePosixPermissions;
// - (nullable NSString *)fileOwnerAccountName;
// - (nullable NSString *)fileGroupOwnerAccountName;
// - (NSInteger)fileSystemNumber;
// - (NSUInteger)fileSystemFileNumber;
// - (BOOL)fileExtensionHidden;
// - (OSType)fileHFSCreatorCode;
// - (OSType)fileHFSTypeCode;
// - (BOOL)fileIsImmutable;
// - (BOOL)fileIsAppendOnly;
// - (nullable NSDate *)fileCreationDate;
// - (nullable NSNumber *)fileOwnerAccountID;
// - (nullable NSNumber *)fileGroupOwnerAccountID;
/* @end */






typedef NSUInteger NSPointerFunctionsOptions; enum {



    NSPointerFunctionsStrongMemory __attribute__((availability(ios,introduced=6_0))) = (0UL << 0),



    NSPointerFunctionsOpaqueMemory __attribute__((availability(ios,introduced=6_0))) = (2UL << 0),
    NSPointerFunctionsMallocMemory __attribute__((availability(ios,introduced=6_0))) = (3UL << 0),
    NSPointerFunctionsMachVirtualMemory __attribute__((availability(ios,introduced=6_0))) = (4UL << 0),
    NSPointerFunctionsWeakMemory __attribute__((availability(ios,introduced=6_0))) = (5UL << 0),



    NSPointerFunctionsObjectPersonality __attribute__((availability(ios,introduced=6_0))) = (0UL << 8),
    NSPointerFunctionsOpaquePersonality __attribute__((availability(ios,introduced=6_0))) = (1UL << 8),
    NSPointerFunctionsObjectPointerPersonality __attribute__((availability(ios,introduced=6_0))) = (2UL << 8),
    NSPointerFunctionsCStringPersonality __attribute__((availability(ios,introduced=6_0))) = (3UL << 8),
    NSPointerFunctionsStructPersonality __attribute__((availability(ios,introduced=6_0))) = (4UL << 8),
    NSPointerFunctionsIntegerPersonality __attribute__((availability(ios,introduced=6_0))) = (5UL << 8),

    NSPointerFunctionsCopyIn __attribute__((availability(ios,introduced=6_0))) = (1UL << 16),
};

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=6_0)))

#ifndef _REWRITER_typedef_NSPointerFunctions
#define _REWRITER_typedef_NSPointerFunctions
typedef struct objc_object NSPointerFunctions;
typedef struct {} _objc_exc_NSPointerFunctions;
#endif

struct NSPointerFunctions_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// - (instancetype)initWithOptions:(NSPointerFunctionsOptions)options __attribute__((objc_designated_initializer));
// + (NSPointerFunctions *)pointerFunctionsWithOptions:(NSPointerFunctionsOptions)options;


// @property (nullable) NSUInteger (*hashFunction)(const void *item, NSUInteger (* _Nullable size)(const void *item));
// @property (nullable) BOOL (*isEqualFunction)(const void *item1, const void*item2, NSUInteger (* _Nullable size)(const void *item));
// @property (nullable) NSUInteger (*sizeFunction)(const void *item);
// @property (nullable) NSString * _Nullable (*descriptionFunction)(const void *item);


// @property (nullable) void (*relinquishFunction)(const void *item, NSUInteger (* _Nullable size)(const void *item));
// @property (nullable) void * _Nonnull (*acquireFunction)(const void *src, NSUInteger (* _Nullable size)(const void *item), BOOL shouldCopy);


// @property BOOL usesStrongWriteBarrier;
// @property BOOL usesWeakReadAndWriteBarriers;
/* @end */







// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSSet
#define _REWRITER_typedef_NSSet
typedef struct objc_object NSSet;
typedef struct {} _objc_exc_NSSet;
#endif

#ifndef _REWRITER_typedef_NSHashTable
#define _REWRITER_typedef_NSHashTable
typedef struct objc_object NSHashTable;
typedef struct {} _objc_exc_NSHashTable;
#endif








static const NSPointerFunctionsOptions NSHashTableStrongMemory __attribute__((availability(ios,introduced=6_0))) = NSPointerFunctionsStrongMemory;



static const NSPointerFunctionsOptions NSHashTableCopyIn __attribute__((availability(ios,introduced=6_0))) = NSPointerFunctionsCopyIn;
static const NSPointerFunctionsOptions NSHashTableObjectPointerPersonality __attribute__((availability(ios,introduced=6_0))) = NSPointerFunctionsObjectPointerPersonality;
static const NSPointerFunctionsOptions NSHashTableWeakMemory __attribute__((availability(ios,introduced=6_0))) = NSPointerFunctionsWeakMemory;

typedef NSUInteger NSHashTableOptions;

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=6_0)))

#ifndef _REWRITER_typedef_NSHashTable
#define _REWRITER_typedef_NSHashTable
typedef struct objc_object NSHashTable;
typedef struct {} _objc_exc_NSHashTable;
#endif

struct NSHashTable_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// - (instancetype)initWithOptions:(NSPointerFunctionsOptions)options capacity:(NSUInteger)initialCapacity __attribute__((objc_designated_initializer));
// - (instancetype)initWithPointerFunctions:(NSPointerFunctions *)functions capacity:(NSUInteger)initialCapacity __attribute__((objc_designated_initializer));



// + (NSHashTable<ObjectType> *)hashTableWithOptions:(NSPointerFunctionsOptions)options;





// + (NSHashTable<ObjectType> *)weakObjectsHashTable __attribute__((availability(ios,introduced=6_0)));



// @property (readonly, copy) NSPointerFunctions *pointerFunctions;

// @property (readonly) NSUInteger count;
// - (nullable ObjectType)member:(nullable ObjectType)object;
// - (NSEnumerator<ObjectType> *)objectEnumerator;

// - (void)addObject:(nullable ObjectType)object;
// - (void)removeObject:(nullable ObjectType)object;

// - (void)removeAllObjects;

// @property (readonly, copy) NSArray<ObjectType> *allObjects;

// @property (nullable, nonatomic, readonly) ObjectType anyObject;
// - (BOOL)containsObject:(nullable ObjectType)anObject;

// - (BOOL)intersectsHashTable:(NSHashTable<ObjectType> *)other;
// - (BOOL)isEqualToHashTable:(NSHashTable<ObjectType> *)other;
// - (BOOL)isSubsetOfHashTable:(NSHashTable<ObjectType> *)other;

// - (void)intersectHashTable:(NSHashTable<ObjectType> *)other;
// - (void)unionHashTable:(NSHashTable<ObjectType> *)other;
// - (void)minusHashTable:(NSHashTable<ObjectType> *)other;

// @property (readonly, copy) NSSet<ObjectType> *setRepresentation;

/* @end */

// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

// @class NSDate;
#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

// @class NSNumber;
#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
typedef struct objc_object NSNumber;
typedef struct {} _objc_exc_NSNumber;
#endif

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @class NSURL;
#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif








extern "C" NSString * const NSHTTPCookieName;





extern "C" NSString * const NSHTTPCookieValue;





extern "C" NSString * const NSHTTPCookieOriginURL;





extern "C" NSString * const NSHTTPCookieVersion;





extern "C" NSString * const NSHTTPCookieDomain;





extern "C" NSString * const NSHTTPCookiePath;





extern "C" NSString * const NSHTTPCookieSecure;





extern "C" NSString * const NSHTTPCookieExpires;





extern "C" NSString * const NSHTTPCookieComment;





extern "C" NSString * const NSHTTPCookieCommentURL;





extern "C" NSString * const NSHTTPCookieDiscard;





extern "C" NSString * const NSHTTPCookieMaximumAge;





extern "C" NSString * const NSHTTPCookiePort;


// @class NSHTTPCookieInternal;
#ifndef _REWRITER_typedef_NSHTTPCookieInternal
#define _REWRITER_typedef_NSHTTPCookieInternal
typedef struct objc_object NSHTTPCookieInternal;
typedef struct {} _objc_exc_NSHTTPCookieInternal;
#endif


#ifndef _REWRITER_typedef_NSHTTPCookie
#define _REWRITER_typedef_NSHTTPCookie
typedef struct objc_object NSHTTPCookie;
typedef struct {} _objc_exc_NSHTTPCookie;
#endif

struct NSHTTPCookie_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSHTTPCookieInternal *__strong _cookiePrivate;
};

// - (nullable instancetype)initWithProperties:(NSDictionary<NSString *, id> *)properties;
// + (nullable NSHTTPCookie *)cookieWithProperties:(NSDictionary<NSString *, id> *)properties;
// + (NSDictionary<NSString *, NSString *> *)requestHeaderFieldsWithCookies:(NSArray<NSHTTPCookie *> *)cookies;
// + (NSArray<NSHTTPCookie *> *)cookiesWithResponseHeaderFields:(NSDictionary<NSString *, NSString *> *)headerFields forURL:(NSURL *)URL;
// @property (nullable, readonly, copy) NSDictionary<NSString *, id> *properties;
// @property (readonly) NSUInteger version;






// @property (readonly, copy) NSString *name;






// @property (readonly, copy) NSString *value;
// @property (nullable, readonly, copy) NSDate *expiresDate;
// @property (readonly, getter=isSessionOnly) BOOL sessionOnly;
// @property (readonly, copy) NSString *domain;
// @property (readonly, copy) NSString *path;
// @property (readonly, getter=isSecure) BOOL secure;
// @property (readonly, getter=isHTTPOnly) BOOL HTTPOnly;
// @property (nullable, readonly, copy) NSString *comment;
// @property (nullable, readonly, copy) NSURL *commentURL;
// @property (nullable, readonly, copy) NSArray<NSNumber *> *portList;

/* @end */

// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

// @class NSHTTPCookie;
#ifndef _REWRITER_typedef_NSHTTPCookie
#define _REWRITER_typedef_NSHTTPCookie
typedef struct objc_object NSHTTPCookie;
typedef struct {} _objc_exc_NSHTTPCookie;
#endif

// @class NSURL;
#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

// @class NSDate;
#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

// @class NSURLSessionTask;
#ifndef _REWRITER_typedef_NSURLSessionTask
#define _REWRITER_typedef_NSURLSessionTask
typedef struct objc_object NSURLSessionTask;
typedef struct {} _objc_exc_NSURLSessionTask;
#endif

// @class NSSortDescriptor;
#ifndef _REWRITER_typedef_NSSortDescriptor
#define _REWRITER_typedef_NSSortDescriptor
typedef struct objc_object NSSortDescriptor;
typedef struct {} _objc_exc_NSSortDescriptor;
#endif

typedef NSUInteger NSHTTPCookieAcceptPolicy; enum {
    NSHTTPCookieAcceptPolicyAlways,
    NSHTTPCookieAcceptPolicyNever,
    NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain
};


// @class NSHTTPCookieStorageInternal;
#ifndef _REWRITER_typedef_NSHTTPCookieStorageInternal
#define _REWRITER_typedef_NSHTTPCookieStorageInternal
typedef struct objc_object NSHTTPCookieStorageInternal;
typedef struct {} _objc_exc_NSHTTPCookieStorageInternal;
#endif


#ifndef _REWRITER_typedef_NSHTTPCookieStorage
#define _REWRITER_typedef_NSHTTPCookieStorage
typedef struct objc_object NSHTTPCookieStorage;
typedef struct {} _objc_exc_NSHTTPCookieStorage;
#endif

struct NSHTTPCookieStorage_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSHTTPCookieStorageInternal *__strong _internal;
};

// + (NSHTTPCookieStorage *)sharedHTTPCookieStorage;
// + (NSHTTPCookieStorage *)sharedCookieStorageForGroupContainerIdentifier:(NSString *)identifier __attribute__((availability(ios,introduced=9_0)));






// @property (nullable , readonly, copy) NSArray<NSHTTPCookie *> *cookies;







// - (void)setCookie:(NSHTTPCookie *)cookie;





// - (void)deleteCookie:(NSHTTPCookie *)cookie;





// - (void)removeCookiesSinceDate:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));
// - (nullable NSArray<NSHTTPCookie *> *)cookiesForURL:(NSURL *)URL;
// - (void)setCookies:(NSArray<NSHTTPCookie *> *)cookies forURL:(nullable NSURL *)URL mainDocumentURL:(nullable NSURL *)mainDocumentURL;






// @property NSHTTPCookieAcceptPolicy cookieAcceptPolicy;







// - (NSArray<NSHTTPCookie *> *)sortedCookiesUsingDescriptors:(NSArray<NSSortDescriptor *> *) sortOrder __attribute__((availability(ios,introduced=5_0)));

/* @end */


// @interface NSHTTPCookieStorage (NSURLSessionTaskAdditions)
// - (void)storeCookies:(NSArray<NSHTTPCookie *> *)cookies forTask:(NSURLSessionTask *)task __attribute__((availability(ios,introduced=8_0)));
// - (void)getCookiesForTask:(NSURLSessionTask *)task completionHandler:(void (^) (NSArray<NSHTTPCookie *> * _Nullable cookies))completionHandler __attribute__((availability(ios,introduced=8_0)));
/* @end */








extern "C" NSString * const NSHTTPCookieManagerAcceptPolicyChangedNotification;





extern "C" NSString * const NSHTTPCookieManagerCookiesChangedNotification;

#ifndef _REWRITER_typedef_NSIndexPath
#define _REWRITER_typedef_NSIndexPath
typedef struct objc_object NSIndexPath;
typedef struct {} _objc_exc_NSIndexPath;
#endif

struct NSIndexPath_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSUInteger *_indexes;
	NSUInteger _length;
	void *_reserved;
};


// + (instancetype)indexPathWithIndex:(NSUInteger)index;
// + (instancetype)indexPathWithIndexes:(const NSUInteger [])indexes length:(NSUInteger)length;

// - (instancetype)initWithIndexes:(const NSUInteger [])indexes length:(NSUInteger)length __attribute__((objc_designated_initializer));

// - (instancetype)initWithIndex:(NSUInteger)index;


// - (NSIndexPath *)indexPathByAddingIndex:(NSUInteger)index;
// - (NSIndexPath *)indexPathByRemovingLastIndex;

// - (NSUInteger)indexAtPosition:(NSUInteger)position;
// @property (readonly) NSUInteger length;
// - (void)getIndexes:(NSUInteger *)indexes range:(NSRange)positionRange __attribute__((availability(ios,introduced=7_0)));


// - (NSComparisonResult)compare:(NSIndexPath *)otherObject;

/* @end */


// @interface NSIndexPath (NSDeprecated)

// - (void)getIndexes:(NSUInteger *)indexes;
/* @end */


#ifndef _REWRITER_typedef_NSIndexSet
#define _REWRITER_typedef_NSIndexSet
typedef struct objc_object NSIndexSet;
typedef struct {} _objc_exc_NSIndexSet;
#endif

struct NSIndexSet_IMPL {
	struct NSObject_IMPL NSObject_IVARS;

	struct  {
	NSUInteger _isEmpty : 1;
	NSUInteger _hasSingleRange : 1;
	NSUInteger _cacheValid : 1;
	NSUInteger _reservedArrayBinderController : 29;
	} _indexSetFlags;

	union  {

	struct  {
	NSRange _range;
	} _singleRange;

	struct  {
	void *_data;
	void *_reserved;
	} _multipleRanges;
	} _internal;
};


// + (instancetype)indexSet;
// + (instancetype)indexSetWithIndex:(NSUInteger)value;
// + (instancetype)indexSetWithIndexesInRange:(NSRange)range;

// - (instancetype)initWithIndexesInRange:(NSRange)range __attribute__((objc_designated_initializer));
// - (instancetype)initWithIndexSet:(NSIndexSet *)indexSet __attribute__((objc_designated_initializer));

// - (instancetype)initWithIndex:(NSUInteger)value;

// - (BOOL)isEqualToIndexSet:(NSIndexSet *)indexSet;

// @property (readonly) NSUInteger count;



// @property (readonly) NSUInteger firstIndex;
// @property (readonly) NSUInteger lastIndex;
// - (NSUInteger)indexGreaterThanIndex:(NSUInteger)value;
// - (NSUInteger)indexLessThanIndex:(NSUInteger)value;
// - (NSUInteger)indexGreaterThanOrEqualToIndex:(NSUInteger)value;
// - (NSUInteger)indexLessThanOrEqualToIndex:(NSUInteger)value;



// - (NSUInteger)getIndexes:(NSUInteger *)indexBuffer maxCount:(NSUInteger)bufferSize inIndexRange:(nullable NSRangePointer)range;

// - (NSUInteger)countOfIndexesInRange:(NSRange)range __attribute__((availability(ios,introduced=2_0)));

// - (BOOL)containsIndex:(NSUInteger)value;
// - (BOOL)containsIndexesInRange:(NSRange)range;
// - (BOOL)containsIndexes:(NSIndexSet *)indexSet;

// - (BOOL)intersectsIndexesInRange:(NSRange)range;

// - (void)enumerateIndexesUsingBlock:(void (^)(NSUInteger idx, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));
// - (void)enumerateIndexesWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(NSUInteger idx, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));
// - (void)enumerateIndexesInRange:(NSRange)range options:(NSEnumerationOptions)opts usingBlock:(void (^)(NSUInteger idx, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));

// - (NSUInteger)indexPassingTest:(BOOL (^)(NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));
// - (NSUInteger)indexWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));
// - (NSUInteger)indexInRange:(NSRange)range options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));

// - (NSIndexSet *)indexesPassingTest:(BOOL (^)(NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));
// - (NSIndexSet *)indexesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));
// - (NSIndexSet *)indexesInRange:(NSRange)range options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger idx, BOOL *stop))predicate __attribute__((availability(ios,introduced=4_0)));






// - (void)enumerateRangesUsingBlock:(void (^)(NSRange range, BOOL *stop))block __attribute__((availability(ios,introduced=5_0)));
// - (void)enumerateRangesWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(NSRange range, BOOL *stop))block __attribute__((availability(ios,introduced=5_0)));
// - (void)enumerateRangesInRange:(NSRange)range options:(NSEnumerationOptions)opts usingBlock:(void (^)(NSRange range, BOOL *stop))block __attribute__((availability(ios,introduced=5_0)));

/* @end */



#ifndef _REWRITER_typedef_NSMutableIndexSet
#define _REWRITER_typedef_NSMutableIndexSet
typedef struct objc_object NSMutableIndexSet;
typedef struct {} _objc_exc_NSMutableIndexSet;
#endif

struct NSMutableIndexSet_IMPL {
	struct NSIndexSet_IMPL NSIndexSet_IVARS;
	void *_reserved;
};


// - (void)addIndexes:(NSIndexSet *)indexSet;
// - (void)removeIndexes:(NSIndexSet *)indexSet;
// - (void)removeAllIndexes;
// - (void)addIndex:(NSUInteger)value;
// - (void)removeIndex:(NSUInteger)value;
// - (void)addIndexesInRange:(NSRange)range;
// - (void)removeIndexesInRange:(NSRange)range;



// - (void)shiftIndexesStartingAtIndex:(NSUInteger)index by:(NSInteger)delta;

/* @end */








// @class NSMethodSignature;
#ifndef _REWRITER_typedef_NSMethodSignature
#define _REWRITER_typedef_NSMethodSignature
typedef struct objc_object NSMethodSignature;
typedef struct {} _objc_exc_NSMethodSignature;
#endif




__attribute__((availability(swift, unavailable, message="NSInvocation and related APIs not available")))

#ifndef _REWRITER_typedef_NSInvocation
#define _REWRITER_typedef_NSInvocation
typedef struct objc_object NSInvocation;
typedef struct {} _objc_exc_NSInvocation;
#endif

struct NSInvocation_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *_frame;
	void *_retdata;
	__strong id _signature;
	__strong id _container;
	uint8_t _retainedArgs;
	uint8_t _reserved[15];
};


// + (NSInvocation *)invocationWithMethodSignature:(NSMethodSignature *)sig;

// @property (readonly, retain) NSMethodSignature *methodSignature;

// - (void)retainArguments;
// @property (readonly) BOOL argumentsRetained;

// @property (nullable, assign) id target;
// @property SEL selector;

// - (void)getReturnValue:(void *)retLoc;
// - (void)setReturnValue:(void *)retLoc;

// - (void)getArgument:(void *)argumentLocation atIndex:(NSInteger)idx;
// - (void)setArgument:(void *)argumentLocation atIndex:(NSInteger)idx;

// - (void)invoke;
// - (void)invokeWithTarget:(id)target;

/* @end */








// @class NSError;
#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSOutputStream
#define _REWRITER_typedef_NSOutputStream
typedef struct objc_object NSOutputStream;
typedef struct {} _objc_exc_NSOutputStream;
#endif

#ifndef _REWRITER_typedef_NSInputStream
#define _REWRITER_typedef_NSInputStream
typedef struct objc_object NSInputStream;
typedef struct {} _objc_exc_NSInputStream;
#endif

#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif




typedef NSUInteger NSJSONReadingOptions; enum {
    NSJSONReadingMutableContainers = (1UL << 0),
    NSJSONReadingMutableLeaves = (1UL << 1),
    NSJSONReadingAllowFragments = (1UL << 2)
} __attribute__((availability(ios,introduced=5_0)));

typedef NSUInteger NSJSONWritingOptions; enum {
    NSJSONWritingPrettyPrinted = (1UL << 0)
} __attribute__((availability(ios,introduced=5_0)));
__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSJSONSerialization
#define _REWRITER_typedef_NSJSONSerialization
typedef struct objc_object NSJSONSerialization;
typedef struct {} _objc_exc_NSJSONSerialization;
#endif

struct NSJSONSerialization_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *reserved[6];
};

// + (BOOL)isValidJSONObject:(id)obj;



// + (nullable NSData *)dataWithJSONObject:(id)obj options:(NSJSONWritingOptions)opt error:(NSError **)error;




// + (nullable id)JSONObjectWithData:(NSData *)data options:(NSJSONReadingOptions)opt error:(NSError **)error;



// + (NSInteger)writeJSONObject:(id)obj toStream:(NSOutputStream *)stream options:(NSJSONWritingOptions)opt error:(NSError **)error;



// + (nullable id)JSONObjectWithStream:(NSInputStream *)stream options:(NSJSONReadingOptions)opt error:(NSError **)error;

/* @end */








// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSIndexSet
#define _REWRITER_typedef_NSIndexSet
typedef struct objc_object NSIndexSet;
typedef struct {} _objc_exc_NSIndexSet;
#endif

#ifndef _REWRITER_typedef_NSSet
#define _REWRITER_typedef_NSSet
typedef struct objc_object NSSet;
typedef struct {} _objc_exc_NSSet;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif






__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSOrderedSet
#define _REWRITER_typedef_NSOrderedSet
typedef struct objc_object NSOrderedSet;
typedef struct {} _objc_exc_NSOrderedSet;
#endif

struct NSOrderedSet_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly) NSUInteger count;
// - (ObjectType)objectAtIndex:(NSUInteger)idx;
// - (NSUInteger)indexOfObject:(ObjectType)object;
// - (instancetype)init __attribute__((objc_designated_initializer));
// - (instancetype)initWithObjects:(const ObjectType [])objects count:(NSUInteger)cnt __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSOrderedSet<ObjectType> (NSExtendedOrderedSet)

// - (void)getObjects:(ObjectType __attribute__((objc_ownership(none))) [])objects range:(NSRange)range;
// - (NSArray<ObjectType> *)objectsAtIndexes:(NSIndexSet *)indexes;
// @property (nullable, nonatomic, readonly) ObjectType firstObject;
// @property (nullable, nonatomic, readonly) ObjectType lastObject;

// - (BOOL)isEqualToOrderedSet:(NSOrderedSet<ObjectType> *)other;

// - (BOOL)containsObject:(ObjectType)object;
// - (BOOL)intersectsOrderedSet:(NSOrderedSet<ObjectType> *)other;
// - (BOOL)intersectsSet:(NSSet<ObjectType> *)set;

// - (BOOL)isSubsetOfOrderedSet:(NSOrderedSet<ObjectType> *)other;
// - (BOOL)isSubsetOfSet:(NSSet<ObjectType> *)set;

// - (ObjectType)objectAtIndexedSubscript:(NSUInteger)idx __attribute__((availability(ios,introduced=6_0)));

// - (NSEnumerator<ObjectType> *)objectEnumerator;
// - (NSEnumerator<ObjectType> *)reverseObjectEnumerator;

// @property (readonly, copy) NSOrderedSet<ObjectType> *reversedOrderedSet;







// @property (readonly, strong) NSArray<ObjectType> *array;
// @property (readonly, strong) NSSet<ObjectType> *set;

// - (void)enumerateObjectsUsingBlock:(void (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;
// - (void)enumerateObjectsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;
// - (void)enumerateObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts usingBlock:(void (^)(ObjectType obj, NSUInteger idx, BOOL *stop))block;

// - (NSUInteger)indexOfObjectPassingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
// - (NSUInteger)indexOfObjectWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
// - (NSUInteger)indexOfObjectAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;

// - (NSIndexSet *)indexesOfObjectsPassingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
// - (NSIndexSet *)indexesOfObjectsWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;
// - (NSIndexSet *)indexesOfObjectsAtIndexes:(NSIndexSet *)s options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(ObjectType obj, NSUInteger idx, BOOL *stop))predicate;

// - (NSUInteger)indexOfObject:(ObjectType)object inSortedRange:(NSRange)range options:(NSBinarySearchingOptions)opts usingComparator:(NSComparator)cmp;

// - (NSArray<ObjectType> *)sortedArrayUsingComparator:(NSComparator)cmptr;
// - (NSArray<ObjectType> *)sortedArrayWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;

// @property (readonly, copy) NSString *description;
// - (NSString *)descriptionWithLocale:(nullable id)locale;
// - (NSString *)descriptionWithLocale:(nullable id)locale indent:(NSUInteger)level;

/* @end */


// @interface NSOrderedSet<ObjectType> (NSOrderedSetCreation)

// + (instancetype)orderedSet;
// + (instancetype)orderedSetWithObject:(ObjectType)object;
// + (instancetype)orderedSetWithObjects:(const ObjectType [])objects count:(NSUInteger)cnt;
// + (instancetype)orderedSetWithObjects:(ObjectType)firstObj, ... __attribute__((sentinel(0,1)));
// + (instancetype)orderedSetWithOrderedSet:(NSOrderedSet<ObjectType> *)set;
// + (instancetype)orderedSetWithOrderedSet:(NSOrderedSet<ObjectType> *)set range:(NSRange)range copyItems:(BOOL)flag;
// + (instancetype)orderedSetWithArray:(NSArray<ObjectType> *)array;
// + (instancetype)orderedSetWithArray:(NSArray<ObjectType> *)array range:(NSRange)range copyItems:(BOOL)flag;
// + (instancetype)orderedSetWithSet:(NSSet<ObjectType> *)set;
// + (instancetype)orderedSetWithSet:(NSSet<ObjectType> *)set copyItems:(BOOL)flag;

// - (instancetype)initWithObject:(ObjectType)object;
// - (instancetype)initWithObjects:(ObjectType)firstObj, ... __attribute__((sentinel(0,1)));
// - (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType> *)set;
// - (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType> *)set copyItems:(BOOL)flag;
// - (instancetype)initWithOrderedSet:(NSOrderedSet<ObjectType> *)set range:(NSRange)range copyItems:(BOOL)flag;
// - (instancetype)initWithArray:(NSArray<ObjectType> *)array;
// - (instancetype)initWithArray:(NSArray<ObjectType> *)set copyItems:(BOOL)flag;
// - (instancetype)initWithArray:(NSArray<ObjectType> *)set range:(NSRange)range copyItems:(BOOL)flag;
// - (instancetype)initWithSet:(NSSet<ObjectType> *)set;
// - (instancetype)initWithSet:(NSSet<ObjectType> *)set copyItems:(BOOL)flag;

/* @end */




__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSMutableOrderedSet
#define _REWRITER_typedef_NSMutableOrderedSet
typedef struct objc_object NSMutableOrderedSet;
typedef struct {} _objc_exc_NSMutableOrderedSet;
#endif

struct NSMutableOrderedSet_IMPL {
	struct NSOrderedSet_IMPL NSOrderedSet_IVARS;
};


// - (void)insertObject:(ObjectType)object atIndex:(NSUInteger)idx;
// - (void)removeObjectAtIndex:(NSUInteger)idx;
// - (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(ObjectType)object;
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));
// - (instancetype)init __attribute__((objc_designated_initializer));
// - (instancetype)initWithCapacity:(NSUInteger)numItems __attribute__((objc_designated_initializer));

/* @end */


// @interface NSMutableOrderedSet<ObjectType> (NSExtendedMutableOrderedSet)

// - (void)addObject:(ObjectType)object;
// - (void)addObjects:(const ObjectType [])objects count:(NSUInteger)count;
// - (void)addObjectsFromArray:(NSArray<ObjectType> *)array;

// - (void)exchangeObjectAtIndex:(NSUInteger)idx1 withObjectAtIndex:(NSUInteger)idx2;
// - (void)moveObjectsAtIndexes:(NSIndexSet *)indexes toIndex:(NSUInteger)idx;

// - (void)insertObjects:(NSArray<ObjectType> *)objects atIndexes:(NSIndexSet *)indexes;

// - (void)setObject:(ObjectType)obj atIndex:(NSUInteger)idx;
// - (void)setObject:(ObjectType)obj atIndexedSubscript:(NSUInteger)idx __attribute__((availability(ios,introduced=6_0)));

// - (void)replaceObjectsInRange:(NSRange)range withObjects:(const ObjectType [])objects count:(NSUInteger)count;
// - (void)replaceObjectsAtIndexes:(NSIndexSet *)indexes withObjects:(NSArray<ObjectType> *)objects;

// - (void)removeObjectsInRange:(NSRange)range;
// - (void)removeObjectsAtIndexes:(NSIndexSet *)indexes;
// - (void)removeAllObjects;

// - (void)removeObject:(ObjectType)object;
// - (void)removeObjectsInArray:(NSArray<ObjectType> *)array;

// - (void)intersectOrderedSet:(NSOrderedSet<ObjectType> *)other;
// - (void)minusOrderedSet:(NSOrderedSet<ObjectType> *)other;
// - (void)unionOrderedSet:(NSOrderedSet<ObjectType> *)other;

// - (void)intersectSet:(NSSet<ObjectType> *)other;
// - (void)minusSet:(NSSet<ObjectType> *)other;
// - (void)unionSet:(NSSet<ObjectType> *)other;


// - (void)sortUsingComparator:(NSComparator)cmptr;
// - (void)sortWithOptions:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;
// - (void)sortRange:(NSRange)range options:(NSSortOptions)opts usingComparator:(NSComparator)cmptr;


/* @end */


// @interface NSMutableOrderedSet<ObjectType> (NSMutableOrderedSetCreation)

// + (instancetype)orderedSetWithCapacity:(NSUInteger)numItems;

/* @end */



// @class NSError;
#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

extern "C" NSString *const NSUndefinedKeyException;



extern "C" NSString *const NSAverageKeyValueOperator;
extern "C" NSString *const NSCountKeyValueOperator;
extern "C" NSString *const NSDistinctUnionOfArraysKeyValueOperator;
extern "C" NSString *const NSDistinctUnionOfObjectsKeyValueOperator;
extern "C" NSString *const NSDistinctUnionOfSetsKeyValueOperator;
extern "C" NSString *const NSMaximumKeyValueOperator;
extern "C" NSString *const NSMinimumKeyValueOperator;
extern "C" NSString *const NSSumKeyValueOperator;
extern "C" NSString *const NSUnionOfArraysKeyValueOperator;
extern "C" NSString *const NSUnionOfObjectsKeyValueOperator;
extern "C" NSString *const NSUnionOfSetsKeyValueOperator;

// @interface NSObject(NSKeyValueCoding)



// + (BOOL)accessInstanceVariablesDirectly;
// - (nullable id)valueForKey:(NSString *)key;
// - (void)setValue:(nullable id)value forKey:(NSString *)key;





// - (BOOL)validateValue:(inout id _Nullable * _Nonnull)ioValue forKey:(NSString *)inKey error:(out NSError **)outError;
// - (NSMutableArray *)mutableArrayValueForKey:(NSString *)key;
// - (NSMutableOrderedSet *)mutableOrderedSetValueForKey:(NSString *)key __attribute__((availability(ios,introduced=5_0)));
// - (NSMutableSet *)mutableSetValueForKey:(NSString *)key;



// - (nullable id)valueForKeyPath:(NSString *)keyPath;
// - (void)setValue:(nullable id)value forKeyPath:(NSString *)keyPath;
// - (BOOL)validateValue:(inout id _Nullable * _Nonnull)ioValue forKeyPath:(NSString *)inKeyPath error:(out NSError **)outError;
// - (NSMutableArray *)mutableArrayValueForKeyPath:(NSString *)keyPath;
// - (NSMutableOrderedSet *)mutableOrderedSetValueForKeyPath:(NSString *)keyPath __attribute__((availability(ios,introduced=5_0)));
// - (NSMutableSet *)mutableSetValueForKeyPath:(NSString *)keyPath;



// - (nullable id)valueForUndefinedKey:(NSString *)key;



// - (void)setValue:(nullable id)value forUndefinedKey:(NSString *)key;



// - (void)setNilValueForKey:(NSString *)key;



// - (NSDictionary<NSString *, id> *)dictionaryWithValuesForKeys:(NSArray<NSString *> *)keys;



// - (void)setValuesForKeysWithDictionary:(NSDictionary<NSString *, id> *)keyedValues;

/* @end */


// @interface NSArray<ObjectType>(NSKeyValueCoding)



// - (id)valueForKey:(NSString *)key;



// - (void)setValue:(nullable id)value forKey:(NSString *)key;

/* @end */


// @interface NSDictionary<KeyType, ObjectType>(NSKeyValueCoding)



// - (nullable ObjectType)valueForKey:(NSString *)key;

/* @end */


// @interface NSMutableDictionary<KeyType, ObjectType>(NSKeyValueCoding)



// - (void)setValue:(nullable ObjectType)value forKey:(NSString *)key;

/* @end */


// @interface NSOrderedSet<ObjectType>(NSKeyValueCoding)



// - (id)valueForKey:(NSString *)key __attribute__((availability(ios,introduced=5_0)));



// - (void)setValue:(nullable id)value forKey:(NSString *)key __attribute__((availability(ios,introduced=5_0)));

/* @end */


// @interface NSSet<ObjectType>(NSKeyValueCoding)



// - (id)valueForKey:(NSString *)key;



// - (void)setValue:(nullable id)value forKey:(NSString *)key;

/* @end */

// @class NSIndexSet;
#ifndef _REWRITER_typedef_NSIndexSet
#define _REWRITER_typedef_NSIndexSet
typedef struct objc_object NSIndexSet;
typedef struct {} _objc_exc_NSIndexSet;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif






typedef NSUInteger NSKeyValueObservingOptions; enum {



    NSKeyValueObservingOptionNew = 0x01,
    NSKeyValueObservingOptionOld = 0x02,



    NSKeyValueObservingOptionInitial __attribute__((availability(ios,introduced=2_0))) = 0x04,





    NSKeyValueObservingOptionPrior __attribute__((availability(ios,introduced=2_0))) = 0x08

};



typedef NSUInteger NSKeyValueChange; enum {
    NSKeyValueChangeSetting = 1,
    NSKeyValueChangeInsertion = 2,
    NSKeyValueChangeRemoval = 3,
    NSKeyValueChangeReplacement = 4,
};



typedef NSUInteger NSKeyValueSetMutationKind; enum {
    NSKeyValueUnionSetMutation = 1,
    NSKeyValueMinusSetMutation = 2,
    NSKeyValueIntersectSetMutation = 3,
    NSKeyValueSetSetMutation = 4
};



extern "C" NSString *const NSKeyValueChangeKindKey;
extern "C" NSString *const NSKeyValueChangeNewKey;
extern "C" NSString *const NSKeyValueChangeOldKey;
extern "C" NSString *const NSKeyValueChangeIndexesKey;
extern "C" NSString *const NSKeyValueChangeNotificationIsPriorKey __attribute__((availability(ios,introduced=2_0)));

// @interface NSObject(NSKeyValueObserving)
// - (void)observeValueForKeyPath:(nullable NSString *)keyPath ofObject:(nullable id)object change:(nullable NSDictionary<NSString*, id> *)change context:(nullable void *)context;

/* @end */


// @interface NSObject(NSKeyValueObserverRegistration)



// - (void)addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(nullable void *)context;
// - (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath context:(nullable void *)context __attribute__((availability(ios,introduced=5_0)));
// - (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath;

/* @end */


// @interface NSArray<ObjectType>(NSKeyValueObserverRegistration)



// - (void)addObserver:(NSObject *)observer toObjectsAtIndexes:(NSIndexSet *)indexes forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(nullable void *)context;
// - (void)removeObserver:(NSObject *)observer fromObjectsAtIndexes:(NSIndexSet *)indexes forKeyPath:(NSString *)keyPath context:(nullable void *)context __attribute__((availability(ios,introduced=5_0)));
// - (void)removeObserver:(NSObject *)observer fromObjectsAtIndexes:(NSIndexSet *)indexes forKeyPath:(NSString *)keyPath;



// - (void)addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(nullable void *)context;
// - (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath context:(nullable void *)context __attribute__((availability(ios,introduced=5_0)));
// - (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath;

/* @end */


// @interface NSOrderedSet<ObjectType>(NSKeyValueObserverRegistration)



// - (void)addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(nullable void *)context;
// - (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath context:(nullable void *)context __attribute__((availability(ios,introduced=5_0)));
// - (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath;

/* @end */


// @interface NSSet<ObjectType>(NSKeyValueObserverRegistration)



// - (void)addObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath options:(NSKeyValueObservingOptions)options context:(nullable void *)context;
// - (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath context:(nullable void *)context __attribute__((availability(ios,introduced=5_0)));
// - (void)removeObserver:(NSObject *)observer forKeyPath:(NSString *)keyPath;

/* @end */


// @interface NSObject(NSKeyValueObserverNotification)







// - (void)willChangeValueForKey:(NSString *)key;
// - (void)didChangeValueForKey:(NSString *)key;







// - (void)willChange:(NSKeyValueChange)changeKind valuesAtIndexes:(NSIndexSet *)indexes forKey:(NSString *)key;
// - (void)didChange:(NSKeyValueChange)changeKind valuesAtIndexes:(NSIndexSet *)indexes forKey:(NSString *)key;
// - (void)willChangeValueForKey:(NSString *)key withSetMutation:(NSKeyValueSetMutationKind)mutationKind usingObjects:(NSSet *)objects;
// - (void)didChangeValueForKey:(NSString *)key withSetMutation:(NSKeyValueSetMutationKind)mutationKind usingObjects:(NSSet *)objects;

/* @end */


// @interface NSObject(NSKeyValueObservingCustomization)
// + (NSSet<NSString *> *)keyPathsForValuesAffectingValueForKey:(NSString *)key __attribute__((availability(ios,introduced=2_0)));



// + (BOOL)automaticallyNotifiesObserversForKey:(NSString *)key;



// @property (nullable) void *observationInfo __attribute__((objc_returns_inner_pointer));

/* @end */













// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSInputStream
#define _REWRITER_typedef_NSInputStream
typedef struct objc_object NSInputStream;
typedef struct {} _objc_exc_NSInputStream;
#endif

#ifndef _REWRITER_typedef_NSOutputStream
#define _REWRITER_typedef_NSOutputStream
typedef struct objc_object NSOutputStream;
typedef struct {} _objc_exc_NSOutputStream;
#endif




typedef NSUInteger NSPropertyListMutabilityOptions; enum {
    NSPropertyListImmutable = kCFPropertyListImmutable,
    NSPropertyListMutableContainers = kCFPropertyListMutableContainers,
    NSPropertyListMutableContainersAndLeaves = kCFPropertyListMutableContainersAndLeaves
};

typedef NSUInteger NSPropertyListFormat; enum {
    NSPropertyListOpenStepFormat = kCFPropertyListOpenStepFormat,
    NSPropertyListXMLFormat_v1_0 = kCFPropertyListXMLFormat_v1_0,
    NSPropertyListBinaryFormat_v1_0 = kCFPropertyListBinaryFormat_v1_0
};

typedef NSPropertyListMutabilityOptions NSPropertyListReadOptions;
typedef NSUInteger NSPropertyListWriteOptions;


#ifndef _REWRITER_typedef_NSPropertyListSerialization
#define _REWRITER_typedef_NSPropertyListSerialization
typedef struct objc_object NSPropertyListSerialization;
typedef struct {} _objc_exc_NSPropertyListSerialization;
#endif

struct NSPropertyListSerialization_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *reserved[6];
};




// + (BOOL)propertyList:(id)plist isValidForFormat:(NSPropertyListFormat)format;



// + (nullable NSData *)dataWithPropertyList:(id)plist format:(NSPropertyListFormat)format options:(NSPropertyListWriteOptions)opt error:(out NSError **)error __attribute__((availability(ios,introduced=4_0)));



// + (NSInteger)writePropertyList:(id)plist toStream:(NSOutputStream *)stream format:(NSPropertyListFormat)format options:(NSPropertyListWriteOptions)opt error:(out NSError **)error __attribute__((availability(ios,introduced=4_0)));



// + (nullable id)propertyListWithData:(NSData *)data options:(NSPropertyListReadOptions)opt format:(nullable NSPropertyListFormat *)format error:(out NSError **)error __attribute__((availability(ios,introduced=4_0)));



// + (nullable id)propertyListWithStream:(NSInputStream *)stream options:(NSPropertyListReadOptions)opt format:(nullable NSPropertyListFormat *)format error:(out NSError **)error __attribute__((availability(ios,introduced=4_0)));




// + (nullable NSData *)dataFromPropertyList:(id)plist format:(NSPropertyListFormat)format errorDescription:(out __attribute__((objc_ownership(strong))) NSString * _Nullable * _Nullable)errorString __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use dataWithPropertyList:format:options:error: instead.")));



// + (nullable id)propertyListFromData:(NSData *)data mutabilityOption:(NSPropertyListMutabilityOptions)opt format:(nullable NSPropertyListFormat *)format errorDescription:(out __attribute__((objc_ownership(strong))) NSString * _Nullable * _Nullable)errorString __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use propertyListWithData:options:format:error: instead.")));

/* @end */






// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSMutableData
#define _REWRITER_typedef_NSMutableData
typedef struct objc_object NSMutableData;
typedef struct {} _objc_exc_NSMutableData;
#endif

#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @protocol NSKeyedArchiverDelegate, NSKeyedUnarchiverDelegate;



extern "C" NSString * const NSInvalidArchiveOperationException;
extern "C" NSString * const NSInvalidUnarchiveOperationException;

extern "C" NSString * const NSKeyedArchiveRootObjectKey __attribute__((availability(ios,introduced=7_0)));


#ifndef _REWRITER_typedef_NSKeyedArchiver
#define _REWRITER_typedef_NSKeyedArchiver
typedef struct objc_object NSKeyedArchiver;
typedef struct {} _objc_exc_NSKeyedArchiver;
#endif

struct NSKeyedArchiver_IMPL {
	struct NSCoder_IMPL NSCoder_IVARS;
	void *_stream;
	NSUInteger _flags;
	__strong id _delegate;
	__strong id _containers;
	__strong id _objects;
	__strong id _objRefMap;
	__strong id _replacementMap;
	__strong id _classNameMap;
	__strong id _conditionals;
	__strong id _classes;
	NSUInteger _genericKey;
	void *_cache;
	NSUInteger _cacheSize;
	NSUInteger _estimatedCount;
	void *_reserved2;
	__strong id _visited;
	void *_reserved0;
};


// + (NSData *)archivedDataWithRootObject:(id)rootObject;
// + (BOOL)archiveRootObject:(id)rootObject toFile:(NSString *)path;

// - (instancetype)initForWritingWithMutableData:(NSMutableData *)data;

// @property (nullable, assign) id <NSKeyedArchiverDelegate> delegate;

// @property NSPropertyListFormat outputFormat;

// - (void)finishEncoding;

// + (void)setClassName:(nullable NSString *)codedName forClass:(Class)cls;
// - (void)setClassName:(nullable NSString *)codedName forClass:(Class)cls;



// + (nullable NSString *)classNameForClass:(Class)cls;
// - (nullable NSString *)classNameForClass:(Class)cls;

// - (void)encodeObject:(nullable id)objv forKey:(NSString *)key;
// - (void)encodeConditionalObject:(nullable id)objv forKey:(NSString *)key;
// - (void)encodeBool:(BOOL)boolv forKey:(NSString *)key;
// - (void)encodeInt:(int)intv forKey:(NSString *)key;
// - (void)encodeInt32:(int32_t)intv forKey:(NSString *)key;
// - (void)encodeInt64:(int64_t)intv forKey:(NSString *)key;
// - (void)encodeFloat:(float)realv forKey:(NSString *)key;
// - (void)encodeDouble:(double)realv forKey:(NSString *)key;
// - (void)encodeBytes:(nullable const uint8_t *)bytesp length:(NSUInteger)lenv forKey:(NSString *)key;


// @property (readwrite) BOOL requiresSecureCoding __attribute__((availability(ios,introduced=6_0)));

/* @end */



#ifndef _REWRITER_typedef_NSKeyedUnarchiver
#define _REWRITER_typedef_NSKeyedUnarchiver
typedef struct objc_object NSKeyedUnarchiver;
typedef struct {} _objc_exc_NSKeyedUnarchiver;
#endif

struct NSKeyedUnarchiver_IMPL {
	struct NSCoder_IMPL NSCoder_IVARS;
	__strong id _delegate;
	uint32_t _flags;
	__strong id _objRefMap;
	__strong id _replacementMap;
	__strong id _nameClassMap;
	__strong id _tmpRefObjMap;
	__strong id _refObjMap;
	int32_t _genericKey;
	__strong id _data;
	void *_offsetData;
	__strong id _containers;
	__strong id _objects;
	const uint8_t *_bytes;
	uint64_t _len;
	__strong id _helper;
	void *_reserved0;
};


// + (nullable id)unarchiveObjectWithData:(NSData *)data;
// + (nullable id)unarchiveTopLevelObjectWithData:(NSData *)data error:(NSError **)error __attribute__((availability(ios,introduced=9_0))) __attribute__((availability(swift, unavailable, message="Use 'unarchiveTopLevelObjectWithData(_:) throws' instead")));
// + (nullable id)unarchiveObjectWithFile:(NSString *)path;

// - (instancetype)initForReadingWithData:(NSData *)data;

// @property (nullable, assign) id <NSKeyedUnarchiverDelegate> delegate;

// - (void)finishDecoding;

// + (void)setClass:(nullable Class)cls forClassName:(NSString *)codedName;
// - (void)setClass:(nullable Class)cls forClassName:(NSString *)codedName;



// + (nullable Class)classForClassName:(NSString *)codedName;
// - (nullable Class)classForClassName:(NSString *)codedName;

// - (BOOL)containsValueForKey:(NSString *)key;

// - (nullable id)decodeObjectForKey:(NSString *)key;
// - (BOOL)decodeBoolForKey:(NSString *)key;
// - (int)decodeIntForKey:(NSString *)key;
// - (int32_t)decodeInt32ForKey:(NSString *)key;
// - (int64_t)decodeInt64ForKey:(NSString *)key;
// - (float)decodeFloatForKey:(NSString *)key;
// - (double)decodeDoubleForKey:(NSString *)key;
// - (nullable const uint8_t *)decodeBytesForKey:(NSString *)key returnedLength:(nullable NSUInteger *)lengthp __attribute__((objc_returns_inner_pointer));


// @property (readwrite) BOOL requiresSecureCoding __attribute__((availability(ios,introduced=6_0)));

/* @end */


// @protocol NSKeyedArchiverDelegate <NSObject>
/* @optional */


// - (nullable id)archiver:(NSKeyedArchiver *)archiver willEncodeObject:(id)object;
// - (void)archiver:(NSKeyedArchiver *)archiver didEncodeObject:(nullable id)object;






// - (void)archiver:(NSKeyedArchiver *)archiver willReplaceObject:(nullable id)object withObject:(nullable id)newObject;





// - (void)archiverWillFinish:(NSKeyedArchiver *)archiver;


// - (void)archiverDidFinish:(NSKeyedArchiver *)archiver;


/* @end */


// @protocol NSKeyedUnarchiverDelegate <NSObject>
/* @optional */


// - (nullable Class)unarchiver:(NSKeyedUnarchiver *)unarchiver cannotDecodeObjectOfClassName:(NSString *)name originalClasses:(NSArray<NSString *> *)classNames;
// - (nullable id)unarchiver:(NSKeyedUnarchiver *)unarchiver didDecodeObject:(nullable id) __attribute__((ns_consumed)) object __attribute__((ns_returns_retained));







// - (void)unarchiver:(NSKeyedUnarchiver *)unarchiver willReplaceObject:(id)object withObject:(id)newObject;





// - (void)unarchiverWillFinish:(NSKeyedUnarchiver *)unarchiver;


// - (void)unarchiverDidFinish:(NSKeyedUnarchiver *)unarchiver;


/* @end */


// @interface NSObject (NSKeyedArchiverObjectSubstitution)

// @property (nullable, readonly) Class classForKeyedArchiver;
// - (nullable id)replacementObjectForKeyedArchiver:(NSKeyedArchiver *)archiver;
// + (NSArray<NSString *> *)classFallbacksForKeyedArchiver;


/* @end */


// @interface NSObject (NSKeyedUnarchiverObjectSubstitution)

// + (Class)classForKeyedUnarchiver;





/* @end */








// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif







#ifndef _REWRITER_typedef_NSLocale
#define _REWRITER_typedef_NSLocale
typedef struct objc_object NSLocale;
typedef struct {} _objc_exc_NSLocale;
#endif

struct NSLocale_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// - (nullable id)objectForKey:(id)key;

// - (nullable NSString *)displayNameForKey:(id)key value:(id)value;

// - (instancetype)initWithLocaleIdentifier:(NSString *)string __attribute__((objc_designated_initializer));

// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSLocale (NSExtendedLocale)

// @property (readonly, copy) NSString *localeIdentifier;

/* @end */


// @interface NSLocale (NSLocaleCreation)

// + (NSLocale *)autoupdatingCurrentLocale __attribute__((availability(ios,introduced=2_0)));

// + (NSLocale *)currentLocale;
// + (NSLocale *)systemLocale;

// + (instancetype)localeWithLocaleIdentifier:(NSString *)ident __attribute__((availability(ios,introduced=4_0)));

// - (instancetype)init __attribute__((unavailable));

/* @end */


// @interface NSLocale (NSLocaleGeneralInfo)

// + (NSArray<NSString *> *)availableLocaleIdentifiers;
// + (NSArray<NSString *> *)ISOLanguageCodes;
// + (NSArray<NSString *> *)ISOCountryCodes;
// + (NSArray<NSString *> *)ISOCurrencyCodes;
// + (NSArray<NSString *> *)commonISOCurrencyCodes __attribute__((availability(ios,introduced=2_0)));

// + (NSArray<NSString *> *)preferredLanguages __attribute__((availability(ios,introduced=2_0)));

// + (NSDictionary<NSString *, NSString *> *)componentsFromLocaleIdentifier:(NSString *)string;
// + (NSString *)localeIdentifierFromComponents:(NSDictionary<NSString *, NSString *> *)dict;

// + (NSString *)canonicalLocaleIdentifierFromString:(NSString *)string;
// + (NSString *)canonicalLanguageIdentifierFromString:(NSString *)string;

// + (nullable NSString *)localeIdentifierFromWindowsLocaleCode:(uint32_t)lcid __attribute__((availability(ios,introduced=4_0)));
// + (uint32_t)windowsLocaleCodeFromLocaleIdentifier:(NSString *)localeIdentifier __attribute__((availability(ios,introduced=4_0)));

typedef NSUInteger NSLocaleLanguageDirection; enum {
    NSLocaleLanguageDirectionUnknown = kCFLocaleLanguageDirectionUnknown,
    NSLocaleLanguageDirectionLeftToRight = kCFLocaleLanguageDirectionLeftToRight,
    NSLocaleLanguageDirectionRightToLeft = kCFLocaleLanguageDirectionRightToLeft,
    NSLocaleLanguageDirectionTopToBottom = kCFLocaleLanguageDirectionTopToBottom,
    NSLocaleLanguageDirectionBottomToTop = kCFLocaleLanguageDirectionBottomToTop
};

// + (NSLocaleLanguageDirection)characterDirectionForLanguage:(NSString *)isoLangCode __attribute__((availability(ios,introduced=4_0)));
// + (NSLocaleLanguageDirection)lineDirectionForLanguage:(NSString *)isoLangCode __attribute__((availability(ios,introduced=4_0)));

/* @end */



extern "C" NSString * const NSCurrentLocaleDidChangeNotification __attribute__((availability(ios,introduced=2_0)));


extern "C" NSString * const NSLocaleIdentifier;
extern "C" NSString * const NSLocaleLanguageCode;
extern "C" NSString * const NSLocaleCountryCode;
extern "C" NSString * const NSLocaleScriptCode;
extern "C" NSString * const NSLocaleVariantCode;
extern "C" NSString * const NSLocaleExemplarCharacterSet;
extern "C" NSString * const NSLocaleCalendar;
extern "C" NSString * const NSLocaleCollationIdentifier;
extern "C" NSString * const NSLocaleUsesMetricSystem;
extern "C" NSString * const NSLocaleMeasurementSystem;
extern "C" NSString * const NSLocaleDecimalSeparator;
extern "C" NSString * const NSLocaleGroupingSeparator;
extern "C" NSString * const NSLocaleCurrencySymbol;
extern "C" NSString * const NSLocaleCurrencyCode;
extern "C" NSString * const NSLocaleCollatorIdentifier __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSLocaleQuotationBeginDelimiterKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSLocaleQuotationEndDelimiterKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSLocaleAlternateQuotationBeginDelimiterKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSLocaleAlternateQuotationEndDelimiterKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSGregorianCalendar __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarIdentifierGregorian instead")));
extern "C" NSString * const NSBuddhistCalendar __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarIdentifierBuddhist instead")));
extern "C" NSString * const NSChineseCalendar __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarIdentifierChinese instead")));
extern "C" NSString * const NSHebrewCalendar __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarIdentifierHebrew instead")));
extern "C" NSString * const NSIslamicCalendar __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarIdentifierIslamic instead")));
extern "C" NSString * const NSIslamicCivilCalendar __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarIdentifierIslamicCivil instead")));
extern "C" NSString * const NSJapaneseCalendar __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use NSCalendarIdentifierJapanese instead")));
extern "C" NSString * const NSRepublicOfChinaCalendar __attribute__((availability(ios,introduced=4_0,deprecated=8_0,message="" "Use NSCalendarIdentifierRepublicOfChina instead")));
extern "C" NSString * const NSPersianCalendar __attribute__((availability(ios,introduced=4_0,deprecated=8_0,message="" "Use NSCalendarIdentifierPersian instead")));
extern "C" NSString * const NSIndianCalendar __attribute__((availability(ios,introduced=4_0,deprecated=8_0,message="" "Use NSCalendarIdentifierIndian instead")));
extern "C" NSString * const NSISO8601Calendar __attribute__((availability(ios,introduced=4_0,deprecated=8_0,message="" "Use NSCalendarIdentifierISO8601 instead")));






// @class NSDate;
#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif




// @protocol NSLocking

// - (void)lock;
// - (void)unlock;

/* @end */



#ifndef _REWRITER_typedef_NSLock
#define _REWRITER_typedef_NSLock
typedef struct objc_object NSLock;
typedef struct {} _objc_exc_NSLock;
#endif

struct NSLock_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *_priv;
};


// - (BOOL)tryLock;
// - (BOOL)lockBeforeDate:(NSDate *)limit;

// @property (nullable, copy) NSString *name __attribute__((availability(ios,introduced=2_0)));

/* @end */



#ifndef _REWRITER_typedef_NSConditionLock
#define _REWRITER_typedef_NSConditionLock
typedef struct objc_object NSConditionLock;
typedef struct {} _objc_exc_NSConditionLock;
#endif

struct NSConditionLock_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *_priv;
};


// - (instancetype)initWithCondition:(NSInteger)condition __attribute__((objc_designated_initializer));

// @property (readonly) NSInteger condition;
// - (void)lockWhenCondition:(NSInteger)condition;
// - (BOOL)tryLock;
// - (BOOL)tryLockWhenCondition:(NSInteger)condition;
// - (void)unlockWithCondition:(NSInteger)condition;
// - (BOOL)lockBeforeDate:(NSDate *)limit;
// - (BOOL)lockWhenCondition:(NSInteger)condition beforeDate:(NSDate *)limit;

// @property (nullable, copy) NSString *name __attribute__((availability(ios,introduced=2_0)));

/* @end */



#ifndef _REWRITER_typedef_NSRecursiveLock
#define _REWRITER_typedef_NSRecursiveLock
typedef struct objc_object NSRecursiveLock;
typedef struct {} _objc_exc_NSRecursiveLock;
#endif

struct NSRecursiveLock_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *_priv;
};


// - (BOOL)tryLock;
// - (BOOL)lockBeforeDate:(NSDate *)limit;

// @property (nullable, copy) NSString *name __attribute__((availability(ios,introduced=2_0)));

/* @end */




__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=2_0)))

#ifndef _REWRITER_typedef_NSCondition
#define _REWRITER_typedef_NSCondition
typedef struct objc_object NSCondition;
typedef struct {} _objc_exc_NSCondition;
#endif

struct NSCondition_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *_priv;
};


// - (void)wait;
// - (BOOL)waitUntilDate:(NSDate *)limit;
// - (void)signal;
// - (void)broadcast;

// @property (nullable, copy) NSString *name __attribute__((availability(ios,introduced=2_0)));

/* @end */

// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSMapTable
#define _REWRITER_typedef_NSMapTable
typedef struct objc_object NSMapTable;
typedef struct {} _objc_exc_NSMapTable;
#endif

static const NSPointerFunctionsOptions NSMapTableStrongMemory __attribute__((availability(ios,introduced=6_0))) = NSPointerFunctionsStrongMemory;



static const NSPointerFunctionsOptions NSMapTableCopyIn __attribute__((availability(ios,introduced=6_0))) = NSPointerFunctionsCopyIn;
static const NSPointerFunctionsOptions NSMapTableObjectPointerPersonality __attribute__((availability(ios,introduced=6_0))) = NSPointerFunctionsObjectPointerPersonality;
static const NSPointerFunctionsOptions NSMapTableWeakMemory __attribute__((availability(ios,introduced=6_0))) = NSPointerFunctionsWeakMemory;

typedef NSUInteger NSMapTableOptions;

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=6_0)))

#ifndef _REWRITER_typedef_NSMapTable
#define _REWRITER_typedef_NSMapTable
typedef struct objc_object NSMapTable;
typedef struct {} _objc_exc_NSMapTable;
#endif

struct NSMapTable_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// - (instancetype)initWithKeyOptions:(NSPointerFunctionsOptions)keyOptions valueOptions:(NSPointerFunctionsOptions)valueOptions capacity:(NSUInteger)initialCapacity __attribute__((objc_designated_initializer));
// - (instancetype)initWithKeyPointerFunctions:(NSPointerFunctions *)keyFunctions valuePointerFunctions:(NSPointerFunctions *)valueFunctions capacity:(NSUInteger)initialCapacity __attribute__((objc_designated_initializer));

// + (NSMapTable<KeyType, ObjectType> *)mapTableWithKeyOptions:(NSPointerFunctionsOptions)keyOptions valueOptions:(NSPointerFunctionsOptions)valueOptions;
// + (NSMapTable<KeyType, ObjectType> *)strongToStrongObjectsMapTable __attribute__((availability(ios,introduced=6_0)));
// + (NSMapTable<KeyType, ObjectType> *)weakToStrongObjectsMapTable __attribute__((availability(ios,introduced=6_0)));
// + (NSMapTable<KeyType, ObjectType> *)strongToWeakObjectsMapTable __attribute__((availability(ios,introduced=6_0)));
// + (NSMapTable<KeyType, ObjectType> *)weakToWeakObjectsMapTable __attribute__((availability(ios,introduced=6_0)));


// @property (readonly, copy) NSPointerFunctions *keyPointerFunctions;
// @property (readonly, copy) NSPointerFunctions *valuePointerFunctions;

// - (nullable ObjectType)objectForKey:(nullable KeyType)aKey;

// - (void)removeObjectForKey:(nullable KeyType)aKey;
// - (void)setObject:(nullable ObjectType)anObject forKey:(nullable KeyType)aKey;

// @property (readonly) NSUInteger count;

// - (NSEnumerator<KeyType> *)keyEnumerator;
// - (nullable NSEnumerator<ObjectType> *)objectEnumerator;

// - (void)removeAllObjects;

// - (NSDictionary<KeyType, ObjectType> *)dictionaryRepresentation;
/* @end */









__attribute__((availability(swift, unavailable, message="NSInvocation and related APIs not available")))

#ifndef _REWRITER_typedef_NSMethodSignature
#define _REWRITER_typedef_NSMethodSignature
typedef struct objc_object NSMethodSignature;
typedef struct {} _objc_exc_NSMethodSignature;
#endif

struct NSMethodSignature_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *_private;
	void *_reserved[6];
};


// + (nullable NSMethodSignature *)signatureWithObjCTypes:(const char *)types;

// @property (readonly) NSUInteger numberOfArguments;
// - (const char *)getArgumentTypeAtIndex:(NSUInteger)idx __attribute__((objc_returns_inner_pointer));

// @property (readonly) NSUInteger frameLength;

// - (BOOL)isOneway;

// @property (readonly) const char *methodReturnType __attribute__((objc_returns_inner_pointer));
// @property (readonly) NSUInteger methodReturnLength;

/* @end */







// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSOperationQueue
#define _REWRITER_typedef_NSOperationQueue
typedef struct objc_object NSOperationQueue;
typedef struct {} _objc_exc_NSOperationQueue;
#endif







#ifndef _REWRITER_typedef_NSNotification
#define _REWRITER_typedef_NSNotification
typedef struct objc_object NSNotification;
typedef struct {} _objc_exc_NSNotification;
#endif

struct NSNotification_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly, copy) NSString *name;
// @property (nullable, readonly, retain) id object;
// @property (nullable, readonly, copy) NSDictionary *userInfo;

// - (instancetype)initWithName:(NSString *)name object:(nullable id)object userInfo:(nullable NSDictionary *)userInfo __attribute__((availability(ios,introduced=4_0))) __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSNotification (NSNotificationCreation)

// + (instancetype)notificationWithName:(NSString *)aName object:(nullable id)anObject;
// + (instancetype)notificationWithName:(NSString *)aName object:(nullable id)anObject userInfo:(nullable NSDictionary *)aUserInfo;

// - (instancetype)init ;

/* @end */





#ifndef _REWRITER_typedef_NSNotificationCenter
#define _REWRITER_typedef_NSNotificationCenter
typedef struct objc_object NSNotificationCenter;
typedef struct {} _objc_exc_NSNotificationCenter;
#endif

struct NSNotificationCenter_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	void *_impl;
	void *_callback;
	void *_pad[11];
};


// + (NSNotificationCenter *)defaultCenter;

// - (void)addObserver:(id)observer selector:(SEL)aSelector name:(nullable NSString *)aName object:(nullable id)anObject;

// - (void)postNotification:(NSNotification *)notification;
// - (void)postNotificationName:(NSString *)aName object:(nullable id)anObject;
// - (void)postNotificationName:(NSString *)aName object:(nullable id)anObject userInfo:(nullable NSDictionary *)aUserInfo;

// - (void)removeObserver:(id)observer;
// - (void)removeObserver:(id)observer name:(nullable NSString *)aName object:(nullable id)anObject;

// - (id <NSObject>)addObserverForName:(nullable NSString *)name object:(nullable id)obj queue:(nullable NSOperationQueue *)queue usingBlock:(void (^)(NSNotification *note))block __attribute__((availability(ios,introduced=4_0)));



/* @end */







// @class NSNotification;
#ifndef _REWRITER_typedef_NSNotification
#define _REWRITER_typedef_NSNotification
typedef struct objc_object NSNotification;
typedef struct {} _objc_exc_NSNotification;
#endif

#ifndef _REWRITER_typedef_NSNotificationCenter
#define _REWRITER_typedef_NSNotificationCenter
typedef struct objc_object NSNotificationCenter;
typedef struct {} _objc_exc_NSNotificationCenter;
#endif

#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif




typedef NSUInteger NSPostingStyle; enum {
    NSPostWhenIdle = 1,
    NSPostASAP = 2,
    NSPostNow = 3
};

typedef NSUInteger NSNotificationCoalescing; enum {
    NSNotificationNoCoalescing = 0,
    NSNotificationCoalescingOnName = 1,
    NSNotificationCoalescingOnSender = 2
};


#ifndef _REWRITER_typedef_NSNotificationQueue
#define _REWRITER_typedef_NSNotificationQueue
typedef struct objc_object NSNotificationQueue;
typedef struct {} _objc_exc_NSNotificationQueue;
#endif

struct NSNotificationQueue_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _notificationCenter;
	__strong id _asapQueue;
	__strong id _asapObs;
	__strong id _idleQueue;
	__strong id _idleObs;
};


// + (NSNotificationQueue *)defaultQueue;

// - (instancetype)initWithNotificationCenter:(NSNotificationCenter *)notificationCenter __attribute__((objc_designated_initializer));

// - (void)enqueueNotification:(NSNotification *)notification postingStyle:(NSPostingStyle)postingStyle;
// - (void)enqueueNotification:(NSNotification *)notification postingStyle:(NSPostingStyle)postingStyle coalesceMask:(NSNotificationCoalescing)coalesceMask forModes:(nullable NSArray<NSString *> *)modes;

// - (void)dequeueNotificationsMatching:(NSNotification *)notification coalesceMask:(NSUInteger)coalesceMask;

/* @end */










#ifndef _REWRITER_typedef_NSNull
#define _REWRITER_typedef_NSNull
typedef struct objc_object NSNull;
typedef struct {} _objc_exc_NSNull;
#endif

struct NSNull_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// + (NSNull *)null;

/* @end */








// @class NSLocale;
#ifndef _REWRITER_typedef_NSLocale
#define _REWRITER_typedef_NSLocale
typedef struct objc_object NSLocale;
typedef struct {} _objc_exc_NSLocale;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSMutableDictionary
#define _REWRITER_typedef_NSMutableDictionary
typedef struct objc_object NSMutableDictionary;
typedef struct {} _objc_exc_NSMutableDictionary;
#endif

#ifndef _REWRITER_typedef_NSRecursiveLock
#define _REWRITER_typedef_NSRecursiveLock
typedef struct objc_object NSRecursiveLock;
typedef struct {} _objc_exc_NSRecursiveLock;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSCache
#define _REWRITER_typedef_NSCache
typedef struct objc_object NSCache;
typedef struct {} _objc_exc_NSCache;
#endif




typedef NSUInteger NSNumberFormatterBehavior; enum {
    NSNumberFormatterBehaviorDefault = 0,



    NSNumberFormatterBehavior10_4 = 1040,
};


#ifndef _REWRITER_typedef_NSNumberFormatter
#define _REWRITER_typedef_NSNumberFormatter
typedef struct objc_object NSNumberFormatter;
typedef struct {} _objc_exc_NSNumberFormatter;
#endif

struct NSNumberFormatter_IMPL {
	struct NSFormatter_IMPL NSFormatter_IVARS;
	NSMutableDictionary *__strong _attributes;
	CFNumberFormatterRef _formatter;
	NSUInteger _counter;
	NSNumberFormatterBehavior _behavior;
	NSRecursiveLock *__strong _lock;
	unsigned long _stateBitMask;
	NSInteger _cacheGeneration;
	void *_reserved[8];
};


// @property NSFormattingContext formattingContext __attribute__((availability(ios,introduced=8_0)));





// - (BOOL)getObjectValue:(out id _Nullable * _Nullable)obj forString:(NSString *)string range:(inout nullable NSRange *)rangep error:(out NSError **)error;




// - (nullable NSString *)stringFromNumber:(NSNumber *)number;
// - (nullable NSNumber *)numberFromString:(NSString *)string;

typedef NSUInteger NSNumberFormatterStyle; enum {
    NSNumberFormatterNoStyle = kCFNumberFormatterNoStyle,
    NSNumberFormatterDecimalStyle = kCFNumberFormatterDecimalStyle,
    NSNumberFormatterCurrencyStyle = kCFNumberFormatterCurrencyStyle,
    NSNumberFormatterPercentStyle = kCFNumberFormatterPercentStyle,
    NSNumberFormatterScientificStyle = kCFNumberFormatterScientificStyle,
    NSNumberFormatterSpellOutStyle = kCFNumberFormatterSpellOutStyle,
    NSNumberFormatterOrdinalStyle __attribute__((availability(ios,introduced=9_0))) = kCFNumberFormatterOrdinalStyle,
    NSNumberFormatterCurrencyISOCodeStyle __attribute__((availability(ios,introduced=9_0))) = kCFNumberFormatterCurrencyISOCodeStyle,
    NSNumberFormatterCurrencyPluralStyle __attribute__((availability(ios,introduced=9_0))) = kCFNumberFormatterCurrencyPluralStyle,
    NSNumberFormatterCurrencyAccountingStyle __attribute__((availability(ios,introduced=9_0))) = kCFNumberFormatterCurrencyAccountingStyle,
};

// + (NSString *)localizedStringFromNumber:(NSNumber *)num numberStyle:(NSNumberFormatterStyle)nstyle __attribute__((availability(ios,introduced=4_0)));



// + (NSNumberFormatterBehavior)defaultFormatterBehavior;
// + (void)setDefaultFormatterBehavior:(NSNumberFormatterBehavior)behavior;

// @property NSNumberFormatterStyle numberStyle;
// @property (null_resettable, copy) NSLocale *locale;
// @property BOOL generatesDecimalNumbers;
// @property NSNumberFormatterBehavior formatterBehavior;

// @property (null_resettable, copy) NSString *negativeFormat;
// @property (nullable, copy) NSDictionary<NSString *, id> *textAttributesForNegativeValues;
// @property (null_resettable, copy) NSString *positiveFormat;
// @property (nullable, copy) NSDictionary<NSString *, id> *textAttributesForPositiveValues;
// @property BOOL allowsFloats;
// @property (null_resettable, copy) NSString *decimalSeparator;
// @property BOOL alwaysShowsDecimalSeparator;
// @property (null_resettable, copy) NSString *currencyDecimalSeparator;
// @property BOOL usesGroupingSeparator;
// @property (null_resettable, copy) NSString *groupingSeparator;

// @property (nullable, copy) NSString *zeroSymbol;
// @property (nullable, copy) NSDictionary<NSString *, id> *textAttributesForZero;
// @property (copy) NSString *nilSymbol;
// @property (nullable, copy) NSDictionary<NSString *, id> *textAttributesForNil;
// @property (null_resettable, copy) NSString *notANumberSymbol;
// @property (nullable, copy) NSDictionary<NSString *, id> *textAttributesForNotANumber;
// @property (copy) NSString *positiveInfinitySymbol;
// @property (nullable, copy) NSDictionary<NSString *, id> *textAttributesForPositiveInfinity;
// @property (copy) NSString *negativeInfinitySymbol;
// @property (nullable, copy) NSDictionary<NSString *, id> *textAttributesForNegativeInfinity;

// @property (null_resettable, copy) NSString *positivePrefix;
// @property (null_resettable, copy) NSString *positiveSuffix;
// @property (null_resettable, copy) NSString *negativePrefix;
// @property (null_resettable, copy) NSString *negativeSuffix;
// @property (null_resettable, copy) NSString *currencyCode;
// @property (null_resettable, copy) NSString *currencySymbol;
// @property (null_resettable, copy) NSString *internationalCurrencySymbol;
// @property (null_resettable, copy) NSString *percentSymbol;
// @property (null_resettable, copy) NSString *perMillSymbol;
// @property (null_resettable, copy) NSString *minusSign;
// @property (null_resettable, copy) NSString *plusSign;
// @property (null_resettable, copy) NSString *exponentSymbol;

// @property NSUInteger groupingSize;
// @property NSUInteger secondaryGroupingSize;
// @property (nullable, copy) NSNumber *multiplier;
// @property NSUInteger formatWidth;
// @property (null_resettable, copy) NSString *paddingCharacter;


typedef NSUInteger NSNumberFormatterPadPosition; enum {
    NSNumberFormatterPadBeforePrefix = kCFNumberFormatterPadBeforePrefix,
    NSNumberFormatterPadAfterPrefix = kCFNumberFormatterPadAfterPrefix,
    NSNumberFormatterPadBeforeSuffix = kCFNumberFormatterPadBeforeSuffix,
    NSNumberFormatterPadAfterSuffix = kCFNumberFormatterPadAfterSuffix
};

typedef NSUInteger NSNumberFormatterRoundingMode; enum {
    NSNumberFormatterRoundCeiling = kCFNumberFormatterRoundCeiling,
    NSNumberFormatterRoundFloor = kCFNumberFormatterRoundFloor,
    NSNumberFormatterRoundDown = kCFNumberFormatterRoundDown,
    NSNumberFormatterRoundUp = kCFNumberFormatterRoundUp,
    NSNumberFormatterRoundHalfEven = kCFNumberFormatterRoundHalfEven,
    NSNumberFormatterRoundHalfDown = kCFNumberFormatterRoundHalfDown,
    NSNumberFormatterRoundHalfUp = kCFNumberFormatterRoundHalfUp
};

// @property NSNumberFormatterPadPosition paddingPosition;
// @property NSNumberFormatterRoundingMode roundingMode;
// @property (null_resettable, copy) NSNumber *roundingIncrement;
// @property NSUInteger minimumIntegerDigits;
// @property NSUInteger maximumIntegerDigits;
// @property NSUInteger minimumFractionDigits;
// @property NSUInteger maximumFractionDigits;
// @property (nullable, copy) NSNumber *minimum;
// @property (nullable, copy) NSNumber *maximum;
// @property (null_resettable, copy) NSString *currencyGroupingSeparator __attribute__((availability(ios,introduced=2_0)));
// @property (getter=isLenient) BOOL lenient __attribute__((availability(ios,introduced=2_0)));
// @property BOOL usesSignificantDigits __attribute__((availability(ios,introduced=2_0)));
// @property NSUInteger minimumSignificantDigits __attribute__((availability(ios,introduced=2_0)));
// @property NSUInteger maximumSignificantDigits __attribute__((availability(ios,introduced=2_0)));
// @property (getter=isPartialStringValidationEnabled) BOOL partialStringValidationEnabled __attribute__((availability(ios,introduced=2_0)));

/* @end */


// @class NSDecimalNumberHandler;
#ifndef _REWRITER_typedef_NSDecimalNumberHandler
#define _REWRITER_typedef_NSDecimalNumberHandler
typedef struct objc_object NSDecimalNumberHandler;
typedef struct {} _objc_exc_NSDecimalNumberHandler;
#endif










// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSSet
#define _REWRITER_typedef_NSSet
typedef struct objc_object NSSet;
typedef struct {} _objc_exc_NSSet;
#endif

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=2_0)))

#ifndef _REWRITER_typedef_NSOperation
#define _REWRITER_typedef_NSOperation
typedef struct objc_object NSOperation;
typedef struct {} _objc_exc_NSOperation;
#endif

struct NSOperation_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _private;
	int32_t _private1;
	int32_t _private1b;
};


// - (void)start;
// - (void)main;

// @property (readonly, getter=isCancelled) BOOL cancelled;
// - (void)cancel;

// @property (readonly, getter=isExecuting) BOOL executing;
// @property (readonly, getter=isFinished) BOOL finished;
// @property (readonly, getter=isConcurrent) BOOL concurrent;
// @property (readonly, getter=isAsynchronous) BOOL asynchronous __attribute__((availability(ios,introduced=7_0)));
// @property (readonly, getter=isReady) BOOL ready;

// - (void)addDependency:(NSOperation *)op;
// - (void)removeDependency:(NSOperation *)op;

// @property (readonly, copy) NSArray<NSOperation *> *dependencies;

typedef NSInteger NSOperationQueuePriority; enum {
 NSOperationQueuePriorityVeryLow = -8L,
 NSOperationQueuePriorityLow = -4L,
 NSOperationQueuePriorityNormal = 0,
 NSOperationQueuePriorityHigh = 4,
 NSOperationQueuePriorityVeryHigh = 8
};

// @property NSOperationQueuePriority queuePriority;

// @property (nullable, copy) void (^completionBlock)(void) __attribute__((availability(ios,introduced=4_0)));

// - (void)waitUntilFinished __attribute__((availability(ios,introduced=4_0)));

// @property double threadPriority __attribute__((availability(ios,introduced=4_0,deprecated=8_0,message="" )));

// @property NSQualityOfService qualityOfService __attribute__((availability(ios,introduced=8_0)));

// @property (nullable, copy) NSString *name __attribute__((availability(ios,introduced=8_0)));

/* @end */




__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=4_0)))

#ifndef _REWRITER_typedef_NSBlockOperation
#define _REWRITER_typedef_NSBlockOperation
typedef struct objc_object NSBlockOperation;
typedef struct {} _objc_exc_NSBlockOperation;
#endif

struct NSBlockOperation_IMPL {
	struct NSOperation_IMPL NSOperation_IVARS;
	__strong id _private2;
	void *_reserved2;
};


// + (instancetype)blockOperationWithBlock:(void (^)(void))block;

// - (void)addExecutionBlock:(void (^)(void))block;
// @property (readonly, copy) NSArray<void (^)(void)> *executionBlocks;

/* @end */



__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=2_0)))
__attribute__((availability(swift, unavailable, message="NSInvocation and related APIs not available")))

#ifndef _REWRITER_typedef_NSInvocationOperation
#define _REWRITER_typedef_NSInvocationOperation
typedef struct objc_object NSInvocationOperation;
typedef struct {} _objc_exc_NSInvocationOperation;
#endif

struct NSInvocationOperation_IMPL {
	struct NSOperation_IMPL NSOperation_IVARS;
	__strong id _inv;
	__strong id _exception;
	void *_reserved2;
};


// - (nullable instancetype)initWithTarget:(id)target selector:(SEL)sel object:(nullable id)arg;
// - (instancetype)initWithInvocation:(NSInvocation *)inv __attribute__((objc_designated_initializer));

// @property (readonly, retain) NSInvocation *invocation;

// @property (nullable, readonly, retain) id result;

/* @end */


extern "C" NSString * const NSInvocationOperationVoidResultException __attribute__((availability(ios,introduced=2_0)));
extern "C" NSString * const NSInvocationOperationCancelledException __attribute__((availability(ios,introduced=2_0)));

static const NSInteger NSOperationQueueDefaultMaxConcurrentOperationCount = -1;

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=2_0)))

#ifndef _REWRITER_typedef_NSOperationQueue
#define _REWRITER_typedef_NSOperationQueue
typedef struct objc_object NSOperationQueue;
typedef struct {} _objc_exc_NSOperationQueue;
#endif

struct NSOperationQueue_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _private;
	void *_reserved;
};


// - (void)addOperation:(NSOperation *)op;
// - (void)addOperations:(NSArray<NSOperation *> *)ops waitUntilFinished:(BOOL)wait __attribute__((availability(ios,introduced=4_0)));

// - (void)addOperationWithBlock:(void (^)(void))block __attribute__((availability(ios,introduced=4_0)));

// @property (readonly, copy) NSArray<__kindof NSOperation *> *operations;
// @property (readonly) NSUInteger operationCount __attribute__((availability(ios,introduced=4_0)));

// @property NSInteger maxConcurrentOperationCount;

// @property (getter=isSuspended) BOOL suspended;

// @property (nullable, copy) NSString *name __attribute__((availability(ios,introduced=4_0)));

// @property NSQualityOfService qualityOfService __attribute__((availability(ios,introduced=8_0)));

// @property (nullable, assign ) dispatch_queue_t underlyingQueue __attribute__((availability(ios,introduced=8_0)));

// - (void)cancelAllOperations;

// - (void)waitUntilAllOperationsAreFinished;

// + (nullable NSOperationQueue *)currentQueue __attribute__((availability(ios,introduced=4_0)));
// + (NSOperationQueue *)mainQueue __attribute__((availability(ios,introduced=4_0)));

/* @end */








// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif






__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=4_0)))

#ifndef _REWRITER_typedef_NSOrthography
#define _REWRITER_typedef_NSOrthography
typedef struct objc_object NSOrthography;
typedef struct {} _objc_exc_NSOrthography;
#endif

struct NSOrthography_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};



// @property (readonly, copy) NSString *dominantScript;
// @property (readonly, copy) NSDictionary<NSString *, NSArray<NSString *> *> *languageMap;
// - (instancetype)initWithDominantScript:(NSString *)script languageMap:(NSDictionary<NSString *, NSArray<NSString *> *> *)map __attribute__((availability(ios,introduced=4_0))) __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));

/* @end */


// @interface NSOrthography (NSOrthographyExtended)


// - (nullable NSArray<NSString *> *)languagesForScript:(NSString *)script __attribute__((availability(ios,introduced=4_0)));
// - (nullable NSString *)dominantLanguageForScript:(NSString *)script __attribute__((availability(ios,introduced=4_0)));


// @property (readonly, copy) NSString *dominantLanguage __attribute__((availability(ios,introduced=4_0)));
// @property (readonly, copy) NSArray<NSString *> *allScripts __attribute__((availability(ios,introduced=4_0)));
// @property (readonly, copy) NSArray<NSString *> *allLanguages __attribute__((availability(ios,introduced=4_0)));

/* @end */


// @interface NSOrthography (NSOrthographyCreation)

// + (instancetype)orthographyWithDominantScript:(NSString *)script languageMap:(NSDictionary<NSString *, NSArray<NSString *> *> *)map __attribute__((availability(ios,introduced=4_0)));

/* @end */


__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=6_0)))

#ifndef _REWRITER_typedef_NSPointerArray
#define _REWRITER_typedef_NSPointerArray
typedef struct objc_object NSPointerArray;
typedef struct {} _objc_exc_NSPointerArray;
#endif

struct NSPointerArray_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// - (instancetype)initWithOptions:(NSPointerFunctionsOptions)options __attribute__((objc_designated_initializer));
// - (instancetype)initWithPointerFunctions:(NSPointerFunctions *)functions __attribute__((objc_designated_initializer));

// + (NSPointerArray *)pointerArrayWithOptions:(NSPointerFunctionsOptions)options;
// + (NSPointerArray *)pointerArrayWithPointerFunctions:(NSPointerFunctions *)functions;


// @property (readonly, copy) NSPointerFunctions *pointerFunctions;

// - (nullable void *)pointerAtIndex:(NSUInteger)index;


// - (void)addPointer:(nullable void *)pointer;
// - (void)removePointerAtIndex:(NSUInteger)index;
// - (void)insertPointer:(nullable void *)item atIndex:(NSUInteger)index;

// - (void)replacePointerAtIndex:(NSUInteger)index withPointer:(nullable void *)item;

// - (void)compact;



// @property NSUInteger count;

/* @end */



// @interface NSPointerArray (NSPointerArrayConveniences)







// + (NSPointerArray *)strongObjectsPointerArray __attribute__((availability(ios,introduced=6_0)));
// + (NSPointerArray *)weakObjectsPointerArray __attribute__((availability(ios,introduced=6_0)));

// @property (readonly, copy) NSArray *allObjects;

/* @end */








typedef int NSSocketNativeHandle;

// @class NSRunLoop;
#ifndef _REWRITER_typedef_NSRunLoop
#define _REWRITER_typedef_NSRunLoop
typedef struct objc_object NSRunLoop;
typedef struct {} _objc_exc_NSRunLoop;
#endif

#ifndef _REWRITER_typedef_NSMutableArray
#define _REWRITER_typedef_NSMutableArray
typedef struct objc_object NSMutableArray;
typedef struct {} _objc_exc_NSMutableArray;
#endif

#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

// @class NSConnection;
#ifndef _REWRITER_typedef_NSConnection
#define _REWRITER_typedef_NSConnection
typedef struct objc_object NSConnection;
typedef struct {} _objc_exc_NSConnection;
#endif

#ifndef _REWRITER_typedef_NSPortMessage
#define _REWRITER_typedef_NSPortMessage
typedef struct objc_object NSPortMessage;
typedef struct {} _objc_exc_NSPortMessage;
#endif

// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

// @protocol NSPortDelegate, NSMachPortDelegate;



extern "C" NSString * const NSPortDidBecomeInvalidNotification;


#ifndef _REWRITER_typedef_NSPort
#define _REWRITER_typedef_NSPort
typedef struct objc_object NSPort;
typedef struct {} _objc_exc_NSPort;
#endif

struct NSPort_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};








// + (NSPort *)port;

// - (void)invalidate;
// @property (readonly, getter=isValid) BOOL valid;

// - (void)setDelegate:(nullable id <NSPortDelegate>)anObject;
// - (nullable id <NSPortDelegate>)delegate;





// - (void)scheduleInRunLoop:(NSRunLoop *)runLoop forMode:(NSString *)mode;
// - (void)removeFromRunLoop:(NSRunLoop *)runLoop forMode:(NSString *)mode;



// @property (readonly) NSUInteger reservedSpaceLength;
// - (BOOL)sendBeforeDate:(NSDate *)limitDate components:(nullable NSMutableArray *)components from:(nullable NSPort *) receivePort reserved:(NSUInteger)headerSpaceReserved;
// - (BOOL)sendBeforeDate:(NSDate *)limitDate msgid:(NSUInteger)msgID components:(nullable NSMutableArray *)components from:(nullable NSPort *)receivePort reserved:(NSUInteger)headerSpaceReserved;
/* @end */


// @protocol NSPortDelegate <NSObject>
/* @optional */

// - (void)handlePortMessage:(NSPortMessage *)message;



/* @end */




__attribute__((objc_arc_weak_reference_unavailable))

#ifndef _REWRITER_typedef_NSMachPort
#define _REWRITER_typedef_NSMachPort
typedef struct objc_object NSMachPort;
typedef struct {} _objc_exc_NSMachPort;
#endif

struct NSMachPort_IMPL {
	struct NSPort_IMPL NSPort_IVARS;
	__strong id _delegate;
	NSUInteger _flags;
	uint32_t _machPort;
	NSUInteger _reserved;
};


// + (NSPort *)portWithMachPort:(uint32_t)machPort;
// - (instancetype)initWithMachPort:(uint32_t)machPort __attribute__((objc_designated_initializer));

// - (void)setDelegate:(nullable id <NSMachPortDelegate>)anObject;
// - (nullable id <NSMachPortDelegate>)delegate;

typedef NSUInteger NSMachPortOptions; enum {
    NSMachPortDeallocateNone = 0,
    NSMachPortDeallocateSendRight = (1UL << 0),
    NSMachPortDeallocateReceiveRight = (1UL << 1)
} __attribute__((availability(ios,introduced=2_0)));

// + (NSPort *)portWithMachPort:(uint32_t)machPort options:(NSMachPortOptions)f __attribute__((availability(ios,introduced=2_0)));
// - (instancetype)initWithMachPort:(uint32_t)machPort options:(NSMachPortOptions)f __attribute__((availability(ios,introduced=2_0))) __attribute__((objc_designated_initializer));

// @property (readonly) uint32_t machPort;

// - (void)scheduleInRunLoop:(NSRunLoop *)runLoop forMode:(NSString *)mode;
// - (void)removeFromRunLoop:(NSRunLoop *)runLoop forMode:(NSString *)mode;




/* @end */


// @protocol NSMachPortDelegate <NSPortDelegate>
/* @optional */



// - (void)handleMachMessage:(void *)msg;

/* @end */






__attribute__((objc_arc_weak_reference_unavailable))

#ifndef _REWRITER_typedef_NSMessagePort
#define _REWRITER_typedef_NSMessagePort
typedef struct objc_object NSMessagePort;
typedef struct {} _objc_exc_NSMessagePort;
#endif

struct NSMessagePort_IMPL {
	struct NSPort_IMPL NSPort_IVARS;
	void *_port;
	__strong id _delegate;
};


/* @end */








#ifndef _REWRITER_typedef_NSSocketPort
#define _REWRITER_typedef_NSSocketPort
typedef struct objc_object NSSocketPort;
typedef struct {} _objc_exc_NSSocketPort;
#endif

struct NSSocketPort_IMPL {
	struct NSPort_IMPL NSPort_IVARS;
	void *_receiver;
	__strong id _connectors;
	void *_loops;
	void *_data;
	__strong id _signature;
	__strong id _delegate;
	__strong id _lock;
	NSUInteger _maxSize;
	NSUInteger _useCount;
	NSUInteger _reserved;
};


// - (instancetype)init;
// - (nullable instancetype)initWithTCPPort:(unsigned short)port;
// - (nullable instancetype)initWithProtocolFamily:(int)family socketType:(int)type protocol:(int)protocol address:(NSData *)address __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithProtocolFamily:(int)family socketType:(int)type protocol:(int)protocol socket:(NSSocketNativeHandle)sock __attribute__((objc_designated_initializer));
// - (nullable instancetype)initRemoteWithTCPPort:(unsigned short)port host:(nullable NSString *)hostName;
// - (instancetype)initRemoteWithProtocolFamily:(int)family socketType:(int)type protocol:(int)protocol address:(NSData *)address __attribute__((objc_designated_initializer));


// @property (readonly) int protocolFamily;
// @property (readonly) int socketType;
// @property (readonly) int protocol;
// @property (readonly, copy) NSData *address;
// @property (readonly) NSSocketNativeHandle socket;

/* @end */

enum {
    NSWindowsNTOperatingSystem = 1,
    NSWindows95OperatingSystem,
    NSSolarisOperatingSystem,
    NSHPUXOperatingSystem,
    NSMACHOperatingSystem,
    NSSunOSOperatingSystem,
    NSOSF1OperatingSystem
} __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" )));

typedef struct {
    NSInteger majorVersion;
    NSInteger minorVersion;
    NSInteger patchVersion;
} NSOperatingSystemVersion;

// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif



#ifndef _REWRITER_typedef_NSProcessInfo
#define _REWRITER_typedef_NSProcessInfo
typedef struct objc_object NSProcessInfo;
typedef struct {} _objc_exc_NSProcessInfo;
#endif

struct NSProcessInfo_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSDictionary *__strong environment;
	NSArray *__strong arguments;
	NSString *__strong hostName;
	NSString *__strong name;
	NSInteger automaticTerminationOptOutCounter;
};


// + (NSProcessInfo *)processInfo;

// @property (readonly, copy) NSDictionary<NSString *, NSString *> *environment;
// @property (readonly, copy) NSArray<NSString *> *arguments;
// @property (readonly, copy) NSString *hostName;
// @property (copy) NSString *processName;
// @property (readonly) int processIdentifier;

// @property (readonly, copy) NSString *globallyUniqueString;

// - (NSUInteger)operatingSystem __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "-operatingSystem always returns NSMACHOperatingSystem, use -operatingSystemVersion or -isOperatingSystemAtLeastVersion: instead")));
// - (NSString *)operatingSystemName __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "-operatingSystemName always returns NSMACHOperatingSystem, use -operatingSystemVersionString instead")));


// @property (readonly, copy) NSString *operatingSystemVersionString;

// @property (readonly) NSOperatingSystemVersion operatingSystemVersion __attribute__((availability(ios,introduced=8_0)));

// @property (readonly) NSUInteger processorCount __attribute__((availability(ios,introduced=2_0)));
// @property (readonly) NSUInteger activeProcessorCount __attribute__((availability(ios,introduced=2_0)));
// @property (readonly) unsigned long long physicalMemory __attribute__((availability(ios,introduced=2_0)));

// - (BOOL) isOperatingSystemAtLeastVersion:(NSOperatingSystemVersion)version __attribute__((availability(ios,introduced=8_0)));
// @property (readonly) NSTimeInterval systemUptime __attribute__((availability(ios,introduced=4_0)));






// - (void)disableSuddenTermination __attribute__((availability(ios,introduced=NA)));
// - (void)enableSuddenTermination __attribute__((availability(ios,introduced=NA)));







// - (void)disableAutomaticTermination:(NSString *)reason __attribute__((availability(ios,introduced=NA)));
// - (void)enableAutomaticTermination:(NSString *)reason __attribute__((availability(ios,introduced=NA)));






// @property BOOL automaticTerminationSupportEnabled __attribute__((availability(ios,introduced=NA)));

/* @end */

typedef uint64_t NSActivityOptions; enum {
    NSActivityIdleDisplaySleepDisabled = (1ULL << 40),


    NSActivityIdleSystemSleepDisabled = (1ULL << 20),


    NSActivitySuddenTerminationDisabled = (1ULL << 14),


    NSActivityAutomaticTerminationDisabled = (1ULL << 15),





    NSActivityUserInitiated = (0x00FFFFFFULL | NSActivityIdleSystemSleepDisabled),
    NSActivityUserInitiatedAllowingIdleSystemSleep = (NSActivityUserInitiated & ~NSActivityIdleSystemSleepDisabled),


    NSActivityBackground = 0x000000FFULL,


    NSActivityLatencyCritical = 0xFF00000000ULL,
} __attribute__((availability(ios,introduced=7_0)));

// @interface NSProcessInfo (NSProcessInfoActivity)



// - (id <NSObject>)beginActivityWithOptions:(NSActivityOptions)options reason:(NSString *)reason __attribute__((availability(ios,introduced=7_0)));




// - (void)endActivity:(id <NSObject>)activity __attribute__((availability(ios,introduced=7_0)));




// - (void)performActivityWithOptions:(NSActivityOptions)options reason:(NSString *)reason usingBlock:(void (^)(void))block __attribute__((availability(ios,introduced=7_0)));




// - (void)performExpiringActivityWithReason:(NSString *)reason usingBlock:(void(^)(BOOL expired))block __attribute__((availability(ios,introduced=8_2)));

/* @end */



typedef NSInteger NSProcessInfoThermalState; enum {

    NSProcessInfoThermalStateNominal,


    NSProcessInfoThermalStateFair,


    NSProcessInfoThermalStateSerious,


    NSProcessInfoThermalStateCritical
} __attribute__((availability(ios,introduced=NA)));

// @interface NSProcessInfo (NSProcessInfoThermalState)


// @property (readonly) NSProcessInfoThermalState thermalState __attribute__((availability(ios,introduced=NA)));

/* @end */


// @interface NSProcessInfo (NSProcessInfoPowerState)


// @property (readonly, getter=isLowPowerModeEnabled) BOOL lowPowerModeEnabled __attribute__((availability(ios,introduced=9_0)));

/* @end */

extern "C" NSString * const NSProcessInfoThermalStateDidChangeNotification __attribute__((availability(ios,introduced=NA)));
extern "C" NSString * const NSProcessInfoPowerStateDidChangeNotification __attribute__((availability(ios,introduced=9_0)));







// @class NSMethodSignature;
#ifndef _REWRITER_typedef_NSMethodSignature
#define _REWRITER_typedef_NSMethodSignature
typedef struct objc_object NSMethodSignature;
typedef struct {} _objc_exc_NSMethodSignature;
#endif

#ifndef _REWRITER_typedef_NSInvocation
#define _REWRITER_typedef_NSInvocation
typedef struct objc_object NSInvocation;
typedef struct {} _objc_exc_NSInvocation;
#endif




__attribute__((objc_root_class))

#ifndef _REWRITER_typedef_NSProxy
#define _REWRITER_typedef_NSProxy
typedef struct objc_object NSProxy;
typedef struct {} _objc_exc_NSProxy;
#endif

struct NSProxy_IMPL {
	__unsafe_unretained Class isa;
};


// + (id)alloc;
// + (id)allocWithZone:(nullable NSZone *)zone __attribute__((unavailable("not available in automatic reference counting mode")));
// + (Class)class;

// - (void)forwardInvocation:(NSInvocation *)invocation;
// - (nullable NSMethodSignature *)methodSignatureForSelector:(SEL)sel __attribute__((availability(swift, unavailable, message="NSInvocation and related APIs not available")));
// - (void)dealloc;
// - (void)finalize;
// @property (readonly, copy) NSString *description;
// @property (readonly, copy) NSString *debugDescription;
// + (BOOL)respondsToSelector:(SEL)aSelector;

// - (BOOL)allowsWeakReference __attribute__((unavailable));
// - (BOOL)retainWeakReference __attribute__((unavailable));



/* @end */
















// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

#ifndef _REWRITER_typedef_NSTimeZone
#define _REWRITER_typedef_NSTimeZone
typedef struct objc_object NSTimeZone;
typedef struct {} _objc_exc_NSTimeZone;
#endif

#ifndef _REWRITER_typedef_NSOrthography
#define _REWRITER_typedef_NSOrthography
typedef struct objc_object NSOrthography;
typedef struct {} _objc_exc_NSOrthography;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

#ifndef _REWRITER_typedef_NSRegularExpression
#define _REWRITER_typedef_NSRegularExpression
typedef struct objc_object NSRegularExpression;
typedef struct {} _objc_exc_NSRegularExpression;
#endif






typedef uint64_t NSTextCheckingType; enum {
    NSTextCheckingTypeOrthography = 1ULL << 0,
    NSTextCheckingTypeSpelling = 1ULL << 1,
    NSTextCheckingTypeGrammar = 1ULL << 2,
    NSTextCheckingTypeDate = 1ULL << 3,
    NSTextCheckingTypeAddress = 1ULL << 4,
    NSTextCheckingTypeLink = 1ULL << 5,
    NSTextCheckingTypeQuote = 1ULL << 6,
    NSTextCheckingTypeDash = 1ULL << 7,
    NSTextCheckingTypeReplacement = 1ULL << 8,
    NSTextCheckingTypeCorrection = 1ULL << 9,
    NSTextCheckingTypeRegularExpression __attribute__((availability(ios,introduced=4_0))) = 1ULL << 10,
    NSTextCheckingTypePhoneNumber __attribute__((availability(ios,introduced=4_0))) = 1ULL << 11,
    NSTextCheckingTypeTransitInformation __attribute__((availability(ios,introduced=4_0))) = 1ULL << 12
};

typedef uint64_t NSTextCheckingTypes;
enum {
    NSTextCheckingAllSystemTypes = 0xffffffffULL,
    NSTextCheckingAllCustomTypes = 0xffffffffULL << 32,
    NSTextCheckingAllTypes = (NSTextCheckingAllSystemTypes | NSTextCheckingAllCustomTypes)
};

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=4_0)))

#ifndef _REWRITER_typedef_NSTextCheckingResult
#define _REWRITER_typedef_NSTextCheckingResult
typedef struct objc_object NSTextCheckingResult;
typedef struct {} _objc_exc_NSTextCheckingResult;
#endif

struct NSTextCheckingResult_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};



// @property (readonly) NSTextCheckingType resultType;
// @property (readonly) NSRange range;

/* @end */


// @interface NSTextCheckingResult (NSTextCheckingResultOptional)


// @property (nullable, readonly, copy) NSOrthography *orthography;
// @property (nullable, readonly, copy) NSArray<NSString *> *grammarDetails;
// @property (nullable, readonly, copy) NSDate *date;
// @property (nullable, readonly, copy) NSTimeZone *timeZone;
// @property (readonly) NSTimeInterval duration;
// @property (nullable, readonly, copy) NSDictionary<NSString *, NSString *> *components __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSURL *URL;
// @property (nullable, readonly, copy) NSString *replacementString;
// @property (nullable, readonly, copy) NSArray<NSString *> *alternativeStrings __attribute__((availability(ios,introduced=7_0)));
// @property (nullable, readonly, copy) NSRegularExpression *regularExpression __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSString *phoneNumber __attribute__((availability(ios,introduced=4_0)));

// @property (nullable, readonly, copy) NSDictionary<NSString *, NSString *> *addressComponents;


// @property (readonly) NSUInteger numberOfRanges __attribute__((availability(ios,introduced=4_0)));
// - (NSRange)rangeAtIndex:(NSUInteger)idx __attribute__((availability(ios,introduced=4_0)));
// - (NSTextCheckingResult *)resultByAdjustingRangesWithOffset:(NSInteger)offset __attribute__((availability(ios,introduced=5_0)));

/* @end */





extern "C" NSString * const NSTextCheckingNameKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSTextCheckingJobTitleKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSTextCheckingOrganizationKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSTextCheckingStreetKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSTextCheckingCityKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSTextCheckingStateKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSTextCheckingZIPKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSTextCheckingCountryKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSTextCheckingPhoneKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSTextCheckingAirlineKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSTextCheckingFlightKey __attribute__((availability(ios,introduced=4_0)));


// @interface NSTextCheckingResult (NSTextCheckingResultCreation)


// + (NSTextCheckingResult *)orthographyCheckingResultWithRange:(NSRange)range orthography:(NSOrthography *)orthography;
// + (NSTextCheckingResult *)spellCheckingResultWithRange:(NSRange)range;
// + (NSTextCheckingResult *)grammarCheckingResultWithRange:(NSRange)range details:(NSArray<NSString *> *)details;
// + (NSTextCheckingResult *)dateCheckingResultWithRange:(NSRange)range date:(NSDate *)date;
// + (NSTextCheckingResult *)dateCheckingResultWithRange:(NSRange)range date:(NSDate *)date timeZone:(NSTimeZone *)timeZone duration:(NSTimeInterval)duration;
// + (NSTextCheckingResult *)addressCheckingResultWithRange:(NSRange)range components:(NSDictionary<NSString *, NSString *> *)components;
// + (NSTextCheckingResult *)linkCheckingResultWithRange:(NSRange)range URL:(NSURL *)url;
// + (NSTextCheckingResult *)quoteCheckingResultWithRange:(NSRange)range replacementString:(NSString *)replacementString;
// + (NSTextCheckingResult *)dashCheckingResultWithRange:(NSRange)range replacementString:(NSString *)replacementString;
// + (NSTextCheckingResult *)replacementCheckingResultWithRange:(NSRange)range replacementString:(NSString *)replacementString;
// + (NSTextCheckingResult *)correctionCheckingResultWithRange:(NSRange)range replacementString:(NSString *)replacementString;
// + (NSTextCheckingResult *)correctionCheckingResultWithRange:(NSRange)range replacementString:(NSString *)replacementString alternativeStrings:(NSArray<NSString *> *)alternativeStrings __attribute__((availability(ios,introduced=7_0)));
// + (NSTextCheckingResult *)regularExpressionCheckingResultWithRanges:(NSRangePointer)ranges count:(NSUInteger)count regularExpression:(NSRegularExpression *)regularExpression __attribute__((availability(ios,introduced=4_0)));
// + (NSTextCheckingResult *)phoneNumberCheckingResultWithRange:(NSRange)range phoneNumber:(NSString *)phoneNumber __attribute__((availability(ios,introduced=4_0)));
// + (NSTextCheckingResult *)transitInformationCheckingResultWithRange:(NSRange)range components:(NSDictionary<NSString *, NSString *> *)components __attribute__((availability(ios,introduced=4_0)));

/* @end */


// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif







typedef NSUInteger NSRegularExpressionOptions; enum {
   NSRegularExpressionCaseInsensitive = 1 << 0,
   NSRegularExpressionAllowCommentsAndWhitespace = 1 << 1,
   NSRegularExpressionIgnoreMetacharacters = 1 << 2,
   NSRegularExpressionDotMatchesLineSeparators = 1 << 3,
   NSRegularExpressionAnchorsMatchLines = 1 << 4,
   NSRegularExpressionUseUnixLineSeparators = 1 << 5,
   NSRegularExpressionUseUnicodeWordBoundaries = 1 << 6
};

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=4_0)))

#ifndef _REWRITER_typedef_NSRegularExpression
#define _REWRITER_typedef_NSRegularExpression
typedef struct objc_object NSRegularExpression;
typedef struct {} _objc_exc_NSRegularExpression;
#endif

struct NSRegularExpression_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSString *__strong _pattern;
	NSUInteger _options;
	void *_internal;
	__strong id _reserved1;
	int32_t _checkout;
	int32_t _reserved2;
};




// + (nullable NSRegularExpression *)regularExpressionWithPattern:(NSString *)pattern options:(NSRegularExpressionOptions)options error:(NSError **)error;
// - (nullable instancetype)initWithPattern:(NSString *)pattern options:(NSRegularExpressionOptions)options error:(NSError **)error __attribute__((objc_designated_initializer));

// @property (readonly, copy) NSString *pattern;
// @property (readonly) NSRegularExpressionOptions options;
// @property (readonly) NSUInteger numberOfCaptureGroups;



// + (NSString *)escapedPatternForString:(NSString *)string;

/* @end */



typedef NSUInteger NSMatchingOptions; enum {
   NSMatchingReportProgress = 1 << 0,
   NSMatchingReportCompletion = 1 << 1,
   NSMatchingAnchored = 1 << 2,
   NSMatchingWithTransparentBounds = 1 << 3,
   NSMatchingWithoutAnchoringBounds = 1 << 4
};

typedef NSUInteger NSMatchingFlags; enum {
   NSMatchingProgress = 1 << 0,
   NSMatchingCompleted = 1 << 1,
   NSMatchingHitEnd = 1 << 2,
   NSMatchingRequiredEnd = 1 << 3,
   NSMatchingInternalError = 1 << 4
};

// @interface NSRegularExpression (NSMatching)




// - (void)enumerateMatchesInString:(NSString *)string options:(NSMatchingOptions)options range:(NSRange)range usingBlock:(void (^)(NSTextCheckingResult * _Nullable result, NSMatchingFlags flags, BOOL *stop))block;

// - (NSArray<NSTextCheckingResult *> *)matchesInString:(NSString *)string options:(NSMatchingOptions)options range:(NSRange)range;
// - (NSUInteger)numberOfMatchesInString:(NSString *)string options:(NSMatchingOptions)options range:(NSRange)range;
// - (nullable NSTextCheckingResult *)firstMatchInString:(NSString *)string options:(NSMatchingOptions)options range:(NSRange)range;
// - (NSRange)rangeOfFirstMatchInString:(NSString *)string options:(NSMatchingOptions)options range:(NSRange)range;
/* @end */



// @interface NSRegularExpression (NSReplacement)



// - (NSString *)stringByReplacingMatchesInString:(NSString *)string options:(NSMatchingOptions)options range:(NSRange)range withTemplate:(NSString *)templ;
// - (NSUInteger)replaceMatchesInString:(NSMutableString *)string options:(NSMatchingOptions)options range:(NSRange)range withTemplate:(NSString *)templ;



// - (NSString *)replacementStringForResult:(NSTextCheckingResult *)result inString:(NSString *)string offset:(NSInteger)offset template:(NSString *)templ;



// + (NSString *)escapedTemplateForString:(NSString *)string;

/* @end */


__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=4_0)))

#ifndef _REWRITER_typedef_NSDataDetector
#define _REWRITER_typedef_NSDataDetector
typedef struct objc_object NSDataDetector;
typedef struct {} _objc_exc_NSDataDetector;
#endif

struct NSDataDetector_IMPL {
	struct NSRegularExpression_IMPL NSRegularExpression_IVARS;
	NSTextCheckingTypes _types;
};




// + (nullable NSDataDetector *)dataDetectorWithTypes:(NSTextCheckingTypes)checkingTypes error:(NSError **)error;
// - (nullable instancetype)initWithTypes:(NSTextCheckingTypes)checkingTypes error:(NSError **)error __attribute__((objc_designated_initializer));

// @property (readonly) NSTextCheckingTypes checkingTypes;

/* @end */









// @class NSTimer;
#ifndef _REWRITER_typedef_NSTimer
#define _REWRITER_typedef_NSTimer
typedef struct objc_object NSTimer;
typedef struct {} _objc_exc_NSTimer;
#endif

#ifndef _REWRITER_typedef_NSPort
#define _REWRITER_typedef_NSPort
typedef struct objc_object NSPort;
typedef struct {} _objc_exc_NSPort;
#endif

#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif




extern "C" NSString * const NSDefaultRunLoopMode;
extern "C" NSString * const NSRunLoopCommonModes __attribute__((availability(ios,introduced=2_0)));


#ifndef _REWRITER_typedef_NSRunLoop
#define _REWRITER_typedef_NSRunLoop
typedef struct objc_object NSRunLoop;
typedef struct {} _objc_exc_NSRunLoop;
#endif

struct NSRunLoop_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _rl;
	__strong id _dperf;
	__strong id _perft;
	__strong id _info;
	__strong id _ports;
	void *_reserved[6];
};


// + (NSRunLoop *)currentRunLoop;
// + (NSRunLoop *)mainRunLoop __attribute__((availability(ios,introduced=2_0)));

// @property (nullable, readonly, copy) NSString *currentMode;

// - (CFRunLoopRef)getCFRunLoop __attribute__((cf_returns_not_retained));

// - (void)addTimer:(NSTimer *)timer forMode:(NSString *)mode;

// - (void)addPort:(NSPort *)aPort forMode:(NSString *)mode;
// - (void)removePort:(NSPort *)aPort forMode:(NSString *)mode;

// - (nullable NSDate *)limitDateForMode:(NSString *)mode;
// - (void)acceptInputForMode:(NSString *)mode beforeDate:(NSDate *)limitDate;

/* @end */


// @interface NSRunLoop (NSRunLoopConveniences)

// - (void)run;
// - (void)runUntilDate:(NSDate *)limitDate;
// - (BOOL)runMode:(NSString *)mode beforeDate:(NSDate *)limitDate;





/* @end */




// @interface NSObject (NSDelayedPerforming)

// - (void)performSelector:(SEL)aSelector withObject:(nullable id)anArgument afterDelay:(NSTimeInterval)delay inModes:(NSArray<NSString *> *)modes;
// - (void)performSelector:(SEL)aSelector withObject:(nullable id)anArgument afterDelay:(NSTimeInterval)delay;
// + (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget selector:(SEL)aSelector object:(nullable id)anArgument;
// + (void)cancelPreviousPerformRequestsWithTarget:(id)aTarget;

/* @end */


// @interface NSRunLoop (NSOrderedPerform)

// - (void)performSelector:(SEL)aSelector target:(id)target argument:(nullable id)arg order:(NSUInteger)order modes:(NSArray<NSString *> *)modes;
// - (void)cancelPerformSelector:(SEL)aSelector target:(id)target argument:(nullable id)arg;
// - (void)cancelPerformSelectorsWithTarget:(id)target;

/* @end */




#ifndef _REWRITER_typedef_NSSortDescriptor
#define _REWRITER_typedef_NSSortDescriptor
typedef struct objc_object NSSortDescriptor;
typedef struct {} _objc_exc_NSSortDescriptor;
#endif

struct NSSortDescriptor_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSUInteger _sortDescriptorFlags;
	NSString *__strong _key;
	SEL _selector;
	__strong id _selectorOrBlock;
};


// + (instancetype)sortDescriptorWithKey:(nullable NSString *)key ascending:(BOOL)ascending __attribute__((availability(ios,introduced=4_0)));
// + (instancetype)sortDescriptorWithKey:(nullable NSString *)key ascending:(BOOL)ascending selector:(nullable SEL)selector __attribute__((availability(ios,introduced=4_0)));


// - (instancetype)initWithKey:(nullable NSString *)key ascending:(BOOL)ascending;
// - (instancetype)initWithKey:(nullable NSString *)key ascending:(BOOL)ascending selector:(nullable SEL)selector;
// - (nullable instancetype)initWithCoder:(NSCoder *)coder;

// @property (nullable, readonly, copy) NSString *key;
// @property (readonly) BOOL ascending;
// @property (nullable, readonly) SEL selector;

// - (void)allowEvaluation __attribute__((availability(ios,introduced=7_0)));

// + (instancetype)sortDescriptorWithKey:(nullable NSString *)key ascending:(BOOL)ascending comparator:(NSComparator)cmptr __attribute__((availability(ios,introduced=4_0)));

// - (instancetype)initWithKey:(nullable NSString *)key ascending:(BOOL)ascending comparator:(NSComparator)cmptr __attribute__((availability(ios,introduced=4_0)));

// @property (readonly) NSComparator comparator __attribute__((availability(ios,introduced=4_0)));

// - (NSComparisonResult)compareObject:(id)object1 toObject:(id)object2;
// @property (readonly, retain) id reversedSortDescriptor;

/* @end */


// @interface NSSet<ObjectType> (NSSortDescriptorSorting)

// - (NSArray<ObjectType> *)sortedArrayUsingDescriptors:(NSArray<NSSortDescriptor *> *)sortDescriptors __attribute__((availability(ios,introduced=4_0)));

/* @end */


// @interface NSArray<ObjectType> (NSSortDescriptorSorting)

// - (NSArray<ObjectType> *)sortedArrayUsingDescriptors:(NSArray<NSSortDescriptor *> *)sortDescriptors;

/* @end */


// @interface NSMutableArray<ObjectType> (NSSortDescriptorSorting)

// - (void)sortUsingDescriptors:(NSArray<NSSortDescriptor *> *)sortDescriptors;

/* @end */


// @interface NSOrderedSet<ObjectType> (NSKeyValueSorting)


// - (NSArray<ObjectType> *)sortedArrayUsingDescriptors:(NSArray<NSSortDescriptor *> *)sortDescriptors __attribute__((availability(ios,introduced=5_0)));

/* @end */


// @interface NSMutableOrderedSet<ObjectType> (NSKeyValueSorting)


// - (void)sortUsingDescriptors:(NSArray<NSSortDescriptor *> *)sortDescriptors __attribute__((availability(ios,introduced=5_0)));

/* @end */







// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSHost
#define _REWRITER_typedef_NSHost
typedef struct objc_object NSHost;
typedef struct {} _objc_exc_NSHost;
#endif

#ifndef _REWRITER_typedef_NSInputStream
#define _REWRITER_typedef_NSInputStream
typedef struct objc_object NSInputStream;
typedef struct {} _objc_exc_NSInputStream;
#endif

#ifndef _REWRITER_typedef_NSOutputStream
#define _REWRITER_typedef_NSOutputStream
typedef struct objc_object NSOutputStream;
typedef struct {} _objc_exc_NSOutputStream;
#endif

#ifndef _REWRITER_typedef_NSRunLoop
#define _REWRITER_typedef_NSRunLoop
typedef struct objc_object NSRunLoop;
typedef struct {} _objc_exc_NSRunLoop;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

// @protocol NSStreamDelegate;



typedef NSUInteger NSStreamStatus; enum {
    NSStreamStatusNotOpen = 0,
    NSStreamStatusOpening = 1,
    NSStreamStatusOpen = 2,
    NSStreamStatusReading = 3,
    NSStreamStatusWriting = 4,
    NSStreamStatusAtEnd = 5,
    NSStreamStatusClosed = 6,
    NSStreamStatusError = 7
};

typedef NSUInteger NSStreamEvent; enum {
    NSStreamEventNone = 0,
    NSStreamEventOpenCompleted = 1UL << 0,
    NSStreamEventHasBytesAvailable = 1UL << 1,
    NSStreamEventHasSpaceAvailable = 1UL << 2,
    NSStreamEventErrorOccurred = 1UL << 3,
    NSStreamEventEndEncountered = 1UL << 4
};




#ifndef _REWRITER_typedef_NSStream
#define _REWRITER_typedef_NSStream
typedef struct objc_object NSStream;
typedef struct {} _objc_exc_NSStream;
#endif

struct NSStream_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};

// - (void)open;
// - (void)close;

// @property (nullable, assign) id <NSStreamDelegate> delegate;


// - (nullable id)propertyForKey:(NSString *)key;
// - (BOOL)setProperty:(nullable id)property forKey:(NSString *)key;

// - (void)scheduleInRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;
// - (void)removeFromRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;

// @property (readonly) NSStreamStatus streamStatus;
// @property (nullable, readonly, copy) NSError *streamError;
/* @end */





#ifndef _REWRITER_typedef_NSInputStream
#define _REWRITER_typedef_NSInputStream
typedef struct objc_object NSInputStream;
typedef struct {} _objc_exc_NSInputStream;
#endif

struct NSInputStream_IMPL {
	struct NSStream_IMPL NSStream_IVARS;
};

// - (NSInteger)read:(uint8_t *)buffer maxLength:(NSUInteger)len;


// - (BOOL)getBuffer:(uint8_t * _Nullable * _Nonnull)buffer length:(NSUInteger *)len;


// @property (readonly) BOOL hasBytesAvailable;


// - (instancetype)initWithData:(NSData *)data __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithURL:(NSURL *)url __attribute__((availability(ios,introduced=4_0))) __attribute__((objc_designated_initializer));

/* @end */





#ifndef _REWRITER_typedef_NSOutputStream
#define _REWRITER_typedef_NSOutputStream
typedef struct objc_object NSOutputStream;
typedef struct {} _objc_exc_NSOutputStream;
#endif

struct NSOutputStream_IMPL {
	struct NSStream_IMPL NSStream_IVARS;
};

// - (NSInteger)write:(const uint8_t *)buffer maxLength:(NSUInteger)len;


// @property (readonly) BOOL hasSpaceAvailable;


// - (instancetype)initToMemory __attribute__((objc_designated_initializer));
// - (instancetype)initToBuffer:(uint8_t *)buffer capacity:(NSUInteger)capacity __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithURL:(NSURL *)url append:(BOOL)shouldAppend __attribute__((availability(ios,introduced=4_0))) __attribute__((objc_designated_initializer));

/* @end */



// @interface NSStream (NSSocketStreamCreationExtensions)

// + (void)getStreamsToHostWithName:(NSString *)hostname port:(NSInteger)port inputStream:(NSInputStream * _Nullable * _Nullable)inputStream outputStream:(NSOutputStream * _Nullable * _Nullable)outputStream __attribute__((availability(ios,introduced=8_0))) __attribute__((availability(watchos,unavailable)));





/* @end */


// @interface NSStream (NSStreamBoundPairCreationExtensions)
// + (void)getBoundStreamsWithBufferSize:(NSUInteger)bufferSize inputStream:(NSInputStream * _Nullable * _Nullable)inputStream outputStream:(NSOutputStream * _Nullable * _Nullable)outputStream __attribute__((availability(ios,introduced=8_0)));
/* @end */



// @interface NSInputStream (NSInputStreamExtensions)
// - (nullable instancetype)initWithFileAtPath:(NSString *)path;

// + (nullable instancetype)inputStreamWithData:(NSData *)data;
// + (nullable instancetype)inputStreamWithFileAtPath:(NSString *)path;
// + (nullable instancetype)inputStreamWithURL:(NSURL *)url __attribute__((availability(ios,introduced=4_0)));
/* @end */



// @interface NSOutputStream (NSOutputStreamExtensions)
// - (nullable instancetype)initToFileAtPath:(NSString *)path append:(BOOL)shouldAppend;

// + (instancetype)outputStreamToMemory;
// + (instancetype)outputStreamToBuffer:(uint8_t *)buffer capacity:(NSUInteger)capacity;
// + (instancetype)outputStreamToFileAtPath:(NSString *)path append:(BOOL)shouldAppend;
// + (nullable instancetype)outputStreamWithURL:(NSURL *)url append:(BOOL)shouldAppend __attribute__((availability(ios,introduced=4_0)));
/* @end */


// @protocol NSStreamDelegate <NSObject>
/* @optional */
// - (void)stream:(NSStream *)aStream handleEvent:(NSStreamEvent)eventCode;
/* @end */




extern "C" NSString * const NSStreamSocketSecurityLevelKey __attribute__((availability(ios,introduced=2_0)));

extern "C" NSString * const NSStreamSocketSecurityLevelNone __attribute__((availability(ios,introduced=2_0)));
extern "C" NSString * const NSStreamSocketSecurityLevelSSLv2 __attribute__((availability(ios,introduced=2_0)));
extern "C" NSString * const NSStreamSocketSecurityLevelSSLv3 __attribute__((availability(ios,introduced=2_0)));
extern "C" NSString * const NSStreamSocketSecurityLevelTLSv1 __attribute__((availability(ios,introduced=2_0)));
extern "C" NSString * const NSStreamSocketSecurityLevelNegotiatedSSL __attribute__((availability(ios,introduced=2_0)));

extern "C" NSString * const NSStreamSOCKSProxyConfigurationKey __attribute__((availability(ios,introduced=2_0)));

extern "C" NSString * const NSStreamSOCKSProxyHostKey __attribute__((availability(ios,introduced=2_0)));

extern "C" NSString * const NSStreamSOCKSProxyPortKey __attribute__((availability(ios,introduced=2_0)));

extern "C" NSString * const NSStreamSOCKSProxyVersionKey __attribute__((availability(ios,introduced=2_0)));

extern "C" NSString * const NSStreamSOCKSProxyUserKey __attribute__((availability(ios,introduced=2_0)));

extern "C" NSString * const NSStreamSOCKSProxyPasswordKey __attribute__((availability(ios,introduced=2_0)));


extern "C" NSString * const NSStreamSOCKSProxyVersion4 __attribute__((availability(ios,introduced=2_0)));

extern "C" NSString * const NSStreamSOCKSProxyVersion5 __attribute__((availability(ios,introduced=2_0)));


extern "C" NSString * const NSStreamDataWrittenToMemoryStreamKey __attribute__((availability(ios,introduced=2_0)));


extern "C" NSString * const NSStreamFileCurrentOffsetKey __attribute__((availability(ios,introduced=2_0)));



extern "C" NSString * const NSStreamSocketSSLErrorDomain __attribute__((availability(ios,introduced=2_0)));

extern "C" NSString * const NSStreamSOCKSErrorDomain __attribute__((availability(ios,introduced=2_0)));






extern "C" NSString * const NSStreamNetworkServiceType __attribute__((availability(ios,introduced=4_0)));

extern "C" NSString * const NSStreamNetworkServiceTypeVoIP __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSStreamNetworkServiceTypeVideo __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSStreamNetworkServiceTypeBackground __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSStreamNetworkServiceTypeVoice __attribute__((availability(ios,introduced=5_0)));









// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSMutableDictionary
#define _REWRITER_typedef_NSMutableDictionary
typedef struct objc_object NSMutableDictionary;
typedef struct {} _objc_exc_NSMutableDictionary;
#endif

#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
typedef struct objc_object NSNumber;
typedef struct {} _objc_exc_NSNumber;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif





#ifndef _REWRITER_typedef_NSThread
#define _REWRITER_typedef_NSThread
typedef struct objc_object NSThread;
typedef struct {} _objc_exc_NSThread;
#endif

struct NSThread_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _private;
	uint8_t _bytes[44];
};


// + (NSThread *)currentThread;

// + (void)detachNewThreadSelector:(SEL)selector toTarget:(id)target withObject:(nullable id)argument;

// + (BOOL)isMultiThreaded;

// @property (readonly, retain) NSMutableDictionary *threadDictionary;

// + (void)sleepUntilDate:(NSDate *)date;
// + (void)sleepForTimeInterval:(NSTimeInterval)ti;

// + (void)exit;

// + (double)threadPriority;
// + (BOOL)setThreadPriority:(double)p;

// @property double threadPriority __attribute__((availability(ios,introduced=4_0)));

// @property NSQualityOfService qualityOfService __attribute__((availability(ios,introduced=8_0)));

// + (NSArray<NSNumber *> *)callStackReturnAddresses __attribute__((availability(ios,introduced=2_0)));
// + (NSArray<NSString *> *)callStackSymbols __attribute__((availability(ios,introduced=4_0)));

// @property (nullable, copy) NSString *name __attribute__((availability(ios,introduced=2_0)));

// @property NSUInteger stackSize __attribute__((availability(ios,introduced=2_0)));

// @property (readonly) BOOL isMainThread __attribute__((availability(ios,introduced=2_0)));
// + (BOOL)isMainThread __attribute__((availability(ios,introduced=2_0)));
// + (NSThread *)mainThread __attribute__((availability(ios,introduced=2_0)));

// - (instancetype)init __attribute__((availability(ios,introduced=2_0))) __attribute__((objc_designated_initializer));
// - (instancetype)initWithTarget:(id)target selector:(SEL)selector object:(nullable id)argument __attribute__((availability(ios,introduced=2_0)));

// @property (readonly, getter=isExecuting) BOOL executing __attribute__((availability(ios,introduced=2_0)));
// @property (readonly, getter=isFinished) BOOL finished __attribute__((availability(ios,introduced=2_0)));
// @property (readonly, getter=isCancelled) BOOL cancelled __attribute__((availability(ios,introduced=2_0)));

// - (void)cancel __attribute__((availability(ios,introduced=2_0)));

// - (void)start __attribute__((availability(ios,introduced=2_0)));

// - (void)main __attribute__((availability(ios,introduced=2_0)));

/* @end */


extern "C" NSString * const NSWillBecomeMultiThreadedNotification;
extern "C" NSString * const NSDidBecomeSingleThreadedNotification;
extern "C" NSString * const NSThreadWillExitNotification;

// @interface NSObject (NSThreadPerformAdditions)

// - (void)performSelectorOnMainThread:(SEL)aSelector withObject:(nullable id)arg waitUntilDone:(BOOL)wait modes:(nullable NSArray<NSString *> *)array;
// - (void)performSelectorOnMainThread:(SEL)aSelector withObject:(nullable id)arg waitUntilDone:(BOOL)wait;


// - (void)performSelector:(SEL)aSelector onThread:(NSThread *)thr withObject:(nullable id)arg waitUntilDone:(BOOL)wait modes:(nullable NSArray<NSString *> *)array __attribute__((availability(ios,introduced=2_0)));
// - (void)performSelector:(SEL)aSelector onThread:(NSThread *)thr withObject:(nullable id)arg waitUntilDone:(BOOL)wait __attribute__((availability(ios,introduced=2_0)));

// - (void)performSelectorInBackground:(SEL)aSelector withObject:(nullable id)arg __attribute__((availability(ios,introduced=2_0)));

/* @end */








// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSLocale
#define _REWRITER_typedef_NSLocale
typedef struct objc_object NSLocale;
typedef struct {} _objc_exc_NSLocale;
#endif





#ifndef _REWRITER_typedef_NSTimeZone
#define _REWRITER_typedef_NSTimeZone
typedef struct objc_object NSTimeZone;
typedef struct {} _objc_exc_NSTimeZone;
#endif

struct NSTimeZone_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly, copy) NSString *name;
// @property (readonly, copy) NSData *data;

// - (NSInteger)secondsFromGMTForDate:(NSDate *)aDate;
// - (nullable NSString *)abbreviationForDate:(NSDate *)aDate;
// - (BOOL)isDaylightSavingTimeForDate:(NSDate *)aDate;
// - (NSTimeInterval)daylightSavingTimeOffsetForDate:(NSDate *)aDate __attribute__((availability(ios,introduced=2_0)));
// - (nullable NSDate *)nextDaylightSavingTimeTransitionAfterDate:(NSDate *)aDate __attribute__((availability(ios,introduced=2_0)));

/* @end */


// @interface NSTimeZone (NSExtendedTimeZone)

// + (NSTimeZone *)systemTimeZone;
// + (void)resetSystemTimeZone;

// + (NSTimeZone *)defaultTimeZone;
// + (void)setDefaultTimeZone:(NSTimeZone *)aTimeZone;

// + (NSTimeZone *)localTimeZone;

// + (NSArray<NSString *> *)knownTimeZoneNames;

// + (NSDictionary<NSString *, NSString *> *)abbreviationDictionary;
// + (void)setAbbreviationDictionary:(NSDictionary<NSString *, NSString *> *)dict __attribute__((availability(ios,introduced=4_0)));

// + (NSString *)timeZoneDataVersion __attribute__((availability(ios,introduced=4_0)));

// @property (readonly) NSInteger secondsFromGMT;
// @property (nullable, readonly, copy) NSString *abbreviation;
// @property (readonly, getter=isDaylightSavingTime) BOOL daylightSavingTime;
// @property (readonly) NSTimeInterval daylightSavingTimeOffset __attribute__((availability(ios,introduced=2_0)));
// @property (nullable, readonly, copy) NSDate *nextDaylightSavingTimeTransition __attribute__((availability(ios,introduced=2_0)));

// @property (readonly, copy) NSString *description;

// - (BOOL)isEqualToTimeZone:(NSTimeZone *)aTimeZone;

typedef NSInteger NSTimeZoneNameStyle; enum {
 NSTimeZoneNameStyleStandard,
 NSTimeZoneNameStyleShortStandard,
 NSTimeZoneNameStyleDaylightSaving,
 NSTimeZoneNameStyleShortDaylightSaving,
 NSTimeZoneNameStyleGeneric,
 NSTimeZoneNameStyleShortGeneric
};

// - (nullable NSString *)localizedName:(NSTimeZoneNameStyle)style locale:(nullable NSLocale *)locale __attribute__((availability(ios,introduced=2_0)));

/* @end */


// @interface NSTimeZone (NSTimeZoneCreation)




// + (nullable instancetype)timeZoneWithName:(NSString *)tzName;
// + (nullable instancetype)timeZoneWithName:(NSString *)tzName data:(nullable NSData *)aData;

// - (nullable instancetype)initWithName:(NSString *)tzName;
// - (nullable instancetype)initWithName:(NSString *)tzName data:(nullable NSData *)aData;




// + (instancetype)timeZoneForSecondsFromGMT:(NSInteger)seconds;

// + (nullable instancetype)timeZoneWithAbbreviation:(NSString *)abbreviation;

/* @end */


extern "C" NSString * const NSSystemTimeZoneDidChangeNotification __attribute__((availability(ios,introduced=2_0)));

#ifndef _REWRITER_typedef_NSTimer
#define _REWRITER_typedef_NSTimer
typedef struct objc_object NSTimer;
typedef struct {} _objc_exc_NSTimer;
#endif

struct NSTimer_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// + (NSTimer *)timerWithTimeInterval:(NSTimeInterval)ti invocation:(NSInvocation *)invocation repeats:(BOOL)yesOrNo;
// + (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)ti invocation:(NSInvocation *)invocation repeats:(BOOL)yesOrNo;

// + (NSTimer *)timerWithTimeInterval:(NSTimeInterval)ti target:(id)aTarget selector:(SEL)aSelector userInfo:(nullable id)userInfo repeats:(BOOL)yesOrNo;
// + (NSTimer *)scheduledTimerWithTimeInterval:(NSTimeInterval)ti target:(id)aTarget selector:(SEL)aSelector userInfo:(nullable id)userInfo repeats:(BOOL)yesOrNo;

// - (instancetype)initWithFireDate:(NSDate *)date interval:(NSTimeInterval)ti target:(id)t selector:(SEL)s userInfo:(nullable id)ui repeats:(BOOL)rep __attribute__((objc_designated_initializer));

// - (void)fire;

// @property (copy) NSDate *fireDate;
// @property (readonly) NSTimeInterval timeInterval;



// @property NSTimeInterval tolerance __attribute__((availability(ios,introduced=7_0)));

// - (void)invalidate;
// @property (readonly, getter=isValid) BOOL valid;

// @property (nullable, readonly, retain) id userInfo;

/* @end */

// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
typedef struct objc_object NSNumber;
typedef struct {} _objc_exc_NSNumber;
#endif

#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif






#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

struct NSURL_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSString *__strong _urlString;
	NSURL *__strong _baseURL;
	void *_clients;
	void *_reserved;
};





extern "C" NSString *NSURLFileScheme;




// - (nullable instancetype)initWithScheme:(NSString *)scheme host:(nullable NSString *)host path:(NSString *)path __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLComponents instead, which lets you create a valid URL with any valid combination of URL components and subcomponents (not just scheme, host and path), and lets you set components and subcomponents with either percent-encoded or un-percent-encoded strings.")));



// - (instancetype)initFileURLWithPath:(NSString *)path isDirectory:(BOOL)isDir relativeToURL:(nullable NSURL *)baseURL __attribute__((availability(ios,introduced=9_0))) __attribute__((objc_designated_initializer));


// - (instancetype)initFileURLWithPath:(NSString *)path relativeToURL:(nullable NSURL *)baseURL __attribute__((availability(ios,introduced=9_0))) __attribute__((objc_designated_initializer));

// - (instancetype)initFileURLWithPath:(NSString *)path isDirectory:(BOOL)isDir __attribute__((availability(ios,introduced=2_0))) __attribute__((objc_designated_initializer));
// - (instancetype)initFileURLWithPath:(NSString *)path __attribute__((objc_designated_initializer));



// + (NSURL *)fileURLWithPath:(NSString *)path isDirectory:(BOOL) isDir relativeToURL:(nullable NSURL *)baseURL __attribute__((availability(ios,introduced=9_0)));


// + (NSURL *)fileURLWithPath:(NSString *)path relativeToURL:(nullable NSURL *)baseURL __attribute__((availability(ios,introduced=9_0)));

// + (NSURL *)fileURLWithPath:(NSString *)path isDirectory:(BOOL)isDir __attribute__((availability(ios,introduced=2_0)));
// + (NSURL *)fileURLWithPath:(NSString *)path;



// - (instancetype)initFileURLWithFileSystemRepresentation:(const char *)path isDirectory:(BOOL)isDir relativeToURL:(nullable NSURL *)baseURL __attribute__((availability(ios,introduced=7_0))) __attribute__((objc_designated_initializer));



// + (NSURL *)fileURLWithFileSystemRepresentation:(const char *)path isDirectory:(BOOL) isDir relativeToURL:(nullable NSURL *)baseURL __attribute__((availability(ios,introduced=7_0)));



// - (nullable instancetype)initWithString:(NSString *)URLString;
// - (nullable instancetype)initWithString:(NSString *)URLString relativeToURL:(nullable NSURL *)baseURL __attribute__((objc_designated_initializer));
// + (nullable instancetype)URLWithString:(NSString *)URLString;
// + (nullable instancetype)URLWithString:(NSString *)URLString relativeToURL:(nullable NSURL *)baseURL;




// - (instancetype)initWithDataRepresentation:(NSData *)data relativeToURL:(nullable NSURL *)baseURL __attribute__((availability(ios,introduced=9_0))) __attribute__((objc_designated_initializer));


// + (NSURL *)URLWithDataRepresentation:(NSData *)data relativeToURL:(nullable NSURL *)baseURL __attribute__((availability(ios,introduced=9_0)));



// - (instancetype)initAbsoluteURLWithDataRepresentation:(NSData *)data relativeToURL:(nullable NSURL *)baseURL __attribute__((availability(ios,introduced=9_0))) __attribute__((objc_designated_initializer));


// + (NSURL *)absoluteURLWithDataRepresentation:(NSData *)data relativeToURL:(nullable NSURL *)baseURL __attribute__((availability(ios,introduced=9_0)));



// @property (readonly, copy) NSData *dataRepresentation __attribute__((availability(ios,introduced=9_0)));

// @property (readonly, copy) NSString *absoluteString;
// @property (nullable, readonly, copy) NSString *relativeString;
// @property (nullable, readonly, copy) NSURL *baseURL;
// @property (readonly, copy) NSURL *absoluteURL;



// @property (readonly, copy) NSString *scheme;
// @property (readonly, copy) NSString *resourceSpecifier;



// @property (nullable, readonly, copy) NSString *host;
// @property (nullable, readonly, copy) NSNumber *port;
// @property (nullable, readonly, copy) NSString *user;
// @property (nullable, readonly, copy) NSString *password;
// @property (nullable, readonly, copy) NSString *path;
// @property (nullable, readonly, copy) NSString *fragment;
// @property (nullable, readonly, copy) NSString *parameterString;
// @property (nullable, readonly, copy) NSString *query;
// @property (nullable, readonly, copy) NSString *relativePath;



// @property (readonly) BOOL hasDirectoryPath __attribute__((availability(ios,introduced=9_0)));



// - (BOOL)getFileSystemRepresentation:(char *)buffer maxLength:(NSUInteger)maxBufferLength __attribute__((availability(ios,introduced=7_0)));



// @property (readonly) __attribute__((objc_ownership(strong))) const char *fileSystemRepresentation __attribute__((objc_returns_inner_pointer)) __attribute__((availability(ios,introduced=7_0)));

// @property (readonly, getter=isFileURL) BOOL fileURL;

// @property (nullable, readonly, copy) NSURL *standardizedURL;




// - (BOOL)checkResourceIsReachableAndReturnError:(NSError **)error __attribute__((swift_error(none))) __attribute__((availability(ios,introduced=4_0)));







// - (BOOL)isFileReferenceURL __attribute__((availability(ios,introduced=4_0)));



// - (nullable NSURL *)fileReferenceURL __attribute__((availability(ios,introduced=4_0)));



// @property (nullable, readonly, copy) NSURL *filePathURL __attribute__((availability(ios,introduced=4_0)));
// - (BOOL)getResourceValue:(out id _Nullable * _Nonnull)value forKey:(NSString *)key error:(out NSError ** _Nullable)error __attribute__((availability(ios,introduced=4_0)));



// - (nullable NSDictionary<NSString *, id> *)resourceValuesForKeys:(NSArray<NSString *> *)keys error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));



// - (BOOL)setResourceValue:(nullable id)value forKey:(NSString *)key error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));



// - (BOOL)setResourceValues:(NSDictionary<NSString *, id> *)keyedValues error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));

extern "C" NSString * const NSURLKeysOfUnsetValuesKey __attribute__((availability(ios,introduced=5_0)));



// - (void)removeCachedResourceValueForKey:(NSString *)key __attribute__((availability(ios,introduced=7_0)));



// - (void)removeAllCachedResourceValues __attribute__((availability(ios,introduced=7_0)));



// - (void)setTemporaryResourceValue:(nullable id)value forKey:(NSString *)key __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSURLNameKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLLocalizedNameKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLIsRegularFileKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLIsDirectoryKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLIsSymbolicLinkKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLIsVolumeKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLIsPackageKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLIsApplicationKey __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSURLApplicationIsScriptableKey __attribute__((availability(ios,introduced=NA)));
extern "C" NSString * const NSURLIsSystemImmutableKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLIsUserImmutableKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLIsHiddenKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLHasHiddenExtensionKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLCreationDateKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLContentAccessDateKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLContentModificationDateKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLAttributeModificationDateKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLLinkCountKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLParentDirectoryURLKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeURLKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLTypeIdentifierKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLLocalizedTypeDescriptionKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLLabelNumberKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLLabelColorKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLLocalizedLabelKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLEffectiveIconKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLCustomIconKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLFileResourceIdentifierKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeIdentifierKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLPreferredIOBlockSizeKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLIsReadableKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLIsWritableKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLIsExecutableKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLFileSecurityKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLIsExcludedFromBackupKey __attribute__((availability(ios,introduced=5_1)));
extern "C" NSString * const NSURLTagNamesKey __attribute__((availability(ios,introduced=NA)));
extern "C" NSString * const NSURLPathKey __attribute__((availability(ios,introduced=6_0)));
extern "C" NSString * const NSURLIsMountTriggerKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLGenerationIdentifierKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSURLDocumentIdentifierKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSURLAddedToDirectoryDateKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSURLQuarantinePropertiesKey __attribute__((availability(ios,introduced=NA)));
extern "C" NSString * const NSURLFileResourceTypeKey __attribute__((availability(ios,introduced=5_0)));



extern "C" NSString * const NSURLFileResourceTypeNamedPipe __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLFileResourceTypeCharacterSpecial __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLFileResourceTypeDirectory __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLFileResourceTypeBlockSpecial __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLFileResourceTypeRegular __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLFileResourceTypeSymbolicLink __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLFileResourceTypeSocket __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLFileResourceTypeUnknown __attribute__((availability(ios,introduced=5_0)));

extern "C" NSString * const NSURLThumbnailDictionaryKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSURLThumbnailKey __attribute__((availability(ios,unavailable)));



extern "C" NSString * const NSThumbnail1024x1024SizeKey __attribute__((availability(ios,introduced=8_0)));



extern "C" NSString * const NSURLFileSizeKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLFileAllocatedSizeKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLTotalFileSizeKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLTotalFileAllocatedSizeKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLIsAliasFileKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLFileProtectionKey __attribute__((availability(ios,introduced=9_0)));



extern "C" NSString * const NSURLFileProtectionNone __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSURLFileProtectionComplete __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSURLFileProtectionCompleteUnlessOpen __attribute__((availability(ios,introduced=9_0)));
extern "C" NSString * const NSURLFileProtectionCompleteUntilFirstUserAuthentication __attribute__((availability(ios,introduced=9_0)));





extern "C" NSString * const NSURLVolumeLocalizedFormatDescriptionKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeTotalCapacityKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeAvailableCapacityKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeResourceCountKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeSupportsPersistentIDsKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeSupportsSymbolicLinksKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeSupportsHardLinksKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeSupportsJournalingKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeIsJournalingKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeSupportsSparseFilesKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeSupportsZeroRunsKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeSupportsCaseSensitiveNamesKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeSupportsCasePreservedNamesKey __attribute__((availability(ios,introduced=4_0)));
extern "C" NSString * const NSURLVolumeSupportsRootDirectoryDatesKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeSupportsVolumeSizesKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeSupportsRenamingKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeSupportsAdvisoryFileLockingKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeSupportsExtendedSecurityKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeIsBrowsableKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeMaximumFileSizeKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeIsEjectableKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeIsRemovableKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeIsInternalKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeIsAutomountedKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeIsLocalKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeIsReadOnlyKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeCreationDateKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeURLForRemountingKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeUUIDStringKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeNameKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLVolumeLocalizedNameKey __attribute__((availability(ios,introduced=5_0)));



extern "C" NSString * const NSURLIsUbiquitousItemKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLUbiquitousItemHasUnresolvedConflictsKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLUbiquitousItemIsDownloadedKey __attribute__((availability(ios,introduced=5_0,deprecated=7_0,message="" "Use NSURLUbiquitousItemDownloadingStatusKey instead")));
extern "C" NSString * const NSURLUbiquitousItemIsDownloadingKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLUbiquitousItemIsUploadedKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLUbiquitousItemIsUploadingKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSURLUbiquitousItemPercentDownloadedKey __attribute__((availability(ios,introduced=5_0,deprecated=6_0,message="" )));
extern "C" NSString * const NSURLUbiquitousItemPercentUploadedKey __attribute__((availability(ios,introduced=5_0,deprecated=6_0,message="" )));
extern "C" NSString * const NSURLUbiquitousItemDownloadingStatusKey __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSURLUbiquitousItemDownloadingErrorKey __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSURLUbiquitousItemUploadingErrorKey __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSURLUbiquitousItemDownloadRequestedKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSURLUbiquitousItemContainerDisplayNameKey __attribute__((availability(ios,introduced=8_0)));




extern "C" NSString * const NSURLUbiquitousItemDownloadingStatusNotDownloaded __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSURLUbiquitousItemDownloadingStatusDownloaded __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSURLUbiquitousItemDownloadingStatusCurrent __attribute__((availability(ios,introduced=7_0)));




typedef NSUInteger NSURLBookmarkCreationOptions; enum {
    NSURLBookmarkCreationPreferFileIDResolution __attribute__((availability(ios,introduced=4_0,deprecated=7_0,message="" ))) = ( 1UL << 8 ),
    NSURLBookmarkCreationMinimalBookmark = ( 1UL << 9 ),
    NSURLBookmarkCreationSuitableForBookmarkFile = ( 1UL << 10 ),
    NSURLBookmarkCreationWithSecurityScope __attribute__((availability(ios,introduced=NA))) = ( 1 << 11 ),
    NSURLBookmarkCreationSecurityScopeAllowOnlyReadAccess __attribute__((availability(ios,introduced=NA))) = ( 1 << 12 ),
} __attribute__((availability(ios,introduced=4_0)));

typedef NSUInteger NSURLBookmarkResolutionOptions; enum {
    NSURLBookmarkResolutionWithoutUI = ( 1UL << 8 ),
    NSURLBookmarkResolutionWithoutMounting = ( 1UL << 9 ),
    NSURLBookmarkResolutionWithSecurityScope __attribute__((availability(ios,introduced=NA))) = ( 1 << 10 )
} __attribute__((availability(ios,introduced=4_0)));

typedef NSUInteger NSURLBookmarkFileCreationOptions;



// - (nullable NSData *)bookmarkDataWithOptions:(NSURLBookmarkCreationOptions)options includingResourceValuesForKeys:(nullable NSArray<NSString *> *)keys relativeToURL:(nullable NSURL *)relativeURL error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));



// - (nullable instancetype)initByResolvingBookmarkData:(NSData *)bookmarkData options:(NSURLBookmarkResolutionOptions)options relativeToURL:(nullable NSURL *)relativeURL bookmarkDataIsStale:(BOOL * _Nullable)isStale error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));


// + (nullable instancetype)URLByResolvingBookmarkData:(NSData *)bookmarkData options:(NSURLBookmarkResolutionOptions)options relativeToURL:(nullable NSURL *)relativeURL bookmarkDataIsStale:(BOOL * _Nullable)isStale error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));



// + (nullable NSDictionary<NSString *, id> *)resourceValuesForKeys:(NSArray<NSString *> *)keys fromBookmarkData:(NSData *)bookmarkData __attribute__((availability(ios,introduced=4_0)));



// + (BOOL)writeBookmarkData:(NSData *)bookmarkData toURL:(NSURL *)bookmarkFileURL options:(NSURLBookmarkFileCreationOptions)options error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));



// + (nullable NSData *)bookmarkDataWithContentsOfURL:(NSURL *)bookmarkFileURL error:(NSError **)error __attribute__((availability(ios,introduced=4_0)));



// + (nullable instancetype)URLByResolvingAliasFileAtURL:(NSURL *)url options:(NSURLBookmarkResolutionOptions)options error:(NSError **)error __attribute__((availability(ios,introduced=8_0)));



// - (BOOL)startAccessingSecurityScopedResource __attribute__((availability(ios,introduced=8_0)));



// - (void)stopAccessingSecurityScopedResource __attribute__((availability(ios,introduced=8_0)));

/* @end */



// @interface NSURL (NSPromisedItems)
// - (BOOL)getPromisedItemResourceValue:(id _Nullable * _Nonnull)value forKey:(NSString *)key error:(NSError **)error __attribute__((availability(ios,introduced=8_0)));
// - (nullable NSDictionary<NSString *, id> *)promisedItemResourceValuesForKeys:(NSArray<NSString *> *)keys error:(NSError **)error __attribute__((availability(ios,introduced=8_0)));
// - (BOOL)checkPromisedItemIsReachableAndReturnError:(NSError **)error __attribute__((swift_error(none))) __attribute__((availability(ios,introduced=8_0)));

/* @end */




__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=8_0)))


#ifndef _REWRITER_typedef_NSURLQueryItem
#define _REWRITER_typedef_NSURLQueryItem
typedef struct objc_object NSURLQueryItem;
typedef struct {} _objc_exc_NSURLQueryItem;
#endif

struct NSURLQueryItem_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSString *__strong _name;
	NSString *__strong _value;
};

// - (instancetype)initWithName:(NSString *)name value:(nullable NSString *)value __attribute__((objc_designated_initializer));
// + (instancetype)queryItemWithName:(NSString *)name value:(nullable NSString *)value;
// @property (readonly) NSString *name;
// @property (nullable, readonly) NSString *value;
/* @end */



__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=7_0)))

#ifndef _REWRITER_typedef_NSURLComponents
#define _REWRITER_typedef_NSURLComponents
typedef struct objc_object NSURLComponents;
typedef struct {} _objc_exc_NSURLComponents;
#endif

struct NSURLComponents_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};



// - (instancetype)init;


// - (nullable instancetype)initWithURL:(NSURL *)url resolvingAgainstBaseURL:(BOOL)resolve;


// + (nullable instancetype)componentsWithURL:(NSURL *)url resolvingAgainstBaseURL:(BOOL)resolve;


// - (nullable instancetype)initWithString:(NSString *)URLString;


// + (nullable instancetype)componentsWithString:(NSString *)URLString;


// @property (nullable, readonly, copy) NSURL *URL;


// - (nullable NSURL *)URLRelativeToURL:(nullable NSURL *)baseURL;


// @property (nullable, readonly, copy) NSString *string __attribute__((availability(ios,introduced=8_0)));




// @property (nullable, copy) NSString *scheme;
// @property (nullable, copy) NSString *user;
// @property (nullable, copy) NSString *password;
// @property (nullable, copy) NSString *host;
// @property (nullable, copy) NSNumber *port;
// @property (nullable, copy) NSString *path;
// @property (nullable, copy) NSString *query;
// @property (nullable, copy) NSString *fragment;


// @property (nullable, copy) NSString *percentEncodedUser;
// @property (nullable, copy) NSString *percentEncodedPassword;
// @property (nullable, copy) NSString *percentEncodedHost;
// @property (nullable, copy) NSString *percentEncodedPath;
// @property (nullable, copy) NSString *percentEncodedQuery;
// @property (nullable, copy) NSString *percentEncodedFragment;



// @property (readonly) NSRange rangeOfScheme __attribute__((availability(ios,introduced=9_0)));
// @property (readonly) NSRange rangeOfUser __attribute__((availability(ios,introduced=9_0)));
// @property (readonly) NSRange rangeOfPassword __attribute__((availability(ios,introduced=9_0)));
// @property (readonly) NSRange rangeOfHost __attribute__((availability(ios,introduced=9_0)));
// @property (readonly) NSRange rangeOfPort __attribute__((availability(ios,introduced=9_0)));
// @property (readonly) NSRange rangeOfPath __attribute__((availability(ios,introduced=9_0)));
// @property (readonly) NSRange rangeOfQuery __attribute__((availability(ios,introduced=9_0)));
// @property (readonly) NSRange rangeOfFragment __attribute__((availability(ios,introduced=9_0)));




// @property (nullable, copy) NSArray<NSURLQueryItem *> *queryItems __attribute__((availability(ios,introduced=8_0)));

/* @end */



// @interface NSCharacterSet (NSURLUtilities)




// + (NSCharacterSet *)URLUserAllowedCharacterSet __attribute__((availability(ios,introduced=7_0)));


// + (NSCharacterSet *)URLPasswordAllowedCharacterSet __attribute__((availability(ios,introduced=7_0)));


// + (NSCharacterSet *)URLHostAllowedCharacterSet __attribute__((availability(ios,introduced=7_0)));


// + (NSCharacterSet *)URLPathAllowedCharacterSet __attribute__((availability(ios,introduced=7_0)));


// + (NSCharacterSet *)URLQueryAllowedCharacterSet __attribute__((availability(ios,introduced=7_0)));


// + (NSCharacterSet *)URLFragmentAllowedCharacterSet __attribute__((availability(ios,introduced=7_0)));

/* @end */



// @interface NSString (NSURLUtilities)


// - (nullable NSString *)stringByAddingPercentEncodingWithAllowedCharacters:(NSCharacterSet *)allowedCharacters __attribute__((availability(ios,introduced=7_0)));


// @property (nullable, readonly, copy) NSString *stringByRemovingPercentEncoding __attribute__((availability(ios,introduced=7_0)));


// - (nullable NSString *)stringByAddingPercentEscapesUsingEncoding:(NSStringEncoding)enc __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use -stringByAddingPercentEncodingWithAllowedCharacters: instead, which always uses the recommended UTF-8 encoding, and which encodes for a specific URL component or subcomponent since each URL component or subcomponent has different rules for what characters are valid.")));
// - (nullable NSString *)stringByReplacingPercentEscapesUsingEncoding:(NSStringEncoding)enc __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use -stringByRemovingPercentEncoding instead, which always uses the recommended UTF-8 encoding.")));

/* @end */



// @interface NSURL (NSURLPathUtilities)



// + (nullable NSURL *)fileURLWithPathComponents:(NSArray<NSString *> *)components __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSArray<NSString *> *pathComponents __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSString *lastPathComponent __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSString *pathExtension __attribute__((availability(ios,introduced=4_0)));
// - (NSURL *)URLByAppendingPathComponent:(NSString *)pathComponent __attribute__((availability(ios,introduced=4_0)));
// - (NSURL *)URLByAppendingPathComponent:(NSString *)pathComponent isDirectory:(BOOL)isDirectory __attribute__((availability(ios,introduced=5_0)));
// @property (nullable, readonly, copy) NSURL *URLByDeletingLastPathComponent __attribute__((availability(ios,introduced=4_0)));
// - (NSURL *)URLByAppendingPathExtension:(NSString *)pathExtension __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSURL *URLByDeletingPathExtension __attribute__((availability(ios,introduced=4_0)));



// @property (nullable, readonly, copy) NSURL *URLByStandardizingPath __attribute__((availability(ios,introduced=4_0)));
// @property (nullable, readonly, copy) NSURL *URLByResolvingSymlinksInPath __attribute__((availability(ios,introduced=4_0)));

/* @end */






__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSFileSecurity
#define _REWRITER_typedef_NSFileSecurity
typedef struct objc_object NSFileSecurity;
typedef struct {} _objc_exc_NSFileSecurity;
#endif

struct NSFileSecurity_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};

// - (nullable instancetype) initWithCoder:(NSCoder *)aDecoder __attribute__((objc_designated_initializer));
/* @end */

// @class NSURLAuthenticationChallenge;
#ifndef _REWRITER_typedef_NSURLAuthenticationChallenge
#define _REWRITER_typedef_NSURLAuthenticationChallenge
typedef struct objc_object NSURLAuthenticationChallenge;
typedef struct {} _objc_exc_NSURLAuthenticationChallenge;
#endif

// @class NSURLCredential;
#ifndef _REWRITER_typedef_NSURLCredential
#define _REWRITER_typedef_NSURLCredential
typedef struct objc_object NSURLCredential;
typedef struct {} _objc_exc_NSURLCredential;
#endif

// @class NSURLProtectionSpace;
#ifndef _REWRITER_typedef_NSURLProtectionSpace
#define _REWRITER_typedef_NSURLProtectionSpace
typedef struct objc_object NSURLProtectionSpace;
typedef struct {} _objc_exc_NSURLProtectionSpace;
#endif

// @class NSURLResponse;
#ifndef _REWRITER_typedef_NSURLResponse
#define _REWRITER_typedef_NSURLResponse
typedef struct objc_object NSURLResponse;
typedef struct {} _objc_exc_NSURLResponse;
#endif

// @class NSError;
#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

// @protocol NSURLAuthenticationChallengeSender <NSObject>




// - (void)useCredential:(NSURLCredential *)credential forAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;




// - (void)continueWithoutCredentialForAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;




// - (void)cancelAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;

/* @optional */



// - (void)performDefaultHandlingForAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;




// - (void)rejectProtectionSpaceAndContinueWithChallenge:(NSURLAuthenticationChallenge *)challenge;

/* @end */


// @class NSURLAuthenticationChallengeInternal;
#ifndef _REWRITER_typedef_NSURLAuthenticationChallengeInternal
#define _REWRITER_typedef_NSURLAuthenticationChallengeInternal
typedef struct objc_object NSURLAuthenticationChallengeInternal;
typedef struct {} _objc_exc_NSURLAuthenticationChallengeInternal;
#endif


#ifndef _REWRITER_typedef_NSURLAuthenticationChallenge
#define _REWRITER_typedef_NSURLAuthenticationChallenge
typedef struct objc_object NSURLAuthenticationChallenge;
typedef struct {} _objc_exc_NSURLAuthenticationChallenge;
#endif

struct NSURLAuthenticationChallenge_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSURLAuthenticationChallengeInternal *__strong _internal;
};

// - (instancetype)initWithProtectionSpace:(NSURLProtectionSpace *)space proposedCredential:(nullable NSURLCredential *)credential previousFailureCount:(NSInteger)previousFailureCount failureResponse:(nullable NSURLResponse *)response error:(nullable NSError *)error sender:(id<NSURLAuthenticationChallengeSender>)sender;
// - (instancetype)initWithAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge sender:(id<NSURLAuthenticationChallengeSender>)sender;






// @property (readonly, copy) NSURLProtectionSpace *protectionSpace;
// @property (nullable, readonly, copy) NSURLCredential *proposedCredential;






// @property (readonly) NSInteger previousFailureCount;
// @property (nullable, readonly, copy) NSURLResponse *failureResponse;
// @property (nullable, readonly, copy) NSError *error;







// @property (nullable, readonly, retain) id<NSURLAuthenticationChallengeSender> sender;

/* @end */

typedef NSUInteger NSURLCacheStoragePolicy; enum
{
    NSURLCacheStorageAllowed,
    NSURLCacheStorageAllowedInMemoryOnly,
    NSURLCacheStorageNotAllowed,
};


// @class NSCachedURLResponseInternal;
#ifndef _REWRITER_typedef_NSCachedURLResponseInternal
#define _REWRITER_typedef_NSCachedURLResponseInternal
typedef struct objc_object NSCachedURLResponseInternal;
typedef struct {} _objc_exc_NSCachedURLResponseInternal;
#endif

// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

// @class NSURLRequest;
#ifndef _REWRITER_typedef_NSURLRequest
#define _REWRITER_typedef_NSURLRequest
typedef struct objc_object NSURLRequest;
typedef struct {} _objc_exc_NSURLRequest;
#endif

// @class NSURLResponse;
#ifndef _REWRITER_typedef_NSURLResponse
#define _REWRITER_typedef_NSURLResponse
typedef struct objc_object NSURLResponse;
typedef struct {} _objc_exc_NSURLResponse;
#endif

// @class NSDate;
#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

// @class NSURLSessionDataTask;
#ifndef _REWRITER_typedef_NSURLSessionDataTask
#define _REWRITER_typedef_NSURLSessionDataTask
typedef struct objc_object NSURLSessionDataTask;
typedef struct {} _objc_exc_NSURLSessionDataTask;
#endif


#ifndef _REWRITER_typedef_NSCachedURLResponse
#define _REWRITER_typedef_NSCachedURLResponse
typedef struct objc_object NSCachedURLResponse;
typedef struct {} _objc_exc_NSCachedURLResponse;
#endif

struct NSCachedURLResponse_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSCachedURLResponseInternal *__strong _internal;
};

// - (instancetype)initWithResponse:(NSURLResponse *)response data:(NSData *)data;
// - (instancetype)initWithResponse:(NSURLResponse *)response data:(NSData *)data userInfo:(nullable NSDictionary *)userInfo storagePolicy:(NSURLCacheStoragePolicy)storagePolicy;






// @property (readonly, copy) NSURLResponse *response;






// @property (readonly, copy) NSData *data;






// @property (nullable, readonly, copy) NSDictionary *userInfo;






// @property (readonly) NSURLCacheStoragePolicy storagePolicy;

/* @end */



// @class NSURLRequest;
#ifndef _REWRITER_typedef_NSURLRequest
#define _REWRITER_typedef_NSURLRequest
typedef struct objc_object NSURLRequest;
typedef struct {} _objc_exc_NSURLRequest;
#endif

// @class NSURLCacheInternal;
#ifndef _REWRITER_typedef_NSURLCacheInternal
#define _REWRITER_typedef_NSURLCacheInternal
typedef struct objc_object NSURLCacheInternal;
typedef struct {} _objc_exc_NSURLCacheInternal;
#endif



#ifndef _REWRITER_typedef_NSURLCache
#define _REWRITER_typedef_NSURLCache
typedef struct objc_object NSURLCache;
typedef struct {} _objc_exc_NSURLCache;
#endif

struct NSURLCache_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSURLCacheInternal *__strong _internal;
};

// + (NSURLCache *)sharedURLCache;
// + (void)setSharedURLCache:(NSURLCache *)cache;
// - (instancetype)initWithMemoryCapacity:(NSUInteger)memoryCapacity diskCapacity:(NSUInteger)diskCapacity diskPath:(nullable NSString *)path;
// - (nullable NSCachedURLResponse *)cachedResponseForRequest:(NSURLRequest *)request;
// - (void)storeCachedResponse:(NSCachedURLResponse *)cachedResponse forRequest:(NSURLRequest *)request;
// - (void)removeCachedResponseForRequest:(NSURLRequest *)request;






// - (void)removeAllCachedResponses;





// - (void)removeCachedResponsesSinceDate:(NSDate *)date __attribute__((availability(ios,introduced=8_0)));







// @property NSUInteger memoryCapacity;







// @property NSUInteger diskCapacity;
// @property (readonly) NSUInteger currentMemoryUsage;
// @property (readonly) NSUInteger currentDiskUsage;

/* @end */


// @interface NSURLCache (NSURLSessionTaskAdditions)
// - (void)storeCachedResponse:(NSCachedURLResponse *)cachedResponse forDataTask:(NSURLSessionDataTask *)dataTask __attribute__((availability(ios,introduced=8_0)));
// - (void)getCachedResponseForDataTask:(NSURLSessionDataTask *)dataTask completionHandler:(void (^) (NSCachedURLResponse * _Nullable cachedResponse))completionHandler __attribute__((availability(ios,introduced=8_0)));
// - (void)removeCachedResponseForDataTask:(NSURLSessionDataTask *)dataTask __attribute__((availability(ios,introduced=8_0)));
/* @end */

// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

// @class NSURL;
#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

// @class NSCachedURLResponse;
#ifndef _REWRITER_typedef_NSCachedURLResponse
#define _REWRITER_typedef_NSCachedURLResponse
typedef struct objc_object NSCachedURLResponse;
typedef struct {} _objc_exc_NSCachedURLResponse;
#endif

// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

// @class NSError;
#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

// @class NSURLAuthenticationChallenge;
#ifndef _REWRITER_typedef_NSURLAuthenticationChallenge
#define _REWRITER_typedef_NSURLAuthenticationChallenge
typedef struct objc_object NSURLAuthenticationChallenge;
typedef struct {} _objc_exc_NSURLAuthenticationChallenge;
#endif

// @class NSURLConnectionInternal;
#ifndef _REWRITER_typedef_NSURLConnectionInternal
#define _REWRITER_typedef_NSURLConnectionInternal
typedef struct objc_object NSURLConnectionInternal;
typedef struct {} _objc_exc_NSURLConnectionInternal;
#endif

// @class NSURLRequest;
#ifndef _REWRITER_typedef_NSURLRequest
#define _REWRITER_typedef_NSURLRequest
typedef struct objc_object NSURLRequest;
typedef struct {} _objc_exc_NSURLRequest;
#endif

// @class NSURLResponse;
#ifndef _REWRITER_typedef_NSURLResponse
#define _REWRITER_typedef_NSURLResponse
typedef struct objc_object NSURLResponse;
typedef struct {} _objc_exc_NSURLResponse;
#endif

// @class NSRunLoop;
#ifndef _REWRITER_typedef_NSRunLoop
#define _REWRITER_typedef_NSRunLoop
typedef struct objc_object NSRunLoop;
typedef struct {} _objc_exc_NSRunLoop;
#endif

// @class NSInputStream;
#ifndef _REWRITER_typedef_NSInputStream
#define _REWRITER_typedef_NSInputStream
typedef struct objc_object NSInputStream;
typedef struct {} _objc_exc_NSInputStream;
#endif

// @class NSURLProtectionSpace;
#ifndef _REWRITER_typedef_NSURLProtectionSpace
#define _REWRITER_typedef_NSURLProtectionSpace
typedef struct objc_object NSURLProtectionSpace;
typedef struct {} _objc_exc_NSURLProtectionSpace;
#endif

// @class NSOperationQueue;
#ifndef _REWRITER_typedef_NSOperationQueue
#define _REWRITER_typedef_NSOperationQueue
typedef struct objc_object NSOperationQueue;
typedef struct {} _objc_exc_NSOperationQueue;
#endif


// @protocol NSURLConnectionDelegate;

#ifndef _REWRITER_typedef_NSURLConnection
#define _REWRITER_typedef_NSURLConnection
typedef struct objc_object NSURLConnection;
typedef struct {} _objc_exc_NSURLConnection;
#endif

struct NSURLConnection_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSURLConnectionInternal *__strong _internal;
};



// - (nullable instancetype)initWithRequest:(NSURLRequest *)request delegate:(nullable id)delegate startImmediately:(BOOL)startImmediately __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession (see NSURLSession.h)"))) __attribute__((availability(watchos,unavailable)));

// - (nullable instancetype)initWithRequest:(NSURLRequest *)request delegate:(nullable id)delegate __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession (see NSURLSession.h)"))) __attribute__((availability(watchos,unavailable)));
// + (nullable NSURLConnection*)connectionWithRequest:(NSURLRequest *)request delegate:(nullable id)delegate __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession (see NSURLSession.h)"))) __attribute__((availability(watchos,unavailable)));

// @property (readonly, copy) NSURLRequest *originalRequest __attribute__((availability(ios,introduced=5_0)));
// @property (readonly, copy) NSURLRequest *currentRequest __attribute__((availability(ios,introduced=5_0)));

// - (void)start __attribute__((availability(ios,introduced=2_0)));
// - (void)cancel;

// - (void)scheduleInRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode __attribute__((availability(ios,introduced=2_0)));
// - (void)unscheduleFromRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode __attribute__((availability(ios,introduced=2_0)));
// - (void)setDelegateQueue:(nullable NSOperationQueue*) queue __attribute__((availability(ios,introduced=5_0)));
// + (BOOL)canHandleRequest:(NSURLRequest *)request;

/* @end */

// @protocol NSURLConnectionDelegate <NSObject>
/* @optional */
// - (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error;
// - (BOOL)connectionShouldUseCredentialStorage:(NSURLConnection *)connection;
// - (void)connection:(NSURLConnection *)connection willSendRequestForAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;
// - (BOOL)connection:(NSURLConnection *)connection canAuthenticateAgainstProtectionSpace:(NSURLProtectionSpace *)protectionSpace __attribute__((availability(ios,introduced=3_0,deprecated=8_0,message="" "Use -connection:willSendRequestForAuthenticationChallenge: instead.")));
// - (void)connection:(NSURLConnection *)connection didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use -connection:willSendRequestForAuthenticationChallenge: instead.")));
// - (void)connection:(NSURLConnection *)connection didCancelAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge __attribute__((availability(ios,introduced=2_0,deprecated=8_0,message="" "Use -connection:willSendRequestForAuthenticationChallenge: instead.")));
/* @end */

// @protocol NSURLConnectionDataDelegate <NSURLConnectionDelegate>
/* @optional */
// - (nullable NSURLRequest *)connection:(NSURLConnection *)connection willSendRequest:(NSURLRequest *)request redirectResponse:(nullable NSURLResponse *)response;
// - (void)connection:(NSURLConnection *)connection didReceiveResponse:(NSURLResponse *)response;

// - (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data;

// - (nullable NSInputStream *)connection:(NSURLConnection *)connection needNewBodyStream:(NSURLRequest *)request;
#if 0
- (void)connection:(NSURLConnection *)connection didSendBodyData:(NSInteger)bytesWritten
                                                 totalBytesWritten:(NSInteger)totalBytesWritten
                                         totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite;
#endif


// - (nullable NSCachedURLResponse *)connection:(NSURLConnection *)connection willCacheResponse:(NSCachedURLResponse *)cachedResponse;

// - (void)connectionDidFinishLoading:(NSURLConnection *)connection;
/* @end */

// @protocol NSURLConnectionDownloadDelegate <NSURLConnectionDelegate>
/* @optional */
// - (void)connection:(NSURLConnection *)connection didWriteData:(long long)bytesWritten totalBytesWritten:(long long)totalBytesWritten expectedTotalBytes:(long long) expectedTotalBytes;
// - (void)connectionDidResumeDownloading:(NSURLConnection *)connection totalBytesWritten:(long long)totalBytesWritten expectedTotalBytes:(long long) expectedTotalBytes;

/* @required */
// - (void)connectionDidFinishDownloading:(NSURLConnection *)connection destinationURL:(NSURL *) destinationURL;
/* @end */

// @interface NSURLConnection (NSURLConnectionSynchronousLoading)
// + (nullable NSData *)sendSynchronousRequest:(NSURLRequest *)request returningResponse:(NSURLResponse * _Nullable * _Nullable)response error:(NSError **)error __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use [NSURLSession dataTaskWithRequest:completionHandler:] (see NSURLSession.h"))) __attribute__((availability(watchos,unavailable)));

/* @end */

// @interface NSURLConnection (NSURLConnectionQueuedLoading)
#if 0
+ (void)sendAsynchronousRequest:(NSURLRequest*) request
                          queue:(NSOperationQueue*) queue
              completionHandler:(void (^)(NSURLResponse* _Nullable response, NSData* _Nullable data, NSError* _Nullable connectionError)) handler __attribute__((availability(ios,introduced=5_0,deprecated=9_0,message="" "Use [NSURLSession dataTaskWithRequest:completionHandler:] (see NSURLSession.h"))) __attribute__((availability(watchos,unavailable)));
#endif


/* @end */









extern "C" {
typedef struct __attribute__((objc_bridge(id))) __SecCertificate *SecCertificateRef;







typedef struct __attribute__((objc_bridge(id))) __SecIdentity *SecIdentityRef;






typedef struct __attribute__((objc_bridge(id))) __SecKey *SecKeyRef;






typedef struct __attribute__((objc_bridge(id))) __SecPolicy *SecPolicyRef;






typedef struct __attribute__((objc_bridge(id))) __SecAccessControl *SecAccessControlRef;
enum
{
    errSecSuccess = 0,
    errSecUnimplemented = -4,
    errSecIO = -36,
    errSecOpWr = -49,
    errSecParam = -50,
    errSecAllocate = -108,
    errSecUserCanceled = -128,
    errSecBadReq = -909,
    errSecInternalComponent = -2070,
    errSecNotAvailable = -25291,
    errSecDuplicateItem = -25299,
    errSecItemNotFound = -25300,
    errSecInteractionNotAllowed = -25308,
    errSecDecode = -26275,
    errSecAuthFailed = -25293,
};




}
extern "C" {
CFTypeID SecCertificateGetTypeID(void)
    __attribute__((availability(macosx,introduced=10.3)));
_Nullable
SecCertificateRef SecCertificateCreateWithData(CFAllocatorRef _Nullable allocator,
    CFDataRef data) __attribute__((availability(macosx,introduced=10.6)));
CFDataRef SecCertificateCopyData(SecCertificateRef certificate)
    __attribute__((availability(macosx,introduced=10.6)));
_Nullable
CFStringRef SecCertificateCopySubjectSummary(SecCertificateRef certificate)
    __attribute__((availability(macosx,introduced=10.6)));




}
extern "C" {
CFTypeID SecIdentityGetTypeID(void)
    __attribute__((availability(macosx,introduced=10.3)));
OSStatus SecIdentityCopyCertificate(
            SecIdentityRef identityRef,
            SecCertificateRef * _Nonnull __attribute__((cf_returns_retained)) certificateRef)
    __attribute__((availability(macosx,introduced=10.3)));
OSStatus SecIdentityCopyPrivateKey(
            SecIdentityRef identityRef,
            SecKeyRef * _Nonnull __attribute__((cf_returns_retained)) privateKeyRef)
    __attribute__((availability(macosx,introduced=10.3)));




}
extern "C" {
extern const CFStringRef kSecImportExportPassphrase
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecImportItemLabel
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecImportItemKeyID
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecImportItemTrust
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecImportItemCertChain
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecImportItemIdentity
    __attribute__((availability(macosx,introduced=10.6)));
OSStatus SecPKCS12Import(CFDataRef pkcs12_data, CFDictionaryRef options,
    CFArrayRef * _Nonnull __attribute__((cf_returns_retained)) items) __attribute__((availability(macosx,introduced=10.6)));




}
extern "C" {
CFTypeID SecAccessControlGetTypeID(void)
__attribute__((availability(macosx,introduced=10.10)));

typedef CFIndex SecAccessControlCreateFlags; enum {
    kSecAccessControlUserPresence = 1 << 0,
    kSecAccessControlTouchIDAny __attribute__((availability(ios,introduced=9_0))) = 1 << 1,
    kSecAccessControlTouchIDCurrentSet __attribute__((availability(ios,introduced=9_0))) = 1 << 3,
    kSecAccessControlDevicePasscode __attribute__((availability(ios,introduced=9_0))) = 1 << 4,
    kSecAccessControlOr __attribute__((availability(ios,introduced=9_0))) = 1 << 14,
    kSecAccessControlAnd __attribute__((availability(ios,introduced=9_0))) = 1 << 15,
    kSecAccessControlPrivateKeyUsage __attribute__((availability(ios,introduced=9_0))) = 1 << 30,
    kSecAccessControlApplicationPassword __attribute__((availability(ios,introduced=9_0))) = 1 << 31,
} __attribute__((availability(macosx,introduced=10.10)));
_Nullable
SecAccessControlRef SecAccessControlCreateWithFlags(CFAllocatorRef _Nullable allocator, CFTypeRef protection,
                                                    SecAccessControlCreateFlags flags, CFErrorRef *error)
__attribute__((availability(macosx,introduced=10.10)));




}
extern "C" {
extern const CFStringRef kSecClass
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecClassGenericPassword
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecClassInternetPassword
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecClassCertificate
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecClassKey
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecClassIdentity
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecAttrAccessible
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecAttrAccessControl
    __attribute__((availability(macosx,introduced=10.10)));
extern const CFStringRef kSecAttrAccessGroup
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecAttrSynchronizable
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecAttrCreationDate
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrModificationDate
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrDescription
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrComment
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrCreator
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrType
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrLabel
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrIsInvisible
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrIsNegative
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrAccount
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrService
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrGeneric
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrSecurityDomain
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrServer
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocol
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrAuthenticationType
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrPort
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrPath
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrSubject
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrIssuer
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrSerialNumber
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrSubjectKeyID
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrPublicKeyHash
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrCertificateType
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrCertificateEncoding
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrKeyClass
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrApplicationLabel
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrIsPermanent
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrApplicationTag
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrKeyType
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrKeySizeInBits
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrEffectiveKeySize
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrCanEncrypt
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrCanDecrypt
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrCanDerive
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrCanSign
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrCanVerify
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrCanWrap
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrCanUnwrap
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrSyncViewHint
    __attribute__((availability(macosx,introduced=10.11)));
extern const CFStringRef kSecAttrTokenID
    __attribute__((availability(macosx,introduced=10.11)));
extern const CFStringRef kSecAttrAccessibleWhenUnlocked
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecAttrAccessibleAfterFirstUnlock
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecAttrAccessibleAlways
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecAttrAccessibleWhenPasscodeSetThisDeviceOnly
    __attribute__((availability(macosx,introduced=10.10)));
extern const CFStringRef kSecAttrAccessibleWhenUnlockedThisDeviceOnly
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecAttrAccessibleAfterFirstUnlockThisDeviceOnly
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecAttrAccessibleAlwaysThisDeviceOnly
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecAttrProtocolFTP
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolFTPAccount
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolHTTP
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolIRC
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolNNTP
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolPOP3
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolSMTP
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolSOCKS
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolIMAP
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolLDAP
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolAppleTalk
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolAFP
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolTelnet
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolSSH
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolFTPS
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolHTTPS
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolHTTPProxy
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolHTTPSProxy
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolFTPProxy
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolSMB
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolRTSP
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolRTSPProxy
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolDAAP
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolEPPC
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolIPP
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolNNTPS
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolLDAPS
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolTelnetS
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolIMAPS
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolIRCS
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrProtocolPOP3S
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrAuthenticationTypeNTLM
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrAuthenticationTypeMSN
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrAuthenticationTypeDPA
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrAuthenticationTypeRPA
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrAuthenticationTypeHTTPBasic
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrAuthenticationTypeHTTPDigest
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrAuthenticationTypeHTMLForm
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrAuthenticationTypeDefault
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecAttrKeyClassPublic
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecAttrKeyClassPrivate
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecAttrKeyClassSymmetric
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecAttrKeyTypeRSA
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecAttrKeyTypeEC
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecAttrSynchronizableAny
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecMatchPolicy
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecMatchItemList
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecMatchSearchList
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecMatchIssuers
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecMatchEmailAddressIfPresent
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecMatchSubjectContains
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecMatchCaseInsensitive
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecMatchTrustedOnly
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecMatchValidOnDate
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecMatchLimit
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecMatchLimitOne
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecMatchLimitAll
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecReturnData
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecReturnAttributes
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecReturnRef
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecReturnPersistentRef
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecValueData
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecValueRef
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecValuePersistentRef
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecUseItemList
    __attribute__((availability(macosx,introduced=10.6)));
extern const CFStringRef kSecUseOperationPrompt
    __attribute__((availability(macosx,introduced=10.10)));
extern const CFStringRef kSecUseNoAuthenticationUI
    __attribute__((availability(macosx,introduced=10.10,deprecated=10.11,message="Use a kSecAuthenticationUI instead.")));
extern const CFStringRef kSecUseAuthenticationUI
    __attribute__((availability(macosx,introduced=10.11)));
extern const CFStringRef kSecUseAuthenticationContext
    __attribute__((availability(macosx,introduced=10.11)));
extern const CFStringRef kSecUseAuthenticationUIAllow
    __attribute__((availability(macosx,introduced=10.11)));
extern const CFStringRef kSecUseAuthenticationUIFail
    __attribute__((availability(macosx,introduced=10.11)));
extern const CFStringRef kSecUseAuthenticationUISkip
    __attribute__((availability(macosx,introduced=10.11)));
extern const CFStringRef kSecAttrTokenIDSecureEnclave
    __attribute__((availability(macosx,unavailable)));
OSStatus SecItemCopyMatching(CFDictionaryRef query, CFTypeRef * _Nullable __attribute__((cf_returns_retained)) result)
    __attribute__((availability(macosx,introduced=10.6)));
OSStatus SecItemAdd(CFDictionaryRef attributes, CFTypeRef * _Nullable __attribute__((cf_returns_retained)) result)
    __attribute__((availability(macosx,introduced=10.6)));
OSStatus SecItemUpdate(CFDictionaryRef query,
    CFDictionaryRef attributesToUpdate)
    __attribute__((availability(macosx,introduced=10.6)));
OSStatus SecItemDelete(CFDictionaryRef query)
    __attribute__((availability(macosx,introduced=10.6)));




}
extern "C" {





typedef uint32_t SecPadding; enum
{
    kSecPaddingNone = 0,
    kSecPaddingPKCS1 = 1,
    kSecPaddingOAEP = 2,




    kSecPaddingSigRaw = 0x4000,




    kSecPaddingPKCS1MD2 = 0x8000,




    kSecPaddingPKCS1MD5 = 0x8001,




    kSecPaddingPKCS1SHA1 = 0x8002,




    kSecPaddingPKCS1SHA224 = 0x8003,




    kSecPaddingPKCS1SHA256 = 0x8004,




    kSecPaddingPKCS1SHA384 = 0x8005,




    kSecPaddingPKCS1SHA512 = 0x8006,
};







CFTypeID SecKeyGetTypeID(void)
    __attribute__((availability(macosx,introduced=10.3)));
extern const CFStringRef kSecPrivateKeyAttrs
    __attribute__((availability(macosx,introduced=10.8)));
extern const CFStringRef kSecPublicKeyAttrs
    __attribute__((availability(macosx,introduced=10.8)));
OSStatus SecKeyGeneratePair(CFDictionaryRef parameters, SecKeyRef * _Nullable __attribute__((cf_returns_retained)) publicKey,
    SecKeyRef * _Nullable __attribute__((cf_returns_retained)) privateKey) __attribute__((availability(macosx,introduced=10.7)));
OSStatus SecKeyRawSign(
    SecKeyRef key,
 SecPadding padding,
 const uint8_t *dataToSign,
 size_t dataToSignLen,
 uint8_t *sig,
 size_t *sigLen)
    __attribute__((availability(macosx,introduced=10.7)));
OSStatus SecKeyRawVerify(
    SecKeyRef key,
 SecPadding padding,
 const uint8_t *signedData,
 size_t signedDataLen,
 const uint8_t *sig,
 size_t sigLen)
    __attribute__((availability(macosx,introduced=10.7)));
OSStatus SecKeyEncrypt(
    SecKeyRef key,
 SecPadding padding,
 const uint8_t *plainText,
 size_t plainTextLen,
 uint8_t *cipherText,
 size_t *cipherTextLen)
    __attribute__((availability(macosx,introduced=10.7)));
OSStatus SecKeyDecrypt(
    SecKeyRef key,
 SecPadding padding,


 const uint8_t *cipherText,
 size_t cipherTextLen,
 uint8_t *plainText,
 size_t *plainTextLen)
    __attribute__((availability(macosx,introduced=10.7)));
size_t SecKeyGetBlockSize(SecKeyRef key)
    __attribute__((availability(macosx,introduced=10.7)));




}
extern "C" {
extern const CFStringRef kSecPolicyAppleX509Basic
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyAppleSSL
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyAppleSMIME
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyAppleEAP
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyAppleIPsec
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyApplePKINITClient
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyApplePKINITServer
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyAppleCodeSigning
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyMacAppStoreReceipt
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyAppleIDValidation
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyAppleTimeStamping
    __attribute__((availability(macosx,introduced=10.8)));
extern const CFStringRef kSecPolicyAppleRevocation
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecPolicyApplePayIssuerEncryption
    __attribute__((availability(macosx,introduced=10.11)));
extern const CFStringRef kSecPolicyOid
 __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyName
 __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyClient
 __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPolicyRevocationFlags
 __attribute__((availability(macosx,introduced=10.9)));







CFTypeID SecPolicyGetTypeID(void)
 __attribute__((availability(macosx,introduced=10.3)));
CFDictionaryRef SecPolicyCopyProperties(SecPolicyRef policyRef)
 __attribute__((availability(macosx,introduced=10.7)));







SecPolicyRef SecPolicyCreateBasicX509(void)
 __attribute__((availability(macosx,introduced=10.6)));
SecPolicyRef SecPolicyCreateSSL(Boolean server, CFStringRef _Nullable hostname)
 __attribute__((availability(macosx,introduced=10.6)));
enum {
 kSecRevocationOCSPMethod = (1 << 0),
 kSecRevocationCRLMethod = (1 << 1),
 kSecRevocationPreferCRL = (1 << 2),
 kSecRevocationRequirePositiveResponse = (1 << 3),
 kSecRevocationNetworkAccessDisabled = (1 << 4),
 kSecRevocationUseAnyAvailableMethod = (kSecRevocationOCSPMethod |
  kSecRevocationCRLMethod)
};
SecPolicyRef SecPolicyCreateRevocation(CFOptionFlags revocationFlags)
 __attribute__((availability(macosx,introduced=10.9)));
SecPolicyRef SecPolicyCreateWithProperties(CFTypeRef policyIdentifier,
 CFDictionaryRef _Nullable properties)
 __attribute__((availability(macosx,introduced=10.9)));
}
extern "C" {
typedef const struct __SecRandom * SecRandomRef;



extern const SecRandomRef kSecRandomDefault
    __attribute__((availability(macosx,introduced=10.7)));







int SecRandomCopyBytes(SecRandomRef _Nullable rnd, size_t count, uint8_t *bytes)
    __attribute__((availability(macosx,introduced=10.7)));




}
extern "C" {
extern const CFStringRef kSecSharedPassword
    __attribute__((availability(macosx,unavailable))) __attribute__((availability(watchos,unavailable)));
void SecAddSharedWebCredential(CFStringRef fqdn, CFStringRef account, CFStringRef _Nullable password,
    void (*completionHandler)(CFErrorRef _Nullable error))
    __attribute__((availability(macosx,unavailable))) __attribute__((availability(watchos,unavailable)));
void SecRequestSharedWebCredential(CFStringRef _Nullable fqdn, CFStringRef _Nullable account,
    void (*completionHandler)(CFArrayRef _Nullable credentials, CFErrorRef _Nullable error))
    __attribute__((availability(macosx,unavailable))) __attribute__((availability(watchos,unavailable)));






_Nullable
CFStringRef SecCreateSharedWebCredentialPassword(void)
__attribute__((availability(macosx,unavailable))) __attribute__((availability(watchos,unavailable)));







}
extern "C" {
typedef uint32_t SecTrustResultType;
enum {
    kSecTrustResultInvalid = 0,
    kSecTrustResultProceed = 1,
    kSecTrustResultConfirm __attribute__((deprecated)) = 2,
    kSecTrustResultDeny = 3,
    kSecTrustResultUnspecified = 4,
    kSecTrustResultRecoverableTrustFailure = 5,
    kSecTrustResultFatalTrustFailure = 6,
    kSecTrustResultOtherError = 7
};





typedef struct __attribute__((objc_bridge(id))) __SecTrust *SecTrustRef;
extern const CFStringRef kSecPropertyTypeTitle
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecPropertyTypeError
    __attribute__((availability(macosx,introduced=10.7)));
extern const CFStringRef kSecTrustEvaluationDate
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecTrustExtendedValidation
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecTrustOrganizationName
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecTrustResultValue
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecTrustRevocationChecked
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecTrustRevocationValidUntilDate
    __attribute__((availability(macosx,introduced=10.9)));
extern const CFStringRef kSecTrustCertificateTransparency
__attribute__((availability(macosx,introduced=10.11)));
typedef void (*SecTrustCallback)(SecTrustRef trustRef, SecTrustResultType trustResult);
CFTypeID SecTrustGetTypeID(void)
    __attribute__((availability(macosx,introduced=10.3)));
OSStatus SecTrustCreateWithCertificates(CFTypeRef certificates,
    CFTypeRef _Nullable policies, SecTrustRef * _Nonnull __attribute__((cf_returns_retained)) trust)
    __attribute__((availability(macosx,introduced=10.3)));
OSStatus SecTrustSetPolicies(SecTrustRef trust, CFTypeRef policies)
    __attribute__((availability(macosx,introduced=10.3)));
OSStatus SecTrustCopyPolicies(SecTrustRef trust, CFArrayRef * _Nonnull __attribute__((cf_returns_retained)) policies)
    __attribute__((availability(macosx,introduced=10.3)));
OSStatus SecTrustSetNetworkFetchAllowed(SecTrustRef trust,
    Boolean allowFetch)
    __attribute__((availability(macosx,introduced=10.9)));
OSStatus SecTrustGetNetworkFetchAllowed(SecTrustRef trust,
    Boolean *allowFetch)
    __attribute__((availability(macosx,introduced=10.9)));
OSStatus SecTrustSetAnchorCertificates(SecTrustRef trust,
    CFArrayRef anchorCertificates)
    __attribute__((availability(macosx,introduced=10.3)));
OSStatus SecTrustSetAnchorCertificatesOnly(SecTrustRef trust,
    Boolean anchorCertificatesOnly)
    __attribute__((availability(macosx,introduced=10.6)));
OSStatus SecTrustCopyCustomAnchorCertificates(SecTrustRef trust,
    CFArrayRef * _Nonnull __attribute__((cf_returns_retained)) anchors)
    __attribute__((availability(macosx,introduced=10.5)));
OSStatus SecTrustSetVerifyDate(SecTrustRef trust, CFDateRef verifyDate)
    __attribute__((availability(macosx,introduced=10.3)));
CFAbsoluteTime SecTrustGetVerifyTime(SecTrustRef trust)
    __attribute__((availability(macosx,introduced=10.6)));
OSStatus SecTrustEvaluate(SecTrustRef trust, SecTrustResultType * _Nullable result)
    __attribute__((availability(macosx,introduced=10.3)));
OSStatus SecTrustEvaluateAsync(SecTrustRef trust,
    dispatch_queue_t _Nullable queue, SecTrustCallback result)
    __attribute__((availability(macosx,introduced=10.7)));
OSStatus SecTrustGetTrustResult(SecTrustRef trust,
    SecTrustResultType *result)
    __attribute__((availability(macosx,introduced=10.7)));
_Nullable
SecKeyRef SecTrustCopyPublicKey(SecTrustRef trust)
    __attribute__((availability(macosx,introduced=10.7)));
CFIndex SecTrustGetCertificateCount(SecTrustRef trust)
    __attribute__((availability(macosx,introduced=10.7)));
_Nullable
SecCertificateRef SecTrustGetCertificateAtIndex(SecTrustRef trust, CFIndex ix)
    __attribute__((availability(macosx,introduced=10.7)));
CFDataRef SecTrustCopyExceptions(SecTrustRef trust)
    __attribute__((availability(macosx,introduced=10.9)));
bool SecTrustSetExceptions(SecTrustRef trust, CFDataRef exceptions)
    __attribute__((availability(macosx,introduced=10.9)));
_Nullable
CFArrayRef SecTrustCopyProperties(SecTrustRef trust)
    __attribute__((availability(macosx,introduced=10.7)));
_Nullable
CFDictionaryRef SecTrustCopyResult(SecTrustRef trust)
    __attribute__((availability(macosx,introduced=10.9)));
OSStatus SecTrustSetOCSPResponse(SecTrustRef trust, CFTypeRef _Nullable responseData)
    __attribute__((availability(macosx,introduced=10.9)));
}

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

typedef NSUInteger NSURLCredentialPersistence; enum {
    NSURLCredentialPersistenceNone,
    NSURLCredentialPersistenceForSession,
    NSURLCredentialPersistencePermanent,
    NSURLCredentialPersistenceSynchronizable __attribute__((availability(ios,introduced=6_0)))
};

// @class NSURLCredentialInternal;
#ifndef _REWRITER_typedef_NSURLCredentialInternal
#define _REWRITER_typedef_NSURLCredentialInternal
typedef struct objc_object NSURLCredentialInternal;
typedef struct {} _objc_exc_NSURLCredentialInternal;
#endif








#ifndef _REWRITER_typedef_NSURLCredential
#define _REWRITER_typedef_NSURLCredential
typedef struct objc_object NSURLCredential;
typedef struct {} _objc_exc_NSURLCredential;
#endif

struct NSURLCredential_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSURLCredentialInternal *__strong _internal;
};







// @property (readonly) NSURLCredentialPersistence persistence;

/* @end */






// @interface NSURLCredential(NSInternetPassword)
// - (instancetype)initWithUser:(NSString *)user password:(NSString *)password persistence:(NSURLCredentialPersistence)persistence;
// + (NSURLCredential *)credentialWithUser:(NSString *)user password:(NSString *)password persistence:(NSURLCredentialPersistence)persistence;






// @property (nullable, readonly, copy) NSString *user;
// @property (nullable, readonly, copy) NSString *password;
// @property (readonly) BOOL hasPassword;

/* @end */






// @interface NSURLCredential(NSClientCertificate)
// - (instancetype)initWithIdentity:(SecIdentityRef)identity certificates:(nullable NSArray *)certArray persistence:(NSURLCredentialPersistence)persistence __attribute__((availability(ios,introduced=3_0)));
// + (NSURLCredential *)credentialWithIdentity:(SecIdentityRef)identity certificates:(nullable NSArray *)certArray persistence:(NSURLCredentialPersistence)persistence __attribute__((availability(ios,introduced=3_0)));






// @property (nullable, readonly) SecIdentityRef identity;






// @property (readonly, copy) NSArray *certificates __attribute__((availability(ios,introduced=3_0)));

/* @end */


// @interface NSURLCredential(NSServerTrust)






// - (instancetype)initWithTrust:(SecTrustRef)trust __attribute__((availability(ios,introduced=3_0)));






// + (NSURLCredential *)credentialForTrust:(SecTrustRef)trust __attribute__((availability(ios,introduced=3_0)));

/* @end */









// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif








extern "C" NSString * const NSURLProtectionSpaceHTTP __attribute__((availability(ios,introduced=2_0)));





extern "C" NSString * const NSURLProtectionSpaceHTTPS __attribute__((availability(ios,introduced=2_0)));





extern "C" NSString * const NSURLProtectionSpaceFTP __attribute__((availability(ios,introduced=2_0)));





extern "C" NSString * const NSURLProtectionSpaceHTTPProxy;





extern "C" NSString * const NSURLProtectionSpaceHTTPSProxy;





extern "C" NSString * const NSURLProtectionSpaceFTPProxy;





extern "C" NSString * const NSURLProtectionSpaceSOCKSProxy;





extern "C" NSString * const NSURLAuthenticationMethodDefault;






extern "C" NSString * const NSURLAuthenticationMethodHTTPBasic;





extern "C" NSString * const NSURLAuthenticationMethodHTTPDigest;





extern "C" NSString * const NSURLAuthenticationMethodHTMLForm;





extern "C" NSString * const NSURLAuthenticationMethodNTLM __attribute__((availability(ios,introduced=2_0)));





extern "C" NSString * const NSURLAuthenticationMethodNegotiate __attribute__((availability(ios,introduced=2_0)));





extern "C" NSString * const NSURLAuthenticationMethodClientCertificate __attribute__((availability(ios,introduced=3_0)));





extern "C" NSString * const NSURLAuthenticationMethodServerTrust __attribute__((availability(ios,introduced=3_0)));

// @class NSURLProtectionSpaceInternal;
#ifndef _REWRITER_typedef_NSURLProtectionSpaceInternal
#define _REWRITER_typedef_NSURLProtectionSpaceInternal
typedef struct objc_object NSURLProtectionSpaceInternal;
typedef struct {} _objc_exc_NSURLProtectionSpaceInternal;
#endif








#ifndef _REWRITER_typedef_NSURLProtectionSpace
#define _REWRITER_typedef_NSURLProtectionSpace
typedef struct objc_object NSURLProtectionSpace;
typedef struct {} _objc_exc_NSURLProtectionSpace;
#endif

struct NSURLProtectionSpace_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSURLProtectionSpaceInternal *__strong _internal;
};

// - (instancetype)initWithHost:(NSString *)host port:(NSInteger)port protocol:(nullable NSString *)protocol realm:(nullable NSString *)realm authenticationMethod:(nullable NSString *)authenticationMethod;
// - (instancetype)initWithProxyHost:(NSString *)host port:(NSInteger)port type:(nullable NSString *)type realm:(nullable NSString *)realm authenticationMethod:(nullable NSString *)authenticationMethod;
// @property (nullable, readonly, copy) NSString *realm;






// @property (readonly) BOOL receivesCredentialSecurely;






// @property (readonly) BOOL isProxy;






// @property (readonly, copy) NSString *host;






// @property (readonly) NSInteger port;






// @property (nullable, readonly, copy) NSString *proxyType;






// @property (nullable, readonly, copy) NSString *protocol;






// @property (readonly, copy) NSString *authenticationMethod;

/* @end */






// @interface NSURLProtectionSpace(NSClientCertificateSpace)






// @property (nullable, readonly, copy) NSArray<NSData *> *distinguishedNames __attribute__((availability(ios,introduced=3_0)));

/* @end */






// @interface NSURLProtectionSpace(NSServerTrustValidationSpace)






// @property (nullable, readonly) SecTrustRef serverTrust __attribute__((availability(ios,introduced=3_0)));

/* @end */


// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @class NSURLCredential;
#ifndef _REWRITER_typedef_NSURLCredential
#define _REWRITER_typedef_NSURLCredential
typedef struct objc_object NSURLCredential;
typedef struct {} _objc_exc_NSURLCredential;
#endif

// @class NSURLSessionTask;
#ifndef _REWRITER_typedef_NSURLSessionTask
#define _REWRITER_typedef_NSURLSessionTask
typedef struct objc_object NSURLSessionTask;
typedef struct {} _objc_exc_NSURLSessionTask;
#endif


// @class NSURLCredentialStorageInternal;
#ifndef _REWRITER_typedef_NSURLCredentialStorageInternal
#define _REWRITER_typedef_NSURLCredentialStorageInternal
typedef struct objc_object NSURLCredentialStorageInternal;
typedef struct {} _objc_exc_NSURLCredentialStorageInternal;
#endif


#ifndef _REWRITER_typedef_NSURLCredentialStorage
#define _REWRITER_typedef_NSURLCredentialStorage
typedef struct objc_object NSURLCredentialStorage;
typedef struct {} _objc_exc_NSURLCredentialStorage;
#endif

struct NSURLCredentialStorage_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSURLCredentialStorageInternal *__strong _internal;
};







// + (NSURLCredentialStorage *)sharedCredentialStorage;







// - (nullable NSDictionary<NSString *, NSURLCredential *> *)credentialsForProtectionSpace:(NSURLProtectionSpace *)space;
// @property (readonly, copy) NSDictionary<NSURLProtectionSpace *, NSDictionary<NSString *, NSURLCredential *> *> *allCredentials;
// - (void)setCredential:(NSURLCredential *)credential forProtectionSpace:(NSURLProtectionSpace *)space;
// - (void)removeCredential:(NSURLCredential *)credential forProtectionSpace:(NSURLProtectionSpace *)space;
// - (void)removeCredential:(NSURLCredential *)credential forProtectionSpace:(NSURLProtectionSpace *)space options:(nullable NSDictionary<NSString *, id> *)options __attribute__((availability(ios,introduced=7_0)));






// - (nullable NSURLCredential *)defaultCredentialForProtectionSpace:(NSURLProtectionSpace *)space;
// - (void)setDefaultCredential:(NSURLCredential *)credential forProtectionSpace:(NSURLProtectionSpace *)space;

/* @end */


// @interface NSURLCredentialStorage (NSURLSessionTaskAdditions)
// - (void)getCredentialsForProtectionSpace:(NSURLProtectionSpace *)protectionSpace task:(NSURLSessionTask *)task completionHandler:(void (^) (NSDictionary<NSString *, NSURLCredential *> * _Nullable credentials))completionHandler __attribute__((availability(ios,introduced=8_0)));
// - (void)setCredential:(NSURLCredential *)credential forProtectionSpace:(NSURLProtectionSpace *)protectionSpace task:(NSURLSessionTask *)task __attribute__((availability(ios,introduced=8_0)));
// - (void)removeCredential:(NSURLCredential *)credential forProtectionSpace:(NSURLProtectionSpace *)protectionSpace options:(nullable NSDictionary<NSString *, id> *)options task:(NSURLSessionTask *)task __attribute__((availability(ios,introduced=8_0)));
// - (void)getDefaultCredentialForProtectionSpace:(NSURLProtectionSpace *)space task:(NSURLSessionTask *)task completionHandler:(void (^) (NSURLCredential * _Nullable credential))completionHandler __attribute__((availability(ios,introduced=8_0)));
// - (void)setDefaultCredential:(NSURLCredential *)credential forProtectionSpace:(NSURLProtectionSpace *)protectionSpace task:(NSURLSessionTask *)task __attribute__((availability(ios,introduced=8_0)));
/* @end */







extern "C" NSString *const NSURLCredentialStorageChangedNotification;







extern "C" NSString *const NSURLCredentialStorageRemoveSynchronizableCredentials __attribute__((availability(ios,introduced=7_0)));











extern "C" {
extern const CFStringRef kCFErrorDomainCFNetwork __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFErrorDomainWinSock __attribute__((availability(ios,introduced=2_0)));
typedef int CFNetworkErrors; enum {

  kCFHostErrorHostNotFound = 1,
  kCFHostErrorUnknown = 2,

  kCFSOCKSErrorUnknownClientVersion = 100,
  kCFSOCKSErrorUnsupportedServerVersion = 101,

  kCFSOCKS4ErrorRequestFailed = 110,
  kCFSOCKS4ErrorIdentdFailed = 111,
  kCFSOCKS4ErrorIdConflict = 112,
  kCFSOCKS4ErrorUnknownStatusCode = 113,

  kCFSOCKS5ErrorBadState = 120,
  kCFSOCKS5ErrorBadResponseAddr = 121,
  kCFSOCKS5ErrorBadCredentials = 122,
  kCFSOCKS5ErrorUnsupportedNegotiationMethod = 123,
  kCFSOCKS5ErrorNoAcceptableMethod = 124,

  kCFFTPErrorUnexpectedStatusCode = 200,

  kCFErrorHTTPAuthenticationTypeUnsupported = 300,
  kCFErrorHTTPBadCredentials = 301,
  kCFErrorHTTPConnectionLost = 302,
  kCFErrorHTTPParseFailure = 303,
  kCFErrorHTTPRedirectionLoopDetected = 304,
  kCFErrorHTTPBadURL = 305,
  kCFErrorHTTPProxyConnectionFailure = 306,
  kCFErrorHTTPBadProxyCredentials = 307,
  kCFErrorPACFileError = 308,
  kCFErrorPACFileAuth = 309,
  kCFErrorHTTPSProxyConnectionFailure = 310,
  kCFStreamErrorHTTPSProxyFailureUnexpectedResponseToCONNECTMethod = 311,


  kCFURLErrorBackgroundSessionInUseByAnotherProcess = -996,
  kCFURLErrorBackgroundSessionWasDisconnected = -997,
  kCFURLErrorUnknown = -998,
  kCFURLErrorCancelled = -999,
  kCFURLErrorBadURL = -1000,
  kCFURLErrorTimedOut = -1001,
  kCFURLErrorUnsupportedURL = -1002,
  kCFURLErrorCannotFindHost = -1003,
  kCFURLErrorCannotConnectToHost = -1004,
  kCFURLErrorNetworkConnectionLost = -1005,
  kCFURLErrorDNSLookupFailed = -1006,
  kCFURLErrorHTTPTooManyRedirects = -1007,
  kCFURLErrorResourceUnavailable = -1008,
  kCFURLErrorNotConnectedToInternet = -1009,
  kCFURLErrorRedirectToNonExistentLocation = -1010,
  kCFURLErrorBadServerResponse = -1011,
  kCFURLErrorUserCancelledAuthentication = -1012,
  kCFURLErrorUserAuthenticationRequired = -1013,
  kCFURLErrorZeroByteResource = -1014,
  kCFURLErrorCannotDecodeRawData = -1015,
  kCFURLErrorCannotDecodeContentData = -1016,
  kCFURLErrorCannotParseResponse = -1017,
  kCFURLErrorInternationalRoamingOff = -1018,
  kCFURLErrorCallIsActive = -1019,
  kCFURLErrorDataNotAllowed = -1020,
  kCFURLErrorRequestBodyStreamExhausted = -1021,
  kCFURLErrorAppTransportSecurityRequiresSecureConnection = -1022,
  kCFURLErrorFileDoesNotExist = -1100,
  kCFURLErrorFileIsDirectory = -1101,
  kCFURLErrorNoPermissionsToReadFile = -1102,
  kCFURLErrorDataLengthExceedsMaximum = -1103,

  kCFURLErrorSecureConnectionFailed = -1200,
  kCFURLErrorServerCertificateHasBadDate = -1201,
  kCFURLErrorServerCertificateUntrusted = -1202,
  kCFURLErrorServerCertificateHasUnknownRoot = -1203,
  kCFURLErrorServerCertificateNotYetValid = -1204,
  kCFURLErrorClientCertificateRejected = -1205,
  kCFURLErrorClientCertificateRequired = -1206,
  kCFURLErrorCannotLoadFromNetwork = -2000,

  kCFURLErrorCannotCreateFile = -3000,
  kCFURLErrorCannotOpenFile = -3001,
  kCFURLErrorCannotCloseFile = -3002,
  kCFURLErrorCannotWriteToFile = -3003,
  kCFURLErrorCannotRemoveFile = -3004,
  kCFURLErrorCannotMoveFile = -3005,
  kCFURLErrorDownloadDecodingFailedMidStream = -3006,
  kCFURLErrorDownloadDecodingFailedToComplete = -3007,


  kCFHTTPCookieCannotParseCookieFile = -4000,


  kCFNetServiceErrorUnknown = -72000L,
  kCFNetServiceErrorCollision = -72001L,
  kCFNetServiceErrorNotFound = -72002L,
  kCFNetServiceErrorInProgress = -72003L,
  kCFNetServiceErrorBadArgument = -72004L,
  kCFNetServiceErrorCancel = -72005L,
  kCFNetServiceErrorInvalid = -72006L,
  kCFNetServiceErrorTimeout = -72007L,
  kCFNetServiceErrorDNSServiceFailure = -73000L
};
extern const CFStringRef kCFURLErrorFailingURLErrorKey __attribute__((availability(ios,introduced=2_2)));
extern const CFStringRef kCFURLErrorFailingURLStringErrorKey __attribute__((availability(ios,introduced=2_2)));
extern const CFStringRef kCFGetAddrInfoFailureKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFSOCKSStatusCodeKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFSOCKSVersionKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFSOCKSNegotiationMethodKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFDNSServiceFailureKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFFTPStatusCodeKey __attribute__((availability(ios,introduced=2_0)));



}



extern "C" {


#pragma pack(push, 2)








typedef struct __CFHost* CFHostRef;
extern const SInt32 kCFStreamErrorDomainNetDB __attribute__((availability(ios,introduced=2_0)));
extern const SInt32 kCFStreamErrorDomainSystemConfiguration __attribute__((availability(ios,introduced=2_0)));
typedef int CFHostInfoType; enum {





  kCFHostAddresses = 0,




  kCFHostNames = 1,





  kCFHostReachability = 2
};
struct CFHostClientContext {






  CFIndex version;





  void * _Nullable info;
  CFAllocatorRetainCallBack _Nullable retain;





  CFAllocatorReleaseCallBack _Nullable release;







  CFAllocatorCopyDescriptionCallBack copyDescription;
};
typedef struct CFHostClientContext CFHostClientContext;
typedef void ( * CFHostClientCallBack)(CFHostRef theHost, CFHostInfoType typeInfo, const CFStreamError * _Nullable error, void * _Nullable info);
extern CFTypeID
CFHostGetTypeID(void) __attribute__((availability(ios,introduced=2_0)));
extern CFHostRef
CFHostCreateWithName(CFAllocatorRef _Nullable allocator, CFStringRef hostname) __attribute__((availability(ios,introduced=2_0)));
extern CFHostRef
CFHostCreateWithAddress(CFAllocatorRef _Nullable allocator, CFDataRef addr) __attribute__((availability(ios,introduced=2_0)));
extern CFHostRef
CFHostCreateCopy(CFAllocatorRef _Nullable alloc, CFHostRef host) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHostStartInfoResolution(CFHostRef theHost, CFHostInfoType info, CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFArrayRef
CFHostGetAddressing(CFHostRef theHost, Boolean * _Nullable hasBeenResolved) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFArrayRef
CFHostGetNames(CFHostRef theHost, Boolean * _Nullable hasBeenResolved) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFDataRef
CFHostGetReachability(CFHostRef theHost, Boolean * _Nullable hasBeenResolved) __attribute__((availability(ios,introduced=2_0)));
extern void
CFHostCancelInfoResolution(CFHostRef theHost, CFHostInfoType info) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHostSetClient(CFHostRef theHost, CFHostClientCallBack _Nullable clientCB, CFHostClientContext * _Nullable clientContext) __attribute__((availability(ios,introduced=2_0)));
extern void
CFHostScheduleWithRunLoop(CFHostRef theHost, CFRunLoopRef runLoop, CFStringRef runLoopMode) __attribute__((availability(ios,introduced=2_0)));
extern void
CFHostUnscheduleFromRunLoop(CFHostRef theHost, CFRunLoopRef runLoop, CFStringRef runLoopMode) __attribute__((availability(ios,introduced=2_0)));



#pragma pack(pop)


}



extern "C" {


#pragma pack(push, 2)
typedef struct __CFNetService* CFNetServiceRef;
typedef struct __CFNetServiceMonitor* CFNetServiceMonitorRef;
typedef struct __CFNetServiceBrowser* CFNetServiceBrowserRef;
extern const SInt32 kCFStreamErrorDomainMach __attribute__((availability(ios,introduced=2_0)));
extern const SInt32 kCFStreamErrorDomainNetServices __attribute__((availability(ios,introduced=2_0)));
typedef int CFNetServicesError; enum {




  kCFNetServicesErrorUnknown = -72000L,






  kCFNetServicesErrorCollision = -72001L,




  kCFNetServicesErrorNotFound = -72002L,





  kCFNetServicesErrorInProgress = -72003L,




  kCFNetServicesErrorBadArgument = -72004L,




  kCFNetServicesErrorCancel = -72005L,





  kCFNetServicesErrorInvalid = -72006L,





  kCFNetServicesErrorTimeout = -72007L
};
typedef int CFNetServiceMonitorType; enum {




  kCFNetServiceMonitorTXT = 1
};
typedef CFOptionFlags CFNetServiceRegisterFlags; enum {




  kCFNetServiceFlagNoAutoRename = 1
};
typedef CFOptionFlags CFNetServiceBrowserFlags; enum {




  kCFNetServiceFlagMoreComing = 1,




  kCFNetServiceFlagIsDomain = 2,




  kCFNetServiceFlagIsDefault = 4,




  kCFNetServiceFlagIsRegistrationDomain __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" ))) = 4,




  kCFNetServiceFlagRemove = 8
};
struct CFNetServiceClientContext {






  CFIndex version;





  void * _Nullable info;
  CFAllocatorRetainCallBack _Nullable retain;





  CFAllocatorReleaseCallBack _Nullable release;







  CFAllocatorCopyDescriptionCallBack _Nullable copyDescription;
};
typedef struct CFNetServiceClientContext CFNetServiceClientContext;
typedef void ( * CFNetServiceClientCallBack)(CFNetServiceRef theService, CFStreamError * _Nullable error, void * _Nullable info);
typedef void ( * CFNetServiceMonitorClientCallBack)(CFNetServiceMonitorRef theMonitor, CFNetServiceRef theService, CFNetServiceMonitorType typeInfo, CFDataRef rdata, CFStreamError * _Nullable error, void * _Nullable info);
typedef void ( * CFNetServiceBrowserClientCallBack)(CFNetServiceBrowserRef browser, CFOptionFlags flags, CFTypeRef domainOrService, CFStreamError * _Nullable error, void * _Nullable info);
extern CFTypeID
CFNetServiceGetTypeID(void) __attribute__((availability(ios,introduced=2_0)));
extern CFTypeID
CFNetServiceMonitorGetTypeID(void) __attribute__((availability(ios,introduced=2_0)));
extern CFTypeID
CFNetServiceBrowserGetTypeID(void) __attribute__((availability(ios,introduced=2_0)));
extern CFNetServiceRef
CFNetServiceCreate(CFAllocatorRef _Nullable alloc, CFStringRef domain, CFStringRef serviceType, CFStringRef name, SInt32 port) __attribute__((availability(ios,introduced=2_0)));
extern CFNetServiceRef
CFNetServiceCreateCopy(CFAllocatorRef _Nullable alloc, CFNetServiceRef service) __attribute__((availability(ios,introduced=2_0)));
extern CFStringRef
CFNetServiceGetDomain(CFNetServiceRef theService) __attribute__((availability(ios,introduced=2_0)));
extern CFStringRef
CFNetServiceGetType(CFNetServiceRef theService) __attribute__((availability(ios,introduced=2_0)));
extern CFStringRef
CFNetServiceGetName(CFNetServiceRef theService) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFNetServiceRegisterWithOptions(CFNetServiceRef theService, CFOptionFlags options, CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFNetServiceResolveWithTimeout(CFNetServiceRef theService, CFTimeInterval timeout, CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetServiceCancel(CFNetServiceRef theService) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFStringRef
CFNetServiceGetTargetHost(CFNetServiceRef theService) __attribute__((availability(ios,introduced=2_0)));
extern SInt32
CFNetServiceGetPortNumber(CFNetServiceRef theService) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFArrayRef
CFNetServiceGetAddressing(CFNetServiceRef theService) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFDataRef
CFNetServiceGetTXTData(CFNetServiceRef theService) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFNetServiceSetTXTData(CFNetServiceRef theService, CFDataRef txtRecord) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFDictionaryRef
CFNetServiceCreateDictionaryWithTXTData(CFAllocatorRef _Nullable alloc, CFDataRef txtRecord) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFDataRef
CFNetServiceCreateTXTDataWithDictionary(CFAllocatorRef _Nullable alloc, CFDictionaryRef keyValuePairs) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFNetServiceSetClient(CFNetServiceRef theService, CFNetServiceClientCallBack _Nullable clientCB, CFNetServiceClientContext * _Nullable clientContext) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetServiceScheduleWithRunLoop(CFNetServiceRef theService, CFRunLoopRef runLoop, CFStringRef runLoopMode) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetServiceUnscheduleFromRunLoop(CFNetServiceRef theService, CFRunLoopRef runLoop, CFStringRef runLoopMode) __attribute__((availability(ios,introduced=2_0)));
extern CFNetServiceMonitorRef
CFNetServiceMonitorCreate(
  CFAllocatorRef _Nullable alloc,
  CFNetServiceRef theService,
  CFNetServiceMonitorClientCallBack clientCB,
  CFNetServiceClientContext * clientContext) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetServiceMonitorInvalidate(CFNetServiceMonitorRef monitor) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFNetServiceMonitorStart(CFNetServiceMonitorRef monitor, CFNetServiceMonitorType recordType, CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetServiceMonitorStop(CFNetServiceMonitorRef monitor, CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetServiceMonitorScheduleWithRunLoop(CFNetServiceMonitorRef monitor, CFRunLoopRef runLoop, CFStringRef runLoopMode) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetServiceMonitorUnscheduleFromRunLoop(CFNetServiceMonitorRef monitor, CFRunLoopRef runLoop, CFStringRef runLoopMode) __attribute__((availability(ios,introduced=2_0)));
extern CFNetServiceBrowserRef
CFNetServiceBrowserCreate(CFAllocatorRef _Nullable alloc, CFNetServiceBrowserClientCallBack clientCB, CFNetServiceClientContext *clientContext) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetServiceBrowserInvalidate(CFNetServiceBrowserRef browser) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFNetServiceBrowserSearchForDomains(CFNetServiceBrowserRef browser, Boolean registrationDomains, CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFNetServiceBrowserSearchForServices(CFNetServiceBrowserRef browser, CFStringRef domain, CFStringRef serviceType, CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetServiceBrowserStopSearch(CFNetServiceBrowserRef browser, CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetServiceBrowserScheduleWithRunLoop(CFNetServiceBrowserRef browser, CFRunLoopRef runLoop, CFStringRef runLoopMode) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetServiceBrowserUnscheduleFromRunLoop(CFNetServiceBrowserRef browser, CFRunLoopRef runLoop, CFStringRef runLoopMode) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFNetServiceRegister(CFNetServiceRef theService, CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=NA,deprecated=NA,message="" )));
extern Boolean
CFNetServiceResolve(CFNetServiceRef theService, CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=NA,deprecated=NA,message="" )));
extern _Nullable CFStringRef
CFNetServiceGetProtocolSpecificInformation(CFNetServiceRef theService) __attribute__((availability(ios,introduced=NA,deprecated=NA,message="" )));
extern void
CFNetServiceSetProtocolSpecificInformation(CFNetServiceRef theService, CFStringRef _Nullable theInfo) __attribute__((availability(ios,introduced=NA,deprecated=NA,message="" )));





#pragma pack(pop)


}








extern "C" {
extern const CFStringRef kCFStreamPropertySSLContext __attribute__((availability(ios,introduced=5_0)));
extern const CFStringRef kCFStreamPropertySSLPeerTrust __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSSLValidatesCertificateChain __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertySSLSettings __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSSLLevel __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSSLPeerName __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSSLCertificates __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSSLIsServer __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamNetworkServiceType __attribute__((availability(ios,introduced=4_0)));


extern const CFStringRef kCFStreamNetworkServiceTypeVideo __attribute__((availability(ios,introduced=5_0)));
extern const CFStringRef kCFStreamNetworkServiceTypeVoice __attribute__((availability(ios,introduced=5_0)));
extern const CFStringRef kCFStreamNetworkServiceTypeBackground __attribute__((availability(ios,introduced=5_0)));


extern const CFStringRef kCFStreamNetworkServiceTypeVoIP __attribute__((availability(ios,introduced=4_0,deprecated=9_0,message="" "use PushKit for VoIP control purposes")));
extern const CFStringRef kCFStreamPropertyNoCellular __attribute__((availability(ios,introduced=5_0)));
extern const CFStringRef kCFStreamPropertyConnectionIsCellular __attribute__((availability(ios,introduced=6_0)));
extern const CFIndex kCFStreamErrorDomainWinSock __attribute__((availability(ios,introduced=2_0)));
extern const int kCFStreamErrorDomainSOCKS __attribute__((availability(ios,introduced=2_0)));



static __inline__ __attribute__((always_inline))
SInt32 CFSocketStreamSOCKSGetErrorSubdomain(const CFStreamError* error) {
 return ((error->error >> 16) & 0x0000FFFF);
}

static __inline__ __attribute__((always_inline))
SInt32 CFSocketStreamSOCKSGetError(const CFStreamError* error) {
 return (error->error & 0x0000FFFF);
}

enum {
  kCFStreamErrorSOCKSSubDomainNone = 0,
  kCFStreamErrorSOCKSSubDomainVersionCode = 1,
  kCFStreamErrorSOCKS4SubDomainResponse = 2,
  kCFStreamErrorSOCKS5SubDomainUserPass = 3,
  kCFStreamErrorSOCKS5SubDomainMethod = 4,
  kCFStreamErrorSOCKS5SubDomainResponse = 5
};



enum {
  kCFStreamErrorSOCKS5BadResponseAddr = 1,
  kCFStreamErrorSOCKS5BadState = 2,
  kCFStreamErrorSOCKSUnknownClientVersion = 3
};


enum {
  kCFStreamErrorSOCKS4RequestFailed = 91,
  kCFStreamErrorSOCKS4IdentdFailed = 92,
  kCFStreamErrorSOCKS4IdConflict = 93
};


enum {
  kSOCKS5NoAcceptableMethod = 0xFF
};
extern const CFStringRef kCFStreamPropertySOCKSProxy __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertySOCKSProxyHost __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertySOCKSProxyPort __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertySOCKSVersion __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSocketSOCKSVersion4 __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSocketSOCKSVersion5 __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertySOCKSUser __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertySOCKSPassword __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertyProxyLocalBypass __attribute__((availability(ios,introduced=2_0)));
extern const int kCFStreamErrorDomainSSL __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertySocketSecurityLevel __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSocketSecurityLevelNone __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSocketSecurityLevelSSLv2 __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSocketSecurityLevelSSLv3 __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSocketSecurityLevelTLSv1 __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamSocketSecurityLevelNegotiatedSSL __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertyShouldCloseNativeSocket __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertySocketRemoteHost __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertySocketRemoteNetService __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertySocketExtendedBackgroundIdleMode __attribute__((availability(ios,introduced=9_0)));
extern void
CFStreamCreatePairWithSocketToCFHost(
  CFAllocatorRef _Nullable alloc,
  CFHostRef host,
  SInt32 port,
  CFReadStreamRef _Nullable * _Nullable readStream,
  CFWriteStreamRef _Nullable * _Nullable writeStream) __attribute__((availability(ios,introduced=2_0)));
extern void
CFStreamCreatePairWithSocketToNetService(
  CFAllocatorRef _Nullable alloc,
  CFNetServiceRef service,
  CFReadStreamRef _Nullable * _Nullable readStream,
  CFWriteStreamRef _Nullable * _Nullable writeStream) __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertySSLPeerCertificates __attribute__((availability(ios,introduced=2_0,deprecated=4_0,message="" )));
extern const CFStringRef kCFStreamSSLAllowsExpiredCertificates __attribute__((availability(ios,introduced=2_0,deprecated=4_0,message="" )));
extern const CFStringRef kCFStreamSSLAllowsExpiredRoots __attribute__((availability(ios,introduced=2_0,deprecated=4_0,message="" )));
extern const CFStringRef kCFStreamSSLAllowsAnyRoot __attribute__((availability(ios,introduced=2_0,deprecated=4_0,message="" )));







}



extern "C" {
extern const SInt32 kCFStreamErrorDomainFTP __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFStreamPropertyFTPUserName __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFStreamPropertyFTPPassword __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFStreamPropertyFTPUsePassiveMode __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFStreamPropertyFTPResourceSize __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFStreamPropertyFTPFetchResourceInfo __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFStreamPropertyFTPFileTransferOffset __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFStreamPropertyFTPAttemptPersistentConnection __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFStreamPropertyFTPProxy __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFStreamPropertyFTPProxyHost __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFStreamPropertyFTPProxyPort __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));





extern const CFStringRef kCFStreamPropertyFTPProxyUser __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));





extern const CFStringRef kCFStreamPropertyFTPProxyPassword __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFFTPResourceMode __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFFTPResourceName __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFFTPResourceOwner __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFFTPResourceGroup __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFFTPResourceLink __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFFTPResourceSize __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFFTPResourceType __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern const CFStringRef kCFFTPResourceModDate __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern CFReadStreamRef
CFReadStreamCreateWithFTPURL(CFAllocatorRef _Nullable alloc, CFURLRef ftpURL) __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern CFIndex
CFFTPCreateParsedResourceListing(CFAllocatorRef _Nullable alloc, const UInt8 *buffer, CFIndex bufferLength, CFDictionaryRef _Nullable * _Nullable parsed) __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));
extern CFWriteStreamRef
CFWriteStreamCreateWithFTPURL(CFAllocatorRef _Nullable alloc, CFURLRef ftpURL) __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSessionAPI for ftp requests")));



}







extern "C" {
extern const CFStringRef kCFHTTPVersion1_0 __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFHTTPVersion1_1 __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFHTTPVersion2_0 __attribute__((availability(ios,introduced=8_0)));
extern const CFStringRef kCFHTTPAuthenticationSchemeBasic __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFHTTPAuthenticationSchemeDigest __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFHTTPAuthenticationSchemeNTLM __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFHTTPAuthenticationSchemeKerberos __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFHTTPAuthenticationSchemeNegotiate __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFHTTPAuthenticationSchemeNegotiate2 __attribute__((availability(ios,introduced=3_0)));
extern const CFStringRef kCFHTTPAuthenticationSchemeXMobileMeAuthToken __attribute__((availability(ios,introduced=4_3)));
extern const CFStringRef kCFHTTPAuthenticationSchemeOAuth1 __attribute__((availability(ios,introduced=7_0)));
typedef struct __CFHTTPMessage* CFHTTPMessageRef;
extern CFTypeID
CFHTTPMessageGetTypeID(void) __attribute__((availability(ios,introduced=2_0)));
extern CFHTTPMessageRef
CFHTTPMessageCreateRequest(CFAllocatorRef _Nullable alloc, CFStringRef requestMethod, CFURLRef url, CFStringRef httpVersion) __attribute__((availability(ios,introduced=2_0)));
extern CFHTTPMessageRef
CFHTTPMessageCreateResponse(
  CFAllocatorRef _Nullable alloc,
  CFIndex statusCode,
  CFStringRef _Nullable statusDescription,
  CFStringRef httpVersion) __attribute__((availability(ios,introduced=2_0)));
extern CFHTTPMessageRef
CFHTTPMessageCreateEmpty(CFAllocatorRef _Nullable alloc, Boolean isRequest) __attribute__((availability(ios,introduced=2_0)));
extern CFHTTPMessageRef
CFHTTPMessageCreateCopy(CFAllocatorRef _Nullable alloc, CFHTTPMessageRef message) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHTTPMessageIsRequest(CFHTTPMessageRef message) __attribute__((availability(ios,introduced=2_0)));
extern CFStringRef
CFHTTPMessageCopyVersion(CFHTTPMessageRef message) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFDataRef
CFHTTPMessageCopyBody(CFHTTPMessageRef message) __attribute__((availability(ios,introduced=2_0)));
extern void
CFHTTPMessageSetBody(CFHTTPMessageRef message, CFDataRef bodyData) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFStringRef
CFHTTPMessageCopyHeaderFieldValue(CFHTTPMessageRef message, CFStringRef headerField) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFDictionaryRef
CFHTTPMessageCopyAllHeaderFields(CFHTTPMessageRef message) __attribute__((availability(ios,introduced=2_0)));
extern void
CFHTTPMessageSetHeaderFieldValue(CFHTTPMessageRef message, CFStringRef headerField, CFStringRef _Nullable value) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHTTPMessageAppendBytes(CFHTTPMessageRef message, const UInt8 *newBytes, CFIndex numBytes) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHTTPMessageIsHeaderComplete(CFHTTPMessageRef message) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFDataRef
CFHTTPMessageCopySerializedMessage(CFHTTPMessageRef message) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFURLRef
CFHTTPMessageCopyRequestURL(CFHTTPMessageRef request) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFStringRef
CFHTTPMessageCopyRequestMethod(CFHTTPMessageRef request) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHTTPMessageAddAuthentication(
  CFHTTPMessageRef request,
  CFHTTPMessageRef _Nullable authenticationFailureResponse,
  CFStringRef username,
  CFStringRef password,
  CFStringRef _Nullable authenticationScheme,
  Boolean forProxy) __attribute__((availability(ios,introduced=2_0)));
extern CFIndex
CFHTTPMessageGetResponseStatusCode(CFHTTPMessageRef response) __attribute__((availability(ios,introduced=2_0)));
extern _Nullable CFStringRef
CFHTTPMessageCopyResponseStatusLine(CFHTTPMessageRef response) __attribute__((availability(ios,introduced=2_0)));




}



extern "C" {
extern const SInt32 kCFStreamErrorDomainHTTP __attribute__((availability(ios,introduced=2_0)));







typedef int CFStreamErrorHTTP; enum {




  kCFStreamErrorHTTPParseFailure = -1,




  kCFStreamErrorHTTPRedirectionLoop = -2,




  kCFStreamErrorHTTPBadURL = -3
};
extern const CFStringRef kCFStreamPropertyHTTPResponseHeader __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern const CFStringRef kCFStreamPropertyHTTPFinalURL __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern const CFStringRef kCFStreamPropertyHTTPFinalRequest __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern const CFStringRef kCFStreamPropertyHTTPProxy __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern const CFStringRef kCFStreamPropertyHTTPProxyHost __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern const CFStringRef kCFStreamPropertyHTTPProxyPort __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern const CFStringRef kCFStreamPropertyHTTPSProxyHost __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern const CFStringRef kCFStreamPropertyHTTPSProxyPort __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern const CFStringRef kCFStreamPropertyHTTPShouldAutoredirect __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern const CFStringRef kCFStreamPropertyHTTPAttemptPersistentConnection __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern const CFStringRef kCFStreamPropertyHTTPRequestBytesWrittenCount __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern CFReadStreamRef
CFReadStreamCreateForHTTPRequest(CFAllocatorRef _Nullable alloc, CFHTTPMessageRef request) __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern CFReadStreamRef
CFReadStreamCreateForStreamedHTTPRequest(CFAllocatorRef _Nullable alloc, CFHTTPMessageRef requestHeaders, CFReadStreamRef requestBody) __attribute__((availability(ios,introduced=2_0,deprecated=9_0,message="" "Use NSURLSession API for http requests")));
extern void
CFHTTPReadStreamSetRedirectsAutomatically(CFReadStreamRef httpStream, Boolean shouldAutoRedirect) __attribute__((availability(ios,introduced=NA,deprecated=NA,message="" )));
}



extern "C" {
typedef struct _CFHTTPAuthentication* CFHTTPAuthenticationRef;
typedef int CFStreamErrorHTTPAuthentication; enum {





  kCFStreamErrorHTTPAuthenticationTypeUnsupported = -1000,





  kCFStreamErrorHTTPAuthenticationBadUserName = -1001,





  kCFStreamErrorHTTPAuthenticationBadPassword = -1002
};
extern const CFStringRef kCFHTTPAuthenticationUsername __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFHTTPAuthenticationPassword __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFHTTPAuthenticationAccountDomain __attribute__((availability(ios,introduced=2_0)));
extern CFTypeID
CFHTTPAuthenticationGetTypeID(void) __attribute__((availability(ios,introduced=2_0)));
extern CFHTTPAuthenticationRef
CFHTTPAuthenticationCreateFromResponse(CFAllocatorRef _Nullable alloc, CFHTTPMessageRef response) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHTTPAuthenticationIsValid(CFHTTPAuthenticationRef auth, CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHTTPAuthenticationAppliesToRequest(CFHTTPAuthenticationRef auth, CFHTTPMessageRef request) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHTTPAuthenticationRequiresOrderedRequests(CFHTTPAuthenticationRef auth) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHTTPMessageApplyCredentials(
  CFHTTPMessageRef request,
  CFHTTPAuthenticationRef auth,
  CFStringRef _Nullable username,
  CFStringRef _Nullable password,
  CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHTTPMessageApplyCredentialDictionary(
  CFHTTPMessageRef request,
  CFHTTPAuthenticationRef auth,
  CFDictionaryRef dict,
  CFStreamError * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern CFStringRef
CFHTTPAuthenticationCopyRealm(CFHTTPAuthenticationRef auth) __attribute__((availability(ios,introduced=2_0)));
extern CFArrayRef
CFHTTPAuthenticationCopyDomains(CFHTTPAuthenticationRef auth) __attribute__((availability(ios,introduced=2_0)));
extern CFStringRef
CFHTTPAuthenticationCopyMethod(CFHTTPAuthenticationRef auth) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHTTPAuthenticationRequiresUserNameAndPassword(CFHTTPAuthenticationRef auth) __attribute__((availability(ios,introduced=2_0)));
extern Boolean
CFHTTPAuthenticationRequiresAccountDomain(CFHTTPAuthenticationRef auth) __attribute__((availability(ios,introduced=2_0)));




}



extern "C" {
typedef struct __CFNetDiagnostic* CFNetDiagnosticRef;







typedef int CFNetDiagnosticStatusValues; enum {




  kCFNetDiagnosticNoErr = 0,




  kCFNetDiagnosticErr = -66560L,




  kCFNetDiagnosticConnectionUp = -66559L,
  kCFNetDiagnosticConnectionIndeterminate = -66558L,




  kCFNetDiagnosticConnectionDown = -66557L
};
typedef CFIndex CFNetDiagnosticStatus;
extern CFNetDiagnosticRef
CFNetDiagnosticCreateWithStreams(CFAllocatorRef _Nullable alloc, CFReadStreamRef _Nullable readStream, CFWriteStreamRef _Nullable writeStream) __attribute__((availability(ios,introduced=2_0)));
extern CFNetDiagnosticRef
CFNetDiagnosticCreateWithURL(CFAllocatorRef alloc, CFURLRef url) __attribute__((availability(ios,introduced=2_0)));
extern void
CFNetDiagnosticSetName(CFNetDiagnosticRef details, CFStringRef name) __attribute__((availability(ios,introduced=2_0)));
extern CFNetDiagnosticStatus
CFNetDiagnosticDiagnoseProblemInteractively(CFNetDiagnosticRef details) __attribute__((availability(ios,introduced=2_0)));
extern CFNetDiagnosticStatus
CFNetDiagnosticCopyNetworkStatusPassively(CFNetDiagnosticRef details, CFStringRef _Nullable * _Nullable description) __attribute__((availability(ios,introduced=2_0)));




}







extern "C" {
extern _Nullable CFDictionaryRef
CFNetworkCopySystemProxySettings(void) __attribute__((availability(ios,introduced=2_0)));
extern CFArrayRef
CFNetworkCopyProxiesForURL(CFURLRef url, CFDictionaryRef proxySettings) __attribute__((availability(ios,introduced=2_0)));
typedef void ( * CFProxyAutoConfigurationResultCallback)(void *client, CFArrayRef proxyList, CFErrorRef _Nullable error);
extern _Nullable CFArrayRef
CFNetworkCopyProxiesForAutoConfigurationScript(CFStringRef proxyAutoConfigurationScript, CFURLRef targetURL, CFErrorRef * _Nullable error) __attribute__((availability(ios,introduced=2_0)));
extern CFRunLoopSourceRef
CFNetworkExecuteProxyAutoConfigurationScript(
  CFStringRef proxyAutoConfigurationScript,
  CFURLRef targetURL,
  CFProxyAutoConfigurationResultCallback cb,
  CFStreamClientContext * clientContext) __attribute__((availability(ios,introduced=2_0)));
extern CFRunLoopSourceRef
CFNetworkExecuteProxyAutoConfigurationURL(
  CFURLRef proxyAutoConfigURL,
  CFURLRef targetURL,
  CFProxyAutoConfigurationResultCallback cb,
  CFStreamClientContext * clientContext) __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFProxyTypeKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFProxyHostNameKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFProxyPortNumberKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFProxyAutoConfigurationURLKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFProxyAutoConfigurationJavaScriptKey __attribute__((availability(ios,introduced=3_0)));
extern const CFStringRef kCFProxyUsernameKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFProxyPasswordKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFProxyTypeNone __attribute__((availability(ios,introduced=2_0)));





extern const CFStringRef kCFProxyTypeHTTP __attribute__((availability(ios,introduced=2_0)));





extern const CFStringRef kCFProxyTypeHTTPS __attribute__((availability(ios,introduced=2_0)));





extern const CFStringRef kCFProxyTypeSOCKS __attribute__((availability(ios,introduced=2_0)));





extern const CFStringRef kCFProxyTypeFTP __attribute__((availability(ios,introduced=2_0)));





extern const CFStringRef kCFProxyTypeAutoConfigurationURL __attribute__((availability(ios,introduced=2_0)));





extern const CFStringRef kCFProxyTypeAutoConfigurationJavaScript __attribute__((availability(ios,introduced=3_0)));





extern const CFStringRef kCFProxyAutoConfigurationHTTPResponseKey __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFNetworkProxiesExceptionsList __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesExcludeSimpleHostnames __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesFTPEnable __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesFTPPassive __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesFTPPort __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesFTPProxy __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesGopherEnable __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesGopherPort __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesGopherProxy __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesHTTPEnable __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFNetworkProxiesHTTPPort __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFNetworkProxiesHTTPProxy __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFNetworkProxiesHTTPSEnable __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesHTTPSPort __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesHTTPSProxy __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesRTSPEnable __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesRTSPPort __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesRTSPProxy __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesSOCKSEnable __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesSOCKSPort __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesSOCKSProxy __attribute__((availability(ios,introduced=NA)));
extern const CFStringRef kCFNetworkProxiesProxyAutoConfigEnable __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFNetworkProxiesProxyAutoConfigURLString __attribute__((availability(ios,introduced=2_0)));
extern const CFStringRef kCFNetworkProxiesProxyAutoConfigJavaScript __attribute__((availability(ios,introduced=3_0)));
extern const CFStringRef kCFNetworkProxiesProxyAutoDiscoveryEnable __attribute__((availability(ios,introduced=NA)));



}
// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif








extern "C" NSString * const NSURLErrorDomain;





extern "C" NSString * const NSURLErrorFailingURLErrorKey __attribute__((availability(ios,introduced=4_0)));






extern "C" NSString * const NSURLErrorFailingURLStringErrorKey __attribute__((availability(ios,introduced=4_0)));






extern "C" NSString * const NSErrorFailingURLStringKey __attribute__((availability(ios,introduced=2_0,deprecated=4_0,message="" )));





extern "C" NSString * const NSURLErrorFailingURLPeerTrustErrorKey __attribute__((availability(ios,introduced=4_0)));






extern "C" NSString * const NSURLErrorBackgroundTaskCancelledReasonKey __attribute__((availability(ios,introduced=8_0)));






enum
{
    NSURLErrorCancelledReasonUserForceQuitApplication = 0,
    NSURLErrorCancelledReasonBackgroundUpdatesDisabled = 1,
    NSURLErrorCancelledReasonInsufficientSystemResources __attribute__((availability(ios,introduced=8_0))) = 2,

} __attribute__((availability(ios,introduced=7_0)));





enum
{
    NSURLErrorUnknown = -1,
    NSURLErrorCancelled = -999,
    NSURLErrorBadURL = -1000,
    NSURLErrorTimedOut = -1001,
    NSURLErrorUnsupportedURL = -1002,
    NSURLErrorCannotFindHost = -1003,
    NSURLErrorCannotConnectToHost = -1004,
    NSURLErrorNetworkConnectionLost = -1005,
    NSURLErrorDNSLookupFailed = -1006,
    NSURLErrorHTTPTooManyRedirects = -1007,
    NSURLErrorResourceUnavailable = -1008,
    NSURLErrorNotConnectedToInternet = -1009,
    NSURLErrorRedirectToNonExistentLocation = -1010,
    NSURLErrorBadServerResponse = -1011,
    NSURLErrorUserCancelledAuthentication = -1012,
    NSURLErrorUserAuthenticationRequired = -1013,
    NSURLErrorZeroByteResource = -1014,
    NSURLErrorCannotDecodeRawData = -1015,
    NSURLErrorCannotDecodeContentData = -1016,
    NSURLErrorCannotParseResponse = -1017,
    NSURLErrorAppTransportSecurityRequiresSecureConnection __attribute__((availability(ios,introduced=9_0))) = -1022,
    NSURLErrorFileDoesNotExist = -1100,
    NSURLErrorFileIsDirectory = -1101,
    NSURLErrorNoPermissionsToReadFile = -1102,
    NSURLErrorDataLengthExceedsMaximum __attribute__((availability(ios,introduced=2_0))) = -1103,


    NSURLErrorSecureConnectionFailed = -1200,
    NSURLErrorServerCertificateHasBadDate = -1201,
    NSURLErrorServerCertificateUntrusted = -1202,
    NSURLErrorServerCertificateHasUnknownRoot = -1203,
    NSURLErrorServerCertificateNotYetValid = -1204,
    NSURLErrorClientCertificateRejected = -1205,
    NSURLErrorClientCertificateRequired = -1206,
    NSURLErrorCannotLoadFromNetwork = -2000,


    NSURLErrorCannotCreateFile = -3000,
    NSURLErrorCannotOpenFile = -3001,
    NSURLErrorCannotCloseFile = -3002,
    NSURLErrorCannotWriteToFile = -3003,
    NSURLErrorCannotRemoveFile = -3004,
    NSURLErrorCannotMoveFile = -3005,
    NSURLErrorDownloadDecodingFailedMidStream = -3006,
    NSURLErrorDownloadDecodingFailedToComplete =-3007,

    NSURLErrorInternationalRoamingOff __attribute__((availability(ios,introduced=3_0))) = -1018,
    NSURLErrorCallIsActive __attribute__((availability(ios,introduced=3_0))) = -1019,
    NSURLErrorDataNotAllowed __attribute__((availability(ios,introduced=3_0))) = -1020,
    NSURLErrorRequestBodyStreamExhausted __attribute__((availability(ios,introduced=3_0))) = -1021,

    NSURLErrorBackgroundSessionRequiresSharedContainer __attribute__((availability(ios,introduced=8_0))) = -995,
    NSURLErrorBackgroundSessionInUseByAnotherProcess __attribute__((availability(ios,introduced=8_0))) = -996,
    NSURLErrorBackgroundSessionWasDisconnected __attribute__((availability(ios,introduced=8_0)))= -997,
};

// @class NSCachedURLResponse;
#ifndef _REWRITER_typedef_NSCachedURLResponse
#define _REWRITER_typedef_NSCachedURLResponse
typedef struct objc_object NSCachedURLResponse;
typedef struct {} _objc_exc_NSCachedURLResponse;
#endif

// @class NSError;
#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

// @class NSMutableURLRequest;
#ifndef _REWRITER_typedef_NSMutableURLRequest
#define _REWRITER_typedef_NSMutableURLRequest
typedef struct objc_object NSMutableURLRequest;
typedef struct {} _objc_exc_NSMutableURLRequest;
#endif

// @class NSURLAuthenticationChallenge;
#ifndef _REWRITER_typedef_NSURLAuthenticationChallenge
#define _REWRITER_typedef_NSURLAuthenticationChallenge
typedef struct objc_object NSURLAuthenticationChallenge;
typedef struct {} _objc_exc_NSURLAuthenticationChallenge;
#endif

// @class NSURLConnection;
#ifndef _REWRITER_typedef_NSURLConnection
#define _REWRITER_typedef_NSURLConnection
typedef struct objc_object NSURLConnection;
typedef struct {} _objc_exc_NSURLConnection;
#endif

// @class NSURLProtocol;
#ifndef _REWRITER_typedef_NSURLProtocol
#define _REWRITER_typedef_NSURLProtocol
typedef struct objc_object NSURLProtocol;
typedef struct {} _objc_exc_NSURLProtocol;
#endif

// @class NSURLProtocolInternal;
#ifndef _REWRITER_typedef_NSURLProtocolInternal
#define _REWRITER_typedef_NSURLProtocolInternal
typedef struct objc_object NSURLProtocolInternal;
typedef struct {} _objc_exc_NSURLProtocolInternal;
#endif

// @class NSURLRequest;
#ifndef _REWRITER_typedef_NSURLRequest
#define _REWRITER_typedef_NSURLRequest
typedef struct objc_object NSURLRequest;
typedef struct {} _objc_exc_NSURLRequest;
#endif

// @class NSURLResponse;
#ifndef _REWRITER_typedef_NSURLResponse
#define _REWRITER_typedef_NSURLResponse
typedef struct objc_object NSURLResponse;
typedef struct {} _objc_exc_NSURLResponse;
#endif

// @class NSURLSessionTask;
#ifndef _REWRITER_typedef_NSURLSessionTask
#define _REWRITER_typedef_NSURLSessionTask
typedef struct objc_object NSURLSessionTask;
typedef struct {} _objc_exc_NSURLSessionTask;
#endif

// @protocol NSURLProtocolClient <NSObject>
// - (void)URLProtocol:(NSURLProtocol *)protocol wasRedirectedToRequest:(NSURLRequest *)request redirectResponse:(NSURLResponse *)redirectResponse;
// - (void)URLProtocol:(NSURLProtocol *)protocol cachedResponseIsValid:(NSCachedURLResponse *)cachedResponse;
// - (void)URLProtocol:(NSURLProtocol *)protocol didReceiveResponse:(NSURLResponse *)response cacheStoragePolicy:(NSURLCacheStoragePolicy)policy;
// - (void)URLProtocol:(NSURLProtocol *)protocol didLoadData:(NSData *)data;







// - (void)URLProtocolDidFinishLoading:(NSURLProtocol *)protocol;
// - (void)URLProtocol:(NSURLProtocol *)protocol didFailWithError:(NSError *)error;
// - (void)URLProtocol:(NSURLProtocol *)protocol didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;







// - (void)URLProtocol:(NSURLProtocol *)protocol didCancelAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;

/* @end */


#ifndef _REWRITER_typedef_NSURLProtocol
#define _REWRITER_typedef_NSURLProtocol
typedef struct objc_object NSURLProtocol;
typedef struct {} _objc_exc_NSURLProtocol;
#endif

struct NSURLProtocol_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSURLProtocolInternal *__strong _internal;
};

// - (instancetype)initWithRequest:(NSURLRequest *)request cachedResponse:(nullable NSCachedURLResponse *)cachedResponse client:(nullable id <NSURLProtocolClient>)client __attribute__((objc_designated_initializer));






// @property (nullable, readonly, retain) id <NSURLProtocolClient> client;






// @property (readonly, copy) NSURLRequest *request;






// @property (nullable, readonly, copy) NSCachedURLResponse *cachedResponse;
// + (BOOL)canInitWithRequest:(NSURLRequest *)request;
// + (NSURLRequest *)canonicalRequestForRequest:(NSURLRequest *)request;
// + (BOOL)requestIsCacheEquivalent:(NSURLRequest *)a toRequest:(NSURLRequest *)b;







// - (void)startLoading;
// - (void)stopLoading;
// + (nullable id)propertyForKey:(NSString *)key inRequest:(NSURLRequest *)request;
// + (void)setProperty:(id)value forKey:(NSString *)key inRequest:(NSMutableURLRequest *)request;
// + (void)removePropertyForKey:(NSString *)key inRequest:(NSMutableURLRequest *)request;
// + (BOOL)registerClass:(Class)protocolClass;
// + (void)unregisterClass:(Class)protocolClass;

/* @end */



// @interface NSURLProtocol (NSURLSessionTaskAdditions)
// + (BOOL)canInitWithTask:(NSURLSessionTask *)task __attribute__((availability(ios,introduced=8_0)));
// - (instancetype)initWithTask:(NSURLSessionTask *)task cachedResponse:(nullable NSCachedURLResponse *)cachedResponse client:(nullable id <NSURLProtocolClient>)client __attribute__((availability(ios,introduced=8_0)));
// @property (nullable, readonly, copy) NSURLSessionTask *task __attribute__((availability(ios,introduced=8_0)));
/* @end */

// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

// @class NSInputStream;
#ifndef _REWRITER_typedef_NSInputStream
#define _REWRITER_typedef_NSInputStream
typedef struct objc_object NSInputStream;
typedef struct {} _objc_exc_NSInputStream;
#endif

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @class NSURL;
#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

// @class NSURLRequestInternal;
#ifndef _REWRITER_typedef_NSURLRequestInternal
#define _REWRITER_typedef_NSURLRequestInternal
typedef struct objc_object NSURLRequestInternal;
typedef struct {} _objc_exc_NSURLRequestInternal;
#endif

typedef NSUInteger NSURLRequestCachePolicy; enum
{
    NSURLRequestUseProtocolCachePolicy = 0,

    NSURLRequestReloadIgnoringLocalCacheData = 1,
    NSURLRequestReloadIgnoringLocalAndRemoteCacheData = 4,
    NSURLRequestReloadIgnoringCacheData = NSURLRequestReloadIgnoringLocalCacheData,

    NSURLRequestReturnCacheDataElseLoad = 2,
    NSURLRequestReturnCacheDataDontLoad = 3,

    NSURLRequestReloadRevalidatingCacheData = 5,
};
typedef NSUInteger NSURLRequestNetworkServiceType; enum
{
    NSURLNetworkServiceTypeDefault = 0,
    NSURLNetworkServiceTypeVoIP = 1,
    NSURLNetworkServiceTypeVideo = 2,
    NSURLNetworkServiceTypeBackground = 3,
    NSURLNetworkServiceTypeVoice = 4
};

#ifndef _REWRITER_typedef_NSURLRequest
#define _REWRITER_typedef_NSURLRequest
typedef struct objc_object NSURLRequest;
typedef struct {} _objc_exc_NSURLRequest;
#endif

struct NSURLRequest_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSURLRequestInternal *__strong _internal;
};

// + (instancetype)requestWithURL:(NSURL *)URL;






// + (BOOL)supportsSecureCoding;
// + (instancetype)requestWithURL:(NSURL *)URL cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(NSTimeInterval)timeoutInterval;
// - (instancetype)initWithURL:(NSURL *)URL;
// - (instancetype)initWithURL:(NSURL *)URL cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(NSTimeInterval)timeoutInterval __attribute__((objc_designated_initializer));






// @property (nullable, readonly, copy) NSURL *URL;






// @property (readonly) NSURLRequestCachePolicy cachePolicy;
// @property (readonly) NSTimeInterval timeoutInterval;
// @property (nullable, readonly, copy) NSURL *mainDocumentURL;
// @property (readonly) NSURLRequestNetworkServiceType networkServiceType __attribute__((availability(ios,introduced=4_0)));
// @property (readonly) BOOL allowsCellularAccess __attribute__((availability(ios,introduced=6_0)));

/* @end */


#ifndef _REWRITER_typedef_NSMutableURLRequest
#define _REWRITER_typedef_NSMutableURLRequest
typedef struct objc_object NSMutableURLRequest;
typedef struct {} _objc_exc_NSMutableURLRequest;
#endif

struct NSMutableURLRequest_IMPL {
	struct NSURLRequest_IMPL NSURLRequest_IVARS;
};







// @property (nullable, copy) NSURL *URL;






// @property NSURLRequestCachePolicy cachePolicy;
// @property NSTimeInterval timeoutInterval;
// @property (nullable, copy) NSURL *mainDocumentURL;
// @property NSURLRequestNetworkServiceType networkServiceType __attribute__((availability(ios,introduced=4_0)));
// @property BOOL allowsCellularAccess __attribute__((availability(ios,introduced=6_0)));

/* @end */

// @interface NSURLRequest (NSHTTPURLRequest)






// @property (nullable, readonly, copy) NSString *HTTPMethod;
// @property (nullable, readonly, copy) NSDictionary<NSString *, NSString *> *allHTTPHeaderFields;
// - (nullable NSString *)valueForHTTPHeaderField:(NSString *)field;
// @property (nullable, readonly, copy) NSData *HTTPBody;
// @property (nullable, readonly, retain) NSInputStream *HTTPBodyStream;
// @property (readonly) BOOL HTTPShouldHandleCookies;
// @property (readonly) BOOL HTTPShouldUsePipelining __attribute__((availability(ios,introduced=4_0)));

/* @end */

// @interface NSMutableURLRequest (NSMutableHTTPURLRequest)






// @property (copy) NSString *HTTPMethod;
// @property (nullable, copy) NSDictionary<NSString *, NSString *> *allHTTPHeaderFields;
// - (void)setValue:(nullable NSString *)value forHTTPHeaderField:(NSString *)field;
// - (void)addValue:(NSString *)value forHTTPHeaderField:(NSString *)field;
// @property (nullable, copy) NSData *HTTPBody;
// @property (nullable, retain) NSInputStream *HTTPBodyStream;
// @property BOOL HTTPShouldHandleCookies;
// @property BOOL HTTPShouldUsePipelining __attribute__((availability(ios,introduced=4_0)));

/* @end */

// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @class NSURL;
#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

// @class NSURLRequest;
#ifndef _REWRITER_typedef_NSURLRequest
#define _REWRITER_typedef_NSURLRequest
typedef struct objc_object NSURLRequest;
typedef struct {} _objc_exc_NSURLRequest;
#endif

// @class NSURLResponseInternal;
#ifndef _REWRITER_typedef_NSURLResponseInternal
#define _REWRITER_typedef_NSURLResponseInternal
typedef struct objc_object NSURLResponseInternal;
typedef struct {} _objc_exc_NSURLResponseInternal;
#endif


#ifndef _REWRITER_typedef_NSURLResponse
#define _REWRITER_typedef_NSURLResponse
typedef struct objc_object NSURLResponse;
typedef struct {} _objc_exc_NSURLResponse;
#endif

struct NSURLResponse_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSURLResponseInternal *__strong _internal;
};

// - (instancetype)initWithURL:(NSURL *)URL MIMEType:(nullable NSString *)MIMEType expectedContentLength:(NSInteger)length textEncodingName:(nullable NSString *)name __attribute__((objc_designated_initializer));






// @property (nullable, readonly, copy) NSURL *URL;
// @property (nullable, readonly, copy) NSString *MIMEType;
// @property (readonly) long long expectedContentLength;
// @property (nullable, readonly, copy) NSString *textEncodingName;
// @property (nullable, readonly, copy) NSString *suggestedFilename;

/* @end */




// @class NSHTTPURLResponseInternal;
#ifndef _REWRITER_typedef_NSHTTPURLResponseInternal
#define _REWRITER_typedef_NSHTTPURLResponseInternal
typedef struct objc_object NSHTTPURLResponseInternal;
typedef struct {} _objc_exc_NSHTTPURLResponseInternal;
#endif


#ifndef _REWRITER_typedef_NSHTTPURLResponse
#define _REWRITER_typedef_NSHTTPURLResponse
typedef struct objc_object NSHTTPURLResponse;
typedef struct {} _objc_exc_NSHTTPURLResponse;
#endif

struct NSHTTPURLResponse_IMPL {
	struct NSURLResponse_IMPL NSURLResponse_IVARS;
	NSHTTPURLResponseInternal *__strong _httpInternal;
};

// - (nullable instancetype)initWithURL:(NSURL *)url statusCode:(NSInteger)statusCode HTTPVersion:(nullable NSString *)HTTPVersion headerFields:(nullable NSDictionary<NSString *, NSString *> *)headerFields __attribute__((availability(ios,introduced=5_0)));






// @property (readonly) NSInteger statusCode;
// @property (readonly, copy) NSDictionary *allHeaderFields;
// + (NSString *)localizedStringForStatusCode:(NSInteger)statusCode;

/* @end */







// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSMutableDictionary
#define _REWRITER_typedef_NSMutableDictionary
typedef struct objc_object NSMutableDictionary;
typedef struct {} _objc_exc_NSMutableDictionary;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif





extern "C" NSString * const NSGlobalDomain;

extern "C" NSString * const NSArgumentDomain;

extern "C" NSString * const NSRegistrationDomain;

#ifndef _REWRITER_typedef_NSUserDefaults
#define _REWRITER_typedef_NSUserDefaults
typedef struct objc_object NSUserDefaults;
typedef struct {} _objc_exc_NSUserDefaults;
#endif

struct NSUserDefaults_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _kvo_;
	CFStringRef _identifier_;
	CFStringRef _container_;
	void *_reserved[2];
};





// + (NSUserDefaults *)standardUserDefaults;


// + (void)resetStandardUserDefaults;


// - (instancetype)init;


// - (nullable instancetype)initWithSuiteName:(nullable NSString *)suitename __attribute__((availability(ios,introduced=7_0))) __attribute__((objc_designated_initializer));


// - (nullable id)initWithUser:(NSString *)username __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" )));




// - (nullable id)objectForKey:(NSString *)defaultName;




// - (void)setObject:(nullable id)value forKey:(NSString *)defaultName;


// - (void)removeObjectForKey:(NSString *)defaultName;


// - (nullable NSString *)stringForKey:(NSString *)defaultName;


// - (nullable NSArray *)arrayForKey:(NSString *)defaultName;

// - (nullable NSDictionary<NSString *, id> *)dictionaryForKey:(NSString *)defaultName;

// - (nullable NSData *)dataForKey:(NSString *)defaultName;

// - (nullable NSArray<NSString *> *)stringArrayForKey:(NSString *)defaultName;



// - (NSInteger)integerForKey:(NSString *)defaultName;

// - (float)floatForKey:(NSString *)defaultName;

// - (double)doubleForKey:(NSString *)defaultName;




// - (BOOL)boolForKey:(NSString *)defaultName;



// - (nullable NSURL *)URLForKey:(NSString *)defaultName __attribute__((availability(ios,introduced=4_0)));


// - (void)setInteger:(NSInteger)value forKey:(NSString *)defaultName;

// - (void)setFloat:(float)value forKey:(NSString *)defaultName;

// - (void)setDouble:(double)value forKey:(NSString *)defaultName;

// - (void)setBool:(BOOL)value forKey:(NSString *)defaultName;

// - (void)setURL:(nullable NSURL *)url forKey:(NSString *)defaultName __attribute__((availability(ios,introduced=4_0)));






// - (void)registerDefaults:(NSDictionary<NSString *, id> *)registrationDictionary;




// - (void)addSuiteNamed:(NSString *)suiteName;



// - (void)removeSuiteNamed:(NSString *)suiteName;




// - (NSDictionary<NSString *, id> *)dictionaryRepresentation;




// @property (readonly, copy) NSArray<NSString *> *volatileDomainNames;
// - (NSDictionary<NSString *, id> *)volatileDomainForName:(NSString *)domainName;
// - (void)setVolatileDomain:(NSDictionary<NSString *, id> *)domain forName:(NSString *)domainName;
// - (void)removeVolatileDomainForName:(NSString *)domainName;


// - (NSArray *)persistentDomainNames __attribute__((availability(ios,introduced=2_0,deprecated=7_0,message="" )));


// - (nullable NSDictionary<NSString *, id> *)persistentDomainForName:(NSString *)domainName;

// - (void)setPersistentDomain:(NSDictionary<NSString *, id> *)domain forName:(NSString *)domainName;

// - (void)removePersistentDomainForName:(NSString *)domainName;
// - (BOOL)synchronize;


// - (BOOL)objectIsForcedForKey:(NSString *)key;


// - (BOOL)objectIsForcedForKey:(NSString *)key inDomain:(NSString *)domain;

/* @end */





extern "C" NSString * const NSUserDefaultsSizeLimitExceededNotification __attribute__((availability(ios,introduced=9_3)));




extern "C" NSString * const NSUbiquitousUserDefaultsDidChangeAccountsNotification __attribute__((availability(ios,introduced=9_3)));




extern "C" NSString * const NSUbiquitousUserDefaultsCompletedInitialSyncNotification __attribute__((availability(ios,introduced=9_3)));




extern "C" NSString * const NSUserDefaultsDidChangeNotification;







// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif




extern "C" NSString * const NSNegateBooleanTransformerName __attribute__((availability(ios,introduced=3_0)));
extern "C" NSString * const NSIsNilTransformerName __attribute__((availability(ios,introduced=3_0)));
extern "C" NSString * const NSIsNotNilTransformerName __attribute__((availability(ios,introduced=3_0)));
extern "C" NSString * const NSUnarchiveFromDataTransformerName __attribute__((availability(ios,introduced=3_0)));
extern "C" NSString * const NSKeyedUnarchiveFromDataTransformerName __attribute__((availability(ios,introduced=3_0)));

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=3_0)))

#ifndef _REWRITER_typedef_NSValueTransformer
#define _REWRITER_typedef_NSValueTransformer
typedef struct objc_object NSValueTransformer;
typedef struct {} _objc_exc_NSValueTransformer;
#endif

struct NSValueTransformer_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};




// + (void)setValueTransformer:(nullable NSValueTransformer *)transformer forName:(NSString *)name;
// + (nullable NSValueTransformer *)valueTransformerForName:(NSString *)name;
// + (NSArray<NSString *> *)valueTransformerNames;


// + (Class)transformedValueClass;
// + (BOOL)allowsReverseTransformation;

// - (nullable id)transformedValue:(nullable id)value;
// - (nullable id)reverseTransformedValue:(nullable id)value;

/* @end */







// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

#ifndef _REWRITER_typedef_NSInputStream
#define _REWRITER_typedef_NSInputStream
typedef struct objc_object NSInputStream;
typedef struct {} _objc_exc_NSInputStream;
#endif

#ifndef _REWRITER_typedef_NSSet
#define _REWRITER_typedef_NSSet
typedef struct objc_object NSSet;
typedef struct {} _objc_exc_NSSet;
#endif

// @protocol NSXMLParserDelegate;



__attribute__((availability(ios,introduced=8_0)))
typedef NSUInteger NSXMLParserExternalEntityResolvingPolicy; enum {
    NSXMLParserResolveExternalEntitiesNever = 0,
    NSXMLParserResolveExternalEntitiesNoNetwork,
    NSXMLParserResolveExternalEntitiesSameOriginOnly,
    NSXMLParserResolveExternalEntitiesAlways
};


#ifndef _REWRITER_typedef_NSXMLParser
#define _REWRITER_typedef_NSXMLParser
typedef struct objc_object NSXMLParser;
typedef struct {} _objc_exc_NSXMLParser;
#endif

struct NSXMLParser_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _reserved0;
	__strong id _delegate;
	__strong id _reserved1;
	__strong id _reserved2;
	__strong id _reserved3;
};

// - (nullable instancetype)initWithContentsOfURL:(NSURL *)url;
// - (instancetype)initWithData:(NSData *)data __attribute__((objc_designated_initializer));
// - (instancetype)initWithStream:(NSInputStream *)stream __attribute__((availability(ios,introduced=5_0)));


// @property (nullable, assign) id <NSXMLParserDelegate> delegate;

// @property BOOL shouldProcessNamespaces;
// @property BOOL shouldReportNamespacePrefixes;


// @property NSXMLParserExternalEntityResolvingPolicy externalEntityResolvingPolicy __attribute__((availability(ios,introduced=8_0)));

// @property (nullable, copy) NSSet<NSURL *> *allowedExternalEntityURLs __attribute__((availability(ios,introduced=8_0)));

// - (BOOL)parse;
// - (void)abortParsing;

// @property (nullable, readonly, copy) NSError *parserError;



// @property BOOL shouldResolveExternalEntities;

/* @end */



// @interface NSXMLParser (NSXMLParserLocatorAdditions)
// @property (nullable, readonly, copy) NSString *publicID;
// @property (nullable, readonly, copy) NSString *systemID;
// @property (readonly) NSInteger lineNumber;
// @property (readonly) NSInteger columnNumber;

/* @end */

// @protocol NSXMLParserDelegate <NSObject>
/* @optional */


// - (void)parserDidStartDocument:(NSXMLParser *)parser;

// - (void)parserDidEndDocument:(NSXMLParser *)parser;



// - (void)parser:(NSXMLParser *)parser foundNotationDeclarationWithName:(NSString *)name publicID:(nullable NSString *)publicID systemID:(nullable NSString *)systemID;

// - (void)parser:(NSXMLParser *)parser foundUnparsedEntityDeclarationWithName:(NSString *)name publicID:(nullable NSString *)publicID systemID:(nullable NSString *)systemID notationName:(nullable NSString *)notationName;

// - (void)parser:(NSXMLParser *)parser foundAttributeDeclarationWithName:(NSString *)attributeName forElement:(NSString *)elementName type:(nullable NSString *)type defaultValue:(nullable NSString *)defaultValue;

// - (void)parser:(NSXMLParser *)parser foundElementDeclarationWithName:(NSString *)elementName model:(NSString *)model;

// - (void)parser:(NSXMLParser *)parser foundInternalEntityDeclarationWithName:(NSString *)name value:(nullable NSString *)value;

// - (void)parser:(NSXMLParser *)parser foundExternalEntityDeclarationWithName:(NSString *)name publicID:(nullable NSString *)publicID systemID:(nullable NSString *)systemID;

// - (void)parser:(NSXMLParser *)parser didStartElement:(NSString *)elementName namespaceURI:(nullable NSString *)namespaceURI qualifiedName:(nullable NSString *)qName attributes:(NSDictionary<NSString *, NSString *> *)attributeDict;







// - (void)parser:(NSXMLParser *)parser didEndElement:(NSString *)elementName namespaceURI:(nullable NSString *)namespaceURI qualifiedName:(nullable NSString *)qName;


// - (void)parser:(NSXMLParser *)parser didStartMappingPrefix:(NSString *)prefix toURI:(NSString *)namespaceURI;




// - (void)parser:(NSXMLParser *)parser didEndMappingPrefix:(NSString *)prefix;


// - (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string;


// - (void)parser:(NSXMLParser *)parser foundIgnorableWhitespace:(NSString *)whitespaceString;


// - (void)parser:(NSXMLParser *)parser foundProcessingInstructionWithTarget:(NSString *)target data:(nullable NSString *)data;


// - (void)parser:(NSXMLParser *)parser foundComment:(NSString *)comment;


// - (void)parser:(NSXMLParser *)parser foundCDATA:(NSData *)CDATABlock;


// - (nullable NSData *)parser:(NSXMLParser *)parser resolveExternalEntityName:(NSString *)name systemID:(nullable NSString *)systemID;


// - (void)parser:(NSXMLParser *)parser parseErrorOccurred:(NSError *)parseError;


// - (void)parser:(NSXMLParser *)parser validationErrorOccurred:(NSError *)validationError;

/* @end */


extern "C" NSString * const NSXMLParserErrorDomain __attribute__((availability(ios,introduced=2_0)));


typedef NSInteger NSXMLParserError; enum {
    NSXMLParserInternalError = 1,
    NSXMLParserOutOfMemoryError = 2,
    NSXMLParserDocumentStartError = 3,
    NSXMLParserEmptyDocumentError = 4,
    NSXMLParserPrematureDocumentEndError = 5,
    NSXMLParserInvalidHexCharacterRefError = 6,
    NSXMLParserInvalidDecimalCharacterRefError = 7,
    NSXMLParserInvalidCharacterRefError = 8,
    NSXMLParserInvalidCharacterError = 9,
    NSXMLParserCharacterRefAtEOFError = 10,
    NSXMLParserCharacterRefInPrologError = 11,
    NSXMLParserCharacterRefInEpilogError = 12,
    NSXMLParserCharacterRefInDTDError = 13,
    NSXMLParserEntityRefAtEOFError = 14,
    NSXMLParserEntityRefInPrologError = 15,
    NSXMLParserEntityRefInEpilogError = 16,
    NSXMLParserEntityRefInDTDError = 17,
    NSXMLParserParsedEntityRefAtEOFError = 18,
    NSXMLParserParsedEntityRefInPrologError = 19,
    NSXMLParserParsedEntityRefInEpilogError = 20,
    NSXMLParserParsedEntityRefInInternalSubsetError = 21,
    NSXMLParserEntityReferenceWithoutNameError = 22,
    NSXMLParserEntityReferenceMissingSemiError = 23,
    NSXMLParserParsedEntityRefNoNameError = 24,
    NSXMLParserParsedEntityRefMissingSemiError = 25,
    NSXMLParserUndeclaredEntityError = 26,
    NSXMLParserUnparsedEntityError = 28,
    NSXMLParserEntityIsExternalError = 29,
    NSXMLParserEntityIsParameterError = 30,
    NSXMLParserUnknownEncodingError = 31,
    NSXMLParserEncodingNotSupportedError = 32,
    NSXMLParserStringNotStartedError = 33,
    NSXMLParserStringNotClosedError = 34,
    NSXMLParserNamespaceDeclarationError = 35,
    NSXMLParserEntityNotStartedError = 36,
    NSXMLParserEntityNotFinishedError = 37,
    NSXMLParserLessThanSymbolInAttributeError = 38,
    NSXMLParserAttributeNotStartedError = 39,
    NSXMLParserAttributeNotFinishedError = 40,
    NSXMLParserAttributeHasNoValueError = 41,
    NSXMLParserAttributeRedefinedError = 42,
    NSXMLParserLiteralNotStartedError = 43,
    NSXMLParserLiteralNotFinishedError = 44,
    NSXMLParserCommentNotFinishedError = 45,
    NSXMLParserProcessingInstructionNotStartedError = 46,
    NSXMLParserProcessingInstructionNotFinishedError = 47,
    NSXMLParserNotationNotStartedError = 48,
    NSXMLParserNotationNotFinishedError = 49,
    NSXMLParserAttributeListNotStartedError = 50,
    NSXMLParserAttributeListNotFinishedError = 51,
    NSXMLParserMixedContentDeclNotStartedError = 52,
    NSXMLParserMixedContentDeclNotFinishedError = 53,
    NSXMLParserElementContentDeclNotStartedError = 54,
    NSXMLParserElementContentDeclNotFinishedError = 55,
    NSXMLParserXMLDeclNotStartedError = 56,
    NSXMLParserXMLDeclNotFinishedError = 57,
    NSXMLParserConditionalSectionNotStartedError = 58,
    NSXMLParserConditionalSectionNotFinishedError = 59,
    NSXMLParserExternalSubsetNotFinishedError = 60,
    NSXMLParserDOCTYPEDeclNotFinishedError = 61,
    NSXMLParserMisplacedCDATAEndStringError = 62,
    NSXMLParserCDATANotFinishedError = 63,
    NSXMLParserMisplacedXMLDeclarationError = 64,
    NSXMLParserSpaceRequiredError = 65,
    NSXMLParserSeparatorRequiredError = 66,
    NSXMLParserNMTOKENRequiredError = 67,
    NSXMLParserNAMERequiredError = 68,
    NSXMLParserPCDATARequiredError = 69,
    NSXMLParserURIRequiredError = 70,
    NSXMLParserPublicIdentifierRequiredError = 71,
    NSXMLParserLTRequiredError = 72,
    NSXMLParserGTRequiredError = 73,
    NSXMLParserLTSlashRequiredError = 74,
    NSXMLParserEqualExpectedError = 75,
    NSXMLParserTagNameMismatchError = 76,
    NSXMLParserUnfinishedTagError = 77,
    NSXMLParserStandaloneValueError = 78,
    NSXMLParserInvalidEncodingNameError = 79,
    NSXMLParserCommentContainsDoubleHyphenError = 80,
    NSXMLParserInvalidEncodingError = 81,
    NSXMLParserExternalStandaloneEntityError = 82,
    NSXMLParserInvalidConditionalSectionError = 83,
    NSXMLParserEntityValueRequiredError = 84,
    NSXMLParserNotWellBalancedError = 85,
    NSXMLParserExtraContentError = 86,
    NSXMLParserInvalidCharacterInEntityError = 87,
    NSXMLParserParsedEntityRefInInternalError = 88,
    NSXMLParserEntityRefLoopError = 89,
    NSXMLParserEntityBoundaryError = 90,
    NSXMLParserInvalidURIError = 91,
    NSXMLParserURIFragmentError = 92,
    NSXMLParserNoDTDError = 94,
    NSXMLParserDelegateAbortedParseError = 512
};










enum {

    NSFileNoSuchFileError = 4,
    NSFileLockingError = 255,
    NSFileReadUnknownError = 256,
    NSFileReadNoPermissionError = 257,
    NSFileReadInvalidFileNameError = 258,
    NSFileReadCorruptFileError = 259,
    NSFileReadNoSuchFileError = 260,
    NSFileReadInapplicableStringEncodingError = 261,
    NSFileReadUnsupportedSchemeError = 262,
    NSFileReadTooLargeError __attribute__((availability(ios,introduced=2_0))) = 263,
    NSFileReadUnknownStringEncodingError __attribute__((availability(ios,introduced=2_0))) = 264,
    NSFileWriteUnknownError = 512,
    NSFileWriteNoPermissionError = 513,
    NSFileWriteInvalidFileNameError = 514,
    NSFileWriteFileExistsError __attribute__((availability(ios,introduced=5_0))) = 516,
    NSFileWriteInapplicableStringEncodingError = 517,
    NSFileWriteUnsupportedSchemeError = 518,
    NSFileWriteOutOfSpaceError = 640,
    NSFileWriteVolumeReadOnlyError __attribute__((availability(ios,introduced=4_0))) = 642,


    NSFileManagerUnmountUnknownError __attribute__((availability(ios,introduced=NA))) = 768,
    NSFileManagerUnmountBusyError __attribute__((availability(ios,introduced=NA))) = 769,


    NSKeyValueValidationError = 1024,
    NSFormattingError = 2048,
    NSUserCancelledError = 3072,
    NSFeatureUnsupportedError __attribute__((availability(ios,introduced=6_0))) = 3328,


    NSExecutableNotLoadableError __attribute__((availability(ios,introduced=2_0))) = 3584,
    NSExecutableArchitectureMismatchError __attribute__((availability(ios,introduced=2_0))) = 3585,
    NSExecutableRuntimeMismatchError __attribute__((availability(ios,introduced=2_0))) = 3586,
    NSExecutableLoadError __attribute__((availability(ios,introduced=2_0))) = 3587,
    NSExecutableLinkError __attribute__((availability(ios,introduced=2_0))) = 3588,


    NSFileErrorMinimum = 0,
    NSFileErrorMaximum = 1023,

    NSValidationErrorMinimum = 1024,
    NSValidationErrorMaximum = 2047,

    NSExecutableErrorMinimum __attribute__((availability(ios,introduced=2_0))) = 3584,
    NSExecutableErrorMaximum __attribute__((availability(ios,introduced=2_0))) = 3839,

    NSFormattingErrorMinimum = 2048,
    NSFormattingErrorMaximum = 2559,

    NSPropertyListReadCorruptError __attribute__((availability(ios,introduced=4_0))) = 3840,
    NSPropertyListReadUnknownVersionError __attribute__((availability(ios,introduced=4_0))) = 3841,
    NSPropertyListReadStreamError __attribute__((availability(ios,introduced=4_0))) = 3842,
    NSPropertyListWriteStreamError __attribute__((availability(ios,introduced=4_0))) = 3851,
    NSPropertyListWriteInvalidError __attribute__((availability(ios,introduced=8_0))) = 3852,

    NSPropertyListErrorMinimum __attribute__((availability(ios,introduced=4_0))) = 3840,
    NSPropertyListErrorMaximum __attribute__((availability(ios,introduced=4_0))) = 4095,

    NSXPCConnectionInterrupted __attribute__((availability(ios,introduced=6_0))) = 4097,
    NSXPCConnectionInvalid __attribute__((availability(ios,introduced=6_0))) = 4099,
    NSXPCConnectionReplyInvalid __attribute__((availability(ios,introduced=6_0))) = 4101,

    NSXPCConnectionErrorMinimum __attribute__((availability(ios,introduced=6_0))) = 4096,
    NSXPCConnectionErrorMaximum __attribute__((availability(ios,introduced=6_0))) = 4224,

    NSUbiquitousFileUnavailableError __attribute__((availability(ios,introduced=7_0))) = 4353,
    NSUbiquitousFileNotUploadedDueToQuotaError __attribute__((availability(ios,introduced=7_0))) = 4354,
    NSUbiquitousFileUbiquityServerNotAvailable __attribute__((availability(ios,introduced=7_0))) = 4355,

    NSUbiquitousFileErrorMinimum __attribute__((availability(ios,introduced=7_0))) = 4352,
    NSUbiquitousFileErrorMaximum __attribute__((availability(ios,introduced=7_0))) = 4607,

    NSUserActivityHandoffFailedError __attribute__((availability(ios,introduced=8_0))) = 4608,
    NSUserActivityConnectionUnavailableError __attribute__((availability(ios,introduced=8_0))) = 4609,
    NSUserActivityRemoteApplicationTimedOutError __attribute__((availability(ios,introduced=8_0))) = 4610,
    NSUserActivityHandoffUserInfoTooLargeError __attribute__((availability(ios,introduced=8_0))) = 4611,

    NSUserActivityErrorMinimum __attribute__((availability(ios,introduced=8_0))) = 4608,
    NSUserActivityErrorMaximum __attribute__((availability(ios,introduced=8_0))) = 4863,

    NSCoderReadCorruptError __attribute__((availability(ios,introduced=9_0))) = 4864,
    NSCoderValueNotFoundError __attribute__((availability(ios,introduced=9_0))) = 4865,
    NSCoderErrorMinimum __attribute__((availability(ios,introduced=9_0))) = 4864,
    NSCoderErrorMaximum __attribute__((availability(ios,introduced=9_0))) = 4991,

    NSBundleErrorMinimum __attribute__((availability(ios,introduced=9_0))) = 4992,
    NSBundleErrorMaximum __attribute__((availability(ios,introduced=9_0))) = 5119,

    NSBundleOnDemandResourceOutOfSpaceError __attribute__((availability(ios,introduced=9_0))) = 4992,
    NSBundleOnDemandResourceExceededMaximumSizeError __attribute__((availability(ios,introduced=9_0))) = 4993,
    NSBundleOnDemandResourceInvalidTagError __attribute__((availability(ios,introduced=9_0))) = 4994,
};



__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=3_2)))

#ifndef _REWRITER_typedef_NSAttributedString
#define _REWRITER_typedef_NSAttributedString
typedef struct objc_object NSAttributedString;
typedef struct {} _objc_exc_NSAttributedString;
#endif

struct NSAttributedString_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly, copy) NSString *string;
// - (NSDictionary<NSString *, id> *)attributesAtIndex:(NSUInteger)location effectiveRange:(nullable NSRangePointer)range;

/* @end */


// @interface NSAttributedString (NSExtendedAttributedString)

// @property (readonly) NSUInteger length;
// - (nullable id)attribute:(NSString *)attrName atIndex:(NSUInteger)location effectiveRange:(nullable NSRangePointer)range;
// - (NSAttributedString *)attributedSubstringFromRange:(NSRange)range;

// - (NSDictionary<NSString *, id> *)attributesAtIndex:(NSUInteger)location longestEffectiveRange:(nullable NSRangePointer)range inRange:(NSRange)rangeLimit;
// - (nullable id)attribute:(NSString *)attrName atIndex:(NSUInteger)location longestEffectiveRange:(nullable NSRangePointer)range inRange:(NSRange)rangeLimit;

// - (BOOL)isEqualToAttributedString:(NSAttributedString *)other;

// - (instancetype)initWithString:(NSString *)str;
// - (instancetype)initWithString:(NSString *)str attributes:(nullable NSDictionary<NSString *, id> *)attrs;
// - (instancetype)initWithAttributedString:(NSAttributedString *)attrStr;

typedef NSUInteger NSAttributedStringEnumerationOptions; enum {
  NSAttributedStringEnumerationReverse = (1UL << 1),
  NSAttributedStringEnumerationLongestEffectiveRangeNotRequired = (1UL << 20)
};

// - (void)enumerateAttributesInRange:(NSRange)enumerationRange options:(NSAttributedStringEnumerationOptions)opts usingBlock:(void (^)(NSDictionary<NSString *, id> *attrs, NSRange range, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));
// - (void)enumerateAttribute:(NSString *)attrName inRange:(NSRange)enumerationRange options:(NSAttributedStringEnumerationOptions)opts usingBlock:(void (^)(id _Nullable value, NSRange range, BOOL *stop))block __attribute__((availability(ios,introduced=4_0)));

/* @end */


__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=3_2)))

#ifndef _REWRITER_typedef_NSMutableAttributedString
#define _REWRITER_typedef_NSMutableAttributedString
typedef struct objc_object NSMutableAttributedString;
typedef struct {} _objc_exc_NSMutableAttributedString;
#endif

struct NSMutableAttributedString_IMPL {
	struct NSAttributedString_IMPL NSAttributedString_IVARS;
};


// - (void)replaceCharactersInRange:(NSRange)range withString:(NSString *)str;
// - (void)setAttributes:(nullable NSDictionary<NSString *, id> *)attrs range:(NSRange)range;

/* @end */


// @interface NSMutableAttributedString (NSExtendedMutableAttributedString)

// @property (readonly, retain) NSMutableString *mutableString;

// - (void)addAttribute:(NSString *)name value:(id)value range:(NSRange)range;
// - (void)addAttributes:(NSDictionary<NSString *, id> *)attrs range:(NSRange)range;
// - (void)removeAttribute:(NSString *)name range:(NSRange)range;

// - (void)replaceCharactersInRange:(NSRange)range withAttributedString:(NSAttributedString *)attrString;
// - (void)insertAttributedString:(NSAttributedString *)attrString atIndex:(NSUInteger)loc;
// - (void)appendAttributedString:(NSAttributedString *)attrString;
// - (void)deleteCharactersInRange:(NSRange)range;
// - (void)setAttributedString:(NSAttributedString *)attrString;

// - (void)beginEditing;
// - (void)endEditing;

/* @end */









typedef NSUInteger NSByteCountFormatterUnits; enum {

    NSByteCountFormatterUseDefault = 0,

    NSByteCountFormatterUseBytes = 1UL << 0,
    NSByteCountFormatterUseKB = 1UL << 1,
    NSByteCountFormatterUseMB = 1UL << 2,
    NSByteCountFormatterUseGB = 1UL << 3,
    NSByteCountFormatterUseTB = 1UL << 4,
    NSByteCountFormatterUsePB = 1UL << 5,
    NSByteCountFormatterUseEB = 1UL << 6,
    NSByteCountFormatterUseZB = 1UL << 7,
    NSByteCountFormatterUseYBOrHigher = 0x0FFUL << 8,

    NSByteCountFormatterUseAll = 0x0FFFFUL
};

typedef NSInteger NSByteCountFormatterCountStyle; enum {

    NSByteCountFormatterCountStyleFile = 0,

    NSByteCountFormatterCountStyleMemory = 1,

    NSByteCountFormatterCountStyleDecimal = 2,
    NSByteCountFormatterCountStyleBinary = 3
};


__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=6_0)))

#ifndef _REWRITER_typedef_NSByteCountFormatter
#define _REWRITER_typedef_NSByteCountFormatter
typedef struct objc_object NSByteCountFormatter;
typedef struct {} _objc_exc_NSByteCountFormatter;
#endif

struct NSByteCountFormatter_IMPL {
	struct NSFormatter_IMPL NSFormatter_IVARS;
	unsigned int _allowedUnits;
	char _countStyle;
	BOOL _allowsNonnumericFormatting;
	BOOL _includesUnit;
	BOOL _includesCount;
	BOOL _includesActualByteCount;
	BOOL _adaptive;
	BOOL _zeroPadsFractionDigits;
	int _formattingContext;
	int _reserved[5];
};




// + (NSString *)stringFromByteCount:(long long)byteCount countStyle:(NSByteCountFormatterCountStyle)countStyle;



// - (NSString *)stringFromByteCount:(long long)byteCount;



// @property NSByteCountFormatterUnits allowedUnits;



// @property NSByteCountFormatterCountStyle countStyle;



// @property BOOL allowsNonnumericFormatting;



// @property BOOL includesUnit;
// @property BOOL includesCount;



// @property BOOL includesActualByteCount;



// @property (getter=isAdaptive) BOOL adaptive;



// @property BOOL zeroPadsFractionDigits;



// @property NSFormattingContext formattingContext __attribute__((availability(ios,introduced=8_0)));

/* @end */







// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @protocol NSCacheDelegate;



__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=4_0)))

#ifndef _REWRITER_typedef_NSCache
#define _REWRITER_typedef_NSCache
typedef struct objc_object NSCache;
typedef struct {} _objc_exc_NSCache;
#endif

struct NSCache_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _delegate;
	void *_private[5];
	void *_reserved;
};


// @property (copy) NSString *name;

// @property (nullable, assign) id<NSCacheDelegate> delegate;

// - (nullable ObjectType)objectForKey:(KeyType)key;
// - (void)setObject:(ObjectType)obj forKey:(KeyType)key;
// - (void)setObject:(ObjectType)obj forKey:(KeyType)key cost:(NSUInteger)g;
// - (void)removeObjectForKey:(KeyType)key;

// - (void)removeAllObjects;

// @property NSUInteger totalCostLimit;
// @property NSUInteger countLimit;
// @property BOOL evictsObjectsWithDiscardedContent;

/* @end */


// @protocol NSCacheDelegate <NSObject>
/* @optional */
// - (void)cache:(NSCache *)cache willEvictObject:(id)obj;
/* @end */





// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif






__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=3_0)))

#ifndef _REWRITER_typedef_NSPredicate
#define _REWRITER_typedef_NSPredicate
typedef struct objc_object NSPredicate;
typedef struct {} _objc_exc_NSPredicate;
#endif

	struct _predicateFlags {
	unsigned int _evaluationBlocked : 1;
	unsigned int _reservedPredicateFlags : 31;
	} ;
struct NSPredicate_IMPL {
	struct NSObject_IMPL NSObject_IVARS;

	struct _predicateFlags _predicateFlags;
	uint32_t reserved;
};



// + (NSPredicate *)predicateWithFormat:(NSString *)predicateFormat argumentArray:(nullable NSArray *)arguments;
// + (NSPredicate *)predicateWithFormat:(NSString *)predicateFormat, ...;
// + (NSPredicate *)predicateWithFormat:(NSString *)predicateFormat arguments:(va_list)argList;

// + (nullable NSPredicate *)predicateFromMetadataQueryString:(NSString *)queryString __attribute__((availability(ios,unavailable)));

// + (NSPredicate *)predicateWithValue:(BOOL)value;

// + (NSPredicate*)predicateWithBlock:(BOOL (^)(id evaluatedObject, NSDictionary<NSString *, id> * _Nullable bindings))block __attribute__((availability(ios,introduced=4_0)));

// @property (readonly, copy) NSString *predicateFormat;

// - (instancetype)predicateWithSubstitutionVariables:(NSDictionary<NSString *, id> *)variables;

// - (BOOL)evaluateWithObject:(nullable id)object;

// - (BOOL)evaluateWithObject:(nullable id)object substitutionVariables:(nullable NSDictionary<NSString *, id> *)bindings __attribute__((availability(ios,introduced=3_0)));

// - (void)allowEvaluation __attribute__((availability(ios,introduced=7_0)));

/* @end */


// @interface NSArray<ObjectType> (NSPredicateSupport)
// - (NSArray<ObjectType> *)filteredArrayUsingPredicate:(NSPredicate *)predicate;
/* @end */


// @interface NSMutableArray<ObjectType> (NSPredicateSupport)
// - (void)filterUsingPredicate:(NSPredicate *)predicate;
/* @end */



// @interface NSSet<ObjectType> (NSPredicateSupport)
// - (NSSet<ObjectType> *)filteredSetUsingPredicate:(NSPredicate *)predicate __attribute__((availability(ios,introduced=3_0)));
/* @end */


// @interface NSMutableSet<ObjectType> (NSPredicateSupport)
// - (void)filterUsingPredicate:(NSPredicate *)predicate __attribute__((availability(ios,introduced=3_0)));
/* @end */


// @interface NSOrderedSet<ObjectType> (NSPredicateSupport)

// - (NSOrderedSet<ObjectType> *)filteredOrderedSetUsingPredicate:(NSPredicate *)p __attribute__((availability(ios,introduced=5_0)));

/* @end */


// @interface NSMutableOrderedSet<ObjectType> (NSPredicateSupport)

// - (void)filterUsingPredicate:(NSPredicate *)p __attribute__((availability(ios,introduced=5_0)));

/* @end */





typedef NSUInteger NSComparisonPredicateOptions; enum {
    NSCaseInsensitivePredicateOption = 0x01,
    NSDiacriticInsensitivePredicateOption = 0x02,
    NSNormalizedPredicateOption __attribute__((availability(ios,introduced=4_0))) = 0x04,
};


typedef NSUInteger NSComparisonPredicateModifier; enum {
    NSDirectPredicateModifier = 0,
    NSAllPredicateModifier,
    NSAnyPredicateModifier
};



typedef NSUInteger NSPredicateOperatorType; enum {
    NSLessThanPredicateOperatorType = 0,
    NSLessThanOrEqualToPredicateOperatorType,
    NSGreaterThanPredicateOperatorType,
    NSGreaterThanOrEqualToPredicateOperatorType,
    NSEqualToPredicateOperatorType,
    NSNotEqualToPredicateOperatorType,
    NSMatchesPredicateOperatorType,
    NSLikePredicateOperatorType,
    NSBeginsWithPredicateOperatorType,
    NSEndsWithPredicateOperatorType,
    NSInPredicateOperatorType,
    NSCustomSelectorPredicateOperatorType,
    NSContainsPredicateOperatorType __attribute__((availability(ios,introduced=3_0))) = 99,
    NSBetweenPredicateOperatorType __attribute__((availability(ios,introduced=3_0)))
};

// @class NSPredicateOperator;
#ifndef _REWRITER_typedef_NSPredicateOperator
#define _REWRITER_typedef_NSPredicateOperator
typedef struct objc_object NSPredicateOperator;
typedef struct {} _objc_exc_NSPredicateOperator;
#endif

// @class NSExpression;
#ifndef _REWRITER_typedef_NSExpression
#define _REWRITER_typedef_NSExpression
typedef struct objc_object NSExpression;
typedef struct {} _objc_exc_NSExpression;
#endif




__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=3_0)))

#ifndef _REWRITER_typedef_NSComparisonPredicate
#define _REWRITER_typedef_NSComparisonPredicate
typedef struct objc_object NSComparisonPredicate;
typedef struct {} _objc_exc_NSComparisonPredicate;
#endif

struct NSComparisonPredicate_IMPL {
	struct NSPredicate_IMPL NSPredicate_IVARS;
	void *_reserved2;
	NSPredicateOperator *__strong _predicateOperator;
	NSExpression *__strong _lhs;
	NSExpression *__strong _rhs;
};


// + (NSComparisonPredicate *)predicateWithLeftExpression:(NSExpression *)lhs rightExpression:(NSExpression *)rhs modifier:(NSComparisonPredicateModifier)modifier type:(NSPredicateOperatorType)type options:(NSComparisonPredicateOptions)options;
// + (NSComparisonPredicate *)predicateWithLeftExpression:(NSExpression *)lhs rightExpression:(NSExpression *)rhs customSelector:(SEL)selector;

// - (instancetype)initWithLeftExpression:(NSExpression *)lhs rightExpression:(NSExpression *)rhs modifier:(NSComparisonPredicateModifier)modifier type:(NSPredicateOperatorType)type options:(NSComparisonPredicateOptions)options __attribute__((objc_designated_initializer));
// - (instancetype)initWithLeftExpression:(NSExpression *)lhs rightExpression:(NSExpression *)rhs customSelector:(SEL)selector __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)coder __attribute__((objc_designated_initializer));

// @property (readonly) NSPredicateOperatorType predicateOperatorType;
// @property (readonly) NSComparisonPredicateModifier comparisonPredicateModifier;
// @property (readonly, retain) NSExpression *leftExpression;
// @property (readonly, retain) NSExpression *rightExpression;
// @property (nullable, readonly) SEL customSelector;
// @property (readonly) NSComparisonPredicateOptions options;

/* @end */







// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif






typedef NSUInteger NSCompoundPredicateType; enum {
    NSNotPredicateType = 0,
    NSAndPredicateType,
    NSOrPredicateType,
};

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=3_0)))

#ifndef _REWRITER_typedef_NSCompoundPredicate
#define _REWRITER_typedef_NSCompoundPredicate
typedef struct objc_object NSCompoundPredicate;
typedef struct {} _objc_exc_NSCompoundPredicate;
#endif

struct NSCompoundPredicate_IMPL {
	struct NSPredicate_IMPL NSPredicate_IVARS;
	void *_reserved2;
	NSUInteger _type;
	NSArray *__strong _subpredicates;
};


// - (instancetype)initWithType:(NSCompoundPredicateType)type subpredicates:(NSArray<NSPredicate *> *)subpredicates __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)coder __attribute__((objc_designated_initializer));

// @property (readonly) NSCompoundPredicateType compoundPredicateType;
// @property (readonly, copy) NSArray *subpredicates;


// + (NSCompoundPredicate *)andPredicateWithSubpredicates:(NSArray<NSPredicate *> *)subpredicates __attribute__((swift_name("init(andPredicateWithSubpredicates:)")));
// + (NSCompoundPredicate *)orPredicateWithSubpredicates:(NSArray<NSPredicate *> *)subpredicates __attribute__((swift_name("init(orPredicateWithSubpredicates:)")));
// + (NSCompoundPredicate *)notPredicateWithSubpredicate:(NSPredicate *)predicate __attribute__((swift_name("init(notPredicateWithSubpredicate:)")));

/* @end */

__attribute__((availability(ios,introduced=8_0)))
typedef NSInteger NSDateComponentsFormatterUnitsStyle; enum {
    NSDateComponentsFormatterUnitsStylePositional = 0,
    NSDateComponentsFormatterUnitsStyleAbbreviated,
    NSDateComponentsFormatterUnitsStyleShort,
    NSDateComponentsFormatterUnitsStyleFull,
    NSDateComponentsFormatterUnitsStyleSpellOut
};

__attribute__((availability(ios,introduced=8_0)))
typedef NSUInteger NSDateComponentsFormatterZeroFormattingBehavior; enum {
    NSDateComponentsFormatterZeroFormattingBehaviorNone = (0),
    NSDateComponentsFormatterZeroFormattingBehaviorDefault = (1 << 0),

    NSDateComponentsFormatterZeroFormattingBehaviorDropLeading = (1 << 1),
    NSDateComponentsFormatterZeroFormattingBehaviorDropMiddle = (1 << 2),
    NSDateComponentsFormatterZeroFormattingBehaviorDropTrailing = (1 << 3),
    NSDateComponentsFormatterZeroFormattingBehaviorDropAll = (NSDateComponentsFormatterZeroFormattingBehaviorDropLeading | NSDateComponentsFormatterZeroFormattingBehaviorDropMiddle | NSDateComponentsFormatterZeroFormattingBehaviorDropTrailing),

    NSDateComponentsFormatterZeroFormattingBehaviorPad = (1 << 16),
};



__attribute__((availability(ios,introduced=8_0)))

#ifndef _REWRITER_typedef_NSDateComponentsFormatter
#define _REWRITER_typedef_NSDateComponentsFormatter
typedef struct objc_object NSDateComponentsFormatter;
typedef struct {} _objc_exc_NSDateComponentsFormatter;
#endif

struct NSDateComponentsFormatter_IMPL {
	struct NSFormatter_IMPL NSFormatter_IVARS;
	pthread_mutex_t _lock;
	void *_fmt;
	void *_unused;
	NSString *__strong _fmtLocaleIdent;
	NSCalendar *__strong _calendar;
	NSDate *__strong _referenceDate;
	NSNumberFormatter *__strong _unitFormatter;
	NSCalendarUnit _allowedUnits;
	NSFormattingContext _formattingContext;
	NSDateComponentsFormatterUnitsStyle _unitsStyle;
	NSDateComponentsFormatterZeroFormattingBehavior _zeroFormattingBehavior;
	NSInteger _maximumUnitCount;
	BOOL _allowsFractionalUnits;
	BOOL _collapsesLargestUnit;
	BOOL _includesApproximationPhrase;
	BOOL _includesTimeRemainingPhrase;
	void *_reserved;
};




// - (nullable NSString *)stringForObjectValue:(id)obj;

// - (nullable NSString *)stringFromDateComponents:(NSDateComponents *)components;







// - (nullable NSString *)stringFromDate:(NSDate *)startDate toDate:(NSDate *)endDate;



// - (nullable NSString *)stringFromTimeInterval:(NSTimeInterval)ti;


// + (nullable NSString *)localizedStringFromDateComponents:(NSDateComponents *)components unitsStyle:(NSDateComponentsFormatterUnitsStyle) unitsStyle;



// @property NSDateComponentsFormatterUnitsStyle unitsStyle;
// @property NSCalendarUnit allowedUnits;





// @property NSDateComponentsFormatterZeroFormattingBehavior zeroFormattingBehavior;



// @property (nullable, copy) NSCalendar *calendar;



// @property BOOL allowsFractionalUnits;
// @property NSInteger maximumUnitCount;



// @property BOOL collapsesLargestUnit;



// @property BOOL includesApproximationPhrase;



// @property BOOL includesTimeRemainingPhrase;




// @property NSFormattingContext formattingContext;



// - (BOOL)getObjectValue:(out id _Nullable * _Nullable)obj forString:(NSString *)string errorDescription:(out NSString * _Nullable * _Nullable)error;

/* @end */







// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

// @class NSMutableDictionary;
#ifndef _REWRITER_typedef_NSMutableDictionary
#define _REWRITER_typedef_NSMutableDictionary
typedef struct objc_object NSMutableDictionary;
typedef struct {} _objc_exc_NSMutableDictionary;
#endif

// @class NSPredicate;
#ifndef _REWRITER_typedef_NSPredicate
#define _REWRITER_typedef_NSPredicate
typedef struct objc_object NSPredicate;
typedef struct {} _objc_exc_NSPredicate;
#endif






typedef NSUInteger NSExpressionType; enum {
    NSConstantValueExpressionType = 0,
    NSEvaluatedObjectExpressionType,
    NSVariableExpressionType,
    NSKeyPathExpressionType,
    NSFunctionExpressionType,
    NSUnionSetExpressionType __attribute__((availability(ios,introduced=3_0))),
    NSIntersectSetExpressionType __attribute__((availability(ios,introduced=3_0))),
    NSMinusSetExpressionType __attribute__((availability(ios,introduced=3_0))),
    NSSubqueryExpressionType __attribute__((availability(ios,introduced=3_0))) = 13,
    NSAggregateExpressionType __attribute__((availability(ios,introduced=3_0))) = 14,
    NSAnyKeyExpressionType __attribute__((availability(ios,introduced=7_0))) = 15,
    NSBlockExpressionType = 19,
    NSConditionalExpressionType __attribute__((availability(ios,introduced=9_0))) = 20

};

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=3_0)))

#ifndef _REWRITER_typedef_NSExpression
#define _REWRITER_typedef_NSExpression
typedef struct objc_object NSExpression;
typedef struct {} _objc_exc_NSExpression;
#endif

	struct _expressionFlags {
	unsigned int _evaluationBlocked : 1;
	unsigned int _reservedExpressionFlags : 31;
	} ;
struct NSExpression_IMPL {
	struct NSObject_IMPL NSObject_IVARS;

	struct _expressionFlags _expressionFlags;
	uint32_t reserved;
	NSExpressionType _expressionType;
};


// + (NSExpression *)expressionWithFormat:(NSString *)expressionFormat argumentArray:(NSArray *)arguments __attribute__((availability(ios,introduced=4_0)));
// + (NSExpression *)expressionWithFormat:(NSString *)expressionFormat, ... __attribute__((availability(ios,introduced=4_0)));
// + (NSExpression *)expressionWithFormat:(NSString *)expressionFormat arguments:(va_list)argList __attribute__((availability(ios,introduced=4_0)));

// + (NSExpression *)expressionForConstantValue:(nullable id)obj;
// + (NSExpression *)expressionForEvaluatedObject;
// + (NSExpression *)expressionForVariable:(NSString *)string;
// + (NSExpression *)expressionForKeyPath:(NSString *)keyPath;
// + (NSExpression *)expressionForFunction:(NSString *)name arguments:(NSArray *)parameters;
// + (NSExpression *)expressionForAggregate:(NSArray *)subexpressions __attribute__((availability(ios,introduced=3_0)));
// + (NSExpression *)expressionForUnionSet:(NSExpression *)left with:(NSExpression *)right __attribute__((availability(ios,introduced=3_0)));
// + (NSExpression *)expressionForIntersectSet:(NSExpression *)left with:(NSExpression *)right __attribute__((availability(ios,introduced=3_0)));
// + (NSExpression *)expressionForMinusSet:(NSExpression *)left with:(NSExpression *)right __attribute__((availability(ios,introduced=3_0)));
// + (NSExpression *)expressionForSubquery:(NSExpression *)expression usingIteratorVariable:(NSString *)variable predicate:(id)predicate __attribute__((availability(ios,introduced=3_0)));
// + (NSExpression *)expressionForFunction:(NSExpression *)target selectorName:(NSString *)name arguments:(nullable NSArray *)parameters __attribute__((availability(ios,introduced=3_0)));
// + (NSExpression *)expressionForAnyKey __attribute__((availability(ios,introduced=7_0)));
// + (NSExpression *)expressionForBlock:(id (^)(id _Nullable evaluatedObject, NSArray *expressions, NSMutableDictionary * _Nullable context))block arguments:(nullable NSArray<NSExpression *> *)arguments __attribute__((availability(ios,introduced=4_0)));
// + (NSExpression *)expressionForConditional:(NSPredicate *)predicate trueExpression:(NSExpression *)trueExpression falseExpression:(NSExpression *)falseExpression __attribute__((availability(ios,introduced=9_0)));

// - (instancetype)initWithExpressionType:(NSExpressionType)type __attribute__((objc_designated_initializer));
// - (nullable instancetype)initWithCoder:(NSCoder *)coder __attribute__((objc_designated_initializer));


// @property (readonly) NSExpressionType expressionType;
// @property (readonly, retain) id constantValue;
// @property (readonly, copy) NSString *keyPath;
// @property (readonly, copy) NSString *function;
// @property (readonly, copy) NSString *variable;
// @property (readonly, copy) NSExpression *operand;
// @property (nullable, readonly, copy) NSArray<NSExpression *> *arguments;

// @property (readonly, retain) id collection __attribute__((availability(ios,introduced=3_0)));
// @property (readonly, copy) NSPredicate *predicate __attribute__((availability(ios,introduced=3_0)));
// @property (readonly, copy) NSExpression *leftExpression __attribute__((availability(ios,introduced=3_0)));
// @property (readonly, copy) NSExpression *rightExpression __attribute__((availability(ios,introduced=3_0)));


// @property (readonly, copy) NSExpression *trueExpression __attribute__((availability(ios,introduced=9_0)));
// @property (readonly, copy) NSExpression *falseExpression __attribute__((availability(ios,introduced=9_0)));

// @property (readonly, copy) id (^expressionBlock)(id _Nullable, NSArray *, NSMutableDictionary * _Nullable) __attribute__((availability(ios,introduced=4_0)));


// - (id)expressionValueWithObject:(nullable id)object context:(nullable NSMutableDictionary *)context;

// - (void)allowEvaluation __attribute__((availability(ios,introduced=7_0)));

/* @end */

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=8_0)))

#ifndef _REWRITER_typedef_NSExtensionContext
#define _REWRITER_typedef_NSExtensionContext
typedef struct objc_object NSExtensionContext;
typedef struct {} _objc_exc_NSExtensionContext;
#endif

struct NSExtensionContext_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};



// @property(readonly, copy, nonatomic) NSArray *inputItems;


// - (void)completeRequestReturningItems:(nullable NSArray *)items completionHandler:(void(^ _Nullable)(BOOL expired))completionHandler;


// - (void)cancelRequestWithError:(NSError *)error;


// - (void)openURL:(NSURL *)URL completionHandler:(void (^ _Nullable)(BOOL success))completionHandler;

/* @end */



extern "C" NSString * _Null_unspecified const NSExtensionItemsAndErrorsKey __attribute__((availability(ios,introduced=8_0)));


extern "C" NSString * _Null_unspecified const NSExtensionHostWillEnterForegroundNotification __attribute__((availability(ios,introduced=8_2)));


extern "C" NSString * _Null_unspecified const NSExtensionHostDidEnterBackgroundNotification __attribute__((availability(ios,introduced=8_2)));


extern "C" NSString * _Null_unspecified const NSExtensionHostWillResignActiveNotification __attribute__((availability(ios,introduced=8_2)));


extern "C" NSString * _Null_unspecified const NSExtensionHostDidBecomeActiveNotification __attribute__((availability(ios,introduced=8_2)));





typedef void (*NSItemProviderCompletionHandler)(_Nullable id /*<NSSecureCoding>*/ item, NSError * _Null_unspecified error);
typedef void (*NSItemProviderLoadHandler)(_Null_unspecified NSItemProviderCompletionHandler completionHandler, _Null_unspecified Class expectedValueClass, NSDictionary * _Null_unspecified options);


__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=8_0)))

#ifndef _REWRITER_typedef_NSItemProvider
#define _REWRITER_typedef_NSItemProvider
typedef struct objc_object NSItemProvider;
typedef struct {} _objc_exc_NSItemProvider;
#endif

struct NSItemProvider_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};



// - (instancetype)initWithItem:(nullable id <NSSecureCoding>)item typeIdentifier:(nullable NSString *)typeIdentifier __attribute__((objc_designated_initializer));


// - (nullable instancetype)initWithContentsOfURL:(null_unspecified NSURL *)fileURL;


// - (void)registerItemForTypeIdentifier:(NSString *)typeIdentifier loadHandler:(NSItemProviderLoadHandler)loadHandler;


// @property(copy, readonly, nonatomic) NSArray *registeredTypeIdentifiers;


// - (BOOL)hasItemConformingToTypeIdentifier:(NSString *)typeIdentifier;


// - (void)loadItemForTypeIdentifier:(NSString *)typeIdentifier options:(nullable NSDictionary *)options completionHandler:(nullable NSItemProviderCompletionHandler)completionHandler;

/* @end */



extern "C" NSString * _Null_unspecified const NSItemProviderPreferredImageSizeKey __attribute__((availability(ios,introduced=8_0)));

// @interface NSItemProvider(NSPreviewSupport)


// @property(nullable, copy, nonatomic) NSItemProviderLoadHandler previewImageHandler __attribute__((availability(ios,introduced=8_0)));


// - (void)loadPreviewImageWithOptions:(null_unspecified NSDictionary *)options completionHandler:(null_unspecified NSItemProviderCompletionHandler)completionHandler __attribute__((availability(ios,introduced=8_0)));

/* @end */






extern "C" NSString * _Null_unspecified const NSExtensionJavaScriptPreprocessingResultsKey __attribute__((availability(ios,introduced=8_0)));


extern "C" NSString * _Null_unspecified const NSExtensionJavaScriptFinalizeArgumentKey __attribute__((availability(ios,introduced=8_0)));





extern "C" NSString * _Null_unspecified const NSItemProviderErrorDomain __attribute__((availability(ios,introduced=8_0)));


typedef NSInteger NSItemProviderErrorCode; enum {
    NSItemProviderUnknownError = -1,
    NSItemProviderItemUnavailableError = -1000,
    NSItemProviderUnexpectedValueClassError = -1100,
    NSItemProviderUnavailableCoercionError __attribute__((availability(ios,introduced=9_0))) = -1200
} __attribute__((availability(ios,introduced=8_0)));





__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=8_0)))

#ifndef _REWRITER_typedef_NSExtensionItem
#define _REWRITER_typedef_NSExtensionItem
typedef struct objc_object NSExtensionItem;
typedef struct {} _objc_exc_NSExtensionItem;
#endif

struct NSExtensionItem_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};



// @property(nullable, copy, nonatomic) NSAttributedString *attributedTitle;


// @property(nullable, copy, nonatomic) NSAttributedString *attributedContentText;


// @property(nullable, copy, nonatomic) NSArray *attachments;


// @property(nullable, copy, nonatomic) NSDictionary *userInfo;

/* @end */



extern "C" NSString * _Null_unspecified const NSExtensionItemAttributedTitleKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * _Null_unspecified const NSExtensionItemAttributedContentTextKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * _Null_unspecified const NSExtensionItemAttachmentsKey __attribute__((availability(ios,introduced=8_0)));
// @class NSExtensionContext;
#ifndef _REWRITER_typedef_NSExtensionContext
#define _REWRITER_typedef_NSExtensionContext
typedef struct objc_object NSExtensionContext;
typedef struct {} _objc_exc_NSExtensionContext;
#endif



// @protocol NSExtensionRequestHandling <NSObject>

/* @required */


// - (void)beginRequestWithExtensionContext:(NSExtensionContext *)context;

/* @end */









// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSMutableDictionary
#define _REWRITER_typedef_NSMutableDictionary
typedef struct objc_object NSMutableDictionary;
typedef struct {} _objc_exc_NSMutableDictionary;
#endif

#ifndef _REWRITER_typedef_NSOperationQueue
#define _REWRITER_typedef_NSOperationQueue
typedef struct objc_object NSOperationQueue;
typedef struct {} _objc_exc_NSOperationQueue;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif


// @protocol NSFilePresenter;



typedef NSUInteger NSFileCoordinatorReadingOptions; enum {



    NSFileCoordinatorReadingWithoutChanges = 1 << 0,



    NSFileCoordinatorReadingResolvesSymbolicLink = 1 << 1,



    NSFileCoordinatorReadingImmediatelyAvailableMetadataOnly __attribute__((availability(ios,introduced=8_0))) = 1 << 2,





    NSFileCoordinatorReadingForUploading __attribute__((availability(ios,introduced=8_0))) = 1 << 3,

};

typedef NSUInteger NSFileCoordinatorWritingOptions; enum {
    NSFileCoordinatorWritingForDeleting = 1 << 0,





    NSFileCoordinatorWritingForMoving = 1 << 1,



    NSFileCoordinatorWritingForMerging = 1 << 2,







    NSFileCoordinatorWritingForReplacing = 1 << 3,



    NSFileCoordinatorWritingContentIndependentMetadataOnly __attribute__((availability(ios,introduced=8_0))) = 1 << 4

};


__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=8_0)))

#ifndef _REWRITER_typedef_NSFileAccessIntent
#define _REWRITER_typedef_NSFileAccessIntent
typedef struct objc_object NSFileAccessIntent;
typedef struct {} _objc_exc_NSFileAccessIntent;
#endif

struct NSFileAccessIntent_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSURL *__strong _url;
	BOOL _isRead;
	NSInteger _options;
};

// + (instancetype)readingIntentWithURL:(NSURL *)url options:(NSFileCoordinatorReadingOptions)options;
// + (instancetype)writingIntentWithURL:(NSURL *)url options:(NSFileCoordinatorWritingOptions)options;
// @property (readonly, copy) NSURL *URL;
/* @end */



__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSFileCoordinator
#define _REWRITER_typedef_NSFileCoordinator
typedef struct objc_object NSFileCoordinator;
typedef struct {} _objc_exc_NSFileCoordinator;
#endif

struct NSFileCoordinator_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _accessArbiter;
	__strong id _fileReactor;
	__strong id _purposeID;
	NSURL *__strong _recentFilePresenterURL;
	__strong id _accessClaimIDOrIDs;
	BOOL _isCancelled;
	NSMutableDictionary *__strong _movedItems;
};








// + (void)addFilePresenter:(id<NSFilePresenter>)filePresenter;
// + (void)removeFilePresenter:(id<NSFilePresenter>)filePresenter;
// + (NSArray<id<NSFilePresenter>> *)filePresenters;
// - (instancetype)initWithFilePresenter:(nullable id<NSFilePresenter>)filePresenterOrNil __attribute__((objc_designated_initializer));
// @property (copy) NSString *purposeIdentifier __attribute__((availability(ios,introduced=5_0)));
// - (void)coordinateAccessWithIntents:(NSArray<NSFileAccessIntent *> *)intents queue:(NSOperationQueue *)queue byAccessor:(void (^)(NSError * _Nullable error))accessor __attribute__((availability(ios,introduced=8_0)));
// - (void)coordinateReadingItemAtURL:(NSURL *)url options:(NSFileCoordinatorReadingOptions)options error:(NSError **)outError byAccessor:(void (^)(NSURL *newURL))reader;
// - (void)coordinateWritingItemAtURL:(NSURL *)url options:(NSFileCoordinatorWritingOptions)options error:(NSError **)outError byAccessor:(void (^)(NSURL *newURL))writer;
// - (void)coordinateReadingItemAtURL:(NSURL *)readingURL options:(NSFileCoordinatorReadingOptions)readingOptions writingItemAtURL:(NSURL *)writingURL options:(NSFileCoordinatorWritingOptions)writingOptions error:(NSError **)outError byAccessor:(void (^)(NSURL *newReadingURL, NSURL *newWritingURL))readerWriter;
// - (void)coordinateWritingItemAtURL:(NSURL *)url1 options:(NSFileCoordinatorWritingOptions)options1 writingItemAtURL:(NSURL *)url2 options:(NSFileCoordinatorWritingOptions)options2 error:(NSError **)outError byAccessor:(void (^)(NSURL *newURL1, NSURL *newURL2))writer;
// - (void)prepareForReadingItemsAtURLs:(NSArray<NSURL *> *)readingURLs options:(NSFileCoordinatorReadingOptions)readingOptions writingItemsAtURLs:(NSArray<NSURL *> *)writingURLs options:(NSFileCoordinatorWritingOptions)writingOptions error:(NSError **)outError byAccessor:(void (^)(void (^completionHandler)(void)))batchAccessor;
// - (void)itemAtURL:(NSURL *)oldURL willMoveToURL:(NSURL *)newURL __attribute__((availability(ios,introduced=6_0)));
// - (void)itemAtURL:(NSURL *)oldURL didMoveToURL:(NSURL *)newURL;







// - (void)cancel;

/* @end */









// @class NSError;
#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSFileVersion
#define _REWRITER_typedef_NSFileVersion
typedef struct objc_object NSFileVersion;
typedef struct {} _objc_exc_NSFileVersion;
#endif

#ifndef _REWRITER_typedef_NSOperationQueue
#define _REWRITER_typedef_NSOperationQueue
typedef struct objc_object NSOperationQueue;
typedef struct {} _objc_exc_NSOperationQueue;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

// @protocol NSFilePresenter<NSObject>

/* @required */





// @property (nullable, readonly, copy) NSURL *presentedItemURL;





// @property (readonly, retain) NSOperationQueue *presentedItemOperationQueue;

/* @optional */



// @property (nullable, readonly, copy) NSURL *primaryPresentedItemURL __attribute__((availability(ios,introduced=NA)));





// - (void)relinquishPresentedItemToReader:(void (^)(void (^ _Nullable reacquirer)(void)))reader;





// - (void)relinquishPresentedItemToWriter:(void (^)(void (^ _Nullable reacquirer)(void)))writer;







// - (void)savePresentedItemChangesWithCompletionHandler:(void (^)(NSError * _Nullable errorOrNil))completionHandler;







// - (void)accommodatePresentedItemDeletionWithCompletionHandler:(void (^)(NSError * _Nullable errorOrNil))completionHandler;
// - (void)presentedItemDidMoveToURL:(NSURL *)newURL;
// - (void)presentedItemDidChange;





// - (void)presentedItemDidGainVersion:(NSFileVersion *)version;
// - (void)presentedItemDidLoseVersion:(NSFileVersion *)version;
// - (void)presentedItemDidResolveConflictVersion:(NSFileVersion *)version;
// - (void)accommodatePresentedSubitemDeletionAtURL:(NSURL *)url completionHandler:(void (^)(NSError * _Nullable errorOrNil))completionHandler;





// - (void)presentedSubitemDidAppearAtURL:(NSURL *)url;





// - (void)presentedSubitemAtURL:(NSURL *)oldURL didMoveToURL:(NSURL *)newURL;





// - (void)presentedSubitemDidChangeAtURL:(NSURL *)url;



// - (void)presentedSubitemAtURL:(NSURL *)url didGainVersion:(NSFileVersion *)version;
// - (void)presentedSubitemAtURL:(NSURL *)url didLoseVersion:(NSFileVersion *)version;
// - (void)presentedSubitemAtURL:(NSURL *)url didResolveConflictVersion:(NSFileVersion *)version;

/* @end */









// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSDate
#define _REWRITER_typedef_NSDate
typedef struct objc_object NSDate;
typedef struct {} _objc_exc_NSDate;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif




typedef NSUInteger NSFileVersionAddingOptions; enum {



    NSFileVersionAddingByMoving = 1 << 0

};

typedef NSUInteger NSFileVersionReplacingOptions; enum {



    NSFileVersionReplacingByMoving = 1 << 0

};



__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSFileVersion
#define _REWRITER_typedef_NSFileVersion
typedef struct objc_object NSFileVersion;
typedef struct {} _objc_exc_NSFileVersion;
#endif

struct NSFileVersion_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSURL *__strong _fileURL;
	__strong id _addition;
	__strong id _deadVersionIdentifier;
	__strong id _nonLocalVersion;
	NSURL *__strong _contentsURL;
	BOOL _isBackup;
	NSString *__strong _localizedName;
	NSString *__strong _localizedComputerName;
	NSDate *__strong _modificationDate;
	BOOL _isResolved;
	BOOL _contentsURLIsAccessed;
	__strong id _reserved;
	NSString *__strong _name;
};




// + (nullable NSFileVersion *)currentVersionOfItemAtURL:(NSURL *)url;



// + (nullable NSArray<NSFileVersion *> *)otherVersionsOfItemAtURL:(NSURL *)url;



// + (nullable NSArray<NSFileVersion *> *)unresolvedConflictVersionsOfItemAtURL:(NSURL *)url;







// + (void)getNonlocalVersionsOfItemAtURL:(NSURL *)url completionHandler:(void (^)(NSArray<NSFileVersion *> * _Nullable nonlocalFileVersions, NSError * _Nullable error))completionHandler __attribute__((availability(ios,introduced=8_0)));



// + (nullable NSFileVersion *)versionOfItemAtURL:(NSURL *)url forPersistentIdentifier:(id)persistentIdentifier;







// + (nullable NSFileVersion *)addVersionOfItemAtURL:(NSURL *)url withContentsOfURL:(NSURL *)contentsURL options:(NSFileVersionAddingOptions)options error:(NSError **)outError __attribute__((availability(ios,unavailable)));



// + (NSURL *)temporaryDirectoryURLForNewVersionOfItemAtURL:(NSURL *)url __attribute__((availability(ios,unavailable)));



// @property (readonly, copy) NSURL *URL;



// @property (nullable, readonly, copy) NSString *localizedName;



// @property (nullable, readonly, copy) NSString *localizedNameOfSavingComputer;



// @property (nullable, readonly, copy) NSDate *modificationDate;



// @property (readonly, retain) id<NSCoding> persistentIdentifier;



// @property (readonly, getter=isConflict) BOOL conflict;







// @property (getter=isResolved) BOOL resolved;
// @property (getter=isDiscardable) BOOL discardable __attribute__((availability(ios,unavailable)));



// @property (readonly) BOOL hasLocalContents __attribute__((availability(ios,introduced=8_0)));



// @property (readonly) BOOL hasThumbnail __attribute__((availability(ios,introduced=8_0)));





// - (nullable NSURL *)replaceItemAtURL:(NSURL *)url options:(NSFileVersionReplacingOptions)options error:(NSError **)error;







// - (BOOL)removeAndReturnError:(NSError **)outError;





// + (BOOL)removeOtherVersionsOfItemAtURL:(NSURL *)url error:(NSError **)outError;

/* @end */








// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif




typedef NSUInteger NSFileWrapperReadingOptions; enum {



    NSFileWrapperReadingImmediate = 1 << 0,



    NSFileWrapperReadingWithoutMapping = 1 << 1

} __attribute__((availability(ios,introduced=4_0)));

typedef NSUInteger NSFileWrapperWritingOptions; enum {



    NSFileWrapperWritingAtomic = 1 << 0,



    NSFileWrapperWritingWithNameUpdating = 1 << 1

} __attribute__((availability(ios,introduced=4_0)));

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=4_0)))

#ifndef _REWRITER_typedef_NSFileWrapper
#define _REWRITER_typedef_NSFileWrapper
typedef struct objc_object NSFileWrapper;
typedef struct {} _objc_exc_NSFileWrapper;
#endif

struct NSFileWrapper_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSDictionary *__strong _fileAttributes;
	NSString *__strong _preferredFileName;
	NSString *__strong _fileName;
	__strong id _contents;
	__strong id _icon;
	__strong id _moreVars;
};






// - (nullable instancetype)initWithURL:(NSURL *)url options:(NSFileWrapperReadingOptions)options error:(NSError **)outError __attribute__((objc_designated_initializer)) __attribute__((availability(ios,introduced=4_0)));



// - (instancetype)initDirectoryWithFileWrappers:(NSDictionary<NSString *, NSFileWrapper *> *)childrenByPreferredName __attribute__((objc_designated_initializer));



// - (instancetype)initRegularFileWithContents:(NSData *)contents __attribute__((objc_designated_initializer));



// - (instancetype)initSymbolicLinkWithDestinationURL:(NSURL *)url __attribute__((objc_designated_initializer)) __attribute__((availability(ios,introduced=4_0)));



// - (nullable instancetype)initWithSerializedRepresentation:(NSData *)serializeRepresentation __attribute__((objc_designated_initializer));

// - (nullable instancetype)initWithCoder:(NSCoder *)inCoder __attribute__((objc_designated_initializer));





// @property (readonly, getter=isDirectory) BOOL directory;
// @property (readonly, getter=isRegularFile) BOOL regularFile;
// @property (readonly, getter=isSymbolicLink) BOOL symbolicLink;





// @property (nullable, copy) NSString *preferredFilename;



// @property (nullable, copy) NSString *filename;



// @property (copy) NSDictionary<NSString *, id> *fileAttributes;
// - (BOOL)matchesContentsOfURL:(NSURL *)url __attribute__((availability(ios,introduced=4_0)));



// - (BOOL)readFromURL:(NSURL *)url options:(NSFileWrapperReadingOptions)options error:(NSError **)outError __attribute__((availability(ios,introduced=4_0)));





// - (BOOL)writeToURL:(NSURL *)url options:(NSFileWrapperWritingOptions)options originalContentsURL:(nullable NSURL *)originalContentsURL error:(NSError **)outError __attribute__((availability(ios,introduced=4_0)));





// @property (nullable, readonly, copy) NSData *serializedRepresentation;







// - (NSString *)addFileWrapper:(NSFileWrapper *)child;



// - (NSString *)addRegularFileWithContents:(NSData *)data preferredFilename:(NSString *)fileName;



// - (void)removeFileWrapper:(NSFileWrapper *)child;



// @property (nullable, readonly, copy) NSDictionary<NSString *, NSFileWrapper *> *fileWrappers;



// - (nullable NSString *)keyForFileWrapper:(NSFileWrapper *)child;







// @property (nullable, readonly, copy) NSData *regularFileContents;







// @property (nullable, readonly, copy) NSURL *symbolicLinkDestinationURL __attribute__((availability(ios,introduced=4_0)));

/* @end */









// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSOrthography
#define _REWRITER_typedef_NSOrthography
typedef struct objc_object NSOrthography;
typedef struct {} _objc_exc_NSOrthography;
#endif

#ifndef _REWRITER_typedef_NSValue
#define _REWRITER_typedef_NSValue
typedef struct objc_object NSValue;
typedef struct {} _objc_exc_NSValue;
#endif








extern "C" NSString *const NSLinguisticTagSchemeTokenType __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagSchemeLexicalClass __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagSchemeNameType __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagSchemeNameTypeOrLexicalClass __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagSchemeLemma __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagSchemeLanguage __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagSchemeScript __attribute__((availability(ios,introduced=5_0)));


extern "C" NSString *const NSLinguisticTagWord __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagPunctuation __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagWhitespace __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagOther __attribute__((availability(ios,introduced=5_0)));


extern "C" NSString *const NSLinguisticTagNoun __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagVerb __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagAdjective __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagAdverb __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagPronoun __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagDeterminer __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagParticle __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagPreposition __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagNumber __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagConjunction __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagInterjection __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagClassifier __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagIdiom __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagOtherWord __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagSentenceTerminator __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagOpenQuote __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagCloseQuote __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagOpenParenthesis __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagCloseParenthesis __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagWordJoiner __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagDash __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagOtherPunctuation __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagParagraphBreak __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagOtherWhitespace __attribute__((availability(ios,introduced=5_0)));


extern "C" NSString *const NSLinguisticTagPersonalName __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagPlaceName __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString *const NSLinguisticTagOrganizationName __attribute__((availability(ios,introduced=5_0)));





typedef NSUInteger NSLinguisticTaggerOptions; enum {
    NSLinguisticTaggerOmitWords = 1 << 0,
    NSLinguisticTaggerOmitPunctuation = 1 << 1,
    NSLinguisticTaggerOmitWhitespace = 1 << 2,
    NSLinguisticTaggerOmitOther = 1 << 3,
    NSLinguisticTaggerJoinNames = 1 << 4
};

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSLinguisticTagger
#define _REWRITER_typedef_NSLinguisticTagger
typedef struct objc_object NSLinguisticTagger;
typedef struct {} _objc_exc_NSLinguisticTagger;
#endif

struct NSLinguisticTagger_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSArray *__strong _schemes;
	NSUInteger _options;
	NSString *__strong _string;
	__strong id _orthographyArray;
	__strong id _tokenArray;
	__strong id _reserved;
};




// - (instancetype)initWithTagSchemes:(NSArray<NSString *> *)tagSchemes options:(NSUInteger)opts __attribute__((objc_designated_initializer)) __attribute__((availability(ios,introduced=5_0)));

// @property (readonly, copy) NSArray<NSString *> *tagSchemes __attribute__((availability(ios,introduced=5_0)));
// @property (nullable, retain) NSString *string __attribute__((availability(ios,introduced=5_0)));



// + (NSArray<NSString *> *)availableTagSchemesForLanguage:(NSString *)language __attribute__((availability(ios,introduced=5_0)));



// - (void)setOrthography:(nullable NSOrthography *)orthography range:(NSRange)range __attribute__((availability(ios,introduced=5_0)));
// - (nullable NSOrthography *)orthographyAtIndex:(NSUInteger)charIndex effectiveRange:(nullable NSRangePointer)effectiveRange __attribute__((availability(ios,introduced=5_0)));



// - (void)stringEditedInRange:(NSRange)newRange changeInLength:(NSInteger)delta __attribute__((availability(ios,introduced=5_0)));



// - (void)enumerateTagsInRange:(NSRange)range scheme:(NSString *)tagScheme options:(NSLinguisticTaggerOptions)opts usingBlock:(void (^)(NSString *tag, NSRange tokenRange, NSRange sentenceRange, BOOL *stop))block __attribute__((availability(ios,introduced=5_0)));

// - (NSRange)sentenceRangeForRange:(NSRange)range __attribute__((availability(ios,introduced=5_0)));
// - (nullable NSString *)tagAtIndex:(NSUInteger)charIndex scheme:(NSString *)tagScheme tokenRange:(nullable NSRangePointer)tokenRange sentenceRange:(nullable NSRangePointer)sentenceRange __attribute__((availability(ios,introduced=5_0)));
// - (NSArray<NSString *> *)tagsInRange:(NSRange)range scheme:(NSString *)tagScheme options:(NSLinguisticTaggerOptions)opts tokenRanges:(NSArray<NSValue *> * _Nullable * _Nullable)tokenRanges __attribute__((availability(ios,introduced=5_0)));
// - (nullable NSArray<NSString *> *)possibleTagsAtIndex:(NSUInteger)charIndex scheme:(NSString *)tagScheme tokenRange:(nullable NSRangePointer)tokenRange sentenceRange:(nullable NSRangePointer)sentenceRange scores:(NSArray<NSValue *> * _Nullable * _Nullable)scores __attribute__((availability(ios,introduced=5_0)));

/* @end */


// @interface NSString (NSLinguisticAnalysis)



// - (NSArray<NSString *> *)linguisticTagsInRange:(NSRange)range scheme:(NSString *)tagScheme options:(NSLinguisticTaggerOptions)opts orthography:(nullable NSOrthography *)orthography tokenRanges:(NSArray<NSValue *> * _Nullable * _Nullable)tokenRanges __attribute__((availability(ios,introduced=5_0)));
// - (void)enumerateLinguisticTagsInRange:(NSRange)range scheme:(NSString *)tagScheme options:(NSLinguisticTaggerOptions)opts orthography:(nullable NSOrthography *)orthography usingBlock:(void (^)(NSString *tag, NSRange tokenRange, NSRange sentenceRange, BOOL *stop))block __attribute__((availability(ios,introduced=5_0)));

/* @end */











// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif






extern "C" NSString * const NSMetadataItemFSNameKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataItemDisplayNameKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataItemURLKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataItemPathKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataItemFSSizeKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataItemFSCreationDateKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataItemFSContentChangeDateKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataItemContentTypeKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSMetadataItemContentTypeTreeKey __attribute__((availability(ios,introduced=8_0)));

extern "C" NSString * const NSMetadataItemIsUbiquitousKey __attribute__((availability(ios,introduced=5_0)));

extern "C" NSString * const NSMetadataUbiquitousItemHasUnresolvedConflictsKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataUbiquitousItemIsDownloadedKey __attribute__((availability(ios,introduced=5_0,deprecated=7_0,message="" "Use NSMetadataUbiquitousItemDownloadingStatusKey instead")));
extern "C" NSString * const NSMetadataUbiquitousItemDownloadingStatusKey __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSMetadataUbiquitousItemDownloadingStatusNotDownloaded __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSMetadataUbiquitousItemDownloadingStatusDownloaded __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSMetadataUbiquitousItemDownloadingStatusCurrent __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSMetadataUbiquitousItemIsDownloadingKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataUbiquitousItemIsUploadedKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataUbiquitousItemIsUploadingKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataUbiquitousItemPercentDownloadedKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataUbiquitousItemPercentUploadedKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataUbiquitousItemDownloadingErrorKey __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSMetadataUbiquitousItemUploadingErrorKey __attribute__((availability(ios,introduced=7_0)));
extern "C" NSString * const NSMetadataUbiquitousItemDownloadRequestedKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSMetadataUbiquitousItemIsExternalDocumentKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSMetadataUbiquitousItemContainerDisplayNameKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSMetadataUbiquitousItemURLInLocalContainerKey __attribute__((availability(ios,introduced=8_0)));



extern "C" NSString * const NSMetadataItemAttributeChangeDateKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemKeywordsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemTitleKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAuthorsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemEditorsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemParticipantsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemProjectsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemDownloadedDateKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemWhereFromsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemCommentKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemCopyrightKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemLastUsedDateKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemContentCreationDateKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemContentModificationDateKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemDateAddedKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemDurationSecondsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemContactKeywordsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemVersionKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemPixelHeightKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemPixelWidthKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemPixelCountKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemColorSpaceKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemBitsPerSampleKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemFlashOnOffKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemFocalLengthKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAcquisitionMakeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAcquisitionModelKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemISOSpeedKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemOrientationKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemLayerNamesKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemWhiteBalanceKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemApertureKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemProfileNameKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemResolutionWidthDPIKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemResolutionHeightDPIKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemExposureModeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemExposureTimeSecondsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemEXIFVersionKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemCameraOwnerKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemFocalLength35mmKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemLensModelKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemEXIFGPSVersionKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAltitudeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemLatitudeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemLongitudeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemSpeedKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemTimestampKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSTrackKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemImageDirectionKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemNamedLocationKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemGPSStatusKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSMeasureModeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSDOPKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSMapDatumKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSDestLatitudeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSDestLongitudeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSDestBearingKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSDestDistanceKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSProcessingMethodKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSAreaInformationKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSDateStampKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGPSDifferentalKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemCodecsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemMediaTypesKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemStreamableKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemTotalBitRateKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemVideoBitRateKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAudioBitRateKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemDeliveryTypeKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemAlbumKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemHasAlphaChannelKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemRedEyeOnOffKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemMeteringModeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemMaxApertureKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemFNumberKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemExposureProgramKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemExposureTimeStringKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemHeadlineKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemInstructionsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemCityKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemStateOrProvinceKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemCountryKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemTextContentKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemAudioSampleRateKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAudioChannelCountKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemTempoKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemKeySignatureKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemTimeSignatureKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAudioEncodingApplicationKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemComposerKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemLyricistKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAudioTrackNumberKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemRecordingDateKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemMusicalGenreKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemIsGeneralMIDISequenceKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemRecordingYearKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemOrganizationsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemLanguagesKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemRightsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemPublishersKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemContributorsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemCoverageKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemSubjectKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemThemeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemDescriptionKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemIdentifierKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAudiencesKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemNumberOfPagesKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemPageWidthKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemPageHeightKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemSecurityMethodKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemCreatorKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemEncodingApplicationsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemDueDateKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemStarRatingKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemPhoneNumbersKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemEmailAddressesKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemInstantMessageAddressesKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemKindKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemRecipientsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemFinderCommentKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemFontsKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemAppleLoopsRootKeyKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAppleLoopsKeyFilterTypeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAppleLoopsLoopModeKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAppleLoopDescriptorsKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemMusicalInstrumentCategoryKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemMusicalInstrumentNameKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemCFBundleIdentifierKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemInformationKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemDirectorKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemProducerKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemGenreKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemPerformersKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemOriginalFormatKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemOriginalSourceKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAuthorEmailAddressesKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemRecipientEmailAddressesKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemAuthorAddressesKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemRecipientAddressesKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemIsLikelyJunkKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemExecutableArchitecturesKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemExecutablePlatformKey __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataItemApplicationCategoriesKey __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataItemIsApplicationManagedKey __attribute__((availability(ios,unavailable)));




// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSPredicate
#define _REWRITER_typedef_NSPredicate
typedef struct objc_object NSPredicate;
typedef struct {} _objc_exc_NSPredicate;
#endif

#ifndef _REWRITER_typedef_NSOperationQueue
#define _REWRITER_typedef_NSOperationQueue
typedef struct objc_object NSOperationQueue;
typedef struct {} _objc_exc_NSOperationQueue;
#endif

#ifndef _REWRITER_typedef_NSSortDescriptor
#define _REWRITER_typedef_NSSortDescriptor
typedef struct objc_object NSSortDescriptor;
typedef struct {} _objc_exc_NSSortDescriptor;
#endif

// @class NSMetadataItem;
#ifndef _REWRITER_typedef_NSMetadataItem
#define _REWRITER_typedef_NSMetadataItem
typedef struct objc_object NSMetadataItem;
typedef struct {} _objc_exc_NSMetadataItem;
#endif

#ifndef _REWRITER_typedef_NSMetadataQueryAttributeValueTuple
#define _REWRITER_typedef_NSMetadataQueryAttributeValueTuple
typedef struct objc_object NSMetadataQueryAttributeValueTuple;
typedef struct {} _objc_exc_NSMetadataQueryAttributeValueTuple;
#endif

#ifndef _REWRITER_typedef_NSMetadataQueryResultGroup
#define _REWRITER_typedef_NSMetadataQueryResultGroup
typedef struct objc_object NSMetadataQueryResultGroup;
typedef struct {} _objc_exc_NSMetadataQueryResultGroup;
#endif

// @protocol NSMetadataQueryDelegate;



__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSMetadataQuery
#define _REWRITER_typedef_NSMetadataQuery
typedef struct objc_object NSMetadataQuery;
typedef struct {} _objc_exc_NSMetadataQuery;
#endif

struct NSMetadataQuery_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	NSUInteger _flags;
	NSTimeInterval _interval;
	id __strong _private[11];
	void *_reserved;
};


// @property (nullable, assign) id<NSMetadataQueryDelegate> delegate;
// @property (nullable, copy) NSPredicate *predicate;
// @property (copy) NSArray<NSSortDescriptor *> *sortDescriptors;
// @property (copy) NSArray<NSString *> *valueListAttributes;
// @property (nullable, copy) NSArray<NSString *> *groupingAttributes;
// @property NSTimeInterval notificationBatchingInterval;

// @property (copy) NSArray *searchScopes;





// @property (nullable, copy) NSArray *searchItems __attribute__((availability(ios,introduced=7_0)));



// @property (nullable, retain) NSOperationQueue *operationQueue __attribute__((availability(ios,introduced=7_0)));


// - (BOOL)startQuery;
// - (void)stopQuery;

// @property (readonly, getter=isStarted) BOOL started;
// @property (readonly, getter=isGathering) BOOL gathering;
// @property (readonly, getter=isStopped) BOOL stopped;

// - (void)disableUpdates;
// - (void)enableUpdates;



// @property (readonly) NSUInteger resultCount;
// - (id)resultAtIndex:(NSUInteger)idx;

// - (void)enumerateResultsUsingBlock:(void (^)(id result, NSUInteger idx, BOOL *stop))block __attribute__((availability(ios,introduced=7_0)));
// - (void)enumerateResultsWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(id result, NSUInteger idx, BOOL *stop))block __attribute__((availability(ios,introduced=7_0)));

// @property (readonly, copy) NSArray *results;

// - (NSUInteger)indexOfResult:(id)result;

// @property (readonly, copy) NSDictionary<NSString *, NSArray<NSMetadataQueryAttributeValueTuple *> *> *valueLists;

// @property (readonly, copy) NSArray<NSMetadataQueryResultGroup *> *groupedResults;

// - (nullable id)valueOfAttribute:(NSString *)attrName forResultAtIndex:(NSUInteger)idx;

/* @end */


// @protocol NSMetadataQueryDelegate <NSObject>
/* @optional */

// - (id)metadataQuery:(NSMetadataQuery *)query replacementObjectForResultObject:(NSMetadataItem *)result;
// - (id)metadataQuery:(NSMetadataQuery *)query replacementValueForAttribute:(NSString *)attrName value:(id)attrValue;

/* @end */



extern "C" NSString * const NSMetadataQueryDidStartGatheringNotification __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataQueryGatheringProgressNotification __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataQueryDidFinishGatheringNotification __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataQueryDidUpdateNotification __attribute__((availability(ios,introduced=5_0)));


extern "C" NSString * const NSMetadataQueryUpdateAddedItemsKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSMetadataQueryUpdateChangedItemsKey __attribute__((availability(ios,introduced=8_0)));
extern "C" NSString * const NSMetadataQueryUpdateRemovedItemsKey __attribute__((availability(ios,introduced=8_0)));

extern "C" NSString * const NSMetadataQueryResultContentRelevanceAttribute __attribute__((availability(ios,introduced=5_0)));


extern "C" NSString * const NSMetadataQueryUserHomeScope __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataQueryLocalComputerScope __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataQueryNetworkScope __attribute__((availability(ios,unavailable)));

extern "C" NSString * const NSMetadataQueryIndexedLocalComputerScope __attribute__((availability(ios,unavailable)));
extern "C" NSString * const NSMetadataQueryIndexedNetworkScope __attribute__((availability(ios,unavailable)));


extern "C" NSString * const NSMetadataQueryUbiquitousDocumentsScope __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataQueryUbiquitousDataScope __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSMetadataQueryAccessibleUbiquitousExternalDocumentsScope __attribute__((availability(ios,introduced=8_0)));


__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSMetadataItem
#define _REWRITER_typedef_NSMetadataItem
typedef struct objc_object NSMetadataItem;
typedef struct {} _objc_exc_NSMetadataItem;
#endif

struct NSMetadataItem_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _item;
	void *_reserved;
};


// - (nullable instancetype)initWithURL:(NSURL *)url __attribute__((objc_designated_initializer)) __attribute__((availability(ios,unavailable)));

// - (nullable id)valueForAttribute:(NSString *)key;
// - (nullable NSDictionary<NSString *, id> *)valuesForAttributes:(NSArray<NSString *> *)keys;

// @property (readonly, copy) NSArray<NSString *> *attributes;

/* @end */


__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSMetadataQueryAttributeValueTuple
#define _REWRITER_typedef_NSMetadataQueryAttributeValueTuple
typedef struct objc_object NSMetadataQueryAttributeValueTuple;
typedef struct {} _objc_exc_NSMetadataQueryAttributeValueTuple;
#endif

struct NSMetadataQueryAttributeValueTuple_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _attr;
	__strong id _value;
	NSUInteger _count;
	void *_reserved;
};


// @property (readonly, copy) NSString *attribute;
// @property (nullable, readonly, retain) id value;
// @property (readonly) NSUInteger count;

/* @end */


__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSMetadataQueryResultGroup
#define _REWRITER_typedef_NSMetadataQueryResultGroup
typedef struct objc_object NSMetadataQueryResultGroup;
typedef struct {} _objc_exc_NSMetadataQueryResultGroup;
#endif

struct NSMetadataQueryResultGroup_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	id __strong _private[9];
	NSUInteger _private2[1];
	void *_reserved;
};


// @property (readonly, copy) NSString *attribute;
// @property (readonly, retain) id value;

// @property (nullable, readonly, copy) NSArray<NSMetadataQueryResultGroup *> *subgroups;

// @property (readonly) NSUInteger resultCount;
// - (id)resultAtIndex:(NSUInteger)idx;

// @property (readonly, copy) NSArray *results;

/* @end */









// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSInputStream
#define _REWRITER_typedef_NSInputStream
typedef struct objc_object NSInputStream;
typedef struct {} _objc_exc_NSInputStream;
#endif

#ifndef _REWRITER_typedef_NSNumber
#define _REWRITER_typedef_NSNumber
typedef struct objc_object NSNumber;
typedef struct {} _objc_exc_NSNumber;
#endif

#ifndef _REWRITER_typedef_NSOutputStream
#define _REWRITER_typedef_NSOutputStream
typedef struct objc_object NSOutputStream;
typedef struct {} _objc_exc_NSOutputStream;
#endif

#ifndef _REWRITER_typedef_NSRunLoop
#define _REWRITER_typedef_NSRunLoop
typedef struct objc_object NSRunLoop;
typedef struct {} _objc_exc_NSRunLoop;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @protocol NSNetServiceDelegate, NSNetServiceBrowserDelegate;





extern "C" NSString * const NSNetServicesErrorCode;
extern "C" NSString * const NSNetServicesErrorDomain;

typedef NSInteger NSNetServicesError; enum {



    NSNetServicesUnknownError = -72000L,



    NSNetServicesCollisionError = -72001L,



    NSNetServicesNotFoundError = -72002L,



    NSNetServicesActivityInProgress = -72003L,



    NSNetServicesBadArgumentError = -72004L,



    NSNetServicesCancelledError = -72005L,



    NSNetServicesInvalidError = -72006L,



    NSNetServicesTimeoutError = -72007L,

};


typedef NSUInteger NSNetServiceOptions; enum {




    NSNetServiceNoAutoRename = 1UL << 0,
    NSNetServiceListenForConnections __attribute__((availability(ios,introduced=7_0))) = 1UL << 1
};





__attribute__((availability(watchos,unavailable)))

#ifndef _REWRITER_typedef_NSNetService
#define _REWRITER_typedef_NSNetService
typedef struct objc_object NSNetService;
typedef struct {} _objc_exc_NSNetService;
#endif

struct NSNetService_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _netService;
	__strong id _delegate;
	__strong id _reserved;
};




// - (instancetype)initWithDomain:(NSString *)domain type:(NSString *)type name:(NSString *)name port:(int)port __attribute__((objc_designated_initializer));





// - (instancetype)initWithDomain:(NSString *)domain type:(NSString *)type name:(NSString *)name;



// - (void)scheduleInRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;
// - (void)removeFromRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;



// @property (nullable, assign) id <NSNetServiceDelegate> delegate;



// @property BOOL includesPeerToPeer __attribute__((availability(ios,introduced=7_0)));



// @property (readonly, copy) NSString *name;



// @property (readonly, copy) NSString *type;



// @property (readonly, copy) NSString *domain;



// @property (nullable, readonly, copy) NSString *hostName;



// @property (nullable, readonly, copy) NSArray<NSData *> *addresses;



// @property (readonly) NSInteger port __attribute__((availability(ios,introduced=2_0)));





// - (void)publish;





// - (void)publishWithOptions:(NSNetServiceOptions)options __attribute__((availability(ios,introduced=2_0)));




// - (void)resolve __attribute__((availability(ios,introduced=2_0,deprecated=2_0,message="" )));



// - (void)stop;



// + (NSDictionary<NSString *, NSData *> *)dictionaryFromTXTRecordData:(NSData *)txtData;



// + (NSData *)dataFromTXTRecordDictionary:(NSDictionary<NSString *, NSData *> *)txtDictionary;



// - (void)resolveWithTimeout:(NSTimeInterval)timeout;



// - (BOOL)getInputStream:(out __attribute__((objc_ownership(strong))) NSInputStream * _Nullable * _Nullable)inputStream outputStream:(out __attribute__((objc_ownership(strong))) NSOutputStream * _Nullable * _Nullable)outputStream;



// - (BOOL)setTXTRecordData:(nullable NSData *)recordData;



// - (nullable NSData *)TXTRecordData;



// - (void)startMonitoring;



// - (void)stopMonitoring;


/* @end */




__attribute__((availability(watchos,unavailable)))

#ifndef _REWRITER_typedef_NSNetServiceBrowser
#define _REWRITER_typedef_NSNetServiceBrowser
typedef struct objc_object NSNetServiceBrowser;
typedef struct {} _objc_exc_NSNetServiceBrowser;
#endif

struct NSNetServiceBrowser_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _netServiceBrowser;
	__strong id _delegate;
	void *_reserved;
};


// - (instancetype)init;



// @property (nullable, assign) id <NSNetServiceBrowserDelegate> delegate;



// @property BOOL includesPeerToPeer __attribute__((availability(ios,introduced=7_0)));



// - (void)scheduleInRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;
// - (void)removeFromRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;



// - (void)searchForBrowsableDomains;



// - (void)searchForRegistrationDomains;



// - (void)searchForServicesOfType:(NSString *)type inDomain:(NSString *)domainString;



// - (void)stop;

/* @end */




__attribute__((availability(watchos,unavailable)))
// @protocol NSNetServiceDelegate <NSObject>
/* @optional */



// - (void)netServiceWillPublish:(NSNetService *)sender;



// - (void)netServiceDidPublish:(NSNetService *)sender;



// - (void)netService:(NSNetService *)sender didNotPublish:(NSDictionary<NSString *, NSNumber *> *)errorDict;



// - (void)netServiceWillResolve:(NSNetService *)sender;



// - (void)netServiceDidResolveAddress:(NSNetService *)sender;



// - (void)netService:(NSNetService *)sender didNotResolve:(NSDictionary<NSString *, NSNumber *> *)errorDict;



// - (void)netServiceDidStop:(NSNetService *)sender;



// - (void)netService:(NSNetService *)sender didUpdateTXTRecordData:(NSData *)data;
// - (void)netService:(NSNetService *)sender didAcceptConnectionWithInputStream:(NSInputStream *)inputStream outputStream:(NSOutputStream *)outputStream __attribute__((availability(ios,introduced=7_0)));

/* @end */




__attribute__((availability(watchos,unavailable)))
// @protocol NSNetServiceBrowserDelegate <NSObject>
/* @optional */



// - (void)netServiceBrowserWillSearch:(NSNetServiceBrowser *)browser;



// - (void)netServiceBrowserDidStopSearch:(NSNetServiceBrowser *)browser;



// - (void)netServiceBrowser:(NSNetServiceBrowser *)browser didNotSearch:(NSDictionary<NSString *, NSNumber *> *)errorDict;



// - (void)netServiceBrowser:(NSNetServiceBrowser *)browser didFindDomain:(NSString *)domainString moreComing:(BOOL)moreComing;



// - (void)netServiceBrowser:(NSNetServiceBrowser *)browser didFindService:(NSNetService *)service moreComing:(BOOL)moreComing;



// - (void)netServiceBrowser:(NSNetServiceBrowser *)browser didRemoveDomain:(NSString *)domainString moreComing:(BOOL)moreComing;



// - (void)netServiceBrowser:(NSNetServiceBrowser *)browser didRemoveService:(NSNetService *)service moreComing:(BOOL)moreComing;

/* @end */









// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif




__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=5_0)))

#ifndef _REWRITER_typedef_NSUbiquitousKeyValueStore
#define _REWRITER_typedef_NSUbiquitousKeyValueStore
typedef struct objc_object NSUbiquitousKeyValueStore;
typedef struct {} _objc_exc_NSUbiquitousKeyValueStore;
#endif

struct NSUbiquitousKeyValueStore_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _private1;
	__strong id _private2;
	__strong id _private3;
	void *_private4;
	void *_reserved[3];
	int _daemonWakeToken;
};


// + (NSUbiquitousKeyValueStore *)defaultStore;

// - (nullable id)objectForKey:(NSString *)aKey;
// - (void)setObject:(nullable id)anObject forKey:(NSString *)aKey;
// - (void)removeObjectForKey:(NSString *)aKey;

// - (nullable NSString *)stringForKey:(NSString *)aKey;
// - (nullable NSArray *)arrayForKey:(NSString *)aKey;
// - (nullable NSDictionary<NSString *, id> *)dictionaryForKey:(NSString *)aKey;
// - (nullable NSData *)dataForKey:(NSString *)aKey;
// - (long long)longLongForKey:(NSString *)aKey;
// - (double)doubleForKey:(NSString *)aKey;
// - (BOOL)boolForKey:(NSString *)aKey;

// - (void)setString:(nullable NSString *)aString forKey:(NSString *)aKey;
// - (void)setData:(nullable NSData *)aData forKey:(NSString *)aKey;
// - (void)setArray:(nullable NSArray *)anArray forKey:(NSString *)aKey;
// - (void)setDictionary:(nullable NSDictionary<NSString *, id> *)aDictionary forKey:(NSString *)aKey;
// - (void)setLongLong:(long long)value forKey:(NSString *)aKey;
// - (void)setDouble:(double)value forKey:(NSString *)aKey;
// - (void)setBool:(BOOL)value forKey:(NSString *)aKey;

// @property (readonly, copy) NSDictionary<NSString *, id> *dictionaryRepresentation;

// - (BOOL)synchronize;

/* @end */


extern "C" NSString * const NSUbiquitousKeyValueStoreDidChangeExternallyNotification __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSUbiquitousKeyValueStoreChangeReasonKey __attribute__((availability(ios,introduced=5_0)));
extern "C" NSString * const NSUbiquitousKeyValueStoreChangedKeysKey __attribute__((availability(ios,introduced=5_0)));

enum {
    NSUbiquitousKeyValueStoreServerChange __attribute__((availability(ios,introduced=5_0))),
    NSUbiquitousKeyValueStoreInitialSyncChange __attribute__((availability(ios,introduced=5_0))),
    NSUbiquitousKeyValueStoreQuotaViolationChange __attribute__((availability(ios,introduced=5_0))),
    NSUbiquitousKeyValueStoreAccountChange __attribute__((availability(ios,introduced=6_0)))
};
// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif





static const NSUInteger NSUndoCloseGroupingRunLoopOrdering = 350000;

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=3_0)))

#ifndef _REWRITER_typedef_NSUndoManager
#define _REWRITER_typedef_NSUndoManager
typedef struct objc_object NSUndoManager;
typedef struct {} _objc_exc_NSUndoManager;
#endif

struct NSUndoManager_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
	__strong id _undoStack;
	__strong id _redoStack;
	NSArray *__strong _runLoopModes;
	uint64_t _NSUndoManagerPrivate1;
	__strong id _target;
	__strong id _proxy;
	void *_NSUndoManagerPrivate2;
	void *_NSUndoManagerPrivate3;
};




// - (void)beginUndoGrouping;
// - (void)endUndoGrouping;


// @property (readonly) NSInteger groupingLevel;




// - (void)disableUndoRegistration;
// - (void)enableUndoRegistration;
// @property (readonly, getter=isUndoRegistrationEnabled) BOOL undoRegistrationEnabled;



// @property BOOL groupsByEvent;






// @property NSUInteger levelsOfUndo;






// @property (copy) NSArray<NSString *> *runLoopModes;



// - (void)undo;



// - (void)redo;


// - (void)undoNestedGroup;



// @property (readonly) BOOL canUndo;
// @property (readonly) BOOL canRedo;


// @property (readonly, getter=isUndoing) BOOL undoing;
// @property (readonly, getter=isRedoing) BOOL redoing;





// - (void)removeAllActions;

// - (void)removeAllActionsWithTarget:(id)target;



// - (void)registerUndoWithTarget:(id)target selector:(SEL)selector object:(nullable id)anObject;



// - (id)prepareWithInvocationTarget:(id)target;
// - (void)registerUndoWithTarget:(id)target handler:(void (^)(id target))undoHandler __attribute__((availability(ios,introduced=9_0))) __attribute__((swift_private));

// - (void)setActionIsDiscardable:(BOOL)discardable __attribute__((availability(ios,introduced=5_0)));



extern "C" NSString * const NSUndoManagerGroupIsDiscardableKey __attribute__((availability(ios,introduced=5_0)));

// @property (readonly) BOOL undoActionIsDiscardable __attribute__((availability(ios,introduced=5_0)));
// @property (readonly) BOOL redoActionIsDiscardable __attribute__((availability(ios,introduced=5_0)));




// @property (readonly, copy) NSString *undoActionName;
// @property (readonly, copy) NSString *redoActionName;



// - (void)setActionName:(NSString *)actionName;





// @property (readonly, copy) NSString *undoMenuItemTitle;
// @property (readonly, copy) NSString *redoMenuItemTitle;






// - (NSString *)undoMenuTitleForUndoActionName:(NSString *)actionName;
// - (NSString *)redoMenuTitleForUndoActionName:(NSString *)actionName;




/* @end */


extern "C" NSString * const NSUndoManagerCheckpointNotification __attribute__((availability(ios,introduced=3_0)));




extern "C" NSString * const NSUndoManagerWillUndoChangeNotification __attribute__((availability(ios,introduced=3_0)));
extern "C" NSString * const NSUndoManagerWillRedoChangeNotification __attribute__((availability(ios,introduced=3_0)));

extern "C" NSString * const NSUndoManagerDidUndoChangeNotification __attribute__((availability(ios,introduced=3_0)));
extern "C" NSString * const NSUndoManagerDidRedoChangeNotification __attribute__((availability(ios,introduced=3_0)));

extern "C" NSString * const NSUndoManagerDidOpenUndoGroupNotification __attribute__((availability(ios,introduced=3_0)));
extern "C" NSString * const NSUndoManagerWillCloseUndoGroupNotification __attribute__((availability(ios,introduced=3_0)));


extern "C" NSString * const NSUndoManagerDidCloseUndoGroupNotification __attribute__((availability(ios,introduced=5_0)));








typedef uint16_t SSLCipherSuite;


enum
{ SSL_NULL_WITH_NULL_NULL = 0x0000,
    SSL_RSA_WITH_NULL_MD5 = 0x0001,
    SSL_RSA_WITH_NULL_SHA = 0x0002,
    SSL_RSA_EXPORT_WITH_RC4_40_MD5 = 0x0003,
    SSL_RSA_WITH_RC4_128_MD5 = 0x0004,
    SSL_RSA_WITH_RC4_128_SHA = 0x0005,
    SSL_RSA_EXPORT_WITH_RC2_CBC_40_MD5 = 0x0006,
    SSL_RSA_WITH_IDEA_CBC_SHA = 0x0007,
    SSL_RSA_EXPORT_WITH_DES40_CBC_SHA = 0x0008,
    SSL_RSA_WITH_DES_CBC_SHA = 0x0009,
    SSL_RSA_WITH_3DES_EDE_CBC_SHA = 0x000A,
    SSL_DH_DSS_EXPORT_WITH_DES40_CBC_SHA = 0x000B,
    SSL_DH_DSS_WITH_DES_CBC_SHA = 0x000C,
    SSL_DH_DSS_WITH_3DES_EDE_CBC_SHA = 0x000D,
    SSL_DH_RSA_EXPORT_WITH_DES40_CBC_SHA = 0x000E,
    SSL_DH_RSA_WITH_DES_CBC_SHA = 0x000F,
    SSL_DH_RSA_WITH_3DES_EDE_CBC_SHA = 0x0010,
    SSL_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA = 0x0011,
    SSL_DHE_DSS_WITH_DES_CBC_SHA = 0x0012,
    SSL_DHE_DSS_WITH_3DES_EDE_CBC_SHA = 0x0013,
    SSL_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA = 0x0014,
    SSL_DHE_RSA_WITH_DES_CBC_SHA = 0x0015,
    SSL_DHE_RSA_WITH_3DES_EDE_CBC_SHA = 0x0016,
    SSL_DH_anon_EXPORT_WITH_RC4_40_MD5 = 0x0017,
    SSL_DH_anon_WITH_RC4_128_MD5 = 0x0018,
    SSL_DH_anon_EXPORT_WITH_DES40_CBC_SHA = 0x0019,
    SSL_DH_anon_WITH_DES_CBC_SHA = 0x001A,
    SSL_DH_anon_WITH_3DES_EDE_CBC_SHA = 0x001B,
    SSL_FORTEZZA_DMS_WITH_NULL_SHA = 0x001C,
    SSL_FORTEZZA_DMS_WITH_FORTEZZA_CBC_SHA = 0x001D,


 TLS_RSA_WITH_AES_128_CBC_SHA = 0x002F,
 TLS_DH_DSS_WITH_AES_128_CBC_SHA = 0x0030,
 TLS_DH_RSA_WITH_AES_128_CBC_SHA = 0x0031,
 TLS_DHE_DSS_WITH_AES_128_CBC_SHA = 0x0032,
 TLS_DHE_RSA_WITH_AES_128_CBC_SHA = 0x0033,
 TLS_DH_anon_WITH_AES_128_CBC_SHA = 0x0034,
 TLS_RSA_WITH_AES_256_CBC_SHA = 0x0035,
 TLS_DH_DSS_WITH_AES_256_CBC_SHA = 0x0036,
 TLS_DH_RSA_WITH_AES_256_CBC_SHA = 0x0037,
 TLS_DHE_DSS_WITH_AES_256_CBC_SHA = 0x0038,
 TLS_DHE_RSA_WITH_AES_256_CBC_SHA = 0x0039,
 TLS_DH_anon_WITH_AES_256_CBC_SHA = 0x003A,


 TLS_ECDH_ECDSA_WITH_NULL_SHA = 0xC001,
 TLS_ECDH_ECDSA_WITH_RC4_128_SHA = 0xC002,
 TLS_ECDH_ECDSA_WITH_3DES_EDE_CBC_SHA = 0xC003,
 TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA = 0xC004,
 TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA = 0xC005,
 TLS_ECDHE_ECDSA_WITH_NULL_SHA = 0xC006,
 TLS_ECDHE_ECDSA_WITH_RC4_128_SHA = 0xC007,
 TLS_ECDHE_ECDSA_WITH_3DES_EDE_CBC_SHA = 0xC008,
 TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA = 0xC009,
 TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA = 0xC00A,
 TLS_ECDH_RSA_WITH_NULL_SHA = 0xC00B,
 TLS_ECDH_RSA_WITH_RC4_128_SHA = 0xC00C,
 TLS_ECDH_RSA_WITH_3DES_EDE_CBC_SHA = 0xC00D,
 TLS_ECDH_RSA_WITH_AES_128_CBC_SHA = 0xC00E,
 TLS_ECDH_RSA_WITH_AES_256_CBC_SHA = 0xC00F,
 TLS_ECDHE_RSA_WITH_NULL_SHA = 0xC010,
 TLS_ECDHE_RSA_WITH_RC4_128_SHA = 0xC011,
 TLS_ECDHE_RSA_WITH_3DES_EDE_CBC_SHA = 0xC012,
 TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA = 0xC013,
 TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA = 0xC014,
 TLS_ECDH_anon_WITH_NULL_SHA = 0xC015,
 TLS_ECDH_anon_WITH_RC4_128_SHA = 0xC016,
 TLS_ECDH_anon_WITH_3DES_EDE_CBC_SHA = 0xC017,
 TLS_ECDH_anon_WITH_AES_128_CBC_SHA = 0xC018,
 TLS_ECDH_anon_WITH_AES_256_CBC_SHA = 0xC019,




    TLS_NULL_WITH_NULL_NULL = 0x0000,


    TLS_RSA_WITH_NULL_MD5 = 0x0001,
    TLS_RSA_WITH_NULL_SHA = 0x0002,
    TLS_RSA_WITH_RC4_128_MD5 = 0x0004,
    TLS_RSA_WITH_RC4_128_SHA = 0x0005,
    TLS_RSA_WITH_3DES_EDE_CBC_SHA = 0x000A,


    TLS_RSA_WITH_NULL_SHA256 = 0x003B,
    TLS_RSA_WITH_AES_128_CBC_SHA256 = 0x003C,
    TLS_RSA_WITH_AES_256_CBC_SHA256 = 0x003D,


    TLS_DH_DSS_WITH_3DES_EDE_CBC_SHA = 0x000D,
    TLS_DH_RSA_WITH_3DES_EDE_CBC_SHA = 0x0010,
    TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA = 0x0013,
    TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA = 0x0016,
    TLS_DH_DSS_WITH_AES_128_CBC_SHA256 = 0x003E,
    TLS_DH_RSA_WITH_AES_128_CBC_SHA256 = 0x003F,
    TLS_DHE_DSS_WITH_AES_128_CBC_SHA256 = 0x0040,
    TLS_DHE_RSA_WITH_AES_128_CBC_SHA256 = 0x0067,
    TLS_DH_DSS_WITH_AES_256_CBC_SHA256 = 0x0068,
    TLS_DH_RSA_WITH_AES_256_CBC_SHA256 = 0x0069,
    TLS_DHE_DSS_WITH_AES_256_CBC_SHA256 = 0x006A,
    TLS_DHE_RSA_WITH_AES_256_CBC_SHA256 = 0x006B,


    TLS_DH_anon_WITH_RC4_128_MD5 = 0x0018,
    TLS_DH_anon_WITH_3DES_EDE_CBC_SHA = 0x001B,


    TLS_DH_anon_WITH_AES_128_CBC_SHA256 = 0x006C,
    TLS_DH_anon_WITH_AES_256_CBC_SHA256 = 0x006D,



    TLS_PSK_WITH_RC4_128_SHA = 0x008A,
    TLS_PSK_WITH_3DES_EDE_CBC_SHA = 0x008B,
    TLS_PSK_WITH_AES_128_CBC_SHA = 0x008C,
    TLS_PSK_WITH_AES_256_CBC_SHA = 0x008D,
    TLS_DHE_PSK_WITH_RC4_128_SHA = 0x008E,
    TLS_DHE_PSK_WITH_3DES_EDE_CBC_SHA = 0x008F,
    TLS_DHE_PSK_WITH_AES_128_CBC_SHA = 0x0090,
    TLS_DHE_PSK_WITH_AES_256_CBC_SHA = 0x0091,
    TLS_RSA_PSK_WITH_RC4_128_SHA = 0x0092,
    TLS_RSA_PSK_WITH_3DES_EDE_CBC_SHA = 0x0093,
    TLS_RSA_PSK_WITH_AES_128_CBC_SHA = 0x0094,
    TLS_RSA_PSK_WITH_AES_256_CBC_SHA = 0x0095,



    TLS_PSK_WITH_NULL_SHA = 0x002C,
    TLS_DHE_PSK_WITH_NULL_SHA = 0x002D,
    TLS_RSA_PSK_WITH_NULL_SHA = 0x002E,



    TLS_RSA_WITH_AES_128_GCM_SHA256 = 0x009C,
    TLS_RSA_WITH_AES_256_GCM_SHA384 = 0x009D,
    TLS_DHE_RSA_WITH_AES_128_GCM_SHA256 = 0x009E,
    TLS_DHE_RSA_WITH_AES_256_GCM_SHA384 = 0x009F,
    TLS_DH_RSA_WITH_AES_128_GCM_SHA256 = 0x00A0,
    TLS_DH_RSA_WITH_AES_256_GCM_SHA384 = 0x00A1,
    TLS_DHE_DSS_WITH_AES_128_GCM_SHA256 = 0x00A2,
    TLS_DHE_DSS_WITH_AES_256_GCM_SHA384 = 0x00A3,
    TLS_DH_DSS_WITH_AES_128_GCM_SHA256 = 0x00A4,
    TLS_DH_DSS_WITH_AES_256_GCM_SHA384 = 0x00A5,
    TLS_DH_anon_WITH_AES_128_GCM_SHA256 = 0x00A6,
    TLS_DH_anon_WITH_AES_256_GCM_SHA384 = 0x00A7,


    TLS_PSK_WITH_AES_128_GCM_SHA256 = 0x00A8,
    TLS_PSK_WITH_AES_256_GCM_SHA384 = 0x00A9,
    TLS_DHE_PSK_WITH_AES_128_GCM_SHA256 = 0x00AA,
    TLS_DHE_PSK_WITH_AES_256_GCM_SHA384 = 0x00AB,
    TLS_RSA_PSK_WITH_AES_128_GCM_SHA256 = 0x00AC,
    TLS_RSA_PSK_WITH_AES_256_GCM_SHA384 = 0x00AD,

    TLS_PSK_WITH_AES_128_CBC_SHA256 = 0x00AE,
    TLS_PSK_WITH_AES_256_CBC_SHA384 = 0x00AF,
    TLS_PSK_WITH_NULL_SHA256 = 0x00B0,
    TLS_PSK_WITH_NULL_SHA384 = 0x00B1,

    TLS_DHE_PSK_WITH_AES_128_CBC_SHA256 = 0x00B2,
    TLS_DHE_PSK_WITH_AES_256_CBC_SHA384 = 0x00B3,
    TLS_DHE_PSK_WITH_NULL_SHA256 = 0x00B4,
    TLS_DHE_PSK_WITH_NULL_SHA384 = 0x00B5,

    TLS_RSA_PSK_WITH_AES_128_CBC_SHA256 = 0x00B6,
    TLS_RSA_PSK_WITH_AES_256_CBC_SHA384 = 0x00B7,
    TLS_RSA_PSK_WITH_NULL_SHA256 = 0x00B8,
    TLS_RSA_PSK_WITH_NULL_SHA384 = 0x00B9,




    TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA256 = 0xC023,
    TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA384 = 0xC024,
    TLS_ECDH_ECDSA_WITH_AES_128_CBC_SHA256 = 0xC025,
    TLS_ECDH_ECDSA_WITH_AES_256_CBC_SHA384 = 0xC026,
    TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA256 = 0xC027,
    TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA384 = 0xC028,
    TLS_ECDH_RSA_WITH_AES_128_CBC_SHA256 = 0xC029,
    TLS_ECDH_RSA_WITH_AES_256_CBC_SHA384 = 0xC02A,



    TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256 = 0xC02B,
    TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384 = 0xC02C,
    TLS_ECDH_ECDSA_WITH_AES_128_GCM_SHA256 = 0xC02D,
    TLS_ECDH_ECDSA_WITH_AES_256_GCM_SHA384 = 0xC02E,
    TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256 = 0xC02F,
    TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384 = 0xC030,
    TLS_ECDH_RSA_WITH_AES_128_GCM_SHA256 = 0xC031,
    TLS_ECDH_RSA_WITH_AES_256_GCM_SHA384 = 0xC032,


    TLS_EMPTY_RENEGOTIATION_INFO_SCSV = 0x00FF,




    SSL_RSA_WITH_RC2_CBC_MD5 = 0xFF80,
    SSL_RSA_WITH_IDEA_CBC_MD5 = 0xFF81,
    SSL_RSA_WITH_DES_CBC_MD5 = 0xFF82,
    SSL_RSA_WITH_3DES_EDE_CBC_MD5 = 0xFF83,
    SSL_NO_SUCH_CIPHERSUITE = 0xFFFF
};





extern "C" {
struct SSLContext;
typedef struct __attribute__((objc_bridge(id))) SSLContext *SSLContextRef;


typedef const void * SSLConnectionRef;


typedef int SSLProtocol; enum {
 kSSLProtocolUnknown = 0,
 kSSLProtocol3 = 2,
 kTLSProtocol1 = 4,
    kTLSProtocol11 = 7,
    kTLSProtocol12 = 8,
    kDTLSProtocol1 = 9,


    kSSLProtocol2 = 1,
    kSSLProtocol3Only = 3,
    kTLSProtocol1Only = 5,
    kSSLProtocolAll = 6,

};


typedef int SSLSessionOption; enum {







 kSSLSessionOptionBreakOnServerAuth = 0,




 kSSLSessionOptionBreakOnCertRequested = 1,






    kSSLSessionOptionBreakOnClientAuth = 2,





    kSSLSessionOptionFalseStart = 3,





    kSSLSessionOptionSendOneByteRecord = 4,




    kSSLSessionOptionAllowServerIdentityChange = 5,




    kSSLSessionOptionFallback = 6,



    kSSLSessionOptionBreakOnClientHello = 7,

};


typedef int SSLSessionState; enum {
 kSSLIdle,
 kSSLHandshake,
 kSSLConnected,
 kSSLClosed,
 kSSLAborted
};





typedef int SSLClientCertificateState; enum {

 kSSLClientCertNone,

 kSSLClientCertRequested,






 kSSLClientCertSent,




 kSSLClientCertRejected
} ;
typedef OSStatus
(*SSLReadFunc) (SSLConnectionRef connection,
        void *data,


        size_t *dataLength);
typedef OSStatus
(*SSLWriteFunc) (SSLConnectionRef connection,
        const void *data,
        size_t *dataLength);
enum {
 errSSLProtocol = -9800,
 errSSLNegotiation = -9801,
 errSSLFatalAlert = -9802,
 errSSLWouldBlock = -9803,
    errSSLSessionNotFound = -9804,
    errSSLClosedGraceful = -9805,
    errSSLClosedAbort = -9806,
    errSSLXCertChainInvalid = -9807,
    errSSLBadCert = -9808,
 errSSLCrypto = -9809,
 errSSLInternal = -9810,
 errSSLModuleAttach = -9811,
    errSSLUnknownRootCert = -9812,
    errSSLNoRootCert = -9813,
 errSSLCertExpired = -9814,
 errSSLCertNotYetValid = -9815,
 errSSLClosedNoNotify = -9816,
 errSSLBufferOverflow = -9817,
 errSSLBadCipherSuite = -9818,


 errSSLPeerUnexpectedMsg = -9819,
 errSSLPeerBadRecordMac = -9820,
 errSSLPeerDecryptionFail = -9821,
 errSSLPeerRecordOverflow = -9822,
 errSSLPeerDecompressFail = -9823,
 errSSLPeerHandshakeFail = -9824,
 errSSLPeerBadCert = -9825,
 errSSLPeerUnsupportedCert = -9826,
 errSSLPeerCertRevoked = -9827,
 errSSLPeerCertExpired = -9828,
 errSSLPeerCertUnknown = -9829,
 errSSLIllegalParam = -9830,
 errSSLPeerUnknownCA = -9831,
 errSSLPeerAccessDenied = -9832,
 errSSLPeerDecodeError = -9833,
 errSSLPeerDecryptError = -9834,
 errSSLPeerExportRestriction = -9835,
 errSSLPeerProtocolVersion = -9836,
 errSSLPeerInsufficientSecurity = -9837,
 errSSLPeerInternalError = -9838,
 errSSLPeerUserCancelled = -9839,
 errSSLPeerNoRenegotiation = -9840,


 errSSLPeerAuthCompleted = -9841,
 errSSLClientCertRequested = -9842,


 errSSLHostNameMismatch = -9843,
 errSSLConnectionRefused = -9844,
 errSSLDecryptionFail = -9845,
 errSSLBadRecordMac = -9846,
 errSSLRecordOverflow = -9847,
 errSSLBadConfiguration = -9848,
 errSSLUnexpectedRecord = -9849,
    errSSLWeakPeerEphemeralDHKey = -9850,


    errSSLClientHelloReceived = -9851,
};
typedef int SSLProtocolSide; enum
{
    kSSLServerSide,
    kSSLClientSide
};

typedef int SSLConnectionType; enum
{
    kSSLStreamType,
    kSSLDatagramType
};
CFTypeID
SSLContextGetTypeID(void)
 __attribute__((availability(macosx,introduced=10.8)));




_Nullable
SSLContextRef
SSLCreateContext(CFAllocatorRef _Nullable alloc, SSLProtocolSide protocolSide, SSLConnectionType connectionType)
 __attribute__((availability(macosx,introduced=10.8)));
OSStatus
SSLGetSessionState (SSLContextRef context,
        SSLSessionState *state)
 __attribute__((availability(macosx,introduced=10.2)));





OSStatus
SSLSetSessionOption (SSLContextRef context,
        SSLSessionOption option,
        Boolean value)
 __attribute__((availability(macosx,introduced=10.6)));




OSStatus
SSLGetSessionOption (SSLContextRef context,
        SSLSessionOption option,
        Boolean *value)
 __attribute__((availability(macosx,introduced=10.6)));
OSStatus
SSLSetIOFuncs (SSLContextRef context,
        SSLReadFunc readFunc,
        SSLWriteFunc writeFunc)
 __attribute__((availability(macosx,introduced=10.2)));
OSStatus
SSLSetProtocolVersionMin (SSLContextRef context,
                           SSLProtocol minVersion)
    __attribute__((availability(macosx,introduced=10.8)));




OSStatus
SSLGetProtocolVersionMin (SSLContextRef context,
                           SSLProtocol *minVersion)
    __attribute__((availability(macosx,introduced=10.8)));
OSStatus
SSLSetProtocolVersionMax (SSLContextRef context,
                           SSLProtocol maxVersion)
    __attribute__((availability(macosx,introduced=10.8)));




OSStatus
SSLGetProtocolVersionMax (SSLContextRef context,
                           SSLProtocol *maxVersion)
    __attribute__((availability(macosx,introduced=10.8)));
OSStatus
SSLSetCertificate (SSLContextRef context,
        CFArrayRef certRefs)
 __attribute__((availability(macosx,introduced=10.2)));
OSStatus
SSLSetConnection (SSLContextRef context,
        SSLConnectionRef _Nullable connection)
 __attribute__((availability(macosx,introduced=10.2)));

OSStatus
SSLGetConnection (SSLContextRef context,
        SSLConnectionRef * _Nonnull __attribute__((cf_returns_not_retained)) connection)
 __attribute__((availability(macosx,introduced=10.2)));
OSStatus
SSLSetPeerDomainName (SSLContextRef context,
        const char * _Nullable peerName,
        size_t peerNameLen)
 __attribute__((availability(macosx,introduced=10.2)));




OSStatus
SSLGetPeerDomainNameLength (SSLContextRef context,
        size_t *peerNameLen)
 __attribute__((availability(macosx,introduced=10.2)));




OSStatus
SSLGetPeerDomainName (SSLContextRef context,
        char *peerName,
        size_t *peerNameLen)
 __attribute__((availability(macosx,introduced=10.2)));






OSStatus
SSLSetDatagramHelloCookie (SSLContextRef dtlsContext,
                             const void * _Nullable cookie,
                             size_t cookieLen)
 __attribute__((availability(macosx,introduced=10.8)));
OSStatus
SSLSetMaxDatagramRecordSize (SSLContextRef dtlsContext,
                             size_t maxSize)
 __attribute__((availability(macosx,introduced=10.8)));





OSStatus
SSLGetMaxDatagramRecordSize (SSLContextRef dtlsContext,
                             size_t *maxSize)
 __attribute__((availability(macosx,introduced=10.8)));







OSStatus
SSLGetNegotiatedProtocolVersion (SSLContextRef context,
          SSLProtocol *protocol)
 __attribute__((availability(macosx,introduced=10.2)));







OSStatus
SSLGetNumberSupportedCiphers (SSLContextRef context,
         size_t *numCiphers)
 __attribute__((availability(macosx,introduced=10.2)));

OSStatus
SSLGetSupportedCiphers (SSLContextRef context,
         SSLCipherSuite *ciphers,
         size_t *numCiphers)
 __attribute__((availability(macosx,introduced=10.2)));







OSStatus
SSLSetEnabledCiphers (SSLContextRef context,
        const SSLCipherSuite *ciphers,
        size_t numCiphers)
 __attribute__((availability(macosx,introduced=10.2)));







OSStatus
SSLGetNumberEnabledCiphers (SSLContextRef context,
        size_t *numCiphers)
 __attribute__((availability(macosx,introduced=10.2)));

OSStatus
SSLGetEnabledCiphers (SSLContextRef context,
        SSLCipherSuite *ciphers,
        size_t *numCiphers)
 __attribute__((availability(macosx,introduced=10.2)));



typedef int SSLSessionStrengthPolicy; enum
{
    kSSLSessionStrengthPolicyDefault,
    kSSLSessionStrengthPolicyATSv1,
    kSSLSessionStrengthPolicyATSv1_noPFS,
};

OSStatus
SSLSetSessionStrengthPolicy(SSLContextRef context,
                            SSLSessionStrengthPolicy policyStrength);
OSStatus
SSLCopyPeerTrust (SSLContextRef context,
        SecTrustRef * _Nonnull __attribute__((cf_returns_retained)) trust)
 __attribute__((availability(macosx,introduced=10.6)));
OSStatus
SSLSetPeerID (SSLContextRef context,
        const void * _Nullable peerID,
        size_t peerIDLen)
 __attribute__((availability(macosx,introduced=10.2)));





OSStatus
SSLGetPeerID (SSLContextRef context,
        const void * _Nullable * _Nonnull peerID,
        size_t *peerIDLen)
 __attribute__((availability(macosx,introduced=10.2)));





OSStatus
SSLGetNegotiatedCipher (SSLContextRef context,
        SSLCipherSuite *cipherSuite)
 __attribute__((availability(macosx,introduced=10.2)));
OSStatus
SSLSetEncryptionCertificate (SSLContextRef context,
        CFArrayRef certRefs)
 __attribute__((availability(macosx,introduced=10.2,deprecated=10.11)));







typedef int SSLAuthenticate; enum {
 kNeverAuthenticate,
 kAlwaysAuthenticate,
 kTryAuthenticate

};

OSStatus
SSLSetClientSideAuthenticate (SSLContextRef context,
         SSLAuthenticate auth)
 __attribute__((availability(macosx,introduced=10.2)));





OSStatus
SSLAddDistinguishedName (SSLContextRef context,
        const void * _Nullable derDN,
        size_t derDNLen)
 __attribute__((availability(macosx,introduced=10.4)));
OSStatus
SSLCopyDistinguishedNames (SSLContextRef context,
        CFArrayRef * _Nonnull __attribute__((cf_returns_retained)) names)
 __attribute__((availability(macosx,introduced=10.5)));







OSStatus
SSLGetClientCertificateState (SSLContextRef context,
         SSLClientCertificateState *clientState)
 __attribute__((availability(macosx,introduced=10.3)));
OSStatus
SSLHandshake (SSLContextRef context)
 __attribute__((availability(macosx,introduced=10.2)));






OSStatus
SSLWrite (SSLContextRef context,
        const void * _Nullable data,
        size_t dataLength,
        size_t *processed)
 __attribute__((availability(macosx,introduced=10.2)));






OSStatus
SSLRead (SSLContextRef context,
        void * data,
        size_t dataLength,
        size_t *processed)
 __attribute__((availability(macosx,introduced=10.2)));






OSStatus
SSLGetBufferedReadSize (SSLContextRef context,
        size_t *bufSize)
 __attribute__((availability(macosx,introduced=10.2)));







OSStatus
SSLGetDatagramWriteSize (SSLContextRef dtlsContext,
        size_t *bufSize)
 __attribute__((availability(macosx,introduced=10.8)));




OSStatus
SSLClose (SSLContextRef context)
 __attribute__((availability(macosx,introduced=10.2)));





}

// @class NSString;
#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

// @class NSURL;
#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

// @class NSError;
#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

// @class NSDictionary;
#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

// @class NSInputStream;
#ifndef _REWRITER_typedef_NSInputStream
#define _REWRITER_typedef_NSInputStream
typedef struct objc_object NSInputStream;
typedef struct {} _objc_exc_NSInputStream;
#endif

// @class NSOutputStream;
#ifndef _REWRITER_typedef_NSOutputStream
#define _REWRITER_typedef_NSOutputStream
typedef struct objc_object NSOutputStream;
typedef struct {} _objc_exc_NSOutputStream;
#endif

// @class NSData;
#ifndef _REWRITER_typedef_NSData
#define _REWRITER_typedef_NSData
typedef struct objc_object NSData;
typedef struct {} _objc_exc_NSData;
#endif

// @class NSOperationQueue;
#ifndef _REWRITER_typedef_NSOperationQueue
#define _REWRITER_typedef_NSOperationQueue
typedef struct objc_object NSOperationQueue;
typedef struct {} _objc_exc_NSOperationQueue;
#endif


// @class NSURLCache;
#ifndef _REWRITER_typedef_NSURLCache
#define _REWRITER_typedef_NSURLCache
typedef struct objc_object NSURLCache;
typedef struct {} _objc_exc_NSURLCache;
#endif

// @class NSURLResponse;
#ifndef _REWRITER_typedef_NSURLResponse
#define _REWRITER_typedef_NSURLResponse
typedef struct objc_object NSURLResponse;
typedef struct {} _objc_exc_NSURLResponse;
#endif

// @class NSHTTPURLResponse;
#ifndef _REWRITER_typedef_NSHTTPURLResponse
#define _REWRITER_typedef_NSHTTPURLResponse
typedef struct objc_object NSHTTPURLResponse;
typedef struct {} _objc_exc_NSHTTPURLResponse;
#endif

// @class NSHTTPCookie;
#ifndef _REWRITER_typedef_NSHTTPCookie
#define _REWRITER_typedef_NSHTTPCookie
typedef struct objc_object NSHTTPCookie;
typedef struct {} _objc_exc_NSHTTPCookie;
#endif

// @class NSCachedURLResponse;
#ifndef _REWRITER_typedef_NSCachedURLResponse
#define _REWRITER_typedef_NSCachedURLResponse
typedef struct objc_object NSCachedURLResponse;
typedef struct {} _objc_exc_NSCachedURLResponse;
#endif

// @class NSURLAuthenticationChallenge;
#ifndef _REWRITER_typedef_NSURLAuthenticationChallenge
#define _REWRITER_typedef_NSURLAuthenticationChallenge
typedef struct objc_object NSURLAuthenticationChallenge;
typedef struct {} _objc_exc_NSURLAuthenticationChallenge;
#endif

// @class NSURLProtectionSpace;
#ifndef _REWRITER_typedef_NSURLProtectionSpace
#define _REWRITER_typedef_NSURLProtectionSpace
typedef struct objc_object NSURLProtectionSpace;
typedef struct {} _objc_exc_NSURLProtectionSpace;
#endif

// @class NSURLCredential;
#ifndef _REWRITER_typedef_NSURLCredential
#define _REWRITER_typedef_NSURLCredential
typedef struct objc_object NSURLCredential;
typedef struct {} _objc_exc_NSURLCredential;
#endif

// @class NSURLCredentialStorage;
#ifndef _REWRITER_typedef_NSURLCredentialStorage
#define _REWRITER_typedef_NSURLCredentialStorage
typedef struct objc_object NSURLCredentialStorage;
typedef struct {} _objc_exc_NSURLCredentialStorage;
#endif

// @class NSURLSessionDataTask;
#ifndef _REWRITER_typedef_NSURLSessionDataTask
#define _REWRITER_typedef_NSURLSessionDataTask
typedef struct objc_object NSURLSessionDataTask;
typedef struct {} _objc_exc_NSURLSessionDataTask;
#endif

// @class NSURLSessionUploadTask;
#ifndef _REWRITER_typedef_NSURLSessionUploadTask
#define _REWRITER_typedef_NSURLSessionUploadTask
typedef struct objc_object NSURLSessionUploadTask;
typedef struct {} _objc_exc_NSURLSessionUploadTask;
#endif

// @class NSURLSessionDownloadTask;
#ifndef _REWRITER_typedef_NSURLSessionDownloadTask
#define _REWRITER_typedef_NSURLSessionDownloadTask
typedef struct objc_object NSURLSessionDownloadTask;
typedef struct {} _objc_exc_NSURLSessionDownloadTask;
#endif

// @class NSNetService;
#ifndef _REWRITER_typedef_NSNetService
#define _REWRITER_typedef_NSNetService
typedef struct objc_object NSNetService;
typedef struct {} _objc_exc_NSNetService;
#endif

// @class NSURLSession;
#ifndef _REWRITER_typedef_NSURLSession
#define _REWRITER_typedef_NSURLSession
typedef struct objc_object NSURLSession;
typedef struct {} _objc_exc_NSURLSession;
#endif

// @class NSURLSessionDataTask;
#ifndef _REWRITER_typedef_NSURLSessionDataTask
#define _REWRITER_typedef_NSURLSessionDataTask
typedef struct objc_object NSURLSessionDataTask;
typedef struct {} _objc_exc_NSURLSessionDataTask;
#endif

// @class NSURLSessionUploadTask;
#ifndef _REWRITER_typedef_NSURLSessionUploadTask
#define _REWRITER_typedef_NSURLSessionUploadTask
typedef struct objc_object NSURLSessionUploadTask;
typedef struct {} _objc_exc_NSURLSessionUploadTask;
#endif

// @class NSURLSessionDownloadTask;
#ifndef _REWRITER_typedef_NSURLSessionDownloadTask
#define _REWRITER_typedef_NSURLSessionDownloadTask
typedef struct objc_object NSURLSessionDownloadTask;
typedef struct {} _objc_exc_NSURLSessionDownloadTask;
#endif

// @class NSURLSessionStreamTask;
#ifndef _REWRITER_typedef_NSURLSessionStreamTask
#define _REWRITER_typedef_NSURLSessionStreamTask
typedef struct objc_object NSURLSessionStreamTask;
typedef struct {} _objc_exc_NSURLSessionStreamTask;
#endif

// @class NSURLSessionConfiguration;
#ifndef _REWRITER_typedef_NSURLSessionConfiguration
#define _REWRITER_typedef_NSURLSessionConfiguration
typedef struct objc_object NSURLSessionConfiguration;
typedef struct {} _objc_exc_NSURLSessionConfiguration;
#endif

// @protocol NSURLSessionDelegate;
extern "C" const int64_t NSURLSessionTransferSizeUnknown __attribute__((availability(ios,introduced=7_0)));

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=7_0)))

#ifndef _REWRITER_typedef_NSURLSession
#define _REWRITER_typedef_NSURLSession
typedef struct objc_object NSURLSession;
typedef struct {} _objc_exc_NSURLSession;
#endif

struct NSURLSession_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};






// + (NSURLSession *)sharedSession;
// + (NSURLSession *)sessionWithConfiguration:(NSURLSessionConfiguration *)configuration;
// + (NSURLSession *)sessionWithConfiguration:(NSURLSessionConfiguration *)configuration delegate:(nullable id <NSURLSessionDelegate>)delegate delegateQueue:(nullable NSOperationQueue *)queue;

// @property (readonly, retain) NSOperationQueue *delegateQueue;
// @property (nullable, readonly, retain) id <NSURLSessionDelegate> delegate;
// @property (readonly, copy) NSURLSessionConfiguration *configuration;





// @property (nullable, copy) NSString *sessionDescription;
// - (void)finishTasksAndInvalidate;






// - (void)invalidateAndCancel;

// - (void)resetWithCompletionHandler:(void (^)(void))completionHandler;
// - (void)flushWithCompletionHandler:(void (^)(void))completionHandler;

// - (void)getTasksWithCompletionHandler:(void (^)(NSArray<NSURLSessionDataTask *> *dataTasks, NSArray<NSURLSessionUploadTask *> *uploadTasks, NSArray<NSURLSessionDownloadTask *> *downloadTasks))completionHandler;

// - (void)getAllTasksWithCompletionHandler:(void (^)(NSArray<__kindof NSURLSessionTask *> *tasks))completionHandler __attribute__((availability(ios,introduced=9_0)));







// - (NSURLSessionDataTask *)dataTaskWithRequest:(NSURLRequest *)request;


// - (NSURLSessionDataTask *)dataTaskWithURL:(NSURL *)url;


// - (NSURLSessionUploadTask *)uploadTaskWithRequest:(NSURLRequest *)request fromFile:(NSURL *)fileURL;


// - (NSURLSessionUploadTask *)uploadTaskWithRequest:(NSURLRequest *)request fromData:(NSData *)bodyData;


// - (NSURLSessionUploadTask *)uploadTaskWithStreamedRequest:(NSURLRequest *)request;


// - (NSURLSessionDownloadTask *)downloadTaskWithRequest:(NSURLRequest *)request;


// - (NSURLSessionDownloadTask *)downloadTaskWithURL:(NSURL *)url;


// - (NSURLSessionDownloadTask *)downloadTaskWithResumeData:(NSData *)resumeData;



// - (NSURLSessionStreamTask *)streamTaskWithHostName:(NSString *)hostname port:(NSInteger)port __attribute__((availability(ios,introduced=9_0))) __attribute__((availability(watchos,unavailable)));




// - (NSURLSessionStreamTask *)streamTaskWithNetService:(NSNetService *)service __attribute__((availability(ios,introduced=9_0))) __attribute__((availability(watchos,unavailable)));

/* @end */

// @interface NSURLSession (NSURLSessionAsynchronousConvenience)
// - (NSURLSessionDataTask *)dataTaskWithRequest:(NSURLRequest *)request completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;
// - (NSURLSessionDataTask *)dataTaskWithURL:(NSURL *)url completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;




// - (NSURLSessionUploadTask *)uploadTaskWithRequest:(NSURLRequest *)request fromFile:(NSURL *)fileURL completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;
// - (NSURLSessionUploadTask *)uploadTaskWithRequest:(NSURLRequest *)request fromData:(nullable NSData *)bodyData completionHandler:(void (^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;







// - (NSURLSessionDownloadTask *)downloadTaskWithRequest:(NSURLRequest *)request completionHandler:(void (^)(NSURL * _Nullable location, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;
// - (NSURLSessionDownloadTask *)downloadTaskWithURL:(NSURL *)url completionHandler:(void (^)(NSURL * _Nullable location, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;
// - (NSURLSessionDownloadTask *)downloadTaskWithResumeData:(NSData *)resumeData completionHandler:(void (^)(NSURL * _Nullable location, NSURLResponse * _Nullable response, NSError * _Nullable error))completionHandler;

/* @end */


typedef NSInteger NSURLSessionTaskState; enum {
    NSURLSessionTaskStateRunning = 0,
    NSURLSessionTaskStateSuspended = 1,
    NSURLSessionTaskStateCanceling = 2,
    NSURLSessionTaskStateCompleted = 3,
} __attribute__((availability(ios,introduced=7_0)));





__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=7_0)))

#ifndef _REWRITER_typedef_NSURLSessionTask
#define _REWRITER_typedef_NSURLSessionTask
typedef struct objc_object NSURLSessionTask;
typedef struct {} _objc_exc_NSURLSessionTask;
#endif

struct NSURLSessionTask_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// @property (readonly) NSUInteger taskIdentifier;
// @property (nullable, readonly, copy) NSURLRequest *originalRequest;
// @property (nullable, readonly, copy) NSURLRequest *currentRequest;
// @property (nullable, readonly, copy) NSURLResponse *response;







// @property (readonly) int64_t countOfBytesReceived;


// @property (readonly) int64_t countOfBytesSent;


// @property (readonly) int64_t countOfBytesExpectedToSend;


// @property (readonly) int64_t countOfBytesExpectedToReceive;





// @property (nullable, copy) NSString *taskDescription;







// - (void)cancel;




// @property (readonly) NSURLSessionTaskState state;





// @property (nullable, readonly, copy) NSError *error;
// - (void)suspend;
// - (void)resume;
// @property float priority __attribute__((availability(ios,introduced=8_0)));

/* @end */


extern "C" const float NSURLSessionTaskPriorityDefault __attribute__((availability(ios,introduced=8_0)));
extern "C" const float NSURLSessionTaskPriorityLow __attribute__((availability(ios,introduced=8_0)));
extern "C" const float NSURLSessionTaskPriorityHigh __attribute__((availability(ios,introduced=8_0)));







#ifndef _REWRITER_typedef_NSURLSessionDataTask
#define _REWRITER_typedef_NSURLSessionDataTask
typedef struct objc_object NSURLSessionDataTask;
typedef struct {} _objc_exc_NSURLSessionDataTask;
#endif

struct NSURLSessionDataTask_IMPL {
	struct NSURLSessionTask_IMPL NSURLSessionTask_IVARS;
};

/* @end */









#ifndef _REWRITER_typedef_NSURLSessionUploadTask
#define _REWRITER_typedef_NSURLSessionUploadTask
typedef struct objc_object NSURLSessionUploadTask;
typedef struct {} _objc_exc_NSURLSessionUploadTask;
#endif

struct NSURLSessionUploadTask_IMPL {
	struct NSURLSessionDataTask_IMPL NSURLSessionDataTask_IVARS;
};

/* @end */







#ifndef _REWRITER_typedef_NSURLSessionDownloadTask
#define _REWRITER_typedef_NSURLSessionDownloadTask
typedef struct objc_object NSURLSessionDownloadTask;
typedef struct {} _objc_exc_NSURLSessionDownloadTask;
#endif

struct NSURLSessionDownloadTask_IMPL {
	struct NSURLSessionTask_IMPL NSURLSessionTask_IVARS;
};

// - (void)cancelByProducingResumeData:(void (^)(NSData * _Nullable resumeData))completionHandler;

/* @end */

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=9_0)))

#ifndef _REWRITER_typedef_NSURLSessionStreamTask
#define _REWRITER_typedef_NSURLSessionStreamTask
typedef struct objc_object NSURLSessionStreamTask;
typedef struct {} _objc_exc_NSURLSessionStreamTask;
#endif

struct NSURLSessionStreamTask_IMPL {
	struct NSURLSessionTask_IMPL NSURLSessionTask_IVARS;
};







// - (void)readDataOfMinLength:(NSUInteger)minBytes maxLength:(NSUInteger)maxBytes timeout:(NSTimeInterval)timeout completionHandler:(void (^) (NSData * _Nullable data, BOOL atEOF, NSError * _Nullable error))completionHandler;






// - (void)writeData:(NSData *)data timeout:(NSTimeInterval)timeout completionHandler:(void (^) (NSError * _Nullable error))completionHandler;







// - (void)captureStreams;







// - (void)closeWrite;





// - (void)closeRead;






// - (void)startSecureConnection;





// - (void)stopSecureConnection;

/* @end */

__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=7_0)))

#ifndef _REWRITER_typedef_NSURLSessionConfiguration
#define _REWRITER_typedef_NSURLSessionConfiguration
typedef struct objc_object NSURLSessionConfiguration;
typedef struct {} _objc_exc_NSURLSessionConfiguration;
#endif

struct NSURLSessionConfiguration_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};


// + (NSURLSessionConfiguration *)defaultSessionConfiguration;
// + (NSURLSessionConfiguration *)ephemeralSessionConfiguration;
// + (NSURLSessionConfiguration *)backgroundSessionConfigurationWithIdentifier:(NSString *)identifier __attribute__((availability(ios,introduced=8_0)));


// @property (nullable, readonly, copy) NSString *identifier;


// @property NSURLRequestCachePolicy requestCachePolicy;


// @property NSTimeInterval timeoutIntervalForRequest;


// @property NSTimeInterval timeoutIntervalForResource;


// @property NSURLRequestNetworkServiceType networkServiceType;


// @property BOOL allowsCellularAccess;


// @property (getter=isDiscretionary) BOOL discretionary __attribute__((availability(ios,introduced=7_0)));





// @property (nullable, copy) NSString *sharedContainerIdentifier __attribute__((availability(ios,introduced=8_0)));






// @property BOOL sessionSendsLaunchEvents __attribute__((availability(ios,introduced=7_0)));


// @property (nullable, copy) NSDictionary *connectionProxyDictionary;


// @property SSLProtocol TLSMinimumSupportedProtocol;


// @property SSLProtocol TLSMaximumSupportedProtocol;


// @property BOOL HTTPShouldUsePipelining;


// @property BOOL HTTPShouldSetCookies;


// @property NSHTTPCookieAcceptPolicy HTTPCookieAcceptPolicy;



// @property (nullable, copy) NSDictionary *HTTPAdditionalHeaders;


// @property NSInteger HTTPMaximumConnectionsPerHost;


// @property (nullable, retain) NSHTTPCookieStorage *HTTPCookieStorage;


// @property (nullable, retain) NSURLCredentialStorage *URLCredentialStorage;


// @property (nullable, retain) NSURLCache *URLCache;




// @property BOOL shouldUseExtendedBackgroundIdleMode __attribute__((availability(ios,introduced=9_0)));
// @property (nullable, copy) NSArray<Class> *protocolClasses;

/* @end */





typedef NSInteger NSURLSessionAuthChallengeDisposition; enum {
    NSURLSessionAuthChallengeUseCredential = 0,
    NSURLSessionAuthChallengePerformDefaultHandling = 1,
    NSURLSessionAuthChallengeCancelAuthenticationChallenge = 2,
    NSURLSessionAuthChallengeRejectProtectionSpace = 3,
} __attribute__((availability(ios,introduced=7_0)));


typedef NSInteger NSURLSessionResponseDisposition; enum {
    NSURLSessionResponseCancel = 0,
    NSURLSessionResponseAllow = 1,
    NSURLSessionResponseBecomeDownload = 2,
    NSURLSessionResponseBecomeStream __attribute__((availability(ios,introduced=9_0))) = 3,
} __attribute__((availability(ios,introduced=7_0)));
// @protocol NSURLSessionDelegate <NSObject>
/* @optional */





// - (void)URLSession:(NSURLSession *)session didBecomeInvalidWithError:(nullable NSError *)error;
#if 0
- (void)URLSession:(NSURLSession *)session didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge
                                             completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler;
#endif

// - (void)URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession *)session __attribute__((availability(ios,introduced=7_0)));

/* @end */





// @protocol NSURLSessionTaskDelegate <NSURLSessionDelegate>
/* @optional */
#if 0
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
                     willPerformHTTPRedirection:(NSHTTPURLResponse *)response
                                     newRequest:(NSURLRequest *)request
                              completionHandler:(void (^)(NSURLRequest * _Nullable))completionHandler;
#endif







#if 0
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
                            didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge
                              completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler;
#endif






#if 0
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
                              needNewBodyStream:(void (^)(NSInputStream * _Nullable bodyStream))completionHandler;
#endif





#if 0
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
                                didSendBodyData:(int64_t)bytesSent
                                 totalBytesSent:(int64_t)totalBytesSent
                       totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
#endif





#if 0
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task
                           didCompleteWithError:(nullable NSError *)error;
#endif


/* @end */






// @protocol NSURLSessionDataDelegate <NSURLSessionTaskDelegate>
/* @optional */
#if 0
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
                                 didReceiveResponse:(NSURLResponse *)response
                                  completionHandler:(void (^)(NSURLSessionResponseDisposition disposition))completionHandler;
#endif





#if 0
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
                              didBecomeDownloadTask:(NSURLSessionDownloadTask *)downloadTask;
#endif

#if 0
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
                                didBecomeStreamTask:(NSURLSessionStreamTask *)streamTask;
#endif







#if 0
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
                                     didReceiveData:(NSData *)data;
#endif








#if 0
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask
                                  willCacheResponse:(NSCachedURLResponse *)proposedResponse
                                  completionHandler:(void (^)(NSCachedURLResponse * _Nullable cachedResponse))completionHandler;
#endif


/* @end */






// @protocol NSURLSessionDownloadDelegate <NSURLSessionTaskDelegate>






#if 0
- (void)URLSession:(NSURLSession *)session downloadTask:(NSURLSessionDownloadTask *)downloadTask
                              didFinishDownloadingToURL:(NSURL *)location;
#endif


/* @optional */

#if 0
- (void)URLSession:(NSURLSession *)session downloadTask:(NSURLSessionDownloadTask *)downloadTask
                                           didWriteData:(int64_t)bytesWritten
                                      totalBytesWritten:(int64_t)totalBytesWritten
                              totalBytesExpectedToWrite:(int64_t)totalBytesExpectedToWrite;
#endif







#if 0
- (void)URLSession:(NSURLSession *)session downloadTask:(NSURLSessionDownloadTask *)downloadTask
                                      didResumeAtOffset:(int64_t)fileOffset
                                     expectedTotalBytes:(int64_t)expectedTotalBytes;
#endif


/* @end */


// @protocol NSURLSessionStreamDelegate <NSURLSessionTaskDelegate>
/* @optional */







// - (void)URLSession:(NSURLSession *)session readClosedForStreamTask:(NSURLSessionStreamTask *)streamTask;





// - (void)URLSession:(NSURLSession *)session writeClosedForStreamTask:(NSURLSessionStreamTask *)streamTask;
// - (void)URLSession:(NSURLSession *)session betterRouteDiscoveredForStreamTask:(NSURLSessionStreamTask *)streamTask;







#if 0
- (void)URLSession:(NSURLSession *)session streamTask:(NSURLSessionStreamTask *)streamTask
                                 didBecomeInputStream:(NSInputStream *)inputStream
                                         outputStream:(NSOutputStream *)outputStream;
#endif


/* @end */



extern "C" NSString * const NSURLSessionDownloadTaskResumeData __attribute__((availability(ios,introduced=7_0)));

// @interface NSURLSessionConfiguration (NSURLSessionDeprecated)
// + (NSURLSessionConfiguration *)backgroundSessionConfiguration:(NSString *)identifier __attribute__((availability(ios,introduced=7_0,deprecated=8_0,message="" "Please use backgroundSessionConfigurationWithIdentifier: instead")));
/* @end */









// @class NSArray;
#ifndef _REWRITER_typedef_NSArray
#define _REWRITER_typedef_NSArray
typedef struct objc_object NSArray;
typedef struct {} _objc_exc_NSArray;
#endif

#ifndef _REWRITER_typedef_NSDictionary
#define _REWRITER_typedef_NSDictionary
typedef struct objc_object NSDictionary;
typedef struct {} _objc_exc_NSDictionary;
#endif

#ifndef _REWRITER_typedef_NSSet
#define _REWRITER_typedef_NSSet
typedef struct objc_object NSSet;
typedef struct {} _objc_exc_NSSet;
#endif

#ifndef _REWRITER_typedef_NSString
#define _REWRITER_typedef_NSString
typedef struct objc_object NSString;
typedef struct {} _objc_exc_NSString;
#endif

#ifndef _REWRITER_typedef_NSURL
#define _REWRITER_typedef_NSURL
typedef struct objc_object NSURL;
typedef struct {} _objc_exc_NSURL;
#endif

#ifndef _REWRITER_typedef_NSInputStream
#define _REWRITER_typedef_NSInputStream
typedef struct objc_object NSInputStream;
typedef struct {} _objc_exc_NSInputStream;
#endif

#ifndef _REWRITER_typedef_NSOutputStream
#define _REWRITER_typedef_NSOutputStream
typedef struct objc_object NSOutputStream;
typedef struct {} _objc_exc_NSOutputStream;
#endif

#ifndef _REWRITER_typedef_NSError
#define _REWRITER_typedef_NSError
typedef struct objc_object NSError;
typedef struct {} _objc_exc_NSError;
#endif

// @protocol NSUserActivityDelegate;





__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=8_0)))

#ifndef _REWRITER_typedef_NSUserActivity
#define _REWRITER_typedef_NSUserActivity
typedef struct objc_object NSUserActivity;
typedef struct {} _objc_exc_NSUserActivity;
#endif

struct NSUserActivity_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};




// - (instancetype)initWithActivityType:(NSString *)activityType;



// - (instancetype)init;



// @property (readonly, copy) NSString *activityType;



// @property (nullable, copy) NSString *title;



// @property (nullable, copy) NSDictionary *userInfo;



// - (void)addUserInfoEntriesFromDictionary:(NSDictionary *)otherDictionary;


// @property (copy) NSSet<NSString *> *requiredUserInfoKeys __attribute__((availability(ios,introduced=9_0)));



// @property (assign) BOOL needsSave;



// @property (nullable, copy) NSURL *webpageURL;


// @property (copy) NSDate *expirationDate __attribute__((availability(ios,introduced=9_0)));


// @property (copy) NSSet<NSString *> *keywords __attribute__((availability(ios,introduced=9_0)));



// @property BOOL supportsContinuationStreams;



// @property (nullable, weak) id<NSUserActivityDelegate> delegate;



// - (void)becomeCurrent;


// - (void)resignCurrent __attribute__((availability(ios,introduced=9_0)));



// - (void)invalidate;



// - (void)getContinuationStreamsWithCompletionHandler:(void (^)(NSInputStream * _Nullable inputStream, NSOutputStream * _Nullable outputStream, NSError * _Nullable error))completionHandler;


// @property (getter=isEligibleForHandoff) BOOL eligibleForHandoff __attribute__((availability(ios,introduced=9_0)));


// @property (getter=isEligibleForSearch) BOOL eligibleForSearch __attribute__((availability(ios,introduced=9_0)));


// @property (getter=isEligibleForPublicIndexing) BOOL eligibleForPublicIndexing __attribute__((availability(ios,introduced=9_0)));

/* @end */




extern "C" NSString * const NSUserActivityTypeBrowsingWeb __attribute__((availability(ios,introduced=8_0)));



__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=8_0)))
// @protocol NSUserActivityDelegate <NSObject>
/* @optional */



// - (void)userActivityWillSave:(NSUserActivity *)userActivity;



// - (void)userActivityWasContinued:(NSUserActivity *)userActivity;



// - (void)userActivity:(nullable NSUserActivity *)userActivity didReceiveInputStream:(NSInputStream *)inputStream outputStream:(NSOutputStream *)outputStream;

/* @end */







typedef __darwin_uuid_string_t uuid_string_t;






extern "C" {


void uuid_clear(uuid_t uu);

int uuid_compare(const uuid_t uu1, const uuid_t uu2);

void uuid_copy(uuid_t dst, const uuid_t src);

void uuid_generate(uuid_t out);
void uuid_generate_random(uuid_t out);
void uuid_generate_time(uuid_t out);

int uuid_is_null(const uuid_t uu);

int uuid_parse(const uuid_string_t in, uuid_t uu);

void uuid_unparse(const uuid_t uu, uuid_string_t out);
void uuid_unparse_lower(const uuid_t uu, uuid_string_t out);
void uuid_unparse_upper(const uuid_t uu, uuid_string_t out);


}





__attribute__((visibility("default"))) __attribute__((availability(ios,introduced=6_0)))

#ifndef _REWRITER_typedef_NSUUID
#define _REWRITER_typedef_NSUUID
typedef struct objc_object NSUUID;
typedef struct {} _objc_exc_NSUUID;
#endif

struct NSUUID_IMPL {
	struct NSObject_IMPL NSObject_IVARS;
};



// + (instancetype)UUID;


// - (instancetype)init __attribute__((objc_designated_initializer));


// - (nullable instancetype)initWithUUIDString:(NSString *)string;


// - (instancetype)initWithUUIDBytes:(const uuid_t)bytes;


// - (void)getUUIDBytes:(uuid_t)uuid;


// @property (readonly, copy) NSString *UUIDString;

/* @end */


typedef int (*blk_t)(int);

struct __func_block_impl_0 {
  struct __block_impl impl;
  struct __func_block_desc_0* Desc;
  int rate;
  __func_block_impl_0(void *fp, struct __func_block_desc_0 *desc, int _rate, int flags=0) : rate(_rate) {
    impl.isa = &_NSConcreteStackBlock;
    impl.Flags = flags;
    impl.FuncPtr = fp;
    Desc = desc;
  }
};
static int __func_block_func_0(struct __func_block_impl_0 *__cself, int count) {
  int rate = __cself->rate; // bound by copy
return rate * count;}

static struct __func_block_desc_0 {
  size_t reserved;
  size_t Block_size;
} __func_block_desc_0_DATA = { 0, sizeof(struct __func_block_impl_0)};
blk_t func(int rate)
{
    return ((int (*)(int))&__func_block_impl_0((void *)__func_block_func_0, &__func_block_desc_0_DATA, rate));
}

int main(int argc, char * argv[]) {
 __attribute__((objc_ownership(weak))) NSObject* obj = ((NSObject *(*)(id, SEL))(void *)objc_msgSend)((id)objc_getClass("NSObject"), sel_registerName("new"));
 ((id (*)(id, SEL))(void *)objc_msgSend)((id)obj, sel_registerName("copy"));
 return 0;
}
static struct IMAGE_INFO { unsigned version; unsigned flag; } _OBJC_IMAGE_INFO = { 0, 2 };
