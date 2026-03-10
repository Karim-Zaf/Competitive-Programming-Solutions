import java.util.*

const val N = 2e5.toInt() + 30

var vis = Array(5) { IntArray(N) }
var t = Array(5) { CharArray(N) }
var n = 0
var m = 0
var cnt = 0L

val dx = intArrayOf(0, 1, 0, -1)
val dy = intArrayOf(1, 0, -1, 0)

fun canMove(i: Int, j: Int): Boolean {
    return i >= 0 && i < n && j >= 0 && j < m
}

fun dfsMaze(i: Int, j: Int) {
    vis[i][j] = 1
    cnt++
    for (pas in 0 until 4) {
        val x = i + dx[pas]
        val y = j + dy[pas]
        if (canMove(x, y) && vis[x][y] == 0 && t[x][y] == '*') {
            dfsMaze(x, y)
        }
    }
}

fun solve() {
    m = readLine()!!.toInt()
    n = 2
    var res = 0
    for (i in 0 until 2) {
        t[i] = readLine()!!.toCharArray()
        vis[i] = IntArray(m)
    }

    for (i in 0 until 2) {
        for (j in 0 until m) {
            cnt = 0
            if (t[i][j] == '*' && vis[i][j] == 0) {
                dfsMaze(i, j)
                res += cnt.toInt() - 1
            }
        }
    }
    println(res)
}

fun main() {
    val test = readLine()!!.toInt()
    repeat(test) {
        solve()
    }
}
