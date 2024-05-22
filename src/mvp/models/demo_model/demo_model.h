#pragma once

class DemoModel {
    private:
        int demo_value_1;
        int demo_value_2;

    public:
        DemoModel(int val1, int val2);

        void setValue1(int val1);

        void setValue2(int val2);

        int getValue1();

        int getValue2();
};
