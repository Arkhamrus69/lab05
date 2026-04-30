# Отчет по лабораторной работе №5

## Тема лабораторной работы

Изучение фреймворков для тестирования на примере **Google Test / GTest**.

## Цель работы

Целью данной лабораторной работы является подключение фреймворка Google Test к C++ проекту, настройка сборки тестов через CMake, создание тестового файла и запуск тестов локально.

---

Очередные вводные данные:
<pre>
$ export GITHUB_USERNAME=Arkhamrus69
$ alias gsed=sed # for *-nix system</pre>

Клогнирование лабы 5 очевидно

## Переход в рабочую директорию

```bash
cd "/home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05" 
```
## Cохранение пути
```bash
$ pushd .
```
<details> <summary> Мини вывод </summary>
~/Рабочий стол/arkhamrus69@gmail.com/workspace ~/Рабочий стол/arkhamrus69@gmail.com/workspace

</details>

##  Проверка состояния Git
```bash
$ git status
```


## Проверка удаленного репозитория
```bash
$ git remote -v
```



## Удаление старого origin

```bash
$ git remote remove origin
```

## Добавление нового origin

```bash
$ git remote add origin https://github.com/arkhamrus69/lab05.git
```

## Создание папки для сторонних библиотек

```bash
$ mkdir -p third-party
```

## Подключение Google Test

```bash
$ git submodule add https://github.com/google/googletest third-party/gtest
```

## Переход в папку Google Test

```bash
$ cd third-party/gtest
```

## Переключение Google Test на версию release-1.8.1

```bash
$ git checkout release-1.8.1
```

## Возврат в корень проекта

```bash
$ cd ../..
```

## Добавление Google Test в Git

```bash
$ git add .gitmodules third-party/gtest
```

## Коммит подключения Google Test

```bash
$ git commit -m "added gtest framework"
```

## Создание папки для тестов

```bash
$ mkdir -p tests
```

## Создание файла tests/test1.cpp

```bash
$ cat > tests/test1.cpp <<'EOF'
#include <gtest/gtest.h>

TEST(Example, BasicTest)
{
    EXPECT_EQ(1, 1);
}
EOF
```

## Содержимое файла tests/test1.cpp

```cpp
#include <gtest/gtest.h>

TEST(Example, BasicTest)
{
    EXPECT_EQ(1, 1);
}
```


Были проблемы с gtest, поэтому совместно с gpt в начале вставили в tests/test1.cpp, чтобы проверить:
<pre>
tests/test1.cpp существует
CMake его видит
gtest подключился
check собирается
ctest запускается
</pre>



<details> <summary> Тестов приколов с не тем кодом... </summary>
  <pre>
[  5%] Building CXX object third-party/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 10%] Linking CXX static library libgtest.a
[ 10%] Built target gtest
[ 15%] Building CXX object third-party/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 20%] Linking CXX static library libgtest_main.a
[ 20%] Built target gtest_main
[ 25%] Building CXX object formatter_lib/CMakeFiles/formatter.dir/formatter.cpp.o
[ 30%] Linking CXX static library libformatter.a
[ 30%] Built target formatter
[ 35%] Building CXX object formatter_ex_lib/CMakeFiles/formatter_ex.dir/formatter_ex.cpp.o
[ 40%] Linking CXX static library libformatter_ex.a
[ 40%] Built target formatter_ex
[ 45%] Building CXX object solver_lib/CMakeFiles/solver_lib.dir/solver.cpp.o
[ 50%] Linking CXX static library libsolver_lib.a
[ 50%] Built target solver_lib
[ 55%] Building CXX object CMakeFiles/check.dir/tests/test1.cpp.o
[ 60%] Linking CXX executable check
[ 60%] Built target check
[ 65%] Building CXX object hello_world/CMakeFiles/hello_world.dir/main.cpp.o
[ 70%] Linking CXX executable hello_world
[ 70%] Built target hello_world
[ 75%] Building CXX object solver/CMakeFiles/solver.dir/main.cpp.o
[ 80%] Linking CXX executable solver
[ 80%] Built target solver
[ 85%] Building CXX object third-party/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 90%] Linking CXX static library libgmock.a
[ 90%] Built target gmock
[ 95%] Building CXX object third-party/gtest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library libgmock_main.a
[100%] Built target gmock_main</pre>
</details>



<details> <summary>ctest --test-dir _build --verbose</summary>
  <pre>
  Internal ctest changing into directory: /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build
UpdateCTestConfiguration  from :/home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build/DartConfiguration.tcl
UpdateCTestConfiguration  from :/home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build/DartConfiguration.tcl
Test project /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: check

1: Test command: /home/vboxuser/Рабочий\ стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build/check
1: Working Directory: /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build
1: Test timeout computed to be: 10000000
1: Running main() from /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/third-party/gtest/googletest/src/gtest_main.cc
1: [==========] Running 1 test from 1 test case.
1: [----------] Global test environment set-up.
1: [----------] 1 test from Example
1: [ RUN      ] Example.BasicTest
1: [       OK ] Example.BasicTest (0 ms)
1: [----------] 1 test from Example (0 ms total)
1: 
1: [----------] Global test environment tear-down
1: [==========] 1 test from 1 test case ran. (0 ms total)
1: [  PASSED  ] 1 test.
1/1 Test #1: check ............................   Passed    0.00 sec
100% tests passed, 0 tests failed out of 1</pre>
</details>


## Приколы с изменением нашего текста:
```bash
/home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/tests/test1.cpp: In member function ‘virtual void FormatterEx_FormatString_Test::TestBody()’:
/home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/tests/test1.cpp:15:26: error: ‘formatter_ex’ was not declared in this scope; did you mean ‘formatter’?
   15 |     std::string result = formatter_ex("hello");
      |                          ^~~~~~~~~~~~
      |                          formatter
In file included from /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/third-party/gtest/googletest/include/gtest/gtest.h:382,
                 from /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/tests/test1.cpp:1:
/home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/tests/test1.cpp: In member function ‘virtual void Solver_LinearEquation_Test::TestBody()’:
/home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/tests/test1.cpp:22:29: error: request for member ‘first’ in ‘result’, which is of non-class type ‘double’
   22 |     EXPECT_DOUBLE_EQ(result.first, 1);
      |                             ^~~~~
/home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/tests/test1.cpp:23:29: error: request for member ‘second’ in ‘result’, which is of non-class type ‘double’
   23 |     EXPECT_DOUBLE_EQ(result.second, 1);
      |                             ^~~~~~
gmake[2]: *** [CMakeFiles/check.dir/build.make:79: CMakeFiles/check.dir/tests/test1.cpp.o] Ошибка 1
gmake[1]: *** [CMakeFiles/Makefile2:275: CMakeFiles/check.dir/all] Ошибка 2
gmake: *** [Makefile:146: all] Ошибка 2
```

функции formatter_ex() нет...
Заменим на:
```bash
#include <gtest/gtest.h>

#include <formatter.h>
#include <solver.h>

#include <string>

TEST(Formatter, FormatString)
{
    std::string result = formatter("hello");

    EXPECT_FALSE(result.empty());
}

TEST(Solver, QuadraticEquation)
{
    double result = solve(1, -2, 1);

    EXPECT_DOUBLE_EQ(result, 1);
}
```

## WIN
```bash
[  5%] Building CXX object third-party/gtest/googlemock/gtest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
[ 10%] Linking CXX static library libgtest.a
[ 10%] Built target gtest
[ 15%] Building CXX object third-party/gtest/googlemock/gtest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
[ 20%] Linking CXX static library libgtest_main.a
[ 20%] Built target gtest_main
[ 25%] Building CXX object formatter_lib/CMakeFiles/formatter.dir/formatter.cpp.o
[ 30%] Linking CXX static library libformatter.a
[ 30%] Built target formatter
[ 35%] Building CXX object formatter_ex_lib/CMakeFiles/formatter_ex.dir/formatter_ex.cpp.o
[ 40%] Linking CXX static library libformatter_ex.a
[ 40%] Built target formatter_ex
[ 45%] Building CXX object solver_lib/CMakeFiles/solver_lib.dir/solver.cpp.o
[ 50%] Linking CXX static library libsolver_lib.a
[ 50%] Built target solver_lib
[ 55%] Building CXX object CMakeFiles/check.dir/tests/test1.cpp.o
[ 60%] Linking CXX executable check
[ 60%] Built target check
[ 65%] Building CXX object hello_world/CMakeFiles/hello_world.dir/main.cpp.o
[ 70%] Linking CXX executable hello_world
[ 70%] Built target hello_world
[ 75%] Building CXX object solver/CMakeFiles/solver.dir/main.cpp.o
[ 80%] Linking CXX executable solver
[ 80%] Built target solver
[ 85%] Building CXX object third-party/gtest/googlemock/CMakeFiles/gmock.dir/src/gmock-all.cc.o
[ 90%] Linking CXX static library libgmock.a
[ 90%] Built target gmock
[ 95%] Building CXX object third-party/gtest/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
[100%] Linking CXX static library libgmock_main.a
[100%] Built target gmock_main
```
<details> <summary>ctest --test-dir _build --verbose</summary>
  <pre>
Internal ctest changing into directory: /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build
UpdateCTestConfiguration  from :/home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build/DartConfiguration.tcl
UpdateCTestConfiguration  from :/home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build/DartConfiguration.tcl
Test project /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: check
1: Test command: /home/vboxuser/Рабочий\ стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build/check
1: Working Directory: /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/_build
1: Test timeout computed to be: 10000000
1: Running main() from /home/vboxuser/Рабочий стол/arkhamrus69@gmail.com/workspace/projects/lab05/third-party/gtest/googletest/src/gtest_main.cc
1: [==========] Running 2 tests from 2 test cases.
1: [----------] Global test environment set-up.
1: [----------] 1 test from Formatter
1: [ RUN      ] Formatter.FormatString
1: [       OK ] Formatter.FormatString (0 ms)
1: [----------] 1 test from Formatter (0 ms total)
1: 
1: [----------] 1 test from Solver
1: [ RUN      ] Solver.QuadraticEquation
1: [       OK ] Solver.QuadraticEquation (0 ms)
1: [----------] 1 test from Solver (0 ms total)
1: 
1: [----------] Global test environment tear-down
1: [==========] 2 tests from 2 test cases ran. (0 ms total)
1: [  PASSED  ] 2 tests.
1/1 Test #1: check ............................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec
</details>

Два коммита, которые пропали

<img width="1397" height="800" alt="Снимок экрана 2026-04-30 в 12 22 55" src="https://github.com/user-attachments/assets/8326e1c5-4e24-472f-95f1-711d201bb369" />
<img width="1407" height="122" alt="Снимок экрана 2026-04-30 в 12 23 05" src="https://github.com/user-attachments/assets/e37cae95-6b45-49af-ab1c-0b2e628f1eab" />


Дальше все понятно
