fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        var ans = 0
        val ncs = readLine()!!.split(" ")
        val n = ncs[0].toInt()
        val c = ncs[1]
        val s = readLine()!!

        var nxt = 0
        if (c[0] == 'g') {
            println(0)
        } else {
            while (s[nxt] != 'g') {
                nxt++
                if (nxt == n) nxt = 0
            }
            for (i in 0 until n) {
                if (s[i] == 'g') {
                    nxt++
                    if (nxt == n) nxt = 0
                    while (s[nxt] != 'g') {
                        nxt++
                        if (nxt == n) nxt = 0
                    }
                }

                if (s[i] == c[0]) {
                    val dist = if (i <= nxt) nxt - i else n - i + nxt
                    ans = maxOf(ans, dist)
                }
            }
            println(ans)
        }
    }
}
