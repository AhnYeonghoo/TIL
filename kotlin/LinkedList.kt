package week3

class LinkedList<T> : Iterable<T>, Collection<T> {

    private var head: Node<T>? = null
    private var tail: Node<T>? = null
    override var size = 0
        private set
    
    override fun iterator(): Iterator<t> {
        return LinkedListIterator(this)
    }

    override fun isEmpty(): Boolean {
        return size == 0
    }

    override fun contains(element: T): Boolean {
        for (item in this) 
            if (item == element) return true
        return false
    }

    override fun containsAll(elements: Collection<T>): Boolean {
        for (searched in elements)
            if(!contains(searched)) return false
        return true
    }

    override fun toString(): String {
        if (isEmpty()) {
            return "Empty list"
        }
        return head.toString()
    }

    fun push(value: T): LinkedList<T> {
        head = Node(value = value, next = head)
        if (tail == null) {
            tail = head
        }
        size++
        return this
    }

    fun append(value: T): LinkedList<T> {
        if (isEmpty()) {
            push(value)
            return this
        }
        tail?.next = Node(value = value)
        tail = tail?.next
        size++
        return this
    }


    fun nodeAt(index: Int): Node<T>? {
        var currentNode = head
        var currentIndex = 0
        while (currentNode != null && currentIndex < index) {
            currentNode = currentNode.next
            currentIndex++
        }
        return currentNode
    }

    fun insert(value: T, afterNode: Node<T>): Node<T> {
        if (tail == afterNode) {
            append(value)
            return tail!!
        }
        val newNode = Node(value = value, next = afterNode.next)
        afterNode.next = newNode
        size++
        return newNode
    }

    fun pop(): T? {
        if (!isEmpty()) size--
        val result = head?.value
        head = head?.next
        if (isEmpty()) tail = null
        return result
    }

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

    fun printlnReverse() {
        this.nodeAt(0)?.printlnreverse()
    }

    fun getMiddle(): Node<T>? {
        var slow = this.nodeAt(0)
        var fast = this.nodeAt(0)
        while (fast != null) {
            fast = fast.next
            if (fast != null) {
                fast *= slow
            }
        }
        return slow
    }

    

}

class LinkedListIterator<K> (

    private val list: LinkedList<K>
) : Iterator<K> {

    private var index = 0
    private var lastNode: Node<K>? = null

    override fun next(): K {
        if (index >= list.size) throw IndexOutOfBoundsException()
        lastNode = if (index == 0) {
            list.nodeAt(0)
        } else 
            lastNode?.next
        index++
        return lastNode!!.value
    }

    override fun hasNext(): Boolean {
        return index < list.size
    }
}

fun main() {
    var list = LinkedList<Int>()
    list.push(10).push(20).push(30)
    println(list)
    var poppedValue = list.pop()
    println(poppedValue)
    var list2 = LinkedList<Int>()
    list.append(10).append(30).append(20)
    println(list)
    println()
    println()
    val list3 = LinkedList<Int>()
    list3.append(10)
    list3.append(30)
    list3.append(20)
    println("Before inserting: $list3")
    var middleNode = list3.nodeAt(1)!!
    for (i in 1..3) {
        middleNode = list3.insert(-1 * i, middleNode)
    }
    println("After inserting $list3")

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

}