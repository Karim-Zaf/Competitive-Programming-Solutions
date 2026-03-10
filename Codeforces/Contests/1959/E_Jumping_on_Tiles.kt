fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val s = readLine()!!
        val n = s.length
        var ans = -1
        val v = mutableListOf<Int>()
        val mp = mutableMapOf<Char, MutableList<Int>>()

        for (i in s.indices) {
            if (mp.containsKey(s[i])) {
                mp[s[i]]!!.add(i)
            } else {
                mp[s[i]] = mutableListOf(i)
            }
        }

        for (c in s[0]..s.last()) {
            ans++
            mp[c]?.let { list ->
                v.addAll(list)
            }
        }

        if (s[0] != s.last()) {
            for (c in s[0] downTo s.last()) {
                ans++
                mp[c]?.let { list ->
                    v.addAll(list)
                }
            }
        }

        println("$ans ${v.size}")
        v.forEach { print("${it + 1} ") }
        println()
    }
}
