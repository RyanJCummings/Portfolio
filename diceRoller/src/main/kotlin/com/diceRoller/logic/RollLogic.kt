package com.diceRoller.logic

import com.diceRoller.data.Dice
import kotlin.random.Random
/*
 * Handles rolling and tallying results.
 * Returns a map of dice to their individual rolls.
 * Also handles tallying total.
 */

class RollLogic (dice: Dice) {

    // make Dice data class values iterable
    private val diceList: List<Int> = listOf(
        dice.d4,
        dice.d6,
        dice.d8,
        dice.d10,
        dice.d12,
        dice.d20
    )

    // declare map
    val results: MutableMap<String, Int> = mutableMapOf()

    init {
        parseIntoMap()
    }

    private fun parseIntoMap() {
        for ((index, value) in diceList.withIndex()) {
            for (j in 0 until value) {
                val nameAndValue: Pair<String, Int> = parseDie(index)
                results.put(nameAndValue.first + "_" + j.toString(),
                    nameAndValue.second)
            }
        }
    }

    private fun parseDie(die: Int): Pair<String, Int> {
        when(die) {
            0 -> return Pair("d4", Random.nextInt(1,4))
            1 -> return Pair("d6", Random.nextInt(1,6))
            2 -> return Pair("d8", Random.nextInt(1,8))
            3 -> return Pair("d10", Random.nextInt(1,10))
            4 -> return Pair("d12", Random.nextInt(1,12))
            5 -> return Pair("d20", Random.nextInt(1,20))
        }
        // error: no correct die type
        return Pair("error", -1)
    }
    //TODO - Tally results total
}