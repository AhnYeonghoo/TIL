# keyword arguments

def parrot(voltage, state='a stiff', action='voom', type='Norwegian Blue'):
    print('-- This parrot wouldn\'t', action, end=' ')
    print('if you put', voltage, 'volts through it.')
    print('-- Lovely plumage, the', type)
    print('-- it\'s ', state, "!")

parrot(1000)
parrot(voltage=1000)
parrot(voltage=10000000, action='VOOOOOM')


def cheeseshop(kind, *arguments, **keywords):
    print('-- Do you have any ', kind , "?")
    print('-- i\`m sorry we\'re all out of', kind)
    for arg in arguments:
        print(arg)
    print("-" * 40)
    for kw in keywords:
        print(kw, ":", keywords[kw])
    
cheeseshop("Limburger", "It's very runny, sir.",
           "It's really very, VERY runny, sir.",
           shopkeeper="Michael Palin",
           client="John Cleese",
           sketch="Cheese Shop Sketch")

def an(ham: str, eggs: str = 'eggs') -> str:
    print("Annotations:", an.__annotations__)
    print("Arguments: ", ham, eggs)
    return ham + ', and ' + eggs
    
an('spam')