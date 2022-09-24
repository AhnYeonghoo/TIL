class Flower private constructor(val name: String) {

    companion object bud {

        private var numFlowers: Int = 0

        /* 싱글톤 패턴을 지키기 위해서 함수 하나만 정의함. */

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

class Smartphone(val model: String) {

    private val cpu = "i5-8900"

    var name: String = "Noname"

    fun func1() {
        println("Name is $name")
    }

    inner class Inner {
        fun whichCpu() {
            println(cpu)
            getSomething()
        }
    }

    companion object {
        const val country = "Korea"
        fun getSomething() = println("Get Country")
        fun whichCpu() {
            println("I don`t know..")
        }
    }
}

enum class Weekday(val favor: Int) {
    Sunday(80), Monday(0),
    Tuesday(10), Wednesday(20),
    Tursday(30), Friday(90),
    Saturday(100);
}

open class Animal constructor(var age: Int) {

}

class Cat(age: Int = 1, var name: String) : Animal(age) {
    constructor(age: Int) : this(age, "Noname") {
        println("No named Cat")
    }

    constructor() : this(name = "noName") {
        println("ddd")
    }

    fun talk() {
        print("${name}: ")
        for (i in 1...age) {
            print("miyao")
        }
        println()
    }

    fun helloToOhter(c: Cat?) {
        print("${name}: ")
        val isOlder = c?.let {
            it.age > this.age
        }
        when (isOlder) {
            false -> println("${c.name}에게 안녕.")
            true -> println("${c.name}에게 안녕하세요")
            else -> println("? ??? ")
        }
    }
}

sealed class Fruit1 {
    class Apple() : Fruit1()
    class Banana() : Fruit2()
}

sealed class Fruit2
class Apple() : Fruit2
class Banana() : Fruit2

fun main() {
    var f1 = Flower.bud.bloom("ROse")
    var f2 = Flower.bloom("Hibiscus")

    val output = Outer.Nested().greeting()
    println(output)

    val outer = Outer()
    println(outer.outside())
    Outer.Nested().accessCompanionMethod()


    println(f1)
    println(f2)

    val s1 = Smartphone("a32")
    s1.Inner().whichCpu()

    Smartphone.companion.whichCpu()

    val outer = Outer()
    Outer.Nested().accessCompanionMethod()
}
