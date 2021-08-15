import numpy as np
import pandas as pd
import scipy.linalg as sla
import matplotlib.pyplot as plt

from sklearn import datasets
from sklearn.linear_model import LinearRegression, Lasso, Ridge

# f = sin(x1)**2 + sin(x2)**2...
# x - вектор (х1, х2, ...)
def f(x):
    return np.sum(np.sin(x)**2)

# Мы хоти найти минимум этой функции, то есть x1 и x2 такие, что f(x1, x2) минимальна.

# Частные производные вычислим аналитически
def defiv(xn):
    return np.sin(2 * xn)

# Градиент функции f, определенной выше
def grad_f(x):
    return np.array([defiv(xi) for xi in x])


def grad_descent_2d(f, grad_f, lr, num_iter=100, x0=None, n=2):
    """
    функция, которая реализует градиентный спуск в минимум для функции f от двух переменных.
        :param f: скалярная функция двух переменных
        :param grad_f: градиент функции f (вектор размерности 2)
        :param lr: learning rate алгоритма
        :param num_iter: количество итераций градиентного спуска
        :return: np.array[num_iter, 2] пар вида (x, f(x))
        :n: количество переменных в векторе x
    """
    if x0 is None:
        x0 = np.random.random(n)

    # Будем сохранять значения аргументов и значений функции в процессе град. спуска в переменную history
    history = []

    # итерация цикла -- шаг градиентнго спуска
    currX = x0.copy()
    for iter_num in range(num_iter):
        entry = np.hstack((currX, f(currX)))        # Соединение массивов по горизонтали
        history.append(entry)

        currX -= lr * grad_f(currX)

    return np.vstack(history)    # Соединяет массивы по вертикали. Одномерные массивы соединяются построчно в двумерные

steps = grad_descent_2d(f, grad_f, lr=0.1, num_iter=20)

# Генерация батчей
def generate_batches(X, y, batch_size):
    """
    param X: np.array[n_objects, n_features] --- матрица объекты-признаки
    param y: np.array[n_objects] --- вектор целевых переменных
    param batch_size -- размер выборки
    """
    assert len(X) == len(y)
    np.random.seed(42)
    X = np.array(X)
    y = np.array(y)
    perm = np.random.permutation(len(X))            # Сгенерировали массив с номерами строк X в рандомном порядке
    count_batch = len(X) // batch_size              # Количество батчей, помещающихся в массив

    for i in range(count_batch):                    # Перебираем все возможные батчи
        start = i * batch_size                      # Индекс, с которого начинается очередной батч
        end = start + batch_size                    # Индекс, которым заканчивается очередной батч

        p = perm[start:end]                         # Выборка из массива рандомных строк
        new_x = X[p]                                # Берет строки из массива X в нужном диапазоне
        new_y = y[p]                                # Берет строки из массива y в нужном диапазоне
        yield (new_x, new_y)

def logit(x, w):
    return np.dot(x, w)

def sigmoid(h):
    return 1. / (1 + np.exp(-h))

class MyElasticLogisticRegression(object):
    def __init__(self, l1_coef, l2_coef):
        self.l1_coef = l1_coef
        self.l2_coef = l2_coef
        self.w = None

    def fit(self, X, y, epochs=10, lr=0.1, batch_size=100):
        n, k = X.shape
        if self.w is None:
            np.random.seed(42)
            self.w = np.random.randn(k + 1)                             # Вектор столбец в качестве весов

        X_train = np.concatenate((np.ones((n, 1)), X), axis=1)          # Добавляет в каждую строку 1 на первое место

        losses = []             # Положите в лист losses лосс на каждом батче. Не нужно усреднять лосс по эпохе.

        for i in range(epochs):
            for X_batch, y_batch in generate_batches(X_train, y, batch_size):
                self.w -= lr * self.get_grad(X_batch, y_batch, sigmoid(logit(X_batch, self.w)))
                scalXW = logit(X_batch, self.w)
                y_pred = sigmoid(scalXW)
                losses.append(self.__loss(y_batch, y_pred))
        return losses

    def get_grad(self, X_batch, y_batch, predictions):
        wc = np.copy(self.w)
        wc[0] = 0

        grad = X_batch.T @ (predictions - y_batch) / len(X_batch)
        grad += 2 * self.l2_coef * wc
        grad += self.l1_coef * np.sign(wc)

        return grad

    def predict_proba(self, X):
        n, k = X.shape
        X_ = np.concatenate((np.ones((n, 1)), X), axis=1)
        return sigmoid(logit(X_, self.w))

    def predict(self, X, threshold=0.5):
        return self.predict_proba(X) >= threshold

    def get_weights(self):
        return self.w.copy()

    def __loss(self, y, p):
        p = np.clip(p, 1e-10, 1 - 1e-10)        # Ограничение на размеры, все элементы больше 1 станут 1, меньше 0 - 0
        return -np.sum(y * np.log(p) + (1 - y) * np.log(1 - p))

a = MyElasticLogisticRegression(1, 2)
X = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
y = np.array([1, 2, 3])
a.fit(X, y, 1, 0.1, 2)
