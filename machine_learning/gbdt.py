#!/bin/bash/python

from sklearn.datasets import make_hastie_10_2
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.ensemble import GradientBoostingRegressor

X,y = make_hastie_10_2(random_state=0)
X_train, X_test = X[:2000], X[2000:]
y_train, y_test = y[:2000], y[2000:]

#class sklearn.ensemble.GradientBoostingClassifier(loss=’deviance’, learning_rate=0.1, n_estimators=100, subsample=1.0,\
#criterion=’friedman_mse’, min_samples_split=2, min_samples_leaf=1, min_weight_fraction_leaf=0.0, max_depth=3,\
#min_impurity_decrease=0.0, min_impurity_split=None, init=None, random_state=None, max_features=None, verbose=0,\
#max_leaf_nodes=None, warm_start=False, presort=’auto’))

#clf = GradientBoostingRegressor(n_estimators=100, learning_rate=1.0 , \
clf = GradientBoostingClassifier(n_estimators=100, learning_rate=1.0 , \
max_depth=1, random_state=0).fit(X_train, y_train)

#target = 'Disbursed'
#print X['Disbursed'].value_counts()

print clf.score(X_test, y_test)
