/*
 * Создайте приложение для конвертации величин из дюймов в километры и наоборот.
 * Интерфейс:
 *    EditText (id editText) - поле ввода/вывода значения в дюймах.
 *    EditText (id editText2) поле для ввода/вывода значения в километрах .
 *    TextView (id status) - статус операции
 *
 * 1 км ~ 39370 inc
 * Точность значений соответствует типу Float. Если введенные данные некорректны,
 * необходимо вывести "error" в элементе с id status. Если операция корректна,
 * status должен быть пуст. Обратите внимание на то, что пустая строка является ошибкой!
 */

package com.example.company.myapplication

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.text.Editable
import android.text.TextWatcher
import android.util.Log
import kotlinx.android.synthetic.main.activity_main.*

class MainActivity : AppCompatActivity()
{
    var con: Float = 39370.0F

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        status.setText("")
        editText.setText("")
        editText2.setText("")

        editText.addTextChangedListener(object: TextWatcher{
            override fun beforeTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {
                Log.d("TAG", "before")
            }

            override fun onTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {
                if (editText.isFocused())
                    try
                    {
                        var x: Float = editText.text.toString().toFloat()
                        editText2.setText((x / con).toString())
                        status.setText("")
                    }
                    catch (e: Throwable)
                    {
                        status.setText("error")
                    }
            }

            override fun afterTextChanged(p0: Editable?) {
                Log.d("TAG", "after")
            }

        })

        editText2.addTextChangedListener(object: TextWatcher{
            override fun beforeTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {
                Log.d("TAG", "before")
            }

            override fun onTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {
                if(editText2.isFocused())
                    try {
                        var x: Float = editText2.text.toString().toFloat()
                        editText.setText((x * con).toString())
                        status.setText("")
                    }
                    catch (e: Throwable)
                    {
                        status.setText("error")
                    }
            }

            override fun afterTextChanged(p0: Editable?) {
                Log.d("TAG", "after")
            }

        })
    }
}
