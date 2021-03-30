package com.diceRoller.control

import org.springframework.web.bind.annotation.PostMapping
import org.springframework.web.bind.annotation.RequestBody
import org.springframework.web.bind.annotation.RequestMapping
import org.springframework.web.bind.annotation.RestController

@RestController
@RequestMapping("/")
class SamplePostController {

    @PostMapping("postBody")
    fun postBody(@RequestBody fullName: String): String {
        return "Hello $fullName"
    }
}