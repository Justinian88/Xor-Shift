# Xor-Shift
Семейство Xor-Shift генераторов 

Используемая библиотека для больших чисел [LibTomMath](https://www.libtom.net/LibTomMath/)

 ## Теоретическое описание
 
Xorshift - семейство генераторов регистров сдвига, представляют собой класс генераторов псевдослучайных чисел , впервые описанных Джорджем Марсалья. Подробное описание алгоритмов и рекомендуемых к использованию констант приведенов в [статье](https://www.jstatsoft.org/article/view/v008i14) Дж. Марсалья.
 
Помимо наиболее популярных xorshift32 и xorshift64 генераторов были реализованы генераторы 
 
 ## Представленные генераторы
 
1) XorShift32: имеет одно 32-битное слово состояния и период 2 32 -1. 

```C
mp_err mp_xorshift_32 (int *a, int *b, int *c, mp_int *num) MP_WUR;
```

2) XorShift64: имеет одно 64-битное слово состояния и период 2 64 -1.

```C
mp_err mp_xorshift_64 (int *a, int *b, int *c, mp_int *num) MP_WUR;
```

3)
4)
5)

## Библиотека LibTomMath

Все генераторы псевдослучайных чисел реализованы в стилистике бибилиотеки LibTomMath. Функции возвращают значение типа mp_err - сообщение об ошибке. Также в случае если возвращаемое значение не присваивается ни одной переменной, будет реализовано предупреждение MP_WUR - warn unused result.

## Какие файлы были добавлены

### wiki.h

Добавлены инициализации описанных ранее генераторов псевдослучайных чисел.

### wiki.c

Реализации генераторов для библиотеки LibTomMath.

### xor.h



### const.h

Содержатся значения seed для генераторов. Для удобства были вынесены в оотдельный файл с константами.

### main.c



## Тесты
