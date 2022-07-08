/*
 * Есть seekBar от 0 до 20, выводим listView квадратами
 */

package com.example.company.myapplication

import android.os.Bundle
import android.support.v7.app.AppCompatActivity
import android.util.Log
import android.widget.ArrayAdapter
import android.widget.SeekBar
import android.widget.TextView
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        seekBar.max = 20

        var data: MutableList<Int> = MutableList(0, {0})
        var adapter = ArrayAdapter<Int>(this, android.R.layout.simple_list_item_1, data)
        listView.adapter = adapter

        seekBar.setOnSeekBarChangeListener(object : SeekBar.OnSeekBarChangeListener{
            override fun onProgressChanged(p0: SeekBar?, p1: Int, p2: Boolean) {
                var x : Int = seekBar.progress.toString().toInt()

                data.clear()
                for(i in 1..x)
                    data.add(i * i)

                adapter.notifyDataSetChanged()
                Log.d("TEXT", seekBar.progress.toString())
            }

            override fun onStartTrackingTouch(p0: SeekBar?) {
                Log.d("PASS", "start")
            }

            override fun onStopTrackingTouch(p0: SeekBar?) {
                Log.d("PASS", "stop")
            }

        })
    }
}
