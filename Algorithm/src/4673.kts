import java.util.*
fun main() = with(Scanner(System.`in`)) {
    var array = IntArray(10001) { i -> i + 1}

    for (i in 0 until array.size) {
        val temp = sum(i.toString())
        if (temp > 10000) continue
        array[temp] = 0
    }

    for (i in 0 until array.size) {
        if (array[i] != 0) println("${array[i] - 1}")
    }
}

fun sum(sequence: String): Int {
    var temp: Int = sequence.toInt()
    for (i in 0 until sequence.length)
        temp += sequence.substring(i, i + 1).toInt()
    return temp
}