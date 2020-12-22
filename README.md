# Xor-Shift
Семейство Xor-Shift генераторов 

Используемая библиотека для больших чисел [LibTomMath](https://www.libtom.net/LibTomMath/)

 ## Теоретическое описание
 
Xorshift - семейство генераторов регистров сдвига, представляют собой класс генераторов псевдослучайных чисел , впервые описанных Джорджем Марсалья. Подробное описание алгоритмов и рекомендуемых к использованию констант приведенов в [статье](https://www.jstatsoft.org/article/view/v008i14) Дж. Марсалья.
 
Помимо наиболее популярных xorshift32 и xorshift64 генераторов были реализованы генераторы xorwow и xoshiro_256ss, xoshiro_256p. Дdа последних помимо XOR и shift, так же используют функцию rotate. Описание этих генераторов псевдослучайных чисел были взяты из [работ](http://prng.di.unimi.it) Себастьяно Винья и Дэвида Блэкмана.
 
 ## Представленные генераторы
 
1) XorShift32: имеет одно 32-битное слово состояния и период 2^32 -1. 

```C
mp_err mp_xorshift_32 (int *a, int *b, int *c, mp_int *num) MP_WUR;
```

2) XorShift64: имеет одно 64-битное слово состояния и период 2^64 -1.

```C
mp_err mp_xorshift_64 (int *a, int *b, int *c, mp_int *num) MP_WUR;
```

3) Xorwow: имеет пять (шесть) 32-битных слов состояния и период до 2^192 −2^32.

```C
mp_err mp_xorwow (struct mp_xorwow_set *params, mp_int *num) MP_WUR;
```

4) Xoshiro256++: имеет четыре 64-битных слова состояния и период 2^256 -1.

```C
mp_err mp_xoshiro_256p (struct mp_xoshiro_set *params, mp_int *num) MP_WUR;
```

5) Xoshiro256**: имеет четыре 64-битных слова состояния и период 2^256 -1.

```C
mp_err mp_xoshiro_256ss (struct mp_xoshiro_set *params, mp_int *num) MP_WUR;
```

## Библиотека LibTomMath

Все генераторы псевдослучайных чисел реализованы в стилистике бибилиотеки LibTomMath. Функции возвращают значение типа mp_err - сообщение об ошибке. Также в случае если возвращаемое значение не присваивается ни одной переменной, будет реализовано предупреждение MP_WUR - warn unused result.

## Какие файлы были добавлены

### wiki.h

Добавлены инициализации описанных ранее генераторов псевдослучайных чисел.

Добавлена struct mp_xorwow_set для внутренних параметов состоятния генератора Xorwow.
 ```C
 struct mp_xorwow_set {
    mp_int x, y, z, w, v, d;
};
```

Добавлена struct mp_xoshiro_set для внутренних параметов состоятния генератора Xoshiro256++ и Xoshiro256**.
 ```C
 struct mp_xoshiro_set {
    mp_int a, b, c, d;
};
```

### wiki.c

Реализации генераторов для библиотеки LibTomMath.

### xor.h

Для проведения тестов и сравнения выработанных значений использовались фрагменты кода, приведенные автором в указанной ранее статье. 

### const.h

Содержатся значения seed и иных параметров для генераторов. Для удобства были вынесены в отдельный файл с константами.

```
#define MY_SEED_32 2463542
#define MY_SEED_64 8817264525252LL

// Параметры состояния для xorwow 32-bit
#define WOW_X 123456789
#define WOW_Y 362436069
#define WOW_Z 521288629
#define WOW_W 88675123
#define WOW_V 5783321
#define WOW_D 6615241

// Параметры состояния для xorshiro 256-bit
#define XOSHIRO_1 44674407370955LL
#define XOSHIRO_2 38817264525252LL
#define XOSHIRO_3 12345678909876LL
#define XOSHIRO_4 337711884509LL
```

## Тесты
См. файл main.c

Можно заметить, что для небольших значений параметров и зерна генераторы предложенные Дж. Марсалья работают одинаково как без использования сторонних библиотек, так с и ними. Тем не менее при изменении параметров для теста 1 TEST 32-bit integer (a = 7, b = 17, c = 21) можно заметить отклонения в полученных генераторами значених. Это связано непостредственно с использованием библиотеки LibTomMath для больших чисел.

![alt text](https://sun9-47.userapi.com/impf/5ou0BJkeM04x2vxVy5bMUMlyVUrdHEs9aWP92g/YtFgeSAaeQY.jpg?size=584x686&quality=96&proxy=1&sign=8b4942d349976036213a38eb6d951a17&type=album)

![alt text](https://sun9-11.userapi.com/impf/Oyc2fJNsQJoSfp_ErmgPLonD9wY8-efipJXDHA/DtnsWLcYH6A.jpg?size=732x296&quality=96&proxy=1&sign=14b7a1531436d2914511d2f6ee37f6ea&type=album)
