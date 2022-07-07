/*
 * При нажатии на кнопку открыть второе активити
 * При возврате из нее, переписать данные из editText в textView
 */

package com.example.company.myapplication

import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.android.synthetic.main.activity_main.view.*


class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        editText.setText("")
        textView.setText("")
        button.setOnClickListener {
            var intent: Intent = Intent(this, SecondActivity::class.java)
            startActivityForResult(intent, 1)
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        when(requestCode)
        {
            1 ->  {
                textView.setText(editText.text.toString())
                editText.setText("")
            }
            else -> {
                Log.d("ERROR", "~~~")
            }
        }
    }
}
