/*
 * Передать данные из editText mainActivity в textView SecondActivity
 * по нажатию кнопки
 */

package com.example.company.myapplication

import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.os.Environment
import android.support.v4.app.ActivityCompat
import android.support.v4.content.ContextCompat
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    var textInput: String = ""

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        editText.setText("")
        button.setOnClickListener {
            textInput = editText.text.toString()

            var intent = Intent(this, SecondActivity::class.java)
            intent.putExtra("textView", textInput.toString().decapitalize().replace(" ", ""))
            startActivity(intent)
        }
    }
}
