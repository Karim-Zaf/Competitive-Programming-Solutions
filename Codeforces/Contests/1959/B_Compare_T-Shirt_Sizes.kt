import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    val testCases = scanner.nextInt()
    repeat(testCases) {
        val a = scanner.next()
        val b = scanner.next()

        when {
            a == b -> println("=")
            a.last() == 'S' && b.last() == 'M' -> println("<")
            a.last() == 'M' && b.last() == 'S' -> println(">")
            a.last() == 'S' && b.last() == 'L' -> println("<")
            a.last() == 'L' && b.last() == 'S' -> println(">")
            a.last() == 'M' && b.last() == 'L' -> println("<")
            a.last() == 'L' && b.last() == 'M' -> println(">")
            a.last() == 'S' && a < b -> println(">")
            a.last() == 'S' -> println("<")
            a.last() == 'L' && a < b -> println("<")
            a.last() == 'L' -> println(">")
            else -> println(">")
        }
    }
}
