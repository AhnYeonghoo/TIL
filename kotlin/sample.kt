package com.example.kotlinpractice

fun main() {

    // 3. String Template

    val name : String = "Ahn"
    val lastName : String = "Yeonghoo"
    println("my name is ${name + lastName}231")

    println("this is 2\$doller")
    println("잔디밭 심기^^")

    // 4. comment
    // basic comment
    /*
        여러줄 주석
    */

    checkNum(1)


}

// 1. 함수
// 리턴 형식이 Unit이면 void와 동일
fun helloWorld() : Unit {
    println("Hello World")

}

fun add(a : Int, b : Int) : Int {
    return a + b
}

// 2. val & var
// val = value(값) -> const인듯?
// var = variable -> 변수
fun hi() {

    val a : Int = 10
    var b : Int = 9
    b = 100
    // a = 20 -> 불가능

    val auto = 20 // 자동으로 형식 지정해줌 Int로
    var d = 100

    var name : String = "Ahn Yeonghoo"
    println(name)

}

// 5. condition expression
fun maxBy(a: Int, b: Int): Int {
    if (a > b) {
        return a
    } else {
        return b
    }
}

// maxBy와 동일한 함수식
fun maxBy2(a: Int, b: Int) : Int = if(a > b) a else b

fun checkNum(score : Int) {
    // switch expression과 동일
    when (score) {
        0 -> println("this is zeor")
        1 -> println("this is 1")
        2, 3 -> println("this is 2 or 3")
        else -> println("I dont No")
    }

    var b: Int = when(score) {
        1-> 1
        2-> 2
        else-> 3
    }

    println("b: ${b}")

    when(score) {

        in 90..100-> println("You are genius")
        in 10..80-> println("not bad")
        else-> println("okay")
    }
}