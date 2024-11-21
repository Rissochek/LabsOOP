cmake_minimum_required(VERSION 3.10)

# Устанавливаем имя проекта
project(NPCFactoryProject)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем поддержку Google Test
add_subdirectory(googletest)

# Указываем каталоги с исходными файлами
include_directories(
    lib/NpcLib
    lib/ObserverLib
    lib/UtillsLib
    lib/FactoryLib
    lib/VisitorLib
)

# Источники проекта
set(SOURCES
    main.cpp
    lib/NpcLib/Npc.cpp
    lib/ObserverLib/Observer.cpp
    lib/UtillsLib/Utills.cpp
    lib/FactoryLib/Factory.cpp
    lib/VisitorLib/Visitor.cpp
)

# Создаем общую библиотеку для проекта (этот код будет использоваться как в основном проекте, так и в тестах)
add_library(NPCFactoryLibrary STATIC ${SOURCES})

# Создаем исполнимый файл для основного проекта
add_executable(NPCFactoryProject main.cpp)

# Линкуем библиотеку с основным проектом
target_link_libraries(NPCFactoryProject NPCFactoryLibrary)

# Указываем тестовые файлы
set(TEST_SOURCES
    tests.cpp
)

# Создаем исполнимый файл для тестов
add_executable(NPCFactoryProjectTests ${TEST_SOURCES})

# Линкуем gtest и gtest_main с тестами
target_link_libraries(NPCFactoryProjectTests gtest gtest_main NPCFactoryLibrary)

# Добавляем тесты для запуска
enable_testing()
add_test(NAME MyTests COMMAND NPCFactoryProjectTests)


file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})