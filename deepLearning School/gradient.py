import numpy as np
import math
import sympy as sp

# Функция, которую дают на вход
def func(x):
     return x[0] ** 2 + x[1]

def derivX(func, vector):
     eps = 1e-6
     newVec = [vector[0] + eps, vector[1]]
     return (func(newVec) - func(vector)) / eps

def derivY(func, vector):
     eps = 1e-6
     newVec = [vector[0], vector[1] + eps]
     return (func(newVec) - func(vector)) / eps


# Функция, которая находит считаем ближайший минимум к координате
def onePoint(func, anotherVector):
     lr = 0.0001
     derX = derivX(func, anotherVector)
     derY = derivY(func, anotherVector)
     count = 0

     while math.fabs(derX) > 1e-6 and math.fabs(derY) > 1e-6:
          anotherVector[0] -= lr * derX
          anotherVector[1] -= lr * derY

          derX = derivX(func, anotherVector)
          derY = derivY(func, anotherVector)

          count += 1
          if count > 200000: break
     return anotherVector, func(anotherVector)

# Функция, которая находит минимум на всем отрезке по одной координате
def grad_descent_2d(func, low, high, callback=None):
     low = [-5, -5]
     high = [5, 5]

     stepX = abs(high[0] - low[0]) / 20
     stepY = abs(high[1] - low[1]) / 20
     myVector = [low[0], low[1]]
     minVector = [low[0], low[1]]
     minF = func(myVector)

     while myVector[0] < high[0]:
          newVector, newF = onePoint(func, myVector.copy())
          if newF < minF:
               minF = newF
               minVector = newVector

          myVector[0] += stepX
          myVector[1] += stepY
     return minVector[0], minVector[1]

print(grad_descent_2d(func, 12, 2))





# Функция, которая находит частную производную
# arg - по какой переменной дифферинцируем
# vector - словарь координат текущей точки
def deriv(func, arg, vector):
     arg = sp.Symbol(arg)
     x = sp.Symbol('x')
     y = sp.Symbol('y')
     symVector = {'x': x, 'y': y}
     f = sp.diff(func(symVector), arg)
     ans = f.subs(x, vector['x'])
     ans = ans.subs(y, vector['y'])
     return ans


# Функция, которая находит считаем ближайший минимум к координате
def onePoin(func, vector):
     lr = 0.0001
     derX = deriv(func, 'x', vector)
     derY = deriv(func, 'y', vector)
     count = 0

     while math.fabs(derX) > 1e-6 and math.fabs(derY) > 1e-6:
          vector['x'] -= lr * derX
          vector['y'] -= lr * derY

          derX = deriv(func, 'x', vector)
          derY = deriv(func, 'y', vector)

          count += 1
          if count > 200000: break

     return vector, func(vector['x'], vector['y'])