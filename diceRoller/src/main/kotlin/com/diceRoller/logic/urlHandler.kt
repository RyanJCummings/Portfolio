package com.diceRoller.logic

import java.net.URLDecoder
import java.nio.charset.StandardCharsets

class urlHandler {

    private fun decode(value: String): String? {
        return URLDecoder.decode(value, StandardCharsets.UTF_8.toString())
    }

}