# Implement your function below.
def non_repeating(given_string):
    input_dict = {}
    for element in given_string:
        if element not in input_dict:
            input_dict[element] = 1
        else:
            input_dict[element] +=1
    item = None
    for element in input_dict:
        if input_dict[element] == 1:
            item = element
    
    return item
  
# NOTE: The following input values will be used for testing your solution.
print(non_repeating("abcab")) # should return 'c'
print(non_repeating("abab")) # should return None
print(non_repeating("aabbbc")) # should return 'c'
print(non_repeating("aabbdbc")) # should return 'd'
