import numpy as np
import tensorflow as tf
from tensorflow.keras.preprocessing.text import Tokenizer
from tensorflow.keras.preprocessing.sequence import pad_sequences

# Load the dinosaur names dataset
with open("dinos.txt") as f:
    dinos = f.readlines()
dinos = [x.lower().strip() for x in dinos]

# Create a tokenizer and fit it on the dinosaur names
tokenizer = Tokenizer(char_level=True)
tokenizer.fit_on_texts(dinos)

# Convert the dinosaur names to sequences of integers
sequences = tokenizer.texts_to_sequences(dinos)

# Pad the sequences so they all have the same length
maxlen = max([len(x) for x in sequences])
padded_sequences = pad_sequences(sequences, maxlen=maxlen, padding="post")

# Split the sequences into input and output
X = padded_sequences[:, :-1]
y = padded_sequences[:, 1:]

# Define the model architecture
model = tf.keras.Sequential([
    tf.keras.layers.Embedding(input_dim=len(
        tokenizer.word_index)+1, output_dim=64),
    tf.keras.layers.LSTM(128, return_sequences=True),
    tf.keras.layers.Dropout(0.2),
    tf.keras.layers.LSTM(128),
    tf.keras.layers.Dropout(0.2),
    tf.keras.layers.Dense(len(tokenizer.word_index)+1, activation="softmax")
])

# Compile the model
model.compile(loss="sparse_categorical_crossentropy",
              optimizer="adam", metrics=["accuracy"])

# Train the model
model.fit(X, y, epochs=100)

# Generate new dinosaur names using the model
for i in range(10):
    name = ""
    while len(name) < maxlen-1:
        x = np.zeros((1, maxlen-1))
        x[0, :len(name)] = [tokenizer.word_index[c] for c in name]
        pred = model.predict(x)[0]
        next_char = tokenizer.index_word[np.argmax(pred)]
        name += next_char
    print(name.capitalize())
