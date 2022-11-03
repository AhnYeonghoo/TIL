def f(ham: str, eggs: str = 'eggs') -> str:
    print("Annotations: ", f.__annotations__)
    print("Arguments: ", ham, eggs)
    return ham + " and " + eggs

f('spam')

num: int = 1

def add(a: int, b: int) -> int:
    return a + b

print(add(3, 5))

class MyRepr:
    def __repr__(self):
        return "MyRepr()"

    def __str__(self):
        return "Hello MyRepr"

obj = MyRepr()

obj_repr = repr(obj)
new_obj = eval(obj_repr)
print(type(new_obj))

