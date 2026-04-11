#You are given multiple documents, each represented as a set of words. Your task is to compute the set of words that appear in exactly one document.
#Author - Vedika Udgir

doc1 = {"apple", "banana", "cherry"}
doc2 = {"banana", "dragonfruit", "orange"} 
doc3 = {"strawberry", "grape", "apple"}

uniqueWords = (doc1 ^ doc2) ^ doc3
print(uniqueWords)