/*
 * RadioButton в действии
 */

package com.example.company.myapplication

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.RadioButton
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        tvAnswer.setText("")

        butAnswer.setOnClickListener{
            var idRadio = radioGroup.checkedRadioButtonId
            tvAnswer.setText(if(idRadio == R.id.rbSphere) "Правильно!" else "Неправильно!")
        }
    }
}
