
## Continuous Integration

Проект настроен на автоматическую сборку с помощью GitHub Actions на платформах:
- **Linux** (gcc, clang)
- **macOS** (clang)

При каждом push и pull request запускается сборка и тесты.
Чтобы запустить это чудо на Винде: 
1. В матрицу os добавить windows-latest.
2. Для Windows включить компилятор MSVC (cl.exe) в разделе include.
3. Для Windows добавить шаг установки CMake через choco (chocolatey).
4. В шагах запуска разделены команды для разных ОС: для Unix используется ./, для Windows — .\...\.exe.
