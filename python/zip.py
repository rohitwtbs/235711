x= [1,2,3,4,5]
y= ["a","b","c"]

x_and_y = list(zip(x,y))
print(x_and_y)

# it will print zipped but the length of the
# longest will be lost


import itertools

another_x_y = list(itertools.zip_longest(x,y))
print(another_x_y)