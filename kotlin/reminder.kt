
fun checkFirst(names: List<String>) {
    if (names.firstOrNull() != null) {
        println(names.first())
    } else {
        println("No Names")
    }
}

fun linearContains(value: Int, numbers: List<Int>): Boolean {
    for (element in numbers) {
        if (element == value) {
            return true
        }
    }
    return false
}

fun pseudoBinaryContains(value: Int, numbers: List<Int>): Boolean {
    if (numbers.isEmpty()) return false
    val middleIndex = numbers.size / 2
    if (value <= numbers[middleIndex]) {
        for (index in 0..middleIndex) {
            if (numbers[index] == value) {
                return true
            }
        }
    } else {
        for (index in middleIndex until numbers.size) {
            if (numbers[index] == value) return true
        }
    }
    return false
}

fun sumFromOne(n: Int): Int {
    return n * (n + 1) / 2
}

fun printNames(names: List<String>) {
    for (name in names) println(name)
}

fun multiplicationBoard(size: Int) {
    for (number in 1..size) {
        print("|")
        for (otherNumber in 1..size) {
            print("${number} x ${otherNumber} = ${number * otherNumber} | ")
        }
        println()
    }
}

data class Node<T> (var value: T, var next: Node<T>? = null) {
    override fun toString(): String {
        return if (next != null) { "${value} -> ${next.toString() }"
        } else "${value}"
    } 
}

fun main() {
    val name: List<String> = listOf("Kevin", "Mila", "Sally" )
    val name2: List<String>? = listOf("", "odod")
    checkFirst(name)
    checkFirst(name2!!)
    val numbers = listOf(1, 3, 56, 66, 67, 89, 99, 105, 480)
    println(linearContains(99, numbers))
    println(pseudoBinaryContains(99, numbers))
    println()
    val names: List<String> = listOf("Kevvin", "ahn")
    printNames(names)
    println()
    multiplicationBoard(5)
    println()
    val node1 = Node(value=1)
    val node2 = Node(value=2)
    val node3 = Node(value=3)
    node1.next = node2
    node2.next = node3
    println(node1)
}