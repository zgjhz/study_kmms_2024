#!/bin/bash

# Вид сборки / суффикс в названии каталога сборки
#
# "Ninja" / "ninja"
# "Visual Studio 17 2022" / "visual_studio"
#
BUILD_TYPE="Ninja"
BUILD_SUFFIX="ninja"

export LANG=en_US.UTF-8

BUILD_FOLDER="build_${BUILD_SUFFIX}"
SOURCE_FOLDER="projects"

# Проверяем существование каталога и создаем его при необходимости
if [ ! -d "${BUILD_FOLDER}" ]; then
  mkdir "${BUILD_FOLDER}"
fi

cd "${BUILD_FOLDER}"

# Запускаем CMake для конфигурации проекта
cmake -G "${BUILD_TYPE}" "../${SOURCE_FOLDER}"
cmake --build .

# Копируем файлы, если это необходимо
cp "../${SOURCE_FOLDER}/bubble_sort/run_bubble_sort.sh" "./bubble_sort"
cp "../${SOURCE_FOLDER}/bubble_sort_mf/run_bubble_sort_mf.sh" "./bubble_sort_mf"

# Возвращаемся в исходный каталог
cd -
