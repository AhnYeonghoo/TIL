# Generic
from collections.abc import Sequence

ConnectionOpt = dict[str, str]
Address = tuple[str, int]
Server = tuple(Address, ConnectionOpt)

def broadcast_message(message: str, servers: Sequence[Server]) -> None

def broadcast_message (
    message: str,
    servers: Sequence[tuple[tuple[str, int], dict[str, str]]] -> None
)


def greeting(name: str) -> str:
    return "Hello" + name

Vector = list[float]

def scale(scalar: float, vector: Vector) -> Vector:
    return [scalar * num for num in vector]

print(greeting('ahn'))
new_vector = scale(2.0, [1.0, -4.2, 5.4])
print(new_vector)
