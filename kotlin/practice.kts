open class GroundUnit constructor(health: Int, damage: Int) {

    var health: Int
    var damage: Int

    init {
        this.health = health
        this.damage = damage
    }

    open fun attack(damage: Int): Int {
        println("지상유닛 공격")
        return this.damage
    }

    open fun defense(): Int {
        println("지상유닛이 방어했습니다!")
        return this.health
    }
}

class Marine constructor(health: Int, damage: Int, height: Int) : GroundUnit(health, damage) {
    var health: Int
    var damage: Int
    var height: Int

    init {
        this.height = height
    }

    override fun attack(damage: Int): Int {
        println("마린이 공격합니다. ")
        return this.damage
    }

    override fun defense(): Int {
        println("마린이 방어했습니다. ")
        return this.health
    }

    fun steamPack(): Unit {
        println("스팀팩 발동!")
    }
}

open class FlyUnit constructor(speed: Int, health: Int) {
    var speed: Int
    var health: Int

    init {
        this.speed = speed
        this.health = health
    }
}

abstract class Loader {

    abstract fun innerLoad()

    fun load() {

        innerLoad()
    }
}

class ProfileLoader : Loader() {

    override fun innerLoad() {

    }
}

class ImageLoader : Loader() {

    override fun innerLoad() {

    }
}

class Progress {

    fun show() {

    }

    fun hide() {

    }
}

class ProfileLoader : Loader() {

    val progress = Progress()

    override fun innerLoad() {
        progress.show()
        progress.hide()
    }
}
