fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val s = readLine()!!
        var i = s.length - 1

        while (i >= 0 && s[i] in '0'..'9') {
            if (s[i] > '0') break
            i--
        }

        for (j in 0 until i ) {
            print(s[j])
        }
        println()
    }
}
