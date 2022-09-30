fun forEachDepthFirst(visit: Visitor<T>) {
    visit(this)
    children.forEach {
        it.forEachDepthFirst(visit)
    }
}