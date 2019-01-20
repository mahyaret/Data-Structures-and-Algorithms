import copy
import queue
import math

# Implement your function below.
# n = # rows = # columns in the given 2d array
def rotate(given_array, n):
    # rotated = copy.deepcopy(given_array)
    # NOTE: To solve it in place, write this function so that you
    # won't have to create rotated.
    temp_items = [-1]*4
    for i in range(math.ceil(n/2)):
        for j in range(math.floor(n/2)):
            (current_i,current_j) = (i,j)
            for t in range(4):
                temp_items[t] = given_array[current_i][current_j]
                (current_i,current_j) = sub_rotate(current_i,current_j,n)
            for t in range(4):
                given_array[current_i][current_j] = temp_items[(t+3)%4]
                (current_i,current_j) = sub_rotate(current_i,current_j,n)
    return given_array



def sub_rotate(i,j,n):
    return j,n-1-i
                    
# NOTE: Feel free to use the following function for testing.
# It converts a 2-dimensional array (a list of lists) into
# an easy-to-read string format.
def to_string(given_array):
    list_rows = []
    for row in given_array:
        list_rows.append(str(row))
    return '[' + ',\n '.join(list_rows) + ']'



# NOTE: The following input values will be used for testing your solution.
a1 = [[1, 2, 3],
      [4, 5, 6],
      [7, 8, 9]]
print(to_string(rotate(a1, 3))) #should return:
# [[7, 4, 1],
#  [8, 5, 2],
#  [9, 6, 3]]

a2 = [[1, 2, 3, 4],
      [5, 6, 7, 8],
      [9, 10, 11, 12],
      [13, 14, 15, 16]]
print(to_string(rotate(a2, 4))) #should return:
# [[13, 9, 5, 1],
#  [14, 10, 6, 2],
#  [15, 11, 7, 3],
#  [16, 12, 8, 4]]

