package com.diceRoller.control

import com.diceRoller.data.Comment
import org.springframework.http.HttpStatus
import org.springframework.http.MediaType
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.*
import java.time.Instant  // DELETE THIS TOO!
import org.springframework.web.bind.annotation.RequestMapping
import org.springframework.web.bind.annotation.RestController


@RestController
class ApiController {

    @GetMapping("/hello")
    fun getHello() = "Hello, World!"

    @GetMapping("/history")
    fun getHistory() = "Here is your history."

    @PostMapping("/rollDice", MediaType.APPLICATION_FORM_URLENCODED_VALUE)
    fun handleRollInput(@RequestBody dNum: String) : ResponseEntity<String> {
        val newNum = dNum.toInt() + 2
        print(newNum)
        return ResponseEntity<String>(newNum.toString(), HttpStatus.OK)
    }

    @PostMapping(path = "/test",
        consumes = {MediaType.APPLICATION_FORM_URLENCODED_VALUE,
        MediaType.MULTIPART_FORM_DATA_VALUE},
        produces = MediaType.APPLICATION_JSON_VALUE)

    // --------------------------------------------------------------
    // DELETE THIS BEFORE PRODUCTION
    // New route to hand comment request
    @RequestMapping("/getcomment")
    fun getComment() : Comment {
        val comment = Comment(
            author = "codebeast",
            content = "I'm so loving Kotlin",
            created = Instant.now()
        )
        return comment
    }
    // --------------------------------------------------------------
}