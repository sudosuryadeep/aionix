/*
 * ============================================================
 *  COMPREHENSIVE C LANGUAGE REFERENCE - ALL IN ONE FILE
 *  Covers: Basics, Pointers, Arrays, Strings, Structs, Unions,
 *          Enums, File I/O, Dynamic Memory, Recursion, Sorting,
 *          Searching, Linked Lists, Stacks, Queues, Trees,
 *          Bit Manipulation, Preprocessor, and much more.
 * ============================================================
 */

/* ============================================================
 * SECTION 1: HEADERS AND PREPROCESSOR DIRECTIVES
 * ============================================================ */

#include <stdio.h>       /* Standard I/O */
#include <stdlib.h>      /* Memory allocation, conversions */
#include <string.h>      /* String functions */
#include <math.h>        /* Math functions */
#include <ctype.h>       /* Character classification */
#include <time.h>        /* Date and time */
#include <limits.h>      /* Integer limits */
#include <float.h>       /* Float limits */
#include <stdarg.h>      /* Variable arguments */
#include <assert.h>      /* Assertions */
#include <errno.h>       /* Error numbers */
#include <stdbool.h>     /* Boolean type */
#include <stdint.h>      /* Fixed-width integers */

/* Macro definitions */
#define PI              3.14159265358979323846
#define MAX(a, b)       ((a) > (b) ? (a) : (b))
#define MIN(a, b)       ((a) < (b) ? (a) : (b))
#define ABS(x)          ((x) < 0 ? -(x) : (x))
#define SQUARE(x)       ((x) * (x))
#define SWAP(a, b, T)   do { T _t = (a); (a) = (b); (b) = _t; } while(0)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define IS_EVEN(n)      ((n) % 2 == 0)
#define IS_ODD(n)       ((n) % 2 != 0)
#define CLAMP(x,lo,hi)  ((x) < (lo) ? (lo) : (x) > (hi) ? (hi) : (x))
#define UNUSED(x)       (void)(x)

/* Conditional compilation */
#define DEBUG 1
#ifdef DEBUG
    #define LOG(fmt, ...) fprintf(stderr, "[DEBUG] " fmt "\n", ##__VA_ARGS__)
#else
    #define LOG(fmt, ...) /* nothing */
#endif

/* Stringification and token pasting */
#define STRINGIFY(x) #x
#define TOSTRING(x)  STRINGIFY(x)
#define CONCAT(a, b) a##b

/* ============================================================
 * SECTION 2: CONSTANTS AND GLOBAL VARIABLES
 * ============================================================ */

const int    GLOBAL_CONST   = 100;
const double EULER          = 2.71828182845904523536;
const double GOLDEN_RATIO   = 1.61803398874989484820;

static int   static_global  = 0;   /* File-scope static */
int          extern_example = 42;  /* Can be extern'd elsewhere */

/* ============================================================
 * SECTION 3: DATA TYPES AND SIZES
 * ============================================================ */

void section_data_types(void) {
    printf("\n===== DATA TYPES =====\n");

    /* Signed integers */
    char            c   = 'A';
    short           s   = 32767;
    int             i   = 2147483647;
    long            l   = 2147483647L;
    long long       ll  = 9223372036854775807LL;

    /* Unsigned integers */
    unsigned char   uc  = 255;
    unsigned short  us  = 65535;
    unsigned int    ui  = 4294967295U;
    unsigned long   ul  = 4294967295UL;
    unsigned long long ull = 18446744073709551615ULL;

    /* Floating point */
    float           f   = 3.14f;
    double          d   = 3.141592653589793;
    long double     ld  = 3.141592653589793238L;

    /* Boolean (C99) */
    bool flag = true;

    /* Fixed-width types (stdint.h) */
    int8_t   i8  =  127;
    int16_t  i16 =  32767;
    int32_t  i32 =  2147483647;
    int64_t  i64 =  9223372036854775807LL;
    uint8_t  u8  =  255;
    uint16_t u16 =  65535;
    uint32_t u32 =  4294967295U;
    uint64_t u64 =  18446744073709551615ULL;

    printf("sizeof(char)=%zu, sizeof(short)=%zu, sizeof(int)=%zu\n",
           sizeof(char), sizeof(short), sizeof(int));
    printf("sizeof(long)=%zu, sizeof(long long)=%zu\n",
           sizeof(long), sizeof(long long));
    printf("sizeof(float)=%zu, sizeof(double)=%zu, sizeof(long double)=%zu\n",
           sizeof(float), sizeof(double), sizeof(long double));
    printf("sizeof(bool)=%zu, sizeof(int64_t)=%zu\n",
           sizeof(bool), sizeof(int64_t));

    printf("INT_MAX=%d, INT_MIN=%d\n", INT_MAX, INT_MIN);
    printf("UINT_MAX=%u\n", UINT_MAX);
    printf("DBL_MAX=%g, DBL_MIN=%g, DBL_EPSILON=%g\n",
           DBL_MAX, DBL_MIN, DBL_EPSILON);

    /* Silence unused variable warnings */
    UNUSED(c); UNUSED(s); UNUSED(i); UNUSED(l); UNUSED(ll);
    UNUSED(uc); UNUSED(us); UNUSED(ui); UNUSED(ul); UNUSED(ull);
    UNUSED(f); UNUSED(d); UNUSED(ld); UNUSED(flag);
    UNUSED(i8); UNUSED(i16); UNUSED(i32); UNUSED(i64);
    UNUSED(u8); UNUSED(u16); UNUSED(u32); UNUSED(u64);
}

/* ============================================================
 * SECTION 4: OPERATORS
 * ============================================================ */

void section_operators(void) {
    printf("\n===== OPERATORS =====\n");

    int a = 10, b = 3;

    /* Arithmetic */
    printf("Arithmetic: %d+%d=%d, %d-%d=%d, %d*%d=%d, %d/%d=%d, %d%%%d=%d\n",
           a,b,a+b, a,b,a-b, a,b,a*b, a,b,a/b, a,b,a%b);

    /* Relational */
    printf("Relational: %d==%d:%d, %d!=%d:%d, %d>%d:%d, %d<%d:%d\n",
           a,b,a==b, a,b,a!=b, a,b,a>b, a,b,a<b);

    /* Logical */
    int x=1, y=0;
    printf("Logical: x&&y=%d, x||y=%d, !x=%d\n", x&&y, x||y, !x);

    /* Bitwise */
    unsigned int u=0b10110011, v=0b11001010;
    printf("Bitwise: u&v=0x%X, u|v=0x%X, u^v=0x%X, ~u=0x%X\n",
           u&v, u|v, u^v, ~u);
    printf("Shifts: u<<2=0x%X, u>>2=0x%X\n", u<<2, u>>2);

    /* Assignment operators */
    int n = 5;
    n += 3;  printf("+=: %d\n", n);
    n -= 2;  printf("-=: %d\n", n);
    n *= 4;  printf("*=: %d\n", n);
    n /= 3;  printf("/=: %d\n", n);
    n %= 4;  printf("%%=: %d\n", n);
    n <<= 1; printf("<<=: %d\n", n);
    n >>= 1; printf(">>=: %d\n", n);
    n &= 6;  printf("&=: %d\n", n);
    n |= 9;  printf("|=: %d\n", n);
    n ^= 3;  printf("^=: %d\n", n);

    /* Increment / decrement */
    int p = 5;
    printf("p++=%d, p=%d\n", p++, p);
    printf("++p=%d, p=%d\n", ++p, p);
    printf("p--=%d, p=%d\n", p--, p);
    printf("--p=%d, p=%d\n", --p, p);

    /* Ternary */
    int max_ab = (a > b) ? a : b;
    printf("Ternary max(%d,%d)=%d\n", a, b, max_ab);

    /* Comma operator */
    int q = (a=1, b=2, a+b);
    printf("Comma: q=%d\n", q);

    /* sizeof / typeof */
    printf("sizeof(int)=%zu\n", sizeof(int));
    printf("sizeof(double)=%zu\n", sizeof(double));
}

/* ============================================================
 * SECTION 5: CONTROL FLOW
 * ============================================================ */

void section_control_flow(void) {
    printf("\n===== CONTROL FLOW =====\n");

    /* if / else if / else */
    int score = 75;
    if      (score >= 90) printf("Grade: A\n");
    else if (score >= 80) printf("Grade: B\n");
    else if (score >= 70) printf("Grade: C\n");
    else if (score >= 60) printf("Grade: D\n");
    else                  printf("Grade: F\n");

    /* switch */
    int day = 3;
    switch (day) {
        case 1: printf("Monday\n");    break;
        case 2: printf("Tuesday\n");   break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n");  break;
        case 5: printf("Friday\n");    break;
        case 6: printf("Saturday\n");  break;
        case 7: printf("Sunday\n");    break;
        default: printf("Invalid\n");  break;
    }

    /* Fall-through example */
    int x = 2;
    switch (x) {
        case 1:
        case 2:
        case 3:
            printf("x is 1, 2, or 3 (fall-through): x=%d\n", x);
            break;
        default:
            printf("x is other: %d\n", x);
    }

    /* while loop */
    int i = 0;
    while (i < 5) {
        printf("while i=%d\n", i);
        i++;
    }

    /* do-while loop */
    int j = 0;
    do {
        printf("do-while j=%d\n", j);
        j++;
    } while (j < 3);

    /* for loop */
    for (int k = 0; k < 5; k++) {
        printf("for k=%d\n", k);
    }

    /* Nested loops with break and continue */
    for (int r = 0; r < 4; r++) {
        for (int c = 0; c < 4; c++) {
            if (c == 2) continue;
            if (r == 3 && c == 3) break;
            printf("(%d,%d) ", r, c);
        }
    }
    printf("\n");

    /* goto (use sparingly) */
    int count = 0;
loop_start:
    if (count < 3) {
        printf("goto count=%d\n", count);
        count++;
        goto loop_start;
    }
}

/* ============================================================
 * SECTION 6: FUNCTIONS
 * ============================================================ */

/* Forward declarations (prototypes) */
int    add(int a, int b);
double power(double base, int exp);
void   print_separator(char ch, int width);
int    gcd(int a, int b);
long   factorial(int n);
int    fibonacci(int n);
void   swap_ints(int *a, int *b);
int    sum_array(const int *arr, int n);
double average(const int *arr, int n);
int    is_prime(int n);
void   variadic_sum(int count, ...);
int  (*get_op(char op))(int, int); /* Returns function pointer */

/* Implementations */
int add(int a, int b) { return a + b; }

double power(double base, int exp) {
    if (exp == 0) return 1.0;
    if (exp < 0)  return 1.0 / power(base, -exp);
    double result = 1.0;
    while (exp-- > 0) result *= base;
    return result;
}

void print_separator(char ch, int width) {
    for (int i = 0; i < width; i++) putchar(ch);
    putchar('\n');
}

int gcd(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void swap_ints(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int sum_array(const int *arr, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) s += arr[i];
    return s;
}

double average(const int *arr, int n) {
    return (n == 0) ? 0.0 : (double)sum_array(arr, n) / n;
}

int is_prime(int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; (long)i*i <= n; i += 2)
        if (n % i == 0) return 0;
    return 1;
}

/* Variadic function */
void variadic_sum(int count, ...) {
    va_list args;
    va_start(args, count);
    int total = 0;
    for (int i = 0; i < count; i++)
        total += va_arg(args, int);
    va_end(args);
    printf("Variadic sum(%d args)=%d\n", count, total);
}

/* Function pointers */
int multiply(int a, int b) { return a * b; }
int divide(int a, int b)   { return (b != 0) ? a / b : 0; }
int subtract(int a, int b) { return a - b; }

int (*get_op(char op))(int, int) {
    switch (op) {
        case '+': return add;
        case '-': return subtract;
        case '*': return multiply;
        case '/': return divide;
        default:  return NULL;
    }
}

void section_functions(void) {
    printf("\n===== FUNCTIONS =====\n");
    printf("add(3,4)=%d\n", add(3, 4));
    printf("power(2,10)=%.0f\n", power(2, 10));
    printf("gcd(48,18)=%d\n", gcd(48, 18));
    printf("factorial(10)=%ld\n", factorial(10));

    /* Print Fibonacci sequence */
    printf("Fibonacci: ");
    for (int i = 0; i < 10; i++) printf("%d ", fibonacci(i));
    printf("\n");

    int arr[] = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    int n = ARRAY_SIZE(arr);
    printf("sum=%d, avg=%.2f\n", sum_array(arr, n), average(arr, n));

    int a = 10, b = 20;
    printf("Before swap: a=%d, b=%d\n", a, b);
    swap_ints(&a, &b);
    printf("After swap:  a=%d, b=%d\n", a, b);

    /* Primes up to 50 */
    printf("Primes <=50: ");
    for (int i = 2; i <= 50; i++)
        if (is_prime(i)) printf("%d ", i);
    printf("\n");

    variadic_sum(4, 10, 20, 30, 40);

    /* Function pointers */
    int (*op)(int, int) = get_op('*');
    if (op) printf("FnPtr * : 6*7=%d\n", op(6, 7));

    /* Array of function pointers */
    int (*ops[4])(int,int) = { add, subtract, multiply, divide };
    const char *names[] = { "add", "sub", "mul", "div" };
    for (int i = 0; i < 4; i++)
        printf("FnArr %s(12,4)=%d\n", names[i], ops[i](12, 4));
}

/* ============================================================
 * SECTION 7: ARRAYS
 * ============================================================ */

void section_arrays(void) {
    printf("\n===== ARRAYS =====\n");

    /* 1D array */
    int arr[10] = {0};
    for (int i = 0; i < 10; i++) arr[i] = i * i;
    printf("Squares: ");
    for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
    printf("\n");

    /* Designated initializers */
    int sparse[10] = {[0]=1, [3]=9, [7]=49};
    printf("Sparse: ");
    for (int i = 0; i < 10; i++) printf("%d ", sparse[i]);
    printf("\n");

    /* 2D array */
    int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    printf("Matrix:\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) printf("%3d", mat[r][c]);
        printf("\n");
    }

    /* Matrix transpose */
    int trans[3][3];
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            trans[c][r] = mat[r][c];
    printf("Transpose:\n");
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) printf("%3d", trans[r][c]);
        printf("\n");
    }

    /* 3D array */
    int cube[2][2][2];
    int val = 1;
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                cube[i][j][k] = val++;
    printf("Cube[0][1][1]=%d\n", cube[0][1][1]);

    /* VLA (Variable Length Array, C99) */
    int n = 5;
    int vla[n];
    for (int i = 0; i < n; i++) vla[i] = i + 1;
    printf("VLA: ");
    for (int i = 0; i < n; i++) printf("%d ", vla[i]);
    printf("\n");

    /* Array decay to pointer */
    int *ptr = arr;
    printf("arr[3] via pointer: %d\n", ptr[3]);
    printf("arr[3] via arithmetic: %d\n", *(ptr + 3));
}

/* ============================================================
 * SECTION 8: STRINGS
 * ============================================================ */

/* Reverse a string in-place */
void str_reverse(char *s) {
    int lo = 0, hi = (int)strlen(s) - 1;
    while (lo < hi) { SWAP(s[lo], s[hi], char); lo++; hi--; }
}

/* Count words in a string */
int count_words(const char *s) {
    int count = 0, in_word = 0;
    while (*s) {
        if (isspace((unsigned char)*s)) { in_word = 0; }
        else if (!in_word) { in_word = 1; count++; }
        s++;
    }
    return count;
}

/* Check palindrome */
int is_palindrome(const char *s) {
    int lo = 0, hi = (int)strlen(s) - 1;
    while (lo < hi)
        if (s[lo++] != s[hi--]) return 0;
    return 1;
}

void section_strings(void) {
    printf("\n===== STRINGS =====\n");

    /* Declaration and initialization */
    char s1[] = "Hello, World!";
    char s2[50];
    char s3[] = {'C', ' ', 'L', 'a', 'n', 'g', '\0'};
    const char *s4 = "String literal";

    printf("s1=\"%s\", len=%zu\n", s1, strlen(s1));
    printf("s3=\"%s\"\n", s3);
    printf("s4=\"%s\"\n", s4);

    /* strcpy / strncpy */
    strcpy(s2, "Copied string");
    printf("strcpy: \"%s\"\n", s2);
    strncpy(s2, "Safe copy", 49);
    s2[49] = '\0';
    printf("strncpy: \"%s\"\n", s2);

    /* strcat / strncat */
    char buf[100] = "Hello";
    strcat(buf, ", ");
    strncat(buf, "World!", 99 - strlen(buf));
    printf("strcat: \"%s\"\n", buf);

    /* strcmp */
    printf("strcmp(\"abc\",\"abc\")=%d\n", strcmp("abc","abc"));
    printf("strcmp(\"abc\",\"abd\")=%d\n", strcmp("abc","abd"));
    printf("strcasecmp: %d\n", strcasecmp("Hello","hello"));

    /* String search */
    char haystack[] = "The quick brown fox jumps over the lazy dog";
    char *found = strstr(haystack, "fox");
    if (found) printf("strstr found 'fox' at offset %td\n", found - haystack);

    char *ch = strchr(haystack, 'q');
    if (ch) printf("strchr 'q' at offset %td\n", ch - haystack);

    /* String to number */
    printf("atoi(\"42\")=%d\n", atoi("42"));
    printf("atof(\"3.14\")=%f\n", atof("3.14"));
    printf("strtol(\"0xFF\")=%ld\n", strtol("0xFF", NULL, 16));
    printf("strtod(\"2.718\")=%f\n", strtod("2.718", NULL));

    /* Number to string */
    char numstr[32];
    sprintf(numstr, "%d", 12345);
    printf("sprintf number: \"%s\"\n", numstr);

    /* Tokenize */
    char csv[] = "one,two,three,four,five";
    char *token = strtok(csv, ",");
    printf("Tokens: ");
    while (token) {
        printf("[%s] ", token);
        token = strtok(NULL, ",");
    }
    printf("\n");

    /* Reverse and palindrome */
    char rev[] = "Programming";
    str_reverse(rev);
    printf("Reversed: \"%s\"\n", rev);
    printf("is_palindrome(\"racecar\")=%d\n", is_palindrome("racecar"));
    printf("is_palindrome(\"hello\")=%d\n",   is_palindrome("hello"));
    printf("word count in \"%s\"=%d\n", haystack, count_words(haystack));

    /* sprintf / sscanf */
    char formatted[64];
    sprintf(formatted, "Value: %05d, Pi: %.4f", 42, PI);
    printf("sprintf: \"%s\"\n", formatted);

    int num; float fval;
    sscanf("99 3.14", "%d %f", &num, &fval);
    printf("sscanf: num=%d, fval=%f\n", num, fval);

    /* memset / memcpy / memmove */
    char mem[20];
    memset(mem, 'X', sizeof(mem) - 1);
    mem[sizeof(mem)-1] = '\0';
    printf("memset: \"%s\"\n", mem);

    memcpy(mem, "MemCpy", 6);
    printf("memcpy: \"%s\"\n", mem);

    memmove(mem + 2, mem, 6);
    mem[8] = '\0';
    printf("memmove: \"%s\"\n", mem);
}

/* ============================================================
 * SECTION 9: POINTERS
 * ============================================================ */

void section_pointers(void) {
    printf("\n===== POINTERS =====\n");

    int x = 42;
    int *p = &x;

    printf("x=%d, &x=%p, p=%p, *p=%d\n", x, (void*)&x, (void*)p, *p);

    *p = 100;
    printf("After *p=100: x=%d\n", x);

    /* Pointer arithmetic */
    int arr[] = {10, 20, 30, 40, 50};
    int *pa = arr;
    printf("Pointer arithmetic: ");
    for (int i = 0; i < 5; i++) printf("%d ", *(pa + i));
    printf("\n");
    printf("pa[2]=%d, *(pa+2)=%d\n", pa[2], *(pa+2));

    /* Pointer to pointer */
    int **pp = &p;
    printf("pp=%p, *pp=%p, **pp=%d\n", (void*)pp, (void*)*pp, **pp);

    /* void pointer */
    void *vp = &x;
    printf("void* value: %d\n", *(int*)vp);

    /* const pointers */
    const int ci = 99;
    const int *cip = &ci;         /* pointer to const int */
    int yi = 55;
    int * const cp = &yi;         /* const pointer to int */
    const int * const ccp = &ci;  /* const pointer to const int */
    printf("const int*: %d, int* const: %d, const int* const: %d\n",
           *cip, *cp, *ccp);

    /* NULL pointer check */
    int *null_ptr = NULL;
    if (null_ptr == NULL) printf("null_ptr is NULL\n");

    /* Pointer comparison */
    int arr2[] = {1,2,3,4,5};
    int *begin = arr2;
    int *end   = arr2 + 5;
    printf("Array via pointer iteration: ");
    for (int *it = begin; it != end; it++) printf("%d ", *it);
    printf("\n");

    /* Function pointer */
    double (*fnp)(double, int) = power;
    printf("FnPtr power(2,8)=%.0f\n", fnp(2.0, 8));

    /* Pointer to array */
    int (*parr)[5] = &arr2;  /* pointer to array of 5 ints */
    printf("(*parr)[3]=%d\n", (*parr)[3]);

    /* Generic swap using void* */
    /* (implemented inline) */
    double da=1.5, db=2.5;
    double dt = da; da = db; db = dt;
    printf("Swapped doubles: %.1f %.1f\n", da, db);
}

/* ============================================================
 * SECTION 10: STRUCTS
 * ============================================================ */

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct Rectangle {
    Point top_left;
    Point bottom_right;
} Rectangle;

typedef struct Person {
    char   name[50];
    int    age;
    double gpa;
} Person;

/* Struct methods (using functions that take struct*) */
double point_distance(const Point *a, const Point *b) {
    double dx = a->x - b->x, dy = a->y - b->y;
    return sqrt(dx*dx + dy*dy);
}

double rect_area(const Rectangle *r) {
    double w = ABS(r->bottom_right.x - r->top_left.x);
    double h = ABS(r->bottom_right.y - r->top_left.y);
    return w * h;
}

void person_print(const Person *p) {
    printf("Person{name=\"%s\", age=%d, gpa=%.2f}\n", p->name, p->age, p->gpa);
}

int person_compare_age(const void *a, const void *b) {
    return ((Person*)a)->age - ((Person*)b)->age;
}

void section_structs(void) {
    printf("\n===== STRUCTS =====\n");

    /* Initialization */
    Point p1 = {0.0, 0.0};
    Point p2 = {3.0, 4.0};
    printf("Distance p1->p2=%.2f\n", point_distance(&p1, &p2));

    /* Designated initializers */
    Rectangle rect = { .top_left={0,10}, .bottom_right={5,0} };
    printf("Rect area=%.2f\n", rect_area(&rect));

    /* Arrow vs dot */
    Person alice;
    strcpy(alice.name, "Alice");
    alice.age = 30;
    alice.gpa = 3.9;
    person_print(&alice);

    Person *pp = &alice;
    printf("Via arrow: name=%s, age=%d\n", pp->name, pp->age);

    /* Array of structs */
    Person people[] = {
        {"Charlie", 25, 3.5},
        {"Bob",     22, 3.7},
        {"Diana",   28, 3.2},
        {"Eve",     23, 3.8},
    };
    int np = ARRAY_SIZE(people);
    qsort(people, np, sizeof(Person), person_compare_age);
    printf("Sorted by age:\n");
    for (int i = 0; i < np; i++) person_print(&people[i]);

    /* Nested struct */
    typedef struct {
        char street[50];
        char city[30];
        int  zip;
    } Address;
    typedef struct {
        Person  person;
        Address address;
    } Employee;

    Employee emp = {{"Frank", 35, 3.6}, {"123 Main St", "Springfield", 12345}};
    printf("Employee: %s lives at %s, %s %d\n",
           emp.person.name, emp.address.street,
           emp.address.city, emp.address.zip);

    /* Bit fields */
    typedef struct {
        unsigned int is_active   : 1;
        unsigned int is_admin    : 1;
        unsigned int permissions : 4;
        unsigned int reserved    : 26;
    } Flags;
    Flags f = {1, 0, 0b1010, 0};
    printf("Flags: active=%u, admin=%u, perm=%u\n",
           f.is_active, f.is_admin, f.permissions);
    printf("sizeof(Flags)=%zu\n", sizeof(Flags));
}

/* ============================================================
 * SECTION 11: UNIONS AND ENUMS
 * ============================================================ */

typedef enum {
    MON=1, TUE, WED, THU, FRI, SAT, SUN
} Weekday;

typedef enum Color {
    COLOR_RED   = 0xFF0000,
    COLOR_GREEN = 0x00FF00,
    COLOR_BLUE  = 0x0000FF,
    COLOR_WHITE = 0xFFFFFF,
    COLOR_BLACK = 0x000000,
} Color;

typedef union {
    int    i;
    float  f;
    char   bytes[4];
} Data;

typedef struct {
    enum { TYPE_INT, TYPE_FLOAT, TYPE_STRING } type;
    union {
        int    ival;
        float  fval;
        char   sval[32];
    } val;
} Variant;

void section_unions_enums(void) {
    printf("\n===== UNIONS AND ENUMS =====\n");

    /* Enum */
    Weekday today = WED;
    const char *day_names[] = {"","Mon","Tue","Wed","Thu","Fri","Sat","Sun"};
    printf("Today: %s (value=%d)\n", day_names[today], today);

    Color c = COLOR_BLUE;
    printf("COLOR_BLUE=0x%06X\n", c);

    /* Union – all members share the same memory */
    Data d;
    d.i = 0x41424344;
    printf("Union as int: %d\n", d.i);
    printf("Union bytes: %c %c %c %c\n",
           d.bytes[0], d.bytes[1], d.bytes[2], d.bytes[3]);
    d.f = 3.14f;
    printf("Union as float: %f\n", d.f);
    printf("sizeof(Data)=%zu\n", sizeof(Data));

    /* Tagged union (Variant) */
    Variant v;
    v.type = TYPE_INT;
    v.val.ival = 42;
    if (v.type == TYPE_INT)
        printf("Variant int: %d\n", v.val.ival);

    v.type = TYPE_FLOAT;
    v.val.fval = 2.718f;
    if (v.type == TYPE_FLOAT)
        printf("Variant float: %.3f\n", v.val.fval);

    v.type = TYPE_STRING;
    strcpy(v.val.sval, "hello");
    if (v.type == TYPE_STRING)
        printf("Variant string: \"%s\"\n", v.val.sval);
}

/* ============================================================
 * SECTION 12: DYNAMIC MEMORY ALLOCATION
 * ============================================================ */

void section_dynamic_memory(void) {
    printf("\n===== DYNAMIC MEMORY =====\n");

    /* malloc */
    int n = 5;
    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) { perror("malloc"); return; }
    for (int i = 0; i < n; i++) arr[i] = (i+1) * 10;
    printf("malloc array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    /* realloc */
    int new_n = 10;
    int *arr2 = (int*)realloc(arr, new_n * sizeof(int));
    if (!arr2) { perror("realloc"); free(arr); return; }
    arr = arr2;
    for (int i = n; i < new_n; i++) arr[i] = (i+1) * 10;
    printf("realloc array: ");
    for (int i = 0; i < new_n; i++) printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    arr = NULL;

    /* calloc – zero-initialized */
    double *dbls = (double*)calloc(5, sizeof(double));
    if (!dbls) { perror("calloc"); return; }
    printf("calloc (zero): ");
    for (int i = 0; i < 5; i++) printf("%.1f ", dbls[i]);
    printf("\n");
    free(dbls);

    /* Dynamic 2D array */
    int rows = 3, cols = 4;
    int **mat = (int**)malloc(rows * sizeof(int*));
    for (int r = 0; r < rows; r++) {
        mat[r] = (int*)malloc(cols * sizeof(int));
        for (int c = 0; c < cols; c++)
            mat[r][c] = r * cols + c;
    }
    printf("Dynamic 2D:\n");
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) printf("%3d", mat[r][c]);
        printf("\n");
    }
    for (int r = 0; r < rows; r++) free(mat[r]);
    free(mat);

    /* Dynamic struct */
    Person *p = (Person*)malloc(sizeof(Person));
    if (p) {
        strcpy(p->name, "Dynamic Alice");
        p->age = 25;
        p->gpa = 3.9;
        person_print(p);
        free(p);
    }

    /* Dynamic array of structs */
    int cnt = 3;
    Person *people = (Person*)calloc(cnt, sizeof(Person));
    if (people) {
        strcpy(people[0].name, "A"); people[0].age = 20;
        strcpy(people[1].name, "B"); people[1].age = 22;
        strcpy(people[2].name, "C"); people[2].age = 21;
        for (int i = 0; i < cnt; i++) person_print(&people[i]);
        free(people);
    }
}

/* ============================================================
 * SECTION 13: SORTING AND SEARCHING
 * ============================================================ */

/* Bubble sort */
void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                SWAP(arr[j], arr[j+1], int);
}

/* Selection sort */
void selection_sort(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx]) min_idx = j;
        SWAP(arr[i], arr[min_idx], int);
    }
}

/* Insertion sort */
void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) { arr[j+1] = arr[j]; j--; }
        arr[j+1] = key;
    }
}

/* Merge sort */
static void merge(int *arr, int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int *L = (int*)malloc(n1*sizeof(int));
    int *R = (int*)malloc(n2*sizeof(int));
    for (int i=0;i<n1;i++) L[i]=arr[l+i];
    for (int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while (i<n1 && j<n2) arr[k++] = (L[i]<=R[j]) ? L[i++] : R[j++];
    while (i<n1) arr[k++]=L[i++];
    while (j<n2) arr[k++]=R[j++];
    free(L); free(R);
}
void merge_sort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

/* Quick sort */
static int partition(int *arr, int lo, int hi) {
    int pivot = arr[hi], i = lo - 1;
    for (int j = lo; j < hi; j++)
        if (arr[j] <= pivot) SWAP(arr[++i], arr[j], int);
    SWAP(arr[i+1], arr[hi], int);
    return i + 1;
}
void quick_sort(int *arr, int lo, int hi) {
    if (lo < hi) {
        int pi = partition(arr, lo, hi);
        quick_sort(arr, lo, pi-1);
        quick_sort(arr, pi+1, hi);
    }
}

/* Binary search */
int binary_search(const int *arr, int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target)  lo = mid + 1;
        else                    hi = mid - 1;
    }
    return -1;
}

/* Linear search */
int linear_search(const int *arr, int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target) return i;
    return -1;
}

/* qsort comparator */
int int_compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void section_sorting_searching(void) {
    printf("\n===== SORTING AND SEARCHING =====\n");

    int a[] = {64,34,25,12,22,11,90};
    int n = ARRAY_SIZE(a);

    /* Bubble sort */
    int b[7]; memcpy(b,a,sizeof(a));
    bubble_sort(b,n);
    printf("Bubble:    "); for(int i=0;i<n;i++) printf("%d ",b[i]); printf("\n");

    /* Selection sort */
    memcpy(b,a,sizeof(a));
    selection_sort(b,n);
    printf("Selection: "); for(int i=0;i<n;i++) printf("%d ",b[i]); printf("\n");

    /* Insertion sort */
    memcpy(b,a,sizeof(a));
    insertion_sort(b,n);
    printf("Insertion: "); for(int i=0;i<n;i++) printf("%d ",b[i]); printf("\n");

    /* Merge sort */
    memcpy(b,a,sizeof(a));
    merge_sort(b,0,n-1);
    printf("Merge:     "); for(int i=0;i<n;i++) printf("%d ",b[i]); printf("\n");

    /* Quick sort */
    memcpy(b,a,sizeof(a));
    quick_sort(b,0,n-1);
    printf("Quick:     "); for(int i=0;i<n;i++) printf("%d ",b[i]); printf("\n");

    /* stdlib qsort */
    memcpy(b,a,sizeof(a));
    qsort(b,n,sizeof(int),int_compare);
    printf("qsort:     "); for(int i=0;i<n;i++) printf("%d ",b[i]); printf("\n");

    /* Binary search on sorted array */
    int idx = binary_search(b, n, 34);
    printf("BinarySearch(34)=%d\n", idx);

    /* Linear search */
    idx = linear_search(a, n, 22);
    printf("LinearSearch(22)=%d\n", idx);
}

/* ============================================================
 * SECTION 14: LINKED LIST
 * ============================================================ */

typedef struct Node {
    int          data;
    struct Node *next;
} Node;

Node* node_create(int data) {
    Node *n = (Node*)malloc(sizeof(Node));
    if (n) { n->data = data; n->next = NULL; }
    return n;
}

Node* list_push_front(Node *head, int data) {
    Node *n = node_create(data);
    n->next = head;
    return n;
}

Node* list_push_back(Node *head, int data) {
    Node *n = node_create(data);
    if (!head) return n;
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return head;
}

Node* list_remove(Node *head, int data) {
    if (!head) return NULL;
    if (head->data == data) {
        Node *next = head->next;
        free(head);
        return next;
    }
    Node *cur = head;
    while (cur->next && cur->next->data != data)
        cur = cur->next;
    if (cur->next) {
        Node *del = cur->next;
        cur->next = del->next;
        free(del);
    }
    return head;
}

void list_print(const Node *head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

Node* list_reverse(Node *head) {
    Node *prev=NULL, *cur=head, *next=NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int list_length(const Node *head) {
    int len = 0;
    while (head) { len++; head = head->next; }
    return len;
}

void list_free(Node *head) {
    while (head) { Node *n = head->next; free(head); head = n; }
}

/* Merge two sorted lists */
Node* list_merge_sorted(Node *a, Node *b) {
    if (!a) return b;
    if (!b) return a;
    if (a->data <= b->data) { a->next = list_merge_sorted(a->next, b); return a; }
    else                    { b->next = list_merge_sorted(a, b->next); return b; }
}

void section_linked_list(void) {
    printf("\n===== LINKED LIST =====\n");

    Node *head = NULL;
    for (int i = 5; i >= 1; i--)
        head = list_push_front(head, i * 10);
    printf("List: "); list_print(head);
    printf("Length: %d\n", list_length(head));

    head = list_push_back(head, 60);
    printf("After push_back(60): "); list_print(head);

    head = list_remove(head, 30);
    printf("After remove(30): "); list_print(head);

    head = list_reverse(head);
    printf("Reversed: "); list_print(head);

    list_free(head);
}

/* ============================================================
 * SECTION 15: STACK (using linked list)
 * ============================================================ */

typedef struct {
    Node *top;
    int   size;
} Stack;

void stack_init(Stack *s)        { s->top=NULL; s->size=0; }
void stack_push(Stack *s, int v) { s->top=list_push_front(s->top,v); s->size++; }
int  stack_empty(Stack *s)       { return s->top==NULL; }
int  stack_peek(Stack *s)        { return s->top ? s->top->data : 0; }
int  stack_pop(Stack *s) {
    if (!s->top) return 0;
    int v = s->top->data;
    Node *old = s->top;
    s->top = s->top->next;
    free(old);
    s->size--;
    return v;
}
void stack_free(Stack *s) { list_free(s->top); s->top=NULL; s->size=0; }

void section_stack(void) {
    printf("\n===== STACK =====\n");
    Stack s;
    stack_init(&s);
    for (int i = 1; i <= 5; i++) {
        stack_push(&s, i * 11);
        printf("Pushed %d (top=%d, size=%d)\n", i*11, stack_peek(&s), s.size);
    }
    printf("Pop sequence: ");
    while (!stack_empty(&s)) printf("%d ", stack_pop(&s));
    printf("\n");

    /* Use stack to check balanced brackets */
    const char *expr = "{[()]}";
    Stack bs; stack_init(&bs);
    bool balanced = true;
    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];
        if (ch=='(' || ch=='[' || ch=='{') {
            stack_push(&bs, ch);
        } else if (ch==')' || ch==']' || ch=='}') {
            if (stack_empty(&bs)) { balanced=false; break; }
            int top = stack_pop(&bs);
            if ((ch==')' && top!='(') ||
                (ch==']' && top!='[') ||
                (ch=='}' && top!='{')) { balanced=false; break; }
        }
    }
    balanced = balanced && stack_empty(&bs);
    printf("Expression \"%s\" balanced: %s\n", expr, balanced?"yes":"no");
    stack_free(&bs);
}

/* ============================================================
 * SECTION 16: QUEUE (using linked list)
 * ============================================================ */

typedef struct {
    Node *front;
    Node *rear;
    int   size;
} Queue;

void queue_init(Queue *q) { q->front=q->rear=NULL; q->size=0; }
int  queue_empty(Queue *q){ return q->front==NULL; }

void queue_enqueue(Queue *q, int v) {
    Node *n = node_create(v);
    if (!q->rear) { q->front=q->rear=n; }
    else { q->rear->next=n; q->rear=n; }
    q->size++;
}

int queue_dequeue(Queue *q) {
    if (!q->front) return 0;
    int v = q->front->data;
    Node *old = q->front;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(old);
    q->size--;
    return v;
}

void queue_free(Queue *q) {
    list_free(q->front);
    q->front=q->rear=NULL;
    q->size=0;
}

void section_queue(void) {
    printf("\n===== QUEUE =====\n");
    Queue q;
    queue_init(&q);
    for (int i=1; i<=5; i++) {
        queue_enqueue(&q, i*7);
        printf("Enqueued %d (size=%d)\n", i*7, q.size);
    }
    printf("Dequeue sequence: ");
    while (!queue_empty(&q)) printf("%d ", queue_dequeue(&q));
    printf("\n");
}

/* ============================================================
 * SECTION 17: BINARY SEARCH TREE
 * ============================================================ */

typedef struct TreeNode {
    int              data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* bst_insert(TreeNode *root, int val) {
    if (!root) {
        TreeNode *n = (TreeNode*)malloc(sizeof(TreeNode));
        n->data=val; n->left=n->right=NULL;
        return n;
    }
    if      (val < root->data) root->left  = bst_insert(root->left,  val);
    else if (val > root->data) root->right = bst_insert(root->right, val);
    return root;
}

void bst_inorder(const TreeNode *root) {
    if (!root) return;
    bst_inorder(root->left);
    printf("%d ", root->data);
    bst_inorder(root->right);
}

void bst_preorder(const TreeNode *root) {
    if (!root) return;
    printf("%d ", root->data);
    bst_preorder(root->left);
    bst_preorder(root->right);
}

void bst_postorder(const TreeNode *root) {
    if (!root) return;
    bst_postorder(root->left);
    bst_postorder(root->right);
    printf("%d ", root->data);
}

int bst_search(const TreeNode *root, int val) {
    if (!root) return 0;
    if (val == root->data) return 1;
    if (val <  root->data) return bst_search(root->left,  val);
    return                        bst_search(root->right, val);
}

int bst_height(const TreeNode *root) {
    if (!root) return 0;
    int lh = bst_height(root->left);
    int rh = bst_height(root->right);
    return 1 + MAX(lh, rh);
}

void bst_free(TreeNode *root) {
    if (!root) return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}

void section_bst(void) {
    printf("\n===== BINARY SEARCH TREE =====\n");
    int vals[] = {50,30,70,20,40,60,80,10,25,35,45};
    TreeNode *root = NULL;
    for (int i=0; i<(int)ARRAY_SIZE(vals); i++)
        root = bst_insert(root, vals[i]);

    printf("In-order:   "); bst_inorder(root);   printf("\n");
    printf("Pre-order:  "); bst_preorder(root);  printf("\n");
    printf("Post-order: "); bst_postorder(root); printf("\n");
    printf("Height: %d\n", bst_height(root));
    printf("Search(40)=%d, Search(99)=%d\n",
           bst_search(root,40), bst_search(root,99));
    bst_free(root);
}

/* ============================================================
 * SECTION 18: BIT MANIPULATION
 * ============================================================ */

void section_bit_manipulation(void) {
    printf("\n===== BIT MANIPULATION =====\n");

    unsigned int n = 0b10110101;

    /* Set bit k */
    #define SET_BIT(n,k)   ((n) |  (1u << (k)))
    /* Clear bit k */
    #define CLR_BIT(n,k)   ((n) & ~(1u << (k)))
    /* Toggle bit k */
    #define TGL_BIT(n,k)   ((n) ^  (1u << (k)))
    /* Test bit k */
    #define TST_BIT(n,k)   (((n) >> (k)) & 1u)

    printf("n        = 0x%02X (%u)\n", n, n);
    printf("SET_BIT 2= 0x%02X\n", SET_BIT(n,2));
    printf("CLR_BIT 4= 0x%02X\n", CLR_BIT(n,4));
    printf("TGL_BIT 0= 0x%02X\n", TGL_BIT(n,0));
    printf("TST_BIT 5= %u\n", TST_BIT(n,5));

    /* Count set bits (popcount) */
    unsigned int tmp = n, cnt = 0;
    while (tmp) { cnt += tmp & 1; tmp >>= 1; }
    printf("popcount(%u)=%u\n", n, cnt);

    /* Brian Kernighan's bit count */
    tmp = n; cnt = 0;
    while (tmp) { tmp &= tmp-1; cnt++; }
    printf("Kernighan popcount(%u)=%u\n", n, cnt);

    /* Check power of 2 */
    for (unsigned int v=0; v<=16; v++)
        if ((v & (v-1)) == 0 && v != 0)
            printf("%u is power of 2\n", v);

    /* Swap without temp */
    int a=13, b=27;
    a^=b; b^=a; a^=b;
    printf("XOR swap: a=%d, b=%d\n", a, b);

    /* Reverse bits of byte */
    unsigned char byte = 0b10110100, rev=0;
    for (int i=0;i<8;i++) { rev=(rev<<1)|(byte&1); byte>>=1; }
    printf("Reversed bits of 0b10110100 = 0b");
    for (int i=7;i>=0;i--) printf("%d",(rev>>i)&1);
    printf("\n");

    /* Isolate lowest set bit */
    unsigned int m = 0b10110100;
    printf("Lowest set bit of 0x%X = 0x%X\n", m, m & (-(int)m));

    /* Bit masking */
    unsigned int flags = 0;
    #define FLAG_A (1u << 0)
    #define FLAG_B (1u << 1)
    #define FLAG_C (1u << 2)
    flags |= FLAG_A | FLAG_C;
    printf("Flags: A=%d, B=%d, C=%d\n",
           !!(flags&FLAG_A), !!(flags&FLAG_B), !!(flags&FLAG_C));
}

/* ============================================================
 * SECTION 19: FILE I/O
 * ============================================================ */

void section_file_io(void) {
    printf("\n===== FILE I/O =====\n");

    const char *fname = "/tmp/c_demo.txt";

    /* Write text file */
    FILE *fp = fopen(fname, "w");
    if (!fp) { perror("fopen write"); return; }
    fprintf(fp, "Line 1: Hello, File!\n");
    fprintf(fp, "Line 2: Number = %d\n", 42);
    fprintf(fp, "Line 3: Pi = %.6f\n", PI);
    for (int i = 0; i < 5; i++)
        fprintf(fp, "Data %d %d\n", i, i*i);
    fclose(fp);
    printf("Wrote to %s\n", fname);

    /* Read text file line by line */
    fp = fopen(fname, "r");
    if (!fp) { perror("fopen read"); return; }
    printf("Reading %s:\n", fname);
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0'; /* strip newline */
        printf("  > %s\n", line);
    }
    fclose(fp);

    /* fscanf */
    fp = fopen(fname, "r");
    if (fp) {
        /* skip 3 header lines */
        for (int i=0;i<3;i++) fgets(line, sizeof(line), fp);
        printf("Parsed data pairs: ");
        int idx, val;
        while (fscanf(fp, "Data %d %d\n", &idx, &val) == 2)
            printf("(%d,%d) ", idx, val);
        printf("\n");
        fclose(fp);
    }

    /* Binary file I/O */
    const char *bfname = "/tmp/c_demo.bin";
    double data[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int nd = ARRAY_SIZE(data);

    fp = fopen(bfname, "wb");
    if (fp) {
        fwrite(&nd, sizeof(int), 1, fp);
        fwrite(data, sizeof(double), nd, fp);
        fclose(fp);
    }

    fp = fopen(bfname, "rb");
    if (fp) {
        int rd_n;
        fread(&rd_n, sizeof(int), 1, fp);
        double rd_data[10];
        fread(rd_data, sizeof(double), rd_n, fp);
        printf("Binary read %d doubles: ", rd_n);
        for (int i=0;i<rd_n;i++) printf("%.1f ", rd_data[i]);
        printf("\n");
        fclose(fp);
    }

    /* fseek / ftell / rewind */
    fp = fopen(fname, "r");
    if (fp) {
        fseek(fp, 0, SEEK_END);
        long size = ftell(fp);
        printf("File size: %ld bytes\n", size);
        rewind(fp);
        int firstchar = fgetc(fp);
        printf("First char: '%c'\n", firstchar);
        fclose(fp);
    }

    /* Append mode */
    fp = fopen(fname, "a");
    if (fp) {
        fprintf(fp, "Appended line.\n");
        fclose(fp);
    }

    /* Cleanup */
    remove(fname);
    remove(bfname);
}

/* ============================================================
 * SECTION 20: RECURSION EXAMPLES
 * ============================================================ */

/* Tower of Hanoi */
void hanoi(int n, char from, char to, char via) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n-1, from, via, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n-1, via, to, from);
}

/* Power set (all subsets) */
void power_set(int *set, int n, int *subset, int idx, int sub_idx) {
    /* Print current subset */
    printf("{");
    for (int i=0;i<sub_idx;i++) printf("%d%s",subset[i],i<sub_idx-1?",":"");
    printf("} ");

    for (int i=idx;i<n;i++) {
        subset[sub_idx]=set[i];
        power_set(set,n,subset,i+1,sub_idx+1);
    }
}

/* Permutations */
void permute(int *arr, int lo, int hi) {
    if (lo==hi) {
        for (int i=lo;i<=hi;i++) printf("%d ",arr[i]);
        printf("| ");
        return;
    }
    for (int i=lo;i<=hi;i++) {
        SWAP(arr[lo],arr[i],int);
        permute(arr,lo+1,hi);
        SWAP(arr[lo],arr[i],int);
    }
}

/* Binary search recursive */
int bsearch_rec(const int *arr, int lo, int hi, int target) {
    if (lo>hi) return -1;
    int mid=lo+(hi-lo)/2;
    if (arr[mid]==target) return mid;
    if (arr[mid]<target)  return bsearch_rec(arr,mid+1,hi,target);
    return                       bsearch_rec(arr,lo,mid-1,target);
}

/* Flatten nested sum: sum of digits recursively */
int digit_sum(int n) {
    if (n < 0) n = -n;
    if (n < 10) return n;
    return n%10 + digit_sum(n/10);
}

void section_recursion(void) {
    printf("\n===== RECURSION =====\n");

    printf("Hanoi(3 disks):\n");
    hanoi(3,'A','C','B');

    int set[]={1,2,3}, subset[3];
    printf("Power set of {1,2,3}: ");
    power_set(set,3,subset,0,0);
    printf("\n");

    int perm[]={1,2,3};
    printf("Permutations of {1,2,3}: ");
    permute(perm,0,2);
    printf("\n");

    int sorted[]={2,5,8,12,16,23,38,56,72,91};
    printf("Recursive BSearch(23)=%d\n",
           bsearch_rec(sorted,0,9,23));

    printf("digit_sum(9875)=%d\n", digit_sum(9875));
}

/* ============================================================
 * SECTION 21: MATH FUNCTIONS
 * ============================================================ */

void section_math(void) {
    printf("\n===== MATH FUNCTIONS =====\n");

    printf("sqrt(2)=%.6f\n",     sqrt(2.0));
    printf("cbrt(27)=%.6f\n",    cbrt(27.0));
    printf("pow(2,10)=%.0f\n",   pow(2,10));
    printf("exp(1)=%.6f\n",      exp(1.0));
    printf("log(e)=%.6f\n",      log(EULER));
    printf("log2(1024)=%.0f\n",  log2(1024.0));
    printf("log10(1000)=%.0f\n", log10(1000.0));
    printf("fabs(-3.7)=%.1f\n",  fabs(-3.7));
    printf("ceil(3.2)=%.0f\n",   ceil(3.2));
    printf("floor(3.9)=%.0f\n",  floor(3.9));
    printf("round(3.5)=%.0f\n",  round(3.5));
    printf("fmod(10,3)=%.1f\n",  fmod(10.0,3.0));
    printf("sin(PI/2)=%.6f\n",   sin(PI/2));
    printf("cos(0)=%.6f\n",      cos(0.0));
    printf("tan(PI/4)=%.6f\n",   tan(PI/4));
    printf("atan2(1,1)=%.6f\n",  atan2(1.0,1.0));
    printf("hypot(3,4)=%.1f\n",  hypot(3.0,4.0));
    printf("ldexp(1,10)=%.0f\n", ldexp(1.0,10));

    /* Integer math */
    printf("MAX(13,27)=%d\n",    MAX(13,27));
    printf("MIN(13,27)=%d\n",    MIN(13,27));
    printf("ABS(-99)=%d\n",      ABS(-99));
    printf("CLAMP(150,0,100)=%d\n", CLAMP(150,0,100));

    /* Random numbers */
    srand((unsigned)time(NULL));
    printf("Random ints (1-100): ");
    for (int i=0;i<5;i++) printf("%d ", (rand()%100)+1);
    printf("\n");
}

/* ============================================================
 * SECTION 22: TIME AND DATE
 * ============================================================ */

void section_time(void) {
    printf("\n===== TIME AND DATE =====\n");

    time_t now = time(NULL);
    printf("time_t now=%ld\n", (long)now);

    struct tm *local = localtime(&now);
    printf("Local: %04d-%02d-%02d %02d:%02d:%02d\n",
           local->tm_year+1900, local->tm_mon+1, local->tm_mday,
           local->tm_hour, local->tm_min, local->tm_sec);

    char buf[64];
    strftime(buf, sizeof(buf), "%A, %B %d %Y %H:%M:%S", local);
    printf("Formatted: %s\n", buf);

    struct tm *utc = gmtime(&now);
    printf("UTC: %04d-%02d-%02d %02d:%02d:%02d\n",
           utc->tm_year+1900, utc->tm_mon+1, utc->tm_mday,
           utc->tm_hour, utc->tm_min, utc->tm_sec);

    /* clock – measure CPU time */
    clock_t start = clock();
    volatile long sum = 0;
    for (long i=0;i<10000000L;i++) sum+=i;
    clock_t end = clock();
    printf("CPU time for loop: %.4f s\n",
           (double)(end-start)/CLOCKS_PER_SEC);
    printf("Sum=%ld\n", sum);
}

/* ============================================================
 * SECTION 23: TYPE CASTING AND TYPE CONVERSION
 * ============================================================ */

void section_type_casting(void) {
    printf("\n===== TYPE CASTING =====\n");

    /* Implicit conversions */
    int    i   = 65;
    double d   = i;         /* int -> double */
    char   c   = (char)i;   /* int -> char (explicit) */
    printf("int %d -> double %.1f -> char '%c'\n", i, d, c);

    /* Integer division vs floating point */
    int a=7, b=2;
    printf("7/2=%d (int div)\n", a/b);
    printf("7/2=%.4f (fp div)\n", (double)a/b);
    printf("7/2=%.4f (fp div2)\n", a/(double)b);

    /* Truncation */
    double pi = 3.99;
    int trunc_pi = (int)pi;
    printf("(int)3.99=%d\n", trunc_pi);

    /* Unsigned / signed */
    unsigned int u = 4294967295U;
    int si = (int)u;
    printf("uint %u -> int %d\n", u, si);

    /* Pointer casting */
    float f = 3.14f;
    unsigned int *ip = (unsigned int*)&f;
    printf("float 3.14f bits: 0x%08X\n", *ip);

    /* char arithmetic */
    char ch = 'a';
    printf("'a'+1='%c', 'z'-'a'=%d\n", ch+1, 'z'-'a');

    /* Integer promotion */
    char x=200, y=100;
    int sum = x + y;  /* promoted to int */
    printf("char 200 + char 100 = %d (as int)\n", sum);
}

/* ============================================================
 * SECTION 24: PREPROCESSOR ADVANCED
 * ============================================================ */

/* Multi-line macro */
#define FOR_EACH(i, lo, hi) \
    for (int i = (lo); i < (hi); i++)

/* Generic max using _Generic (C11) */
#define generic_max(a,b) _Generic((a), \
    int:    MAX(a,b),                  \
    double: (double)MAX(a,b),          \
    float:  (float)MAX(a,b)            \
)

/* X-macro trick */
#define COLOR_LIST \
    X(RED,   0) \
    X(GREEN, 1) \
    X(BLUE,  2)

typedef enum {
#define X(name, val) CLRX_##name = val,
    COLOR_LIST
#undef X
} ColorX;

static const char* ColorX_names[] = {
#define X(name, val) #name,
    COLOR_LIST
#undef X
};

void section_preprocessor(void) {
    printf("\n===== PREPROCESSOR =====\n");

    printf("PI = " TOSTRING(PI) "\n");
    printf("File: %s, Line: %d\n", __FILE__, __LINE__);
    printf("Date: %s, Time: %s\n", __DATE__, __TIME__);
    printf("Function: %s\n", __func__);

    FOR_EACH(i, 0, 5) printf("i=%d ", i);
    printf("\n");

    printf("generic_max(3,5)=%d\n", generic_max(3,5));
    printf("generic_max(3.1,2.9)=%g\n", generic_max(3.1,2.9));

    /* X-macro */
    for (int i=0;i<3;i++)
        printf("Color %d = %s\n", i, ColorX_names[i]);

    /* Stringification */
    #define PRINT_EXPR(expr) printf(#expr " = %d\n", expr)
    PRINT_EXPR(2+3*4);
    PRINT_EXPR(sizeof(long long));

    LOG("Debug message %d", 42);
}

/* ============================================================
 * SECTION 25: ERROR HANDLING AND ASSERTIONS
 * ============================================================ */

/* Custom error codes */
typedef enum {
    ERR_OK     =  0,
    ERR_NULL   = -1,
    ERR_BOUNDS = -2,
    ERR_DIV0   = -3,
    ERR_ALLOC  = -4,
} ErrCode;

const char* err_to_str(ErrCode e) {
    switch (e) {
        case ERR_OK:     return "OK";
        case ERR_NULL:   return "NULL pointer";
        case ERR_BOUNDS: return "Out of bounds";
        case ERR_DIV0:   return "Division by zero";
        case ERR_ALLOC:  return "Allocation failed";
        default:         return "Unknown error";
    }
}

ErrCode safe_divide(int a, int b, int *result) {
    if (!result) return ERR_NULL;
    if (b == 0)  return ERR_DIV0;
    *result = a / b;
    return ERR_OK;
}

void section_error_handling(void) {
    printf("\n===== ERROR HANDLING =====\n");

    int result;
    ErrCode e;

    e = safe_divide(10, 2, &result);
    printf("10/2: err=%s, result=%d\n", err_to_str(e), result);

    e = safe_divide(10, 0, &result);
    printf("10/0: err=%s\n", err_to_str(e));

    e = safe_divide(10, 2, NULL);
    printf("NULL result: err=%s\n", err_to_str(e));

    /* errno */
    FILE *fp = fopen("/nonexistent/path/file.txt", "r");
    if (!fp) printf("fopen error: %s (errno=%d)\n", strerror(errno), errno);

    /* assert */
    int x = 42;
    assert(x == 42);  /* passes */
    printf("assert(x==42) passed\n");
    /* assert(x == 0); would abort */

    /* perror example */
    errno = ENOMEM;
    perror("perror example");
}

/* ============================================================
 * SECTION 26: MISCELLANEOUS USEFUL PATTERNS
 * ============================================================ */

/* Sieve of Eratosthenes */
void sieve_of_eratosthenes(int limit) {
    bool *is_prime_arr = (bool*)calloc(limit+1, sizeof(bool));
    for (int i=2;i<=limit;i++) is_prime_arr[i]=true;
    for (int i=2;(long)i*i<=limit;i++)
        if (is_prime_arr[i])
            for (int j=i*i;j<=limit;j+=i)
                is_prime_arr[j]=false;
    printf("Primes up to %d: ", limit);
    int count=0;
    for (int i=2;i<=limit;i++)
        if (is_prime_arr[i]) { printf("%d ",i); count++; }
    printf("(count=%d)\n", count);
    free(is_prime_arr);
}

/* Matrix multiplication */
void matrix_multiply(const int A[][3], const int B[][3],
                     int C[][3], int n) {
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) {
            C[i][j]=0;
            for (int k=0;k<n;k++) C[i][j]+=A[i][k]*B[k][j];
        }
}

/* Run-length encoding */
void run_length_encode(const char *s) {
    int len = strlen(s);
    printf("RLE of \"%s\": ", s);
    for (int i=0;i<len;) {
        char ch=s[i]; int cnt=0;
        while (i<len && s[i]==ch) { cnt++; i++; }
        printf("%d%c", cnt, ch);
    }
    printf("\n");
}

/* Caesar cipher */
void caesar_cipher(char *s, int shift) {
    shift = ((shift % 26) + 26) % 26;
    for (int i=0;s[i];i++) {
        if (isupper((unsigned char)s[i]))
            s[i] = 'A' + (s[i]-'A'+shift)%26;
        else if (islower((unsigned char)s[i]))
            s[i] = 'a' + (s[i]-'a'+shift)%26;
    }
}

/* Number base conversion */
void print_in_base(unsigned int n, int base) {
    if (base<2||base>36) return;
    const char digits[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char buf[64]; int idx=0;
    if (n==0) { printf("0"); return; }
    while (n>0) { buf[idx++]=digits[n%base]; n/=base; }
    for (int i=idx-1;i>=0;i--) putchar(buf[i]);
}

void section_misc(void) {
    printf("\n===== MISCELLANEOUS =====\n");

    sieve_of_eratosthenes(50);

    /* Matrix multiply */
    int A[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int B[3][3]={{9,8,7},{6,5,4},{3,2,1}};
    int C[3][3];
    matrix_multiply(A,B,C,3);
    printf("Matrix A*B:\n");
    for (int r=0;r<3;r++) {
        for (int c=0;c<3;c++) printf("%4d",C[r][c]);
        printf("\n");
    }

    run_length_encode("aaabbbccddddeeee");
    run_length_encode("abcde");

    char msg[]="Hello, World!";
    caesar_cipher(msg,13);
    printf("ROT13(\"%s\")=\"%s\"\n","Hello, World!",msg);
    caesar_cipher(msg,13);
    printf("ROT13 back: \"%s\"\n",msg);

    /* Base conversion */
    unsigned int num=255;
    printf("%u in base 2:  "); print_in_base(num,2);  printf("\n");
    printf("%u in base 8:  "); print_in_base(num,8);  printf("\n");
    printf("%u in base 16: "); print_in_base(num,16); printf("\n");

    /* Integer limits */
    printf("INT_MAX=%d, UINT_MAX=%u\n", INT_MAX, UINT_MAX);
    printf("LLONG_MAX=%lld\n", LLONG_MAX);
    printf("FLT_EPSILON=%g, DBL_EPSILON=%g\n", FLT_EPSILON, DBL_EPSILON);
}

/* ============================================================
 * SECTION 27: STORAGE CLASSES AND LINKAGE
 * ============================================================ */

void demonstrate_static(void) {
    static int call_count = 0;  /* retains value between calls */
    call_count++;
    printf("static call_count=%d\n", call_count);
}

void section_storage_classes(void) {
    printf("\n===== STORAGE CLASSES =====\n");

    /* auto (default for local variables) */
    auto int x = 10;
    printf("auto x=%d\n", x);

    /* register hint */
    register int r = 42;
    printf("register r=%d\n", r);

    /* static local */
    for (int i=0;i<4;i++) demonstrate_static();

    /* extern - referencing global */
    extern int extern_example;
    printf("extern_example=%d\n", extern_example);

    /* volatile */
    volatile int v = 0;
    v = 1;
    printf("volatile v=%d\n", v);

    /* const */
    const double e = EULER;
    printf("const e=%.10f\n", e);
}

/* ============================================================
 * SECTION 28: INLINE FUNCTIONS AND RESTRICT
 * ============================================================ */

static inline int clamp_int(int v, int lo, int hi) {
    return v<lo ? lo : v>hi ? hi : v;
}

static inline double deg_to_rad(double deg) {
    return deg * PI / 180.0;
}

/* restrict – tells compiler pointers don't alias */
void vec_add(const double * restrict a,
             const double * restrict b,
             double       * restrict c,
             int n) {
    for (int i=0;i<n;i++) c[i]=a[i]+b[i];
}

void section_inline_restrict(void) {
    printf("\n===== INLINE AND RESTRICT =====\n");
    printf("clamp_int(150,0,100)=%d\n", clamp_int(150,0,100));
    printf("deg_to_rad(180)=%.6f\n", deg_to_rad(180.0));

    double a[]={1,2,3,4,5}, b[]={5,4,3,2,1}, c[5];
    vec_add(a,b,c,5);
    printf("vec_add: ");
    for(int i=0;i<5;i++) printf("%.0f ",c[i]);
    printf("\n");
}

/* ============================================================
 * SECTION 29: COMMON PATTERNS
 * ============================================================ */

/* Circular buffer */
#define CIRBUF_SIZE 8
typedef struct {
    int  buf[CIRBUF_SIZE];
    int  head, tail, count;
} CircBuf;

void cbuf_init(CircBuf *cb) { cb->head=cb->tail=cb->count=0; }
int  cbuf_full(CircBuf *cb) { return cb->count==CIRBUF_SIZE; }
int  cbuf_empty(CircBuf *cb){ return cb->count==0; }

bool cbuf_push(CircBuf *cb, int val) {
    if (cbuf_full(cb)) return false;
    cb->buf[cb->head] = val;
    cb->head = (cb->head+1) % CIRBUF_SIZE;
    cb->count++;
    return true;
}

bool cbuf_pop(CircBuf *cb, int *val) {
    if (cbuf_empty(cb)) return false;
    *val = cb->buf[cb->tail];
    cb->tail = (cb->tail+1) % CIRBUF_SIZE;
    cb->count--;
    return true;
}

/* Observer / callback pattern */
typedef void (*Callback)(int event, void *ctx);

typedef struct {
    Callback  callbacks[8];
    void     *contexts[8];
    int       count;
} EventBus;

void bus_subscribe(EventBus *bus, Callback cb, void *ctx) {
    if (bus->count<8) {
        bus->callbacks[bus->count]=cb;
        bus->contexts[bus->count]=ctx;
        bus->count++;
    }
}

void bus_emit(EventBus *bus, int event) {
    for (int i=0;i<bus->count;i++)
        bus->callbacks[i](event, bus->contexts[i]);
}

static void my_handler(int event, void *ctx) {
    printf("Handler A received event=%d ctx=%s\n", event, (char*)ctx);
}
static void my_handler2(int event, void *ctx) {
    printf("Handler B received event=%d ctx=%p\n", event, ctx);
}

void section_patterns(void) {
    printf("\n===== DESIGN PATTERNS =====\n");

    /* Circular buffer */
    CircBuf cb;
    cbuf_init(&cb);
    for (int i=1;i<=6;i++) cbuf_push(&cb,i*10);
    printf("CircBuf pop: ");
    int val;
    while (cbuf_pop(&cb,&val)) printf("%d ",val);
    printf("\n");

    /* Event bus */
    EventBus bus = {.count=0};
    bus_subscribe(&bus, my_handler,  "context1");
    bus_subscribe(&bus, my_handler2, NULL);
    bus_emit(&bus, 42);
}

/* ============================================================
 * SECTION 30: MAIN ENTRY POINT
 * ============================================================ */

int main(int argc, char *argv[]) {
    printf("============================================================\n");
    printf(" COMPREHENSIVE C LANGUAGE REFERENCE\n");
    printf(" Compiled: %s %s\n", __DATE__, __TIME__);
    printf("============================================================\n");

    if (argc > 1) {
        printf("Arguments (%d):\n", argc);
        for (int i=0;i<argc;i++)
            printf("  argv[%d] = \"%s\"\n", i, argv[i]);
    }

    section_data_types();
    section_operators();
    section_control_flow();
    section_functions();
    section_arrays();
    section_strings();
    section_pointers();
    section_structs();
    section_unions_enums();
    section_dynamic_memory();
    section_sorting_searching();
    section_linked_list();
    section_stack();
    section_queue();
    section_bst();
    section_bit_manipulation();
    section_file_io();
    section_recursion();
    section_math();
    section_time();
    section_type_casting();
    section_preprocessor();
    section_error_handling();
    section_misc();
    section_storage_classes();
    section_inline_restrict();
    section_patterns();

    printf("\n============================================================\n");
    printf(" ALL SECTIONS COMPLETE\n");
    printf("============================================================\n");

    return EXIT_SUCCESS;
}
