fun main(args: Array<String>) {
    val age = 30
    val name: String = "Ahn Yeonghoo"
    println(name.length)
    val a: Int = 30
    val b: Int = 40
    println(maxOf(a, b))
}

fun maxOf(a: Int, b: Int): Int = if (a > b) a else b