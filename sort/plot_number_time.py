from matplotlib import pyplot as plt
import pandas as pd
import numpy as np
import csv

t = []
y_bubble = []

for i in range(50):
    t.append(100*(i+1))

datafile = 'bubble_sort.csv'

with open(datafile, encoding='utf-8') as r_file:
    file_reader = csv.reader(r_file, delimiter=";")
    i = 0
    for row in file_reader:
        y_bubble.append(int(row[0].split(';')[1]))

for i in range(1, len(y_bubble)):
    if (y_bubble[i] * 5) < y_bubble[i-1]:
        y_bubble[i] *= 10

plt.plot(t, y_bubble, 'red', label='Пузырёк')
plt.legend()

y_insert = []
datafile = 'insert_sort.csv'

with open(datafile, encoding='utf-8') as r_file:
    file_reader = csv.reader(r_file, delimiter=";")
    i = 0
    for row in file_reader:
        y_insert.append(int(row[0].split(';')[1]))

for i in range(1, len(y_insert)):
    if (y_insert[i] * 5) < y_insert[i-1]:
        y_insert[i] *= 10

plt.plot(t, y_insert, 'blue', label='Вставки')
plt.legend()

y_merge = []
datafile = 'merge_sort.csv'

with open(datafile, encoding='utf-8') as r_file:
    file_reader = csv.reader(r_file, delimiter=";")
    i = 0
    for row in file_reader:
        y_merge.append(int(row[0].split(';')[1]))

for i in range(1, len(y_merge)):
    if (y_merge[i] * 5) < y_merge[i-1]:
        y_merge[i] *= 10

plt.plot(t, y_merge, 'green', label='Слияние')
plt.legend()

y_qsort = []
datafile = 'q_sort.csv'

with open(datafile, encoding='utf-8') as r_file:
    file_reader = csv.reader(r_file, delimiter=";")
    i = 0
    for row in file_reader:
        y_qsort.append(int(row[0].split(';')[1]))

for i in range(1, len(y_qsort)):
    if (y_qsort[i] * 5) < y_qsort[i-1]:
        y_qsort[i] *= 10

plt.plot(t, y_qsort, 'black', label='Быстрая сортировка')
plt.legend()

y_std = []
datafile = 'std_sort.csv'

with open(datafile, encoding='utf-8') as r_file:
    file_reader = csv.reader(r_file, delimiter=";")
    i = 0
    for row in file_reader:
        y_std.append(int(row[0].split(';')[1]))

for i in range(1, len(y_std)):
    if (y_std[i] * 5) < y_std[i-1]:
        y_std[i] *= 10

plt.plot(t, y_std, 'brown', label='Стандартная std::sort')
plt.legend()

y_stupid = []
datafile = 'stupid_sort.csv'

with open(datafile, encoding='utf-8') as r_file:
    file_reader = csv.reader(r_file, delimiter=";")
    i = 0
    for row in file_reader:
        y_stupid.append(int(row[0].split(';')[1]))

for i in range(1, len(y_stupid)):
    if (y_stupid[i] * 5) < y_stupid[i-1]:
        y_stupid[i] *= 10

plt.plot(t, y_stupid, 'yellow', label='Глупая гномья сортировка')
plt.legend()

plt.title('Зависимость времени работы от количества элементов')
plt.ylabel('t, мс.')
plt.xlabel('N, ед.')
plt.grid()
plt.show()
print(y_bubble)
