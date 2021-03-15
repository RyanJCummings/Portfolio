package com.diceRoller

import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RestController

@RestController
class AppController {

    @GetMapping("/")
    fun hello() = "Hello, World!"
}