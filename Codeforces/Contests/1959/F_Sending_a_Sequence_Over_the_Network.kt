fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val n = readLine()!!.toInt()
        val v = readLine()!!.split(" ").map { it.toInt() }.toMutableList()
        val dp = BooleanArray(n + 1)

        dp[0] = true

        for (i in 1..n) {
            val nxt = i + v[i - 1]
            if (nxt <= n) dp[nxt] = dp[nxt] || dp[i - 1]

            val prv = i - v[i - 1] - 1
            if (prv >= 0) dp[i] = dp[i] || dp[prv]
        }

        println(if (dp[n]) "YES" else "NO")
    }
}
