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


```kotlin
fun String.checkParentheses(): Boolean {
    val stack = Stack<Char>()
    for (character in this) {
        when (character) {
            '(' -> stack.push(character)
            ')' -> if (stack.isEmpty) {
                return false
            } else {
                stack.pop()
            }
        }
    }
    return stack.isEmpty
}
```

- Stack을 이용한 괄호 개수의 짝이 맞는지 체크하는 함수
- 위 함수는 기존 String 클래스의 맴버 함수를 닷연산자를 이용해 추가하는 코틀린에서 제공해주는 문법을 이용함.(신기)

<br>


```kotlin
class Flower private constructor(val name: String) {
    companion object bud {
        private var numFlowers: Int = 0
       
        fun bloom(name: String): Flower? {
            if (numFlowers > 0)
                return null
            numFlowers += 1
            return Flower(name)
        }
    }

    override fun toString(): String {
        return "Flower $name"
    }
}
```

- Companion
    - 클래스 내에 존재하는 객체 (생성 X여도 객체로 존재)
        - 자신이 속한 클래스의 생성자에 권한 상관없이 접근 가능


<br >

```kotlin
class Outer {
    val ov = 5

    class Nested {
        val nv = 10
        fun greeting() = "Nested"
        fun accessCompanionMethod() {
            println(country)
            getSomething()
        }
    }

    companion object {
        const val country = "Korea"
        fun getSomething() = println("Get Country")
        fun callNestedGreeting() {
            Outer.Nested().greeting() 
        }
    }
    fun outside() {
        val msg = Nested().greeting()
        println(Nested().nv)
    }
    
}
```
- Nested Class

    - Companion Object와 유사하게 Outer 클래스의 객체 생성없이 사용가능 
    - 단, Nested Class 자체는 객체 생성이 필요함.

<br>

- Nested & Inner와는 달리, Companion Object는 클래스 내에 1개밖에 못 만든다!

<br>

```kotlin
sealed class Fruit1 {
    class Apple():Fruit1()
    class Banana():Fruit2()
}
```
- 실드 클래스 사용
    - 나를 상속받은 자식들은 이 자식들이야 라고 알려줌.
    - 복잡한 상속관계를 정리하기 용이
    
<br>


```kotlin
open class Animal constructor(var age: Int) {
    
}

class Cat(age: Int = 1, var name: String) : Animal (age) {
    constructor(age: Int): this(age, "Noname") {
        println("No named Cat")
    }
    constructor(): this(name="noName") {
        println("ddd")
    }
    fun talk() {
        print("${name}: ")
        for (i in 1...age) {
            print("miyao")
        }
        println()
    }
    
}
```

- 클래스의 생성자는 여러개 만들 수 있다.
    - init도 가능, constructor도 가능
    - 부생성자도 존재.

<br>

```kotlin
enum class Weekday(val favor: Int) {
    Sunday(80), Monday(0),
    Tuesday(10), Wednesday(20),
    Tursday(30), Friday(90),
    Saturday(100);
}
```

- Enum Class의 구조
    
<br>

```kotlin
fun helloToOhter(c: Cat?) {
        print("${name}: ")
        val isOlder = c?.let {
            it.age > this.age
        }
        when(isOlder) {
            false -> println("${c.name}에게 안녕.")
            true -> println("${c.name}에게 안녕하세요")
            else -> println("? ??? ")
        }
    }
```
- 예의가 바른 고양이 함수

<br>

<br>

## Standard Library: Functions

- let
    - 주어진 객체에 대한 안전한 operation 수행을 가능하게 한다.(JS랑 동일)
    
- with
    - 주어진 객체에 대한 맴버변수,함수 접근을 편리하게 함

- run
    - with와 유사하지만, let처럼 ?를 붙임으로써 안전하게 실행되게 할 수 있으나, 주어진 객체를 this로만 표기 가능, it 불가능
    
- also
    - let과 매우 유사하나, 객체 자신을 리턴.
    - 반환 타입이 객체기 때문에 해당 객체에 대한 함수를 다시 호출이 가능함.

- apply 
    - also와 유사하게 객체 자신을 리턴
    - 하지만 run과 동일하게 주어진 객체를 this로 표기


<br>

## Queue

- 먼저 들어간 item이 먼저 나오게 됨
    - FIFO(First-in First-out)


```kotlin
interface QueueInterface<T> {
    fun enqueue(element: T): Boolean
    fun dequeue(): T?
    val count: Int
        get
    val isEmpty: Boolean
        get() = count == 0
    fun peek(): T?
}

class ArrayListQueue<T> : QueueInterface<T> {
    private val list = arrayListOf<T>()
    
    override val count: Int
        get() = list.size
        
    override fun peek(): T? = list.getOrNull(0)
    override fun enqueue(element: T): Boolean {
        list.add(element)
        return true
    }
    override fun dequeue(): T? =
        if (isEmpty) null else list.removeAt(0)

    override fun toString(): String = list.toString()
}
```
- Queue의 코드 구현


<br>
<br>



## 느낀점

- 언어들의 장점만 모아놓은 신기한 언어인 것 같다. 