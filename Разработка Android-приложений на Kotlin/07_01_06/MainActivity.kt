/* Запросики, запросики */

package com.example.company.myapplication

import android.os.Bundle
import android.util.Log
import androidx.appcompat.app.AppCompatActivity
import com.android.volley.Request
import com.android.volley.Response
import com.android.volley.toolbox.StringRequest
import com.android.volley.toolbox.Volley
import kotlinx.android.synthetic.main.activity_main.*
import kotlinx.android.synthetic.main.activity_main.view.*


class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        editText.setText("")
        textView.setText("Failed")

        button.setOnClickListener {

            var thr = Thread {
               Log.d("TESTS", "TEST")

                val queue = Volley.newRequestQueue(this)
                //val url = "https://www.google.com"
                val url = editText.text.toString()

                runOnUiThread {
                    val stringRequest = StringRequest(
                        Request.Method.GET, url,
                        { response ->
                            textView.text = "Ok"
                        },
                        { textView.text = "Failed" })
                    queue.add(stringRequest)
                }
            }
            thr.start()
            thr.join()

        }
    }
}
