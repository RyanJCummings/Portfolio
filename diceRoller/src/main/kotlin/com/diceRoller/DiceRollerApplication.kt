package com.diceRoller

import org.springframework.boot.autoconfigure.SpringBootApplication
import org.springframework.boot.runApplication

@SpringBootApplication
class DiceRollerApplication

fun main(args: Array<String>) {
	runApplication<DiceRollerApplication>(*args)
}
