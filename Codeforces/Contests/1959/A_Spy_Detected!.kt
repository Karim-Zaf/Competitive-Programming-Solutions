import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    val testCases = scanner.nextInt()
    repeat(testCases) {
        val n = scanner.nextInt()
        val v = IntArray(n + 1)
        val mp = HashMap<Int, Int>()
        for (i in 1..n) {
            v[i] = scanner.nextInt()
            mp[v[i]] = mp.getOrDefault(v[i], 0) + 1
        }

        for (i in 1..n) {
            if (mp[v[i]] == 1) {
                println(i)
                break
            }
        }
    }
}
