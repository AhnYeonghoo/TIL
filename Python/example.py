import pandas as pd

dict_data = {'a': 1, 'b' : 2, 'c': 3}

ar = pd.Series(dict_data)

print(type(ar))
print('\n')
print(ar)