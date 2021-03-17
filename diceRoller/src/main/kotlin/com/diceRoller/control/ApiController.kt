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
        fun handleRollInput() : ResponseEntity<String> {
            return ResponseEntity<String>("Nice roll", HttpStatus.OK)
        }

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