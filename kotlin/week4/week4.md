# 데이터구조 4주차 수업 요약

<br >

```kotlin
 fun pop(): T? {
    if (!isEmpty()) size--
    val result = head?.value
    head = head?.next
    if (isEmpty()) tail = null
    return result
}
```
- LinkedList: Pop
    - 맨 앞에 위치한 1개의 item을 제거하며 그 값을 리턴하는 함수.

<br>

```kotlin
fun removeLast(): T? {
        val head = head ?: return null

        if (head.next == null) return pop()

        size--
        var prev = head
        var current = head
        var next = current.next

        while (next != null) {
            prev = current
            current = next
            next = current.next
        }

        prev.next = null
        tail = prev
        return current.value
    }
```
- LinkedList: removeLast
    - 가장 뒤에 있는 item을 삭제 및 리턴하는 함수

<br>

```kotlin
fun removeAfter(node: Node<T>): T? {
        val result = node.next?.value`
        if (node.next == tail) {
            tail = node
        }
        if (node.next != null) {
            size--
        }
        node.next = node.next?.next
        return result
    }
```
- LinkedList: RemoveAfter
    - 임의 위치의 item을 삭제하고 그 값을 리턴하는 함수

<br>

```kotlin
val list4 = LinkedList<Int>()
    list.push(3)
    list.push(2)
    list.push(1)
    println(list)
    var theNode = list.nodeAt(0)!!
    while (true) {
        print("${theNode.value * 2}")
        if (theNode.next != null) {
            print(" -> ")
            theNode = theNode.next!!
        } else 
            break

    }
```

- LinkedList 객체의 각 'item의 2배 값을 화면에 순서대로 출력하는 코드'


<br>

```kotlin
fun printlnReverse() {
        this.next?.printlnReverse()
        if (this.next != null) {
            print(" -> ")
        }
        print(this.value.toString())
    }
```
- Node 클래스에 추가한 item을 역순으로 화면에 출력하는 함수

<br>

```kotlin
fun printlnReverse() {
        this.nodeAt(0)?.printlnreverse()
    }
```
- LinkedList 클래스에 item을 역순으로 화면에 출력하는 함수


## 배열과 링크드리스트의 차이
    - 배열은 사이즈가 고정되어 있는 반면, 링크드리스트는 다이나믹하게 사이즈가 조정될 수 있다. 또, 배열은 컴파일될 때 메모리 할당이 이루어지지만, 링크드리스트는 런타임 동안 할당을 계속 받을 수 있다. 링크드리스트가 배열에 비해 메모리를 더 잡아먹는다. 이유는 링크드리스트 객체는 다음 노드의 주소까지 저장해야 하기 때문이다.
    배열은 원소 접근이 용이하지만, 링크드리스트는 원소 접근이 까다롭다. 반면에 배열의 원소 변경은 시간이 오래 걸리지만, 링크드리스트의 원소 변경 시간은 빠르다.


<br>

## Stack
- 입구이자 출구가 1개 있는 구조(상자)
- LIFO: Last-In, First-Out
- 주요 기능
    - Push And Pop


```kotlin
interface StackInterface<Element> {
    fun push(element: Element)
    fun pop(): Element?
}

class Stack<Element>() : StackInterface<Element> {
    private val storage = arrayListOf<Element>()
    override fun toString() = buildString {
        appendLine("----Top----")
        storage.asReversed().forEach {
            appendLine("$it")
        }
        appendLine("----------")
    }

    override fun push(element: Element) {
        storage.add(element)
    }

    override fun pop(): Element? {
        if (storage.size == 0) {
            return null
        }
        
        return storage.removeAt(count - 1)
    }
}

fun main() {
    val stack = Stack<Int>().apply {
        push(1)
        push(2)
        push(3)
        push(4)

        print(stack)
        val popedElement = stack.pop()
        if (popedElement != null) {
            println("Popped: $popedElement")
        }
        print(stack)
    }
}
```
- 스택의 기본 구조 코드 구현

<br>

```kotlin
val count: Int
        get
    
    fun peek(): Element?
    val isEmpty: Boolean
        get() = count == 0

class Stack {
    override fun peek(): Element? {
        return storage.lastOrNull()
    }

    override val count: Int 
        get() = storage.size
}
```

- stack에 존재하는 top 위치의 item을 pop하지 않고 엿보는 함수 


<br>
