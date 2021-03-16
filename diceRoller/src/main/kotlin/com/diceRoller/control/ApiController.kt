package com.diceRoller.control

import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.PostMapping
import org.springframework.web.bind.annotation.RestController

@RestController
class ApiController {

    @GetMapping("/hello")
    fun getHello() = "Hello, World!"

    @GetMapping("/history")
    fun getHistory() = "Here is your history."

    @PostMapping("/something")
    fun postDiceNum() = ""

    @PostMapping("/somethingElse")
    fun postDiceValues() = ""
}