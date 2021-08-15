import pandas as pd
import numpy as np

all_data = pd.read_csv('forest_dataset.csv')
print(all_data.head())

labels = all_data[all_data.columns[-1]].values
print('Labels = ', labels, '\n')

feature_matrix = all_data[all_data.columns[:-1]].values
print('Feature matrix = \n', feature_matrix, '\n')

''' Обучение модели '''
from sklearn.model_selection import train_test_split

train_feature_matrix, test_feature_matrix, train_labels, test_labels = train_test_split(feature_matrix, labels,
                                                                                        test_size=0.2, random_state=42)
print('train_feature_matrix = \n', train_feature_matrix, '\n')
print('train_feature_matrix.shape = ', train_feature_matrix.shape, '\n')                # (8000, 54)

print('test_feature_matrix = \n', test_feature_matrix, '\n')
print('test_feature_matrix.shape = ', test_feature_matrix.shape, '\n')                  # (2000, 54)

from sklearn.neighbors import KNeighborsClassifier

clf = KNeighborsClassifier()                                                            # Создаем модель
clf.fit(train_feature_matrix, train_labels)                                             # Обучаем модель
y_pred = clf.predict(test_feature_matrix)                                               # Предсказываем

from sklearn.metrics import accuracy_score

ex = accuracy_score(test_labels, y_pred)                                                # Определяем точность
print('Точность предсказаний = ', ex, '\n')                                             # 0.7365


# Подберем лучшие параметры для нашей модели
from sklearn.model_selection import GridSearchCV

params = {
    'n_neighbors': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    'metric': ['manhattan', 'euclidean'],
    'weights': ['uniform', 'distance']
}

# clf = KNeighborsClassifier()
# clf_grid = GridSearchCV(clf, params, cv=5, scoring='accuracy', n_jobs=-1)
# clf_grid.fit(train_feature_matrix, train_labels)

# print(clf_grid.best_params_)                      # {'metric': 'manhattan', 'n_neighbors': 4, 'weights': 'distance'}

optimal_clf = KNeighborsClassifier(metric='manhattan', n_neighbors=4, weights='distance')
optimal_clf.fit(train_feature_matrix, train_labels)
pred_prob = optimal_clf.predict_proba(test_feature_matrix)

print('pred_prob = \n', pred_prob, '\n')

pred_freq = pred_prob.mean(axis=0)
print('pred_freq = \n', pred_freq, '\n')

# import matplotlib.pyplot as plt
# # %matplotlib inline
#
# unique, freq = np.unique(test_labels, return_counts=True)
# freq = list(map(lambda x: x / len(test_labels),freq))
#
# pred_freq = pred_prob.mean(axis=0)
# plt.figure(figsize=(10, 8))
# plt.bar(range(1, 8), pred_freq, width=0.4, align="edge", label='prediction')
# plt.bar(range(1, 8), freq, width=-0.4, align="edge", label='real')
# plt.ylim(0, 0.54)
# plt.legend()
# plt.show()

