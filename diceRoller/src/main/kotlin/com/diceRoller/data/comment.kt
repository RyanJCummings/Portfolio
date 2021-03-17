package com.diceRoller.data
// ------------------------------------------------

// DELETE THIS BEFORE PRODUCTION
import com.fasterxml.jackson.annotation.JsonCreator
import java.time.Instant

data class Comment(
    val author: String,
    val content: String,
    val created: Instant
)
// ------------------------------------------------
