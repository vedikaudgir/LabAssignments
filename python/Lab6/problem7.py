#Given two large datasets representing different product inventories from two warehouses, write a function to find the products available in both inventories.
#Author - Vedika Udgir

set1 = {"laptop", "mouse", "keyboard", "monitor"}
set2 = {"tablet", "mouse", "keyboard", "smartphone"}

def commonElements(set1, set2):
    return set1 & set2

common = commonElements(set1, set2)
print(common)