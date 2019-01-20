# Implement your function below.
def is_one_away(s1, s2):
    if abs(len(s1)-len(s2))>1:
        return False
    
    j = 0
    i = 0
    count = 0
    if len(s1) == len(s2):
        for i in range(0,len(s1)):
            if s1[i] != s2[i]:
                count +=1
            if count > 1:
                return False
    else:
        while i<len(s1):
            if j<len(s2) and s1[i] == s2[j]:
                j += 1
            else:
                j += 2
                count += 1
            i += 1
            if count>1:
                return False
    return True

    # NOTE: The following input values will be used for testing your solution.
print(is_one_away("abcde", "abcd"))  # should return True
print(is_one_away("abde", "abcde"))  # should return True
print(is_one_away("a", "a"))  # should return True
print(is_one_away("abcdef", "abqdef"))  # should return True
print(is_one_away("abcdef", "abccef"))  # should return True
print(is_one_away("abcdef", "abcde"))  # should return True
print(is_one_away("aaa", "abc"))  # should return False
print(is_one_away("abcde", "abc"))  # should return False
print(is_one_away("abc", "abcde"))  # should return False
print(is_one_away("abc", "bcc"))  # should return False
    
