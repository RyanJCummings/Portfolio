package com.vueDiceRoller.control

import org.springframework.web.bind.annotation.GetMapping
import org.springframework.web.bind.annotation.RequestMapping
import org.springframework.web.bind.annotation.RestController

@RestController
@RequestMapping("/")
class helloWorldController {

    @GetMapping("hello")
    fun getHello() = "Hello, World!"
}