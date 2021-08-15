import pandas as pd
import numpy as np

all_data = pd.read_csv('forest_dataset.csv')
print(all_data.head())

# Тырим значения метки класса (насколько я поняла, последний столбец)
labels = all_data[all_data.columns[-1]].values
print('Labels = ', labels, '\n')

# Тырим признаковые описания (все кроме названия строк/столбцов и кроме последнего столбца)
feature_matrix = all_data[all_data.columns[:-1]].values
print('Feature matrix = \n', feature_matrix, '\n')


''' Работа со sklean '''

# Разделим данные на train и test
from sklearn.model_selection import train_test_split

train_feature_matrix, test_feature_matrix, train_labels, test_labels = train_test_split(feature_matrix, labels,
                                                                                        test_size=0.2, random_state=42)
# test_size - контролирует какая часть сета будет тестовой, в данном случае 20%

print('train_feature_matrix = \n', train_feature_matrix, '\n')
print('train_feature_matrix.shape = ', train_feature_matrix.shape, '\n')                # (8000, 54)

print('test_feature_matrix = \n', test_feature_matrix, '\n')
print('test_feature_matrix.shape = ', test_feature_matrix.shape, '\n')                  # (2000, 54)


# Основные обьекты в sklearn - estimators, фактически модели. У каждой есть как минимум два метода - fit и predict
#       fit(X, y) - обучает модель на основе обучающей выборки в виде матрицы признаков Х и вектора ответов у
#       predict(X) - возвращает предсказание на всех обьектах матрицы Х в виде вектора

from sklearn.linear_model import LogisticRegression

clf = LogisticRegression(C=1)                                   # Создание модели с указванием гиперпараметра С
clf.fit(train_feature_matrix, train_labels)                     # Обучение модели
y_pred = clf.predict(test_feature_matrix)                       # Предсказание на тестовой выборке

print('y_pred = ', y_pred, '\n')

# Измерение качества модели
from sklearn.metrics import accuracy_score

ex = accuracy_score(test_labels, y_pred)                        # Альтернатива метод score(X, y)
print('Точность предсказаний = ', ex, '\n')


# Перебор гиперпараметров по сетке
from sklearn.model_selection import GridSearchCV

clf = LogisticRegression(solver='saga')             # Заново создадим модель

param_grid = {                                      # Опишем сетку, по которой будем искать
    'C': [1, 2, 3, 4],
    'penalty': ['l1', 'l2']
}

search = GridSearchCV(clf, param_grid, n_jobs=-1, cv=5, refit=True, scoring='accuracy')  # создадим объект GridSearchCV

search.fit(feature_matrix, labels)                  # Запустим поиск

print(search.best_params_)                          # Выведем наилучшие параметры

print(accuracy_score(labels, search.best_estimator_.predict(feature_matrix)))           # Выведем точность