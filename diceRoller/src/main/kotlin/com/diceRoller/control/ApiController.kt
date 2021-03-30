package com.diceRoller.control

import com.diceRoller.data.Comment
import com.diceRoller.data.Dice
import com.diceRoller.data.UserInput
import com.diceRoller.logic.RollLogic
import com.diceRoller.logic.urlHandler
import org.springframework.http.HttpStatus
import org.springframework.http.MediaType
import org.springframework.http.ResponseEntity
import org.springframework.web.bind.annotation.*
import java.time.Instant  // DELETE THIS TOO!
import org.springframework.web.bind.annotation.RequestMapping
import org.springframework.web.bind.annotation.RestController
import java.net.URLDecoder
import java.nio.charset.StandardCharsets
import org.springframework.web.bind.annotation.RequestBody

import org.springframework.web.bind.annotation.PostMapping
import java.net.URI


@RestController
@RequestMapping("/")
class ApiController {

    @GetMapping("hello")
    fun getHello() = "Hello, World!"

    @GetMapping("history")
    fun getHistory() = "Here is your history."

    /*@PostMapping("rollDice", MediaType.APPLICATION_FORM_URLENCODED_VALUE)
    fun handleRollInput(@RequestBody dNum: String) : ResponseEntity<String> {
        val newNum = dNum.toInt() + 2
        print(newNum)
        return ResponseEntity<String>(newNum.toString(), HttpStatus.OK)
    }*/

    @PostMapping(
        value = ["rollDice"],
        consumes = [MediaType.APPLICATION_FORM_URLENCODED_VALUE],
        produces = [MediaType.ALL_VALUE]
    )
    fun postBody(@RequestBody input: UserInput): ResponseEntity<String?>? {
        val parsedInput: Int = input.number
        return ResponseEntity
            .created(
                URI
                    .create(java.lang.String.format("/rollDice/%s", parsedInput.toString()))
            )
            .body<String?>(parsedInput.toString())
    }

    /*@GetMapping("rollDice")
    fun parseUserInput(): String {
        val num = UserInput()
    }*/

    /*@PostMapping("rollDice", MediaType.APPLICATION_FORM_URLENCODED_VALUE)
    fun getInput(@RequestBody userInput: String): ResponseEntity<String> {
        val userInput = UserInput(number = 1)
        return ResponseEntity<String>("input is $userInput", HttpStatus.OK)
    }*/

    @GetMapping("logictest")
    fun testlogic(): String {
        val dice = Dice(d4 = 1, d6 = 1, d8 = 1, d20 = 2)
        val rollResult = RollLogic(dice)
        return rollResult.results.toString()
    }

    private fun decode(value: String): String? {
        return URLDecoder.decode(value, StandardCharsets.UTF_8.toString())
    }

    /*@GetMapping("urlHandler")
    fun testUrlHandler(): String {
        val blah = urlHandler()
    }*/


    // --------------------------------------------------------------
    // DELETE THIS BEFORE PRODUCTION
    // New route to hand comment request
    @RequestMapping("/getcomment")
    fun getComment(): Comment {
        return Comment(
            author = "codebeast",
            content = "I'm so loving Kotlin",
            created = Instant.now()
        )
    }
    // --------------------------------------------------------------
}