package com.example.company.myapplication

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_finish.*

class FinishActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_finish)

        number.setText("")
        editText.setText("")

        try
        {
            var n = this.intent.getStringExtra("number")
            Log.d("TEXTAA", "$n")
            number.setText(n.toInt().toString())
        }
        catch (e: Throwable)
        {
            number.setText("")
        }

        editText.setText(this.intent.getStringExtra("message"))
    }
}