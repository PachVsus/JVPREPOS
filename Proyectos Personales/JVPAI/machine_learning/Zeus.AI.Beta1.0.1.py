# Machine learning model for Zeus.AI. A virtual assistant that helps you with your daily tasks. It has a masculine and powerful personality. It is a beta version.


# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import pickle
import os
import sys
import time
import datetime
import random
import math
# personality module
import sklearn
import transformers
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import LabelEncoder
from sklearn.preprocessing import OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.metrics import f1_score
from sklearn.metrics import precision_score
from sklearn.metrics import recall_score
from sklearn.metrics import classification_report
from sklearn.metrics import roc_auc_score
from sklearn.metrics import roc_curve
from sklearn.metrics import auc
from sklearn.metrics import mean_squared_error
from sklearn.metrics import r2_score
from sklearn.metrics import mean_absolute_error
from sklearn.metrics import median_absolute_error
from sklearn.metrics import explained_variance_score
from sklearn.metrics import max_error
from sklearn.metrics import mean_squared_log_error
from sklearn.metrics import mean_poisson_deviance
from sklearn.metrics import mean_gamma_deviance
from sklearn.metrics import mean_tweedie_deviance
from sklearn.metrics import mean_absolute_percentage_error
from sklearn.metrics import balanced_accuracy_score
from sklearn.metrics import cohen_kappa_score
from sklearn.metrics import matthews_corrcoef
from sklearn.metrics import hinge_loss
from sklearn.metrics import log_loss
from sklearn.metrics import brier_score_loss
from sklearn.metrics import zero_one_loss
from sklearn.metrics import jaccard_score
from sklearn.metrics import hamming_loss
from sklearn.metrics import accuracy_score
from sklearn.metrics import adjusted_mutual_info_score


from transformers import GPT2LMHeadModel, GPT2Tokenizer

# Cargar el modelo y el tokenizador
model_name = 'gpt2-medium'
model = GPT2LMHeadModel.from_pretrained(model_name)
tokenizer = GPT2Tokenizer.from_pretrained(model_name)

def generate_response(prompt, personality):
    # Combinar el prompt con la personalidad
    input_text = f"{personality}: {prompt}"
    inputs = tokenizer.encode(input_text, return_tensors='pt')
    
    # Generar la respuesta
    outputs = model.generate(inputs, max_length=100, num_return_sequences=1)
    response = tokenizer.decode(outputs[0], skip_special_tokens=True)
    
    return response

# Ejemplo de uso
prompt = "¿Cómo estás hoy campeón?"
personality = "Zeus.AI, un asistente virtual masculino y poderoso"
response = generate_response(prompt, personality)
print(response)

# Importing the dataset
dataset = pd.read_csv('Data.csv')
X = dataset.iloc[:, :-1].values
y = dataset.iloc[:, -1].values

# Encoding categorical data
labelencoder_X = LabelEncoder()
X[:, 0] = labelencoder_X.fit_transform(X[:, 0])
columnTransformer = ColumnTransformer([('encoder', OneHotEncoder(), [0])], remainder='passthrough')
X = np.array(columnTransformer.fit_transform(X), dtype = str)

# Splitting the dataset into the Training set and Test set
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)

# Feature Scaling
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

# Fitting the classifier to the Training set
classifier = Sequential()
classifier.add(Dense(units = 6, kernel_initializer = 'uniform', activation = 'relu', input_dim = 11))
classifier.add(Dense(units = 6, kernel_initializer = 'uniform', activation = 'relu'))
classifier.add(Dense(units = 1, kernel_initializer = 'uniform', activation = 'sigmoid'))
classifier.compile(optimizer = 'adam', loss = 'binary_crossentropy', metrics = ['accuracy'])
classifier.fit(X_train, y_train, batch_size = 10, epochs = 100)

# Setting personality and male mood traits
personality = "Zeus.AI, un asistente virtual masculino y poderoso"
mood = "serio"

# Main loop
while True:
    # Get user input
    prompt = input("You: ")
    
    # Generate response
    response = generate_response(prompt, personality)
    
    # Print response
    print(f"{personality}: {response}")
    
    # Check if user wants to exit
    if prompt.lower() == "exit":
        break

# Save the model
filename = 'finalized_model.sav'
pickle.dump(classifier, open(filename, 'wb'))
print("Model saved successfully")
