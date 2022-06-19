package com.example.kotlinpractice

fun main() {
    // 5. Array and List

    // Array -> 메모리가 컴파일될 떄 결정
    // List 1. immutablelist, 2. mutablelist
    val array : Array<Int> = arrayOf(1, 2, 3)
    val list : List<Int> = listOf(1, 2, 3)
    val array2 : Array<Any> = arrayOf(1, "d", 3.4f)
    val list2 : List<Any> = listOf(1, "d", 11L)

    var arrayList : ArrayList<Int> = arrayListOf<Int>()
    arrayList.add(10)
    arrayList.add(20)
    array[0] = 3
    var result = list[0]
    println(result)
    println(array.get(0))
    println(arrayList)

    forAndWhile()



}




// 6. for / while
fun forAndWhile() {

    val students : ArrayList<String> = arrayListOf("ahnyong", "jany", "kim", "jenny")

    for (name: String in students) {
        println("${name}")
    }

    var sum : Int = 0
    for (i : Int in 1..10 step 2) {
        sum += i
    }

    for ((index, name) in students.withIndex()) {
        println("${index+1}번째 학생: ${name}")
    }
    println("sum is ${sum}")
    var sum2 : Int = 0
    for (i : Int in 10 downTo 1) {
        sum2 += i
    }
    println("sum2 is ${sum2}")

    var index: Int = 0
    while(index < 10) {
        println("current index: ${index}")
        index++
    }

}