import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    val testCases = scanner.nextInt()
    repeat(testCases) {
        var ans = 0
        val n = scanner.nextInt()
        var k = scanner.nextInt()
        var s = scanner.next()

        val mp = mutableMapOf<Char, Int>()
        for (c in s) mp[c] = mp.getOrDefault(c, 0) + 1

        for (i in 0 until 26) {
            var one = mp['a' + i] ?: 0
            var two = mp['A' + i] ?: 0

            val mn = minOf(one, two)

            one -= mn
            two -= mn

            var sum = one + two

            sum /= 2

            val nw = minOf(sum, k)

            ans += nw + mn
            k -= nw
        }

        println(ans)
    }
}
