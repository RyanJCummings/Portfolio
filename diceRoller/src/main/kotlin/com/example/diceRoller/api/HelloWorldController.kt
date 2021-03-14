package com.example.diceRoller.api

import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RequestMapping
import org.springframework.web.bind.annotation.RestController


@RestController
@RequestMapping("/api/v1/hello")
class HelloWorldController {

    @GetMapping ("/world")
    fun getHelloWorld(): String {
        return "Hello World"
    }
}