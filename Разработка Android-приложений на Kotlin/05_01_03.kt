/*
 * Системы счисления
 * Переводим число (поле number) из 10 системы в (поле systemOfCalculus)
 * Результат в convertResult
 */ 

package com.example.company.myapplication

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import kotlinx.android.synthetic.main.activity_main.*
import java.lang.Integer.parseInt

class MainActivity : AppCompatActivity()
{

    override fun onCreate(savedInstanceState: Bundle?)
    {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        number.setText("")
        systemOfCalculus.setText("")
        convertResult.setText("")

        convertButton.setOnClickListener{
            try
            {
                var x: String = number.text.toString()
                var s: Int = systemOfCalculus.text.toString().toInt()

                convertResult.setText(x.toInt().toString(s))
            }
            catch (e: Throwable)
            {
                convertResult.setText("Error")
            }
        }
    }
}
