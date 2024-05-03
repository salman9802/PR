package com.example.q6;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    /* Create an Android application, which show to the user 5-10 quiz questions. All
questions have 4 possible options and one right option exactly. Application counts
and shows to the user how many answers were right and shows the result to user. */

    ArrayList<Question> questions = new ArrayList<>();
    TextView questionTextView;
    RadioButton option_1, option_2, option_3, option_4;
    Button checkAnsBtn;
    RadioGroup optionsGroup;

    int currentQuestionIndex = 0, score = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        questionTextView = (TextView) findViewById(R.id.question_text);
        option_1 = (RadioButton) findViewById(R.id.option_1);
        option_2 = (RadioButton) findViewById(R.id.option_2);
        option_3 = (RadioButton) findViewById(R.id.option_3);
        option_4 = (RadioButton) findViewById(R.id.option_4);
        checkAnsBtn = (Button) findViewById(R.id.check_btn);
        optionsGroup = (RadioGroup) findViewById(R.id.options_group);

        questions.add(new Question("What is the capital of India?", "Mumbai", "Pune", "Delhi", "Bengluru", 2));
        questions.add(new Question("What is ?", "A", "B", "C", "D", 3));
        this.questions.get(currentQuestionIndex).setQuestion(questionTextView, option_1, option_2, option_3, option_4);

        checkAnsBtn.setOnClickListener(v -> {
            int selectedAns = optionsGroup.indexOfChild(optionsGroup.findViewById(optionsGroup.getCheckedRadioButtonId()));
            if(questions.get(currentQuestionIndex).checkAnswer(selectedAns)) score++;
            currentQuestionIndex++;
            if(currentQuestionIndex >= questions.size()) displayScore();
            else this.questions.get(currentQuestionIndex).setQuestion(questionTextView, option_1, option_2, option_3, option_4);
        });
    }

    public void displayScore() {
        this.optionsGroup.setVisibility(View.INVISIBLE);
        this.questionTextView.setText("SCORE: " + score);
    }

    private class Question {
        String q;
        int ans;
        String[] options = new String[4];
        Question(String q, String o1, String o2, String o3, String o4, int ans) {
            this.q = q;
            this.options[0] = o1;
            this.options[1] = o2;
            this.options[2] = o3;
            this.options[3] = o4;
            this.ans = ans;
        }

        public void setQuestion(TextView q, RadioButton b1, RadioButton b2, RadioButton b3, RadioButton b4) {
            q.setText(this.q);
            b1.setText(this.options[0]);
            b2.setText(this.options[1]);
            b3.setText(this.options[2]);
            b4.setText(this.options[3]);
        }

        public boolean checkAnswer(int ans) {
            return this.ans == ans;
        }
    }
}