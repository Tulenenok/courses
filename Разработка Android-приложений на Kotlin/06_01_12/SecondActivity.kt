package com.example.company.myapplication

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.util.Log

class SecondActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_second)
        Log.d("TEXT", "second")
    }

    override fun onDestroy() {
        setResult(1)
        super.onDestroy()
        Log.d("TEXT", "destroy")
    }
}
