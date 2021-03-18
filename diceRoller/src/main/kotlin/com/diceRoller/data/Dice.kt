package com.diceRoller.data

@Serializable
data class Dice(var d4: Int = 0,
                var d6: Int = 0,
                var d8: Int = 0,
                var d10: Int = 0,
                var d12: Int = 0,
                var d20: Int = 0)
{}
