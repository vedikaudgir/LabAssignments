# #Write a function append_item(item, item_list=[]) that appends an item to a list and returns the list.
# i. Test this function by calling it multiple times with the same default argument.
# ii. Explain why the list retains its values across function calls.
# iii. Modify the function to avoid this behavior using None as the default argument.
#Author - Vedika Udgir

def append_item(item, item_list = []):
    if item_list is None:
        item_list = []
        # if the list was not defined it will define one.
    item_list.append(item)
    return item_list

myList = [1]
append_item(2, myList)
append_item(2, myList)
append_item(2, myList)
append_item("Hello", myList)
append_item("Gojo", myList)
append_item([1,2,3], myList)
print(myList)